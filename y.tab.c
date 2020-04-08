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
#define DECLS 291
#define DECL 292
#define DECLATTR 293
#define VARS 294
#define VAR 295
#define BODY 296
#define BODYVARS 297
#define IF_ELIF_ELSE 298
#define RETURN_EXPR 299
#define ELIFS 300
#define INSTRS_INSTRTERM 301
#define INSTRS 302
#define TWO_INTEGERS 303
#define MORE_INTEGERS 304
#define ARGS 305
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    0,    1,    2,    3,    3,    4,    4,    5,    5,
    5,   10,   10,   10,   10,    9,   11,   11,   12,   12,
   13,   13,   13,   14,   14,   15,   15,   16,   17,   17,
   17,    6,    6,    7,    8,    8,   18,   18,   18,   18,
   18,   18,   18,   18,   19,   19,   19,   19,   20,   21,
   21,   22,   22,   22,   22,   23,   23,   24,   24,   25,
   25,   25,   25,   25,   25,   25,   25,   25,   25,   25,
   25,   25,   25,   25,   25,   25,   25,   25,   25,   25,
   25,   25,   25,   25,   26,   26,   27,   29,   29,   30,
   30,   28,   28,   31,   31,
};
static const YYINT yylen[] = {                            2,
    1,    1,    5,    3,    0,    1,    1,    3,    1,    4,
    3,    0,    2,    3,    5,    6,    1,    2,    1,    1,
    0,    1,    1,    0,    1,    1,    3,    2,    1,    1,
    1,    2,    1,    1,    2,    3,    5,    8,    6,    7,
    9,    2,    2,    4,    1,    1,    2,    1,    4,    1,
    2,    0,    1,    1,    2,    1,    2,    1,    4,    1,
    3,    4,    3,    1,    1,    2,    2,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    2,    1,    1,    1,    1,    1,    1,    2,
    2,    1,    3,    1,    3,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,    1,    2,    0,   22,   23,    0,    0,
    7,    9,    0,    0,    0,    0,    0,   29,   30,   31,
    0,    0,    0,    4,   20,    0,   19,   65,   58,   64,
    0,    0,   45,   46,    0,    0,    0,    0,   84,    0,
    0,   33,    0,    0,   56,   53,   34,    0,    0,    0,
    8,    0,    0,    0,   11,   28,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    3,   32,    0,   35,   57,
   55,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   42,
   43,   10,   87,   89,   13,    0,    0,   85,    0,    0,
    0,    0,   26,    0,    0,   61,   36,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   63,    0,    0,   90,    0,   91,
    0,   17,    0,   16,    0,    0,    0,   59,   44,   62,
    0,   93,    0,   18,   27,    0,    0,   37,   50,    0,
    0,    0,   15,    0,    0,    0,   39,   51,    0,   40,
    0,    0,    0,   49,   38,    0,   41,
};
static const YYINT yydgoto[] = {                          3,
    4,    5,    9,   10,   11,   41,   42,   43,   12,   55,
  134,   26,   13,  101,  102,   44,   23,   45,   46,  149,
  150,   47,   48,   58,   50,   95,   96,   97,   98,   99,
  127,
};
static const YYINT yysindex[] = {                      -202,
 -177, -177,    0,    0,    0, -157,    0,    0, -231,  -22,
    0,    0, -111, -220, -146, 1189, -177,    0,    0,    0,
 -252,  -88, -209,    0,    0, -207,    0,    0,    0,    0,
  132,  132,    0,    0,  132,  132,  132,  132,    0,  132,
 -210,    0, 1189,   -3,    0,    0,    0,   80,  -34,  797,
    0,  -88, -237, -191,    0,    0, -252,  -78,  902,  511,
 1193,   35, 1053,   35,  928,    0,    0,   12,    0,    0,
    0,  132,  132,  132,  132,  132,  132,  132,  132,  132,
  132,  132,  132,  132,  132,  132,  132,  132,   29,    0,
    0,    0,    0,    0,    0, -184,   34,    0, -184,   22,
 -137,   58,    0,   80,  132,    0,    0, 1193,  963, 1003,
  476, 1053, 1224, 1224,  463,  463,  463,  463,  258,  258,
  -15,  -15,  -15,  -15,    0, 1193,  -11,    0, -184,    0,
 -166,    0, 1189,    0, -252, -183, 1098,    0,    0,    0,
  132,    0, -237,    0,    0,   80,  132,    0,    0, -173,
  132, 1193,    0, -152, 1138,   80,    0,    0, 1164,    0,
   80, -131,   80,    0,    0, -119,    0,
};
static const YYINT yyrindex[] = {                         0,
  104, -129,    0,    0,    0,   -8,    0,    0,    0,  -98,
    0,    0,    0,    0,    0, -105,  -56,    0,    0,    0,
    0,  -53,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   31,    0,    0,    0,    0,    0,
    0,    0,  -40,    0,    0,    0,    0,  210,  863,    0,
    0,  -53,    0,    0,    0,    0,  -90,  -33,    0,    0,
  314,    3,  175,   39,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  -42,  -38,    0,  -36,    0,
    0,  -81,    0, -103,    0,    0,    0, 1283,    0,    0,
 1263, 1241,  848,  893,  471,  506,  541,  607,  401,  436,
   69,  107,  143,  366,    0,   -6,    0,    0,    0,    0,
  -25,    0,  -40,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0, -117,    0,    0,    0,    0,
    0,   -2,    0,    0,    0, -117,    0,    0,    0,    0,
 -103,    0, -101,    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
    0,    0,  176,    0,  181,   66,  158,    0,    0,  165,
    0,    0,  212,    0,    0,   11,  213,  184,  185,   85,
    0,   33,    0, 1114, 1323,   98,  -44,    0,    0,    0,
    0,
};
#define YYTABLESIZE 1564
static const YYINT yytable[] = {                         60,
   74,   92,   54,   60,   60,   12,   60,   60,   60,   60,
   60,   60,   73,   60,   18,   19,   92,   20,   52,   93,
   86,   94,   88,   22,   89,   60,   60,   60,   60,  140,
   16,   52,  141,   14,   94,   67,   17,   94,   95,   67,
   67,   95,   24,   67,   67,   67,   67,   67,   56,   67,
   57,  128,   66,   68,  130,   69,   73,    1,    2,   60,
   60,   67,   67,   67,   67,  100,   36,  103,   40,  125,
  107,   66,   93,   38,   89,   66,   66,  129,   88,   66,
   66,   66,   66,   66,  142,   66,    6,    7,    8,   48,
   60,   39,  146,  147,  148,   67,   67,   66,   66,   66,
   66,   71,  156,  147,  157,   71,   71,    7,    8,   71,
   71,   71,   71,   71,  131,   71,  135,   36,  143,   40,
   18,   19,   25,   20,   38,  160,   67,   71,   71,   71,
   71,   66,   66,    5,  132,  133,  136,   21,   21,   72,
   21,   21,   39,   72,   72,  145,  165,   72,   72,   72,
   72,   72,  167,   72,   37,   18,   19,   52,   20,   21,
   52,   71,   66,    6,    6,   72,   72,   72,   72,   36,
   52,   40,   52,   52,   52,   73,   38,   14,  154,   73,
   73,   24,   24,   73,   73,   73,   73,   73,  162,   73,
   25,   25,   71,  164,   39,  166,   53,   51,  144,   72,
   67,   73,   73,   73,   73,   37,   72,   83,   12,   12,
   21,   21,   83,   21,   21,   83,   92,   15,   83,   92,
   92,   52,   52,   86,   86,   88,   88,   27,   60,   60,
   72,   70,   71,   83,  158,   73,   14,   14,   60,   60,
  153,   60,   60,   60,   60,    0,   60,   60,    0,    0,
   72,    0,   60,   60,   60,    0,    0,   37,   21,   21,
   21,   21,    0,    0,   67,   67,   73,   83,   54,    0,
    0,    0,    0,    0,   67,   67,    0,   67,   67,   67,
   67,    0,   67,   67,    0,   28,   29,   30,   67,   67,
   67,    0,   48,   48,   87,    0,    0,   89,   83,   85,
   66,   66,   48,    0,   86,    0,   48,   48,   48,    0,
   66,   66,    0,   66,   66,   66,   66,    0,   66,   66,
    0,    0,    0,    0,   66,   66,   66,    0,    0,    0,
   71,   71,    0,    0,    0,    0,   28,   29,   30,    0,
   71,   71,    0,   71,   71,   71,   71,    0,   71,   71,
    0,   88,    0,   31,   71,   71,   71,    0,   32,    0,
    0,   33,   34,   35,    0,    5,    0,    0,   72,   72,
   21,   21,   47,   21,   21,    0,    0,    0,   72,   72,
    0,   72,   72,   72,   72,    0,   72,   72,   28,   29,
   30,    0,   72,   72,   72,    0,    0,    0,   68,    0,
    0,    0,   68,   68,   73,   73,   68,   68,   68,   68,
   68,    0,   68,    0,   73,   73,    0,   73,   73,   73,
   73,    0,   73,   73,   68,   68,   68,   68,   73,   73,
   73,    0,    0,   69,    0,    0,   83,   83,   69,    0,
    0,   69,    0,   69,   69,   69,   83,   83,    0,   83,
   83,   83,   83,    0,   83,   83,    0,    0,   68,   69,
   69,   69,   69,    0,    0,    0,    0,    0,   70,    0,
    0,   54,   54,   70,    0,    0,   70,    0,   70,   70,
   70,   54,    0,    0,    0,   54,   54,   54,    0,   68,
    0,    0,    0,   69,   70,   70,   70,   70,    0,   87,
    0,    0,   89,   74,   85,   83,    0,   84,   74,   86,
    0,   74,   87,   76,   74,   89,    0,   85,   83,    0,
   84,    0,   86,    0,   69,    0,    0,    0,   70,   74,
   74,   74,   74,    0,    0,   79,   78,   80,   75,    0,
    0,    0,    0,   75,    0,    0,   75,   87,   76,   75,
   89,    0,   85,   83,    0,   84,   88,   86,    0,   70,
    0,    0,    0,   74,   75,   75,   75,   75,    0,   88,
   79,   78,   80,   77,    0,   47,   47,    0,   77,    0,
    0,   77,    0,    0,   77,   47,    0,    0,    0,   47,
   47,   47,    0,    0,   74,    0,    0,    0,   75,   77,
   77,   77,   77,    0,   88,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   68,   68,   75,
    0,    0,    0,   77,   75,    0,    0,   68,   68,   76,
   68,   68,   68,   68,   76,   68,   68,   76,    0,    0,
   76,   68,   68,   68,    0,    0,    0,    0,    0,    0,
    0,    0,   69,   69,   77,   76,   76,   76,   76,    0,
    0,    0,   69,   69,    0,   69,   69,   69,   69,    0,
   69,   69,    0,    0,    0,    0,   69,   69,   69,    0,
    0,    0,    0,    0,    0,    0,    0,   70,   70,   76,
    0,    0,    0,    0,    0,    0,    0,   70,   70,    0,
   70,   70,   70,   70,    0,   70,   70,    0,    0,    0,
    0,   70,   70,   70,    0,    0,    0,    0,    0,    0,
   76,    0,   74,   74,    0,    0,    0,    0,    0,    0,
    0,    0,   74,   74,    0,   74,   74,   74,   74,    0,
   74,   74,    0,    0,    0,    0,   74,   74,   74,    0,
    0,   77,   81,   82,    0,    0,    0,   75,   75,    0,
    0,    0,    0,    0,    0,    0,    0,   75,   75,    0,
   75,   75,   75,   75,    0,   75,   75,    0,    0,    0,
  105,   75,   75,   75,    0,    0,   77,   81,   82,    0,
    0,    0,   77,   77,    0,    0,    0,    0,    0,    0,
    0,    0,   77,   77,    0,   77,   77,   77,   77,    0,
   77,   77,    0,    0,    0,    0,   77,   77,   77,   91,
    0,    0,    0,   87,   76,    0,   89,    0,   85,   83,
    0,   84,    0,   86,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   90,   79,   78,   80,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   76,   76,
    0,    0,    0,    0,    0,    0,    0,    0,   76,   76,
   78,   76,   76,   76,   76,   78,   76,   76,   78,    0,
   88,   78,   76,   76,   76,   60,    0,    0,    0,   60,
   60,    0,   60,    0,   60,   60,   78,   60,   78,   60,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   75,   60,   60,   60,   60,   79,    0,    0,    0,    0,
   79,    0,    0,   79,    0,    0,   79,    0,   87,   76,
   78,   89,    0,   85,   83,    0,   84,    0,   86,    0,
    0,   79,    0,   79,    0,    0,   60,    0,    0,    0,
    0,   79,   78,   80,   87,   76,    0,   89,  106,   85,
   83,   78,   84,    0,   86,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   79,   60,   79,   78,   80,
    0,    0,    0,    0,    0,   88,    0,    0,    0,   87,
   76,    0,   89,    0,   85,   83,    0,   84,    0,   86,
    0,    0,    0,    0,    0,    0,   79,    0,    0,    0,
    0,   88,   79,   78,   80,   75,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   87,
   76,    0,   89,    0,   85,   83,    0,   84,    0,   86,
    0,   75,    0,    0,    0,  138,   88,    0,    0,    0,
    0,  139,   79,   78,   80,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   77,   81,   82,    0,   75,    0,    0,   87,
    0,    0,   89,    0,   85,   83,   88,   84,    0,   86,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   78,
   78,    0,   79,   78,   80,    0,    0,    0,    0,   78,
   78,    0,   78,   78,   78,   78,   75,   78,   78,   49,
    0,    0,    0,   78,   87,   76,    0,   89,    0,   85,
   83,    0,   84,    0,   86,    0,   88,    0,   60,   60,
   60,    0,    0,    0,   79,   79,   49,   79,   78,   80,
    0,   49,    0,    0,   79,   79,    0,   79,   79,   79,
   79,    0,   79,   79,   87,   76,  104,   89,   79,   85,
   83,    0,   84,    0,   86,    0,    0,   77,   81,   82,
    0,   88,    0,    0,    0,    0,    0,   79,   78,   80,
   87,   76,    0,   89,    0,   85,   83,    0,   84,    0,
   86,    0,    0,   77,   81,   82,    0,   49,    0,    0,
    0,   75,    0,   79,   78,   80,   36,    0,   40,   87,
   76,   88,   89,   38,   85,   83,    0,   84,    0,   86,
    0,    0,    0,    0,    0,    0,   49,    0,   77,   81,
   82,   39,   79,   78,   80,    0,    0,   88,    0,   49,
   87,   75,    0,   89,    0,   85,   83,    0,   84,   49,
   86,    0,    0,   81,   49,    0,   49,    0,   81,    0,
    0,   81,    0,   79,   81,   80,   88,   75,   77,   81,
   82,    0,    0,    0,    0,   82,    0,    0,    0,   81,
    0,    0,    0,   82,    0,    0,   82,    0,    0,    0,
    0,    0,    0,    0,   37,   80,   75,   88,    0,    0,
    0,   82,    0,   80,    0,    0,   80,    0,    0,    0,
    0,    0,    0,   81,    0,    0,    0,    0,   77,   81,
   82,   80,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   59,   60,   82,    0,   61,   62,   63,
   64,    0,   65,    0,   81,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   80,    0,    0,  151,    0,
    0,    0,    0,   77,   81,   82,   82,    0,    0,    0,
    0,    0,    0,    0,  108,  109,  110,  111,  112,  113,
  114,  115,  116,  117,  118,  119,  120,  121,  122,  123,
  124,  126,  161,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   77,   81,   82,    0,  137,    0,    0,
    0,    0,    0,    0,    0,    0,  163,    0,    0,    0,
    0,    0,    0,    0,    0,   28,   29,   30,    0,   77,
   81,   82,    0,    0,    0,   18,   19,    0,   20,    0,
    0,    0,   31,  152,    0,    0,    0,   32,    0,  155,
   33,   34,   35,  159,    0,    0,    0,    0,   77,   81,
   82,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   81,   81,    0,    0,    0,    0,    0,    0,
   81,   82,   81,   81,    0,   81,   81,   81,   81,    0,
   81,   81,    0,    0,   82,   82,    0,    0,    0,    0,
    0,    0,    0,    0,   82,   82,    0,   82,   82,   82,
   82,    0,   82,   82,   80,   80,    0,    0,    0,    0,
    0,    0,    0,    0,   80,   80,    0,   80,   80,   80,
   80,    0,   80,   80,
};
static const YYINT yycheck[] = {                         33,
   35,   44,   91,   37,   38,   59,   40,   41,   42,   43,
   44,   45,   91,   47,  267,  268,   59,  270,   59,  257,
   59,  259,   59,   13,   40,   59,   60,   61,   62,   41,
  262,   21,   44,   59,   41,   33,   59,   44,   41,   37,
   38,   44,  263,   41,   42,   43,   44,   45,  258,   47,
  258,   96,  263,   43,   99,   59,   91,  260,  261,   93,
   94,   59,   60,   61,   62,  257,   38,   57,   40,   41,
   59,   33,  257,   45,   40,   37,   38,   44,   94,   41,
   42,   43,   44,   45,  129,   47,  264,  265,  266,   59,
  124,   63,  276,  277,  278,   93,   94,   59,   60,   61,
   62,   33,  276,  277,  278,   37,   38,  265,  266,   41,
   42,   43,   44,   45,   93,   47,   59,   38,  285,   40,
  267,  268,  269,  270,   45,  278,  124,   59,   60,   61,
   62,   93,   94,  263,  272,  273,  104,  267,  268,   33,
  270,  271,   63,   37,   38,  135,  278,   41,   42,   43,
   44,   45,  272,   47,  126,  267,  268,  263,  270,  271,
  278,   93,  124,  262,  263,   59,   60,   61,   62,   38,
  272,   40,  276,  277,  278,   33,   45,    2,  146,   37,
   38,  272,  273,   41,   42,   43,   44,   45,  156,   47,
  272,  273,  124,  161,   63,  163,  285,   17,  133,   93,
   43,   59,   60,   61,   62,  126,  285,   33,  262,  263,
  267,  268,   38,  270,  271,   41,   52,    6,   44,  262,
  263,  262,  263,  262,  263,  262,  263,   15,  262,  263,
  124,   48,   48,   59,  150,   93,  262,  263,  272,  273,
  143,  275,  276,  277,  278,   -1,  280,  281,   -1,   -1,
  285,   -1,  286,  287,  288,   -1,   -1,  126,  267,  268,
  269,  270,   -1,   -1,  262,  263,  124,   93,   59,   -1,
   -1,   -1,   -1,   -1,  272,  273,   -1,  275,  276,  277,
  278,   -1,  280,  281,   -1,  257,  258,  259,  286,  287,
  288,   -1,  262,  263,   37,   -1,   -1,   40,  124,   42,
  262,  263,  272,   -1,   47,   -1,  276,  277,  278,   -1,
  272,  273,   -1,  275,  276,  277,  278,   -1,  280,  281,
   -1,   -1,   -1,   -1,  286,  287,  288,   -1,   -1,   -1,
  262,  263,   -1,   -1,   -1,   -1,  257,  258,  259,   -1,
  272,  273,   -1,  275,  276,  277,  278,   -1,  280,  281,
   -1,   94,   -1,  274,  286,  287,  288,   -1,  279,   -1,
   -1,  282,  283,  284,   -1,  262,   -1,   -1,  262,  263,
  267,  268,   59,  270,  271,   -1,   -1,   -1,  272,  273,
   -1,  275,  276,  277,  278,   -1,  280,  281,  257,  258,
  259,   -1,  286,  287,  288,   -1,   -1,   -1,   33,   -1,
   -1,   -1,   37,   38,  262,  263,   41,   42,   43,   44,
   45,   -1,   47,   -1,  272,  273,   -1,  275,  276,  277,
  278,   -1,  280,  281,   59,   60,   61,   62,  286,  287,
  288,   -1,   -1,   33,   -1,   -1,  262,  263,   38,   -1,
   -1,   41,   -1,   43,   44,   45,  272,  273,   -1,  275,
  276,  277,  278,   -1,  280,  281,   -1,   -1,   93,   59,
   60,   61,   62,   -1,   -1,   -1,   -1,   -1,   33,   -1,
   -1,  262,  263,   38,   -1,   -1,   41,   -1,   43,   44,
   45,  272,   -1,   -1,   -1,  276,  277,  278,   -1,  124,
   -1,   -1,   -1,   93,   59,   60,   61,   62,   -1,   37,
   -1,   -1,   40,   33,   42,   43,   -1,   45,   38,   47,
   -1,   41,   37,   38,   44,   40,   -1,   42,   43,   -1,
   45,   -1,   47,   -1,  124,   -1,   -1,   -1,   93,   59,
   60,   61,   62,   -1,   -1,   60,   61,   62,   33,   -1,
   -1,   -1,   -1,   38,   -1,   -1,   41,   37,   38,   44,
   40,   -1,   42,   43,   -1,   45,   94,   47,   -1,  124,
   -1,   -1,   -1,   93,   59,   60,   61,   62,   -1,   94,
   60,   61,   62,   33,   -1,  262,  263,   -1,   38,   -1,
   -1,   41,   -1,   -1,   44,  272,   -1,   -1,   -1,  276,
  277,  278,   -1,   -1,  124,   -1,   -1,   -1,   93,   59,
   60,   61,   62,   -1,   94,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  262,  263,  124,
   -1,   -1,   -1,   93,  124,   -1,   -1,  272,  273,   33,
  275,  276,  277,  278,   38,  280,  281,   41,   -1,   -1,
   44,  286,  287,  288,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  262,  263,  124,   59,   60,   61,   62,   -1,
   -1,   -1,  272,  273,   -1,  275,  276,  277,  278,   -1,
  280,  281,   -1,   -1,   -1,   -1,  286,  287,  288,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  262,  263,   93,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  272,  273,   -1,
  275,  276,  277,  278,   -1,  280,  281,   -1,   -1,   -1,
   -1,  286,  287,  288,   -1,   -1,   -1,   -1,   -1,   -1,
  124,   -1,  262,  263,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  272,  273,   -1,  275,  276,  277,  278,   -1,
  280,  281,   -1,   -1,   -1,   -1,  286,  287,  288,   -1,
   -1,  286,  287,  288,   -1,   -1,   -1,  262,  263,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  272,  273,   -1,
  275,  276,  277,  278,   -1,  280,  281,   -1,   -1,   -1,
  280,  286,  287,  288,   -1,   -1,  286,  287,  288,   -1,
   -1,   -1,  262,  263,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  272,  273,   -1,  275,  276,  277,  278,   -1,
  280,  281,   -1,   -1,   -1,   -1,  286,  287,  288,   33,
   -1,   -1,   -1,   37,   38,   -1,   40,   -1,   42,   43,
   -1,   45,   -1,   47,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   59,   60,   61,   62,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  262,  263,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  272,  273,
   33,  275,  276,  277,  278,   38,  280,  281,   41,   -1,
   94,   44,  286,  287,  288,   33,   -1,   -1,   -1,   37,
   38,   -1,   40,   -1,   42,   43,   59,   45,   61,   47,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  124,   59,   60,   61,   62,   33,   -1,   -1,   -1,   -1,
   38,   -1,   -1,   41,   -1,   -1,   44,   -1,   37,   38,
   93,   40,   -1,   42,   43,   -1,   45,   -1,   47,   -1,
   -1,   59,   -1,   61,   -1,   -1,   94,   -1,   -1,   -1,
   -1,   60,   61,   62,   37,   38,   -1,   40,   41,   42,
   43,  124,   45,   -1,   47,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   93,  124,   60,   61,   62,
   -1,   -1,   -1,   -1,   -1,   94,   -1,   -1,   -1,   37,
   38,   -1,   40,   -1,   42,   43,   -1,   45,   -1,   47,
   -1,   -1,   -1,   -1,   -1,   -1,  124,   -1,   -1,   -1,
   -1,   94,   60,   61,   62,  124,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   37,
   38,   -1,   40,   -1,   42,   43,   -1,   45,   -1,   47,
   -1,  124,   -1,   -1,   -1,   93,   94,   -1,   -1,   -1,
   -1,   59,   60,   61,   62,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  286,  287,  288,   -1,  124,   -1,   -1,   37,
   -1,   -1,   40,   -1,   42,   43,   94,   45,   -1,   47,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  262,
  263,   -1,   60,   61,   62,   -1,   -1,   -1,   -1,  272,
  273,   -1,  275,  276,  277,  278,  124,  280,  281,   16,
   -1,   -1,   -1,  286,   37,   38,   -1,   40,   -1,   42,
   43,   -1,   45,   -1,   47,   -1,   94,   -1,  286,  287,
  288,   -1,   -1,   -1,  262,  263,   43,   60,   61,   62,
   -1,   48,   -1,   -1,  272,  273,   -1,  275,  276,  277,
  278,   -1,  280,  281,   37,   38,  275,   40,  286,   42,
   43,   -1,   45,   -1,   47,   -1,   -1,  286,  287,  288,
   -1,   94,   -1,   -1,   -1,   -1,   -1,   60,   61,   62,
   37,   38,   -1,   40,   -1,   42,   43,   -1,   45,   -1,
   47,   -1,   -1,  286,  287,  288,   -1,  104,   -1,   -1,
   -1,  124,   -1,   60,   61,   62,   38,   -1,   40,   37,
   38,   94,   40,   45,   42,   43,   -1,   45,   -1,   47,
   -1,   -1,   -1,   -1,   -1,   -1,  133,   -1,  286,  287,
  288,   63,   60,   61,   62,   -1,   -1,   94,   -1,  146,
   37,  124,   -1,   40,   -1,   42,   43,   -1,   45,  156,
   47,   -1,   -1,   33,  161,   -1,  163,   -1,   38,   -1,
   -1,   41,   -1,   60,   44,   62,   94,  124,  286,  287,
  288,   -1,   -1,   -1,   -1,   33,   -1,   -1,   -1,   59,
   -1,   -1,   -1,   41,   -1,   -1,   44,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  126,   33,  124,   94,   -1,   -1,
   -1,   59,   -1,   41,   -1,   -1,   44,   -1,   -1,   -1,
   -1,   -1,   -1,   93,   -1,   -1,   -1,   -1,  286,  287,
  288,   59,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   31,   32,   93,   -1,   35,   36,   37,
   38,   -1,   40,   -1,  124,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   93,   -1,   -1,  281,   -1,
   -1,   -1,   -1,  286,  287,  288,  124,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   72,   73,   74,   75,   76,   77,
   78,   79,   80,   81,   82,   83,   84,   85,   86,   87,
   88,   89,  275,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  286,  287,  288,   -1,  105,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  273,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  257,  258,  259,   -1,  286,
  287,  288,   -1,   -1,   -1,  267,  268,   -1,  270,   -1,
   -1,   -1,  274,  141,   -1,   -1,   -1,  279,   -1,  147,
  282,  283,  284,  151,   -1,   -1,   -1,   -1,  286,  287,
  288,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  262,  263,   -1,   -1,   -1,   -1,   -1,   -1,
  287,  288,  272,  273,   -1,  275,  276,  277,  278,   -1,
  280,  281,   -1,   -1,  262,  263,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  272,  273,   -1,  275,  276,  277,
  278,   -1,  280,  281,  262,  263,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  272,  273,   -1,  275,  276,  277,
  278,   -1,  280,  281,
};
#define YYFINAL 3
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 305
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
"DECLS","DECL","DECLATTR","VARS","VAR","BODY","BODYVARS","IF_ELIF_ELSE",
"RETURN_EXPR","ELIFS","INSTRS_INSTRTERM","INSTRS","TWO_INTEGERS",
"MORE_INTEGERS","ARGS",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,"illegal-symbol",
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
"literal : string",
"literal : integerlist",
"integer : INTEGER",
"string : stringintegerlist",
"string : STR",
"stringintegerlist : integer integer",
"stringintegerlist : stringintegerlist integer",
"integerlist : integer",
"integerlist : integerlist ',' integer",
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
#line 199 "gram.y"

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
case 1:
#line 43 "gram.y"
	{ printNode(yystack.l_mark[0].n,0,yynames); }
break;
case 2:
#line 44 "gram.y"
	{ printNode(yystack.l_mark[0].n,0,yynames); }
break;
case 3:
#line 47 "gram.y"
	{ yyval.n = binNode(PROGRAM, yystack.l_mark[-3].n, yystack.l_mark[-1].n); }
break;
case 4:
#line 50 "gram.y"
	{ yyval.n = uniNode(MODULE, yystack.l_mark[-1].n); }
break;
case 5:
#line 53 "gram.y"
	{ yyval.n = nilNode(END); }
break;
case 6:
#line 54 "gram.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 7:
#line 57 "gram.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 8:
#line 58 "gram.y"
	{ yyval.n = binNode(DECLS, yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 9:
#line 61 "gram.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 10:
#line 62 "gram.y"
	{ yyval.n = triNode(DECL, yystack.l_mark[-3].n, yystack.l_mark[-1].n, yystack.l_mark[0].n); }
break;
case 11:
#line 63 "gram.y"
	{ yyval.n = triNode(DECL, yystack.l_mark[-2].n, yystack.l_mark[-1].n, yystack.l_mark[0].n); }
break;
case 12:
#line 66 "gram.y"
	{ yyval.n = nilNode(END); }
break;
case 13:
#line 67 "gram.y"
	{ yyval.n = uniNode(DECLATTR, yystack.l_mark[0].n); }
break;
case 14:
#line 68 "gram.y"
	{ yyval.n = nilNode(END); }
break;
case 15:
#line 69 "gram.y"
	{ yyval.n = uniNode(DECLATTR, yystack.l_mark[0].n); }
break;
case 16:
#line 71 "gram.y"
	{ yyval.n = pentNode(FUNCTION, yystack.l_mark[-4].n, yystack.l_mark[-3].n, strNode(ID, yystack.l_mark[-2].s), yystack.l_mark[-1].n, yystack.l_mark[0].n); }
break;
case 17:
#line 74 "gram.y"
	{ yyval.n = nilNode(END); }
break;
case 18:
#line 75 "gram.y"
	{ yyval.n = uniNode(DO, yystack.l_mark[0].n); }
break;
case 19:
#line 78 "gram.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 20:
#line 79 "gram.y"
	{ yyval.n = uniNode(VOID, nilNode(END)); }
break;
case 21:
#line 82 "gram.y"
	{ yyval.n = nilNode(END); }
break;
case 22:
#line 83 "gram.y"
	{ yyval.n = uniNode(PUBLIC, nilNode(END)); }
break;
case 23:
#line 84 "gram.y"
	{ yyval.n = uniNode(FORWARD, nilNode(END)); }
break;
case 24:
#line 87 "gram.y"
	{ yyval.n = nilNode(END); }
break;
case 25:
#line 88 "gram.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 26:
#line 91 "gram.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 27:
#line 92 "gram.y"
	{ yyval.n = binNode(VARS, yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 28:
#line 95 "gram.y"
	{ yyval.n = binNode(VAR, yystack.l_mark[-1].n, strNode(ID, yystack.l_mark[0].s)); }
break;
case 29:
#line 98 "gram.y"
	{ yyval.n = uniNode(NUMBER, nilNode(END)); }
break;
case 30:
#line 99 "gram.y"
	{ yyval.n = uniNode(ARRAY, nilNode(END)); }
break;
case 31:
#line 100 "gram.y"
	{ yyval.n = uniNode(STRING, nilNode(END)); }
break;
case 32:
#line 103 "gram.y"
	{ yyval.n = binNode(BODY, yystack.l_mark[-1].n, yystack.l_mark[0].n); }
break;
case 33:
#line 104 "gram.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 34:
#line 107 "gram.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 35:
#line 109 "gram.y"
	{ yyval.n = yystack.l_mark[-1].n; }
break;
case 36:
#line 110 "gram.y"
	{ yyval.n = binNode(BODYVARS, yystack.l_mark[-2].n, yystack.l_mark[-1].n); }
break;
case 37:
#line 113 "gram.y"
	{ yyval.n = binNode(IF, yystack.l_mark[-3].n, yystack.l_mark[-1].n); }
break;
case 38:
#line 114 "gram.y"
	{ yyval.n = quadNode(IF_ELIF_ELSE, yystack.l_mark[-6].n, yystack.l_mark[-4].n, yystack.l_mark[-3].n, yystack.l_mark[-1].n); }
break;
case 39:
#line 115 "gram.y"
	{ yyval.n = triNode(ELIF, yystack.l_mark[-4].n, yystack.l_mark[-2].n, yystack.l_mark[-1].n); }
break;
case 40:
#line 116 "gram.y"
	{ yyval.n = triNode(ELSE, yystack.l_mark[-5].n, yystack.l_mark[-3].n, yystack.l_mark[-1].n); }
break;
case 41:
#line 117 "gram.y"
	{ yyval.n = quadNode(FOR, yystack.l_mark[-7].n, yystack.l_mark[-5].n, yystack.l_mark[-3].n, yystack.l_mark[-1].n); }
break;
case 42:
#line 118 "gram.y"
	{ yyval.n = yystack.l_mark[-1].n; }
break;
case 43:
#line 119 "gram.y"
	{ yyval.n = yystack.l_mark[-1].n; }
break;
case 44:
#line 120 "gram.y"
	{ yyval.n = binNode('#', yystack.l_mark[-3].n, yystack.l_mark[-1].n); }
break;
case 45:
#line 123 "gram.y"
	{ yyval.n = uniNode(REPEAT, nilNode(END)); }
break;
case 46:
#line 124 "gram.y"
	{ yyval.n = uniNode(STOP, nilNode(END)); }
break;
case 47:
#line 125 "gram.y"
	{ yyval.n = uniNode(RETURN_EXPR, nilNode(END)); }
break;
case 48:
#line 126 "gram.y"
	{ yyval.n = uniNode(RETURN, nilNode(END)); }
break;
case 49:
#line 129 "gram.y"
	{ yyval.n = binNode(ELIF, yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 50:
#line 132 "gram.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 51:
#line 133 "gram.y"
	{ yyval.n = binNode(ELIFS, yystack.l_mark[-1].n, yystack.l_mark[0].n); }
break;
case 52:
#line 136 "gram.y"
	{ yyval.n = nilNode(END); }
break;
case 53:
#line 137 "gram.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 54:
#line 138 "gram.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 55:
#line 139 "gram.y"
	{ yyval.n = binNode(INSTRS_INSTRTERM, yystack.l_mark[-1].n, yystack.l_mark[0].n); }
break;
case 56:
#line 142 "gram.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 57:
#line 143 "gram.y"
	{ yyval.n = binNode(INSTRS, yystack.l_mark[-1].n, yystack.l_mark[0].n); }
break;
case 58:
#line 146 "gram.y"
	{ yyval.n = strNode(ID, yystack.l_mark[0].s); }
break;
case 59:
#line 147 "gram.y"
	{ yyval.n = binNode('[', yystack.l_mark[-3].n, yystack.l_mark[-1].n); }
break;
case 60:
#line 150 "gram.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 61:
#line 151 "gram.y"
	{ yyval.n = yystack.l_mark[-1].n; }
break;
case 62:
#line 152 "gram.y"
	{ yyval.n = binNode('(', yystack.l_mark[-3].n, yystack.l_mark[-1].n); }
break;
case 63:
#line 153 "gram.y"
	{ yyval.n = yystack.l_mark[-2].n; }
break;
case 64:
#line 154 "gram.y"
	{ yyval.n = strNode(STR, yystack.l_mark[0].s); }
break;
case 65:
#line 155 "gram.y"
	{ yyval.n = intNode(INTEGER, yystack.l_mark[0].i); }
break;
case 66:
#line 156 "gram.y"
	{ yyval.n = uniNode(UMINUS, yystack.l_mark[0].n); }
break;
case 67:
#line 157 "gram.y"
	{ yyval.n = uniNode(ADDR, yystack.l_mark[0].n); }
break;
case 68:
#line 158 "gram.y"
	{ yyval.n = binNode('^', yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 69:
#line 159 "gram.y"
	{ yyval.n = binNode('+', yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 70:
#line 160 "gram.y"
	{ yyval.n = binNode('-', yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 71:
#line 161 "gram.y"
	{ yyval.n = binNode('*', yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 72:
#line 162 "gram.y"
	{ yyval.n = binNode('/', yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 73:
#line 163 "gram.y"
	{ yyval.n = binNode('%', yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 74:
#line 164 "gram.y"
	{ yyval.n = binNode('<', yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 75:
#line 165 "gram.y"
	{ yyval.n = binNode('>', yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 76:
#line 166 "gram.y"
	{ yyval.n = binNode(GE, yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 77:
#line 167 "gram.y"
	{ yyval.n = binNode(LE, yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 78:
#line 168 "gram.y"
	{ yyval.n = binNode(NE, yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 79:
#line 169 "gram.y"
	{ yyval.n = binNode('=', yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 80:
#line 170 "gram.y"
	{ yyval.n = binNode(ATTR, yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 81:
#line 171 "gram.y"
	{ yyval.n = binNode('&', yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 82:
#line 172 "gram.y"
	{ yyval.n = binNode('|', yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 83:
#line 173 "gram.y"
	{ yyval.n = uniNode('~', yystack.l_mark[0].n); }
break;
case 84:
#line 174 "gram.y"
	{ yyval.n = uniNode('?', nilNode(END)); }
break;
case 85:
#line 177 "gram.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 86:
#line 178 "gram.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 87:
#line 181 "gram.y"
	{ yyval.n = intNode(INTEGER, yystack.l_mark[0].i); }
break;
case 88:
#line 184 "gram.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 89:
#line 185 "gram.y"
	{ yyval.n = strNode(STR, yystack.l_mark[0].s); }
break;
case 90:
#line 188 "gram.y"
	{ yyval.n = binNode(TWO_INTEGERS, yystack.l_mark[-1].n, yystack.l_mark[0].n); }
break;
case 91:
#line 189 "gram.y"
	{ yyval.n = binNode(MORE_INTEGERS, yystack.l_mark[-1].n, yystack.l_mark[0].n); }
break;
case 92:
#line 191 "gram.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 93:
#line 192 "gram.y"
	{ yyval.n = binNode(',', yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 94:
#line 195 "gram.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 95:
#line 196 "gram.y"
	{ yyval.n = binNode(ARGS, yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
#line 1292 "y.tab.c"
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
