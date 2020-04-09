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

void declare(Node *pub, int cnst, Node *type, char *name, Node *value);
int nostring(Node *arg1, Node *arg2);
int intonly(Node *arg, int);
int noassign(Node *arg1, Node *arg2);
static int ncicl;
#line 20 "gram.y"
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
#line 52 "y.tab.c"

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
   14,   14,   15,   15,   15,    6,    6,    5,    5,    7,
    7,    8,    8,   16,   16,   16,   16,   30,   16,   16,
   16,   16,   17,   17,   17,   17,   18,   19,   19,   20,
   20,   20,   20,   21,   21,   22,   22,   23,   23,   23,
   23,   23,   23,   23,   23,   23,   23,   23,   23,   23,
   23,   23,   23,   23,   23,   23,   23,   23,   23,   23,
   23,   23,   24,   24,   25,   27,   27,   28,   28,   26,
   26,   29,   29,
};
static const YYINT yylen[] = {                            2,
    1,    1,    5,    4,    3,    2,    1,    3,    1,    5,
    4,    2,    3,    2,    4,    1,    3,    6,    5,    5,
    4,    1,    2,    1,    1,    1,    1,    1,    3,    2,
    2,    5,    1,    1,    1,    2,    1,    2,    1,    0,
    1,    2,    3,    5,    8,    6,    7,    0,   10,    2,
    2,    4,    1,    1,    2,    1,    4,    1,    2,    0,
    1,    1,    2,    1,    2,    1,    4,    1,    3,    4,
    3,    1,    1,    2,    2,    3,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    3,    3,    3,
    2,    1,    1,    1,    1,    1,    1,    2,    2,    1,
    3,    1,    3,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,    1,    2,    0,    0,   26,   27,    0,
    0,    0,    0,    0,    7,    9,    0,    0,    6,    0,
   95,   66,   97,    0,    0,    0,    0,    0,   92,    0,
    0,   37,    0,    0,   64,    0,    0,    0,    0,   72,
    0,   33,   34,   25,   35,    0,    0,   24,   31,    0,
   30,    0,    0,    0,    0,    0,    0,    5,    0,    0,
    0,    0,    0,    0,    0,    4,   36,    0,   42,   65,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   50,   51,
   98,   99,    0,    0,    0,    0,    0,    8,    0,    0,
   17,    0,    0,   93,    0,    0,   69,   43,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   71,    0,    0,   22,    0,
   21,    0,   28,    0,    0,   15,    3,    0,   11,    0,
   53,   54,    0,   61,    0,    0,    0,   67,   52,   70,
    0,   23,    0,   39,    0,   19,   20,    0,   32,   10,
  101,    0,    0,    0,   44,   58,    0,   63,    0,    0,
   38,   29,   18,    0,    0,    0,   46,   59,    0,   47,
    0,    0,   48,   57,   45,    0,    0,   49,
};
static const YYINT yydgoto[] = {                          3,
    4,    5,   14,   15,  152,   31,   32,   33,   16,  131,
   46,   17,  132,   18,   48,   35,  144,  166,  167,  145,
  146,   59,   38,  101,   39,  103,   40,   41,  128,  186,
};
static const YYINT yysindex[] = {                      -222,
  261, -161,    0,    0,    0,  876,  222,    0,    0, -236,
 -234, -227, -214,  -44,    0,    0,   64, -252,    0,  -57,
    0,    0,    0,  970,  970,  970,  970,  970,    0,  970,
 -211,    0,  876,   15,    0,  219,  -34,  767, -198,    0,
 -198,    0,    0,    0,    0, -190, -139,    0,    0,   -4,
    0, -170,  876, -125, -214, -162, -239,    0,  -88,  817,
  934,   55, 1155,   55,  945,    0,    0,   66,    0,    0,
  970,  970,  970,  970,  970,  970,  970,  970,  970,  970,
  970,  970,  970,  970,  970,  970,  970,  501,    0,    0,
    0,    0, -108, -120, -198, -239, -116,    0, -135, -239,
    0, -198,  107,    0, 1149,  970,    0,    0, 1229,  974,
 1069, 1240, 1155,  174,  174,  137,  137,  137,  137,   -5,
   -5,  -23,  -23,  -23,  -23,    0, 1229,   34,    0,  319,
    0,  -46,    0, -108,   68,    0,    0, -239,    0, -198,
    0,    0,  970,    0,  -76, 1149, 1080,    0,    0,    0,
  970,    0,  319,    0, -214,    0,    0,  -46,    0,    0,
    0, 1229, 1149,  970,    0,    0,    9,    0,  970, 1229,
    0,    0,    0, -121, 1111, 1149,    0,    0, 1203,    0,
 1149, -112,    0,    0,    0, 1149, -105,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,    0,  -87,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  -40,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  -87,    0,    0,  -85,  778,    0,  -33,    0,
    3,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  -25,  -87,    0,    0,   -1,    0,    0,   39,    0,
    0,   75, 1270,  111,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    7,    0,
    0,  -38,   11,    0,   21,    0,    0,    0, 1321,    0,
    0, 1193, 1292,  808,  905,  511,  612,  647,  682,  441,
  476,  148,  334,  371,  406,    0,   44,    0,    0,   33,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   31,    0,    0,  285,    0,    0,    0,    0,
    0,    0,   33,    0,    0,    0,    0,    0,    0,    0,
    0,  784, -103,    0,    0,    0,    0,    0,    0,   80,
    0,    0,    0,    0,    0, -103,    0,    0,    0,    0,
   21,    0,    0,    0,    0,  -89,    0,    0,
};
static const YYINT yygindex[] = {                         0,
    0,    0,  185,  134,    0,  141,  163,   73,    0, -109,
  151,  205,   79, 1358,    0,  -20,   69,   53,    0,  147,
   61, 1273, 1532,  -45,  416,    0,  -27,    0,    0,    0,
};
#define YYTABLESIZE 1701
static const YYINT yytable[] = {                         73,
   73,   54,   72,   73,   73,  100,   73,   73,   73,   73,
   73,   73,  155,   73,   54,   70,   88,   21,   16,   23,
  100,   49,  156,   50,  157,   73,   73,   73,   73,  104,
   51,   86,   57,   14,   88,   96,   84,    1,    2,   96,
   96,   85,   96,   96,   96,   96,   96,   96,  173,   96,
  136,   66,   10,   11,  139,   12,   72,   12,   21,   73,
   73,   96,   96,   96,   96,   13,   36,   93,  104,   94,
   87,   68,  104,   69,  150,   68,   68,  151,   68,   68,
   68,   68,   68,   68,  102,   68,   95,  102,   87,   56,
   73,   60,  160,   36,   88,   96,   96,   68,   68,   68,
   68,   19,    7,    8,    9,   10,   11,   75,   12,   13,
  104,   75,   75,   36,   96,   75,   75,   75,   75,   75,
  103,   75,  100,  103,  108,   70,   96,   42,   43,   44,
   45,   68,   68,   75,   75,   75,   75,  134,    7,    8,
    9,   10,   11,   74,   12,   13,  137,   74,   74,  138,
  140,   74,   74,   74,   74,   74,  180,   74,   10,   11,
  159,   12,   68,  129,  130,  185,  188,   75,   75,   74,
   74,   74,   74,   86,   60,   40,   88,   41,   84,   82,
   79,   83,   60,   85,   79,   79,   20,   98,   79,   79,
   79,   79,   79,   97,   79,   67,   71,   94,   75,  163,
  164,  165,  153,   74,   74,   58,   79,   79,   79,   79,
   86,   47,  158,   88,  168,   84,   82,   53,   83,  178,
   85,   16,   16,  100,  100,  129,  130,    0,   73,   73,
   87,    0,    0,   78,   74,   79,   14,   14,   73,   73,
   79,   73,   73,   73,   73,    0,   73,   73,    0,    0,
   71,    0,   73,   73,   73,    0,   26,    0,   30,    0,
   12,   12,    0,   28,   96,   96,    0,   87,   13,   13,
    0,   79,   94,   94,   96,   96,  154,   96,   96,   96,
   96,   29,   96,   96,  176,  164,  177,    0,   96,   96,
   96,    0,   56,   56,   60,   60,   60,   60,   60,  171,
   68,   68,   56,    0,    0,    0,   56,   56,   56,  174,
   68,   68,    0,   68,   68,   68,   68,    0,   68,   68,
    0,    0,  182,    0,   68,   68,   68,  184,    0,    0,
   10,   11,  187,   12,   55,    0,   75,   75,    0,    0,
    0,    0,    0,   62,   27,    0,   75,   75,    0,   75,
   75,   75,   75,    0,   75,   75,   26,    0,   30,    0,
   75,   75,   75,   28,    0,    0,   80,    0,    0,    0,
   80,   80,   74,   74,   80,   80,   80,   80,   80,    0,
   80,   29,   74,   74,    0,   74,   74,   74,   74,    0,
   74,   74,   80,   80,   80,   80,   74,   74,   74,    0,
    0,    0,    0,   81,    0,    0,    0,   81,   81,   79,
   79,   81,   81,   81,   81,   81,    0,   81,    0,   79,
   79,    0,   79,   79,   79,   79,   80,   79,   79,   81,
   81,   81,   81,   79,   79,   79,    0,    0,   76,    0,
    0,    0,   76,   76,   27,    0,   76,   76,   76,   76,
   76,    0,   76,    0,   91,    0,   92,   80,    0,    0,
   80,   81,    0,   81,   76,   76,   76,   76,    0,    0,
    0,    0,  102,   77,    0,   21,   22,   23,   77,    0,
    0,   77,    0,   77,   77,   77,    8,    9,   42,   43,
   44,   45,   24,    0,   81,    0,    0,   25,   76,   77,
   77,   77,   77,    0,    0,    0,    0,    0,   78,    0,
  135,  102,    0,   78,    0,  102,   78,   91,   78,   78,
   78,    0,    6,    0,    7,    8,    9,   10,   11,   76,
   12,   13,    0,   77,   78,   78,   78,   78,   26,    0,
   30,  126,    0,   82,    0,   28,   62,   62,   82,    0,
    0,   82,    0,  102,   82,  161,   62,    0,    0,    0,
   62,   62,   62,   29,   77,    0,    0,    0,   78,   82,
   82,   82,   82,    0,    0,   21,   22,   23,    0,    0,
    0,    0,    0,    0,    0,   10,   11,    0,   12,    0,
    0,    0,   24,    0,    0,   80,   80,   25,    0,   78,
  141,  142,  143,   82,    0,   80,   80,    0,   80,   80,
   80,   80,    0,   80,   80,    0,    0,    0,    0,   80,
   80,   80,    0,    0,    0,    0,   27,    0,    0,    0,
    0,    0,   81,   81,   82,    0,    0,    0,    0,    0,
    0,    0,   81,   81,   83,   81,   81,   81,   81,   83,
   81,   81,   83,    0,    0,   83,   81,   81,   81,    0,
    0,    0,    0,    0,    0,    0,    0,   76,   76,    0,
   83,   83,   83,   83,    0,    0,    0,   76,   76,   85,
   76,   76,   76,   76,   85,   76,   76,   85,    0,    0,
   85,   76,   76,   76,    0,    0,    0,    0,    0,    0,
    0,    0,   77,   77,   83,   85,   85,   85,   85,    0,
    0,    0,   77,   77,   84,   77,   77,   77,   77,   84,
   77,   77,   84,    0,    0,   84,   77,   77,   77,    0,
    0,    0,    0,    0,    0,   83,    0,   78,   78,   85,
   84,   84,   84,   84,    0,    0,    0,   78,   78,    0,
   78,   78,   78,   78,    0,   78,   78,   21,   22,   23,
    0,   78,   78,   78,    0,    0,    0,    0,    0,    0,
   85,    0,   82,   82,   84,    0,    0,    0,    0,    0,
    0,    0,   82,   82,    0,   82,   82,   82,   82,    0,
   82,   82,    0,    0,    0,    0,   82,   82,   82,   90,
    0,    0,    0,   86,   75,   84,   88,    0,   84,   82,
   68,   83,    0,   85,   68,   68,    0,   68,    0,   68,
   68,    0,   68,    0,   68,   89,   78,   77,   79,    0,
    0,    0,    0,    0,    0,    0,   68,   68,   68,   68,
   86,    0,   55,    0,    0,   86,    0,    0,   86,    0,
    0,   86,    0,   86,   75,    0,   88,    0,   84,   82,
   87,   83,    0,   85,    0,    0,   86,    0,   86,    0,
    0,   68,    0,   83,   83,    0,   78,   77,   79,    0,
    0,    0,    0,   83,   83,    0,   83,   83,   83,   83,
   74,   83,   83,    0,    0,    0,    0,   83,   83,   83,
   86,   68,    0,    0,    0,    0,    0,    0,   85,   85,
   87,    0,    0,   26,    0,   30,    0,    0,   85,   85,
   28,   85,   85,   85,   85,    0,   85,   85,    0,    0,
    0,   86,   85,   85,   85,    0,    0,   87,   29,    0,
   74,    0,   87,   84,   84,   87,    0,    0,   87,    0,
    0,    0,    0,   84,   84,    0,   84,   84,   84,   84,
    0,   84,   84,   87,    0,   87,    0,   84,   84,   84,
   86,   75,    0,   88,    0,   84,   82,    0,   83,    0,
   85,   86,   75,    0,   88,  107,   84,   82,    0,   83,
    0,   85,    0,   78,   77,   79,    0,   87,    0,    0,
    0,   27,    0,    0,   78,   77,   79,   26,    0,   30,
   86,   75,    0,   88,   28,   84,   82,    0,   83,    0,
   85,    0,    0,    0,    0,    0,    0,   87,   87,    0,
    0,    0,   29,   78,   77,   79,    0,    0,   87,    0,
    0,    0,    0,    0,    0,   55,   55,    0,    0,    0,
    0,    0,   76,   80,   81,   55,    0,   74,    0,   55,
   55,   55,    0,   68,   68,   68,  148,   87,   74,   86,
   86,    0,    0,    0,    0,    0,    0,    0,    0,   86,
   86,    0,   86,   86,   86,   86,    0,   86,   86,    0,
    0,  105,    0,   86,    0,   27,    0,   74,    0,    0,
    0,    0,   76,   80,   81,   86,   75,    0,   88,    0,
   84,   82,    0,   83,    0,   85,   86,   75,    0,   88,
    0,   84,   82,    0,   83,    0,   85,  149,   78,   77,
   79,    0,   21,   22,   23,    0,    0,    0,    0,   78,
   77,   79,   10,   11,    0,   12,    0,   86,   75,   24,
   88,    0,   84,   82,   25,   83,    0,   85,    0,    0,
    0,    0,   87,    0,    0,    0,   87,   87,    0,    0,
   78,   77,   79,   87,    0,    0,   87,   87,    0,   87,
   87,   87,   87,    0,   87,   87,   26,    0,   30,    0,
   87,   86,   74,   28,   88,    0,   84,   82,    0,   83,
    0,   85,    0,   74,   87,    0,    0,    0,    0,    0,
    0,   29,    0,  106,   78,   77,   79,    0,    0,   76,
   80,   81,    0,    0,    0,   90,   21,   22,   23,    0,
   76,   80,   81,   90,   74,    0,   90,    0,    0,   86,
   75,    0,   88,    0,   84,   82,    0,   83,   87,   85,
    0,   90,    0,    0,    0,    0,    0,    0,    0,   76,
   80,   81,   78,   77,   79,   86,   75,    0,   88,    0,
   84,   82,    0,   83,   27,   85,   86,   75,   37,   88,
    0,   84,   82,    0,   83,   90,   85,    0,   78,   77,
   79,    0,    0,    0,    0,    0,   87,    0,    0,   78,
   77,   79,   91,    0,    0,   37,    0,   91,   37,    0,
   91,    0,    0,   91,    0,    0,   90,    0,    0,    0,
    0,    0,   87,    0,   89,   37,   74,    0,   91,   89,
    0,    0,   89,   87,    0,   89,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   89,    0,   74,   88,   76,   80,   81,    0,    0,    0,
  169,   88,   91,   34,   88,   76,   80,   81,    0,    0,
   52,    0,    0,    0,   56,    0,    0,   37,    0,   88,
    0,    0,    0,    0,   89,  181,    0,    0,    0,    0,
   68,    0,    0,   91,    0,    0,   76,   80,   81,    0,
    0,    0,   37,    0,    0,   21,   22,   23,    0,    0,
   34,    0,   99,   88,    0,   89,    0,    0,   37,    0,
    0,    0,   24,    0,    0,   37,    0,   25,    0,    0,
  141,  142,  143,    0,    0,   37,    0,    0,    0,    0,
   76,   80,   81,    0,    0,    0,    0,    0,   37,    0,
  133,    0,    0,   37,   90,   90,    0,    0,   37,    0,
    0,    0,    0,    0,   90,   90,    0,   90,   90,   90,
   90,    0,   90,   90,    0,  183,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   34,   76,   80,
   81,  133,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   68,    0,  172,    0,   76,   80,   81,    0,    0,    0,
    0,    0,    0,    0,    0,   76,   80,   81,    0,    0,
    0,   91,   91,    0,    0,    0,    0,    0,    0,    0,
    0,   91,   91,    0,   91,   91,   91,   91,    0,   91,
   91,    0,    0,   89,   89,   60,   61,   62,   63,   64,
    0,   65,    0,   89,   89,    0,   89,   89,   89,   89,
    0,   89,   89,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   88,   88,    0,    0,    0,    0,    0,    0,
    0,    0,   88,   88,    0,   88,   88,   88,   88,    0,
   88,   88,  109,  110,  111,  112,  113,  114,  115,  116,
  117,  118,  119,  120,  121,  122,  123,  124,  125,  127,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  147,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  162,    0,    0,    0,    0,    0,
    0,    0,  170,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  175,    0,    0,    0,    0,
  179,
};
static const YYINT yycheck[] = {                         33,
   35,   59,   91,   37,   38,   44,   40,   41,   42,   43,
   44,   45,   59,   47,   59,   36,   40,  257,   59,  259,
   59,  258,  132,  258,  134,   59,   60,   61,   62,   57,
  258,   37,  285,   59,   40,   33,   42,  260,  261,   37,
   38,   47,   40,   41,   42,   43,   44,   45,  158,   47,
   96,  263,  267,  268,  100,  270,   91,   59,  257,   93,
   94,   59,   60,   61,   62,   59,    6,  258,   96,   59,
   94,   33,  100,   59,   41,   37,   38,   44,   40,   41,
   42,   43,   44,   45,   41,   47,   91,   44,   94,   59,
  124,   59,  138,   33,   40,   93,   94,   59,   60,   61,
   62,  263,  264,  265,  266,  267,  268,   33,  270,  271,
  138,   37,   38,   53,  285,   41,   42,   43,   44,   45,
   41,   47,  285,   44,   59,  146,  124,  267,  268,  269,
  270,   93,   94,   59,   60,   61,   62,  258,  264,  265,
  266,  267,  268,   33,  270,  271,  263,   37,   38,  285,
   44,   41,   42,   43,   44,   45,  278,   47,  267,  268,
   93,  270,  124,  272,  273,  278,  272,   93,   94,   59,
   60,   61,   62,   37,  278,  263,   40,  263,   42,   43,
   33,   45,  272,   47,   37,   38,    2,   54,   41,   42,
   43,   44,   45,   53,   47,   33,  285,   47,  124,  276,
  277,  278,  130,   93,   94,  263,   59,   60,   61,   62,
   37,    7,  134,   40,  146,   42,   43,  262,   45,  167,
   47,  262,  263,  262,  263,  272,  273,   -1,  262,  263,
   94,   -1,   -1,   60,  124,   62,  262,  263,  272,  273,
   93,  275,  276,  277,  278,   -1,  280,  281,   -1,   -1,
  285,   -1,  286,  287,  288,   -1,   38,   -1,   40,   -1,
  262,  263,   -1,   45,  262,  263,   -1,   94,  262,  263,
   -1,  124,  262,  263,  272,  273,  130,  275,  276,  277,
  278,   63,  280,  281,  276,  277,  278,   -1,  286,  287,
  288,   -1,  262,  263,  262,  263,  276,  277,  278,  153,
  262,  263,  272,   -1,   -1,   -1,  276,  277,  278,  163,
  272,  273,   -1,  275,  276,  277,  278,   -1,  280,  281,
   -1,   -1,  176,   -1,  286,  287,  288,  181,   -1,   -1,
  267,  268,  186,  270,  271,   -1,  262,  263,   -1,   -1,
   -1,   -1,   -1,   59,  126,   -1,  272,  273,   -1,  275,
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
   45,   -1,   47,   -1,   39,   -1,   41,  124,   -1,   -1,
  287,  288,   -1,   93,   59,   60,   61,   62,   -1,   -1,
   -1,   -1,   57,   33,   -1,  257,  258,  259,   38,   -1,
   -1,   41,   -1,   43,   44,   45,  265,  266,  267,  268,
  269,  270,  274,   -1,  124,   -1,   -1,  279,   93,   59,
   60,   61,   62,   -1,   -1,   -1,   -1,   -1,   33,   -1,
   95,   96,   -1,   38,   -1,  100,   41,  102,   43,   44,
   45,   -1,  262,   -1,  264,  265,  266,  267,  268,  124,
  270,  271,   -1,   93,   59,   60,   61,   62,   38,   -1,
   40,   41,   -1,   33,   -1,   45,  262,  263,   38,   -1,
   -1,   41,   -1,  138,   44,  140,  272,   -1,   -1,   -1,
  276,  277,  278,   63,  124,   -1,   -1,   -1,   93,   59,
   60,   61,   62,   -1,   -1,  257,  258,  259,   -1,   -1,
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
   42,   43,   -1,   45,  126,   47,   37,   38,    6,   40,
   -1,   42,   43,   -1,   45,   93,   47,   -1,   60,   61,
   62,   -1,   -1,   -1,   -1,   -1,   94,   -1,   -1,   60,
   61,   62,   33,   -1,   -1,   33,   -1,   38,   36,   -1,
   41,   -1,   -1,   44,   -1,   -1,  124,   -1,   -1,   -1,
   -1,   -1,   94,   -1,   33,   53,  124,   -1,   59,   38,
   -1,   -1,   41,   94,   -1,   44,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   59,   -1,  124,   33,  286,  287,  288,   -1,   -1,   -1,
  281,   41,   93,    6,   44,  286,  287,  288,   -1,   -1,
   13,   -1,   -1,   -1,   17,   -1,   -1,  105,   -1,   59,
   -1,   -1,   -1,   -1,   93,  275,   -1,   -1,   -1,   -1,
   33,   -1,   -1,  124,   -1,   -1,  286,  287,  288,   -1,
   -1,   -1,  130,   -1,   -1,  257,  258,  259,   -1,   -1,
   53,   -1,   55,   93,   -1,  124,   -1,   -1,  146,   -1,
   -1,   -1,  274,   -1,   -1,  153,   -1,  279,   -1,   -1,
  282,  283,  284,   -1,   -1,  163,   -1,   -1,   -1,   -1,
  286,  287,  288,   -1,   -1,   -1,   -1,   -1,  176,   -1,
   93,   -1,   -1,  181,  262,  263,   -1,   -1,  186,   -1,
   -1,   -1,   -1,   -1,  272,  273,   -1,  275,  276,  277,
  278,   -1,  280,  281,   -1,  273,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  130,  286,  287,
  288,  134,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  153,   -1,  155,   -1,  286,  287,  288,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  286,  287,  288,   -1,   -1,
   -1,  262,  263,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  272,  273,   -1,  275,  276,  277,  278,   -1,  280,
  281,   -1,   -1,  262,  263,   24,   25,   26,   27,   28,
   -1,   30,   -1,  272,  273,   -1,  275,  276,  277,  278,
   -1,  280,  281,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  262,  263,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  272,  273,   -1,  275,  276,  277,  278,   -1,
  280,  281,   71,   72,   73,   74,   75,   76,   77,   78,
   79,   80,   81,   82,   83,   84,   85,   86,   87,   88,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  106,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  143,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  151,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  164,   -1,   -1,   -1,   -1,
  169,
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
"var : STRING ID",
"var : NUMBER ID",
"var : ARRAY ID '[' integer ']'",
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
#line 210 "gram.y"

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
	if (t1 == 3 && t2 == 1) return 0; /* array := int */
	if (t1 == 1 && t2 == 3) return 0; /* int := array */
	if (t1 == 2 && t2 == 11) return 0; /* string := int* */
	if (t1 == 2 && arg2->attrib == INTEGER && arg2->value.i == 0)
		return 0; /* string := 0 */
	if (t1 > 10 && t1 < 20 && arg2->attrib == INTEGER && arg2->value.i == 0)
		return 0; /* pointer := 0 */
	return 1;
}

void declare(Node *pub, int cnst, Node *type, char *name, Node *value)
{
  int typ;
  if (!value) {
    if (pub) {
        if (pub->info == 1 && cnst) {
            yyerror("local constants must be initialised");
        }
    }
    return;
  }
  if (value->attrib = INTEGER && value->value.i == 0 && type->value.i > 10)
  	return; /* NULL pointer */
  if ((typ = value->info) % 10 > 5) typ -= 5;
  if (type->info != typ)
    yyerror("wrong types in initialization");

}
#line 805 "y.tab.c"

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
#line 49 "gram.y"
	{ printNode(yystack.l_mark[0].n,0,yynames); }
break;
case 2:
#line 50 "gram.y"
	{ printNode(yystack.l_mark[0].n,0,yynames); }
break;
case 3:
#line 53 "gram.y"
	{ yyval.n = binNode(PROGRAM, yystack.l_mark[-3].n, yystack.l_mark[-1].n); }
break;
case 4:
#line 54 "gram.y"
	{ yyval.n = uniNode(PROGRAM, yystack.l_mark[-1].n); }
break;
case 5:
#line 57 "gram.y"
	{ yyval.n = uniNode(MODULE, yystack.l_mark[-1].n); }
break;
case 6:
#line 58 "gram.y"
	{ yyval.n = nilNode(MODULE); }
break;
case 7:
#line 61 "gram.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 8:
#line 62 "gram.y"
	{ yyval.n = binNode(DECLS, yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 9:
#line 65 "gram.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 10:
#line 66 "gram.y"
	{ IDnew(yystack.l_mark[-2].n->value.i+5, RIGHT_CHILD(yystack.l_mark[-2].n)->value.s, 0); declare(yystack.l_mark[-4].n, 1, yystack.l_mark[-2].n, RIGHT_CHILD(yystack.l_mark[-2].n)->value.s, yystack.l_mark[0].n); yyval.n = binNode(QUALIFIER, yystack.l_mark[-4].n, binNode(VAR, yystack.l_mark[-2].n, yystack.l_mark[0].n)); }
break;
case 11:
#line 67 "gram.y"
	{ IDnew(yystack.l_mark[-2].n->value.i, RIGHT_CHILD(yystack.l_mark[-2].n)->value.s, 0); declare(yystack.l_mark[-3].n, 0, yystack.l_mark[-2].n, RIGHT_CHILD(yystack.l_mark[-2].n)->value.s, yystack.l_mark[0].n); yyval.n = binNode(QUALIFIER, yystack.l_mark[-3].n, binNode(VAR, yystack.l_mark[-2].n, yystack.l_mark[0].n)); }
break;
case 12:
#line 68 "gram.y"
	{ IDnew(yystack.l_mark[0].n->value.i, RIGHT_CHILD(yystack.l_mark[0].n)->value.s, 0); declare(yystack.l_mark[-1].n, 0, yystack.l_mark[0].n, RIGHT_CHILD(yystack.l_mark[0].n)->value.s, 0); yyval.n = binNode(DECL, yystack.l_mark[-1].n, yystack.l_mark[0].n); }
break;
case 13:
#line 69 "gram.y"
	{ IDnew(yystack.l_mark[0].n->value.i+5, RIGHT_CHILD(yystack.l_mark[0].n)->value.s, 0); declare(yystack.l_mark[-2].n, 1, yystack.l_mark[0].n, RIGHT_CHILD(yystack.l_mark[0].n)->value.s, 0); yyval.n = binNode(DECL, yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 14:
#line 70 "gram.y"
	{ IDnew(yystack.l_mark[0].n->value.i+5, RIGHT_CHILD(yystack.l_mark[0].n)->value.s, 0); declare(0, 1, yystack.l_mark[0].n, RIGHT_CHILD(yystack.l_mark[0].n)->value.s, 0); yyval.n = yystack.l_mark[0].n; }
break;
case 15:
#line 71 "gram.y"
	{ IDnew(yystack.l_mark[-2].n->value.i+5, RIGHT_CHILD(yystack.l_mark[-2].n)->value.s, 0); declare(0, 1, yystack.l_mark[-2].n, RIGHT_CHILD(yystack.l_mark[-2].n)->value.s, yystack.l_mark[0].n); yyval.n = binNode(DECL, yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 16:
#line 72 "gram.y"
	{ IDnew(yystack.l_mark[0].n->value.i, RIGHT_CHILD(yystack.l_mark[0].n)->value.s, 0); declare(0, 0, yystack.l_mark[0].n, RIGHT_CHILD(yystack.l_mark[0].n)->value.s, 0); yyval.n = yystack.l_mark[0].n; }
break;
case 17:
#line 73 "gram.y"
	{ IDnew(yystack.l_mark[-2].n->value.i, RIGHT_CHILD(yystack.l_mark[-2].n)->value.s, 0); declare(0, 0, yystack.l_mark[-2].n, RIGHT_CHILD(yystack.l_mark[-2].n)->value.s, yystack.l_mark[0].n); yyval.n = binNode(DECL, yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 18:
#line 76 "gram.y"
	{ yyval.n = binNode(QUALIFIER, yystack.l_mark[-4].n, binNode(FUNCTYPE, yystack.l_mark[-3].n, binNode(ID, strNode(ID, yystack.l_mark[-2].s), binNode(VARS, yystack.l_mark[-1].n, uniNode(END, yystack.l_mark[0].n))))); }
break;
case 19:
#line 77 "gram.y"
	{ yyval.n = binNode(FUNCTYPE, yystack.l_mark[-3].n, binNode(ID, strNode(ID, yystack.l_mark[-2].s), binNode(VARS, yystack.l_mark[-1].n, uniNode(END, yystack.l_mark[0].n)))); }
break;
case 20:
#line 78 "gram.y"
	{ yyval.n = binNode(QUALIFIER, yystack.l_mark[-3].n, binNode(FUNCTYPE, yystack.l_mark[-2].n, binNode(ID, strNode(ID, yystack.l_mark[-1].s), uniNode(END, yystack.l_mark[0].n)))); }
break;
case 21:
#line 79 "gram.y"
	{ yyval.n = binNode(FUNCTYPE, yystack.l_mark[-2].n, binNode(ID, strNode(ID, yystack.l_mark[-1].s), uniNode(END, yystack.l_mark[0].n))); }
break;
case 22:
#line 82 "gram.y"
	{ yyval.n = nilNode(DONE); }
break;
case 23:
#line 83 "gram.y"
	{ yyval.n = uniNode(DO, yystack.l_mark[0].n); }
break;
case 24:
#line 86 "gram.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 25:
#line 87 "gram.y"
	{ yyval.n = nilNode(VOID); }
break;
case 26:
#line 90 "gram.y"
	{ yyval.n = nilNode(PUBLIC); yyval.n->info = 1; }
break;
case 27:
#line 91 "gram.y"
	{ yyval.n = nilNode(FORWARD); yyval.n->info = 2; }
break;
case 28:
#line 94 "gram.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 29:
#line 95 "gram.y"
	{ yyval.n = binNode(VARS, yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 30:
#line 98 "gram.y"
	{ yyval.n = binNode(VAR, uniNode(STRING, nilNode(STRING)), strNode(ID, yystack.l_mark[0].s)); yyval.n->info = 2; }
break;
case 31:
#line 99 "gram.y"
	{ yyval.n = binNode(VAR, uniNode(NUMBER, nilNode(NUMBER)), strNode(ID, yystack.l_mark[0].s)); yyval.n->info = 1; }
break;
case 32:
#line 100 "gram.y"
	{ yyval.n = binNode(VAR, uniNode(ARRAY, nilNode(ARRAY)), strNode(ID, yystack.l_mark[-3].s)); yyval.n->info = 3; }
break;
case 33:
#line 103 "gram.y"
	{ yyval.n = nilNode(NUMBER); }
break;
case 34:
#line 104 "gram.y"
	{ yyval.n = nilNode(ARRAY); }
break;
case 35:
#line 105 "gram.y"
	{ yyval.n = nilNode(STRING); }
break;
case 36:
#line 108 "gram.y"
	{ yyval.n = binNode(BODY, yystack.l_mark[-1].n, yystack.l_mark[0].n); }
break;
case 37:
#line 109 "gram.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 38:
#line 112 "gram.y"
	{ yyval.n = binNode(BODY, yystack.l_mark[-1].n, yystack.l_mark[0].n); }
break;
case 39:
#line 113 "gram.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 40:
#line 116 "gram.y"
	{ yyval.n = nilNode(NIL); }
break;
case 41:
#line 117 "gram.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 42:
#line 120 "gram.y"
	{ yyval.n = yystack.l_mark[-1].n; }
break;
case 43:
#line 121 "gram.y"
	{ yyval.n = binNode(BODYVARS, yystack.l_mark[-2].n, yystack.l_mark[-1].n); }
break;
case 44:
#line 124 "gram.y"
	{ yyval.n = binNode(IF, yystack.l_mark[-3].n, yystack.l_mark[-1].n); }
break;
case 45:
#line 125 "gram.y"
	{ yyval.n = binNode(IF, yystack.l_mark[-6].n, binNode(THEN, yystack.l_mark[-4].n, binNode(ELIF, yystack.l_mark[-3].n, uniNode(ELSE, yystack.l_mark[-1].n)))); }
break;
case 46:
#line 126 "gram.y"
	{ yyval.n = binNode(IF, yystack.l_mark[-4].n, binNode(THEN, yystack.l_mark[-2].n, uniNode(ELIF, yystack.l_mark[-1].n))); }
break;
case 47:
#line 127 "gram.y"
	{ yyval.n = binNode(IF, yystack.l_mark[-5].n, binNode(THEN, yystack.l_mark[-3].n, uniNode(ELSE, yystack.l_mark[-1].n))); }
break;
case 48:
#line 128 "gram.y"
	{ ncicl++; }
break;
case 49:
#line 128 "gram.y"
	{ yyval.n = binNode(FOR, yystack.l_mark[-8].n, binNode(UNTIL, yystack.l_mark[-6].n, binNode(STEP, yystack.l_mark[-4].n, uniNode(DO, yystack.l_mark[-2].n)))); ncicl--; }
break;
case 50:
#line 129 "gram.y"
	{ yyval.n = yystack.l_mark[-1].n; }
break;
case 51:
#line 130 "gram.y"
	{ yyval.n = yystack.l_mark[-1].n; }
break;
case 52:
#line 131 "gram.y"
	{ yyval.n = binNode('#', yystack.l_mark[-3].n, yystack.l_mark[-1].n); }
break;
case 53:
#line 134 "gram.y"
	{ yyval.n = nilNode(REPEAT); if (ncicl <= 0) yyerror("invalid repeat argument"); }
break;
case 54:
#line 135 "gram.y"
	{ yyval.n = nilNode(STOP); if (ncicl <= 0) yyerror("invalid stop argument"); }
break;
case 55:
#line 136 "gram.y"
	{ yyval.n = uniNode(RETURN_EXPR, yystack.l_mark[0].n); }
break;
case 56:
#line 137 "gram.y"
	{ yyval.n = nilNode(RETURN); }
break;
case 57:
#line 140 "gram.y"
	{ yyval.n = binNode(ELIF, yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 58:
#line 143 "gram.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 59:
#line 144 "gram.y"
	{ yyval.n = binNode(ELIFS, yystack.l_mark[-1].n, yystack.l_mark[0].n); }
break;
case 60:
#line 147 "gram.y"
	{ yyval.n = nilNode(NIL); }
break;
case 61:
#line 148 "gram.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 62:
#line 149 "gram.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 63:
#line 150 "gram.y"
	{ yyval.n = binNode(INSTRS_INSTRTERM, yystack.l_mark[-1].n, yystack.l_mark[0].n); }
break;
case 64:
#line 153 "gram.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 65:
#line 154 "gram.y"
	{ yyval.n = binNode(INSTRS, yystack.l_mark[-1].n, yystack.l_mark[0].n); }
break;
case 66:
#line 157 "gram.y"
	{ yyval.n = strNode(ID, yystack.l_mark[0].s); }
break;
case 67:
#line 158 "gram.y"
	{ yyval.n = binNode('[', yystack.l_mark[-3].n, yystack.l_mark[-1].n); }
break;
case 68:
#line 161 "gram.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 69:
#line 162 "gram.y"
	{ yyval.n = yystack.l_mark[-1].n; }
break;
case 70:
#line 163 "gram.y"
	{ yyval.n = binNode('(', yystack.l_mark[-3].n, yystack.l_mark[-1].n); }
break;
case 71:
#line 164 "gram.y"
	{ yyval.n = yystack.l_mark[-2].n; }
break;
case 72:
#line 165 "gram.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 73:
#line 166 "gram.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 74:
#line 167 "gram.y"
	{ yyval.n = uniNode(UMINUS, yystack.l_mark[0].n); }
break;
case 75:
#line 168 "gram.y"
	{ yyval.n = uniNode(ADDR, yystack.l_mark[0].n); }
break;
case 76:
#line 169 "gram.y"
	{ yyval.n = binNode('^', yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 77:
#line 170 "gram.y"
	{ yyval.n = binNode('+', yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 78:
#line 171 "gram.y"
	{ yyval.n = binNode('-', yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 79:
#line 172 "gram.y"
	{ yyval.n = binNode('*', yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 80:
#line 173 "gram.y"
	{ yyval.n = binNode('/', yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 81:
#line 174 "gram.y"
	{ yyval.n = binNode('%', yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 82:
#line 175 "gram.y"
	{ yyval.n = binNode('<', yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 83:
#line 176 "gram.y"
	{ yyval.n = binNode('>', yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 84:
#line 177 "gram.y"
	{ yyval.n = binNode(GE, yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 85:
#line 178 "gram.y"
	{ yyval.n = binNode(LE, yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 86:
#line 179 "gram.y"
	{ yyval.n = binNode(NE, yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 87:
#line 180 "gram.y"
	{ yyval.n = binNode('=', yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 88:
#line 181 "gram.y"
	{ yyval.n = binNode(ATTR, yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 89:
#line 182 "gram.y"
	{ yyval.n = binNode('&', yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 90:
#line 183 "gram.y"
	{ yyval.n = binNode('|', yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 91:
#line 184 "gram.y"
	{ yyval.n = uniNode('~', yystack.l_mark[0].n); }
break;
case 92:
#line 185 "gram.y"
	{ yyval.n = nilNode('?'); }
break;
case 93:
#line 188 "gram.y"
	{ yyval.n = yystack.l_mark[0].n; yyval.n->info = yystack.l_mark[0].n->info; }
break;
case 94:
#line 189 "gram.y"
	{ yyval.n = yystack.l_mark[0].n; yyval.n->info = yystack.l_mark[0].n->info; }
break;
case 95:
#line 192 "gram.y"
	{ yyval.n = intNode(INTEGER, yystack.l_mark[0].i); yyval.n->info = 1; }
break;
case 96:
#line 195 "gram.y"
	{ yyval.n = yystack.l_mark[0].n; yyval.n->info = yystack.l_mark[0].n->info; }
break;
case 97:
#line 196 "gram.y"
	{ yyval.n = strNode(STR, yystack.l_mark[0].s); yyval.n->info = 2; }
break;
case 98:
#line 199 "gram.y"
	{ yyval.n = binNode(TWO_INTEGERS, yystack.l_mark[-1].n, yystack.l_mark[0].n); yyval.n->info = 2; }
break;
case 99:
#line 200 "gram.y"
	{ yyval.n = binNode(MORE_INTEGERS, yystack.l_mark[-1].n, yystack.l_mark[0].n); yyval.n->info = 2; }
break;
case 100:
#line 202 "gram.y"
	{ yyval.n = yystack.l_mark[0].n; yyval.n->info = yystack.l_mark[0].n->info; }
break;
case 101:
#line 203 "gram.y"
	{ yyval.n = binNode(',', yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = 3; }
break;
case 102:
#line 206 "gram.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 103:
#line 207 "gram.y"
	{ yyval.n = binNode(ARGS, yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
#line 1419 "y.tab.c"
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
