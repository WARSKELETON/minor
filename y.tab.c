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
    0,    0,    1,    1,    2,    4,    4,    5,    5,    5,
    5,    5,    5,    6,    6,    6,    6,   13,   13,   11,
   11,    7,    7,    7,   10,   10,   12,   12,    8,   14,
   14,   14,    3,   15,   15,   15,   15,   15,   15,   15,
   15,   15,   15,   15,   16,   16,   16,   16,   16,   16,
   16,   16,   16,   16,   16,   16,   16,   16,    9,    9,
};
static const YYINT yylen[] = {                            2,
    1,    1,    4,    5,    3,    1,    2,    1,    1,    4,
    2,    3,    1,    6,    4,    5,    5,    1,    2,    1,
    1,    2,    1,    1,    1,    1,    1,    3,    2,    1,
    1,    1,    1,    5,   11,    9,    7,    9,    2,    2,
    1,    1,    2,    1,    1,    2,    2,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    3,    1,    1,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,    1,    2,    0,    0,   25,   26,   30,
   31,   32,   24,    8,    0,    6,    9,    0,    0,    0,
    0,    0,   59,   60,    0,    0,   41,   42,    0,    0,
    0,    0,   45,   33,    0,   21,    0,    0,   20,    0,
    7,    0,    0,   22,   29,    5,    0,    0,    0,    0,
    0,    3,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   39,   40,    0,    0,    0,    0,   12,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   57,   58,    0,   18,    0,   27,    0,   15,    4,
   10,    0,    0,    0,   16,   19,    0,   17,    0,    0,
   34,    0,   14,   28,    0,    0,    0,   37,    0,    0,
    0,    0,    0,   36,   38,    0,   35,
};
static const YYINT yydgoto[] = {                          3,
    4,    5,   32,   15,   16,   17,   18,   19,   33,   20,
   38,   88,   89,   21,   34,   35,
};
static const YYINT yysindex[] = {                      -183,
  404,  476,    0,    0,    0,  -37,  -63,    0,    0,    0,
    0,    0,    0,    0,  414,    0,    0, -235, -274, -225,
 -222,  468,    0,    0,  -32,  -32,    0,    0,  -32,  -32,
  -32, -212,    0,    0,  -33,    0, -249, -198,    0,  -37,
    0, -236, -188,    0,    0,    0,   88,  109,  151,  151,
  151,    0,  -32,  -32,  -32,  -32,  -32,  -32,  -32,  -32,
  -32,  -32,  -32,    0,    0, -185, -220, -180, -188,    0,
  -37,  -32,  -38,  -38,  -38,   49,   49,  -59,  -59,  -59,
  -59,    0,    0, -220,    0,  -37,    0,  -56,    0,    0,
    0, -196,  118,  -56,    0,    0, -235,    0,  -37,  -32,
    0,  -32,    0,    0, -190,  139,  130,    0,  -37,  -37,
 -184, -179,  -37,    0,    0, -189,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  331, -204,
    0,    0,    0,    0,    0,    0,    0,    0,  296,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  362,    0,    0,    0,    0,    0,    0,  313,  248,
  276,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  378,  427,  447,  181,  341,   -3,   25,   53,
   81,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
    0,    0,  -25,   95,   16,    0,    0,    7,  -26,   92,
   64,   18,  -39,    4,  -34,  723,
};
#define YYTABLESIZE 825
static const YYINT yytable[] = {                         65,
   31,   63,   97,   55,   56,   31,   57,   30,   53,   56,
   39,   57,   30,   54,   68,   43,   70,   10,   11,   36,
   12,   58,   63,   59,   42,   64,   58,   63,   59,   53,
   41,   10,   11,   53,   12,   45,   92,   41,   53,   53,
   39,   53,   91,   53,   95,   44,   10,   11,   98,   12,
   52,   85,   86,   69,  103,   53,   53,   54,   53,   67,
   96,   54,   23,   23,  105,   23,   54,   54,   23,   54,
   24,   54,   84,   87,  111,  112,    1,    2,  116,   99,
  100,  101,   90,   54,   54,   56,   54,  108,  117,   56,
   87,  113,  115,  114,   56,   56,   22,   56,   37,   56,
   66,   94,    0,  104,    0,    0,    0,    0,   58,   63,
   59,   56,   56,   55,   56,    0,    0,   55,    0,    0,
    0,    0,   55,   55,   55,   55,    0,   55,    0,   53,
   56,    0,   57,    0,   54,    0,    0,    0,    0,   55,
   55,    0,   55,    0,    0,   55,    0,   58,   63,   59,
   53,   56,    0,   57,   55,   54,    0,    0,    0,   53,
   56,    0,   57,    0,   54,    0,   55,    0,   58,   63,
   59,   53,   56,    0,   57,   55,   54,   58,   63,   59,
   53,   56,    0,   57,    0,   54,    0,   55,    0,   58,
   63,   59,   53,   56,    0,   57,    0,   54,   58,   63,
   59,    8,    9,   10,   11,   36,   12,    0,    0,    0,
   58,   63,   59,   48,    0,   85,   86,   48,    0,   23,
    0,   24,   48,   48,   23,   48,   24,   48,    0,   62,
    0,    0,    0,    0,    0,    0,   25,    0,    0,   48,
    0,   26,    0,    0,   27,   28,   29,    0,   60,   61,
   62,    0,    0,   60,   61,   62,    0,    0,   53,   53,
   53,   53,   53,   53,   53,    0,   53,   53,   53,   53,
    0,   53,   53,   53,   53,    0,   53,   53,    0,    0,
   46,    0,    0,   53,   53,    0,   54,   54,   54,   54,
   54,   54,   54,    0,   54,   54,   54,   54,    0,   54,
   54,   54,   54,    0,   54,   54,   46,    0,   47,    0,
    0,   54,   54,    0,   56,   56,   56,   56,   56,   56,
   56,    0,   56,   56,   56,   56,    0,   56,   56,   56,
   56,    0,   56,   56,   47,   60,   61,   62,    0,   56,
   56,    0,   55,   55,   55,   55,   55,   55,   55,    0,
   55,   55,   55,   55,   44,   55,   55,   55,   55,    0,
   55,   55,   71,    0,    0,    0,    0,   55,   55,    0,
    0,   43,    0,   49,   60,   61,   62,   49,    0,    0,
    0,    0,   49,   49,    0,   49,    0,   49,   72,   13,
    0,    0,    0,    0,    0,   60,   61,   62,  102,   49,
    0,    0,  110,    0,   60,   61,   62,    0,    0,    0,
   50,    0,    0,  109,   50,    0,   60,   61,   62,   50,
   11,    0,    0,    0,   50,   60,   61,   62,    0,    0,
    0,    0,    0,    0,    0,    0,   50,   60,   61,   62,
    0,    0,   48,   48,   48,   48,   48,   48,   48,    0,
   48,   48,   48,   48,    0,   48,   48,   48,   48,   51,
   48,   48,   14,   51,    0,    0,    0,    0,   51,    0,
    0,    0,   14,   51,    0,    0,    0,    0,    0,   52,
    0,    0,    0,   52,    0,   51,    0,    0,   52,    0,
    0,    0,    0,   52,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   52,    0,    0,    0,   46,
   46,   46,   46,   46,   46,   46,    0,   46,   46,   46,
   46,    0,   46,   46,   46,   46,   14,   46,   46,    0,
    0,    0,    0,    0,   14,    0,    0,   47,   47,   47,
   47,   47,   47,   47,    0,   47,   47,   47,   47,    0,
   47,   47,   47,   47,    0,   47,   47,   44,   44,   44,
   44,   44,   44,   44,    0,   44,   44,   44,    0,    0,
    0,   44,   44,   44,   43,   43,   43,   43,   43,   43,
   43,    0,   43,   43,   43,    0,    0,    0,   43,   43,
   43,    0,   13,   13,   13,   13,   13,   13,   13,    0,
   13,   13,   49,   49,   49,   49,   49,   49,   49,    0,
   49,   49,   49,   49,    0,   49,   49,   49,   49,    0,
   49,   49,    0,   11,   11,   11,   11,   11,   11,   11,
    0,   11,   11,    0,    0,    0,    0,    0,    0,   50,
   50,   50,   50,   50,   50,   50,    0,   50,   50,   50,
   50,    0,   50,   50,   50,   50,    0,   50,   50,    0,
    0,    0,    0,    0,    0,    6,    0,    7,    8,    9,
   10,   11,    0,   12,   13,   40,    0,    7,    8,    9,
   10,   11,    0,   12,   13,    0,    0,    0,   51,   51,
   51,   51,   51,   51,   51,    0,   51,   51,   51,   51,
    0,   51,   51,   51,   51,    0,   51,   51,   52,   52,
   52,   52,   52,   52,   52,    0,   52,   52,   52,   52,
    0,   52,   52,   52,   52,    0,   52,   52,    0,    0,
   46,    7,    8,    9,   10,   11,    0,   12,   13,    7,
    8,    9,   10,   11,    0,   12,   13,   47,   48,    0,
    0,   49,   50,   51,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   73,   74,   75,   76,   77,
   78,   79,   80,   81,   82,   83,    0,    0,    0,    0,
    0,    0,    0,    0,   93,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  106,    0,  107,
};
static const YYINT yycheck[] = {                         33,
   38,   61,   59,   37,   43,   38,   45,   45,   42,   43,
    7,   45,   45,   47,   40,  290,   43,  267,  268,  269,
  270,   60,   61,   62,   18,   59,   60,   61,   62,   33,
   15,  267,  268,   37,  270,  258,   71,   22,   42,   43,
   37,   45,   69,   47,   84,  271,  267,  268,   88,  270,
  263,  272,  273,  290,   94,   59,   60,   33,   62,  258,
   86,   37,  267,  268,   99,  270,   42,   43,  257,   45,
  259,   47,  258,   67,  109,  110,  260,  261,  113,  276,
  277,  278,  263,   59,   60,   33,   62,  278,  278,   37,
   84,  276,  272,  278,   42,   43,    2,   45,    7,   47,
   37,   84,   -1,   97,   -1,   -1,   -1,   -1,   60,   61,
   62,   59,   60,   33,   62,   -1,   -1,   37,   -1,   -1,
   -1,   -1,   42,   43,   37,   45,   -1,   47,   -1,   42,
   43,   -1,   45,   -1,   47,   -1,   -1,   -1,   -1,   59,
   60,   -1,   62,   -1,   -1,   37,   -1,   60,   61,   62,
   42,   43,   -1,   45,   37,   47,   -1,   -1,   -1,   42,
   43,   -1,   45,   -1,   47,   -1,   37,   -1,   60,   61,
   62,   42,   43,   -1,   45,   37,   47,   60,   61,   62,
   42,   43,   -1,   45,   -1,   47,   -1,   37,   -1,   60,
   61,   62,   42,   43,   -1,   45,   -1,   47,   60,   61,
   62,  265,  266,  267,  268,  269,  270,   -1,   -1,   -1,
   60,   61,   62,   33,   -1,  272,  273,   37,   -1,  257,
   -1,  259,   42,   43,  257,   45,  259,   47,   -1,  289,
   -1,   -1,   -1,   -1,   -1,   -1,  274,   -1,   -1,   59,
   -1,  279,   -1,   -1,  282,  283,  284,   -1,  287,  288,
  289,   -1,   -1,  287,  288,  289,   -1,   -1,  262,  263,
  264,  265,  266,  267,  268,   -1,  270,  271,  272,  273,
   -1,  275,  276,  277,  278,   -1,  280,  281,   -1,   -1,
   33,   -1,   -1,  287,  288,   -1,  262,  263,  264,  265,
  266,  267,  268,   -1,  270,  271,  272,  273,   -1,  275,
  276,  277,  278,   -1,  280,  281,   59,   -1,   33,   -1,
   -1,  287,  288,   -1,  262,  263,  264,  265,  266,  267,
  268,   -1,  270,  271,  272,  273,   -1,  275,  276,  277,
  278,   -1,  280,  281,   59,  287,  288,  289,   -1,  287,
  288,   -1,  262,  263,  264,  265,  266,  267,  268,   -1,
  270,  271,  272,  273,   59,  275,  276,  277,  278,   -1,
  280,  281,  275,   -1,   -1,   -1,   -1,  287,  288,   -1,
   -1,   59,   -1,   33,  287,  288,  289,   37,   -1,   -1,
   -1,   -1,   42,   43,   -1,   45,   -1,   47,  280,   59,
   -1,   -1,   -1,   -1,   -1,  287,  288,  289,  281,   59,
   -1,   -1,  273,   -1,  287,  288,  289,   -1,   -1,   -1,
   33,   -1,   -1,  275,   37,   -1,  287,  288,  289,   42,
   59,   -1,   -1,   -1,   47,  287,  288,  289,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   59,  287,  288,  289,
   -1,   -1,  262,  263,  264,  265,  266,  267,  268,   -1,
  270,  271,  272,  273,   -1,  275,  276,  277,  278,   33,
  280,  281,   59,   37,   -1,   -1,   -1,   -1,   42,   -1,
   -1,   -1,   59,   47,   -1,   -1,   -1,   -1,   -1,   33,
   -1,   -1,   -1,   37,   -1,   59,   -1,   -1,   42,   -1,
   -1,   -1,   -1,   47,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   59,   -1,   -1,   -1,  262,
  263,  264,  265,  266,  267,  268,   -1,  270,  271,  272,
  273,   -1,  275,  276,  277,  278,   59,  280,  281,   -1,
   -1,   -1,   -1,   -1,   59,   -1,   -1,  262,  263,  264,
  265,  266,  267,  268,   -1,  270,  271,  272,  273,   -1,
  275,  276,  277,  278,   -1,  280,  281,  262,  263,  264,
  265,  266,  267,  268,   -1,  270,  271,  272,   -1,   -1,
   -1,  276,  277,  278,  262,  263,  264,  265,  266,  267,
  268,   -1,  270,  271,  272,   -1,   -1,   -1,  276,  277,
  278,   -1,  262,  263,  264,  265,  266,  267,  268,   -1,
  270,  271,  262,  263,  264,  265,  266,  267,  268,   -1,
  270,  271,  272,  273,   -1,  275,  276,  277,  278,   -1,
  280,  281,   -1,  262,  263,  264,  265,  266,  267,  268,
   -1,  270,  271,   -1,   -1,   -1,   -1,   -1,   -1,  262,
  263,  264,  265,  266,  267,  268,   -1,  270,  271,  272,
  273,   -1,  275,  276,  277,  278,   -1,  280,  281,   -1,
   -1,   -1,   -1,   -1,   -1,  262,   -1,  264,  265,  266,
  267,  268,   -1,  270,  271,  262,   -1,  264,  265,  266,
  267,  268,   -1,  270,  271,   -1,   -1,   -1,  262,  263,
  264,  265,  266,  267,  268,   -1,  270,  271,  272,  273,
   -1,  275,  276,  277,  278,   -1,  280,  281,  262,  263,
  264,  265,  266,  267,  268,   -1,  270,  271,  272,  273,
   -1,  275,  276,  277,  278,   -1,  280,  281,   -1,   -1,
  263,  264,  265,  266,  267,  268,   -1,  270,  271,  264,
  265,  266,  267,  268,   -1,  270,  271,   25,   26,   -1,
   -1,   29,   30,   31,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   53,   54,   55,   56,   57,
   58,   59,   60,   61,   62,   63,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   72,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  100,   -1,  102,
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
"program : PROGRAM START body END",
"program : PROGRAM decls START body END",
"module : MODULE decls END",
"decls : decl",
"decls : decls decl",
"decl : ';'",
"decl : func",
"decl : declpre var ATTR literal",
"decl : declpre var",
"decl : var ATTR literal",
"decl : var",
"func : FUNCTION qualifier functype ID vars funcend",
"func : FUNCTION functype ID funcend",
"func : FUNCTION qualifier functype ID funcend",
"func : FUNCTION functype ID vars funcend",
"funcend : DONE",
"funcend : DO body",
"functype : type",
"functype : VOID",
"declpre : qualifier CONST",
"declpre : qualifier",
"declpre : CONST",
"qualifier : PUBLIC",
"qualifier : FORWARD",
"vars : var",
"vars : vars ';' var",
"var : type ID",
"type : NUMBER",
"type : ARRAY",
"type : STRING",
"body : instr",
"instr : IF expr THEN instr FI",
"instr : IF expr THEN instr ELIF expr THEN instr ELSE instr FI",
"instr : IF expr THEN instr ELIF expr THEN instr FI",
"instr : IF expr THEN instr ELSE instr FI",
"instr : FOR expr UNTIL expr STEP expr DO instr DONE",
"instr : expr ';'",
"instr : expr '!'",
"instr : REPEAT",
"instr : STOP",
"instr : RETURN expr",
"instr : RETURN",
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
#line 134 "gram.y"

char **yynames =
#if YYDEBUG > 0
		 (char**)yyname;
#else
		 0;
#endif
#line 482 "y.tab.c"

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
