%option stack
%{
#include <stdlib.h> 
#include <string.h> 
#include <limits.h>
#include "node.h" 
#include "y.tab.h" 
char *dupstr(const char *s);
extern void yyerror(const char *msg);
int n;
%}

%x X_FILE X_COMMENT X_STRING X_CHAR X_STRING_BACKSLASH X_CHAR_BACKSLASH
%%
<X_FILE>"$$".*\n                      	; /* ignore comments */

<X_FILE>"$"                     yy_push_state(X_COMMENT);
<X_COMMENT>"$"					yy_pop_state();
<X_COMMENT>.|\n               	; /* ignore content */

^"program"			yy_push_state(X_FILE); return PROGRAM;
^"module"			yy_push_state(X_FILE); return MODULE;
<X_FILE>^"program"	return PROGRAM;
<X_FILE>^"module"	return MODULE;
<X_FILE>"start"		return START;
<X_FILE>^"end"		yy_pop_state(); return END;
<X_FILE>"function"	return FUNCTION;
<X_FILE>"public"	return PUBLIC;
<X_FILE>"forward"	return FORWARD;
<X_FILE>"number"	return NUMBER;
<X_FILE>"array"		return ARRAY;
<X_FILE>"void"		return VOID;
<X_FILE>"string"	return STRING;
<X_FILE>"const"		return CONST;
<X_FILE>"do"		return DO;
<X_FILE>"done"		return DONE;
<X_FILE>"if"		return IF;
<X_FILE>"then"		return THEN;
<X_FILE>"else"		return ELSE;
<X_FILE>"elif"		return ELIF;
<X_FILE>"fi"		return FI;
<X_FILE>"for"		return FOR;
<X_FILE>"until"		return UNTIL;
<X_FILE>"step"		return STEP;
<X_FILE>"repeat"	return REPEAT;
<X_FILE>"stop"		return STOP;
<X_FILE>"return"	return RETURN;
<X_FILE>"<="		return LE;
<X_FILE>">="		return GE;
<X_FILE>"~="		return NE;
<X_FILE>":="		return ATTR;

<X_FILE>[A-Za-z][A-Za-z0-9_]*		    { yylval.s = strdup(yytext); return ID; }

<X_FILE>"\'"                            { yy_push_state(X_CHAR); n = 0; }
<X_CHAR>"\\"                		    { yy_push_state(X_CHAR_BACKSLASH); }
<X_CHAR>"\'"                		    { yy_pop_state(); if (n > 1) yyerror("invalid character"); return CHAR; }
<X_CHAR>.                   		    { yylval.i = yytext[0]; n++; }
<X_CHAR_BACKSLASH>"\'"             		{ yylval.i = "\'"[0]; n++; yy_pop_state(); }
<X_CHAR_BACKSLASH>"\\"             		{ yylval.i = "\\"[0]; n++; yy_pop_state(); }
<X_CHAR_BACKSLASH>"n"              		{ yylval.i = "\n"[0]; n++; yy_pop_state(); }
<X_CHAR_BACKSLASH>"r"              		{ yylval.i = "\r"[0]; n++; yy_pop_state(); }
<X_CHAR_BACKSLASH>"t"              		{ yylval.i = "\t"[0]; n++; yy_pop_state(); }
<X_CHAR_BACKSLASH>[0-9A-Fa-f]{1,2} 		{ yylval.i = strtoul(yytext, 0, 16); n++; yy_pop_state(); }
<X_CHAR_BACKSLASH>.                		{ yyerror("non special character"); yy_pop_state(); }

<X_FILE>\"([^*"]|\*.)*\"			        { yylval.s = malloc(yyleng); *yylval.s = 0; REJECT; }
<X_FILE>"\""                                { yy_push_state(X_STRING);}
<X_STRING>"\\"                		        { yy_push_state(X_STRING_BACKSLASH); }
<X_STRING>"\""                		        { yy_pop_state(); return STR; }
<X_STRING>.                   		        { strcat(yylval.s, yytext); }
<X_STRING_BACKSLASH>"\""             		{ strcat(yylval.s, yytext); yy_pop_state(); }
<X_STRING_BACKSLASH>"\\"             		{ strcat(yylval.s, "\\"); yy_pop_state(); }
<X_STRING_BACKSLASH>"n"              		{ strcat(yylval.s, "\n"); yy_pop_state(); }
<X_STRING_BACKSLASH>"r"              		{ strcat(yylval.s, "\r"); yy_pop_state(); }
<X_STRING_BACKSLASH>"t"              		{ strcat(yylval.s, "\t"); yy_pop_state(); }
<X_STRING_BACKSLASH>[0-9A-Fa-f]{1,2} 		{ char* pChar = malloc(sizeof(char)); *pChar =  (char)(unsigned char)strtoul(yytext, 0, 16); strcat(yylval.s, pChar); yy_pop_state(); }
<X_STRING_BACKSLASH>.                		{ yyerror("non special character"); yy_pop_state(); }

<X_FILE>[0][0-7]*					{ int n = (int)strtol(yytext, 0, 8); if (n > INT_MAX || n < 0) yyerror("octal overflow"); yylval.i = n; return INTEGER; }
<X_FILE>[1-9][0-9]*				    { yylval.i = atoi(yytext); if (yylval.i > INT_MAX || yylval.i < 0) yyerror("decimal overflow"); return INTEGER; }
<X_FILE>"0x"[0-9a-fA-F]+			{ int n = (int)strtol(yytext+2, 0, 16); if (n > INT_MAX || n < 0) yyerror("hexadecimal overflow"); yylval.i = n; return INTEGER; }
<X_FILE>"0b"[0-1]+					{ int n = (int)strtol(yytext+2, 0, 2); if (n > INT_MAX || n < 0) yyerror("binary overflow"); yylval.i = n; return INTEGER; }
<X_FILE>[-+*/%!;,#&|~^<>=()?\[\]]	return *yytext;

<X_FILE>[ \t\n\r]+		; /* ignore whitespace */

<X_FILE>.				yyerror("Unknown character");

.						;

%% 
int yywrap() { return 1; } 
char *getyytext() { return yytext; }
