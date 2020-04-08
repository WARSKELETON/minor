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

int nostring(Node *arg1, Node *arg2);
int intonly(Node *arg, int);
int noassign(Node *arg1, Node *arg2);
static int ncicl;
#line 19 "gram.y"
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
#line 51 "y.tab.c"

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
#define NIL 291
#define DECLS 292
#define DECL 293
#define FUNCTYPE 294
#define QUALIFIER 295
#define VARS 296
#define VAR 297
#define BODY 298
#define BODYVARS 299
#define RETURN_EXPR 300
#define ELIFS 301
#define INSTRS_INSTRTERM 302
#define INSTRS 303
#define TWO_INTEGERS 304
#define MORE_INTEGERS 305
#define ARGS 306
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    0,    1,    1,    2,    2,    3,    3,    4,    4,
    4,    4,    4,    4,    4,    4,    4,    9,    9,    9,
    9,   10,   10,   11,   11,   12,   12,   13,   13,   14,
   14,   15,   15,   15,    6,    6,    5,    5,    7,    7,
    8,    8,   16,   16,   16,   16,   30,   16,   16,   16,
   16,   17,   17,   17,   17,   18,   19,   19,   20,   20,
   20,   20,   21,   21,   22,   22,   23,   23,   23,   23,
   23,   23,   23,   23,   23,   23,   23,   23,   23,   23,
   23,   23,   23,   23,   23,   23,   23,   23,   23,   23,
   23,   24,   24,   25,   27,   27,   28,   28,   26,   26,
   29,   29,
};
static const YYINT yylen[] = {                            2,
    1,    1,    5,    4,    3,    2,    1,    3,    1,    5,
    4,    2,    3,    2,    4,    1,    3,    6,    5,    5,
    4,    1,    2,    1,    1,    1,    1,    1,    3,    2,
    5,    1,    1,    1,    2,    1,    2,    1,    0,    1,
    2,    3,    5,    8,    6,    7,    0,   10,    2,    2,
    4,    1,    1,    2,    1,    4,    1,    2,    0,    1,
    1,    2,    1,    2,    1,    4,    1,    3,    4,    3,
    1,    1,    2,    2,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    3,    3,    2,
    1,    1,    1,    1,    1,    1,    2,    2,    1,    3,
    1,    3,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,    1,    2,    0,    0,   26,   27,   32,
   33,   34,    0,    0,    7,    9,    0,    0,    0,    6,
    0,   94,   65,   96,    0,    0,    0,    0,    0,   91,
    0,    0,   36,    0,    0,   63,    0,    0,    0,    0,
   71,    0,   25,    0,    0,   24,    0,    0,    0,    0,
    0,    0,    0,    5,    0,    0,    0,    0,    0,    0,
    0,    4,   35,    0,   41,   64,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   49,   50,   97,   98,    0,    0,
    0,    0,    8,    0,    0,   17,    0,    0,   92,    0,
    0,    0,   68,   42,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   70,    0,    0,   22,    0,   21,    0,   28,    0,
   15,    3,    0,   11,    0,    0,   52,   53,    0,   60,
    0,    0,    0,   66,   51,   69,    0,   23,    0,   38,
    0,   19,   20,    0,   10,  100,   31,    0,    0,    0,
   43,   57,    0,   62,    0,    0,   37,   29,   18,    0,
    0,    0,   45,   58,    0,   46,    0,    0,   47,   56,
   44,    0,    0,   48,
};
static const YYINT yydgoto[] = {                          3,
    4,    5,   14,   15,  148,   32,   33,   34,   16,  127,
   44,   17,  128,   18,   19,   36,  140,  162,  163,  141,
  142,   55,   39,   96,   40,   98,   41,   42,  124,  182,
};
static const YYINT yysindex[] = {                      -222,
 1073,   65,    0,    0,    0,  876, -127,    0,    0,    0,
    0,    0, -144,  -44,    0,    0,   72, -252, -184,    0,
  -57,    0,    0,    0,  970,  970,  970,  970,  970,    0,
  970, -188,    0,  876,   19,    0,  219,  -34,  767, -169,
    0, -169,    0, -173, -216,    0, -192,  876,  240, -144,
 -190, -237,   18,    0,  -88,  817,  934,   62, 1155,   62,
  945,    0,    0,   51,    0,    0,  970,  970,  970,  970,
  970,  970,  970,  970,  970,  970,  970,  970,  970,  970,
  970,  970,  970,  501,    0,    0,    0,    0, -108, -133,
 -237, -149,    0, -155, -237,    0, -169,   87,    0, -169,
 1149,  970,    0,    0, 1229,  974, 1069, 1240, 1155,  174,
  174,  486,  486,  486,  486,   -5,   -5,  -27,  -27,  -27,
  -27,    0, 1229,  -10,    0,  319,    0,  -41,    0, -108,
    0,    0, -237,    0, -169,   53,    0,    0,  970,    0,
 -172, 1149, 1080,    0,    0,    0,  970,    0,  319,    0,
 -144,    0,    0,  -41,    0,    0,    0, 1229, 1149,  970,
    0,    0, -101,    0,  970, 1229,    0,    0,    0, -131,
 1111, 1149,    0,    0, 1203,    0, 1149, -128,    0,    0,
    0, 1149, -115,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,    0,  -97,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  -40,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  -97,    0,    0,  -96,  778,    0,  -33,
    0,    3,    0,    0,    0,    0,   -1,  -97,    0,    0,
    7,    0,  -35,    0,   39,    0,    0,   75, 1270,  111,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   11,    0,    0,  -38,   33,    0,    0,
  -76,    0,    0,    0, 1321,    0,    0, 1193, 1292,  808,
  905,  511,  612,  647,  682,  441,  476,  148,  334,  371,
  406,    0,   15,    0,    0,   35,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   31,    0,
    0,  285,    0,    0,    0,    0,    0,    0,   35,    0,
    0,    0,    0,    0,    0,    0,    0,  784, -100,    0,
    0,    0,    0,    0,    0,   27,    0,    0,    0,    0,
    0, -100,    0,    0,    0,    0,  -76,    0,    0,    0,
    0,  -92,    0,    0,
};
static const YYINT yygindex[] = {                         0,
    0,    0,  180,  134,    0,  139,  154,   68,    0, -105,
  151,  191,   73, 1370,   10,  -21,   70,   50,    0,    2,
   81, 1336, 1549,   12, 1349,    0,  -22,    0,    0,    0,
};
#define YYTABLESIZE 1714
static const YYINT yytable[] = {                         72,
   69,   49,   68,   72,   72,   99,   72,   72,   72,   72,
   72,   72,   84,   72,   49,   66,   46,  151,   16,   22,
   99,   24,  152,   30,  153,   72,   72,   72,   72,   99,
  146,   82,   52,  147,   84,   95,   80,    1,    2,   95,
   95,   81,   95,   95,   95,   95,   95,   95,  169,   95,
   10,   11,   43,   12,   46,  101,   68,   14,  101,   72,
   72,   95,   95,   95,   95,   12,   83,  102,   99,   13,
  102,   67,   99,   53,   62,   67,   67,   65,   67,   67,
   67,   67,   67,   67,   89,   67,   37,   22,   83,   55,
   72,   93,   91,   59,   95,   95,   95,   67,   67,   67,
   67,   84,  131,  159,  160,  161,  134,   74,  100,  104,
   99,   74,   74,  132,   37,   74,   74,   74,   74,   74,
   66,   74,   10,   11,  130,   12,   95,  150,   37,  133,
  135,   67,   67,   74,   74,   74,   74,    8,    9,   10,
   11,   43,   12,   73,  155,  157,  176,   73,   73,  181,
  167,   73,   73,   73,   73,   73,  184,   73,   10,   11,
  170,   12,   67,  125,  126,   39,   40,   74,   74,   73,
   73,   73,   73,  178,  172,  160,  173,   59,  180,   59,
   78,   21,   93,  183,   78,   78,   92,   63,   78,   78,
   78,   78,   78,  149,   78,   90,   67,   45,   74,   59,
   59,   59,  154,   73,   73,   54,   78,   78,   78,   78,
   82,  164,  174,   84,    0,   80,   78,   48,   79,    0,
   81,   16,   16,   99,   99,    0,   30,   30,   72,   72,
  125,  126,    0,   74,   73,   75,   30,   30,   72,   72,
   78,   72,   72,   72,   72,    0,   72,   72,    0,   30,
   67,    0,   72,   72,   72,    0,   27,    0,   31,    0,
   14,   14,    0,   29,   95,   95,    0,   83,   12,   12,
    0,   78,   13,   13,   95,   95,    0,   95,   95,   95,
   95,   30,   95,   95,    0,    0,    0,    0,   95,   95,
   95,    0,   55,   55,   93,   93,   59,   59,    0,    0,
   67,   67,   55,    0,    0,    0,   55,   55,   55,    0,
   67,   67,    0,   67,   67,   67,   67,    0,   67,   67,
    0,    0,    0,    0,   67,   67,   67,   20,    7,    8,
    9,   10,   11,    0,   12,   13,   74,   74,   10,   11,
    0,   12,   50,   61,   28,    0,   74,   74,    0,   74,
   74,   74,   74,    0,   74,   74,   27,    0,   31,    0,
   74,   74,   74,   29,    0,    0,   79,    0,    0,    0,
   79,   79,   73,   73,   79,   79,   79,   79,   79,    0,
   79,   30,   73,   73,    0,   73,   73,   73,   73,    0,
   73,   73,   79,   79,   79,   79,   73,   73,   73,    0,
    0,    0,    0,   80,    0,    0,    0,   80,   80,   78,
   78,   80,   80,   80,   80,   80,    0,   80,    0,   78,
   78,    0,   78,   78,   78,   78,   79,   78,   78,   80,
   80,   80,   80,   78,   78,   78,    0,    0,   75,    0,
    0,    0,   75,   75,   28,    0,   75,   75,   75,   75,
   75,    0,   75,    0,    0,    0,    0,   79,    0,    0,
   76,   77,    0,   80,   75,   75,   75,   75,    0,    0,
    0,    0,    0,   76,    0,   22,   23,   24,   76,    0,
    0,   76,    0,   76,   76,   76,    0,    0,    0,    0,
    0,    0,   25,    0,   80,    0,    0,   26,   75,   76,
   76,   76,   76,    7,    8,    9,   10,   11,   77,   12,
   13,    0,    0,   77,    0,    0,   77,    0,   77,   77,
   77,    0,   82,    0,    0,   84,    0,   80,   78,   75,
   79,    0,   81,   76,   77,   77,   77,   77,   27,    0,
   31,  122,    0,   81,    0,   29,   61,   61,   81,    0,
    0,   81,    0,    0,   81,    0,   61,    0,    0,    0,
   61,   61,   61,   30,   76,    0,    0,    0,   77,   81,
   81,   81,   81,    0,    0,   22,   23,   24,    0,   83,
    0,    0,    0,    0,    0,   10,   11,    0,   12,    0,
    0,    0,   25,    0,    0,   79,   79,   26,    0,   77,
  137,  138,  139,   81,    0,   79,   79,    0,   79,   79,
   79,   79,    0,   79,   79,    0,    0,    0,    0,   79,
   79,   79,    0,    0,    0,    0,   28,    0,    0,    0,
    0,    0,   80,   80,   81,    0,    0,    0,    0,    0,
    0,    0,   80,   80,   82,   80,   80,   80,   80,   82,
   80,   80,   82,    0,    0,   82,   80,   80,   80,    0,
    0,    0,    0,    0,    0,    0,    0,   75,   75,    0,
   82,   82,   82,   82,    0,    0,    0,   75,   75,   84,
   75,   75,   75,   75,   84,   75,   75,   84,    0,    0,
   84,   75,   75,   75,    0,    0,    0,    0,    0,    0,
    0,    0,   76,   76,   82,   84,   84,   84,   84,    0,
    0,    0,   76,   76,   83,   76,   76,   76,   76,   83,
   76,   76,   83,    0,    0,   83,   76,   76,   76,    0,
    0,    0,    0,    0,    0,   82,    0,   77,   77,   84,
   83,   83,   83,   83,    0,    0,    0,   77,   77,    0,
   77,   77,   77,   77,    0,   77,   77,   22,   23,   24,
    0,   77,   77,   77,    0,    0,    0,    0,    0,    0,
   84,    0,   81,   81,   83,    0,    0,    0,    0,    0,
    0,    0,   81,   81,    0,   81,   81,   81,   81,    0,
   81,   81,    0,    0,    0,    0,   81,   81,   81,   86,
    0,    0,    0,   82,   71,   83,   84,    0,   80,   78,
   67,   79,    0,   81,   67,   67,    0,   67,    0,   67,
   67,    0,   67,    0,   67,   85,   74,   73,   75,    0,
    0,    0,    0,    0,    0,    0,   67,   67,   67,   67,
   85,    0,   54,    0,    0,   85,    0,    0,   85,    0,
    0,   85,    0,   82,   71,    0,   84,    0,   80,   78,
   83,   79,    0,   81,    0,    0,   85,    0,   85,    0,
    0,   67,    0,   82,   82,    0,   74,   73,   75,    0,
    0,    0,    0,   82,   82,    0,   82,   82,   82,   82,
   70,   82,   82,    0,    0,    0,    0,   82,   82,   82,
   85,   67,    0,    0,    0,    0,    0,    0,   84,   84,
   83,    0,    0,   27,    0,   31,    0,    0,   84,   84,
   29,   84,   84,   84,   84,    0,   84,   84,    0,    0,
    0,   85,   84,   84,   84,    0,    0,   86,   30,    0,
   70,    0,   86,   83,   83,   86,    0,    0,   86,    0,
    0,    0,    0,   83,   83,    0,   83,   83,   83,   83,
    0,   83,   83,   86,    0,   86,    0,   83,   83,   83,
   82,   71,    0,   84,    0,   80,   78,    0,   79,    0,
   81,   82,   71,    0,   84,  103,   80,   78,    0,   79,
    0,   81,    0,   74,   73,   75,    0,   86,    0,    0,
    0,   28,    0,    0,   74,   73,   75,   27,    0,   31,
   82,   71,    0,   84,   29,   80,   78,    0,   79,    0,
   81,    0,    0,    0,    0,    0,    0,   83,   86,    0,
    0,    0,   30,   74,   73,   75,    0,    0,   83,    0,
    0,    0,    0,    0,    0,   54,   54,    0,    0,    0,
    0,    0,   72,   76,   77,   54,    0,   70,    0,   54,
   54,   54,    0,   67,   67,   67,  144,   83,   70,   85,
   85,    0,    0,    0,    0,    0,    0,    0,    0,   85,
   85,    0,   85,   85,   85,   85,    0,   85,   85,    0,
    0,  101,    0,   85,    0,   28,    0,   70,    0,    0,
    0,    0,   72,   76,   77,   82,   71,    0,   84,    0,
   80,   78,    0,   79,    0,   81,   82,   71,    0,   84,
    0,   80,   78,    0,   79,    0,   81,  145,   74,   73,
   75,    0,   22,   23,   24,    0,    0,    0,    0,   74,
   73,   75,   10,   11,    0,   12,    0,   82,   71,   25,
   84,    0,   80,   78,   26,   79,    0,   81,    0,    0,
    0,    0,   83,    0,    0,    0,   86,   86,    0,    0,
   74,   73,   75,   83,    0,    0,   86,   86,    0,   86,
   86,   86,   86,    0,   86,   86,   27,    0,   31,    0,
   86,   82,   70,   29,   84,    0,   80,   78,    0,   79,
    0,   81,    0,   70,   83,    0,    0,    0,    0,    0,
    0,   30,    0,  102,   74,   73,   75,    0,    0,   72,
   76,   77,    0,    0,    0,   89,   22,   23,   24,    0,
   72,   76,   77,   89,   70,    0,   89,    0,    0,   82,
   71,    0,   84,    0,   80,   78,    0,   79,   83,   81,
    0,   89,    0,    0,    0,    0,    0,    0,    0,   72,
   76,   77,   74,   73,   75,   82,   71,    0,   84,    0,
   80,   78,    0,   79,   28,   81,   82,   71,    0,   84,
    0,   80,   78,    0,   79,   89,   81,    0,   74,   73,
   75,    0,    0,    0,    0,    0,   83,    0,    0,   74,
   73,   75,   90,    0,    0,    0,    0,   90,    0,    0,
   90,    0,    0,   90,    0,    0,   89,    0,    0,    0,
    0,    0,   83,    0,   88,    0,   70,    0,   90,   88,
    0,    0,   88,   83,    6,   88,    7,    8,    9,   10,
   11,   38,   12,   13,    0,    0,    0,    0,    0,    0,
   88,    0,   70,   87,   72,   76,   77,    0,    0,    0,
  165,   87,   90,    0,   87,   72,   76,   77,    0,   38,
    0,    0,   38,    0,    0,   35,    0,    0,    0,   87,
    0,    0,   47,   38,   88,  177,   51,    0,   87,    0,
   88,    0,    0,   90,    0,    0,   72,   76,   77,    0,
   97,    0,    0,   64,    0,   22,   23,   24,    0,    0,
    0,    0,    0,   87,    0,   88,    0,   35,    0,   94,
    0,    0,   25,    0,    0,    0,    0,   26,    0,    0,
  137,  138,  139,    0,    0,    0,   38,    0,    0,   97,
   72,   76,   77,   97,    0,   87,    0,    0,  136,    0,
    0,    0,    0,    0,   89,   89,    0,    0,  129,    0,
    0,   38,    0,    0,   89,   89,    0,   89,   89,   89,
   89,    0,   89,   89,    0,  179,    0,   38,    0,    0,
    0,   97,    0,  156,   38,    0,    0,    0,   72,   76,
   77,    0,    0,    0,   38,   35,    0,    0,    0,  129,
    0,    0,    0,    0,    0,    0,    0,   38,    0,    0,
    0,    0,   38,    0,   72,   76,   77,   38,   64,    0,
  168,    0,    0,    0,    0,   72,   76,   77,    0,    0,
    0,   90,   90,    0,    0,    0,    0,    0,    0,    0,
    0,   90,   90,    0,   90,   90,   90,   90,    0,   90,
   90,    0,    0,   88,   88,    0,    0,    0,    0,    0,
    0,    0,    0,   88,   88,    0,   88,   88,   88,   88,
    0,   88,   88,   56,   57,   58,   59,   60,    0,   61,
    0,    0,   87,   87,    0,    0,    0,    0,    0,    0,
    0,    0,   87,   87,    0,   87,   87,   87,   87,    0,
   87,   87,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  105,  106,  107,  108,  109,
  110,  111,  112,  113,  114,  115,  116,  117,  118,  119,
  120,  121,  123,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  143,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  158,    0,    0,
    0,    0,    0,    0,    0,  166,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  171,    0,
    0,    0,    0,  175,
};
static const YYINT yycheck[] = {                         33,
   35,   59,   91,   37,   38,   44,   40,   41,   42,   43,
   44,   45,   40,   47,   59,   37,    7,   59,   59,  257,
   59,  259,  128,   59,  130,   59,   60,   61,   62,   52,
   41,   37,  285,   44,   40,   33,   42,  260,  261,   37,
   38,   47,   40,   41,   42,   43,   44,   45,  154,   47,
  267,  268,  269,  270,   45,   41,   91,   59,   44,   93,
   94,   59,   60,   61,   62,   59,   94,   41,   91,   59,
   44,   33,   95,  258,  263,   37,   38,   59,   40,   41,
   42,   43,   44,   45,  258,   47,    6,  257,   94,   59,
  124,   59,  285,   59,  285,   93,   94,   59,   60,   61,
   62,   40,   91,  276,  277,  278,   95,   33,   91,   59,
  133,   37,   38,  263,   34,   41,   42,   43,   44,   45,
  142,   47,  267,  268,  258,  270,  124,  126,   48,  285,
   44,   93,   94,   59,   60,   61,   62,  265,  266,  267,
  268,  269,  270,   33,  133,   93,  278,   37,   38,  278,
  149,   41,   42,   43,   44,   45,  272,   47,  267,  268,
  159,  270,  124,  272,  273,  263,  263,   93,   94,   59,
   60,   61,   62,  172,  276,  277,  278,  278,  177,  272,
   33,    2,   49,  182,   37,   38,   48,   34,   41,   42,
   43,   44,   45,  126,   47,   45,  285,    7,  124,  276,
  277,  278,  130,   93,   94,  263,   59,   60,   61,   62,
   37,  142,  163,   40,   -1,   42,   43,  262,   45,   -1,
   47,  262,  263,  262,  263,   -1,  262,  263,  262,  263,
  272,  273,   -1,   60,  124,   62,  272,  273,  272,  273,
   93,  275,  276,  277,  278,   -1,  280,  281,   -1,  285,
  285,   -1,  286,  287,  288,   -1,   38,   -1,   40,   -1,
  262,  263,   -1,   45,  262,  263,   -1,   94,  262,  263,
   -1,  124,  262,  263,  272,  273,   -1,  275,  276,  277,
  278,   63,  280,  281,   -1,   -1,   -1,   -1,  286,  287,
  288,   -1,  262,  263,  262,  263,  262,  263,   -1,   -1,
  262,  263,  272,   -1,   -1,   -1,  276,  277,  278,   -1,
  272,  273,   -1,  275,  276,  277,  278,   -1,  280,  281,
   -1,   -1,   -1,   -1,  286,  287,  288,  263,  264,  265,
  266,  267,  268,   -1,  270,  271,  262,  263,  267,  268,
   -1,  270,  271,   59,  126,   -1,  272,  273,   -1,  275,
  276,  277,  278,   -1,  280,  281,   38,   -1,   40,   -1,
  286,  287,  288,   45,   -1,   -1,   33,   -1,   -1,   -1,
   37,   38,  262,  263,   41,   42,   43,   44,   45,   -1,
   47,   63,  272,  273,   -1,  275,  276,  277,  278,   -1,
  280,  281,   59,   60,   61,   62,  286,  287,  288,   -1,
   -1,   -1,   -1,   33,   -1,   -1,   -1,   37,   38,  262,
  263,   41,   42,   43,   44,   45,   -1,   47,   -1,  272,
  273,   -1,  275,  276,  277,  278,   93,  280,  281,   59,
   60,   61,   62,  286,  287,  288,   -1,   -1,   33,   -1,
   -1,   -1,   37,   38,  126,   -1,   41,   42,   43,   44,
   45,   -1,   47,   -1,   -1,   -1,   -1,  124,   -1,   -1,
  287,  288,   -1,   93,   59,   60,   61,   62,   -1,   -1,
   -1,   -1,   -1,   33,   -1,  257,  258,  259,   38,   -1,
   -1,   41,   -1,   43,   44,   45,   -1,   -1,   -1,   -1,
   -1,   -1,  274,   -1,  124,   -1,   -1,  279,   93,   59,
   60,   61,   62,  264,  265,  266,  267,  268,   33,  270,
  271,   -1,   -1,   38,   -1,   -1,   41,   -1,   43,   44,
   45,   -1,   37,   -1,   -1,   40,   -1,   42,   43,  124,
   45,   -1,   47,   93,   59,   60,   61,   62,   38,   -1,
   40,   41,   -1,   33,   -1,   45,  262,  263,   38,   -1,
   -1,   41,   -1,   -1,   44,   -1,  272,   -1,   -1,   -1,
  276,  277,  278,   63,  124,   -1,   -1,   -1,   93,   59,
   60,   61,   62,   -1,   -1,  257,  258,  259,   -1,   94,
   -1,   -1,   -1,   -1,   -1,  267,  268,   -1,  270,   -1,
   -1,   -1,  274,   -1,   -1,  262,  263,  279,   -1,  124,
  282,  283,  284,   93,   -1,  272,  273,   -1,  275,  276,
  277,  278,   -1,  280,  281,   -1,   -1,   -1,   -1,  286,
  287,  288,   -1,   -1,   -1,   -1,  126,   -1,   -1,   -1,
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
   59,   60,   61,   62,   -1,   -1,   -1,  272,  273,   -1,
  275,  276,  277,  278,   -1,  280,  281,  257,  258,  259,
   -1,  286,  287,  288,   -1,   -1,   -1,   -1,   -1,   -1,
  124,   -1,  262,  263,   93,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  272,  273,   -1,  275,  276,  277,  278,   -1,
  280,  281,   -1,   -1,   -1,   -1,  286,  287,  288,   33,
   -1,   -1,   -1,   37,   38,  124,   40,   -1,   42,   43,
   33,   45,   -1,   47,   37,   38,   -1,   40,   -1,   42,
   43,   -1,   45,   -1,   47,   59,   60,   61,   62,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   59,   60,   61,   62,
   33,   -1,   59,   -1,   -1,   38,   -1,   -1,   41,   -1,
   -1,   44,   -1,   37,   38,   -1,   40,   -1,   42,   43,
   94,   45,   -1,   47,   -1,   -1,   59,   -1,   61,   -1,
   -1,   94,   -1,  262,  263,   -1,   60,   61,   62,   -1,
   -1,   -1,   -1,  272,  273,   -1,  275,  276,  277,  278,
  124,  280,  281,   -1,   -1,   -1,   -1,  286,  287,  288,
   93,  124,   -1,   -1,   -1,   -1,   -1,   -1,  262,  263,
   94,   -1,   -1,   38,   -1,   40,   -1,   -1,  272,  273,
   45,  275,  276,  277,  278,   -1,  280,  281,   -1,   -1,
   -1,  124,  286,  287,  288,   -1,   -1,   33,   63,   -1,
  124,   -1,   38,  262,  263,   41,   -1,   -1,   44,   -1,
   -1,   -1,   -1,  272,  273,   -1,  275,  276,  277,  278,
   -1,  280,  281,   59,   -1,   61,   -1,  286,  287,  288,
   37,   38,   -1,   40,   -1,   42,   43,   -1,   45,   -1,
   47,   37,   38,   -1,   40,   41,   42,   43,   -1,   45,
   -1,   47,   -1,   60,   61,   62,   -1,   93,   -1,   -1,
   -1,  126,   -1,   -1,   60,   61,   62,   38,   -1,   40,
   37,   38,   -1,   40,   45,   42,   43,   -1,   45,   -1,
   47,   -1,   -1,   -1,   -1,   -1,   -1,   94,  124,   -1,
   -1,   -1,   63,   60,   61,   62,   -1,   -1,   94,   -1,
   -1,   -1,   -1,   -1,   -1,  262,  263,   -1,   -1,   -1,
   -1,   -1,  286,  287,  288,  272,   -1,  124,   -1,  276,
  277,  278,   -1,  286,  287,  288,   93,   94,  124,  262,
  263,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  272,
  273,   -1,  275,  276,  277,  278,   -1,  280,  281,   -1,
   -1,  275,   -1,  286,   -1,  126,   -1,  124,   -1,   -1,
   -1,   -1,  286,  287,  288,   37,   38,   -1,   40,   -1,
   42,   43,   -1,   45,   -1,   47,   37,   38,   -1,   40,
   -1,   42,   43,   -1,   45,   -1,   47,   59,   60,   61,
   62,   -1,  257,  258,  259,   -1,   -1,   -1,   -1,   60,
   61,   62,  267,  268,   -1,  270,   -1,   37,   38,  274,
   40,   -1,   42,   43,  279,   45,   -1,   47,   -1,   -1,
   -1,   -1,   94,   -1,   -1,   -1,  262,  263,   -1,   -1,
   60,   61,   62,   94,   -1,   -1,  272,  273,   -1,  275,
  276,  277,  278,   -1,  280,  281,   38,   -1,   40,   -1,
  286,   37,  124,   45,   40,   -1,   42,   43,   -1,   45,
   -1,   47,   -1,  124,   94,   -1,   -1,   -1,   -1,   -1,
   -1,   63,   -1,  280,   60,   61,   62,   -1,   -1,  286,
  287,  288,   -1,   -1,   -1,   33,  257,  258,  259,   -1,
  286,  287,  288,   41,  124,   -1,   44,   -1,   -1,   37,
   38,   -1,   40,   -1,   42,   43,   -1,   45,   94,   47,
   -1,   59,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  286,
  287,  288,   60,   61,   62,   37,   38,   -1,   40,   -1,
   42,   43,   -1,   45,  126,   47,   37,   38,   -1,   40,
   -1,   42,   43,   -1,   45,   93,   47,   -1,   60,   61,
   62,   -1,   -1,   -1,   -1,   -1,   94,   -1,   -1,   60,
   61,   62,   33,   -1,   -1,   -1,   -1,   38,   -1,   -1,
   41,   -1,   -1,   44,   -1,   -1,  124,   -1,   -1,   -1,
   -1,   -1,   94,   -1,   33,   -1,  124,   -1,   59,   38,
   -1,   -1,   41,   94,  262,   44,  264,  265,  266,  267,
  268,    6,  270,  271,   -1,   -1,   -1,   -1,   -1,   -1,
   59,   -1,  124,   33,  286,  287,  288,   -1,   -1,   -1,
  281,   41,   93,   -1,   44,  286,  287,  288,   -1,   34,
   -1,   -1,   37,   -1,   -1,    6,   -1,   -1,   -1,   59,
   -1,   -1,   13,   48,   93,  275,   17,   -1,   40,   -1,
   42,   -1,   -1,  124,   -1,   -1,  286,  287,  288,   -1,
   52,   -1,   -1,   34,   -1,  257,  258,  259,   -1,   -1,
   -1,   -1,   -1,   93,   -1,  124,   -1,   48,   -1,   50,
   -1,   -1,  274,   -1,   -1,   -1,   -1,  279,   -1,   -1,
  282,  283,  284,   -1,   -1,   -1,  101,   -1,   -1,   91,
  286,  287,  288,   95,   -1,   97,   -1,   -1,  100,   -1,
   -1,   -1,   -1,   -1,  262,  263,   -1,   -1,   89,   -1,
   -1,  126,   -1,   -1,  272,  273,   -1,  275,  276,  277,
  278,   -1,  280,  281,   -1,  273,   -1,  142,   -1,   -1,
   -1,  133,   -1,  135,  149,   -1,   -1,   -1,  286,  287,
  288,   -1,   -1,   -1,  159,  126,   -1,   -1,   -1,  130,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  172,   -1,   -1,
   -1,   -1,  177,   -1,  286,  287,  288,  182,  149,   -1,
  151,   -1,   -1,   -1,   -1,  286,  287,  288,   -1,   -1,
   -1,  262,  263,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  272,  273,   -1,  275,  276,  277,  278,   -1,  280,
  281,   -1,   -1,  262,  263,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  272,  273,   -1,  275,  276,  277,  278,
   -1,  280,  281,   25,   26,   27,   28,   29,   -1,   31,
   -1,   -1,  262,  263,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  272,  273,   -1,  275,  276,  277,  278,   -1,
  280,  281,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   67,   68,   69,   70,   71,
   72,   73,   74,   75,   76,   77,   78,   79,   80,   81,
   82,   83,   84,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  102,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  139,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  147,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  160,   -1,
   -1,   -1,   -1,  165,
};
#define YYFINAL 3
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 306
#define YYUNDFTOKEN 339
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
"UNTIL","STEP","REPEAT","STOP","RETURN","ATTR","NE","LE","GE","ADDR","UMINUS",
"NIL","DECLS","DECL","FUNCTYPE","QUALIFIER","VARS","VAR","BODY","BODYVARS",
"RETURN_EXPR","ELIFS","INSTRS_INSTRTERM","INSTRS","TWO_INTEGERS",
"MORE_INTEGERS","ARGS",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : file",
"file : program",
"file : module",
"program : PROGRAM decls START bodyprincipal END",
"program : PROGRAM START bodyprincipal END",
"module : MODULE decls END",
"module : MODULE END",
"decls : decl",
"decls : decls ';' decl",
"decl : func",
"decl : qualifier CONST var ATTR literal",
"decl : qualifier var ATTR literal",
"decl : qualifier var",
"decl : qualifier CONST var",
"decl : CONST var",
"decl : CONST var ATTR literal",
"decl : var",
"decl : var ATTR literal",
"func : FUNCTION qualifier functype ID vars funcend",
"func : FUNCTION functype ID vars funcend",
"func : FUNCTION qualifier functype ID funcend",
"func : FUNCTION functype ID funcend",
"funcend : DONE",
"funcend : DO body",
"functype : type",
"functype : VOID",
"qualifier : PUBLIC",
"qualifier : FORWARD",
"vars : var",
"vars : vars ';' var",
"var : type ID",
"var : type ID '[' integer ']'",
"type : NUMBER",
"type : ARRAY",
"type : STRING",
"bodyprincipal : bodyvars bodyinstrs",
"bodyprincipal : bodyinstrs",
"body : bodyvars block",
"body : block",
"bodyinstrs :",
"bodyinstrs : instrs",
"bodyvars : var ';'",
"bodyvars : bodyvars var ';'",
"instr : IF expr THEN block FI",
"instr : IF expr THEN block elifs ELSE block FI",
"instr : IF expr THEN block elifs FI",
"instr : IF expr THEN block ELSE block FI",
"$$1 :",
"instr : FOR expr UNTIL expr STEP expr DO $$1 block DONE",
"instr : expr ';'",
"instr : expr '!'",
"instr : lvalue '#' expr ';'",
"instrterm : REPEAT",
"instrterm : STOP",
"instrterm : RETURN expr",
"instrterm : RETURN",
"elif : ELIF expr THEN block",
"elifs : elif",
"elifs : elifs elif",
"block :",
"block : instrterm",
"block : instrs",
"block : instrs instrterm",
"instrs : instr",
"instrs : instrs instr",
"lvalue : ID",
"lvalue : lvalue '[' expr ']'",
"expr : lvalue",
"expr : '(' expr ')'",
"expr : expr '(' args ')'",
"expr : expr '(' ')'",
"expr : string",
"expr : integer",
"expr : '-' expr",
"expr : '&' expr",
"expr : expr '^' expr",
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
"expr : lvalue ATTR expr",
"expr : expr '&' expr",
"expr : expr '|' expr",
"expr : '~' expr",
"expr : '?'",
"literal : string",
"literal : integerlist",
"integer : INTEGER",
"string : stringintegerlist",
"string : STR",
"stringintegerlist : integer integer",
"stringintegerlist : stringintegerlist integer",
"integerlist : integer",
"integerlist : integerlist ',' integer",
"args : expr",
"args : args ',' expr",

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
#line 208 "gram.y"

char **yynames =
#if YYDEBUG > 0
		 (char**)yyname;
#else
		 0;
#endif

int nostring(Node *arg1, Node *arg2) {
	if (arg1->info % 5 == 2 || arg2->info % 5 == 2)
		yyerror("can not use strings");
	return arg1->info % 5 == 3 || arg2->info % 5 == 3 ? 3 : 1;
}

int intonly(Node *arg, int novar) {
	if (arg->info % 5 != 1)
		yyerror("only integers can be used");
	if (arg->info % 10 > 5)
		yyerror("argument is constant");
	return 1;
}

int noassign(Node *arg1, Node *arg2) {
	int t1 = arg1->info, t2 = arg2->info;
	if (t1 == t2) return 0;
	if (t1 == 2 && t2 == 11) return 0; /* string := int* */
	if (t1 == 2 && arg2->attrib == INTEGER && arg2->value.i == 0)
		return 0; /* string := 0 */
	if (t1 > 10 && t1 < 20 && arg2->attrib == INTEGER && arg2->value.i == 0)
		return 0; /* pointer := 0 */
	return 1;
}
#line 784 "y.tab.c"

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
case 1:
#line 48 "gram.y"
	{ printNode(yystack.l_mark[0].n,0,yynames); }
break;
case 2:
#line 49 "gram.y"
	{ printNode(yystack.l_mark[0].n,0,yynames); }
break;
case 3:
#line 52 "gram.y"
	{ yyval.n = binNode(PROGRAM, yystack.l_mark[-3].n, yystack.l_mark[-1].n); }
break;
case 4:
#line 53 "gram.y"
	{ yyval.n = uniNode(PROGRAM, yystack.l_mark[-1].n); }
break;
case 5:
#line 56 "gram.y"
	{ yyval.n = uniNode(MODULE, yystack.l_mark[-1].n); }
break;
case 6:
#line 57 "gram.y"
	{ yyval.n = nilNode(MODULE); }
break;
case 7:
#line 60 "gram.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 8:
#line 61 "gram.y"
	{ yyval.n = binNode(DECLS, yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 9:
#line 64 "gram.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 10:
#line 65 "gram.y"
	{ yyval.n = binNode(QUALIFIER, yystack.l_mark[-4].n, binNode(VAR, yystack.l_mark[-2].n, yystack.l_mark[0].n)); }
break;
case 11:
#line 66 "gram.y"
	{ yyval.n = binNode(QUALIFIER, yystack.l_mark[-3].n, binNode(VAR, yystack.l_mark[-2].n, yystack.l_mark[0].n)); }
break;
case 12:
#line 67 "gram.y"
	{ yyval.n = binNode(DECL, yystack.l_mark[-1].n, yystack.l_mark[0].n); }
break;
case 13:
#line 68 "gram.y"
	{ yyval.n = binNode(DECL, yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 14:
#line 69 "gram.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 15:
#line 70 "gram.y"
	{ yyval.n = binNode(DECL, yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 16:
#line 71 "gram.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 17:
#line 72 "gram.y"
	{ yyval.n = binNode(DECL, yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 18:
#line 75 "gram.y"
	{ yyval.n = binNode(QUALIFIER, yystack.l_mark[-4].n, binNode(FUNCTYPE, yystack.l_mark[-3].n, binNode(ID, strNode(ID, yystack.l_mark[-2].s), binNode(VARS, yystack.l_mark[-1].n, uniNode(END, yystack.l_mark[0].n))))); }
break;
case 19:
#line 76 "gram.y"
	{ yyval.n = binNode(FUNCTYPE, yystack.l_mark[-3].n, binNode(ID, strNode(ID, yystack.l_mark[-2].s), binNode(VARS, yystack.l_mark[-1].n, uniNode(END, yystack.l_mark[0].n)))); }
break;
case 20:
#line 77 "gram.y"
	{ yyval.n = binNode(QUALIFIER, yystack.l_mark[-3].n, binNode(FUNCTYPE, yystack.l_mark[-2].n, binNode(ID, strNode(ID, yystack.l_mark[-1].s), uniNode(END, yystack.l_mark[0].n)))); }
break;
case 21:
#line 78 "gram.y"
	{ yyval.n = binNode(FUNCTYPE, yystack.l_mark[-2].n, binNode(ID, strNode(ID, yystack.l_mark[-1].s), uniNode(END, yystack.l_mark[0].n))); }
break;
case 22:
#line 81 "gram.y"
	{ yyval.n = nilNode(DONE); }
break;
case 23:
#line 82 "gram.y"
	{ yyval.n = uniNode(DO, yystack.l_mark[0].n); }
break;
case 24:
#line 85 "gram.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 25:
#line 86 "gram.y"
	{ yyval.n = nilNode(VOID); }
break;
case 26:
#line 89 "gram.y"
	{ yyval.n = nilNode(PUBLIC); }
break;
case 27:
#line 90 "gram.y"
	{ yyval.n = nilNode(FORWARD); }
break;
case 28:
#line 93 "gram.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 29:
#line 94 "gram.y"
	{ yyval.n = binNode(VARS, yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 30:
#line 97 "gram.y"
	{ yyval.n = binNode(VAR, yystack.l_mark[-1].n, strNode(ID, yystack.l_mark[0].s)); }
break;
case 31:
#line 98 "gram.y"
	{ yyval.n = binNode(VAR, yystack.l_mark[-4].n, binNode(ID, strNode(ID, yystack.l_mark[-3].s), yystack.l_mark[-1].n)); }
break;
case 32:
#line 101 "gram.y"
	{ yyval.n = nilNode(NUMBER); }
break;
case 33:
#line 102 "gram.y"
	{ yyval.n = nilNode(ARRAY); }
break;
case 34:
#line 103 "gram.y"
	{ yyval.n = nilNode(STRING); }
break;
case 35:
#line 106 "gram.y"
	{ yyval.n = binNode(BODY, yystack.l_mark[-1].n, yystack.l_mark[0].n); }
break;
case 36:
#line 107 "gram.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 37:
#line 110 "gram.y"
	{ yyval.n = binNode(BODY, yystack.l_mark[-1].n, yystack.l_mark[0].n); }
break;
case 38:
#line 111 "gram.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 39:
#line 114 "gram.y"
	{ yyval.n = nilNode(NIL); }
break;
case 40:
#line 115 "gram.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 41:
#line 118 "gram.y"
	{ yyval.n = yystack.l_mark[-1].n; }
break;
case 42:
#line 119 "gram.y"
	{ yyval.n = binNode(BODYVARS, yystack.l_mark[-2].n, yystack.l_mark[-1].n); }
break;
case 43:
#line 122 "gram.y"
	{ yyval.n = binNode(IF, yystack.l_mark[-3].n, yystack.l_mark[-1].n); }
break;
case 44:
#line 123 "gram.y"
	{ yyval.n = binNode(IF, yystack.l_mark[-6].n, binNode(THEN, yystack.l_mark[-4].n, binNode(ELIF, yystack.l_mark[-3].n, uniNode(ELSE, yystack.l_mark[-1].n)))); }
break;
case 45:
#line 124 "gram.y"
	{ yyval.n = binNode(IF, yystack.l_mark[-4].n, binNode(THEN, yystack.l_mark[-2].n, uniNode(ELIF, yystack.l_mark[-1].n))); }
break;
case 46:
#line 125 "gram.y"
	{ yyval.n = binNode(IF, yystack.l_mark[-5].n, binNode(THEN, yystack.l_mark[-3].n, uniNode(ELSE, yystack.l_mark[-1].n))); }
break;
case 47:
#line 126 "gram.y"
	{ ncicl++; }
break;
case 48:
#line 126 "gram.y"
	{ yyval.n = binNode(FOR, yystack.l_mark[-8].n, binNode(UNTIL, yystack.l_mark[-6].n, binNode(STEP, yystack.l_mark[-4].n, uniNode(DO, yystack.l_mark[-2].n)))); ncicl--; }
break;
case 49:
#line 127 "gram.y"
	{ yyval.n = yystack.l_mark[-1].n; }
break;
case 50:
#line 128 "gram.y"
	{ yyval.n = yystack.l_mark[-1].n; }
break;
case 51:
#line 129 "gram.y"
	{ yyval.n = binNode('#', yystack.l_mark[-3].n, yystack.l_mark[-1].n); }
break;
case 52:
#line 132 "gram.y"
	{ yyval.n = nilNode(REPEAT); if (ncicl <= 0) yyerror("invalid repeat argument"); }
break;
case 53:
#line 133 "gram.y"
	{ yyval.n = nilNode(STOP); if (ncicl <= 0) yyerror("invalid stop argument"); }
break;
case 54:
#line 134 "gram.y"
	{ yyval.n = uniNode(RETURN_EXPR, yystack.l_mark[0].n); }
break;
case 55:
#line 135 "gram.y"
	{ yyval.n = nilNode(RETURN); }
break;
case 56:
#line 138 "gram.y"
	{ yyval.n = binNode(ELIF, yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 57:
#line 141 "gram.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 58:
#line 142 "gram.y"
	{ yyval.n = binNode(ELIFS, yystack.l_mark[-1].n, yystack.l_mark[0].n); }
break;
case 59:
#line 145 "gram.y"
	{ yyval.n = nilNode(NIL); }
break;
case 60:
#line 146 "gram.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 61:
#line 147 "gram.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 62:
#line 148 "gram.y"
	{ yyval.n = binNode(INSTRS_INSTRTERM, yystack.l_mark[-1].n, yystack.l_mark[0].n); }
break;
case 63:
#line 151 "gram.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 64:
#line 152 "gram.y"
	{ yyval.n = binNode(INSTRS, yystack.l_mark[-1].n, yystack.l_mark[0].n); }
break;
case 65:
#line 155 "gram.y"
	{ yyval.n = strNode(ID, yystack.l_mark[0].s); }
break;
case 66:
#line 156 "gram.y"
	{ yyval.n = binNode('[', yystack.l_mark[-3].n, yystack.l_mark[-1].n); }
break;
case 67:
#line 159 "gram.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 68:
#line 160 "gram.y"
	{ yyval.n = yystack.l_mark[-1].n; }
break;
case 69:
#line 161 "gram.y"
	{ yyval.n = binNode('(', yystack.l_mark[-3].n, yystack.l_mark[-1].n); }
break;
case 70:
#line 162 "gram.y"
	{ yyval.n = yystack.l_mark[-2].n; }
break;
case 71:
#line 163 "gram.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 72:
#line 164 "gram.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 73:
#line 165 "gram.y"
	{ yyval.n = uniNode(UMINUS, yystack.l_mark[0].n); }
break;
case 74:
#line 166 "gram.y"
	{ yyval.n = uniNode(ADDR, yystack.l_mark[0].n); }
break;
case 75:
#line 167 "gram.y"
	{ yyval.n = binNode('^', yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 76:
#line 168 "gram.y"
	{ yyval.n = binNode('+', yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 77:
#line 169 "gram.y"
	{ yyval.n = binNode('-', yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 78:
#line 170 "gram.y"
	{ yyval.n = binNode('*', yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 79:
#line 171 "gram.y"
	{ yyval.n = binNode('/', yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 80:
#line 172 "gram.y"
	{ yyval.n = binNode('%', yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 81:
#line 173 "gram.y"
	{ yyval.n = binNode('<', yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 82:
#line 174 "gram.y"
	{ yyval.n = binNode('>', yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 83:
#line 175 "gram.y"
	{ yyval.n = binNode(GE, yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 84:
#line 176 "gram.y"
	{ yyval.n = binNode(LE, yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 85:
#line 177 "gram.y"
	{ yyval.n = binNode(NE, yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 86:
#line 178 "gram.y"
	{ yyval.n = binNode('=', yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 87:
#line 179 "gram.y"
	{ yyval.n = binNode(ATTR, yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 88:
#line 180 "gram.y"
	{ yyval.n = binNode('&', yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 89:
#line 181 "gram.y"
	{ yyval.n = binNode('|', yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 90:
#line 182 "gram.y"
	{ yyval.n = uniNode('~', yystack.l_mark[0].n); }
break;
case 91:
#line 183 "gram.y"
	{ yyval.n = nilNode('?'); }
break;
case 92:
#line 186 "gram.y"
	{ yyval.n = yystack.l_mark[0].n; yyval.n->info = yystack.l_mark[0].n->info; }
break;
case 93:
#line 187 "gram.y"
	{ yyval.n = yystack.l_mark[0].n; yyval.n->info = yystack.l_mark[0].n->info; }
break;
case 94:
#line 190 "gram.y"
	{ yyval.n = intNode(INTEGER, yystack.l_mark[0].i); yyval.n->info = 1; }
break;
case 95:
#line 193 "gram.y"
	{ yyval.n = yystack.l_mark[0].n; yyval.n->info = yystack.l_mark[0].n->info; }
break;
case 96:
#line 194 "gram.y"
	{ yyval.n = strNode(STR, yystack.l_mark[0].s); yyval.n->info = 2; }
break;
case 97:
#line 197 "gram.y"
	{ yyval.n = binNode(TWO_INTEGERS, yystack.l_mark[-1].n, yystack.l_mark[0].n); yyval.n->info = 2; }
break;
case 98:
#line 198 "gram.y"
	{ yyval.n = binNode(MORE_INTEGERS, yystack.l_mark[-1].n, yystack.l_mark[0].n); yyval.n->info = 2; }
break;
case 99:
#line 200 "gram.y"
	{ yyval.n = yystack.l_mark[0].n; yyval.n->info = yystack.l_mark[0].n->info; }
break;
case 100:
#line 201 "gram.y"
	{ yyval.n = binNode(',', yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = 2; }
break;
case 101:
#line 204 "gram.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 102:
#line 205 "gram.y"
	{ yyval.n = binNode(ARGS, yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
#line 1394 "y.tab.c"
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
