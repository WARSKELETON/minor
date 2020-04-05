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
    0,    0,    1,    2,    3,    3,    5,    5,    5,    5,
    5,    6,   12,   12,   10,   10,    7,    7,    7,   11,
   11,    8,   13,   13,   13,    4,   15,   15,   15,   15,
   15,   15,   15,   15,   15,   15,   14,   14,   16,   16,
   16,   16,   16,   16,   16,   16,   16,   16,   16,   16,
   16,   16,   16,    9,    9,
};
static const YYINT yylen[] = {                            2,
    1,    1,    5,    3,    0,    3,    1,    5,    3,    4,
    2,    6,    1,    2,    1,    1,    0,    1,    1,    0,
    3,    2,    1,    1,    1,    1,    5,   11,    9,    7,
    9,    2,    2,    1,    1,    1,    0,    2,    1,    1,
    2,    2,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    1,    1,
};
static const YYINT yydefred[] = {                         0,
    5,    5,    0,    1,    2,    0,    0,   37,    0,    4,
    0,    0,    0,   18,   19,    6,    7,    0,    3,   54,
   39,   55,    0,    0,   34,   35,   36,    0,    0,   40,
   38,    0,    0,   23,   24,   25,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   32,   33,   16,    0,   15,    0,
    0,   22,   37,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   52,   53,   20,    0,   10,    0,    0,
    0,    8,   37,    0,   27,    0,   13,   37,    0,   12,
    0,    0,    0,   14,   21,   30,   37,   37,    0,    0,
   37,   29,   31,    0,   28,
};
static const YYINT yydgoto[] = {                          3,
    4,    5,    6,   11,   16,   17,   18,   38,   30,   58,
   81,   90,   39,   12,   31,   32,
};
static const YYINT yysindex[] = {                      -153,
    0,    0,    0,    0,    0,  -20,  -43,    0, -177,    0,
 -245,  284, -109,    0,    0,    0,    0, -205,    0,    0,
    0,    0,  -21,  -21,    0,    0,    0,  -21,  -21,    0,
    0,  -33,  -96,    0,    0,    0, -173, -257, -223,   38,
   59,  101,  101,  -21,  -21,  -21,  -21,  -21,  -21,  -21,
  -21,  -21,  -21,  -21,    0,    0,    0, -213,    0, -241,
 -251,    0,    0,  -21,   92,   92,   92,  -59,  -59,  -56,
  -56,  -56,  -56,    0,    0,    0, -251,    0,  174,   68,
  -46,    0,    0,  -21,    0,  -21,    0,    0, -173,    0,
  222,   89,   80,    0,    0,    0,    0,    0,  187,  250,
    0,    0,    0,  278,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,  -70,    0,
    0,  -52,  -54,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  -40,    0,    0,
    0,  -11,   27,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  -28,
    0,    0,    0,    0,  146,  149,  162,  122,  133,  -22,
   -1,   10,   31,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
    0,    0,   49,  -34,    0,    0,   43,   -7,  -27,    0,
    0,    0,   34,  180,    0,  525,
};
#define YYTABLESIZE 611
static const YYINT yytable[] = {                         56,
   49,   54,   50,   46,   54,   20,   26,   22,   44,   47,
   48,   48,   89,   45,   48,    9,   29,   19,   11,   48,
   48,   41,   48,   28,   48,   55,   49,   54,   50,   60,
    9,   49,   61,   78,   62,   49,   48,   48,    9,   48,
   49,   49,   51,   49,   76,   49,   51,   41,   77,   82,
    7,   51,   51,   94,   51,   33,   51,   49,   49,   42,
   49,   34,   35,   50,   36,   37,   59,   50,   51,   51,
    0,   51,   50,   50,   46,   50,    0,   50,    0,   44,
   47,   95,   48,    0,   45,   42,   13,   14,   15,   50,
   50,    0,   50,   34,   35,   46,   36,   49,   54,   50,
   44,   47,    0,   48,   46,   45,    1,    2,    0,   44,
   47,    0,   48,    0,   45,    0,   46,    0,   49,   54,
   50,   44,   47,    0,   48,   46,   45,   49,   54,   50,
   44,   47,    0,   48,   47,   45,   48,   46,    0,   49,
   54,   50,   44,   47,    0,   48,    0,   45,   49,   54,
   50,   49,   54,   50,   43,   14,   15,    0,   43,    0,
   49,   54,   50,   43,   43,   44,   43,    0,   43,   44,
   34,   35,   57,   36,   44,   44,    0,   44,   45,   44,
   43,   46,   45,    0,    0,   46,    0,   45,    0,    0,
   46,   44,   45,    0,   47,   46,   17,   17,   47,   17,
   17,    0,    0,   47,   45,    0,    0,   46,   47,   26,
   26,   29,   17,   17,   17,   17,    0,    0,   28,   10,
   47,   11,   11,    0,   29,   87,   88,   51,   52,   53,
    0,   28,   53,    9,    9,   20,   21,   22,    0,    0,
    0,    8,   79,    0,    0,    0,    0,    0,    0,    0,
   48,    0,   48,   51,   52,   53,    0,   48,   48,   29,
    0,   41,   91,   41,   48,   48,   28,    0,   41,   41,
    0,   49,    0,   49,    0,    0,   99,  100,   49,   49,
  104,    0,   51,    0,   51,   49,   49,   29,    0,   51,
   51,    0,    0,    0,   28,    0,   51,   51,    0,   42,
    0,   42,    0,   50,    0,   50,   42,   42,    0,    0,
   50,   50,   63,    0,    0,   29,    0,   50,   50,    0,
    0,   29,   28,    0,   51,   52,   53,    0,   28,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   64,    0,
    0,    0,    0,    0,    0,   51,   52,   53,   86,    0,
    0,    0,   98,    0,   51,   52,   53,    0,    0,    0,
    0,    0,    0,   97,    0,    0,   51,   52,   53,    0,
    0,    0,    0,    0,    0,   51,   52,   53,   51,   52,
   53,    0,    0,    0,    0,    0,    0,   51,   52,   53,
    0,    0,    0,    0,   43,    0,   43,    0,    0,    0,
    0,   43,   43,    0,    0,   44,    0,   44,    0,    0,
    0,    0,   44,   44,    0,    0,    0,    0,   45,    0,
   45,   46,    0,   46,    0,   45,   45,    0,   46,   46,
   20,   21,   22,    0,   47,    0,   47,    0,    0,    0,
    0,   47,   47,   20,   21,   22,    0,   23,    0,   83,
   84,   85,   24,    0,    0,   25,   26,   27,    0,    0,
   23,    0,  101,    0,  102,   24,    0,    0,   25,   26,
   27,    0,    0,    0,    0,    0,    0,    0,   20,   21,
   22,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   23,    0,    0,    0,   96,
   24,    0,    0,   25,   26,   27,   20,   21,   22,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  103,    0,   23,    0,    0,    0,    0,   24,    0,
    0,   25,   26,   27,   20,   21,   22,    0,    0,    0,
   20,   21,   22,    0,    0,    0,    0,   40,   41,    0,
    0,   23,   42,   43,    0,  105,   24,   23,    0,   25,
   26,   27,   24,    0,    0,   25,   26,   27,   65,   66,
   67,   68,   69,   70,   71,   72,   73,   74,   75,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   80,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   92,    0,
   93,
};
static const YYINT yycheck[] = {                         33,
   60,   61,   62,   37,   61,  257,   59,  259,   42,   43,
   33,   45,   59,   47,   37,   59,   38,  263,   59,   42,
   43,   33,   45,   45,   47,   59,   60,   61,   62,   37,
   59,   33,  290,   61,  258,   37,   59,   60,   59,   62,
   42,   43,   33,   45,  258,   47,   37,   59,  290,   77,
    2,   42,   43,   88,   45,   13,   47,   59,   60,   33,
   62,  267,  268,   33,  270,  271,   33,   37,   59,   60,
   -1,   62,   42,   43,   37,   45,   -1,   47,   -1,   42,
   43,   89,   45,   -1,   47,   59,  264,  265,  266,   59,
   60,   -1,   62,  267,  268,   37,  270,   60,   61,   62,
   42,   43,   -1,   45,   37,   47,  260,  261,   -1,   42,
   43,   -1,   45,   -1,   47,   -1,   37,   -1,   60,   61,
   62,   42,   43,   -1,   45,   37,   47,   60,   61,   62,
   42,   43,   -1,   45,   43,   47,   45,   37,   -1,   60,
   61,   62,   42,   43,   -1,   45,   -1,   47,   60,   61,
   62,   60,   61,   62,   33,  265,  266,   -1,   37,   -1,
   60,   61,   62,   42,   43,   33,   45,   -1,   47,   37,
  267,  268,  269,  270,   42,   43,   -1,   45,   33,   47,
   59,   33,   37,   -1,   -1,   37,   -1,   42,   -1,   -1,
   42,   59,   47,   -1,   33,   47,  267,  268,   37,  270,
  271,   -1,   -1,   42,   59,   -1,   -1,   59,   47,  262,
  263,   38,  267,  268,  269,  270,   -1,   -1,   45,  263,
   59,  262,  263,   -1,   38,  272,  273,  287,  288,  289,
   -1,   45,  289,  262,  263,  257,  258,  259,   -1,   -1,
   -1,  262,   63,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  273,   -1,  275,  287,  288,  289,   -1,  280,  281,   38,
   -1,  273,   83,  275,  287,  288,   45,   -1,  280,  281,
   -1,  273,   -1,  275,   -1,   -1,   97,   98,  280,  281,
  101,   -1,  273,   -1,  275,  287,  288,   38,   -1,  280,
  281,   -1,   -1,   -1,   45,   -1,  287,  288,   -1,  273,
   -1,  275,   -1,  273,   -1,  275,  280,  281,   -1,   -1,
  280,  281,  275,   -1,   -1,   38,   -1,  287,  288,   -1,
   -1,   38,   45,   -1,  287,  288,  289,   -1,   45,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  280,   -1,
   -1,   -1,   -1,   -1,   -1,  287,  288,  289,  281,   -1,
   -1,   -1,  273,   -1,  287,  288,  289,   -1,   -1,   -1,
   -1,   -1,   -1,  275,   -1,   -1,  287,  288,  289,   -1,
   -1,   -1,   -1,   -1,   -1,  287,  288,  289,  287,  288,
  289,   -1,   -1,   -1,   -1,   -1,   -1,  287,  288,  289,
   -1,   -1,   -1,   -1,  273,   -1,  275,   -1,   -1,   -1,
   -1,  280,  281,   -1,   -1,  273,   -1,  275,   -1,   -1,
   -1,   -1,  280,  281,   -1,   -1,   -1,   -1,  273,   -1,
  275,  273,   -1,  275,   -1,  280,  281,   -1,  280,  281,
  257,  258,  259,   -1,  273,   -1,  275,   -1,   -1,   -1,
   -1,  280,  281,  257,  258,  259,   -1,  274,   -1,  276,
  277,  278,  279,   -1,   -1,  282,  283,  284,   -1,   -1,
  274,   -1,  276,   -1,  278,  279,   -1,   -1,  282,  283,
  284,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  257,  258,
  259,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  274,   -1,   -1,   -1,  278,
  279,   -1,   -1,  282,  283,  284,  257,  258,  259,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  272,   -1,  274,   -1,   -1,   -1,   -1,  279,   -1,
   -1,  282,  283,  284,  257,  258,  259,   -1,   -1,   -1,
  257,  258,  259,   -1,   -1,   -1,   -1,   23,   24,   -1,
   -1,  274,   28,   29,   -1,  278,  279,  274,   -1,  282,
  283,  284,  279,   -1,   -1,  282,  283,  284,   44,   45,
   46,   47,   48,   49,   50,   51,   52,   53,   54,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   64,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   84,   -1,
   86,
};
#define YYFINAL 3
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 290
#define YYUNDFTOKEN 309
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"'!'",0,0,0,"'%'","'&'",0,"'('",0,"'*'","'+'",0,"'-'",0,"'/'",0,0,0,0,0,0,0,0,0,
0,0,"';'","'<'","'='","'>'","'?'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,"'['",0,0,"'^'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,"'|'",0,"'~'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"INTEGER","ID","STR","PROGRAM","MODULE",
"START","END","FUNCTION","PUBLIC","FORWARD","NUMBER","ARRAY","VOID","STRING",
"CONST","DONE","DO","IF","THEN","ELSE","ELIF","FI","FOR","UNTIL","STEP",
"REPEAT","STOP","RETURN","ADDR","UMINUS","LE","GE","NE","ATTR",0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : file",
"file : program",
"file : module",
"program : PROGRAM decls START body END",
"module : MODULE decls END",
"decls :",
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
"vars : vars ';' var",
"var : type ID",
"type : NUMBER",
"type : ARRAY",
"type : STRING",
"body : instrs",
"instr : IF expr THEN instrs FI",
"instr : IF expr THEN instrs ELIF expr THEN instrs ELSE instrs FI",
"instr : IF expr THEN instrs ELIF expr THEN instrs FI",
"instr : IF expr THEN instrs ELSE instrs FI",
"instr : FOR expr UNTIL expr STEP expr DO instrs DONE",
"instr : expr ';'",
"instr : expr '!'",
"instr : REPEAT",
"instr : STOP",
"instr : RETURN",
"instrs :",
"instrs : instrs instr",
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
#line 129 "gram.y"

char **yynames =
#if YYDEBUG > 0
		 (char**)yyname;
#else
		 0;
#endif
#line 432 "y.tab.c"

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
