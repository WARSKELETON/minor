%{
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "node.h"
#include "tabid.h"
#define YYDEBUG 1
int yylex();
void evaluate(Node *p);
void yyerror(char *s);

void declare(Node *qualifier, int cnst, Node *type, char *name, Node *value);
void enter(Node *qualifier, int typ, char *name);
void function(Node *qualifier, Node *type, char *name, Node *body);
int nostring(Node *arg1, Node *arg2);
void noarray(Node *arg1, Node *arg2);
void sametype(Node *arg1, Node *arg2);
int intonly(Node *arg);
int noassign(Node *arg1, Node *arg2);
int checkargs(char *name, Node *args);
static int ncicl;
static char *fpar;
int typereturn;
int arraysize;
%}

%union {
    int i;          /* integer value */
    char *s;        /* symbol name or string literal */
    int *vi;        /* integer vector */
    Node *n;	    /* tree node */
}

%token <i> INTEGER
%token <s> ID STR
%token PROGRAM MODULE START END FUNCTION PUBLIC FORWARD NUMBER ARRAY VOID STRING CONST DONE DO
%token IF THEN ELSE ELIF FI FOR UNTIL STEP REPEAT STOP RETURN

%right ATTR
%left '|'
%left '&'
%nonassoc '~'
%left NE '='
%left '<' '>' LE GE
%left '+' '-'
%left '*' '/' '%'
%right '^'
%nonassoc ADDR UMINUS '?'
%nonassoc '(' '['

%type <n> program module decls decl body bodyprincipal bodyinstrs bodyvars func funcend functype qualifier params param var type instr instrterm elif elifs block blockfunc instrs lvalue expr literal integer integerlist string args

%token NIL DECLS DECL FUNCTYPE QUALIFIER VARS VAR SIZE BODY RETURN_EXPR BLOCK INSTRS ARGS LOCAL CALL

%%
file    : program                       { printNode($1,0,yynames); }
    | module                            { printNode($1,0,yynames); }
    ;

program : PROGRAM decls START bodyprincipal END  { $$ = binNode(PROGRAM, $2, $4); }
    | PROGRAM START bodyprincipal END            { $$ = uniNode(PROGRAM, $3); }
    ;

module  : MODULE decls END              { $$ = uniNode(MODULE, $2); }
    | MODULE END                        { $$ = nilNode(MODULE); }
    ;

decls   : decl                          { $$ = $1; }
    | decls ';' decl                    { $$ = binNode(DECLS, $1, $3); }
    ;

decl    : func                          { $$ = $1; }
    | qualifier CONST var ATTR literal  { IDnew($3->info+5, RIGHT_CHILD($3)->value.s, 0); declare($1, 1, $3, RIGHT_CHILD($3)->value.s, $5); $$ = binNode(QUALIFIER, $1, binNode(VAR, $3, $5)); }
    | qualifier var ATTR literal        { IDnew($2->info, RIGHT_CHILD($2)->value.s, 0); declare($1, 0, $2, RIGHT_CHILD($2)->value.s, $4); $$ = binNode(QUALIFIER, $1, binNode(VAR, $2, $4)); }
    | qualifier var                     { IDnew($2->info, RIGHT_CHILD($2)->value.s, 0); declare($1, 0, $2, RIGHT_CHILD($2)->value.s, 0); $$ = binNode(DECL, $1, $2); }
    | qualifier CONST var               { IDnew($3->info+5, RIGHT_CHILD($3)->value.s, 0); declare($1, 1, $3, RIGHT_CHILD($3)->value.s, 0); $$ = binNode(DECL, $1, $3); }
    | CONST var                         { IDnew($2->info+5, RIGHT_CHILD($2)->value.s, 0); declare(0, 1, $2, RIGHT_CHILD($2)->value.s, 0); $$ = $2; }
    | CONST var ATTR literal            { IDnew($2->info+5, RIGHT_CHILD($2)->value.s, 0); declare(0, 1, $2, RIGHT_CHILD($2)->value.s, $4); $$ = binNode(DECL, $2, $4); }
    | var                               { IDnew($1->info, RIGHT_CHILD($1)->value.s, 0); declare(0, 0, $1, RIGHT_CHILD($1)->value.s, 0); $$ = $1; }
    | var ATTR literal                  { IDnew($1->info, RIGHT_CHILD($1)->value.s, 0); declare(0, 0, $1, RIGHT_CHILD($1)->value.s, $3); $$ = binNode(DECL, $1, $3); }
    ;

func    : FUNCTION qualifier functype ID { enter($2, $3->info, $4); typereturn = $3->info; } params funcend   { $$ = binNode(QUALIFIER, $2, binNode(FUNCTYPE, $3, binNode(ID, strNode(ID, $4), binNode(VARS, $6, uniNode(END, $7))))); function($2, $3, $4, $7); }
    | FUNCTION functype ID { enter(0, $2->info, $3); typereturn = $2->info; } params funcend                 { $$ = binNode(FUNCTYPE, $2, binNode(ID, strNode(ID, $3), binNode(VARS, $5, uniNode(END, $6)))); function(0, $2, $3, $6); }
    | FUNCTION qualifier functype ID { enter($2, $3->info, $4); typereturn = $3->info; } funcend            { $$ = binNode(QUALIFIER, $2, binNode(FUNCTYPE, $3, binNode(ID, strNode(ID, $4), uniNode(END, $6)))); function($2, $3, $4, $6); }
    | FUNCTION functype ID { enter(0, $2->info, $3); typereturn = $2->info; } funcend                      { $$ = binNode(FUNCTYPE, $2, binNode(ID, strNode(ID, $3), uniNode(END, $5))); function(0, $2, $3, $5); }
    ;

funcend : DONE          { $$ = binNode(DO, 0, 0); }
    | DO body           { $$ = binNode(DO, $2, 0); }
    ;

functype    : type      { $$ = $1; $$->info = $1->info; }
    | VOID              { $$ = nilNode(VOID); $$->info = 4; }
    ;

qualifier   : PUBLIC    { $$ = nilNode(PUBLIC); $$->info = 1; }
    | FORWARD           { $$ = nilNode(FORWARD); $$->info = 2; }
    ;

params  : param         { $$ = binNode(VARS, $1, 0); }
    | params ';' param  { $$ = binNode(VARS, $1, $3); }
    ;

param    : STRING ID                { $$ = binNode(VAR, uniNode(STRING, nilNode(STRING)), strNode(ID, $2)); IDnew(2, $2, 0); if (IDlevel() == 1) fpar[++fpar[0]] = 2; $$->info = 2; }
    | NUMBER ID                     { $$ = binNode(VAR, uniNode(NUMBER, nilNode(NUMBER)), strNode(ID, $2)); IDnew(1, $2, 0); if (IDlevel() == 1) fpar[++fpar[0]] = 1; $$->info = 1; }
    | ARRAY ID '[' integer ']'      { $$ = binNode(VAR, uniNode(ARRAY, nilNode(ARRAY)), strNode(ID, $2)); IDnew(3, $2, 0); if (IDlevel() == 1) fpar[++fpar[0]] = 3; $$->info = 3; }
    ;

var    : STRING ID                  { $$ = binNode(VAR, uniNode(STRING, nilNode(STRING)), strNode(ID, $2)); $$->info = 2; }
    | NUMBER ID                     { $$ = binNode(VAR, uniNode(NUMBER, nilNode(NUMBER)), strNode(ID, $2)); $$->info = 1; }
    | ARRAY ID '[' integer ']'      { $$ = binNode(VAR, intNode(SIZE, $4->value.i), strNode(ID, $2)); $$->info = 3; }
    | ARRAY ID                      { $$ = binNode(VAR, uniNode(ARRAY, nilNode(ARRAY)), strNode(ID, $2)); $$->info = 3; }
    ;

type    : NUMBER            { $$ = nilNode(NUMBER); $$->info = 1; }
    | ARRAY                 { $$ = nilNode(ARRAY); $$->info = 3; }
    | STRING                { $$ = nilNode(STRING); $$->info = 2; }
    ;

bodyprincipal    : bodyvars bodyinstrs   { $$ = binNode(BODY, $1, $2); }
    | bodyinstrs                         { $$ = binNode(BODY, $1, 0); }
    ;

body    : bodyvars blockfunc   { $$ = binNode(BODY, $1, $2); }
    | blockfunc                { $$ = binNode(BODY, $1, 0); }
    ;

bodyinstrs : /* empty */        { $$ = nilNode(NIL); }
    | instrs                    { $$ = binNode(BODY, $1, 0); }
    ;

bodyvars : var ';'              { IDnew($1->info, RIGHT_CHILD($1)->value.s, 0); $$ = binNode(VARS, $1, 0); }
    | bodyvars var ';'          { IDnew($2->info, RIGHT_CHILD($2)->value.s, 0); $$ = binNode(VARS, $1, $2); }
    ;

instr   : IF expr THEN block FI                           { $$ = binNode(IF, $2, $4); if ($2->info % 5 == 4) yyerror("condition as void expression"); }
    | IF expr THEN block elifs ELSE block FI              { $$ = binNode(IF, $2, binNode(THEN, $4, binNode(ELIF, $5, uniNode(ELSE, $7)))); if ($2->info % 5 == 4) yyerror("condition as void expression"); }
    | IF expr THEN block elifs FI                         { $$ = binNode(IF, $2, binNode(THEN, $4, binNode(ELIF, $5, 0))); if ($2->info % 5 == 4) yyerror("condition as void expression"); }
    | IF expr THEN block ELSE block FI                    { $$ = binNode(IF, $2, binNode(THEN, $4, uniNode(ELSE, $6))); if ($2->info % 5 == 4) yyerror("condition as void expression"); }
    | FOR expr UNTIL expr STEP expr DO { ncicl++; } block DONE         { $$ = binNode(FOR, $2, binNode(UNTIL, $4, binNode(STEP, $6, uniNode(DO, $9)))); if ($2->info % 5 == 4 || $4->info % 5 == 4 || $6->info % 5 == 4) yyerror("condition as void expression"); ncicl--; }
    | expr ';'                                            { $$ = $1; }
    | expr '!'                                            { $$ = $1; if ($1->info % 5 == 4) yyerror("printing void expression"); }
    | lvalue '#' expr ';'                                 { $$ = binNode('#', $1, $3); }
    ;

instrterm   : REPEAT    { $$ = nilNode(REPEAT); if (ncicl <= 0) yyerror("invalid repeat argument"); }
    | STOP              { $$ = nilNode(STOP); if (ncicl <= 0) yyerror("invalid stop argument"); }
    | RETURN expr       { if (IDlevel() == 0 && $2->info != 1) yyerror("return non integer out of function"); if (IDlevel() > 0 && typereturn != $2->info) yyerror("return type differs from function type"); $$ = uniNode(RETURN_EXPR, $2); }
    | RETURN            { if (IDlevel() == 0) yyerror("return void out of function"); if (typereturn != 4) yyerror("return type differs from function type"); $$ = nilNode(RETURN); }
    ;

elif    : ELIF expr THEN block    { $$ = binNode(ELIF, $2, $4); if ($2->info % 5 == 4) yyerror("condition as void expression"); }
    ;

elifs    : elif                     { $$ = binNode(ELIF, $1, 0); }
    | elifs elif                    { $$ = binNode(ELIF, $1, $2); }
    ;

block   : /* empty */               { $$ = nilNode(NIL); }
    | instrterm                     { $$ = binNode(BLOCK, $1, 0); }
    | instrs                        { $$ = binNode(BLOCK, $1, 0); }
    | instrs instrterm              { $$ = binNode(BLOCK, $1, $2); }
    ;

blockfunc   : /* empty */           { $$ = nilNode(NIL); }
    | instrterm                     { $$ = binNode(BLOCK, $1, 0); }
    | instrs                        { $$ = binNode(BLOCK, $1, 0); if (IDlevel() > 0 && typereturn != 4) yyerror("non void function without return"); }
    | instrs instrterm              { $$ = binNode(BLOCK, $1, $2); }
    ;

instrs  : instr                     { $$ = binNode(INSTRS, $1, 0); }
    | instrs instr                  { $$ = binNode(INSTRS, $1, $2); }
    ;

lvalue	: ID                        { long pos; int typ = IDfind($1, &pos); if (pos == 0) $$ = strNode(ID, $1); else $$ = intNode(LOCAL, pos); $$->info = typ; }
	| ID '[' expr ']'               { long pos; int typ = IDfind($1, &pos); 
                                        if (pos == 0) $$ = strNode(ID, $1); else $$ = intNode(LOCAL, pos); 
                                        $$ = binNode('[', $1, $3); if (typ != 3 && typ != 2) yyerror("invalid indexation"); intonly($3); $$->info = 1; } /* pode ser array de funcao TODO */
    | string '[' expr ']'           { $$ = binNode('[', $1, $3); intonly($3); $$->info = 1; }
	;

expr    : lvalue              { $$ = $1; $$->info = $1->info; }
    | '(' expr ')'            { $$ = $2; $$->info = $2->info; }
	| ID '(' args ')'         { $$ = binNode(CALL, strNode(ID, $1), $3); long pos; int typ = IDfind($1, &pos); $$->info = checkargs($1, $3); }
	| ID '(' ')'              { $$ = binNode(CALL, strNode(ID, $1), nilNode(NIL)); long pos; int typ = IDfind($1, &pos); $$->info = checkargs($1, 0); }
    | string                  { $$ = $1; $$->info = 2; }
    | integer                 { $$ = $1; $$->info = 1; }
    | '-' expr %prec UMINUS   { $$ = uniNode(UMINUS, $2); $$->info = $2->info; intonly($2);}
    | '&' lvalue %prec ADDR   { $$ = uniNode(ADDR, $2); $$->info = 1; }
    | expr '^' expr           { $$ = binNode('^', $1, $3); $$->info = intonly($1); intonly($3); }
    | expr '+' expr           { $$ = binNode('+', $1, $3); $$->info = intonly($1); intonly($3); }
	| expr '-' expr           { $$ = binNode('-', $1, $3); $$->info = intonly($1); intonly($3); }
	| expr '*' expr           { $$ = binNode('*', $1, $3); $$->info = intonly($1); intonly($3); }
	| expr '/' expr           { $$ = binNode('/', $1, $3); $$->info = intonly($1); intonly($3); }
	| expr '%' expr           { $$ = binNode('%', $1, $3); $$->info = intonly($1); intonly($3); }
	| expr '<' expr           { $$ = binNode('<', $1, $3); $$->info = 1; sametype($1, $3); noarray($1, $3); }
	| expr '>' expr           { $$ = binNode('>', $1, $3); $$->info = 1; sametype($1, $3); noarray($1, $3); }
	| expr GE expr            { $$ = binNode(GE, $1, $3); $$->info = 1; sametype($1, $3); noarray($1, $3); }
	| expr LE expr            { $$ = binNode(LE, $1, $3); $$->info = 1; sametype($1, $3); noarray($1, $3); }
	| expr NE expr            { $$ = binNode(NE, $1, $3); $$->info = 1; sametype($1, $3); noarray($1, $3); }
	| expr '=' expr           { $$ = binNode('=', $1, $3); $$->info = 1; sametype($1, $3); noarray($1, $3); }
    | lvalue ATTR expr        { $$ = binNode(ATTR, $1, $3); if ($$->info % 10 > 5) yyerror("constant value to assignment"); if (noassign($1, $3)) yyerror("illegal assignment"); $$->info = $1->info; }
    | expr '&' expr           { $$ = binNode('&', $1, $3); $$->info = intonly($1); intonly($3); }
    | expr '|' expr           { $$ = binNode('|', $1, $3); $$->info = intonly($1); intonly($3); }
    | '~' expr                { $$ = uniNode('~', $2); $$->info = intonly($2); }
    | '?'                     { $$ = nilNode('?'); $$->info = 1; }
    ;

literal : string                { $$ = $1; $$->info = $1->info; }
    | integerlist               { $$ = $1; $$->info = $1->info; }
    ;

integer : INTEGER               { $$ = intNode(INTEGER, $1); $$->info = 1; }
    ;

string   : integer integer   { $$ = binNode(STR, $1, $2); $$->info = 2; }
    | STR                    { $$ = binNode(STR, strNode(STR, $1), 0); $$->info = 2; }
    | string STR             { $$ = binNode(STR, $1, $2); $$->info = 2; }
    | string integer         { $$ = binNode(STR, $1, $2); $$->info = 2; }

integerlist : integer                   { $$ = $1; $$->info = $1->info; arraysize = 1; }
    | integerlist ',' integer           { $$ = binNode(',', $1, $3); $$->info = 3; arraysize++; }
    ;

args	: expr	                      { $$ = binNode(ARGS, nilNode(NIL), $1); }
	| args ',' expr                   { $$ = binNode(ARGS, $1, $3); }
	;
%%

char **yynames =
#if YYDEBUG > 0
		 (char**)yyname;
#else
		 0;
#endif

int nostring(Node *arg1, Node *arg2) {
	if (arg1->info % 5 == 2 || arg2->info % 5 == 2)
		yyerror("can not use strings");
	return arg1->info % 5 == 3 || arg2->info % 5 == 3 ? 3 : 1;
}

void noarray(Node *arg1, Node *arg2) {
	if (arg1->info % 5 == 3 || arg2->info % 5 == 3)
		yyerror("can not use arrays");
}

void sametype(Node *arg1, Node *arg2) {
	if (arg1->info % 5 != arg2->info % 5)
		yyerror("different types not allowed");
}

int intonly(Node *arg) {
	if (arg->info % 5 != 1)
		yyerror("only integers can be used");
	if (arg->info % 10 > 5)
		yyerror("argument is constant");
	return 1;
}

int noassign(Node *arg1, Node *arg2) {
    /* TODO */
	int t1 = arg1->info, t2 = arg2->info;
    t1 = t1 % 5;
    t2 = t2 % 5;
	if (t1 == t2) return 0;
	if (t1 == 3 && t2 == 1) return 0; /* array := int */
	if (t1 == 1 && t2 == 3) return 0; /* int := array */
	if (t1 == 2 && t2 == 1) return 0; /* string := int* */
	if (t1 == 2 && arg2->attrib == INTEGER && arg2->value.i == 0)
		return 0; /* string := 0 */
	if (t1 > 10 && t1 < 20 && arg2->attrib == INTEGER && arg2->value.i == 0)
		return 0; /* pointer := 0 */
	return 1;
}

void declare(Node *qualifier, int cnst, Node *type, char *name, Node *value)
{
  int typ;
  if (!value) {
    if (qualifier) {
        if (qualifier->info == 1 && cnst) {
            yyerror("local constants must be initialised");
        }
    }
    return;
  }
  if (qualifier) {
      if (qualifier->info == 2) {
          yyerror("forward with declaration");
      }
  }
  if (value->attrib = INTEGER && value->value.i == 0 && type->value.i > 10)
  	return; /* NULL pointer */
  if ((typ = value->info) % 10 > 5) typ -= 5;
  if (type->info == 3) {
    if (LEFT_CHILD(type)->value.i != arraysize) {
        yyerror("array size doesn't correspond to attributions");
    }
  }
  else if (type->info != typ) {
    yyerror("wrong types in initialization");
  }
}

void enter(Node *qualifier, int typ, char *name) {
	fpar = malloc(32); /* 31 arguments, at most */
	fpar[0] = 0; /* argument count */
	if (IDfind(name, (long*)IDtest) < 20)
		IDnew(typ+20, name, (long)fpar);
	IDpush();
	if (typ != 4) IDnew(typ, name, 0);
}

void function(Node *qualifier, Node *type, char *name, Node *body)
{
	Node *bloco = LEFT_CHILD(body);
	IDpop();
    if (qualifier) {
        if (qualifier->info == 2 && bloco != 0) {
            yyerror("forward function with body");
        }
        if (qualifier->info == 1 && bloco == 0) {
            yyerror("not forward function without body");
        }
    }
    else if (bloco == 0) {
        yyerror("not forward function without body");
    }
	/* if (bloco != 0) {
		long par;
		int fwd = IDfind(name, &par);
		if (fwd > 40) yyerror("duplicate function");
		else IDreplace(fwd+40, name, par);
	} */
}

int checkargs(char *name, Node *args) {
	char *arg;
	int typ;
        if ((typ = IDsearch(name, (long*)&arg,IDlevel(),1)) < 20) {
		yyerror("ident not a function");
		return 0;
	}
	if (args == 0 && arg[0] == 0)
		;
	else if (args == 0 && arg[0] != 0)
		yyerror("function requires arguments");
	else if (args != 0 && arg[0] == 0)
		yyerror("function requires no arguments");
	else {
		int err = 0, null, i = arg[0], typ;
		do {
			Node *n;
			if (i == 0) {
				yyerror("too many arguments.");
				err = 1;
				break;
			}
			n = RIGHT_CHILD(args);
			typ = n->info;
			if (typ % 10 > 5) typ -= 5; /* remove CONST */
			null =  (n->attrib == INTEGER && n->value.i == 0 && arg[i] > 10) ? 1 : 0;
			if (!null && arg[i] != typ) {
				yyerror("wrong argument type");
				err = 1;
				break;
			}
			args = LEFT_CHILD(args);
			i--;
		} while (args->attrib != NIL);
		if (!err && i > 0)
			yyerror("missing arguments");
	}
	return typ % 20;
}
