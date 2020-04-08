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

int nostring(Node *arg1, Node *arg2);
int intonly(Node *arg, int);
int noassign(Node *arg1, Node *arg2);
static int ncicl;
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

%type <n> program module decls delclist decl body bodyprincipal bodyinstrs bodyvars func declattr funcend functype qualifier vars varlist var type instr instrterm elif elifs block instrs lvalue expr literal integer integerlist string stringintegerlist args

%token NIL DECLS DECL FUNCTYPE QUALIFIER DECLATTR VARS VAR BODY BODYVARS RETURN_EXPR ELIFS INSTRS_INSTRTERM INSTRS TWO_INTEGERS MORE_INTEGERS ARGS

%%
file    : program                       { ; }
    | module                            { ; }
    ;

program : PROGRAM decls START bodyprincipal END  { $$ = binNode(PROGRAM, $2, $4); }
    ;

module  : MODULE decls END              { $$ = uniNode(MODULE, $2); }
    ;

decls   : /* empty */                   { $$ = nilNode(NIL); }
    | delclist                          { $$ = $1; }
    ;

delclist   : decl                       { $$ = $1; }
    | delclist ';' decl                 { $$ = binNode(DECLS, $1, $3); }
    ;

decl    : func                          { $$ = $1; }
    | qualifier CONST var declattr      { $$ = binNode(QUALIFIER, $1, binNode(VAR, $3, uniNode(DECLATTR, $4))); }
    | qualifier var declattr            { $$ = binNode(QUALIFIER, $1, binNode(VAR, $2, uniNode(DECLATTR, $3))); }
    ;

declattr   : /* empty */                { $$ = nilNode(NIL); }
    | ATTR literal                      { $$ = uniNode(DECLATTR, $2); } /* TODO */
    | '[' INTEGER ']'                   { $$ = nilNode(NIL); }
    | '[' INTEGER ']' ATTR literal      { $$ = uniNode(DECLATTR, $5); }

func    : FUNCTION qualifier functype ID vars funcend   { $$ = binNode(QUALIFIER, $2, binNode(FUNCTYPE, $3, binNode(ID, strNode(ID, $4), binNode(VARS, $5, uniNode(END, $6))))); }
    ;

funcend : DONE  { $$ = nilNode(DONE); }
    | DO body   { $$ = uniNode(DO, $2); }
    ;

functype    : type  { $$ = $1; }
    | VOID  { $$ = nilNode(VOID); }
    ;

qualifier   : /* empty */   { $$ = nilNode(NIL); }
    | PUBLIC                { $$ = nilNode(PUBLIC); }
    | FORWARD               { $$ = nilNode(FORWARD); }
    ;

vars    : /* empty */       { $$ = nilNode(NIL); }
    | varlist               { $$ = $1; }
    ;

varlist : var               { $$ = $1; }
    | varlist ';' var       { $$ = binNode(VARS, $1, $3); }
    ;

var    : type ID            { $$ = binNode(VAR, $1, strNode(ID, $2)); }
    ;

type    : NUMBER            { $$ = nilNode(NUMBER); }
    | ARRAY                 { $$ = nilNode(ARRAY); }
    | STRING                { $$ = nilNode(STRING); }
    ;

bodyprincipal    : bodyvars bodyinstrs   { $$ = binNode(BODY, $1, $2); }
    | bodyinstrs                         { $$ = $1; }
    ;

body    : bodyvars block   { $$ = binNode(BODY, $1, $2); }
    | block                { $$ = $1; }
    ;

bodyinstrs : /* empty */        { $$ = nilNode(NIL); }
    | instrs                    { $$ = $1; }
    ;

bodyvars : var ';'              { $$ = $1; }
    | bodyvars var ';'          { $$ = binNode(BODYVARS, $1, $2); }
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
    | RETURN expr       { $$ = uniNode(RETURN_EXPR, $2); }
    | RETURN            { $$ = nilNode(RETURN); }
    ;

elif    : ELIF expr THEN block    { $$ = binNode(ELIF, $2, $4); }
    ;

elifs    : elif                     { $$ = $1; }
    | elifs elif                    { $$ = binNode(ELIFS, $1, $2); }
    ;

block   : /* empty */               { $$ = nilNode(NIL); }
    | instrterm                     { $$ = $1; }
    | instrs                        { $$ = $1; }
    | instrs instrterm              { $$ = binNode(INSTRS_INSTRTERM, $1, $2); }
    ;

instrs  : instr                     { $$ = $1; }
    | instrs instr                  { $$ = binNode(INSTRS, $1, $2); }
    ;

lvalue	: ID                        { $$ = strNode(ID, $1); }
	| lvalue '[' expr ']'           { $$ = binNode('[', $1, $3); }
	;

expr    : lvalue              { $$ = $1; }
    | '(' expr ')'            { $$ = $2; }
	| expr '(' args ')'       { $$ = binNode('(', $1, $3); }
	| expr '(' ')'            { $$ = $1; }
    | string                  { $$ = $1; }
    | integer                 { $$ = $1; }
    | '-' expr %prec UMINUS   { $$ = uniNode(UMINUS, $2); }
    | '&' expr %prec ADDR     { $$ = uniNode(ADDR, $2); }
    | expr '^' expr           { $$ = binNode('^', $1, $3); }
    | expr '+' expr           { $$ = binNode('+', $1, $3); }
	| expr '-' expr           { $$ = binNode('-', $1, $3); }
	| expr '*' expr           { $$ = binNode('*', $1, $3); }
	| expr '/' expr           { $$ = binNode('/', $1, $3); }
	| expr '%' expr           { $$ = binNode('%', $1, $3); }
	| expr '<' expr           { $$ = binNode('<', $1, $3); }
	| expr '>' expr           { $$ = binNode('>', $1, $3); }
	| expr GE expr            { $$ = binNode(GE, $1, $3); }
	| expr LE expr            { $$ = binNode(LE, $1, $3); }
	| expr NE expr            { $$ = binNode(NE, $1, $3); }
	| expr '=' expr           { $$ = binNode('=', $1, $3); }
    | lvalue ATTR expr        { $$ = binNode(ATTR, $1, $3); }
    | expr '&' expr           { $$ = binNode('&', $1, $3); }
    | expr '|' expr           { $$ = binNode('|', $1, $3); }
    | '~' expr                { $$ = uniNode('~', $2); }
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
    | integerlist ',' integer           { $$ = binNode(',', $1, $3); $$->info = 2; } /* dunno */
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

int intonly(Node *arg, int novar) {
	if (arg->info % 5 != 1)
		yyerror("only integers can be used");
	if (arg->info % 10 > 5)
		yyerror("argument is constant");
	return 1;
}

int noassign(Node *arg1, Node *arg2) {
	int t1 = arg1->info, t2 = arg2->info;
	if (t1 == t2) return 0;
	if (t1 == 2 && t2 == 11) return 0; /* string := int* */
	if (t1 == 2 && arg2->attrib == INTEGER && arg2->value.i == 0)
		return 0; /* string := 0 */
	if (t1 > 10 && t1 < 20 && arg2->attrib == INTEGER && arg2->value.i == 0)
		return 0; /* pointer := 0 */
	return 1;
}
