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

%right ATTR

%%
file    : program
    | module
    ;

program : PROGRAM START body END
    | PROGRAM decls START body END
    ;

module  : MODULE decls END
    ;

decls   : decl
    | decls decl
    ;

decl    : ';'
    | func
    | declpre var ATTR literal 
    | declpre var
    | var ATTR literal
    | var
    ;

func    : FUNCTION qualifier functype ID vars funcend
    | FUNCTION functype ID funcend
    | FUNCTION qualifier functype ID funcend
    | FUNCTION functype ID vars funcend
    ;

funcend : DONE
    | DO body
    ;

functype    : type
    | VOID
    ;

declpre : qualifier CONST
    | qualifier
    | CONST
    ;

qualifier   : PUBLIC
    | FORWARD
    ;

vars    : var
    | vars ';' var
    ;

var    : type ID
    ;

type    : NUMBER
    | ARRAY
    | STRING
    ;

body    : instr
    ;

instr   : expr '!'
    ;

expr    : literal
    ;

literal : STR
    ;

%%

char **yynames =
#if YYDEBUG > 0
		 (char**)yyname;
#else
		 0;
#endif
