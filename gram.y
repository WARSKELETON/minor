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

%type <n> program module decls delclist decl body bodyinstrs bodyvars func declattr funcend functype qualifier vars varlist var type instr instrterm elif elifs block instrs lvalue rvalue literal integer integerlist string stringintegerlist args

%token END DECLS DECL DECLATTR VARS VAR BODY BODYVARS IF_ELIF_ELSE RETURN_EXPR ELIFS INSTRS_INSTRTERM INSTRS TWO_INTEGERS MORE_INTEGERS ARGS

%%
file    : program                       { evaluate($1); freeNode($1); }
    | module                            { evaluate($1); freeNode($1); }
    ;

program : PROGRAM decls START body END  { $$ = binNode(PROGRAM, $2, $4); }
    ;

module  : MODULE decls END              { $$ = uniNode(MODULE, $2); }
    ;

decls   : /* empty */                   { $$ = nilNode(END); }
    | delclist                          { $$ = $1; }
    ;

delclist   : decl                       { $$ = $1; }
    | delclist ';' decl                 { $$ = binNode(DECLS, $1, $3); }
    ;

decl    : func                          { $$ = $1; }
    | qualifier CONST var declattr      { $$ = triNode(DECL, $1, $3, $4); }
    | qualifier var declattr            { $$ = triNode(DECL, $1, $2, $3); }
    ;

declattr   : /* empty */                { $$ = nilNode(END); }
    | ATTR literal                      { $$ = uniNode(DECLATTR, $2); }
    | '[' INTEGER ']'                   { $$ = nilNode(END); }
    | '[' INTEGER ']' ATTR literal      { $$ = uniNode(DECLATTR, $5); }

func    : FUNCTION qualifier functype ID vars funcend   { $$ = pentNode(FUNCTION, $2, $3, strNode(ID, $4), $5, $6); }
    ;

funcend : DONE  { $$ = nilNode(END); }
    | DO body   { $$ = uniNode(DO, $2); }
    ;

functype    : type  { $$ = $1; }
    | VOID  { $$ = uniNode(VOID, nilNode(END)); }
    ;

qualifier   : /* empty */   { $$ = nilNode(END); }
    | PUBLIC                { $$ = uniNode(PUBLIC, nilNode(END)); }
    | FORWARD               { $$ = uniNode(FORWARD, nilNode(END)); }
    ;

vars    : /* empty */       { $$ = nilNode(END); }
    | varlist               { $$ = $1; }
    ;

varlist : var               { $$ = $1; }
    | varlist ';' var       { $$ = binNode(VARS, $1, $3); }
    ;

var    : type ID            { $$ = binNode(VAR, $1, strNode(ID, $2)); }
    ;

type    : NUMBER            { $$ = uniNode(NUMBER, nilNode(END)); }
    | ARRAY                 { $$ = uniNode(ARRAY, nilNode(END)); }
    | STRING                { $$ = uniNode(STRING, nilNode(END)); }
    ;

body    : bodyvars bodyinstrs   { $$ = binNode(BODY, $1, $2); }
    | bodyinstrs                { $$ = $1; }
    ;

bodyinstrs : block              { $$ = $1; }

bodyvars : var ';'              { $$ = $1; }
    | bodyvars var ';'          { $$ = binNode(BODYVARS, $1, $2); }
    ;

instr   : IF rvalue THEN block FI                           { $$ = binNode(IF, $2, $4); }
    | IF rvalue THEN block elifs ELSE block FI              { $$ = quadNode(IF_ELIF_ELSE, $2, $4, $5, $7); }
    | IF rvalue THEN block elifs FI                         { $$ = triNode(ELIF, $2, $4, $5); }
    | IF rvalue THEN block ELSE block FI                    { $$ = triNode(ELSE, $2, $4, $6); }
    | FOR rvalue UNTIL rvalue STEP rvalue DO block DONE     { $$ = quadNode(FOR, $2, $4, $6, $8); }
    | rvalue ';'                                            { $$ = $1; }
    | rvalue '!'                                            { $$ = $1; }
    | lvalue '#' rvalue ';'                                 { $$ = binNode('#', $1, $3); }
    ;

instrterm   : REPEAT    { $$ = uniNode(REPEAT, nilNode(END)); }
    | STOP              { $$ = uniNode(STOP, nilNode(END)); }
    | RETURN rvalue     { $$ = uniNode(RETURN_EXPR, nilNode(END)); }
    | RETURN            { $$ = uniNode(RETURN, nilNode(END)); }
    ;

elif    : ELIF rvalue THEN block    { $$ = binNode(ELIF, $2, $4); }
    ;

elifs    : elif                     { $$ = $1; }
    | elifs elif                    { $$ = binNode(ELIFS, $1, $2); }
    ;

block   : /* empty */               { $$ = nilNode(END); }
    | instrterm                     { $$ = $1; }
    | instrs                        { $$ = $1; }
    | instrs instrterm              { $$ = binNode(INSTRS_INSTRTERM, $1, $2); }
    ;

instrs  : instr                     { $$ = $1; }
    | instrs instr                  { $$ = binNode(INSTRS, $1, $2); }
    ;

lvalue	: ID                        { $$ = strNode(ID, $1); }
	| lvalue '[' rvalue ']'         { $$ = binNode('[', $1, $3); }
	;

rvalue    : lvalue              { $$ = $1; }
    | '(' rvalue ')'            { $$ = $2; }
	| rvalue '(' args ')'       { $$ = binNode('(', $1, $3); }
	| rvalue '(' ')'            { $$ = $1; }
    | STR                       { $$ = strNode(STR, $1); }
    | INTEGER                   { $$ = intNode(INTEGER, $1); }
    | '-' rvalue %prec UMINUS   { $$ = uniNode(UMINUS, $2); }
    | '&' rvalue %prec ADDR     { $$ = uniNode(ADDR, $2); }
    | rvalue '^' rvalue         { $$ = binNode('^', $1, $3); }
    | rvalue '+' rvalue         { $$ = binNode('+', $1, $3); }
	| rvalue '-' rvalue         { $$ = binNode('-', $1, $3); }
	| rvalue '*' rvalue         { $$ = binNode('*', $1, $3); }
	| rvalue '/' rvalue         { $$ = binNode('/', $1, $3); }
	| rvalue '%' rvalue         { $$ = binNode('%', $1, $3); }
	| rvalue '<' rvalue         { $$ = binNode('<', $1, $3); }
	| rvalue '>' rvalue         { $$ = binNode('>', $1, $3); }
	| rvalue GE rvalue          { $$ = binNode(GE, $1, $3); }
	| rvalue LE rvalue          { $$ = binNode(LE, $1, $3); }
	| rvalue NE rvalue          { $$ = binNode(NE, $1, $3); }
	| rvalue '=' rvalue         { $$ = binNode('=', $1, $3); }
    | lvalue ATTR rvalue        { $$ = binNode(ATTR, $1, $3); }
    | rvalue '&' rvalue         { $$ = binNode('&', $1, $3); }
    | rvalue '|' rvalue         { $$ = binNode('|', $1, $3); }
    | '~' rvalue                { $$ = uniNode('~', $2); }
    | '?'                       { $$ = uniNode('?', nilNode(END)); }
    ;

literal : string                { $$ = $1; }
    | integerlist               { $$ = $1; }
    ;

integer : INTEGER               { $$ = intNode(INTEGER, $1); }
    ;

string  : stringintegerlist     { $$ = $1; }
    | STR                       { $$ = strNode(STR, $1); }
    ;

stringintegerlist   : integer integer   { $$ = binNode(TWO_INTEGERS, $1, $2); }
    | stringintegerlist integer         { $$ = binNode(MORE_INTEGERS, $1, $2); }

integerlist : integer                   { $$ = $1; }
    | integerlist ',' integer           { $$ = binNode(',', $1, $3); }
    ;

args	: rvalue	                    { $$ = $1; }
	| args ',' rvalue                   { $$ = binNode(ARGS, $1, $3); }
	;
%%

char **yynames =
#if YYDEBUG > 0
		 (char**)yyname;
#else
		 0;
#endif
