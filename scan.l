%{
#include <stdlib.h> 
#include <string.h> 
#include "y.tab.h"
extern void yyerror(const char *msg);
%}

%%
[A-Za-z][A-Za-z0-9_]*	{ yylval.s = strdup(yytext); return ID; }
 
%% 
int yywrap() { return 1; } 
int main() { 
  
    yylex(); 
    
    return 0;
}
