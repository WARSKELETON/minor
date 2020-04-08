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
   19,   19,   19,   33,   19,   19,   19,   19,   20,   20,
   20,   20,   21,   22,   22,   23,   23,   23,   23,   24,
   24,   25,   25,   26,   26,   26,   26,   26,   26,   26,
   26,   26,   26,   26,   26,   26,   26,   26,   26,   26,
   26,   26,   26,   26,   26,   26,   26,   26,   27,   27,
   28,   30,   30,   31,   31,   29,   29,   32,   32,
};
static const YYINT yylen[] = {                            2,
    1,    1,    5,    3,    0,    1,    1,    3,    1,    4,
    3,    0,    2,    3,    5,    6,    1,    2,    1,    1,
    0,    1,    1,    0,    1,    1,    3,    2,    1,    1,
    1,    2,    1,    2,    1,    0,    1,    2,    3,    5,
    8,    6,    7,    0,   10,    2,    2,    4,    1,    1,
    2,    1,    4,    1,    2,    0,    1,    1,    2,    1,
    2,    1,    4,    1,    3,    4,    3,    1,    1,    2,
    2,    3,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    2,    1,    1,    1,
    1,    1,    1,    2,    2,    1,    3,    1,    3,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,    1,    2,    0,   22,   23,    0,    0,
    7,    9,    0,    0,    0,    0,    0,   29,   30,   31,
    0,    0,    0,    4,   20,    0,   19,   91,   62,   93,
    0,    0,    0,    0,    0,   88,    0,    0,   33,    0,
    0,   60,    0,    0,    0,    0,   68,    0,    8,    0,
    0,    0,   11,   28,    0,    0,    0,    0,    0,    0,
    0,    0,    3,   32,    0,   38,   61,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   46,   47,   94,   95,   10,
   13,    0,    0,   89,    0,    0,    0,   26,    0,    0,
   65,   39,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   67,
    0,    0,    0,    0,   17,    0,   16,    0,   49,   50,
    0,   57,    0,    0,    0,   63,   48,   66,    0,   97,
    0,   18,    0,   35,   27,    0,    0,    0,   40,   54,
    0,   59,    0,    0,   15,   34,    0,    0,    0,   42,
   55,    0,   43,    0,    0,   44,   53,   41,    0,    0,
   45,
};
static const YYINT yydgoto[] = {                          3,
    4,    5,    9,   10,   11,  142,   38,   39,   40,   12,
   53,  127,   26,   13,   96,   97,   41,   23,   42,  132,
  150,  151,  133,  134,   56,   45,   91,   46,   93,   47,
   48,  122,  169,
};
static const YYINT yysindex[] = {                      -222,
  -99,  -99,    0,    0,    0, -178,    0,    0, -247,  -37,
    0,    0, -216, -232, -175,  876,  -99,    0,    0,    0,
 -250,  -89, -199,    0,    0, -185,    0,    0,    0,    0,
  970,  970,  970,  970,  970,    0,  970, -188,    0,  876,
   43,    0,  219,  -34,  767, -172,    0, -172,    0,  -89,
 -191, -152,    0,    0, -250,  -88,  817,  934,   67, 1155,
   67,  945,    0,    0,   55,    0,    0,  970,  970,  970,
  970,  970,  970,  970,  970,  970,  970,  970,  970,  970,
  970,  970,  970,  970,  501,    0,    0,    0,    0,    0,
    0, -172,   87,    0,   47, -163,   84,    0, 1149,  970,
    0,    0, 1229,  974, 1069, 1240, 1155,  174,  174,  137,
  137,  137,  137,   -5,   -5,  -16,  -16,  -16,  -16,    0,
 1229,  -11, -172, -138,    0,  319,    0, -250,    0,    0,
  970,    0,  -76, 1149, 1080,    0,    0,    0,  970,    0,
 -191,    0,  319,    0,    0, 1229, 1149,  970,    0,    0,
   -7,    0,  970, 1229,    0,    0, -121, 1111, 1149,    0,
    0, 1203,    0, 1149, -100,    0,    0,    0, 1149,  -85,
    0,
};
static const YYINT yyrindex[] = {                         0,
   61, -142,    0,    0,    0, -108,    0,    0,    0, -139,
    0,    0,    0,    0,    0,  -80, -129,    0,    0,    0,
    0,  -40,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  -80,
    0,    0,  -75,  778,    0,  -33,    0,    3,    0,  -40,
    0,    0,    0,    0, -122,   39,    0,    0,   75, 1270,
  111,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  -38,  -36,    0,    0,    0,  -97,    0,   10,    0,
    0,    0, 1321,    0,    0, 1193, 1292,  808,  905,  511,
  612,  647,  682,  441,  476,  148,  334,  371,  406,    0,
   12,    0,    0,  -25,    0,   -1,    0,    0,    0,    0,
   31,    0,    0,  285,    0,    0,    0,    0,    0,    0,
    0,    0,   -1,    0,    0,  784,  -84,    0,    0,    0,
    0,    0,    0,   26,    0,    0,    0,    0,  -84,    0,
    0,    0,    0,   10,    0,    0,    0,    0,  -74,    0,
    0,
};
static const YYINT yygindex[] = {                         0,
    0,    0,  201,    0,  189,    0,    0,  172,   89,    0,
  163,    0,    0,  214,    0,    0,   90,  213,  -30,   98,
   95,    0,  328,    9, 1303, 1543,  108,   23,    0,  -35,
    0,    0,    0,
};
#define YYTABLESIZE 1696
static const YYINT yytable[] = {                         69,
   70,   52,   69,   69,   69,   96,   69,   69,   69,   69,
   69,   69,   67,   69,   16,   94,   18,   19,   12,   20,
   96,   17,   90,   85,   43,   69,   69,   69,   69,  138,
   24,   83,  139,   14,   85,   92,   81,    1,    2,   92,
   92,   82,   92,   92,   92,   92,   92,   92,   43,   92,
   18,   19,   98,   20,   21,   98,   69,   56,   54,   69,
   69,   92,   92,   92,   92,   28,   99,   30,   88,   99,
   89,   64,   55,   92,   63,   64,   64,   84,   64,   64,
   64,   64,   64,   64,   28,   64,    7,    8,   84,   52,
   69,   18,   19,   25,   20,   92,   92,   64,   64,   64,
   64,   66,   22,   67,   95,   94,   85,   71,  125,  126,
   50,   71,   71,  102,   88,   71,   71,   71,   71,   71,
    5,   71,    6,    6,   21,   21,   92,   21,   21,   65,
  123,   64,   64,   71,   71,   71,   71,   21,   21,  124,
   21,   21,  128,   70,   98,  140,  141,   70,   70,   24,
   24,   70,   70,   70,   70,   70,  163,   70,   21,   21,
   21,   21,   64,   92,    6,    7,    8,   71,   71,   70,
   70,   70,   70,   83,   25,   25,   85,  168,   81,   79,
   75,   80,   36,   82,   75,   75,  171,   37,   75,   75,
   75,   75,   75,   56,   75,   51,   68,   56,   71,  147,
  148,  149,   14,   70,   70,   49,   75,   75,   75,   75,
   83,   64,   90,   85,  143,   81,   79,  145,   80,   15,
   82,   12,   12,   96,   96,   90,   90,   27,   69,   69,
   84,  152,   65,   75,   70,   76,   14,   14,   69,   69,
   75,   69,   69,   69,   69,  161,   69,   69,  155,    0,
   68,    0,   69,   69,   69,    0,   33,    0,   37,    0,
   56,   56,    0,   35,   92,   92,    0,   84,  159,  148,
  160,   75,    0,    0,   92,   92,    0,   92,   92,   92,
   92,   36,   92,   92,    0,   56,   56,   56,   92,   92,
   92,    0,   52,   52,    0,    0,    0,    0,    0,    0,
   64,   64,   52,    0,    0,    0,   52,   52,   52,    0,
   64,   64,    0,   64,   64,   64,   64,    0,   64,   64,
    0,    0,    5,    0,   64,   64,   64,   21,   21,    0,
   21,   21,    0,    0,    0,    0,   71,   71,    0,    0,
    0,    0,    0,   58,   34,    0,   71,   71,    0,   71,
   71,   71,   71,    0,   71,   71,   33,    0,   37,    0,
   71,   71,   71,   35,    0,    0,   76,    0,    0,    0,
   76,   76,   70,   70,   76,   76,   76,   76,   76,    0,
   76,   36,   70,   70,    0,   70,   70,   70,   70,    0,
   70,   70,   76,   76,   76,   76,   70,   70,   70,    0,
    0,    0,    0,   77,    0,    0,    0,   77,   77,   75,
   75,   77,   77,   77,   77,   77,    0,   77,    0,   75,
   75,    0,   75,   75,   75,   75,   76,   75,   75,   77,
   77,   77,   77,   75,   75,   75,    0,    0,   72,    0,
    0,    0,   72,   72,   34,    0,   72,   72,   72,   72,
   72,    0,   72,  144,    0,    0,    0,   76,    0,    0,
   77,   78,    0,   77,   72,   72,   72,   72,    0,    0,
  156,    0,    0,   73,  157,   28,   29,   30,   73,    0,
    0,   73,    0,   73,   73,   73,  165,    0,    0,    0,
    0,  167,   31,    0,   77,    0,  170,   32,   72,   73,
   73,   73,   73,    0,    0,    0,    0,    0,   74,    0,
    0,    0,    0,   74,    0,    0,   74,    0,   74,   74,
   74,    0,    0,    0,    0,    0,    0,    0,    0,   72,
    0,    0,    0,   73,   74,   74,   74,   74,   33,    0,
   37,  120,    0,   78,    0,   35,   58,   58,   78,    0,
    0,   78,    0,    0,   78,    0,   58,    0,    0,    0,
   58,   58,   58,   36,   73,    0,    0,    0,   74,   78,
   78,   78,   78,    0,    0,   28,   29,   30,    0,    0,
    0,    0,    0,    0,    0,   18,   19,    0,   20,    0,
    0,    0,   31,    0,    0,   76,   76,   32,    0,   74,
  129,  130,  131,   78,    0,   76,   76,    0,   76,   76,
   76,   76,    0,   76,   76,    0,    0,    0,    0,   76,
   76,   76,    0,    0,    0,    0,   34,    0,    0,    0,
    0,    0,   77,   77,   78,    0,    0,    0,    0,    0,
    0,    0,   77,   77,   79,   77,   77,   77,   77,   79,
   77,   77,   79,    0,    0,   79,   77,   77,   77,    0,
    0,    0,    0,    0,    0,    0,    0,   72,   72,    0,
   79,   79,   79,   79,    0,    0,    0,   72,   72,   81,
   72,   72,   72,   72,   81,   72,   72,   81,    0,    0,
   81,   72,   72,   72,    0,    0,    0,    0,    0,    0,
    0,    0,   73,   73,   79,   81,   81,   81,   81,    0,
    0,    0,   73,   73,   80,   73,   73,   73,   73,   80,
   73,   73,   80,    0,    0,   80,   73,   73,   73,    0,
    0,    0,    0,    0,    0,   79,    0,   74,   74,   81,
   80,   80,   80,   80,    0,    0,    0,   74,   74,    0,
   74,   74,   74,   74,    0,   74,   74,   28,   29,   30,
    0,   74,   74,   74,    0,    0,    0,    0,    0,    0,
   81,    0,   78,   78,   80,    0,    0,    0,    0,    0,
    0,    0,   78,   78,    0,   78,   78,   78,   78,    0,
   78,   78,    0,    0,    0,    0,   78,   78,   78,   87,
    0,    0,    0,   83,   72,   80,   85,    0,   81,   79,
   64,   80,    0,   82,   64,   64,    0,   64,    0,   64,
   64,    0,   64,    0,   64,   86,   75,   74,   76,    0,
    0,    0,    0,    0,    0,    0,   64,   64,   64,   64,
   82,    0,   51,    0,    0,   82,    0,    0,   82,    0,
    0,   82,    0,   83,   72,    0,   85,    0,   81,   79,
   84,   80,    0,   82,    0,    0,   82,    0,   82,    0,
    0,   64,    0,   79,   79,    0,   75,   74,   76,    0,
    0,    0,    0,   79,   79,    0,   79,   79,   79,   79,
   71,   79,   79,    0,    0,    0,    0,   79,   79,   79,
   82,   64,    0,    0,    0,    0,    0,    0,   81,   81,
   84,    0,    0,   33,    0,   37,    0,    0,   81,   81,
   35,   81,   81,   81,   81,    0,   81,   81,    0,    0,
    0,   82,   81,   81,   81,    0,    0,   83,   36,    0,
   71,    0,   83,   80,   80,   83,    0,    0,   83,    0,
    0,    0,    0,   80,   80,    0,   80,   80,   80,   80,
    0,   80,   80,   83,    0,   83,    0,   80,   80,   80,
   83,   72,    0,   85,    0,   81,   79,    0,   80,    0,
   82,   83,   72,    0,   85,  101,   81,   79,    0,   80,
    0,   82,    0,   75,   74,   76,    0,   83,    0,    0,
    0,   34,    0,    0,   75,   74,   76,   33,    0,   37,
   83,   72,    0,   85,   35,   81,   79,    0,   80,    0,
   82,    0,    0,    0,    0,    0,    0,   84,   83,    0,
    0,    0,   36,   75,   74,   76,    0,    0,   84,    0,
    0,    0,    0,    0,    0,   51,   51,    0,    0,    0,
    0,    0,   73,   77,   78,   51,    0,   71,    0,   51,
   51,   51,    0,   64,   64,   64,  136,   84,   71,   82,
   82,    0,    0,    0,    0,    0,    0,    0,    0,   82,
   82,    0,   82,   82,   82,   82,    0,   82,   82,    0,
    0,   99,    0,   82,    0,   34,    0,   71,    0,    0,
    0,    0,   73,   77,   78,   83,   72,    0,   85,    0,
   81,   79,    0,   80,    0,   82,   83,   72,    0,   85,
    0,   81,   79,    0,   80,    0,   82,  137,   75,   74,
   76,    0,   28,   29,   30,    0,    0,    0,    0,   75,
   74,   76,   18,   19,    0,   20,    0,   83,   72,   31,
   85,    0,   81,   79,   32,   80,    0,   82,    0,    0,
    0,    0,   84,    0,    0,    0,   83,   83,    0,    0,
   75,   74,   76,   84,    0,    0,   83,   83,    0,   83,
   83,   83,   83,    0,   83,   83,   33,    0,   37,    0,
   83,   83,   71,   35,   85,    0,   81,   79,    0,   80,
    0,   82,    0,   71,   84,    0,    0,    0,    0,    0,
    0,   36,    0,  100,   75,   74,   76,    0,    0,   73,
   77,   78,    0,    0,    0,   86,   28,   29,   30,    0,
   73,   77,   78,   86,   71,    0,   86,    0,    0,   83,
   72,    0,   85,    0,   81,   79,    0,   80,   84,   82,
    0,   86,    0,    0,    0,    0,    0,    0,    0,   73,
   77,   78,   75,   74,   76,   83,   72,    0,   85,    0,
   81,   79,    0,   80,   34,   82,   83,   72,    0,   85,
    0,   81,   79,    0,   80,   86,   82,    0,   75,   74,
   76,    0,    0,    0,    0,    0,   84,    0,    0,   75,
   74,   76,   87,    0,    0,    0,    0,   87,    0,    0,
   87,    0,    0,   87,    0,    0,   86,    0,   44,    0,
    0,    0,   84,    0,   85,    0,   71,    0,   87,   85,
    0,    0,   85,   84,    0,   85,    0,    0,    0,    0,
    0,    0,   44,    0,    0,   44,    0,    0,    0,    0,
   85,    0,   71,   84,   73,   77,   78,    0,    0,    0,
  153,   84,   87,    0,   84,   73,   77,   78,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   84,
    0,    0,    0,    0,   85,  164,    0,    0,    0,    0,
    0,    0,    0,   87,    0,    0,   73,   77,   78,    0,
    0,   44,    0,    0,    0,   28,   29,   30,    0,    0,
    0,    0,    0,   84,    0,   85,    0,    0,    0,    0,
    0,    0,   31,    0,    0,    0,    0,   32,   44,    0,
  129,  130,  131,    0,    0,    0,   44,    0,    0,    0,
   73,   77,   78,    0,    0,   44,    0,    0,    0,   44,
    0,    0,    0,    0,   86,   86,    0,    0,    0,    0,
    0,   44,    0,    0,   86,   86,   44,   86,   86,   86,
   86,   44,   86,   86,    0,  166,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   73,   77,
   78,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   73,   77,   78,    0,    0,    0,
    0,    0,    0,    0,    0,   73,   77,   78,    0,    0,
    0,   87,   87,    0,    0,    0,    0,    0,    0,    0,
    0,   87,   87,    0,   87,   87,   87,   87,    0,   87,
   87,    0,    0,   85,   85,    0,    0,    0,    0,    0,
    0,    0,    0,   85,   85,    0,   85,   85,   85,   85,
    0,   85,   85,   57,   58,   59,   60,   61,    0,   62,
    0,    0,   84,   84,    0,    0,    0,    0,    0,    0,
    0,    0,   84,   84,    0,   84,   84,   84,   84,    0,
   84,   84,    0,    0,    0,    0,    0,    0,    0,    0,
  103,  104,  105,  106,  107,  108,  109,  110,  111,  112,
  113,  114,  115,  116,  117,  118,  119,  121,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  135,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  146,    0,    0,    0,    0,    0,    0,
    0,  154,    0,    0,    0,    0,    0,    0,    0,    0,
  158,    0,    0,    0,    0,  162,
};
static const YYINT yycheck[] = {                         33,
   35,   91,   91,   37,   38,   44,   40,   41,   42,   43,
   44,   45,   43,   47,  262,   51,  267,  268,   59,  270,
   59,   59,   59,   40,   16,   59,   60,   61,   62,   41,
  263,   37,   44,   59,   40,   33,   42,  260,  261,   37,
   38,   47,   40,   41,   42,   43,   44,   45,   40,   47,
  267,  268,   41,  270,  271,   44,   91,   59,  258,   93,
   94,   59,   60,   61,   62,  257,   41,  259,   46,   44,
   48,   33,  258,   51,  263,   37,   38,   94,   40,   41,
   42,   43,   44,   45,  257,   47,  265,  266,   94,   59,
  124,  267,  268,  269,  270,   93,   94,   59,   60,   61,
   62,   59,   13,  134,  257,  141,   40,   33,  272,  273,
   21,   37,   38,   59,   92,   41,   42,   43,   44,   45,
  263,   47,  262,  263,  267,  268,  124,  270,  271,   40,
   44,   93,   94,   59,   60,   61,   62,  267,  268,   93,
  270,  271,   59,   33,   55,  123,  285,   37,   38,  272,
  273,   41,   42,   43,   44,   45,  278,   47,  267,  268,
  269,  270,  124,  141,  264,  265,  266,   93,   94,   59,
   60,   61,   62,   37,  272,  273,   40,  278,   42,   43,
   33,   45,  263,   47,   37,   38,  272,  263,   41,   42,
   43,   44,   45,  278,   47,  285,  285,  272,  124,  276,
  277,  278,    2,   93,   94,   17,   59,   60,   61,   62,
   37,   40,   50,   40,  126,   42,   43,  128,   45,    6,
   47,  262,  263,  262,  263,  262,  263,   15,  262,  263,
   94,  134,  143,   60,  124,   62,  262,  263,  272,  273,
   93,  275,  276,  277,  278,  151,  280,  281,  141,   -1,
  285,   -1,  286,  287,  288,   -1,   38,   -1,   40,   -1,
  262,  263,   -1,   45,  262,  263,   -1,   94,  276,  277,
  278,  124,   -1,   -1,  272,  273,   -1,  275,  276,  277,
  278,   63,  280,  281,   -1,  276,  277,  278,  286,  287,
  288,   -1,  262,  263,   -1,   -1,   -1,   -1,   -1,   -1,
  262,  263,  272,   -1,   -1,   -1,  276,  277,  278,   -1,
  272,  273,   -1,  275,  276,  277,  278,   -1,  280,  281,
   -1,   -1,  262,   -1,  286,  287,  288,  267,  268,   -1,
  270,  271,   -1,   -1,   -1,   -1,  262,  263,   -1,   -1,
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
   45,   -1,   47,  126,   -1,   -1,   -1,  124,   -1,   -1,
  287,  288,   -1,   93,   59,   60,   61,   62,   -1,   -1,
  143,   -1,   -1,   33,  147,  257,  258,  259,   38,   -1,
   -1,   41,   -1,   43,   44,   45,  159,   -1,   -1,   -1,
   -1,  164,  274,   -1,  124,   -1,  169,  279,   93,   59,
   60,   61,   62,   -1,   -1,   -1,   -1,   -1,   33,   -1,
   -1,   -1,   -1,   38,   -1,   -1,   41,   -1,   43,   44,
   45,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  124,
   -1,   -1,   -1,   93,   59,   60,   61,   62,   38,   -1,
   40,   41,   -1,   33,   -1,   45,  262,  263,   38,   -1,
   -1,   41,   -1,   -1,   44,   -1,  272,   -1,   -1,   -1,
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
   42,   43,   -1,   45,  126,   47,   37,   38,   -1,   40,
   -1,   42,   43,   -1,   45,   93,   47,   -1,   60,   61,
   62,   -1,   -1,   -1,   -1,   -1,   94,   -1,   -1,   60,
   61,   62,   33,   -1,   -1,   -1,   -1,   38,   -1,   -1,
   41,   -1,   -1,   44,   -1,   -1,  124,   -1,   16,   -1,
   -1,   -1,   94,   -1,   33,   -1,  124,   -1,   59,   38,
   -1,   -1,   41,   94,   -1,   44,   -1,   -1,   -1,   -1,
   -1,   -1,   40,   -1,   -1,   43,   -1,   -1,   -1,   -1,
   59,   -1,  124,   33,  286,  287,  288,   -1,   -1,   -1,
  281,   41,   93,   -1,   44,  286,  287,  288,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   59,
   -1,   -1,   -1,   -1,   93,  275,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  124,   -1,   -1,  286,  287,  288,   -1,
   -1,   99,   -1,   -1,   -1,  257,  258,  259,   -1,   -1,
   -1,   -1,   -1,   93,   -1,  124,   -1,   -1,   -1,   -1,
   -1,   -1,  274,   -1,   -1,   -1,   -1,  279,  126,   -1,
  282,  283,  284,   -1,   -1,   -1,  134,   -1,   -1,   -1,
  286,  287,  288,   -1,   -1,  143,   -1,   -1,   -1,  147,
   -1,   -1,   -1,   -1,  262,  263,   -1,   -1,   -1,   -1,
   -1,  159,   -1,   -1,  272,  273,  164,  275,  276,  277,
  278,  169,  280,  281,   -1,  273,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  286,  287,
  288,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  286,  287,  288,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  286,  287,  288,   -1,   -1,
   -1,  262,  263,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  272,  273,   -1,  275,  276,  277,  278,   -1,  280,
  281,   -1,   -1,  262,  263,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  272,  273,   -1,  275,  276,  277,  278,
   -1,  280,  281,   31,   32,   33,   34,   35,   -1,   37,
   -1,   -1,  262,  263,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  272,  273,   -1,  275,  276,  277,  278,   -1,
  280,  281,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   68,   69,   70,   71,   72,   73,   74,   75,   76,   77,
   78,   79,   80,   81,   82,   83,   84,   85,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  100,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  131,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  139,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  148,   -1,   -1,   -1,   -1,  153,
};
#define YYFINAL 3
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 307
#define YYUNDFTOKEN 343
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
0,0,0,0,0,0,0,"illegal-symbol",
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
	if (t1 == 2 && t2 == 11) return 0; /* string := int* */
	if (t1 == 2 && arg2->attrib == INTEGER && arg2->value.i == 0)
		return 0; /* string := 0 */
	if (t1 > 10 && t1 < 20 && arg2->attrib == INTEGER && arg2->value.i == 0)
		return 0; /* pointer := 0 */
	return 1;
}
#line 775 "y.tab.c"

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
	{ ; }
break;
case 2:
#line 49 "gram.y"
	{ ; }
break;
case 3:
#line 52 "gram.y"
	{ yyval.n = binNode(PROGRAM, yystack.l_mark[-3].n, yystack.l_mark[-1].n); }
break;
case 4:
#line 55 "gram.y"
	{ yyval.n = uniNode(MODULE, yystack.l_mark[-1].n); }
break;
case 5:
#line 58 "gram.y"
	{ yyval.n = nilNode(NIL); }
break;
case 6:
#line 59 "gram.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 7:
#line 62 "gram.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 8:
#line 63 "gram.y"
	{ yyval.n = binNode(DECLS, yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 9:
#line 66 "gram.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 10:
#line 67 "gram.y"
	{ yyval.n = binNode(QUALIFIER, yystack.l_mark[-3].n, binNode(VAR, yystack.l_mark[-1].n, uniNode(DECLATTR, yystack.l_mark[0].n))); }
break;
case 11:
#line 68 "gram.y"
	{ yyval.n = binNode(QUALIFIER, yystack.l_mark[-2].n, binNode(VAR, yystack.l_mark[-1].n, uniNode(DECLATTR, yystack.l_mark[0].n))); }
break;
case 12:
#line 71 "gram.y"
	{ yyval.n = nilNode(NIL); }
break;
case 13:
#line 72 "gram.y"
	{ yyval.n = uniNode(DECLATTR, yystack.l_mark[0].n); }
break;
case 14:
#line 73 "gram.y"
	{ yyval.n = nilNode(NIL); }
break;
case 15:
#line 74 "gram.y"
	{ yyval.n = uniNode(DECLATTR, yystack.l_mark[0].n); }
break;
case 16:
#line 76 "gram.y"
	{ yyval.n = binNode(QUALIFIER, yystack.l_mark[-4].n, binNode(FUNCTYPE, yystack.l_mark[-3].n, binNode(ID, strNode(ID, yystack.l_mark[-2].s), binNode(VARS, yystack.l_mark[-1].n, uniNode(END, yystack.l_mark[0].n))))); }
break;
case 17:
#line 79 "gram.y"
	{ yyval.n = nilNode(DONE); }
break;
case 18:
#line 80 "gram.y"
	{ yyval.n = uniNode(DO, yystack.l_mark[0].n); }
break;
case 19:
#line 83 "gram.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 20:
#line 84 "gram.y"
	{ yyval.n = nilNode(VOID); }
break;
case 21:
#line 87 "gram.y"
	{ yyval.n = nilNode(NIL); }
break;
case 22:
#line 88 "gram.y"
	{ yyval.n = nilNode(PUBLIC); }
break;
case 23:
#line 89 "gram.y"
	{ yyval.n = nilNode(FORWARD); }
break;
case 24:
#line 92 "gram.y"
	{ yyval.n = nilNode(NIL); }
break;
case 25:
#line 93 "gram.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 26:
#line 96 "gram.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 27:
#line 97 "gram.y"
	{ yyval.n = binNode(VARS, yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 28:
#line 100 "gram.y"
	{ yyval.n = binNode(VAR, yystack.l_mark[-1].n, strNode(ID, yystack.l_mark[0].s)); }
break;
case 29:
#line 103 "gram.y"
	{ yyval.n = nilNode(NUMBER); }
break;
case 30:
#line 104 "gram.y"
	{ yyval.n = nilNode(ARRAY); }
break;
case 31:
#line 105 "gram.y"
	{ yyval.n = nilNode(STRING); }
break;
case 32:
#line 108 "gram.y"
	{ yyval.n = binNode(BODY, yystack.l_mark[-1].n, yystack.l_mark[0].n); }
break;
case 33:
#line 109 "gram.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 34:
#line 112 "gram.y"
	{ yyval.n = binNode(BODY, yystack.l_mark[-1].n, yystack.l_mark[0].n); }
break;
case 35:
#line 113 "gram.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 36:
#line 116 "gram.y"
	{ yyval.n = nilNode(NIL); }
break;
case 37:
#line 117 "gram.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 38:
#line 120 "gram.y"
	{ yyval.n = yystack.l_mark[-1].n; }
break;
case 39:
#line 121 "gram.y"
	{ yyval.n = binNode(BODYVARS, yystack.l_mark[-2].n, yystack.l_mark[-1].n); }
break;
case 40:
#line 124 "gram.y"
	{ yyval.n = binNode(IF, yystack.l_mark[-3].n, yystack.l_mark[-1].n); }
break;
case 41:
#line 125 "gram.y"
	{ yyval.n = binNode(IF, yystack.l_mark[-6].n, binNode(THEN, yystack.l_mark[-4].n, binNode(ELIF, yystack.l_mark[-3].n, uniNode(ELSE, yystack.l_mark[-1].n)))); }
break;
case 42:
#line 126 "gram.y"
	{ yyval.n = binNode(IF, yystack.l_mark[-4].n, binNode(THEN, yystack.l_mark[-2].n, uniNode(ELIF, yystack.l_mark[-1].n))); }
break;
case 43:
#line 127 "gram.y"
	{ yyval.n = binNode(IF, yystack.l_mark[-5].n, binNode(THEN, yystack.l_mark[-3].n, uniNode(ELSE, yystack.l_mark[-1].n))); }
break;
case 44:
#line 128 "gram.y"
	{ ncicl++; }
break;
case 45:
#line 128 "gram.y"
	{ yyval.n = binNode(FOR, yystack.l_mark[-8].n, binNode(UNTIL, yystack.l_mark[-6].n, binNode(STEP, yystack.l_mark[-4].n, uniNode(DO, yystack.l_mark[-2].n)))); ncicl--; }
break;
case 46:
#line 129 "gram.y"
	{ yyval.n = yystack.l_mark[-1].n; }
break;
case 47:
#line 130 "gram.y"
	{ yyval.n = yystack.l_mark[-1].n; }
break;
case 48:
#line 131 "gram.y"
	{ yyval.n = binNode('#', yystack.l_mark[-3].n, yystack.l_mark[-1].n); }
break;
case 49:
#line 134 "gram.y"
	{ yyval.n = nilNode(REPEAT); if (ncicl <= 0) yyerror("invalid repeat argument"); }
break;
case 50:
#line 135 "gram.y"
	{ yyval.n = nilNode(STOP); if (ncicl <= 0) yyerror("invalid stop argument"); }
break;
case 51:
#line 136 "gram.y"
	{ yyval.n = uniNode(RETURN_EXPR, yystack.l_mark[0].n); }
break;
case 52:
#line 137 "gram.y"
	{ yyval.n = nilNode(RETURN); }
break;
case 53:
#line 140 "gram.y"
	{ yyval.n = binNode(ELIF, yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 54:
#line 143 "gram.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 55:
#line 144 "gram.y"
	{ yyval.n = binNode(ELIFS, yystack.l_mark[-1].n, yystack.l_mark[0].n); }
break;
case 56:
#line 147 "gram.y"
	{ yyval.n = nilNode(NIL); }
break;
case 57:
#line 148 "gram.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 58:
#line 149 "gram.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 59:
#line 150 "gram.y"
	{ yyval.n = binNode(INSTRS_INSTRTERM, yystack.l_mark[-1].n, yystack.l_mark[0].n); }
break;
case 60:
#line 153 "gram.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 61:
#line 154 "gram.y"
	{ yyval.n = binNode(INSTRS, yystack.l_mark[-1].n, yystack.l_mark[0].n); }
break;
case 62:
#line 157 "gram.y"
	{ yyval.n = strNode(ID, yystack.l_mark[0].s); }
break;
case 63:
#line 158 "gram.y"
	{ yyval.n = binNode('[', yystack.l_mark[-3].n, yystack.l_mark[-1].n); }
break;
case 64:
#line 161 "gram.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 65:
#line 162 "gram.y"
	{ yyval.n = yystack.l_mark[-1].n; }
break;
case 66:
#line 163 "gram.y"
	{ yyval.n = binNode('(', yystack.l_mark[-3].n, yystack.l_mark[-1].n); }
break;
case 67:
#line 164 "gram.y"
	{ yyval.n = yystack.l_mark[-2].n; }
break;
case 68:
#line 165 "gram.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 69:
#line 166 "gram.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 70:
#line 167 "gram.y"
	{ yyval.n = uniNode(UMINUS, yystack.l_mark[0].n); }
break;
case 71:
#line 168 "gram.y"
	{ yyval.n = uniNode(ADDR, yystack.l_mark[0].n); }
break;
case 72:
#line 169 "gram.y"
	{ yyval.n = binNode('^', yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 73:
#line 170 "gram.y"
	{ yyval.n = binNode('+', yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 74:
#line 171 "gram.y"
	{ yyval.n = binNode('-', yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 75:
#line 172 "gram.y"
	{ yyval.n = binNode('*', yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 76:
#line 173 "gram.y"
	{ yyval.n = binNode('/', yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 77:
#line 174 "gram.y"
	{ yyval.n = binNode('%', yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 78:
#line 175 "gram.y"
	{ yyval.n = binNode('<', yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 79:
#line 176 "gram.y"
	{ yyval.n = binNode('>', yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 80:
#line 177 "gram.y"
	{ yyval.n = binNode(GE, yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 81:
#line 178 "gram.y"
	{ yyval.n = binNode(LE, yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 82:
#line 179 "gram.y"
	{ yyval.n = binNode(NE, yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 83:
#line 180 "gram.y"
	{ yyval.n = binNode('=', yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 84:
#line 181 "gram.y"
	{ yyval.n = binNode(ATTR, yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 85:
#line 182 "gram.y"
	{ yyval.n = binNode('&', yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 86:
#line 183 "gram.y"
	{ yyval.n = binNode('|', yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 87:
#line 184 "gram.y"
	{ yyval.n = uniNode('~', yystack.l_mark[0].n); }
break;
case 88:
#line 185 "gram.y"
	{ yyval.n = nilNode('?'); }
break;
case 89:
#line 188 "gram.y"
	{ yyval.n = yystack.l_mark[0].n; yyval.n->info = yystack.l_mark[0].n->info; }
break;
case 90:
#line 189 "gram.y"
	{ yyval.n = yystack.l_mark[0].n; yyval.n->info = yystack.l_mark[0].n->info; }
break;
case 91:
#line 192 "gram.y"
	{ yyval.n = intNode(INTEGER, yystack.l_mark[0].i); yyval.n->info = 1; }
break;
case 92:
#line 195 "gram.y"
	{ yyval.n = yystack.l_mark[0].n; yyval.n->info = yystack.l_mark[0].n->info; }
break;
case 93:
#line 196 "gram.y"
	{ yyval.n = strNode(STR, yystack.l_mark[0].s); yyval.n->info = 2; }
break;
case 94:
#line 199 "gram.y"
	{ yyval.n = binNode(TWO_INTEGERS, yystack.l_mark[-1].n, yystack.l_mark[0].n); yyval.n->info = 2; }
break;
case 95:
#line 200 "gram.y"
	{ yyval.n = binNode(MORE_INTEGERS, yystack.l_mark[-1].n, yystack.l_mark[0].n); yyval.n->info = 2; }
break;
case 96:
#line 202 "gram.y"
	{ yyval.n = yystack.l_mark[0].n; yyval.n->info = yystack.l_mark[0].n->info; }
break;
case 97:
#line 203 "gram.y"
	{ yyval.n = binNode(',', yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = 2; }
break;
case 98:
#line 206 "gram.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 99:
#line 207 "gram.y"
	{ yyval.n = binNode(ARGS, yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
#line 1373 "y.tab.c"
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
