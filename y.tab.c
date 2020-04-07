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
#define ATTR 285
#define NE 286
#define LE 287
#define GE 288
#define ADDR 289
#define UMINUS 290
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    0,    1,    2,    3,    3,    5,    5,    6,    6,
    6,    6,    6,    7,   13,   13,   11,   11,    8,    8,
    8,   12,   12,   15,   15,    9,   14,   14,   14,    4,
    4,   17,   16,   16,   19,   19,   19,   19,   19,   19,
   19,   19,   23,   23,   23,   23,   24,   21,   21,   18,
   18,   18,   18,   25,   25,   22,   22,   22,   20,   20,
   20,   20,   20,   20,   20,   20,   20,   20,   20,   20,
   20,   20,   20,   20,   20,   20,   20,   20,   20,   20,
   20,   20,   10,   10,   26,   26,
};
static const YYINT yylen[] = {                            2,
    1,    1,    5,    3,    0,    1,    1,    3,    1,    5,
    3,    4,    2,    6,    1,    2,    1,    1,    0,    1,
    1,    0,    1,    1,    3,    2,    1,    1,    1,    2,
    1,    1,    2,    3,    5,    8,    6,    7,    9,    2,
    2,    4,    1,    1,    2,    1,    4,    1,    2,    0,
    1,    1,    2,    1,    2,    1,    4,    2,    1,    3,
    4,    3,    1,    2,    2,    3,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    3,    3,    3,
    2,    1,    1,    1,    1,    3,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,    1,    2,    0,   20,   21,    0,    0,
    7,    9,    0,    0,    0,    0,    0,   27,   28,   29,
    0,    0,    0,    4,   18,    0,   17,   83,   56,   84,
    0,    0,   43,   44,    0,    0,    0,    0,    0,   82,
    0,    0,    0,   63,    0,   31,   32,   54,    0,    0,
   51,    0,    8,    0,    0,   26,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    3,   33,    0,   30,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   40,   41,    0,    0,    0,
   55,   53,    0,   12,   24,    0,    0,    0,    0,   60,
   34,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   62,    0,    0,    0,    0,
    0,   10,   15,    0,   14,    0,    0,    0,   61,    0,
   57,   42,   16,   25,    0,    0,   35,    0,   48,    0,
    0,    0,    0,    0,   37,   49,    0,   38,    0,    0,
    0,   47,   36,    0,   39,
};
static const YYINT yydgoto[] = {                          3,
    4,    5,    9,   42,   10,   11,   12,   13,   43,   44,
   26,   96,  125,   23,   97,   45,   46,   47,   48,   49,
  138,   59,   51,  139,   52,  118,
};
static const YYINT yysindex[] = {                      -222,
 -191, -191,    0,    0,    0, -178,    0,    0, -213,    9,
    0,    0, -252, -192, -216, 1298, -191,    0,    0,    0,
 -237, -206, -173,    0,    0, -155,    0,    0,    0,    0,
  219,  219,    0,    0,  219,  219,  219,  219,  -36,    0,
  219, -153,   56,    0, 1298,    0,    0,    0,  767,  -34,
    0, 1208,    0, -147, -234,    0, -237,  817,  -88,  481,
 1134,  100, 1143,  100,   54,  932,    0,    0,   88,    0,
  219,  219,  219,  219,  219,  219,  219,  219,  219,  219,
  219,  219,  219,  219,  101,    0,    0,  219,  219,  219,
    0,    0, -234,    0,    0, -149,   98, 1208,  219,    0,
    0,  980, 1143,  174,  174,  137,  137,  137,  137,   -5,
   -5,  -27,  -27,  -27,  -27,    0, 1134,  -20, 1134,  943,
  969,    0,    0, 1298,    0, -237, -184, 1069,    0,  219,
    0,    0,    0,    0, 1208,  219,    0, -171,    0,  219,
 1134, -100, 1097, 1208,    0,    0, 1108,    0, 1208,  -91,
 1208,    0,    0,  -84,    0,
};
static const YYINT yyrindex[] = {                         0,
   61, -142,    0,    0,    0, -108,    0,    0,    0, -132,
    0,    0,    0,    0,    0,  -69,  -65,    0,    0,    0,
    0,  -39,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   31,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  -37,    0,    0,    0,    0,  778,
    0,  284,    0,  -25,    0,    0, -122,    0,    3,    0,
  305,   39, 1200,   75,  -33,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  -97, -111,    0,    0,
    0, 1028, 1236,  682,  808,  476,  511,  612,  647,  406,
  441,  111,  148,  334,  371,    0,   15,    0, 1266,    0,
    0,    0,    0,  -37,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  -82,    0,    0,    0,    0,    0,
   25,    0,    0,  -82,    0,    0,    0,    0, -111,    0,
  -74,    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
    0,    0,  198,   77,    0,  195,    0,  207,   57,  -38,
    0,    0,    0,  200,    0,    0,  173,  -40,  168, 1370,
    0, 1063,  176,   94,    0,    0,
};
#define YYTABLESIZE 1582
static const YYINT yytable[] = {                         58,
   90,   58,   89,   58,   58,   39,   58,   58,   58,   58,
   58,   58,   85,   58,   18,   19,   94,   20,   21,   13,
  129,   50,   28,  130,   30,   58,   58,   58,   58,   18,
   19,   83,   20,   11,   85,   59,   81,    1,    2,   59,
   59,   82,   59,   59,   59,   59,   59,   59,   16,   59,
   18,   19,   25,   20,  122,   85,   89,  127,   85,   58,
   58,   59,   59,   59,   59,   86,   84,   17,   86,   22,
   24,   65,    6,    7,    8,   65,   65,   54,   55,   65,
   65,   65,   65,   65,   56,   65,    7,    8,   84,   46,
   58,  135,  136,  137,  142,   59,   59,   65,   65,   65,
   65,   69,   57,  150,  144,  136,  145,   64,  152,   67,
  154,   64,   64,   95,   68,   64,   64,   64,   64,   64,
    5,   64,  123,  124,   19,   19,   59,   19,   19,    6,
    6,   65,   65,   64,   64,   64,   64,   93,   36,   85,
   41,  116,   39,   69,   89,   38,  101,   69,   69,   22,
   22,   69,   69,   69,   69,   69,  126,   69,   19,   19,
   19,   19,   65,   40,   50,   50,   50,   64,   64,   69,
   69,   69,   69,   83,   23,   23,   85,  148,   81,   79,
   70,   80,  134,   82,   70,   70,  153,  155,   70,   70,
   70,   70,   70,   50,   70,   50,   88,   50,   64,   14,
  133,   19,   19,   69,   19,   19,   70,   70,   70,   70,
   83,   53,   15,   85,   27,   81,   79,   70,   80,   91,
   82,   29,   13,   13,   50,   50,   37,   92,   58,   58,
   84,  146,    0,   75,   69,   76,   11,   11,   58,   58,
   70,   58,   58,   58,   58,    0,   58,   58,    0,    0,
   88,   58,   58,   58,   58,    0,   36,    0,   41,    0,
   39,    0,    0,   38,   59,   59,    0,   84,    0,    0,
    0,   70,    0,    0,   59,   59,    0,   59,   59,   59,
   59,   40,   59,   59,    0,    0,    0,    0,   59,   59,
   59,    0,   46,   46,    0,    0,    0,    0,    0,    0,
   65,   65,   46,    0,    0,    0,   46,   46,   46,    0,
   65,   65,    0,   65,   65,   65,   65,    0,   65,   65,
    0,    0,    5,    0,   65,   65,   65,   19,   19,    0,
   19,   19,    0,    0,    0,    0,   64,   64,    0,    0,
    0,    0,   52,    0,   37,    0,   64,   64,    0,   64,
   64,   64,   64,    0,   64,   64,    0,   28,   29,   30,
   64,   64,   64,   45,    0,    0,   71,    0,    0,    0,
   71,   71,   69,   69,   71,   71,   71,   71,   71,    0,
   71,    0,   69,   69,    0,   69,   69,   69,   69,    0,
   69,   69,   71,   71,   71,   71,   69,   69,   69,    0,
    0,    0,    0,   66,    0,    0,    0,   66,   66,   70,
   70,   66,   66,   66,   66,   66,    0,   66,    0,   70,
   70,    0,   70,   70,   70,   70,   71,   70,   70,   66,
   66,   66,   66,   70,   70,   70,    0,    0,   67,    0,
    0,    0,    0,   67,    0,    0,   67,    0,   67,   67,
   67,    0,    0,    0,    0,    0,    0,   71,    0,    0,
   77,   78,    0,   66,   67,   67,   67,   67,    0,    0,
    0,    0,    0,   68,    0,   28,   29,   30,   68,    0,
    0,   68,    0,   68,   68,   68,    0,    0,    0,    0,
    0,    0,    0,    0,   66,    0,    0,    0,   67,   68,
   68,   68,   68,    0,    0,    0,    0,    0,   72,    0,
    0,    0,    0,   72,    0,    0,   72,   83,   72,   72,
   85,    0,   81,   79,    0,   80,    0,   82,    0,   67,
    0,    0,    0,   68,   72,   72,   72,   72,    0,    0,
   75,   74,   76,   73,    0,   52,   52,    0,   73,    0,
    0,   73,    0,    0,   73,   52,    0,    0,    0,   52,
   52,   52,    0,    0,   68,    0,   45,   45,   72,   73,
   73,   73,   73,    0,   84,    0,   45,    0,    0,    0,
   45,   45,   45,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   71,   71,    0,    0,   72,
    0,    0,    0,   73,   71,   71,   71,    0,   71,   71,
   71,   71,    0,   71,   71,    0,    0,    0,    0,   71,
   71,   71,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   66,   66,   73,    0,    0,    0,    0,    0,
    0,    0,   66,   66,   75,   66,   66,   66,   66,   75,
   66,   66,   75,    0,    0,   75,   66,   66,   66,    0,
    0,    0,    0,    0,    0,    0,    0,   67,   67,    0,
   75,   75,   75,   75,    0,    0,    0,   67,   67,   74,
   67,   67,   67,   67,   74,   67,   67,   74,    0,    0,
   74,   67,   67,   67,    0,    0,    0,    0,    0,    0,
    0,    0,   68,   68,   75,   74,   74,   74,   74,    0,
    0,    0,   68,   68,   76,   68,   68,   68,   68,   76,
   68,   68,   76,    0,    0,   76,   68,   68,   68,    0,
    0,    0,    0,    0,    0,   75,    0,   72,   72,   74,
   76,    0,   76,    0,    0,    0,    0,   72,   72,    0,
   72,   72,   72,   72,    0,   72,   72,    0,    0,    0,
   99,   72,   72,   72,    0,    0,   73,   77,   78,    0,
   74,    0,   73,   73,   76,    0,    0,    0,    0,    0,
    0,    0,   73,   73,    0,   73,   73,   73,   73,    0,
   73,   73,    0,    0,    0,    0,   73,   73,   73,   87,
    0,    0,    0,   83,   72,   76,   85,    0,   81,   79,
   59,   80,    0,   82,   59,   59,    0,   59,    0,   59,
   59,    0,   59,    0,   59,   86,   75,   74,   76,    0,
    0,    0,    0,    0,    0,    0,   59,   59,   59,   59,
   77,    0,    0,    0,    0,   77,    0,    0,   77,    0,
    0,   77,    0,   83,   72,    0,   85,    0,   81,   79,
   84,   80,    0,   82,    0,    0,   77,    0,   77,    0,
    0,   59,    0,   75,   75,    0,   75,   74,   76,    0,
    0,    0,    0,   75,   75,    0,   75,   75,   75,   75,
   71,   75,   75,    0,    0,    0,    0,   75,   75,   75,
   77,   59,    0,    0,    0,    0,    0,    0,   74,   74,
   84,    0,    0,    0,    0,    0,    0,    0,   74,   74,
    0,   74,   74,   74,   74,    0,   74,   74,    0,    0,
    0,   77,   74,   74,   74,    0,    0,    0,    0,    0,
   71,    0,    0,   76,   76,    0,    0,    0,    0,    0,
    0,    0,    0,   76,   76,    0,   76,   76,   76,   76,
    0,   76,   76,    0,    0,    0,    0,   76,   83,   72,
    0,   85,  100,   81,   79,    0,   80,    0,   82,   83,
   72,    0,   85,    0,   81,   79,    0,   80,    0,   82,
    0,   75,   74,   76,    0,    0,    0,    0,    0,    0,
    0,    0,   75,   74,   76,   83,   72,    0,   85,    0,
   81,   79,    0,   80,    0,   82,   83,   72,    0,   85,
    0,   81,   79,    0,   80,   84,   82,  132,   75,   74,
   76,    0,    0,    0,    0,  131,   84,    0,    0,   75,
   74,   76,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   73,   77,   78,   71,    0,    0,    0,    0,
   80,    0,   84,   59,   59,   59,   71,    0,   80,   77,
   77,   80,    0,   84,    0,    0,    0,    0,   50,   77,
   77,    0,   77,   77,   77,   77,   80,   77,   77,    0,
    0,   98,   71,   77,    0,    0,    0,    0,    0,    0,
    0,   65,   73,   77,   78,   83,   72,   50,   85,    0,
   81,   79,    0,   80,   50,   82,    0,    0,    0,    0,
   80,    0,    0,    0,    0,    0,    0,    0,   75,   74,
   76,    0,    0,   83,   72,    0,   85,    0,   81,   79,
    0,   80,    0,   82,   83,   72,    0,   85,    0,   81,
   79,   80,   80,    0,   82,    0,   75,   74,   76,    0,
   50,    0,   84,    0,    0,    0,    0,   75,   74,   76,
   83,   72,    0,   85,    0,   81,   79,    0,   80,   83,
   82,    0,   85,    0,   81,   79,   50,   80,    0,   82,
   84,    0,   71,   75,   74,   76,    0,   50,    0,    0,
    0,   84,   75,   74,   76,    0,   50,    0,    0,    0,
    0,   50,    0,   50,    0,    0,    0,   73,   77,   78,
   71,    0,    0,    0,    0,    0,    0,   84,   73,   77,
   78,   71,   81,    0,    0,    0,   84,   81,    0,    0,
   81,    0,    0,   81,    0,   36,    0,   41,    0,   39,
    0,    0,   38,    0,   73,   77,   78,   71,   81,    0,
    0,    0,    0,    0,    0,   73,   77,   78,   79,    0,
   40,    0,    0,   79,    0,    0,   79,    0,    0,   79,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   80,
   80,    0,   81,    0,   79,    0,    0,    0,   78,   80,
   80,    0,   80,   80,   80,   80,   78,   80,   80,   78,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   81,   78,    0,    0,    0,   79,    0,
    0,    0,    0,   37,    0,   36,    0,   41,    0,   39,
    0,    0,   38,    0,    0,    0,    0,    0,    0,  140,
    0,    0,    0,    0,   73,   77,   78,    0,   78,   79,
   40,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  149,    0,    0,    0,    0,    0,    0,    0,    0,
  151,    0,   73,   77,   78,    0,    0,    0,    0,    0,
    0,    0,    0,   73,   77,   78,    0,    0,    0,    0,
   58,   60,    0,    0,   61,   62,   63,   64,    0,    0,
   66,    0,    0,    0,    0,    0,    0,    0,    0,   73,
   77,   78,    0,   37,    0,    0,    0,    0,   73,   77,
   78,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  102,  103,  104,  105,  106,  107,  108,  109,  110,  111,
  112,  113,  114,  115,  117,    0,    0,  119,  120,  121,
    0,   81,   81,    0,   28,   29,   30,    0,  128,    0,
    0,   81,   81,    0,   81,   81,   81,   81,    0,   81,
   81,   31,    0,    0,    0,    0,   32,    0,    0,   33,
   34,   35,    0,    0,    0,    0,    0,   79,   79,  141,
    0,    0,    0,    0,    0,  143,    0,   79,   79,  147,
   79,   79,   79,   79,    0,   79,   79,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   78,   78,    0,
    0,    0,    0,    0,    0,    0,    0,   78,   78,    0,
   78,   78,   78,   78,    0,   78,   78,    0,    0,    0,
    0,    0,    0,    0,   28,   29,   30,    0,    0,    0,
    0,    0,    0,    0,   18,   19,    0,   20,    0,    0,
    0,   31,    0,    0,    0,    0,   32,    0,    0,   33,
   34,   35,
};
static const YYINT yycheck[] = {                         33,
   35,   35,   91,   37,   38,   42,   40,   41,   42,   43,
   44,   45,   40,   47,  267,  268,   55,  270,  271,   59,
   41,   59,  257,   44,  259,   59,   60,   61,   62,  267,
  268,   37,  270,   59,   40,   33,   42,  260,  261,   37,
   38,   47,   40,   41,   42,   43,   44,   45,  262,   47,
  267,  268,  269,  270,   93,   41,   91,   98,   44,   93,
   94,   59,   60,   61,   62,   41,   94,   59,   44,   13,
  263,   33,  264,  265,  266,   37,   38,   21,  285,   41,
   42,   43,   44,   45,  258,   47,  265,  266,   94,   59,
  124,  276,  277,  278,  135,   93,   94,   59,   60,   61,
   62,   45,  258,  144,  276,  277,  278,   33,  149,  263,
  151,   37,   38,   57,   59,   41,   42,   43,   44,   45,
  263,   47,  272,  273,  267,  268,  124,  270,  271,  262,
  263,   93,   94,   59,   60,   61,   62,  285,   38,   40,
   40,   41,   42,   33,   91,   45,   59,   37,   38,  272,
  273,   41,   42,   43,   44,   45,   59,   47,  267,  268,
  269,  270,  124,   63,  276,  277,  278,   93,   94,   59,
   60,   61,   62,   37,  272,  273,   40,  278,   42,   43,
   33,   45,  126,   47,   37,   38,  278,  272,   41,   42,
   43,   44,   45,  263,   47,  278,  285,  272,  124,    2,
  124,  267,  268,   93,  270,  271,   59,   60,   61,   62,
   37,   17,    6,   40,   15,   42,   43,   45,   45,   52,
   47,  258,  262,  263,  262,  263,  126,   52,  262,  263,
   94,  138,   -1,   60,  124,   62,  262,  263,  272,  273,
   93,  275,  276,  277,  278,   -1,  280,  281,   -1,   -1,
  285,  285,  286,  287,  288,   -1,   38,   -1,   40,   -1,
   42,   -1,   -1,   45,  262,  263,   -1,   94,   -1,   -1,
   -1,  124,   -1,   -1,  272,  273,   -1,  275,  276,  277,
  278,   63,  280,  281,   -1,   -1,   -1,   -1,  286,  287,
  288,   -1,  262,  263,   -1,   -1,   -1,   -1,   -1,   -1,
  262,  263,  272,   -1,   -1,   -1,  276,  277,  278,   -1,
  272,  273,   -1,  275,  276,  277,  278,   -1,  280,  281,
   -1,   -1,  262,   -1,  286,  287,  288,  267,  268,   -1,
  270,  271,   -1,   -1,   -1,   -1,  262,  263,   -1,   -1,
   -1,   -1,   59,   -1,  126,   -1,  272,  273,   -1,  275,
  276,  277,  278,   -1,  280,  281,   -1,  257,  258,  259,
  286,  287,  288,   59,   -1,   -1,   33,   -1,   -1,   -1,
   37,   38,  262,  263,   41,   42,   43,   44,   45,   -1,
   47,   -1,  272,  273,   -1,  275,  276,  277,  278,   -1,
  280,  281,   59,   60,   61,   62,  286,  287,  288,   -1,
   -1,   -1,   -1,   33,   -1,   -1,   -1,   37,   38,  262,
  263,   41,   42,   43,   44,   45,   -1,   47,   -1,  272,
  273,   -1,  275,  276,  277,  278,   93,  280,  281,   59,
   60,   61,   62,  286,  287,  288,   -1,   -1,   33,   -1,
   -1,   -1,   -1,   38,   -1,   -1,   41,   -1,   43,   44,
   45,   -1,   -1,   -1,   -1,   -1,   -1,  124,   -1,   -1,
  287,  288,   -1,   93,   59,   60,   61,   62,   -1,   -1,
   -1,   -1,   -1,   33,   -1,  257,  258,  259,   38,   -1,
   -1,   41,   -1,   43,   44,   45,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  124,   -1,   -1,   -1,   93,   59,
   60,   61,   62,   -1,   -1,   -1,   -1,   -1,   33,   -1,
   -1,   -1,   -1,   38,   -1,   -1,   41,   37,   38,   44,
   40,   -1,   42,   43,   -1,   45,   -1,   47,   -1,  124,
   -1,   -1,   -1,   93,   59,   60,   61,   62,   -1,   -1,
   60,   61,   62,   33,   -1,  262,  263,   -1,   38,   -1,
   -1,   41,   -1,   -1,   44,  272,   -1,   -1,   -1,  276,
  277,  278,   -1,   -1,  124,   -1,  262,  263,   93,   59,
   60,   61,   62,   -1,   94,   -1,  272,   -1,   -1,   -1,
  276,  277,  278,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  262,  263,   -1,   -1,  124,
   -1,   -1,   -1,   93,  124,  272,  273,   -1,  275,  276,
  277,  278,   -1,  280,  281,   -1,   -1,   -1,   -1,  286,
  287,  288,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  262,  263,  124,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  272,  273,   33,  275,  276,  277,  278,   38,
  280,  281,   41,   -1,   -1,   44,  286,  287,  288,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  262,  263,   -1,
   59,   60,   61,   62,   -1,   -1,   -1,  272,  273,   33,
  275,  276,  277,  278,   38,  280,  281,   41,   -1,   -1,
   44,  286,  287,  288,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  262,  263,   93,   59,   60,   61,   62,   -1,
   -1,   -1,  272,  273,   33,  275,  276,  277,  278,   38,
  280,  281,   41,   -1,   -1,   44,  286,  287,  288,   -1,
   -1,   -1,   -1,   -1,   -1,  124,   -1,  262,  263,   93,
   59,   -1,   61,   -1,   -1,   -1,   -1,  272,  273,   -1,
  275,  276,  277,  278,   -1,  280,  281,   -1,   -1,   -1,
  280,  286,  287,  288,   -1,   -1,  286,  287,  288,   -1,
  124,   -1,  262,  263,   93,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  272,  273,   -1,  275,  276,  277,  278,   -1,
  280,  281,   -1,   -1,   -1,   -1,  286,  287,  288,   33,
   -1,   -1,   -1,   37,   38,  124,   40,   -1,   42,   43,
   33,   45,   -1,   47,   37,   38,   -1,   40,   -1,   42,
   43,   -1,   45,   -1,   47,   59,   60,   61,   62,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   59,   60,   61,   62,
   33,   -1,   -1,   -1,   -1,   38,   -1,   -1,   41,   -1,
   -1,   44,   -1,   37,   38,   -1,   40,   -1,   42,   43,
   94,   45,   -1,   47,   -1,   -1,   59,   -1,   61,   -1,
   -1,   94,   -1,  262,  263,   -1,   60,   61,   62,   -1,
   -1,   -1,   -1,  272,  273,   -1,  275,  276,  277,  278,
  124,  280,  281,   -1,   -1,   -1,   -1,  286,  287,  288,
   93,  124,   -1,   -1,   -1,   -1,   -1,   -1,  262,  263,
   94,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  272,  273,
   -1,  275,  276,  277,  278,   -1,  280,  281,   -1,   -1,
   -1,  124,  286,  287,  288,   -1,   -1,   -1,   -1,   -1,
  124,   -1,   -1,  262,  263,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  272,  273,   -1,  275,  276,  277,  278,
   -1,  280,  281,   -1,   -1,   -1,   -1,  286,   37,   38,
   -1,   40,   41,   42,   43,   -1,   45,   -1,   47,   37,
   38,   -1,   40,   -1,   42,   43,   -1,   45,   -1,   47,
   -1,   60,   61,   62,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   60,   61,   62,   37,   38,   -1,   40,   -1,
   42,   43,   -1,   45,   -1,   47,   37,   38,   -1,   40,
   -1,   42,   43,   -1,   45,   94,   47,   59,   60,   61,
   62,   -1,   -1,   -1,   -1,   93,   94,   -1,   -1,   60,
   61,   62,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  286,  287,  288,  124,   -1,   -1,   -1,   -1,
   33,   -1,   94,  286,  287,  288,  124,   -1,   41,  262,
  263,   44,   -1,   94,   -1,   -1,   -1,   -1,   16,  272,
  273,   -1,  275,  276,  277,  278,   59,  280,  281,   -1,
   -1,  275,  124,  286,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   39,  286,  287,  288,   37,   38,   45,   40,   -1,
   42,   43,   -1,   45,   52,   47,   -1,   -1,   -1,   -1,
   93,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   60,   61,
   62,   -1,   -1,   37,   38,   -1,   40,   -1,   42,   43,
   -1,   45,   -1,   47,   37,   38,   -1,   40,   -1,   42,
   43,  124,   45,   -1,   47,   -1,   60,   61,   62,   -1,
   98,   -1,   94,   -1,   -1,   -1,   -1,   60,   61,   62,
   37,   38,   -1,   40,   -1,   42,   43,   -1,   45,   37,
   47,   -1,   40,   -1,   42,   43,  124,   45,   -1,   47,
   94,   -1,  124,   60,   61,   62,   -1,  135,   -1,   -1,
   -1,   94,   60,   61,   62,   -1,  144,   -1,   -1,   -1,
   -1,  149,   -1,  151,   -1,   -1,   -1,  286,  287,  288,
  124,   -1,   -1,   -1,   -1,   -1,   -1,   94,  286,  287,
  288,  124,   33,   -1,   -1,   -1,   94,   38,   -1,   -1,
   41,   -1,   -1,   44,   -1,   38,   -1,   40,   -1,   42,
   -1,   -1,   45,   -1,  286,  287,  288,  124,   59,   -1,
   -1,   -1,   -1,   -1,   -1,  286,  287,  288,   33,   -1,
   63,   -1,   -1,   38,   -1,   -1,   41,   -1,   -1,   44,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  262,
  263,   -1,   93,   -1,   59,   -1,   -1,   -1,   33,  272,
  273,   -1,  275,  276,  277,  278,   41,  280,  281,   44,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  124,   59,   -1,   -1,   -1,   93,   -1,
   -1,   -1,   -1,  126,   -1,   38,   -1,   40,   -1,   42,
   -1,   -1,   45,   -1,   -1,   -1,   -1,   -1,   -1,  281,
   -1,   -1,   -1,   -1,  286,  287,  288,   -1,   93,  124,
   63,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  275,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  273,   -1,  286,  287,  288,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  286,  287,  288,   -1,   -1,   -1,   -1,
   31,   32,   -1,   -1,   35,   36,   37,   38,   -1,   -1,
   41,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  286,
  287,  288,   -1,  126,   -1,   -1,   -1,   -1,  286,  287,
  288,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   71,   72,   73,   74,   75,   76,   77,   78,   79,   80,
   81,   82,   83,   84,   85,   -1,   -1,   88,   89,   90,
   -1,  262,  263,   -1,  257,  258,  259,   -1,   99,   -1,
   -1,  272,  273,   -1,  275,  276,  277,  278,   -1,  280,
  281,  274,   -1,   -1,   -1,   -1,  279,   -1,   -1,  282,
  283,  284,   -1,   -1,   -1,   -1,   -1,  262,  263,  130,
   -1,   -1,   -1,   -1,   -1,  136,   -1,  272,  273,  140,
  275,  276,  277,  278,   -1,  280,  281,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  262,  263,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  272,  273,   -1,
  275,  276,  277,  278,   -1,  280,  281,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  257,  258,  259,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  267,  268,   -1,  270,   -1,   -1,
   -1,  274,   -1,   -1,   -1,   -1,  279,   -1,   -1,  282,
  283,  284,
};
#define YYFINAL 3
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 290
#define YYUNDFTOKEN 319
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"'!'",0,"'#'",0,"'%'","'&'",0,"'('","')'","'*'","'+'","','","'-'",0,"'/'",0,0,0,
0,0,0,0,0,0,0,0,"';'","'<'","'='","'>'","'?'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,"'['",0,"']'","'^'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,"'|'",0,"'~'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"INTEGER","ID","STR",
"PROGRAM","MODULE","START","END","FUNCTION","PUBLIC","FORWARD","NUMBER","ARRAY",
"VOID","STRING","CONST","DONE","DO","IF","THEN","ELSE","ELIF","FI","FOR",
"UNTIL","STEP","REPEAT","STOP","RETURN","ATTR","NE","LE","GE","ADDR","UMINUS",0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : file",
"file : program",
"file : module",
"program : PROGRAM decls START body END",
"module : MODULE decls END",
"decls :",
"decls : delclist",
"delclist : decl",
"delclist : delclist ';' decl",
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
"vars : varlist",
"varlist : var",
"varlist : varlist ';' var",
"var : type ID",
"type : NUMBER",
"type : ARRAY",
"type : STRING",
"body : bodyvars bodyinstrs",
"body : bodyinstrs",
"bodyinstrs : block",
"bodyvars : var ';'",
"bodyvars : bodyvars var ';'",
"instr : IF rvalue THEN block FI",
"instr : IF rvalue THEN block elifs ELSE block FI",
"instr : IF rvalue THEN block elifs FI",
"instr : IF rvalue THEN block ELSE block FI",
"instr : FOR rvalue UNTIL rvalue STEP rvalue DO block DONE",
"instr : rvalue ';'",
"instr : rvalue '!'",
"instr : lvalue '#' rvalue ';'",
"instrterm : REPEAT",
"instrterm : STOP",
"instrterm : RETURN rvalue",
"instrterm : RETURN",
"elif : ELIF rvalue THEN block",
"elifs : elif",
"elifs : elifs elif",
"block :",
"block : instrterm",
"block : instrs",
"block : instrs instrterm",
"instrs : instr",
"instrs : instrs instr",
"lvalue : ID",
"lvalue : lvalue '[' rvalue ']'",
"lvalue : '*' lvalue",
"rvalue : lvalue",
"rvalue : '(' rvalue ')'",
"rvalue : rvalue '(' args ')'",
"rvalue : rvalue '(' ')'",
"rvalue : literal",
"rvalue : '-' rvalue",
"rvalue : '&' rvalue",
"rvalue : rvalue '^' rvalue",
"rvalue : rvalue '+' rvalue",
"rvalue : rvalue '-' rvalue",
"rvalue : rvalue '*' rvalue",
"rvalue : rvalue '/' rvalue",
"rvalue : rvalue '%' rvalue",
"rvalue : rvalue '<' rvalue",
"rvalue : rvalue '>' rvalue",
"rvalue : rvalue GE rvalue",
"rvalue : rvalue LE rvalue",
"rvalue : rvalue NE rvalue",
"rvalue : rvalue '=' rvalue",
"rvalue : lvalue ATTR rvalue",
"rvalue : rvalue '&' rvalue",
"rvalue : rvalue '|' rvalue",
"rvalue : '~' rvalue",
"rvalue : '?'",
"literal : INTEGER",
"literal : STR",
"args : rvalue",
"args : args ',' rvalue",

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
#line 178 "gram.y"

char **yynames =
#if YYDEBUG > 0
		 (char**)yyname;
#else
		 0;
#endif
#line 680 "y.tab.c"

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
