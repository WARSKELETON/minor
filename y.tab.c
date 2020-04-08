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
#define NIL 291
#define DECLS 292
#define DECL 293
#define FUNCTYPE 294
#define QUALIFIER 295
#define DECLATTR 296
#define VARS 297
#define VAR 298
#define BODY 299
#define BODYVARS 300
#define RETURN_EXPR 301
#define ELIFS 302
#define INSTRS_INSTRTERM 303
#define INSTRS 304
#define TWO_INTEGERS 305
#define MORE_INTEGERS 306
#define ARGS 307
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    0,    1,    2,    3,    3,    4,    4,    5,    5,
    5,   11,   11,   11,   11,   10,   12,   12,   13,   13,
   14,   14,   14,   15,   15,   16,   16,   17,   18,   18,
   18,    7,    7,    6,    6,    8,    8,    9,    9,   19,
   19,   19,   19,   19,   19,   19,   19,   20,   20,   20,
   20,   21,   22,   22,   23,   23,   23,   23,   24,   24,
   25,   25,   26,   26,   26,   26,   26,   26,   26,   26,
   26,   26,   26,   26,   26,   26,   26,   26,   26,   26,
   26,   26,   26,   26,   26,   26,   26,   27,   27,   28,
   30,   30,   31,   31,   29,   29,   32,   32,
};
static const YYINT yylen[] = {                            2,
    1,    1,    5,    3,    0,    1,    1,    3,    1,    4,
    3,    0,    2,    3,    5,    6,    1,    2,    1,    1,
    0,    1,    1,    0,    1,    1,    3,    2,    1,    1,
    1,    2,    1,    2,    1,    0,    1,    2,    3,    5,
    8,    6,    7,    9,    2,    2,    4,    1,    1,    2,
    1,    4,    1,    2,    0,    1,    1,    2,    1,    2,
    1,    4,    1,    3,    4,    3,    1,    1,    2,    2,
    3,    3,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    2,    1,    1,    1,    1,
    1,    1,    2,    2,    1,    3,    1,    3,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,    1,    2,    0,   22,   23,    0,    0,
    7,    9,    0,    0,    0,    0,    0,   29,   30,   31,
    0,    0,    0,    4,   20,    0,   19,   68,   61,   67,
    0,    0,    0,    0,    0,   87,    0,    0,   33,    0,
    0,   59,    0,    0,    0,    8,    0,    0,    0,   11,
   28,    0,    0,    0,    0,    0,    0,    0,    0,    3,
   32,    0,   38,   60,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   45,   46,   10,   90,   92,   13,    0,    0,
   88,    0,    0,    0,    0,   26,    0,    0,   64,   39,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   66,    0,    0,
   93,    0,   94,    0,   17,    0,   16,    0,   48,   49,
    0,   56,    0,    0,    0,   62,   47,   65,    0,   96,
    0,   18,    0,   35,   27,    0,    0,    0,   40,   53,
    0,   58,    0,    0,   15,   34,    0,    0,    0,   42,
   54,    0,   43,    0,    0,    0,   52,   41,    0,   44,
};
static const YYINT yydgoto[] = {                          3,
    4,    5,    9,   10,   11,  142,   38,   39,   40,   12,
   50,  127,   26,   13,   94,   95,   41,   23,   42,  132,
  150,  151,  133,  134,   53,   45,   88,   89,   90,   91,
   92,  120,
};
static const YYINT yysindex[] = {                      -152,
 -171, -171,    0,    0,    0, -178,    0,    0, -229,  -21,
    0,    0, -111, -220, -146, 1308, -171,    0,    0,    0,
 -252,  -88, -209,    0,    0, -207,    0,    0,    0,    0,
  426,  426,  426,  426,  426,    0,  426, -204,    0, 1308,
    7,    0,   29,  -34,  797,    0,  -88, -237, -184,    0,
    0, -252,  -78,  902,  511,   50, 1053,   50,  928,    0,
    0,   58,    0,    0,  426,  426,  426,  426,  426,  426,
  426,  426,  426,  426,  426,  426,  426,  426,  426,  426,
  426,  132,    0,    0,    0,    0,    0,    0, -138,   82,
    0, -138,   54, -108,   94,    0,   80,  426,    0,    0,
 1193,  963, 1003,  476, 1053, 1224, 1224,  463,  463,  463,
  463,   -5,   -5,  -15,  -15,  -15,  -15,    0, 1193,   12,
    0, -138,    0, -114,    0, 1189,    0, -252,    0,    0,
  426,    0, -173,   80, 1098,    0,    0,    0,  426,    0,
 -237,    0, 1189,    0,    0, 1193,   80,  426,    0,    0,
 -141,    0,  426, 1193,    0,    0, -104, 1138,   80,    0,
    0, 1164,    0,   80, -100,   80,    0,    0,  -83,    0,
};
static const YYINT yyrindex[] = {                         0,
  104, -129,    0,    0,    0,   -8,    0,    0,    0,  -80,
    0,    0,    0,    0,    0,  -71,  -56,    0,    0,    0,
    0,  -53,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  -71,
    0,    0,  -69,  863,    0,    0,  -53,    0,    0,    0,
    0,  -55,  -33,    0,    0,    3,  175,   39,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  -42,  -40,
    0,  -38,    0,    0,  -23,    0,   -6,    0,    0,    0,
 1283,    0,    0, 1263, 1241,  848,  893,  471,  506,  541,
  607,  401,  436,   69,  107,  143,  366,    0,   27,    0,
    0,    0,    0,  -36,    0,  -25,    0,    0,    0,    0,
  210,    0,    0,  314,    0,    0,    0,    0,    0,    0,
    0,    0,  -25,    0,    0,  355,  -79,    0,    0,    0,
    0,    0,    0,   34,    0,    0,    0,    0,  -79,    0,
    0,    0,    0,   -6,    0,  -44,    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
    0,    0,  199,    0,  215,    0,    0,  193,  109,    0,
  194,    0,    0,  240,    0,    0,   18,  237,  -19,  122,
  106,    0,   32,   14,  833, 1537,  123,  -37,    0,    0,
    0,    0,
};
#define YYTABLESIZE 1690
static const YYINT yytable[] = {                         63,
   67,   95,   49,   63,   63,   12,   63,   63,   63,   63,
   63,   63,   66,   63,   18,   19,   95,   20,   89,   86,
   91,   87,   14,   64,   82,   63,   63,   63,   63,   43,
   22,   80,   16,   55,   82,   70,   78,   17,   47,   70,
   70,   79,   24,   70,   70,   70,   70,   70,   51,   70,
   52,  121,  138,   43,  123,  139,   66,   62,   60,   63,
   63,   70,   70,   70,   70,   63,   33,   97,   37,   96,
   97,   69,   93,   35,   98,   69,   69,   98,   81,   69,
   69,   69,   69,   69,  140,   69,    7,    8,   81,   82,
   63,   36,    6,    7,    8,   70,   70,   69,   69,   69,
   69,   74,  147,  148,  149,   74,   74,    1,    2,   74,
   74,   74,   74,   74,   64,   74,  100,   33,   86,   37,
   18,   19,   25,   20,   35,  122,   70,   74,   74,   74,
   74,   69,   69,    5,  159,  148,  160,   21,   21,   75,
   21,   21,   36,   75,   75,  145,  124,   75,   75,   75,
   75,   75,  128,   75,   34,   18,   19,  144,   20,   21,
   62,   74,   69,  125,  126,   75,   75,   75,   75,   33,
  141,   37,  118,  163,  156,   76,   35,  168,  157,   76,
   76,    6,    6,   76,   76,   76,   76,   76,  170,   76,
  165,   36,   74,   37,   36,  167,   48,  169,   55,   75,
   14,   76,   76,   76,   76,   34,   65,   86,   12,   12,
   21,   21,   86,   21,   21,   86,   24,   24,   86,   95,
   95,   89,   89,   91,   91,   14,   14,   55,   63,   63,
   75,   46,   61,   86,  143,   76,   55,   55,   63,   63,
   85,   63,   63,   63,   63,   15,   63,   63,   25,   25,
   65,   27,   63,   63,   63,  152,  161,   34,   21,   21,
   21,   21,    0,  155,   70,   70,   76,   86,   51,   55,
   55,   55,    0,    0,   70,   70,    0,   70,   70,   70,
   70,    0,   70,   70,    0,   28,   29,   30,   70,   70,
   70,    0,    0,    0,    0,    0,    0,    0,   86,    0,
   69,   69,   31,    0,    0,    0,    0,   32,    0,    0,
   69,   69,    0,   69,   69,   69,   69,    0,   69,   69,
    0,    0,    0,    0,   69,   69,   69,    0,    0,    0,
   74,   74,    0,    0,    0,    0,   28,   29,   30,    0,
   74,   74,    0,   74,   74,   74,   74,    0,   74,   74,
    0,    0,    0,   31,   74,   74,   74,    0,   32,    0,
    0,  129,  130,  131,    0,    5,    0,    0,   75,   75,
   21,   21,   57,   21,   21,    0,    0,    0,   75,   75,
    0,   75,   75,   75,   75,    0,   75,   75,   28,   29,
   30,    0,   75,   75,   75,    0,    0,    0,   71,    0,
    0,    0,   71,   71,   76,   76,   71,   71,   71,   71,
   71,    0,   71,   50,   76,   76,    0,   76,   76,   76,
   76,    0,   76,   76,   71,   71,   71,   71,   76,   76,
   76,    0,    0,   72,    0,    0,   86,   86,   72,    0,
    0,   72,    0,   72,   72,   72,   86,   86,    0,   86,
   86,   86,   86,    0,   86,   86,    0,    0,   71,   72,
   72,   72,   72,   33,    0,   37,    0,    0,   73,    0,
   35,   51,   51,   73,    0,    0,   73,    0,   73,   73,
   73,   51,    0,    0,    0,   51,   51,   51,   36,   71,
    0,    0,    0,   72,   73,   73,   73,   73,    0,   80,
    0,    0,   82,   77,   78,   76,    0,   77,   77,   79,
    0,   77,   80,   69,   77,   82,    0,   78,   76,    0,
   77,    0,   79,    0,   72,    0,    0,    0,   73,   77,
   77,   77,   77,    0,    0,   72,   71,   73,   78,    0,
    0,    0,    0,   78,    0,    0,   78,   80,   69,   78,
   82,   34,   78,   76,    0,   77,   81,   79,    0,   73,
    0,    0,    0,   77,   78,   78,   78,   78,    0,   81,
   72,   71,   73,   80,    0,   57,   57,    0,   80,    0,
    0,   80,    0,    0,   80,   57,    0,    0,    0,   57,
   57,   57,    0,    0,   77,    0,    0,    0,   78,   80,
   80,   80,   80,    0,   81,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   50,   50,    0,    0,
    0,    0,    0,    0,    0,    0,   50,   71,   71,   78,
   50,   50,   50,   80,   68,    0,    0,   71,   71,   79,
   71,   71,   71,   71,   79,   71,   71,   79,    0,    0,
   79,   71,   71,   71,    0,    0,    0,    0,    0,    0,
    0,    0,   72,   72,   80,   79,   79,   79,   79,    0,
    0,    0,   72,   72,    0,   72,   72,   72,   72,    0,
   72,   72,   28,   29,   30,    0,   72,   72,   72,    0,
    0,    0,    0,    0,    0,    0,    0,   73,   73,   79,
    0,    0,    0,    0,    0,    0,    0,   73,   73,    0,
   73,   73,   73,   73,    0,   73,   73,    0,    0,    0,
    0,   73,   73,   73,    0,    0,    0,    0,    0,    0,
   79,    0,   77,   77,    0,    0,    0,    0,    0,    0,
    0,    0,   77,   77,    0,   77,   77,   77,   77,    0,
   77,   77,    0,    0,    0,    0,   77,   77,   77,    0,
    0,   70,   74,   75,    0,    0,    0,   78,   78,    0,
    0,    0,    0,    0,    0,    0,    0,   78,   78,    0,
   78,   78,   78,   78,    0,   78,   78,    0,    0,    0,
   98,   78,   78,   78,    0,    0,   70,   74,   75,    0,
    0,    0,   80,   80,    0,    0,    0,    0,    0,    0,
    0,    0,   80,   80,    0,   80,   80,   80,   80,    0,
   80,   80,    0,    0,    0,    0,   80,   80,   80,   84,
    0,    0,    0,   80,   69,    0,   82,    0,   78,   76,
    0,   77,    0,   79,    0,    0,    0,    0,   44,    0,
    0,    0,    0,    0,    0,   83,   72,   71,   73,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   79,   79,
    0,    0,   44,    0,    0,   44,    0,    0,   79,   79,
   81,   79,   79,   79,   79,   81,   79,   79,   81,    0,
   81,   81,   79,   79,   79,   63,    0,    0,    0,   63,
   63,    0,   63,    0,   63,   63,   81,   63,   81,   63,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   68,   63,   63,   63,   63,   82,    0,    0,    0,   44,
   82,    0,    0,   82,    0,    0,   82,    0,   80,   69,
   81,   82,    0,   78,   76,    0,   77,    0,   79,    0,
    0,   82,    0,   82,    0,    0,   63,    0,   44,    0,
    0,   72,   71,   73,   80,   69,   44,   82,   99,   78,
   76,   81,   77,    0,   79,   44,    0,    0,    0,   44,
    0,    0,    0,    0,    0,   82,   63,   72,   71,   73,
    0,   44,    0,    0,    0,   81,   44,    0,   44,   80,
   69,    0,   82,    0,   78,   76,    0,   77,    0,   79,
    0,    0,    0,    0,    0,    0,   82,    0,    0,    0,
    0,   81,   72,   71,   73,   68,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   80,
   69,    0,   82,    0,   78,   76,    0,   77,    0,   79,
    0,   68,    0,    0,    0,  136,   81,    0,    0,    0,
    0,  137,   72,   71,   73,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   70,   74,   75,    0,   68,    0,    0,   80,
    0,    0,   82,    0,   78,   76,   81,   77,    0,   79,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   81,
   81,    0,   72,   71,   73,    0,    0,    0,    0,   81,
   81,    0,   81,   81,   81,   81,   68,   81,   81,    0,
    0,    0,    0,   81,   80,   69,    0,   82,    0,   78,
   76,    0,   77,    0,   79,    0,   81,    0,   63,   63,
   63,    0,    0,    0,   82,   82,    0,   72,   71,   73,
    0,    0,    0,    0,   82,   82,    0,   82,   82,   82,
   82,    0,   82,   82,   80,   69,   97,   82,   82,   78,
   76,    0,   77,    0,   79,    0,    0,   70,   74,   75,
    0,   81,    0,    0,    0,    0,    0,   72,   71,   73,
   80,   69,    0,   82,    0,   78,   76,    0,   77,    0,
   79,    0,    0,   70,   74,   75,    0,    0,    0,    0,
    0,   68,    0,   72,   71,   73,   33,    0,   37,   80,
   69,   81,   82,   35,   78,   76,    0,   77,    0,   79,
    0,    0,    0,    0,    0,    0,    0,    0,   70,   74,
   75,   36,   72,   71,   73,    0,    0,   81,    0,    0,
   80,   68,    0,   82,    0,   78,   76,    0,   77,    0,
   79,    0,    0,   84,    0,    0,    0,    0,   84,    0,
    0,   84,    0,   72,   84,   73,   81,   68,   70,   74,
   75,    0,    0,    0,    0,   85,    0,    0,    0,   84,
    0,    0,    0,   85,    0,    0,   85,    0,    0,    0,
    0,    0,    0,    0,   34,   83,   68,   81,    0,    0,
    0,   85,    0,   83,    0,    0,   83,    0,    0,    0,
    0,    0,    0,   84,    0,    0,    0,    0,   70,   74,
   75,   83,    0,    0,    0,   33,    0,   37,    0,    0,
    0,    0,   35,    0,    0,   85,    0,    0,    0,    0,
    0,    0,    0,    0,   84,    0,    0,    0,    0,    0,
   36,    0,    0,    0,    0,   83,    0,    0,  153,    0,
    0,    0,    0,   70,   74,   75,   85,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  164,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   70,   74,   75,    0,    0,    0,    0,
    0,    0,    0,   34,    0,    0,  166,    0,    0,    0,
    0,    0,    0,    0,    0,   28,   29,   30,    0,   70,
   74,   75,    0,    0,    0,   18,   19,    0,   20,    0,
    0,    0,   31,    0,    0,    0,    0,   32,    0,    0,
  129,  130,  131,    0,    0,    0,    0,    0,   70,   74,
   75,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   84,   84,    0,    0,    0,    0,    0,    0,
   74,   75,   84,   84,    0,   84,   84,   84,   84,    0,
   84,   84,    0,    0,   85,   85,    0,    0,    0,    0,
    0,    0,    0,    0,   85,   85,    0,   85,   85,   85,
   85,    0,   85,   85,   83,   83,    0,    0,    0,    0,
    0,    0,    0,    0,   83,   83,    0,   83,   83,   83,
   83,    0,   83,   83,   28,   29,   30,   54,   55,   56,
   57,   58,    0,   59,   18,   19,    0,   20,    0,    0,
    0,   31,    0,    0,    0,    0,   32,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  101,  102,  103,  104,  105,  106,  107,  108,  109,
  110,  111,  112,  113,  114,  115,  116,  117,  119,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  135,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  146,    0,    0,
    0,    0,    0,    0,    0,  154,    0,    0,    0,    0,
    0,    0,    0,    0,  158,    0,    0,    0,    0,  162,
};
static const YYINT yycheck[] = {                         33,
   35,   44,   91,   37,   38,   59,   40,   41,   42,   43,
   44,   45,   91,   47,  267,  268,   59,  270,   59,  257,
   59,  259,   59,   43,   40,   59,   60,   61,   62,   16,
   13,   37,  262,   59,   40,   33,   42,   59,   21,   37,
   38,   47,  263,   41,   42,   43,   44,   45,  258,   47,
  258,   89,   41,   40,   92,   44,   91,   40,  263,   93,
   94,   59,   60,   61,   62,   59,   38,   41,   40,   52,
   44,   33,  257,   45,   41,   37,   38,   44,   94,   41,
   42,   43,   44,   45,  122,   47,  265,  266,   94,   40,
  124,   63,  264,  265,  266,   93,   94,   59,   60,   61,
   62,   33,  276,  277,  278,   37,   38,  260,  261,   41,
   42,   43,   44,   45,  134,   47,   59,   38,  257,   40,
  267,  268,  269,  270,   45,   44,  124,   59,   60,   61,
   62,   93,   94,  263,  276,  277,  278,  267,  268,   33,
  270,  271,   63,   37,   38,  128,   93,   41,   42,   43,
   44,   45,   59,   47,  126,  267,  268,  126,  270,  271,
  143,   93,  124,  272,  273,   59,   60,   61,   62,   38,
  285,   40,   41,  278,  143,   33,   45,  278,  147,   37,
   38,  262,  263,   41,   42,   43,   44,   45,  272,   47,
  159,  263,  124,  263,   63,  164,  285,  166,  278,   93,
    2,   59,   60,   61,   62,  126,  285,   33,  262,  263,
  267,  268,   38,  270,  271,   41,  272,  273,   44,  262,
  263,  262,  263,  262,  263,  262,  263,  272,  262,  263,
  124,   17,   40,   59,  126,   93,  262,  263,  272,  273,
   47,  275,  276,  277,  278,    6,  280,  281,  272,  273,
  285,   15,  286,  287,  288,  134,  151,  126,  267,  268,
  269,  270,   -1,  141,  262,  263,  124,   93,   59,  276,
  277,  278,   -1,   -1,  272,  273,   -1,  275,  276,  277,
  278,   -1,  280,  281,   -1,  257,  258,  259,  286,  287,
  288,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  124,   -1,
  262,  263,  274,   -1,   -1,   -1,   -1,  279,   -1,   -1,
  272,  273,   -1,  275,  276,  277,  278,   -1,  280,  281,
   -1,   -1,   -1,   -1,  286,  287,  288,   -1,   -1,   -1,
  262,  263,   -1,   -1,   -1,   -1,  257,  258,  259,   -1,
  272,  273,   -1,  275,  276,  277,  278,   -1,  280,  281,
   -1,   -1,   -1,  274,  286,  287,  288,   -1,  279,   -1,
   -1,  282,  283,  284,   -1,  262,   -1,   -1,  262,  263,
  267,  268,   59,  270,  271,   -1,   -1,   -1,  272,  273,
   -1,  275,  276,  277,  278,   -1,  280,  281,  257,  258,
  259,   -1,  286,  287,  288,   -1,   -1,   -1,   33,   -1,
   -1,   -1,   37,   38,  262,  263,   41,   42,   43,   44,
   45,   -1,   47,   59,  272,  273,   -1,  275,  276,  277,
  278,   -1,  280,  281,   59,   60,   61,   62,  286,  287,
  288,   -1,   -1,   33,   -1,   -1,  262,  263,   38,   -1,
   -1,   41,   -1,   43,   44,   45,  272,  273,   -1,  275,
  276,  277,  278,   -1,  280,  281,   -1,   -1,   93,   59,
   60,   61,   62,   38,   -1,   40,   -1,   -1,   33,   -1,
   45,  262,  263,   38,   -1,   -1,   41,   -1,   43,   44,
   45,  272,   -1,   -1,   -1,  276,  277,  278,   63,  124,
   -1,   -1,   -1,   93,   59,   60,   61,   62,   -1,   37,
   -1,   -1,   40,   33,   42,   43,   -1,   45,   38,   47,
   -1,   41,   37,   38,   44,   40,   -1,   42,   43,   -1,
   45,   -1,   47,   -1,  124,   -1,   -1,   -1,   93,   59,
   60,   61,   62,   -1,   -1,   60,   61,   62,   33,   -1,
   -1,   -1,   -1,   38,   -1,   -1,   41,   37,   38,   44,
   40,  126,   42,   43,   -1,   45,   94,   47,   -1,  124,
   -1,   -1,   -1,   93,   59,   60,   61,   62,   -1,   94,
   60,   61,   62,   33,   -1,  262,  263,   -1,   38,   -1,
   -1,   41,   -1,   -1,   44,  272,   -1,   -1,   -1,  276,
  277,  278,   -1,   -1,  124,   -1,   -1,   -1,   93,   59,
   60,   61,   62,   -1,   94,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  262,  263,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  272,  262,  263,  124,
  276,  277,  278,   93,  124,   -1,   -1,  272,  273,   33,
  275,  276,  277,  278,   38,  280,  281,   41,   -1,   -1,
   44,  286,  287,  288,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  262,  263,  124,   59,   60,   61,   62,   -1,
   -1,   -1,  272,  273,   -1,  275,  276,  277,  278,   -1,
  280,  281,  257,  258,  259,   -1,  286,  287,  288,   -1,
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
   -1,   45,   -1,   47,   -1,   -1,   -1,   -1,   16,   -1,
   -1,   -1,   -1,   -1,   -1,   59,   60,   61,   62,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  262,  263,
   -1,   -1,   40,   -1,   -1,   43,   -1,   -1,  272,  273,
   33,  275,  276,  277,  278,   38,  280,  281,   41,   -1,
   94,   44,  286,  287,  288,   33,   -1,   -1,   -1,   37,
   38,   -1,   40,   -1,   42,   43,   59,   45,   61,   47,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  124,   59,   60,   61,   62,   33,   -1,   -1,   -1,   97,
   38,   -1,   -1,   41,   -1,   -1,   44,   -1,   37,   38,
   93,   40,   -1,   42,   43,   -1,   45,   -1,   47,   -1,
   -1,   59,   -1,   61,   -1,   -1,   94,   -1,  126,   -1,
   -1,   60,   61,   62,   37,   38,  134,   40,   41,   42,
   43,  124,   45,   -1,   47,  143,   -1,   -1,   -1,  147,
   -1,   -1,   -1,   -1,   -1,   93,  124,   60,   61,   62,
   -1,  159,   -1,   -1,   -1,   94,  164,   -1,  166,   37,
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
  273,   -1,  275,  276,  277,  278,  124,  280,  281,   -1,
   -1,   -1,   -1,  286,   37,   38,   -1,   40,   -1,   42,
   43,   -1,   45,   -1,   47,   -1,   94,   -1,  286,  287,
  288,   -1,   -1,   -1,  262,  263,   -1,   60,   61,   62,
   -1,   -1,   -1,   -1,  272,  273,   -1,  275,  276,  277,
  278,   -1,  280,  281,   37,   38,  275,   40,  286,   42,
   43,   -1,   45,   -1,   47,   -1,   -1,  286,  287,  288,
   -1,   94,   -1,   -1,   -1,   -1,   -1,   60,   61,   62,
   37,   38,   -1,   40,   -1,   42,   43,   -1,   45,   -1,
   47,   -1,   -1,  286,  287,  288,   -1,   -1,   -1,   -1,
   -1,  124,   -1,   60,   61,   62,   38,   -1,   40,   37,
   38,   94,   40,   45,   42,   43,   -1,   45,   -1,   47,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  286,  287,
  288,   63,   60,   61,   62,   -1,   -1,   94,   -1,   -1,
   37,  124,   -1,   40,   -1,   42,   43,   -1,   45,   -1,
   47,   -1,   -1,   33,   -1,   -1,   -1,   -1,   38,   -1,
   -1,   41,   -1,   60,   44,   62,   94,  124,  286,  287,
  288,   -1,   -1,   -1,   -1,   33,   -1,   -1,   -1,   59,
   -1,   -1,   -1,   41,   -1,   -1,   44,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  126,   33,  124,   94,   -1,   -1,
   -1,   59,   -1,   41,   -1,   -1,   44,   -1,   -1,   -1,
   -1,   -1,   -1,   93,   -1,   -1,   -1,   -1,  286,  287,
  288,   59,   -1,   -1,   -1,   38,   -1,   40,   -1,   -1,
   -1,   -1,   45,   -1,   -1,   93,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  124,   -1,   -1,   -1,   -1,   -1,
   63,   -1,   -1,   -1,   -1,   93,   -1,   -1,  281,   -1,
   -1,   -1,   -1,  286,  287,  288,  124,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  275,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  286,  287,  288,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  126,   -1,   -1,  273,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  257,  258,  259,   -1,  286,
  287,  288,   -1,   -1,   -1,  267,  268,   -1,  270,   -1,
   -1,   -1,  274,   -1,   -1,   -1,   -1,  279,   -1,   -1,
  282,  283,  284,   -1,   -1,   -1,   -1,   -1,  286,  287,
  288,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  262,  263,   -1,   -1,   -1,   -1,   -1,   -1,
  287,  288,  272,  273,   -1,  275,  276,  277,  278,   -1,
  280,  281,   -1,   -1,  262,  263,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  272,  273,   -1,  275,  276,  277,
  278,   -1,  280,  281,  262,  263,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  272,  273,   -1,  275,  276,  277,
  278,   -1,  280,  281,  257,  258,  259,   31,   32,   33,
   34,   35,   -1,   37,  267,  268,   -1,  270,   -1,   -1,
   -1,  274,   -1,   -1,   -1,   -1,  279,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   65,   66,   67,   68,   69,   70,   71,   72,   73,
   74,   75,   76,   77,   78,   79,   80,   81,   82,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   98,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  131,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  139,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  148,   -1,   -1,   -1,   -1,  153,
};
#define YYFINAL 3
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 307
#define YYUNDFTOKEN 342
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
"NIL","DECLS","DECL","FUNCTYPE","QUALIFIER","DECLATTR","VARS","VAR","BODY",
"BODYVARS","RETURN_EXPR","ELIFS","INSTRS_INSTRTERM","INSTRS","TWO_INTEGERS",
"MORE_INTEGERS","ARGS",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : file",
"file : program",
"file : module",
"program : PROGRAM decls START bodyprincipal END",
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
"instr : FOR expr UNTIL expr STEP expr DO block DONE",
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
"expr : STR",
"expr : INTEGER",
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
#line 205 "gram.y"

char **yynames =
#if YYDEBUG > 0
		 (char**)yyname;
#else
		 0;
#endif
#line 739 "y.tab.c"

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
	{ yyval.n = nilNode(NIL); }
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
	{ yyval.n = binNode(QUALIFIER, yystack.l_mark[-3].n, binNode(VAR, yystack.l_mark[-1].n, uniNode(DECLATTR, yystack.l_mark[0].n))); }
break;
case 11:
#line 63 "gram.y"
	{ yyval.n = binNode(QUALIFIER, yystack.l_mark[-2].n, binNode(VAR, yystack.l_mark[-1].n, uniNode(DECLATTR, yystack.l_mark[0].n))); }
break;
case 12:
#line 66 "gram.y"
	{ yyval.n = nilNode(NIL); }
break;
case 13:
#line 67 "gram.y"
	{ yyval.n = uniNode(DECLATTR, yystack.l_mark[0].n); }
break;
case 14:
#line 68 "gram.y"
	{ yyval.n = nilNode(NIL); }
break;
case 15:
#line 69 "gram.y"
	{ yyval.n = uniNode(DECLATTR, yystack.l_mark[0].n); }
break;
case 16:
#line 71 "gram.y"
	{ yyval.n = binNode(QUALIFIER, yystack.l_mark[-4].n, binNode(FUNCTYPE, yystack.l_mark[-3].n, binNode(ID, strNode(ID, yystack.l_mark[-2].s), binNode(VARS, yystack.l_mark[-1].n, uniNode(END, yystack.l_mark[0].n))))); }
break;
case 17:
#line 74 "gram.y"
	{ yyval.n = nilNode(DONE); }
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
	{ yyval.n = nilNode(VOID); }
break;
case 21:
#line 82 "gram.y"
	{ yyval.n = nilNode(NIL); }
break;
case 22:
#line 83 "gram.y"
	{ yyval.n = nilNode(PUBLIC); }
break;
case 23:
#line 84 "gram.y"
	{ yyval.n = nilNode(FORWARD); }
break;
case 24:
#line 87 "gram.y"
	{ yyval.n = nilNode(NIL); }
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
	{ yyval.n = nilNode(NUMBER); }
break;
case 30:
#line 99 "gram.y"
	{ yyval.n = nilNode(ARRAY); }
break;
case 31:
#line 100 "gram.y"
	{ yyval.n = nilNode(STRING); }
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
	{ yyval.n = binNode(BODY, yystack.l_mark[-1].n, yystack.l_mark[0].n); }
break;
case 35:
#line 108 "gram.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 36:
#line 111 "gram.y"
	{ yyval.n = nilNode(NIL); }
break;
case 37:
#line 112 "gram.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 38:
#line 115 "gram.y"
	{ yyval.n = yystack.l_mark[-1].n; }
break;
case 39:
#line 116 "gram.y"
	{ yyval.n = binNode(BODYVARS, yystack.l_mark[-2].n, yystack.l_mark[-1].n); }
break;
case 40:
#line 119 "gram.y"
	{ yyval.n = binNode(IF, yystack.l_mark[-3].n, yystack.l_mark[-1].n); }
break;
case 41:
#line 120 "gram.y"
	{ yyval.n = binNode(IF, yystack.l_mark[-6].n, binNode(THEN, yystack.l_mark[-4].n, binNode(ELIF, yystack.l_mark[-3].n, uniNode(ELSE, yystack.l_mark[-1].n)))); }
break;
case 42:
#line 121 "gram.y"
	{ yyval.n = binNode(IF, yystack.l_mark[-4].n, binNode(THEN, yystack.l_mark[-2].n, uniNode(ELIF, yystack.l_mark[-1].n))); }
break;
case 43:
#line 122 "gram.y"
	{ yyval.n = binNode(IF, yystack.l_mark[-5].n, binNode(THEN, yystack.l_mark[-3].n, uniNode(ELSE, yystack.l_mark[-1].n))); }
break;
case 44:
#line 123 "gram.y"
	{ yyval.n = binNode(FOR, yystack.l_mark[-7].n, binNode(UNTIL, yystack.l_mark[-5].n, binNode(STEP, yystack.l_mark[-3].n, uniNode(DO, yystack.l_mark[-1].n)))); }
break;
case 45:
#line 124 "gram.y"
	{ yyval.n = yystack.l_mark[-1].n; }
break;
case 46:
#line 125 "gram.y"
	{ yyval.n = yystack.l_mark[-1].n; }
break;
case 47:
#line 126 "gram.y"
	{ yyval.n = binNode('#', yystack.l_mark[-3].n, yystack.l_mark[-1].n); }
break;
case 48:
#line 129 "gram.y"
	{ yyval.n = nilNode(REPEAT); }
break;
case 49:
#line 130 "gram.y"
	{ yyval.n = nilNode(STOP); }
break;
case 50:
#line 131 "gram.y"
	{ yyval.n = uniNode(RETURN_EXPR, yystack.l_mark[0].n); }
break;
case 51:
#line 132 "gram.y"
	{ yyval.n = nilNode(RETURN); }
break;
case 52:
#line 135 "gram.y"
	{ yyval.n = binNode(ELIF, yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 53:
#line 138 "gram.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 54:
#line 139 "gram.y"
	{ yyval.n = binNode(ELIFS, yystack.l_mark[-1].n, yystack.l_mark[0].n); }
break;
case 55:
#line 142 "gram.y"
	{ yyval.n = nilNode(NIL); }
break;
case 56:
#line 143 "gram.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 57:
#line 144 "gram.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 58:
#line 145 "gram.y"
	{ yyval.n = binNode(INSTRS_INSTRTERM, yystack.l_mark[-1].n, yystack.l_mark[0].n); }
break;
case 59:
#line 148 "gram.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 60:
#line 149 "gram.y"
	{ yyval.n = binNode(INSTRS, yystack.l_mark[-1].n, yystack.l_mark[0].n); }
break;
case 61:
#line 152 "gram.y"
	{ yyval.n = strNode(ID, yystack.l_mark[0].s); }
break;
case 62:
#line 153 "gram.y"
	{ yyval.n = binNode('[', yystack.l_mark[-3].n, yystack.l_mark[-1].n); }
break;
case 63:
#line 156 "gram.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 64:
#line 157 "gram.y"
	{ yyval.n = yystack.l_mark[-1].n; }
break;
case 65:
#line 158 "gram.y"
	{ yyval.n = binNode('(', yystack.l_mark[-3].n, yystack.l_mark[-1].n); }
break;
case 66:
#line 159 "gram.y"
	{ yyval.n = yystack.l_mark[-2].n; }
break;
case 67:
#line 160 "gram.y"
	{ yyval.n = strNode(STR, yystack.l_mark[0].s); }
break;
case 68:
#line 161 "gram.y"
	{ yyval.n = intNode(INTEGER, yystack.l_mark[0].i); }
break;
case 69:
#line 162 "gram.y"
	{ yyval.n = uniNode(UMINUS, yystack.l_mark[0].n); }
break;
case 70:
#line 163 "gram.y"
	{ yyval.n = uniNode(ADDR, yystack.l_mark[0].n); }
break;
case 71:
#line 164 "gram.y"
	{ yyval.n = binNode('^', yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 72:
#line 165 "gram.y"
	{ yyval.n = binNode('+', yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 73:
#line 166 "gram.y"
	{ yyval.n = binNode('-', yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 74:
#line 167 "gram.y"
	{ yyval.n = binNode('*', yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 75:
#line 168 "gram.y"
	{ yyval.n = binNode('/', yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 76:
#line 169 "gram.y"
	{ yyval.n = binNode('%', yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 77:
#line 170 "gram.y"
	{ yyval.n = binNode('<', yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 78:
#line 171 "gram.y"
	{ yyval.n = binNode('>', yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 79:
#line 172 "gram.y"
	{ yyval.n = binNode(GE, yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 80:
#line 173 "gram.y"
	{ yyval.n = binNode(LE, yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 81:
#line 174 "gram.y"
	{ yyval.n = binNode(NE, yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 82:
#line 175 "gram.y"
	{ yyval.n = binNode('=', yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 83:
#line 176 "gram.y"
	{ yyval.n = binNode(ATTR, yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 84:
#line 177 "gram.y"
	{ yyval.n = binNode('&', yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 85:
#line 178 "gram.y"
	{ yyval.n = binNode('|', yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 86:
#line 179 "gram.y"
	{ yyval.n = uniNode('~', yystack.l_mark[0].n); }
break;
case 87:
#line 180 "gram.y"
	{ yyval.n = nilNode('?'); }
break;
case 88:
#line 183 "gram.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 89:
#line 184 "gram.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 90:
#line 187 "gram.y"
	{ yyval.n = intNode(INTEGER, yystack.l_mark[0].i); }
break;
case 91:
#line 190 "gram.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 92:
#line 191 "gram.y"
	{ yyval.n = strNode(STR, yystack.l_mark[0].s); }
break;
case 93:
#line 194 "gram.y"
	{ yyval.n = binNode(TWO_INTEGERS, yystack.l_mark[-1].n, yystack.l_mark[0].n); }
break;
case 94:
#line 195 "gram.y"
	{ yyval.n = binNode(MORE_INTEGERS, yystack.l_mark[-1].n, yystack.l_mark[0].n); }
break;
case 95:
#line 197 "gram.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 96:
#line 198 "gram.y"
	{ yyval.n = binNode(',', yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 97:
#line 201 "gram.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 98:
#line 202 "gram.y"
	{ yyval.n = binNode(ARGS, yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
#line 1333 "y.tab.c"
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
