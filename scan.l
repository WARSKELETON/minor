%{
#include <stdlib.h> 
#include <string.h> 
#include "node.h" 
#include "y.tab.h" 
char *dupstr(const char *s);
extern void yyerror(const char *msg);
%}

%%
"$$".*			; /* comment */
"program"	return PROGRAM;
"module"	return MODULE;
"start"		return START;
"end"		return END;
"function"	return FUNCTION;
"public"	return PUBLIC;
"forward"	return FORWARD;
"number"	return NUMBER;
"array"		return ARRAY;
"void"		return VOID;
"string"	return STRING;
"const"		return CONST;
"do"		return DO;
"done"		return DONE;
"if"		return IF;
"then"		return THEN;
"else"		return ELSE;
"elif"		return ELIF;
"fi"		return FI;
"for"		return FOR;
"until"		return UNTIL;
"step"		return STEP;
"repeat"	return REPEAT;
"stop"		return STOP;
"return"	return RETURN;
"<="		return LE;
">="		return GE;
"~="		return NE;
":="		return ATTR;

[A-Za-z][A-Za-z0-9_]*		{ yylval.s = strdup(yytext); return ID; }
\'(([^']|\\[nrt']){1})\'	{ yytext[yyleng-1] = 0; yylval.i = strtol(yytext, 0, 10); return INTEGER; } /* resolver este e overflows */
\"(([^"]|\\[nrt"])*)\"		{ yytext[yyleng-1] = 0; yylval.s = dupstr(yytext+1); return STR; }
[0][0-7]*					{ yylval.i = strtol(yytext, 0, 8); return INTEGER; }
[0-9]+						{ yylval.i = strtol(yytext, 0, 10); return INTEGER; } /* Ver melhor */
"0x"[0-9a-fA-F]+			{ yylval.i = strtol(yytext, 0, 0); printf("%d\n", yylval.i); return INTEGER; }
"0b"[0-1]+					{ yylval.i = strtol(yytext+2, 0, 2); printf("%d\n", yylval.i); return INTEGER; }
[-+*/%!;,#&|~^<>=()?\[\]]	return *yytext;

[ \t\n\r]+		; /* ignore whitespace */

.			yyerror("Unknown character");

%% 
int yywrap() { return 1; } 
char *getyytext() { return yytext; }
