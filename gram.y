%{
#include <stdio.h>
#include <stdlib.h>

int yylex();
void yyerror(char *);

%}

%union {
    int i;          /* integer value */
    char *s;        /* symbol name or string literal */
    int *vi;        /* integer vector */
}

%token <i> INTEGER
%token <s> ID STR

%%

start: ;
