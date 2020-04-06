/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20140715

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "gram.y"
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
#line 14 "gram.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
    int i;          /* integer value */
    char *s;        /* symbol name or string literal */
    int *vi;        /* integer vector */
    Node *n;	    /* tree node */
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 46 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define INTEGER 257
#define ID 258
#define STR 259
#define PROGRAM 260
#define MODULE 261
#define START 262
#define END 263
#define FUNCTION 264
#define PUBLIC 265
#define FORWARD 266
#define NUMBER 267
#define ARRAY 268
#define VOID 269
#define STRING 270
#define CONST 271
#define DONE 272
#define DO 273
#define IF 274
#define THEN 275
#define ELSE 276
#define ELIF 277
#define FI 278
#define FOR 279
#define UNTIL 280
#define STEP 281
#define REPEAT 282
#define STOP 283
#define RETURN 284
#define ADDR 285
#define UMINUS 286
#define LE 287
#define GE 288
#define NE 289
#define ATTR 290
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    0,    1,    2,    3,    3,    3,    5,    5,    5,
    5,    5,    6,   12,   12,   10,   10,    7,    7,    7,
   11,   11,   11,    8,   13,   13,   13,    4,   15,   15,
   15,   15,   15,   15,   15,   15,   15,   15,   18,   17,
   17,   14,   14,   16,   16,   16,   16,   16,   16,   16,
   16,   16,   16,   16,   16,   16,   16,   16,   16,    9,
    9,
};
static const YYINT yylen[] = {                            2,
    1,    1,    5,    3,    0,    1,    3,    1,    5,    3,
    4,    2,    6,    1,    2,    1,    1,    0,    1,    1,
    0,    1,    3,    2,    1,    1,    1,    1,    5,    8,
    6,    7,    9,    2,    2,    1,    1,    1,    4,    1,
    2,    0,    2,    3,    1,    1,    2,    2,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    3,    3,    1,
    1,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,    1,    2,    0,   19,   20,    0,    6,
    8,    0,    0,    0,   42,    0,   25,   26,   27,    0,
    0,    0,    4,   17,    0,   16,    0,    0,    7,    0,
    0,   24,    0,    3,   60,   45,   61,    0,    0,   36,
   37,   38,    0,    0,    0,   46,   43,    0,    0,   11,
   22,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   34,   35,
    9,   14,   42,    0,   13,   42,    0,   44,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   58,   59,   15,
   23,    0,    0,   42,    0,   29,    0,   40,    0,    0,
    0,   42,   31,   41,    0,   32,   42,    0,   42,    0,
   30,    0,   33,
};
static const YYINT yydgoto[] = {                          3,
    4,    5,    9,   27,   10,   11,   12,   21,   46,   25,
   52,   75,   22,   28,   47,   48,   97,   98,
};
static const YYINT yysindex[] = {                      -253,
 -248, -248,    0,    0,    0, -165,    0,    0,  -57,    0,
    0, -119,  -54,  -37,    0, -248,    0,    0,    0, -234,
 -259, -216,    0,    0, -199,    0, -200,  258,    0, -224,
 -190,    0, -234,    0,    0,    0,    0,   78,   78,    0,
    0,    0,   78,   78,   78,    0,    0,  -33, -190,    0,
    0,  -56,   44,   65,   72,  128,  128,   78,   78,   78,
   78,   78,   78,   78,   78,   78,   78,   78,    0,    0,
    0,    0,    0, -234,    0,    0,   78,    0,  266,  266,
  266,   33,   33,  -60,  -60,  -60,  -60,    0,    0,    0,
    0,  212,   93,    0,   78,    0, -225,    0,   78,   84,
  100,    0,    0,    0,  121,    0,    0,  140,    0,  258,
    0,  240,    0,
};
static const YYINT yyrindex[] = {                         0,
  133,  280,    0,    0,    0,   46,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   79,    0,    0,    0,    0,
  -27,    0,    0,    0,    0,    0,    0,  -18,    0,    9,
    0,    0,  -46,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  -11,   24,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  178,  181,
  201,  154,  165,  -22,    2,   13,   37,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   30,
    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
    0,    0,   69,    3,   76,    0,   82,   57,  -25,    0,
    0,    0,   71,  262,    0,  518,    0,    1,
};
#define YYTABLESIZE 617
static const YYINT yytable[] = {                         70,
   68,   16,   74,   60,   16,   50,    1,    2,   58,   61,
   54,   62,   21,   59,   54,    6,    7,    8,   54,   54,
   54,   47,   54,   71,   54,   69,   63,   68,   64,   47,
   31,   12,   17,   18,   55,   19,   54,   54,   55,   54,
   28,   32,   55,   55,   55,   57,   55,   47,   55,   57,
  102,   95,  103,   57,   57,   57,   48,   57,   33,   57,
   55,   55,   34,   55,   48,   49,   35,   10,   37,   56,
   13,   57,   57,   56,   57,   90,   30,   56,   56,   56,
   60,   56,   48,   56,   26,   58,   61,   14,   62,   51,
   59,   29,   63,   68,   64,   56,   56,  104,   56,    7,
    8,   60,    0,   63,   68,   64,   58,   61,   60,   62,
    0,   59,   78,   58,   61,   45,   62,   43,   59,    0,
    0,   45,   44,   43,   63,   68,   64,    0,   44,   60,
   91,   63,   68,   64,   58,   61,   60,   62,    0,   59,
    0,   58,   61,    0,   62,    0,   59,   17,   18,    0,
   19,   20,   63,   68,   64,    0,    0,   60,    0,   63,
   68,   64,   58,   61,   60,   62,    0,   59,    0,   58,
   61,    0,   62,    0,   59,    0,    0,   45,    0,   43,
   63,   68,   64,    0,   44,    0,   49,   63,   68,   64,
   49,    5,    0,    0,   49,   49,   49,   50,   49,    0,
   49,   50,    0,    0,   15,   50,   50,   50,   23,   50,
   51,   50,   49,   52,   51,   72,   73,   52,   51,   51,
    0,   52,   52,   50,   51,   21,   21,   52,   67,   17,
   18,   24,   19,   53,   12,   12,   51,   53,    0,   52,
    0,   53,   53,   28,   28,    0,    0,   53,    0,   45,
   54,   43,   54,   65,   66,   67,   44,   54,   54,   53,
    0,   47,    0,   47,   54,   54,    0,    0,   47,   47,
   10,   10,    0,    0,   55,    0,   55,   45,    0,   43,
    0,   55,   55,    0,   44,   57,    0,   57,   55,   55,
    0,    0,   57,   57,    0,   45,   48,   43,   48,   57,
   57,    0,   44,   48,   48,   39,   39,   39,   61,   56,
   62,   56,   18,   18,   18,   18,   56,   56,   76,   65,
   66,   67,    0,   56,   56,   63,   68,   64,    0,    0,
   65,   66,   67,    0,   35,   36,   37,   92,    5,    0,
   35,   36,   37,    0,   77,   18,   18,    0,   18,   18,
    0,   65,   66,   67,    0,  100,    0,   38,   65,   66,
   67,  106,   39,  108,    0,   40,   41,   42,  110,    0,
  112,    0,    0,   99,  107,    0,    0,    0,    0,   65,
   66,   67,    0,    0,    0,    0,   65,   66,   67,    0,
    0,    0,    0,  109,    5,    0,   35,   36,   37,   18,
   18,    0,   18,   18,    0,    0,    0,   65,   66,   67,
    0,    0,    0,   38,   65,   66,   67,  111,   39,    0,
    0,   40,   41,   42,    0,    0,   49,    0,   49,    0,
    0,    0,    0,   49,   49,    0,    0,   50,    0,   50,
    0,    0,    0,    0,   50,   50,    0,    0,    0,    0,
   51,    0,   51,   52,    0,   52,    0,   51,   51,    0,
   52,   52,    0,    0,    0,    0,    0,    0,   35,   36,
   37,    0,    0,   53,    0,   53,    0,    0,    0,    0,
   53,   53,    0,    0,    0,   38,    0,   94,   95,   96,
   39,    0,    0,   40,   41,   42,   35,   36,   37,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  113,    0,   38,   35,   36,   37,    0,   39,    0,
    0,   40,   41,   42,    0,    0,    0,    0,    0,    0,
    0,   38,    0,    0,    0,    0,   39,    0,    0,   40,
   41,   42,    5,    0,    0,    0,   18,   18,    0,   18,
   18,    0,   65,   66,   67,   53,   54,    0,    0,    0,
   55,   56,   57,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   79,   80,   81,   82,   83,
   84,   85,   86,   87,   88,   89,    0,    0,    0,    0,
    0,    0,    0,    0,   93,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  101,    0,    0,    0,  105,
};
static const YYINT yycheck[] = {                         33,
   61,   59,   59,   37,   59,   31,  260,  261,   42,   43,
   33,   45,   59,   47,   37,  264,  265,  266,   41,   42,
   43,   33,   45,   49,   47,   59,   60,   61,   62,   41,
  290,   59,  267,  268,   33,  270,   59,   60,   37,   62,
   59,  258,   41,   42,   43,   33,   45,   59,   47,   37,
  276,  277,  278,   41,   42,   43,   33,   45,  258,   47,
   59,   60,  263,   62,   41,  290,  257,   59,  259,   33,
    2,   59,   60,   37,   62,   73,   20,   41,   42,   43,
   37,   45,   59,   47,   14,   42,   43,    6,   45,   33,
   47,   16,   60,   61,   62,   59,   60,   97,   62,  265,
  266,   37,   -1,   60,   61,   62,   42,   43,   37,   45,
   -1,   47,   41,   42,   43,   38,   45,   40,   47,   -1,
   -1,   38,   45,   40,   60,   61,   62,   -1,   45,   37,
   74,   60,   61,   62,   42,   43,   37,   45,   -1,   47,
   -1,   42,   43,   -1,   45,   -1,   47,  267,  268,   -1,
  270,  271,   60,   61,   62,   -1,   -1,   37,   -1,   60,
   61,   62,   42,   43,   37,   45,   -1,   47,   -1,   42,
   43,   -1,   45,   -1,   47,   -1,   -1,   38,   -1,   40,
   60,   61,   62,   -1,   45,   -1,   33,   60,   61,   62,
   37,   59,   -1,   -1,   41,   42,   43,   33,   45,   -1,
   47,   37,   -1,   -1,  262,   41,   42,   43,  263,   45,
   33,   47,   59,   33,   37,  272,  273,   37,   41,   42,
   -1,   41,   42,   59,   47,  272,  273,   47,  289,  267,
  268,  269,  270,   33,  262,  263,   59,   37,   -1,   59,
   -1,   41,   42,  262,  263,   -1,   -1,   47,   -1,   38,
  273,   40,  275,  287,  288,  289,   45,  280,  281,   59,
   -1,  273,   -1,  275,  287,  288,   -1,   -1,  280,  281,
  262,  263,   -1,   -1,  273,   -1,  275,   38,   -1,   40,
   -1,  280,  281,   -1,   45,  273,   -1,  275,  287,  288,
   -1,   -1,  280,  281,   -1,   38,  273,   40,  275,  287,
  288,   -1,   45,  280,  281,  276,  277,  278,   43,  273,
   45,  275,  267,  268,  269,  270,  280,  281,  275,  287,
  288,  289,   -1,  287,  288,   60,   61,   62,   -1,   -1,
  287,  288,  289,   -1,  257,  258,  259,   76,   59,   -1,
  257,  258,  259,   -1,  280,  267,  268,   -1,  270,  271,
   -1,  287,  288,  289,   -1,   94,   -1,  274,  287,  288,
  289,  278,  279,  102,   -1,  282,  283,  284,  107,   -1,
  109,   -1,   -1,  281,  275,   -1,   -1,   -1,   -1,  287,
  288,  289,   -1,   -1,   -1,   -1,  287,  288,  289,   -1,
   -1,   -1,   -1,  273,  262,   -1,  257,  258,  259,  267,
  268,   -1,  270,  271,   -1,   -1,   -1,  287,  288,  289,
   -1,   -1,   -1,  274,  287,  288,  289,  278,  279,   -1,
   -1,  282,  283,  284,   -1,   -1,  273,   -1,  275,   -1,
   -1,   -1,   -1,  280,  281,   -1,   -1,  273,   -1,  275,
   -1,   -1,   -1,   -1,  280,  281,   -1,   -1,   -1,   -1,
  273,   -1,  275,  273,   -1,  275,   -1,  280,  281,   -1,
  280,  281,   -1,   -1,   -1,   -1,   -1,   -1,  257,  258,
  259,   -1,   -1,  273,   -1,  275,   -1,   -1,   -1,   -1,
  280,  281,   -1,   -1,   -1,  274,   -1,  276,  277,  278,
  279,   -1,   -1,  282,  283,  284,  257,  258,  259,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  272,   -1,  274,  257,  258,  259,   -1,  279,   -1,
   -1,  282,  283,  284,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  274,   -1,   -1,   -1,   -1,  279,   -1,   -1,  282,
  283,  284,  263,   -1,   -1,   -1,  267,  268,   -1,  270,
  271,   -1,  287,  288,  289,   38,   39,   -1,   -1,   -1,
   43,   44,   45,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   58,   59,   60,   61,   62,
   63,   64,   65,   66,   67,   68,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   77,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   95,   -1,   -1,   -1,   99,
};
#define YYFINAL 3
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 290
#define YYUNDFTOKEN 311
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"'!'",0,0,0,"'%'","'&'",0,"'('","')'","'*'","'+'",0,"'-'",0,"'/'",0,0,0,0,0,0,0,
0,0,0,0,"';'","'<'","'='","'>'","'?'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,"'['",0,0,"'^'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,"'|'",0,"'~'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"INTEGER","ID","STR","PROGRAM","MODULE",
"START","END","FUNCTION","PUBLIC","FORWARD","NUMBER","ARRAY","VOID","STRING",
"CONST","DONE","DO","IF","THEN","ELSE","ELIF","FI","FOR","UNTIL","STEP",
"REPEAT","STOP","RETURN","ADDR","UMINUS","LE","GE","NE","ATTR",0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : file",
"file : program",
"file : module",
"program : PROGRAM decls START body END",
"module : MODULE decls END",
"decls :",
"decls : decl",
"decls : decls ';' decl",
"decl : func",
"decl : qualifier CONST var ATTR literal",
"decl : qualifier CONST var",
"decl : qualifier var ATTR literal",
"decl : qualifier var",
"func : FUNCTION qualifier functype ID vars funcend",
"funcend : DONE",
"funcend : DO body",
"functype : type",
"functype : VOID",
"qualifier :",
"qualifier : PUBLIC",
"qualifier : FORWARD",
"vars :",
"vars : var",
"vars : vars ';' var",
"var : type ID",
"type : NUMBER",
"type : ARRAY",
"type : STRING",
"body : instrs",
"instr : IF expr THEN instrs FI",
"instr : IF expr THEN instrs elifs ELSE instrs FI",
"instr : IF expr THEN instrs elifs FI",
"instr : IF expr THEN instrs ELSE instrs FI",
"instr : FOR expr UNTIL expr STEP expr DO instrs DONE",
"instr : expr ';'",
"instr : expr '!'",
"instr : REPEAT",
"instr : STOP",
"instr : RETURN",
"elif : ELIF expr THEN instrs",
"elifs : elif",
"elifs : elifs elif",
"instrs :",
"instrs : instrs instr",
"expr : '(' expr ')'",
"expr : ID",
"expr : literal",
"expr : '-' expr",
"expr : '&' expr",
"expr : expr '+' expr",
"expr : expr '-' expr",
"expr : expr '*' expr",
"expr : expr '/' expr",
"expr : expr '%' expr",
"expr : expr '<' expr",
"expr : expr '>' expr",
"expr : expr GE expr",
"expr : expr LE expr",
"expr : expr NE expr",
"expr : expr '=' expr",
"literal : INTEGER",
"literal : STR",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 140 "gram.y"

char **yynames =
#if YYDEBUG > 0
		 (char**)yyname;
#else
		 0;
#endif
#line 443 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    YYERROR_CALL("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                yys = yyname[YYTRANSLATE(yychar)];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    YYERROR_CALL("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
