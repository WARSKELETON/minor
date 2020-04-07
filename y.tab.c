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
    6,   10,   10,   10,   10,    7,   14,   14,   12,   12,
    8,    8,    8,   13,   13,   16,   16,    9,   15,   15,
   15,    4,    4,   18,   17,   17,   20,   20,   20,   20,
   20,   20,   20,   20,   24,   24,   24,   24,   25,   22,
   22,   19,   19,   19,   19,   26,   26,   23,   23,   23,
   21,   21,   21,   21,   21,   21,   21,   21,   21,   21,
   21,   21,   21,   21,   21,   21,   21,   21,   21,   21,
   21,   21,   21,   21,   21,   11,   11,   28,   28,   27,
   27,
};
static const YYINT yylen[] = {                            2,
    1,    1,    5,    3,    0,    1,    1,    3,    1,    4,
    3,    0,    2,    3,    5,    6,    1,    2,    1,    1,
    0,    1,    1,    0,    1,    1,    3,    2,    1,    1,
    1,    2,    1,    1,    2,    3,    5,    8,    6,    7,
    9,    2,    2,    4,    1,    1,    2,    1,    4,    1,
    2,    0,    1,    1,    2,    1,    2,    1,    4,    2,
    1,    3,    4,    3,    1,    1,    2,    2,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    2,    1,    1,    1,    1,    3,    1,
    3,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,    1,    2,    0,   22,   23,    0,    0,
    7,    9,    0,    0,    0,    0,    0,   29,   30,   31,
    0,    0,    0,    4,   20,    0,   19,   66,   58,   65,
    0,    0,   45,   46,    0,    0,    0,    0,    0,   85,
    0,    0,    0,    0,   33,   34,   56,    0,    0,   53,
    0,    8,    0,    0,    0,   11,   28,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    3,   35,    0,
   32,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   42,   43,    0,    0,
    0,   57,   55,   10,   88,   86,   13,    0,    0,   26,
    0,    0,    0,    0,   62,   36,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   64,    0,    0,    0,    0,    0,    0,    0,   17,    0,
   16,    0,    0,    0,   63,    0,   59,   44,   89,    0,
   18,   27,    0,    0,   37,    0,   50,    0,    0,   15,
    0,    0,    0,   39,   51,    0,   40,    0,    0,    0,
   49,   38,    0,   41,
};
static const YYINT yydgoto[] = {                          3,
    4,    5,    9,   42,   10,   11,   12,   13,   43,   56,
   97,   26,  101,  131,   23,  102,   44,   45,   46,   47,
   48,  146,   60,   50,  147,   51,  123,   98,
};
static const YYINT yysindex[] = {                      -207,
  -99,  -99,    0,    0,    0, -151,    0,    0, -247,  -28,
    0,    0, -197, -224, -139, 1298,  -99,    0,    0,    0,
 -251,  -88, -183,    0,    0, -173,    0,    0,    0,    0,
  219,  219,    0,    0,  219,  219,  219,  219,  -36,    0,
  219, -171,   35, 1298,    0,    0,    0,  767,  -34,    0,
 1208,    0,  -88, -234, -153,    0,    0, -251,  817,  -73,
  481, 1134,   67, 1143,   67,   18,  932,    0,    0,   52,
    0,  219,  219,  219,  219,  219,  219,  219,  219,  219,
  219,  219,  219,  219,  219,  101,    0,    0,  219,  219,
  219,    0,    0,    0,    0,    0,    0,   77,   30,    0,
 -204,   79, 1208,  219,    0,    0,  980, 1143,  174,  174,
  137,  137,  137,  137,   -5,   -5,  -27,  -27,  -27,  -27,
    0, 1134,  -20, 1134,  943,  969, -117, -140,    0, 1298,
    0, -251,  -76, 1069,    0,  219,    0,    0,    0, -234,
    0,    0, 1208,  219,    0,    9,    0,  219, 1134,    0,
 -131, 1097, 1208,    0,    0, 1108,    0, 1208, -121, 1208,
    0,    0,  -94,    0,
};
static const YYINT yyrindex[] = {                         0,
   61, -212,    0,    0,    0, -108,    0,    0,    0, -137,
    0,    0,    0,    0,    0,  -80, -165,    0,    0,    0,
    0,  -39,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   31,    0,    0,    0,    0,    0,
    0,    0,    0,  -37,    0,    0,    0,    0,  778,    0,
  284,    0,  -39,    0,    0,    0,    0, -122,    0,    3,
    0,  305,   39, 1200,   75,  -33,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  -25,    0,    0,
    0,  -97,   19,    0,    0,    0, 1028, 1236,  682,  808,
  476,  511,  612,  647,  406,  441,  111,  148,  334,  371,
    0,  -11,    0, 1266,    0,    0,    0,    7,    0,  -37,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  -91,    0,    0,    0,    0,    0,    8,    0,
    0,    0,  -91,    0,    0,    0,    0,   19,    0,  -84,
    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
    0,    0,  192,   73,    0,  179,    0,  199,   66,  153,
   78,    0,    0,    0,  198,    0,    0,  171,  -65,  169,
 1538,    0, 1057,  177,   86,    0,    0,    0,
};
#define YYTABLESIZE 1686
static const YYINT yytable[] = {                         60,
   91,   60,   55,   60,   60,   39,   60,   60,   60,   60,
   60,   60,   86,   60,   16,   18,   19,   90,   20,   12,
  135,   52,   95,  136,   96,   60,   60,   60,   60,   90,
   17,   84,   90,   87,   86,   61,   82,  133,   24,   61,
   61,   83,   61,   61,   61,   61,   61,   61,   91,   61,
    5,   91,    1,    2,   21,   21,   90,   21,   21,   60,
   60,   61,   61,   61,   61,   14,   85,  129,  130,   18,
   19,   68,   20,   21,   57,   68,   68,  151,   22,   68,
   68,   68,   68,   68,   58,   68,   53,  159,   85,   48,
   60,   68,  161,   69,  163,   61,   61,   68,   68,   68,
   68,   21,   21,   99,   21,   21,   86,   67,   90,   70,
  106,   67,   67,    7,    8,   67,   67,   67,   67,   67,
  127,   67,  128,  100,    6,    6,   61,   18,   19,   25,
   20,   68,   68,   67,   67,   67,   67,  132,   36,  139,
   41,  121,   39,   72,  140,   38,  157,   72,   72,   24,
   24,   72,   72,   72,   72,   72,  162,   72,   21,   21,
   21,   21,   68,   40,    6,    7,    8,   67,   67,   72,
   72,   72,   72,   84,   25,   25,   86,  164,   82,   80,
   73,   81,   52,   83,   73,   73,   52,   52,   73,   73,
   73,   73,   73,   14,   73,   52,   54,  142,   67,  143,
  144,  145,  141,   72,   15,   94,   73,   73,   73,   73,
   84,   89,   27,   86,   71,   82,   80,  150,   81,   92,
   83,   29,   12,   12,   52,   52,   37,   93,   60,   60,
   85,  155,    0,   76,   72,   77,   87,   87,   60,   60,
   73,   60,   60,   60,   60,    0,   60,   60,    0,    0,
   89,   60,   60,   60,   60,    0,   36,    0,   41,    0,
   39,    0,    0,   38,   61,   61,    0,   85,   14,   14,
    0,   73,    0,    0,   61,   61,    0,   61,   61,   61,
   61,   40,   61,   61,  153,  144,  154,    0,   61,   61,
   61,    0,   48,   48,   52,   52,   52,    0,    0,    0,
   68,   68,   48,    0,    0,    0,   48,   48,   48,    0,
   68,   68,    0,   68,   68,   68,   68,    0,   68,   68,
    0,    0,    5,    0,   68,   68,   68,   21,   21,    0,
   21,   21,    0,    0,    0,    0,   67,   67,    0,    0,
    0,    0,   54,    0,   37,    0,   67,   67,    0,   67,
   67,   67,   67,    0,   67,   67,    0,   28,   29,   30,
   67,   67,   67,   47,    0,    0,   74,    0,    0,    0,
   74,   74,   72,   72,   74,   74,   74,   74,   74,    0,
   74,    0,   72,   72,    0,   72,   72,   72,   72,    0,
   72,   72,   74,   74,   74,   74,   72,   72,   72,    0,
    0,    0,    0,   69,    0,    0,    0,   69,   69,   73,
   73,   69,   69,   69,   69,   69,    0,   69,    0,   73,
   73,    0,   73,   73,   73,   73,   74,   73,   73,   69,
   69,   69,   69,   73,   73,   73,    0,    0,   70,    0,
    0,    0,    0,   70,    0,    0,   70,    0,   70,   70,
   70,    0,    0,    0,    0,    0,    0,   74,    0,    0,
   78,   79,    0,   69,   70,   70,   70,   70,    0,    0,
    0,    0,    0,   71,    0,   28,   29,   30,   71,    0,
    0,   71,    0,   71,   71,   71,    0,    0,    0,    0,
    0,    0,    0,    0,   69,    0,    0,    0,   70,   71,
   71,   71,   71,    0,    0,    0,    0,    0,   75,    0,
    0,    0,    0,   75,    0,    0,   75,   84,   73,   75,
   86,    0,   82,   80,    0,   81,    0,   83,    0,   70,
    0,    0,    0,   71,   75,   75,   75,   75,    0,    0,
   76,   75,   77,   76,    0,   54,   54,    0,   76,    0,
    0,   76,    0,    0,   76,   54,    0,    0,    0,   54,
   54,   54,    0,    0,   71,    0,   47,   47,   75,   76,
   76,   76,   76,    0,   85,    0,   47,    0,    0,    0,
   47,   47,   47,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   74,   74,    0,    0,   75,
    0,    0,    0,   76,   72,   74,   74,    0,   74,   74,
   74,   74,    0,   74,   74,    0,    0,    0,    0,   74,
   74,   74,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   69,   69,   76,    0,    0,    0,    0,    0,
    0,    0,   69,   69,   78,   69,   69,   69,   69,   78,
   69,   69,   78,    0,    0,   78,   69,   69,   69,    0,
    0,    0,    0,    0,    0,    0,    0,   70,   70,    0,
   78,   78,   78,   78,    0,    0,    0,   70,   70,   77,
   70,   70,   70,   70,   77,   70,   70,   77,    0,    0,
   77,   70,   70,   70,    0,    0,    0,    0,    0,    0,
    0,    0,   71,   71,   78,   77,   77,   77,   77,    0,
    0,    0,   71,   71,   79,   71,   71,   71,   71,   79,
   71,   71,   79,    0,    0,   79,   71,   71,   71,    0,
    0,    0,    0,    0,    0,   78,    0,   75,   75,   77,
   79,    0,   79,    0,    0,    0,    0,   75,   75,    0,
   75,   75,   75,   75,    0,   75,   75,    0,    0,    0,
  104,   75,   75,   75,    0,    0,   74,   78,   79,    0,
   77,    0,   76,   76,   79,    0,    0,    0,    0,    0,
    0,    0,   76,   76,    0,   76,   76,   76,   76,    0,
   76,   76,    0,    0,    0,    0,   76,   76,   76,   88,
    0,    0,    0,   84,   73,   79,   86,    0,   82,   80,
   61,   81,    0,   83,   61,   61,    0,   61,    0,   61,
   61,    0,   61,    0,   61,   87,   76,   75,   77,    0,
    0,    0,    0,    0,    0,    0,   61,   61,   61,   61,
   80,    0,    0,    0,    0,   80,    0,    0,   80,    0,
    0,   80,    0,   84,   73,    0,   86,    0,   82,   80,
   85,   81,    0,   83,    0,    0,   80,    0,   80,    0,
    0,   61,    0,   78,   78,    0,   76,   75,   77,    0,
    0,    0,    0,   78,   78,    0,   78,   78,   78,   78,
   72,   78,   78,    0,    0,    0,    0,   78,   78,   78,
   80,   61,    0,    0,    0,    0,    0,    0,   77,   77,
   85,    0,    0,    0,    0,    0,    0,    0,   77,   77,
    0,   77,   77,   77,   77,    0,   77,   77,    0,    0,
    0,   80,   77,   77,   77,    0,    0,    0,    0,    0,
   72,    0,    0,   79,   79,    0,    0,    0,    0,    0,
    0,    0,    0,   79,   79,    0,   79,   79,   79,   79,
    0,   79,   79,    0,    0,    0,    0,   79,   84,   73,
    0,   86,  105,   82,   80,    0,   81,    0,   83,   84,
   73,    0,   86,    0,   82,   80,    0,   81,    0,   83,
    0,   76,   75,   77,    0,    0,    0,    0,    0,    0,
    0,    0,   76,   75,   77,   84,   73,    0,   86,    0,
   82,   80,    0,   81,    0,   83,   84,   73,    0,   86,
    0,   82,   80,    0,   81,   85,   83,  138,   76,   75,
   77,    0,    0,    0,    0,  137,   85,    0,    0,   76,
   75,   77,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   74,   78,   79,   72,    0,    0,    0,    0,
   83,    0,   85,   61,   61,   61,   72,    0,   83,   80,
   80,   83,   49,   85,    0,    0,    0,    0,    0,   80,
   80,    0,   80,   80,   80,   80,   83,   80,   80,    0,
    0,  103,   72,   80,    0,   66,    0,    0,    0,    0,
   49,    0,   74,   78,   79,   84,   73,   49,   86,    0,
   82,   80,    0,   81,    0,   83,    0,    0,    0,    0,
   83,    0,    0,    0,    0,    0,    0,    0,   76,   75,
   77,    0,    0,   84,   73,    0,   86,    0,   82,   80,
    0,   81,    0,   83,   84,   73,    0,   86,    0,   82,
   80,   83,   81,    0,   83,    0,   76,   75,   77,   49,
    0,    0,   85,    0,    0,    0,    0,   76,   75,   77,
   84,   73,    0,   86,    0,   82,   80,    0,   81,   84,
   83,    0,   86,    0,   82,   80,   49,   81,    0,   83,
   85,    0,   72,   76,   75,   77,    0,    0,    0,   49,
    0,   85,   76,   75,   77,    0,    0,    0,    0,   49,
    0,    0,    0,    0,   49,    0,   49,   74,   78,   79,
   72,    0,    0,    0,    0,    0,    0,   85,   74,   78,
   79,   72,   84,    0,    0,    0,   85,   84,    0,    0,
   84,    0,    0,   84,    0,   36,    0,   41,    0,   39,
    0,    0,   38,    0,   74,   78,   79,   72,   84,    0,
    0,    0,    0,    0,    0,   74,   78,   79,   82,    0,
   40,    0,    0,   82,    0,    0,   82,    0,    0,   82,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   83,
   83,    0,   84,    0,   82,    0,    0,    0,   81,   83,
   83,    0,   83,   83,   83,   83,   81,   83,   83,   81,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   84,   81,    0,    0,    0,   82,    0,
    0,    0,    0,   37,    0,   36,    0,   41,    0,   39,
    0,    0,   38,    0,    0,    0,    0,    0,    0,  148,
    0,    0,    0,    0,   74,   78,   79,    0,   81,   82,
   40,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  158,    0,    0,    0,    0,    0,    0,    0,    0,
  160,    0,   74,   78,   79,    0,    0,    0,    0,    0,
    0,    0,    0,   74,   78,   79,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   74,
   78,   79,    0,   37,    0,    0,    0,    0,   74,   78,
   79,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   84,   84,    0,   28,   29,   30,    0,    0,    0,
    0,   84,   84,    0,   84,   84,   84,   84,    0,   84,
   84,   31,    0,    0,    0,    0,   32,    0,    0,   33,
   34,   35,    0,    0,    0,    0,    0,   82,   82,    0,
    0,    0,    0,    0,    0,    0,    0,   82,   82,    0,
   82,   82,   82,   82,    0,   82,   82,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   81,   81,    0,
    0,    0,    0,    0,    0,    0,    0,   81,   81,    0,
   81,   81,   81,   81,    0,   81,   81,    0,    0,    0,
    0,    0,    0,    0,   28,   29,   30,    0,    0,    0,
    0,    0,    0,    0,   18,   19,    0,   20,   59,   61,
    0,   31,   62,   63,   64,   65,   32,    0,   67,   33,
   34,   35,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  107,
  108,  109,  110,  111,  112,  113,  114,  115,  116,  117,
  118,  119,  120,  122,    0,    0,  124,  125,  126,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  134,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  149,    0,    0,    0,    0,    0,    0,
    0,  152,    0,    0,    0,  156,
};
static const YYINT yycheck[] = {                         33,
   35,   35,   91,   37,   38,   42,   40,   41,   42,   43,
   44,   45,   40,   47,  262,  267,  268,   91,  270,   59,
   41,   59,  257,   44,  259,   59,   60,   61,   62,   41,
   59,   37,   44,   59,   40,   33,   42,  103,  263,   37,
   38,   47,   40,   41,   42,   43,   44,   45,   41,   47,
  263,   44,  260,  261,  267,  268,   91,  270,  271,   93,
   94,   59,   60,   61,   62,   59,   94,  272,  273,  267,
  268,   33,  270,  271,  258,   37,   38,  143,   13,   41,
   42,   43,   44,   45,  258,   47,   21,  153,   94,   59,
  124,  263,  158,   59,  160,   93,   94,   59,   60,   61,
   62,  267,  268,  257,  270,  271,   40,   33,   91,   44,
   59,   37,   38,  265,  266,   41,   42,   43,   44,   45,
   44,   47,   93,   58,  262,  263,  124,  267,  268,  269,
  270,   93,   94,   59,   60,   61,   62,   59,   38,  257,
   40,   41,   42,   33,  285,   45,  278,   37,   38,  272,
  273,   41,   42,   43,   44,   45,  278,   47,  267,  268,
  269,  270,  124,   63,  264,  265,  266,   93,   94,   59,
   60,   61,   62,   37,  272,  273,   40,  272,   42,   43,
   33,   45,  263,   47,   37,   38,  278,  272,   41,   42,
   43,   44,   45,    2,   47,   17,  285,  132,  124,  276,
  277,  278,  130,   93,    6,   53,   59,   60,   61,   62,
   37,  285,   15,   40,   44,   42,   43,  140,   45,   51,
   47,  258,  262,  263,  262,  263,  126,   51,  262,  263,
   94,  146,   -1,   60,  124,   62,  262,  263,  272,  273,
   93,  275,  276,  277,  278,   -1,  280,  281,   -1,   -1,
  285,  285,  286,  287,  288,   -1,   38,   -1,   40,   -1,
   42,   -1,   -1,   45,  262,  263,   -1,   94,  262,  263,
   -1,  124,   -1,   -1,  272,  273,   -1,  275,  276,  277,
  278,   63,  280,  281,  276,  277,  278,   -1,  286,  287,
  288,   -1,  262,  263,  276,  277,  278,   -1,   -1,   -1,
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
  263,   44,   16,   94,   -1,   -1,   -1,   -1,   -1,  272,
  273,   -1,  275,  276,  277,  278,   59,  280,  281,   -1,
   -1,  275,  124,  286,   -1,   39,   -1,   -1,   -1,   -1,
   44,   -1,  286,  287,  288,   37,   38,   51,   40,   -1,
   42,   43,   -1,   45,   -1,   47,   -1,   -1,   -1,   -1,
   93,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   60,   61,
   62,   -1,   -1,   37,   38,   -1,   40,   -1,   42,   43,
   -1,   45,   -1,   47,   37,   38,   -1,   40,   -1,   42,
   43,  124,   45,   -1,   47,   -1,   60,   61,   62,  103,
   -1,   -1,   94,   -1,   -1,   -1,   -1,   60,   61,   62,
   37,   38,   -1,   40,   -1,   42,   43,   -1,   45,   37,
   47,   -1,   40,   -1,   42,   43,  130,   45,   -1,   47,
   94,   -1,  124,   60,   61,   62,   -1,   -1,   -1,  143,
   -1,   94,   60,   61,   62,   -1,   -1,   -1,   -1,  153,
   -1,   -1,   -1,   -1,  158,   -1,  160,  286,  287,  288,
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
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  286,
  287,  288,   -1,  126,   -1,   -1,   -1,   -1,  286,  287,
  288,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  262,  263,   -1,  257,  258,  259,   -1,   -1,   -1,
   -1,  272,  273,   -1,  275,  276,  277,  278,   -1,  280,
  281,  274,   -1,   -1,   -1,   -1,  279,   -1,   -1,  282,
  283,  284,   -1,   -1,   -1,   -1,   -1,  262,  263,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  272,  273,   -1,
  275,  276,  277,  278,   -1,  280,  281,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  262,  263,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  272,  273,   -1,
  275,  276,  277,  278,   -1,  280,  281,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  257,  258,  259,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  267,  268,   -1,  270,   31,   32,
   -1,  274,   35,   36,   37,   38,  279,   -1,   41,  282,
  283,  284,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   72,
   73,   74,   75,   76,   77,   78,   79,   80,   81,   82,
   83,   84,   85,   86,   -1,   -1,   89,   90,   91,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  104,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  136,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  144,   -1,   -1,   -1,  148,
};
#define YYFINAL 3
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 290
#define YYUNDFTOKEN 321
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
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"illegal-symbol",
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
"decl : qualifier CONST var declattr",
"decl : qualifier var declattr",
"declattr :",
"declattr : ATTR literal",
"declattr : '[' INTEGER ']'",
"declattr : '[' INTEGER ']' ATTR literal",
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
"rvalue : STR",
"rvalue : INTEGER",
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
"literal : STR",
"literal : integerlist",
"integerlist : INTEGER",
"integerlist : integerlist ',' INTEGER",
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
#line 186 "gram.y"

char **yynames =
#if YYDEBUG > 0
		 (char**)yyname;
#else
		 0;
#endif
#line 710 "y.tab.c"

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
