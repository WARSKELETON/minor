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

%%
file    : program
    | module
    ;

program : PROGRAM decls START body END
    ;

module  : MODULE decls END
    ;

decls   : /* empty */
    | delclist
    ;

delclist   : decl
    | delclist ';' decl
    ;

decl    : func
    | qualifier CONST var ATTR literal 
    | qualifier CONST var
    | qualifier var ATTR literal
    | qualifier var
    ;

func    : FUNCTION qualifier functype ID vars funcend
    ;

funcend : DONE
    | DO body
    ;

functype    : type
    | VOID
    ;

qualifier   : /* empty */
    | PUBLIC
    | FORWARD
    ;

vars    : /* empty */
    | varlist
    ;

varlist : var
    | varlist ';' var
    ;

var    : type ID
    ;

type    : NUMBER
    | ARRAY
    | STRING
    ;

body    : bodyvars bodyinstrs
    | bodyinstrs
    ;

bodyinstrs : block

bodyvars : var ';'
    | bodyvars var ';'
    ;

instr   : IF rvalue THEN block FI
    | IF rvalue THEN block elifs ELSE block FI
    | IF rvalue THEN block elifs FI
    | IF rvalue THEN block ELSE block FI
    | FOR rvalue UNTIL rvalue STEP rvalue DO block DONE
    | rvalue ';'
    | rvalue '!'
    | lvalue '#' rvalue ';'
    ;

instrterm   : REPEAT
    | STOP
    | RETURN rvalue
    | RETURN
    ;

elif    : ELIF rvalue THEN block
    ;

elifs    : elif
    | elifs elif
    ;

block   : /* empty */
    | instrterm
    | instrs
    | instrs instrterm
    ;

instrs  : instr
    | instrs instr
    ;

lvalue	: ID
	| lvalue '[' rvalue ']'
	| '*' lvalue /* mal */
	;

rvalue    : lvalue
    | '(' rvalue ')'
	| rvalue '(' args ')'
	| rvalue '(' ')'
    | literal
    | '-' rvalue %prec UMINUS
    | '&' rvalue %prec ADDR
    | rvalue '^' rvalue
    | rvalue '+' rvalue
	| rvalue '-' rvalue
	| rvalue '*' rvalue
	| rvalue '/' rvalue
	| rvalue '%' rvalue
	| rvalue '<' rvalue
	| rvalue '>' rvalue
	| rvalue GE rvalue
	| rvalue LE rvalue
	| rvalue NE rvalue
	| rvalue '=' rvalue
    | lvalue ATTR rvalue
    | rvalue '&' rvalue
    | rvalue '|' rvalue
    | '~' rvalue
    | '?'
    ;

literal : INTEGER 
    | STR
    ;

args	: rvalue	
	| args ',' rvalue
	;
%%

char **yynames =
#if YYDEBUG > 0
		 (char**)yyname;
#else
		 0;
#endif
