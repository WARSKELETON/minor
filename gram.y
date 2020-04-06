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

%nonassoc RETURN INTEGER ID STR
%nonassoc '(' '['
%nonassoc ADDR UMINUS '?'
%right '^'
%left '*' '/' '%'
%left '+' '-'
%left '<' '>' LE GE
%left NE '='
%nonassoc '~'
%left '&'
%left '|'
%right ATTR

%%
file    : program
    | module
    ;

program : PROGRAM decls START body END
    ;

module  : MODULE decls END
    ;

decls   : /* empty */
    | decl
    | decls ';' decl
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
    | var
    | vars ';' var
    ;

var    : type ID
    ;

type    : NUMBER
    | ARRAY
    | STRING
    ;

body    : instrs
    ;

instr   : IF expr THEN instrs FI
    | IF expr THEN instrs elifs ELSE instrs FI
    | IF expr THEN instrs elifs FI
    | IF expr THEN instrs ELSE instrs FI
    | FOR expr UNTIL expr STEP expr DO instrs DONE
    | expr ';'
    | expr '!'
    | REPEAT
    | STOP
    | RETURN
    ;

elif    : ELIF expr THEN instrs
    ;

elifs    : elif
    | elifs elif
    ;

instrs  : /* empty */
    | instrs instr
    ;

expr    : '(' expr ')'
    | ID
    | literal
    | '-' expr %prec UMINUS
    | '&' expr %prec ADDR
    | expr '+' expr
	| expr '-' expr
	| expr '*' expr
	| expr '/' expr
	| expr '%' expr
	| expr '<' expr
	| expr '>' expr
	| expr GE expr
	| expr LE expr
	| expr NE expr
	| expr '=' expr
    ;

literal : INTEGER 
    | STR
    ;

%%

char **yynames =
#if YYDEBUG > 0
		 (char**)yyname;
#else
		 0;
#endif
