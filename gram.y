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

void declare(Node *pub, int cnst, Node *type, char *name, Node *value);
void enter(int pub, int typ, char *name);
void function(int pub, Node *type, char *name, Node *body,int enter);
int nostring(Node *arg1, Node *arg2);
void noarray(Node *arg1, Node *arg2);
void sametype(Node *arg1, Node *arg2);
int intonly(Node *arg);
int noassign(Node *arg1, Node *arg2);
static int ncicl;
static char *fpar;
int typereturn;
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

%type <n> program module decls decl body bodyprincipal bodyinstrs bodyvars func funcend functype qualifier params param var type instr instrterm elif elifs block instrs lvalue expr literal integer integerlist string stringintegerlist args

%token NIL DECLS DECL FUNCTYPE QUALIFIER VARS VAR BODY RETURN_EXPR ELIFS BLOCK INSTRS TWO_INTEGERS MORE_INTEGERS ARGS LOCAL CALL

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

func    : FUNCTION qualifier functype ID { enter($2, $3->info, $4); typereturn = $3->info; } params funcend   { $$ = binNode(QUALIFIER, $2, binNode(FUNCTYPE, $3, binNode(ID, strNode(ID, $4), binNode(VARS, $5, uniNode(END, $6))))); IDpop(); }
    | FUNCTION functype ID { enter(0, $2->info, $3); typereturn = $2->info; } params funcend                 { $$ = binNode(FUNCTYPE, $2, binNode(ID, strNode(ID, $3), binNode(VARS, $4, uniNode(END, $5)))); IDpop(); }
    | FUNCTION qualifier functype ID { enter($2, $3->info, $4); typereturn = $3->info; } funcend            { $$ = binNode(QUALIFIER, $2, binNode(FUNCTYPE, $3, binNode(ID, strNode(ID, $4), uniNode(END, $5)))); IDpop(); }
    | FUNCTION functype ID { enter(0, $2->info, $3); typereturn = $2->info; } funcend                      { $$ = binNode(FUNCTYPE, $2, binNode(ID, strNode(ID, $3), uniNode(END, $4))); IDpop(); }
    ;

funcend : DONE          { $$ = nilNode(DONE); }
    | DO body           { $$ = uniNode(DO, $2); }
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

param    : STRING ID                { $$ = binNode(VAR, uniNode(STRING, nilNode(STRING)), strNode(ID, $2)); IDnew(2, $2, 0); $$->info = 2; }
    | NUMBER ID                     { $$ = binNode(VAR, uniNode(NUMBER, nilNode(NUMBER)), strNode(ID, $2)); IDnew(1, $2, 0); $$->info = 1; }
    | ARRAY ID '[' integer ']'      { $$ = binNode(VAR, uniNode(ARRAY, nilNode(ARRAY)), strNode(ID, $2)); IDnew(3, $2, 0); $$->info = 3; }
    ;

var    : STRING ID                  { $$ = binNode(VAR, uniNode(STRING, nilNode(STRING)), strNode(ID, $2)); $$->info = 2; }
    | NUMBER ID                     { $$ = binNode(VAR, uniNode(NUMBER, nilNode(NUMBER)), strNode(ID, $2)); $$->info = 1; }
    | ARRAY ID '[' integer ']'      { $$ = binNode(VAR, uniNode(ARRAY, nilNode(ARRAY)), strNode(ID, $2)); $$->info = 3; }
    | ARRAY ID                      { $$ = binNode(VAR, uniNode(ARRAY, nilNode(ARRAY)), strNode(ID, $2)); $$->info = 3; }
    ;

type    : NUMBER            { $$ = nilNode(NUMBER); $$->info = 1; }
    | ARRAY                 { $$ = nilNode(ARRAY); $$->info = 3; }
    | STRING                { $$ = nilNode(STRING); $$->info = 2; }
    ;

bodyprincipal    : bodyvars bodyinstrs   { $$ = binNode(BODY, $1, $2); }
    | bodyinstrs                         { $$ = binNode(BODY, $1, 0); }
    ;

body    : bodyvars block   { $$ = binNode(BODY, $1, $2); }
    | block                { $$ = binNode(BODY, $1, 0); }
    ;

bodyinstrs : /* empty */        { $$ = nilNode(NIL); }
    | instrs                    { $$ = binNode(BODY, $1, 0); }
    ;

bodyvars : var ';'              { IDnew($1->info, RIGHT_CHILD($1)->value.s, 0); $$ = binNode(VARS, $1, 0); }
    | bodyvars var ';'          { IDnew($2->info, RIGHT_CHILD($2)->value.s, 0); $$ = binNode(VARS, $1, $2); }
    ;

instr   : IF expr THEN block FI                           { $$ = binNode(IF, $2, $4); }
    | IF expr THEN block elifs ELSE block FI              { $$ = binNode(IF, $2, binNode(THEN, $4, binNode(ELIF, $5, uniNode(ELSE, $7)))); }
    | IF expr THEN block elifs FI                         { $$ = binNode(IF, $2, binNode(THEN, $4, uniNode(ELIF, $5))); }
    | IF expr THEN block ELSE block FI                    { $$ = binNode(IF, $2, binNode(THEN, $4, uniNode(ELSE, $6))); }
    | FOR expr UNTIL expr STEP expr DO { ncicl++; } block DONE         { $$ = binNode(FOR, $2, binNode(UNTIL, $4, binNode(STEP, $6, uniNode(DO, $8)))); ncicl--; }
    | expr ';'                                            { $$ = $1; }
    | expr '!'                                            { $$ = $1; }
    | lvalue '#' expr ';'                                 { $$ = binNode('#', $1, $3); }
    ;

instrterm   : REPEAT    { $$ = nilNode(REPEAT); if (ncicl <= 0) yyerror("invalid repeat argument"); }
    | STOP              { $$ = nilNode(STOP); if (ncicl <= 0) yyerror("invalid stop argument"); }
    | RETURN expr       { if (IDlevel() == 0 && $2->info != 1) yyerror("return non integer out of function"); if (IDlevel() > 0 && typereturn != $2->info) yyerror("return type differs from function type"); $$ = uniNode(RETURN_EXPR, $2); }
    | RETURN            { if (IDlevel() == 0) yyerror("return void out of function"); if (typereturn != 4) yyerror("return type differs from function type"); $$ = nilNode(RETURN); }
    ;

elif    : ELIF expr THEN block    { $$ = binNode(ELIF, $2, $4); }
    ;

elifs    : elif                     { $$ = binNode(ELIFS, $1, 0); }
    | elifs elif                    { $$ = binNode(ELIFS, $1, $2); }
    ;

block   : /* empty */               { $$ = nilNode(NIL); }
    | instrterm                     { $$ = binNode(BLOCK, $1, 0); }
    | instrs                        { $$ = binNode(BLOCK, $1, 0); }
    | instrs instrterm              { $$ = binNode(BLOCK, $1, $2); }
    ;

instrs  : instr                     { $$ = binNode(INSTRS, $1, 0); }
    | instrs instr                  { $$ = binNode(INSTRS, $1, $2); }
    ;

lvalue	: ID                        { long pos; int typ = IDfind($1, &pos); if (pos == 0) $$ = strNode(ID, $1); else $$ = intNode(LOCAL, pos); $$->info = typ; }
	| lvalue '[' expr ']'           { $$ = binNode('[', $1, $3); $$->info = 1; } /* expr tem que ser int mais merdas, pode se indexar strings */
	;

expr    : lvalue              { $$ = $1; $$->info = $1->info; }
    | '(' expr ')'            { $$ = $2; }
	| ID '(' args ')'         { $$ = binNode(CALL, strNode(ID, $1), $3); long pos; int typ = IDfind($1, &pos); $$->info = typ; }
	| ID '(' ')'              { $$ = binNode(CALL, strNode(ID, $1), nilNode(NIL)); long pos; int typ = IDfind($1, &pos); $$->info = typ; }
    | string                  { $$ = $1; $$->info = 2; }
    | integer                 { $$ = $1; $$->info = 1; }
    | '-' expr %prec UMINUS   { $$ = uniNode(UMINUS, $2); $$->info = $2->info; intonly($2);}
    | '&' lvalue %prec ADDR   { $$ = uniNode(ADDR, $2); }
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
    | lvalue ATTR expr        { $$ = binNode(ATTR, $1, $3); }
    | expr '&' expr           { $$ = binNode('&', $1, $3); $$->info = intonly($1); intonly($3); }
    | expr '|' expr           { $$ = binNode('|', $1, $3); $$->info = intonly($1); intonly($3); }
    | '~' expr                { $$ = uniNode('~', $2); $$->info = intonly($2); }
    | '?'                     { $$ = nilNode('?'); }
    ;

literal : string                { $$ = $1; $$->info = $1->info; }
    | integerlist               { $$ = $1; $$->info = $1->info; }
    ;

integer : INTEGER               { $$ = intNode(INTEGER, $1); $$->info = 1; }
    ;

string  : stringintegerlist     { $$ = $1; $$->info = $1->info; }
    | STR                       { $$ = strNode(STR, $1); $$->info = 2; }
    ;

stringintegerlist   : integer integer   { $$ = binNode(TWO_INTEGERS, $1, $2); $$->info = 2; }
    | stringintegerlist integer         { $$ = binNode(MORE_INTEGERS, $1, $2); $$->info = 2; }

integerlist : integer                   { $$ = $1; $$->info = $1->info; }
    | integerlist ',' integer           { $$ = binNode(',', $1, $3); $$->info = 3; }
    ;

args	: expr	                      { $$ = $1; }
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
	int t1 = arg1->info, t2 = arg2->info;
	if (t1 == t2) return 0;
	if (t1 == 3 && t2 == 1) return 0; /* array := int */
	if (t1 == 1 && t2 == 3) return 0; /* int := array */
	if (t1 == 2 && t2 == 11) return 0; /* string := int* */
	if (t1 == 2 && arg2->attrib == INTEGER && arg2->value.i == 0)
		return 0; /* string := 0 */
	if (t1 > 10 && t1 < 20 && arg2->attrib == INTEGER && arg2->value.i == 0)
		return 0; /* pointer := 0 */
	return 1;
}

void declare(Node *pub, int cnst, Node *type, char *name, Node *value)
{
  int typ;
  if (!value) {
    if (pub) {
        if (pub->info == 1 && cnst) {
            yyerror("local constants must be initialised");
        }
    }
    return;
  }
  if (value->attrib = INTEGER && value->value.i == 0 && type->value.i > 10)
  	return; /* NULL pointer */
  if ((typ = value->info) % 10 > 5) typ -= 5;
  if (type->info != typ)
    yyerror("wrong types in initialization");

}

void enter(int pub, int typ, char *name) {
	fpar = malloc(32); /* 31 arguments, at most */
	fpar[0] = 0; /* argument count */
	if (IDfind(name, (long*)IDtest) < 20)
		IDnew(typ+20, name, (long)fpar);
	IDpush();
	if (typ != 4) IDnew(typ, name, 0);
}

void function(int pub, Node *type, char *name, Node *body, int enter)
{

	Node *bloco = LEFT_CHILD(body);
	IDpop();
	if (bloco != 0) { /* not a forward declaration */
		long par;
		int fwd = IDfind(name, &par);
		if (fwd > 40) yyerror("duplicate function");
		else IDreplace(fwd+40, name, par);
	}
}
