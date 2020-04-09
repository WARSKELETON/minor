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
void enter(int pub, int typ, char *name);
void function(int pub, Node *type, char *name, Node *body,int enter);
int nostring(Node *arg1, Node *arg2);
void noarray(Node *arg1, Node *arg2);
void sametype(Node *arg1, Node *arg2);
int intonly(Node *arg);
int noassign(Node *arg1, Node *arg2);
static int ncicl;
static char *fpar;
#line 25 "gram.y"
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
#line 57 "y.tab.c"

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
#define RETURN_EXPR 299
#define ELIFS 300
#define BLOCK 301
#define INSTRS 302
#define TWO_INTEGERS 303
#define MORE_INTEGERS 304
#define ARGS 305
#define LOCAL 306
#define CALL 307
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    0,    1,    1,    2,    2,    3,    3,    4,    4,
    4,    4,    4,    4,    4,    4,    4,   31,    9,   32,
    9,   33,    9,   34,    9,   10,   10,   11,   11,   12,
   12,   13,   13,   14,   14,   14,   15,   15,   15,   15,
   16,   16,   16,    6,    6,    5,    5,    7,    7,    8,
    8,   17,   17,   17,   17,   35,   17,   17,   17,   17,
   18,   18,   18,   18,   19,   20,   20,   21,   21,   21,
   21,   22,   22,   23,   23,   24,   24,   24,   24,   24,
   24,   24,   24,   24,   24,   24,   24,   24,   24,   24,
   24,   24,   24,   24,   24,   24,   24,   24,   24,   24,
   25,   25,   26,   28,   28,   29,   29,   27,   27,   30,
   30,
};
static const YYINT yylen[] = {                            2,
    1,    1,    5,    4,    3,    2,    1,    3,    1,    5,
    4,    2,    3,    2,    4,    1,    3,    0,    7,    0,
    6,    0,    6,    0,    5,    1,    2,    1,    1,    1,
    1,    1,    3,    2,    2,    5,    2,    2,    5,    2,
    1,    1,    1,    2,    1,    2,    1,    0,    1,    2,
    3,    5,    8,    6,    7,    0,   10,    2,    2,    4,
    1,    1,    2,    1,    4,    1,    2,    0,    1,    1,
    2,    1,    2,    1,    4,    1,    3,    4,    3,    1,
    1,    2,    2,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    3,    2,    1,
    1,    1,    1,    1,    1,    2,    2,    1,    3,    1,
    3,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,    1,    2,    0,    0,   30,   31,    0,
    0,    0,    0,    0,    7,    9,    0,    0,    6,    0,
  103,    0,  105,    0,    0,    0,    0,    0,  100,    0,
    0,   45,    0,    0,   72,    0,    0,    0,    0,   80,
    0,   41,   42,   29,   43,    0,    0,   28,   38,    0,
   37,    0,    0,    0,    0,    0,    0,    5,    0,    0,
    0,    0,   74,    0,    0,   82,    0,    4,   44,    0,
   50,   73,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   58,
   59,  106,  107,    0,    0,    0,    0,    0,    8,    0,
    0,   17,    0,    0,  101,   79,    0,    0,    0,    0,
   77,   51,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   15,    3,    0,   11,    0,   78,    0,
   61,   62,    0,   69,    0,    0,    0,   75,   60,    0,
    0,    0,    0,   32,   26,    0,   25,    0,    0,   39,
   10,  109,    0,    0,    0,    0,   52,   66,    0,   71,
    0,   35,    0,   34,    0,   21,   27,    0,   47,    0,
   23,    0,    0,    0,   54,   67,    0,    0,   33,   46,
   19,   55,    0,    0,   56,    0,   65,   53,    0,   36,
    0,   57,
};
static const YYINT yydgoto[] = {                          3,
    4,    5,   14,   15,  177,   31,   32,   33,   16,  157,
   46,   17,  153,  154,   18,   48,   35,  144,  168,  169,
  145,  146,   60,   38,  102,   39,  104,   40,   41,  108,
  158,  130,  159,  131,  199,
};
static const YYINT yysindex[] = {                      -158,
  776, -125,    0,    0,    0, 1299,  314,    0,    0, -241,
 -233, -228, -161,  -56,    0,    0, -215, -248,    0,  -43,
    0,   27,    0,  501,  501, -207,  501,  501,    0,  501,
 -220,    0, 1299,   26,    0, 1244,  -34,  767, -179,    0,
 -179,    0,    0,    0,    0, -171, -103,    0,    0,   20,
    0, -160, 1299,  258, -161, -138, -236,    0,  219,  -85,
  817,  934,    0,   59,  446,    0,  945,    0,    0,  115,
    0,    0,  501,  501,  501,  501,  501,  501,  501,  501,
  501,  501,  501,  501,  501,  501,  501,  501,  501,    0,
    0,    0,    0,    0, -101, -179, -236,  -76,    0, -107,
 -236,    0, -179,  144,    0,    0, 1155,   -2, 1131,  501,
    0,    0, 1155,  974, 1014, 1181,  446,  174,  174,  286,
  286,  286,  286,   68,   68,  100,  100,  100,  100,  -91,
  -90,    0,  103,    0,    0, -236,    0, -179,    0,  501,
    0,    0,  501,    0, -117, 1131, 1064,    0,    0,  -60,
  -57,  -36,  -41,    0,    0,  319,    0,  -91,  -90,    0,
    0,    0, 1155, 1155, 1131,  501,    0,    0,  -63,    0,
  501,    0,  142,    0,  -91,    0,    0,  319,    0,  -41,
    0,  -29, 1085, 1131,    0,    0, 1112, -179,    0,    0,
    0,    0, 1131,  -28,    0,  109,    0,    0, 1131,    0,
  -16,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,    0,   -5,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  -35,    0,    0,
    0,  -33,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   -5,    0,    0,    4,  778,    0,    3,    0,
   39,    0,    0,    0,    0,    0,    0,    0,    0,  -39,
    0,  -25,   -5,    0,    0,    7,    0,    0,    0,   75,
    0,    0,    0,  111, 1212,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0, -199,    0,    0,    0,    0,    0,   11,
    0,    0,  -37,   33,    0,    0,   80,    0,  -15,    0,
    0,    0, 1273,    0,    0, 1253, 1232,  808,  905,  511,
  612,  647,  682,  441,  476,  148,  334,  371,  406,    0,
    0,  133,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   31,    0,    0,  285,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   35,    0,    0,    0,    0,
    0,    0,   85,  737,   -7,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   35,    0,    0,
    0,    0,    0,   -7,    0,    0,    0,    0,    0,    0,
    0,    0,  -15,    0,    0,    0,    0,    0,    5,    0,
    0,    0,
};
static const YYINT yygindex[] = {                         0,
    0,    0,  283,  232,    0,  234,  255,  136,    0, -121,
  252,  293,  146,  130,  498,    0,  -23,  160,  141,    0,
   19,   98, 1418, 1557,  -82,   -8,    0,  -22,    0,    0,
    0,    0,    0,    0,    0,
};
#define YYTABLESIZE 1728
static const YYINT yytable[] = {                         74,
   75,   74,   54,   74,   74,   74,  108,   74,   74,   74,
   74,   74,   72,   74,  134,   54,   49,  175,  137,   40,
   21,  108,   23,   16,   50,   74,   74,   74,   74,   51,
   92,  176,   93,   14,  105,   81,   57,  181,  139,   81,
   81,  140,   68,   81,   81,   81,   81,   81,  103,   81,
   63,   10,   11,  161,   12,   55,   74,   74,  191,   74,
   74,   81,   81,   81,   81,   12,   59,   20,   20,   13,
   20,  104,   24,   24,  105,  104,  104,   21,  105,  104,
  104,  104,  104,  104,   71,  104,   94,  133,  103,   64,
   74,  102,  103,   68,   92,   81,   81,  104,  104,  104,
  104,    1,    2,   36,   88,   10,   11,   76,   12,   86,
   96,   76,   76,  105,   87,   76,   76,   76,   76,   76,
  110,   76,   72,  110,   97,  111,   81,  103,  111,  162,
   36,  104,  104,   76,   76,   76,   76,   19,    7,    8,
    9,   10,   11,   83,   12,   13,  101,   83,   83,   74,
   36,   83,   83,   83,   83,   83,  132,   83,  165,  166,
  167,   89,  104,   42,   43,   44,   45,   76,   76,   83,
   83,   83,   83,  112,  179,  150,  151,  136,  152,  196,
   87,  155,  156,  182,   87,   87,  135,  138,   87,   87,
   87,   87,   87,   89,   87,  160,  190,  172,   76,   73,
  173,  200,  194,   83,   83,   53,   87,   87,   87,   87,
   88,  197,  184,  166,  185,   86,   84,  201,   85,   58,
   87,  174,   40,   40,  108,  108,   16,   16,   74,   74,
  155,  156,  188,   80,   83,   81,   14,   14,   74,   74,
   87,   74,   74,   74,   74,   40,   74,   74,  192,  198,
   73,   74,   74,   74,   74,  202,   26,   48,   30,  106,
   68,   68,   68,   28,   81,   81,   49,   89,   12,   12,
   68,   87,   13,   13,   81,   81,   68,   81,   81,   81,
   81,   29,   81,   81,   20,   99,   98,   69,   81,   81,
   81,  178,   64,   64,  102,  102,   68,   68,   95,   47,
  104,  104,   64,  180,  189,  170,   64,   64,   64,  186,
  104,  104,    0,  104,  104,  104,  104,    0,  104,  104,
    0,    0,   88,    0,  104,  104,  104,   86,   84,    0,
   85,    0,   87,    0,    0,    0,   76,   76,    0,    0,
    0,    0,    0,   70,   27,    0,   76,   76,    0,   76,
   76,   76,   76,    0,   76,   76,   26,    0,   30,    0,
   76,   76,   76,   28,    0,    0,   88,    0,    0,    0,
   88,   88,   83,   83,   88,   88,   88,   88,   88,   89,
   88,   29,   83,   83,    0,   83,   83,   83,   83,    0,
   83,   83,   88,   88,   88,   88,   83,   83,   83,   18,
   18,    0,   18,   89,   22,   22,    0,   89,   89,   87,
   87,   89,   89,   89,   89,   89,    0,   89,    0,   87,
   87,    0,   87,   87,   87,   87,   88,   87,   87,   89,
   89,   89,   89,   87,   87,   87,    0,    0,   84,    0,
    0,    0,   84,   84,   27,    0,   84,   84,   84,   84,
   84,    0,   84,    0,    0,    0,    0,   88,    0,    0,
   82,   83,    0,   89,   84,   84,   84,   84,    0,    0,
    0,    0,    0,   85,    0,   21,   22,   23,   85,    0,
    0,   85,   88,   85,   85,   85,    0,   86,   84,    0,
   85,    0,   87,    0,   89,    0,    0,    0,   84,   85,
   85,   85,   85,   34,    0,   80,   79,   81,   86,    0,
   52,    0,    0,   86,   56,    0,   86,    0,   86,   86,
   86,    7,    8,    9,   10,   11,    0,   12,   13,   84,
   70,    0,    0,   85,   86,   86,   86,   86,   26,   89,
   30,    0,    0,   90,    0,   28,   70,   70,   90,    0,
   34,   90,  100,    0,   90,    0,   70,    0,    0,    0,
   70,   70,   70,   29,   85,    0,    0,    0,   86,   90,
   90,   90,   90,    0,    0,   21,   22,   23,    8,    9,
   42,   43,   44,   45,    0,   10,   11,    0,   12,    0,
    0,    0,   24,    0,    0,   88,   88,   25,    0,   86,
  141,  142,  143,   90,    0,   88,   88,    0,   88,   88,
   88,   88,    0,   88,   88,    0,    0,    0,    0,   88,
   88,   88,    0,    0,    0,    0,   27,    0,    0,    0,
    0,    0,   89,   89,   90,    0,    0,    0,    0,    0,
    0,    0,   89,   89,   91,   89,   89,   89,   89,   91,
   89,   89,   91,   34,    0,   91,   89,   89,   89,    0,
    0,    0,    0,    0,    0,    0,    0,   84,   84,    0,
   91,   91,   91,   91,    0,   70,    0,   84,   84,   93,
   84,   84,   84,   84,   93,   84,   84,   93,    0,    0,
   93,   84,   84,   84,    0,    0,    0,    0,    0,    0,
    0,    0,   85,   85,   91,   93,   93,   93,   93,    0,
    0,    0,   85,   85,   92,   85,   85,   85,   85,   92,
   85,   85,   92,    0,    0,   92,   85,   85,   85,    0,
    0,   78,   82,   83,    0,   91,    0,   86,   86,   93,
   92,   92,   92,   92,    0,    0,    0,   86,   86,    0,
   86,   86,   86,   86,    0,   86,   86,   21,   22,   23,
    0,   86,   86,   86,    0,    0,    0,    0,    0,    0,
   93,    0,   90,   90,   92,    0,    0,    0,    0,    0,
    0,    0,   90,   90,    0,   90,   90,   90,   90,    0,
   90,   90,    0,    0,    0,   63,   90,   90,   90,   91,
    0,    0,    0,   88,   77,   92,    0,    0,   86,   84,
   76,   85,    0,   87,   76,   76,    0,    0,    0,   76,
   76,    0,   76,    0,   76,   90,   80,   79,   81,    0,
    0,    0,    0,    0,    0,    0,   76,   76,   76,   76,
   94,    0,    0,    0,    0,   94,    0,    0,   94,    0,
    0,   94,    0,   88,   77,    0,    0,    0,   86,   84,
   89,   85,    0,   87,    0,    0,   94,    0,   94,    0,
    0,   76,    0,   91,   91,    0,   80,   79,   81,    0,
    0,    0,    0,   91,   91,    0,   91,   91,   91,   91,
   76,   91,   91,    0,    0,    0,    0,   91,   91,   91,
   94,   76,    0,    0,    0,    0,    0,    0,   93,   93,
   89,    0,    0,    0,    0,    0,    0,    0,   93,   93,
    0,   93,   93,   93,   93,    0,   93,   93,    0,    0,
    0,   94,   93,   93,   93,    0,    0,   95,    0,    0,
   76,    0,   95,   92,   92,   95,    0,    0,   95,    0,
    0,    0,    0,   92,   92,    0,   92,   92,   92,   92,
    0,   92,   92,   95,    0,   95,    0,   92,   92,   92,
   88,   77,    0,    0,    0,   86,   84,    0,   85,    0,
   87,   88,   77,    0,    0,  111,   86,   84,    0,   85,
    0,   87,    0,   80,   79,   81,    0,   95,   63,   63,
    0,    0,    0,    0,   80,   79,   81,    0,   63,    0,
   88,   77,   63,   63,   63,   86,   84,    0,   85,    0,
   87,    0,    0,    0,    0,    0,    0,   89,   95,    0,
    0,    0,    0,   80,   79,   81,    0,    6,   89,    7,
    8,    9,   10,   11,    0,   12,   13,    0,    0,    0,
   88,   77,   78,   82,   83,   86,   84,   76,   85,    0,
   87,    0,    0,   76,   76,   76,  148,   89,   76,   94,
   94,    0,  149,   80,   79,   81,    0,    0,    0,   94,
   94,    0,   94,   94,   94,   94,    0,   94,   94,    0,
    0,  109,    0,   94,    0,    0,    0,   76,    0,    0,
   88,   77,   78,   82,   83,   86,   84,   89,   85,    0,
   87,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   88,   77,   80,   79,   81,   86,   84,    0,   85,
    0,   87,    0,    0,    0,    0,    0,   76,    0,    0,
    0,    0,    0,    0,   80,   79,   81,    0,   88,   77,
    0,    0,    0,   86,   84,    0,   85,   89,   87,    0,
    0,    0,    0,    0,    0,    0,   95,   95,   26,    0,
   30,   80,   79,   81,    0,   28,   95,   95,   89,   95,
   95,   95,   95,    0,   95,   95,    0,   76,    0,    0,
   95,   88,   77,   29,    0,    0,   86,   84,    0,   85,
    0,   87,    0,    0,    0,   89,    0,    0,   76,    0,
    0,    0,    0,  110,   80,   79,   81,   88,   77,   78,
   82,   83,   86,   84,    0,   85,    0,   87,    0,    0,
   78,   82,   83,    0,    0,   76,    0,    0,    0,    0,
   80,   79,   81,    0,   99,    0,    0,    0,   89,   99,
    0,    0,   99,    0,    0,   99,   27,    0,    0,   78,
   82,   83,    0,    0,   97,    0,    0,    0,    0,   97,
   99,    0,   97,    0,   89,   97,    0,    0,   76,    0,
    0,   26,    0,   30,    0,   98,    0,    0,   28,    0,
   97,    0,    0,   98,    0,    0,   98,    0,    0,   78,
   82,   83,    0,    0,   99,   96,   29,    0,    0,    0,
    0,   98,    0,   96,    0,    0,   96,    0,    0,    0,
    0,    0,    0,    0,   97,    0,    0,    0,    0,    0,
    0,   96,    0,    0,    0,   99,   26,    0,   30,    0,
    0,    0,    0,   28,  171,   98,    0,    0,    0,   78,
   82,   83,    0,    0,    0,   97,    0,    0,    0,  193,
    0,   29,    0,    0,    0,   96,    0,    0,    0,   27,
   78,   82,   83,    0,    0,    0,   98,    0,    0,    0,
    0,    0,    0,    0,  195,    0,    0,   21,   22,   23,
    0,    0,    0,    0,    0,    0,    0,   78,   82,   83,
    0,    0,    0,    0,   24,    0,    0,    0,    0,   25,
    0,    0,  141,  142,  143,    0,    0,    0,    0,    0,
    0,    0,    0,   37,   27,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   78,   82,   83,   64,    0,    0,    0,    0,    0,    0,
   37,    0,    0,   37,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   78,   82,   83,    0,
   37,    0,    0,   99,   99,    0,    0,    0,    0,    0,
    0,    0,    0,   99,   99,    0,   99,   99,   99,   99,
    0,   99,   99,   97,   97,    0,    0,    0,    0,    0,
   21,   22,   23,   97,   97,    0,   97,   97,   97,   97,
    0,   97,   97,    0,   98,   98,    0,   24,    0,    0,
    0,    0,   25,    0,   98,   98,   37,   98,   98,   98,
   98,    0,   98,   98,   96,   96,    0,    0,    0,    0,
    0,    0,    0,    0,   96,   96,    0,   96,   96,   96,
   96,    0,   96,   96,    0,   21,   22,   23,    0,    0,
    0,    0,    0,   37,    0,   10,   11,    0,   12,    0,
    0,    0,   24,   37,    0,    0,    0,   25,    0,    0,
   61,   62,   37,   65,   66,    0,   67,    0,    0,    0,
    0,    0,    0,    0,    0,   37,    0,    0,    0,    0,
    0,   37,    0,    0,    0,    0,    0,    0,    0,    0,
   37,    0,    0,    0,    0,  107,   37,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  113,
  114,  115,  116,  117,  118,  119,  120,  121,  122,  123,
  124,  125,  126,  127,  128,  129,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  147,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  163,    0,    0,  164,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  183,    0,    0,    0,    0,  187,
};
static const YYINT yycheck[] = {                         33,
   35,   35,   59,   37,   38,   91,   44,   41,   42,   43,
   44,   45,   36,   47,   97,   59,  258,   59,  101,   59,
  257,   59,  259,   59,  258,   59,   60,   61,   62,  258,
   39,  153,   41,   59,   57,   33,  285,  159,   41,   37,
   38,   44,  263,   41,   42,   43,   44,   45,   57,   47,
  258,  267,  268,  136,  270,  271,   91,   91,  180,   93,
   94,   59,   60,   61,   62,   59,   40,  267,  268,   59,
  270,   33,  272,  273,   97,   37,   38,  257,  101,   41,
   42,   43,   44,   45,   59,   47,  258,   96,   97,   59,
  124,   59,  101,   59,  103,   93,   94,   59,   60,   61,
   62,  260,  261,    6,   37,  267,  268,   33,  270,   42,
   91,   37,   38,  136,   47,   41,   42,   43,   44,   45,
   41,   47,  146,   44,  285,   41,  124,  136,   44,  138,
   33,   93,   94,   59,   60,   61,   62,  263,  264,  265,
  266,  267,  268,   33,  270,  271,  285,   37,   38,   91,
   53,   41,   42,   43,   44,   45,  258,   47,  276,  277,
  278,   94,  124,  267,  268,  269,  270,   93,   94,   59,
   60,   61,   62,   59,  156,  267,  268,  285,  270,  188,
   33,  272,  273,  165,   37,   38,  263,   44,   41,   42,
   43,   44,   45,   94,   47,   93,  178,  258,  124,  285,
  258,   93,  184,   93,   94,  262,   59,   60,   61,   62,
   37,  193,  276,  277,  278,   42,   43,  199,   45,  263,
   47,  258,  262,  263,  262,  263,  262,  263,  262,  263,
  272,  273,   91,   60,  124,   62,  262,  263,  272,  273,
   93,  275,  276,  277,  278,  285,  280,  281,  278,  278,
  285,  285,  286,  287,  288,  272,   38,  263,   40,   41,
  276,  277,  278,   45,  262,  263,  263,   94,  262,  263,
  278,  124,  262,  263,  272,  273,  272,  275,  276,  277,
  278,   63,  280,  281,    2,   54,   53,   33,  286,  287,
  288,  156,  262,  263,  262,  263,  262,  263,   47,    7,
  262,  263,  272,  158,  175,  146,  276,  277,  278,  169,
  272,  273,   -1,  275,  276,  277,  278,   -1,  280,  281,
   -1,   -1,   37,   -1,  286,  287,  288,   42,   43,   -1,
   45,   -1,   47,   -1,   -1,   -1,  262,  263,   -1,   -1,
   -1,   -1,   -1,   59,  126,   -1,  272,  273,   -1,  275,
  276,  277,  278,   -1,  280,  281,   38,   -1,   40,   -1,
  286,  287,  288,   45,   -1,   -1,   33,   -1,   -1,   -1,
   37,   38,  262,  263,   41,   42,   43,   44,   45,   94,
   47,   63,  272,  273,   -1,  275,  276,  277,  278,   -1,
  280,  281,   59,   60,   61,   62,  286,  287,  288,  267,
  268,   -1,  270,   33,  272,  273,   -1,   37,   38,  262,
  263,   41,   42,   43,   44,   45,   -1,   47,   -1,  272,
  273,   -1,  275,  276,  277,  278,   93,  280,  281,   59,
   60,   61,   62,  286,  287,  288,   -1,   -1,   33,   -1,
   -1,   -1,   37,   38,  126,   -1,   41,   42,   43,   44,
   45,   -1,   47,   -1,   -1,   -1,   -1,  124,   -1,   -1,
  287,  288,   -1,   93,   59,   60,   61,   62,   -1,   -1,
   -1,   -1,   -1,   33,   -1,  257,  258,  259,   38,   -1,
   -1,   41,   37,   43,   44,   45,   -1,   42,   43,   -1,
   45,   -1,   47,   -1,  124,   -1,   -1,   -1,   93,   59,
   60,   61,   62,    6,   -1,   60,   61,   62,   33,   -1,
   13,   -1,   -1,   38,   17,   -1,   41,   -1,   43,   44,
   45,  264,  265,  266,  267,  268,   -1,  270,  271,  124,
   33,   -1,   -1,   93,   59,   60,   61,   62,   38,   94,
   40,   -1,   -1,   33,   -1,   45,  262,  263,   38,   -1,
   53,   41,   55,   -1,   44,   -1,  272,   -1,   -1,   -1,
  276,  277,  278,   63,  124,   -1,   -1,   -1,   93,   59,
   60,   61,   62,   -1,   -1,  257,  258,  259,  265,  266,
  267,  268,  269,  270,   -1,  267,  268,   -1,  270,   -1,
   -1,   -1,  274,   -1,   -1,  262,  263,  279,   -1,  124,
  282,  283,  284,   93,   -1,  272,  273,   -1,  275,  276,
  277,  278,   -1,  280,  281,   -1,   -1,   -1,   -1,  286,
  287,  288,   -1,   -1,   -1,   -1,  126,   -1,   -1,   -1,
   -1,   -1,  262,  263,  124,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  272,  273,   33,  275,  276,  277,  278,   38,
  280,  281,   41,  156,   -1,   44,  286,  287,  288,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  262,  263,   -1,
   59,   60,   61,   62,   -1,  178,   -1,  272,  273,   33,
  275,  276,  277,  278,   38,  280,  281,   41,   -1,   -1,
   44,  286,  287,  288,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  262,  263,   93,   59,   60,   61,   62,   -1,
   -1,   -1,  272,  273,   33,  275,  276,  277,  278,   38,
  280,  281,   41,   -1,   -1,   44,  286,  287,  288,   -1,
   -1,  286,  287,  288,   -1,  124,   -1,  262,  263,   93,
   59,   60,   61,   62,   -1,   -1,   -1,  272,  273,   -1,
  275,  276,  277,  278,   -1,  280,  281,  257,  258,  259,
   -1,  286,  287,  288,   -1,   -1,   -1,   -1,   -1,   -1,
  124,   -1,  262,  263,   93,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  272,  273,   -1,  275,  276,  277,  278,   -1,
  280,  281,   -1,   -1,   -1,   59,  286,  287,  288,   33,
   -1,   -1,   -1,   37,   38,  124,   -1,   -1,   42,   43,
   33,   45,   -1,   47,   37,   38,   -1,   -1,   -1,   42,
   43,   -1,   45,   -1,   47,   59,   60,   61,   62,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   59,   60,   61,   62,
   33,   -1,   -1,   -1,   -1,   38,   -1,   -1,   41,   -1,
   -1,   44,   -1,   37,   38,   -1,   -1,   -1,   42,   43,
   94,   45,   -1,   47,   -1,   -1,   59,   -1,   61,   -1,
   -1,   94,   -1,  262,  263,   -1,   60,   61,   62,   -1,
   -1,   -1,   -1,  272,  273,   -1,  275,  276,  277,  278,
  124,  280,  281,   -1,   -1,   -1,   -1,  286,  287,  288,
   93,  124,   -1,   -1,   -1,   -1,   -1,   -1,  262,  263,
   94,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  272,  273,
   -1,  275,  276,  277,  278,   -1,  280,  281,   -1,   -1,
   -1,  124,  286,  287,  288,   -1,   -1,   33,   -1,   -1,
  124,   -1,   38,  262,  263,   41,   -1,   -1,   44,   -1,
   -1,   -1,   -1,  272,  273,   -1,  275,  276,  277,  278,
   -1,  280,  281,   59,   -1,   61,   -1,  286,  287,  288,
   37,   38,   -1,   -1,   -1,   42,   43,   -1,   45,   -1,
   47,   37,   38,   -1,   -1,   41,   42,   43,   -1,   45,
   -1,   47,   -1,   60,   61,   62,   -1,   93,  262,  263,
   -1,   -1,   -1,   -1,   60,   61,   62,   -1,  272,   -1,
   37,   38,  276,  277,  278,   42,   43,   -1,   45,   -1,
   47,   -1,   -1,   -1,   -1,   -1,   -1,   94,  124,   -1,
   -1,   -1,   -1,   60,   61,   62,   -1,  262,   94,  264,
  265,  266,  267,  268,   -1,  270,  271,   -1,   -1,   -1,
   37,   38,  286,  287,  288,   42,   43,  124,   45,   -1,
   47,   -1,   -1,  286,  287,  288,   93,   94,  124,  262,
  263,   -1,   59,   60,   61,   62,   -1,   -1,   -1,  272,
  273,   -1,  275,  276,  277,  278,   -1,  280,  281,   -1,
   -1,  275,   -1,  286,   -1,   -1,   -1,  124,   -1,   -1,
   37,   38,  286,  287,  288,   42,   43,   94,   45,   -1,
   47,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   37,   38,   60,   61,   62,   42,   43,   -1,   45,
   -1,   47,   -1,   -1,   -1,   -1,   -1,  124,   -1,   -1,
   -1,   -1,   -1,   -1,   60,   61,   62,   -1,   37,   38,
   -1,   -1,   -1,   42,   43,   -1,   45,   94,   47,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  262,  263,   38,   -1,
   40,   60,   61,   62,   -1,   45,  272,  273,   94,  275,
  276,  277,  278,   -1,  280,  281,   -1,  124,   -1,   -1,
  286,   37,   38,   63,   -1,   -1,   42,   43,   -1,   45,
   -1,   47,   -1,   -1,   -1,   94,   -1,   -1,  124,   -1,
   -1,   -1,   -1,  280,   60,   61,   62,   37,   38,  286,
  287,  288,   42,   43,   -1,   45,   -1,   47,   -1,   -1,
  286,  287,  288,   -1,   -1,  124,   -1,   -1,   -1,   -1,
   60,   61,   62,   -1,   33,   -1,   -1,   -1,   94,   38,
   -1,   -1,   41,   -1,   -1,   44,  126,   -1,   -1,  286,
  287,  288,   -1,   -1,   33,   -1,   -1,   -1,   -1,   38,
   59,   -1,   41,   -1,   94,   44,   -1,   -1,  124,   -1,
   -1,   38,   -1,   40,   -1,   33,   -1,   -1,   45,   -1,
   59,   -1,   -1,   41,   -1,   -1,   44,   -1,   -1,  286,
  287,  288,   -1,   -1,   93,   33,   63,   -1,   -1,   -1,
   -1,   59,   -1,   41,   -1,   -1,   44,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   93,   -1,   -1,   -1,   -1,   -1,
   -1,   59,   -1,   -1,   -1,  124,   38,   -1,   40,   -1,
   -1,   -1,   -1,   45,  281,   93,   -1,   -1,   -1,  286,
  287,  288,   -1,   -1,   -1,  124,   -1,   -1,   -1,  275,
   -1,   63,   -1,   -1,   -1,   93,   -1,   -1,   -1,  126,
  286,  287,  288,   -1,   -1,   -1,  124,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  273,   -1,   -1,  257,  258,  259,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  286,  287,  288,
   -1,   -1,   -1,   -1,  274,   -1,   -1,   -1,   -1,  279,
   -1,   -1,  282,  283,  284,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,    6,  126,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  286,  287,  288,   26,   -1,   -1,   -1,   -1,   -1,   -1,
   33,   -1,   -1,   36,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  286,  287,  288,   -1,
   53,   -1,   -1,  262,  263,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  272,  273,   -1,  275,  276,  277,  278,
   -1,  280,  281,  262,  263,   -1,   -1,   -1,   -1,   -1,
  257,  258,  259,  272,  273,   -1,  275,  276,  277,  278,
   -1,  280,  281,   -1,  262,  263,   -1,  274,   -1,   -1,
   -1,   -1,  279,   -1,  272,  273,  109,  275,  276,  277,
  278,   -1,  280,  281,  262,  263,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  272,  273,   -1,  275,  276,  277,
  278,   -1,  280,  281,   -1,  257,  258,  259,   -1,   -1,
   -1,   -1,   -1,  146,   -1,  267,  268,   -1,  270,   -1,
   -1,   -1,  274,  156,   -1,   -1,   -1,  279,   -1,   -1,
   24,   25,  165,   27,   28,   -1,   30,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  178,   -1,   -1,   -1,   -1,
   -1,  184,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  193,   -1,   -1,   -1,   -1,   59,  199,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   73,
   74,   75,   76,   77,   78,   79,   80,   81,   82,   83,
   84,   85,   86,   87,   88,   89,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  110,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  140,   -1,   -1,  143,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  166,   -1,   -1,   -1,   -1,  171,
};
#define YYFINAL 3
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 307
#define YYUNDFTOKEN 345
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
"NIL","DECLS","DECL","FUNCTYPE","QUALIFIER","VARS","VAR","BODY","RETURN_EXPR",
"ELIFS","BLOCK","INSTRS","TWO_INTEGERS","MORE_INTEGERS","ARGS","LOCAL","CALL",0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"illegal-symbol",
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
"$$1 :",
"func : FUNCTION qualifier functype ID $$1 params funcend",
"$$2 :",
"func : FUNCTION functype ID $$2 params funcend",
"$$3 :",
"func : FUNCTION qualifier functype ID $$3 funcend",
"$$4 :",
"func : FUNCTION functype ID $$4 funcend",
"funcend : DONE",
"funcend : DO body",
"functype : type",
"functype : VOID",
"qualifier : PUBLIC",
"qualifier : FORWARD",
"params : param",
"params : params ';' param",
"param : STRING ID",
"param : NUMBER ID",
"param : ARRAY ID '[' integer ']'",
"var : STRING ID",
"var : NUMBER ID",
"var : ARRAY ID '[' integer ']'",
"var : ARRAY ID",
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
"$$5 :",
"instr : FOR expr UNTIL expr STEP expr DO $$5 block DONE",
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
"expr : ID '(' args ')'",
"expr : ID '(' ')'",
"expr : string",
"expr : integer",
"expr : '-' expr",
"expr : '&' lvalue",
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
#line 221 "gram.y"

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

void noarray(Node *arg1, Node *arg2) {
	if (arg1->info % 5 == 3 || arg2->info % 5 == 3)
		yyerror("can not use arrays");
}

void sametype(Node *arg1, Node *arg2) {
	if (arg1->info % 5 != arg2->info % 5)
		yyerror("different types not allowed");
}

int intonly(Node *arg) {
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

void enter(int pub, int typ, char *name) {
	fpar = malloc(32); /* 31 arguments, at most */
	fpar[0] = 0; /* argument count */
	if (IDfind(name, (long*)IDtest) < 20)
		IDnew(typ+20, name, (long)fpar);
	IDpush();
	if (typ != 4) IDnew(typ, name, 0);
}

void function(int pub, Node *type, char *name, Node *body, int enter)
{

	Node *bloco = LEFT_CHILD(body);
	IDpop();
	if (bloco != 0) { /* not a forward declaration */
		long par;
		int fwd = IDfind(name, &par);
		if (fwd > 40) yyerror("duplicate function");
		else IDreplace(fwd+40, name, par);
	}
}
#line 865 "y.tab.c"

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
#line 54 "gram.y"
	{ printNode(yystack.l_mark[0].n,0,yynames); }
break;
case 2:
#line 55 "gram.y"
	{ printNode(yystack.l_mark[0].n,0,yynames); }
break;
case 3:
#line 58 "gram.y"
	{ yyval.n = binNode(PROGRAM, yystack.l_mark[-3].n, yystack.l_mark[-1].n); }
break;
case 4:
#line 59 "gram.y"
	{ yyval.n = uniNode(PROGRAM, yystack.l_mark[-1].n); }
break;
case 5:
#line 62 "gram.y"
	{ yyval.n = uniNode(MODULE, yystack.l_mark[-1].n); }
break;
case 6:
#line 63 "gram.y"
	{ yyval.n = nilNode(MODULE); }
break;
case 7:
#line 66 "gram.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 8:
#line 67 "gram.y"
	{ yyval.n = binNode(DECLS, yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 9:
#line 70 "gram.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 10:
#line 71 "gram.y"
	{ IDnew(yystack.l_mark[-2].n->info+5, RIGHT_CHILD(yystack.l_mark[-2].n)->value.s, 0); declare(yystack.l_mark[-4].n, 1, yystack.l_mark[-2].n, RIGHT_CHILD(yystack.l_mark[-2].n)->value.s, yystack.l_mark[0].n); yyval.n = binNode(QUALIFIER, yystack.l_mark[-4].n, binNode(VAR, yystack.l_mark[-2].n, yystack.l_mark[0].n)); }
break;
case 11:
#line 72 "gram.y"
	{ IDnew(yystack.l_mark[-2].n->info, RIGHT_CHILD(yystack.l_mark[-2].n)->value.s, 0); declare(yystack.l_mark[-3].n, 0, yystack.l_mark[-2].n, RIGHT_CHILD(yystack.l_mark[-2].n)->value.s, yystack.l_mark[0].n); yyval.n = binNode(QUALIFIER, yystack.l_mark[-3].n, binNode(VAR, yystack.l_mark[-2].n, yystack.l_mark[0].n)); }
break;
case 12:
#line 73 "gram.y"
	{ IDnew(yystack.l_mark[0].n->info, RIGHT_CHILD(yystack.l_mark[0].n)->value.s, 0); declare(yystack.l_mark[-1].n, 0, yystack.l_mark[0].n, RIGHT_CHILD(yystack.l_mark[0].n)->value.s, 0); yyval.n = binNode(DECL, yystack.l_mark[-1].n, yystack.l_mark[0].n); }
break;
case 13:
#line 74 "gram.y"
	{ IDnew(yystack.l_mark[0].n->info+5, RIGHT_CHILD(yystack.l_mark[0].n)->value.s, 0); declare(yystack.l_mark[-2].n, 1, yystack.l_mark[0].n, RIGHT_CHILD(yystack.l_mark[0].n)->value.s, 0); yyval.n = binNode(DECL, yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 14:
#line 75 "gram.y"
	{ IDnew(yystack.l_mark[0].n->info+5, RIGHT_CHILD(yystack.l_mark[0].n)->value.s, 0); declare(0, 1, yystack.l_mark[0].n, RIGHT_CHILD(yystack.l_mark[0].n)->value.s, 0); yyval.n = yystack.l_mark[0].n; }
break;
case 15:
#line 76 "gram.y"
	{ IDnew(yystack.l_mark[-2].n->info+5, RIGHT_CHILD(yystack.l_mark[-2].n)->value.s, 0); declare(0, 1, yystack.l_mark[-2].n, RIGHT_CHILD(yystack.l_mark[-2].n)->value.s, yystack.l_mark[0].n); yyval.n = binNode(DECL, yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 16:
#line 77 "gram.y"
	{ IDnew(yystack.l_mark[0].n->info, RIGHT_CHILD(yystack.l_mark[0].n)->value.s, 0); declare(0, 0, yystack.l_mark[0].n, RIGHT_CHILD(yystack.l_mark[0].n)->value.s, 0); yyval.n = yystack.l_mark[0].n; }
break;
case 17:
#line 78 "gram.y"
	{ IDnew(yystack.l_mark[-2].n->info, RIGHT_CHILD(yystack.l_mark[-2].n)->value.s, 0); declare(0, 0, yystack.l_mark[-2].n, RIGHT_CHILD(yystack.l_mark[-2].n)->value.s, yystack.l_mark[0].n); yyval.n = binNode(DECL, yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 18:
#line 81 "gram.y"
	{ enter(yystack.l_mark[-2].n, yystack.l_mark[-1].n->info, yystack.l_mark[0].s); }
break;
case 19:
#line 81 "gram.y"
	{ yyval.n = binNode(QUALIFIER, yystack.l_mark[-5].n, binNode(FUNCTYPE, yystack.l_mark[-4].n, binNode(ID, strNode(ID, yystack.l_mark[-3].s), binNode(VARS, yystack.l_mark[-2].n, uniNode(END, yystack.l_mark[-1].n))))); IDpop(); }
break;
case 20:
#line 82 "gram.y"
	{ enter(0, yystack.l_mark[-1].n->info, yystack.l_mark[0].s); }
break;
case 21:
#line 82 "gram.y"
	{ yyval.n = binNode(FUNCTYPE, yystack.l_mark[-4].n, binNode(ID, strNode(ID, yystack.l_mark[-3].s), binNode(VARS, yystack.l_mark[-2].n, uniNode(END, yystack.l_mark[-1].n)))); IDpop(); }
break;
case 22:
#line 83 "gram.y"
	{ enter(yystack.l_mark[-2].n, yystack.l_mark[-1].n->info, yystack.l_mark[0].s); }
break;
case 23:
#line 83 "gram.y"
	{ yyval.n = binNode(QUALIFIER, yystack.l_mark[-4].n, binNode(FUNCTYPE, yystack.l_mark[-3].n, binNode(ID, strNode(ID, yystack.l_mark[-2].s), uniNode(END, yystack.l_mark[-1].n)))); IDpop(); }
break;
case 24:
#line 84 "gram.y"
	{ enter(0, yystack.l_mark[-1].n->info, yystack.l_mark[0].s); }
break;
case 25:
#line 84 "gram.y"
	{ yyval.n = binNode(FUNCTYPE, yystack.l_mark[-3].n, binNode(ID, strNode(ID, yystack.l_mark[-2].s), uniNode(END, yystack.l_mark[-1].n))); IDpop(); }
break;
case 26:
#line 87 "gram.y"
	{ yyval.n = nilNode(DONE); }
break;
case 27:
#line 88 "gram.y"
	{ yyval.n = uniNode(DO, yystack.l_mark[0].n); }
break;
case 28:
#line 91 "gram.y"
	{ yyval.n = yystack.l_mark[0].n; yyval.n->info = yystack.l_mark[0].n->info; }
break;
case 29:
#line 92 "gram.y"
	{ yyval.n = nilNode(VOID); yyval.n->info = 4; }
break;
case 30:
#line 95 "gram.y"
	{ yyval.n = nilNode(PUBLIC); yyval.n->info = 1; }
break;
case 31:
#line 96 "gram.y"
	{ yyval.n = nilNode(FORWARD); yyval.n->info = 2; }
break;
case 32:
#line 99 "gram.y"
	{ yyval.n = binNode(VARS, yystack.l_mark[0].n, 0); }
break;
case 33:
#line 100 "gram.y"
	{ yyval.n = binNode(VARS, yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 34:
#line 103 "gram.y"
	{ yyval.n = binNode(VAR, uniNode(STRING, nilNode(STRING)), strNode(ID, yystack.l_mark[0].s)); IDnew(2, yystack.l_mark[0].s, 0); yyval.n->info = 2; }
break;
case 35:
#line 104 "gram.y"
	{ yyval.n = binNode(VAR, uniNode(NUMBER, nilNode(NUMBER)), strNode(ID, yystack.l_mark[0].s)); IDnew(1, yystack.l_mark[0].s, 0); yyval.n->info = 1; }
break;
case 36:
#line 105 "gram.y"
	{ yyval.n = binNode(VAR, uniNode(ARRAY, nilNode(ARRAY)), strNode(ID, yystack.l_mark[-3].s)); IDnew(3, yystack.l_mark[-3].s, 0); yyval.n->info = 3; }
break;
case 37:
#line 108 "gram.y"
	{ yyval.n = binNode(VAR, uniNode(STRING, nilNode(STRING)), strNode(ID, yystack.l_mark[0].s)); yyval.n->info = 2; }
break;
case 38:
#line 109 "gram.y"
	{ yyval.n = binNode(VAR, uniNode(NUMBER, nilNode(NUMBER)), strNode(ID, yystack.l_mark[0].s)); yyval.n->info = 1; }
break;
case 39:
#line 110 "gram.y"
	{ yyval.n = binNode(VAR, uniNode(ARRAY, nilNode(ARRAY)), strNode(ID, yystack.l_mark[-3].s)); yyval.n->info = 3; }
break;
case 40:
#line 111 "gram.y"
	{ yyval.n = binNode(VAR, uniNode(ARRAY, nilNode(ARRAY)), strNode(ID, yystack.l_mark[0].s)); yyval.n->info = 3; }
break;
case 41:
#line 114 "gram.y"
	{ yyval.n = nilNode(NUMBER); yyval.n->info = 1; }
break;
case 42:
#line 115 "gram.y"
	{ yyval.n = nilNode(ARRAY); yyval.n->info = 3; }
break;
case 43:
#line 116 "gram.y"
	{ yyval.n = nilNode(STRING); yyval.n->info = 2; }
break;
case 44:
#line 119 "gram.y"
	{ yyval.n = binNode(BODY, yystack.l_mark[-1].n, yystack.l_mark[0].n); }
break;
case 45:
#line 120 "gram.y"
	{ yyval.n = binNode(BODY, yystack.l_mark[0].n, 0); }
break;
case 46:
#line 123 "gram.y"
	{ yyval.n = binNode(BODY, yystack.l_mark[-1].n, yystack.l_mark[0].n); }
break;
case 47:
#line 124 "gram.y"
	{ yyval.n = binNode(BODY, yystack.l_mark[0].n, 0); }
break;
case 48:
#line 127 "gram.y"
	{ yyval.n = nilNode(NIL); }
break;
case 49:
#line 128 "gram.y"
	{ yyval.n = binNode(BODY, yystack.l_mark[0].n, 0); }
break;
case 50:
#line 131 "gram.y"
	{ IDnew(yystack.l_mark[-1].n->info, RIGHT_CHILD(yystack.l_mark[-1].n)->value.s, 0); yyval.n = binNode(VARS, yystack.l_mark[-1].n, 0); }
break;
case 51:
#line 132 "gram.y"
	{ IDnew(yystack.l_mark[-1].n->info, RIGHT_CHILD(yystack.l_mark[-1].n)->value.s, 0); yyval.n = binNode(VARS, yystack.l_mark[-2].n, yystack.l_mark[-1].n); }
break;
case 52:
#line 135 "gram.y"
	{ yyval.n = binNode(IF, yystack.l_mark[-3].n, yystack.l_mark[-1].n); }
break;
case 53:
#line 136 "gram.y"
	{ yyval.n = binNode(IF, yystack.l_mark[-6].n, binNode(THEN, yystack.l_mark[-4].n, binNode(ELIF, yystack.l_mark[-3].n, uniNode(ELSE, yystack.l_mark[-1].n)))); }
break;
case 54:
#line 137 "gram.y"
	{ yyval.n = binNode(IF, yystack.l_mark[-4].n, binNode(THEN, yystack.l_mark[-2].n, uniNode(ELIF, yystack.l_mark[-1].n))); }
break;
case 55:
#line 138 "gram.y"
	{ yyval.n = binNode(IF, yystack.l_mark[-5].n, binNode(THEN, yystack.l_mark[-3].n, uniNode(ELSE, yystack.l_mark[-1].n))); }
break;
case 56:
#line 139 "gram.y"
	{ ncicl++; }
break;
case 57:
#line 139 "gram.y"
	{ yyval.n = binNode(FOR, yystack.l_mark[-8].n, binNode(UNTIL, yystack.l_mark[-6].n, binNode(STEP, yystack.l_mark[-4].n, uniNode(DO, yystack.l_mark[-2].n)))); ncicl--; }
break;
case 58:
#line 140 "gram.y"
	{ yyval.n = yystack.l_mark[-1].n; }
break;
case 59:
#line 141 "gram.y"
	{ yyval.n = yystack.l_mark[-1].n; }
break;
case 60:
#line 142 "gram.y"
	{ yyval.n = binNode('#', yystack.l_mark[-3].n, yystack.l_mark[-1].n); }
break;
case 61:
#line 145 "gram.y"
	{ yyval.n = nilNode(REPEAT); if (ncicl <= 0) yyerror("invalid repeat argument"); }
break;
case 62:
#line 146 "gram.y"
	{ yyval.n = nilNode(STOP); if (ncicl <= 0) yyerror("invalid stop argument"); }
break;
case 63:
#line 147 "gram.y"
	{ yyval.n = uniNode(RETURN_EXPR, yystack.l_mark[0].n); }
break;
case 64:
#line 148 "gram.y"
	{ yyval.n = nilNode(RETURN); }
break;
case 65:
#line 151 "gram.y"
	{ yyval.n = binNode(ELIF, yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 66:
#line 154 "gram.y"
	{ yyval.n = binNode(ELIFS, yystack.l_mark[0].n, 0); }
break;
case 67:
#line 155 "gram.y"
	{ yyval.n = binNode(ELIFS, yystack.l_mark[-1].n, yystack.l_mark[0].n); }
break;
case 68:
#line 158 "gram.y"
	{ yyval.n = nilNode(NIL); }
break;
case 69:
#line 159 "gram.y"
	{ yyval.n = binNode(BLOCK, yystack.l_mark[0].n, 0); }
break;
case 70:
#line 160 "gram.y"
	{ yyval.n = binNode(BLOCK, yystack.l_mark[0].n, 0); }
break;
case 71:
#line 161 "gram.y"
	{ yyval.n = binNode(BLOCK, yystack.l_mark[-1].n, yystack.l_mark[0].n); }
break;
case 72:
#line 164 "gram.y"
	{ yyval.n = binNode(INSTRS, yystack.l_mark[0].n, 0); }
break;
case 73:
#line 165 "gram.y"
	{ yyval.n = binNode(INSTRS, yystack.l_mark[-1].n, yystack.l_mark[0].n); }
break;
case 74:
#line 168 "gram.y"
	{ long pos; int typ = IDfind(yystack.l_mark[0].s, &pos); if (pos == 0) yyval.n = strNode(ID, yystack.l_mark[0].s); else yyval.n = intNode(LOCAL, pos); yyval.n->info = typ; }
break;
case 75:
#line 169 "gram.y"
	{ yyval.n = binNode('[', yystack.l_mark[-3].n, yystack.l_mark[-1].n); yyval.n->info = 1; }
break;
case 76:
#line 172 "gram.y"
	{ yyval.n = yystack.l_mark[0].n; yyval.n->info = yystack.l_mark[0].n->info; }
break;
case 77:
#line 173 "gram.y"
	{ yyval.n = yystack.l_mark[-1].n; }
break;
case 78:
#line 174 "gram.y"
	{ yyval.n = binNode(CALL, strNode(ID, yystack.l_mark[-3].s), yystack.l_mark[-1].n); long pos; int typ = IDfind(yystack.l_mark[-3].s, &pos); yyval.n->info = typ; }
break;
case 79:
#line 175 "gram.y"
	{ yyval.n = binNode(CALL, strNode(ID, yystack.l_mark[-2].s), nilNode(NIL)); long pos; int typ = IDfind(yystack.l_mark[-2].s, &pos); yyval.n->info = typ; }
break;
case 80:
#line 176 "gram.y"
	{ yyval.n = yystack.l_mark[0].n; yyval.n->info = 2; }
break;
case 81:
#line 177 "gram.y"
	{ yyval.n = yystack.l_mark[0].n; yyval.n->info = 1; }
break;
case 82:
#line 178 "gram.y"
	{ yyval.n = uniNode(UMINUS, yystack.l_mark[0].n); yyval.n->info = yystack.l_mark[0].n->info; intonly(yystack.l_mark[0].n);}
break;
case 83:
#line 179 "gram.y"
	{ yyval.n = uniNode(ADDR, yystack.l_mark[0].n); }
break;
case 84:
#line 180 "gram.y"
	{ yyval.n = binNode('^', yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = intonly(yystack.l_mark[-2].n); intonly(yystack.l_mark[0].n); }
break;
case 85:
#line 181 "gram.y"
	{ yyval.n = binNode('+', yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = intonly(yystack.l_mark[-2].n); intonly(yystack.l_mark[0].n); }
break;
case 86:
#line 182 "gram.y"
	{ yyval.n = binNode('-', yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = intonly(yystack.l_mark[-2].n); intonly(yystack.l_mark[0].n); }
break;
case 87:
#line 183 "gram.y"
	{ yyval.n = binNode('*', yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = intonly(yystack.l_mark[-2].n); intonly(yystack.l_mark[0].n); }
break;
case 88:
#line 184 "gram.y"
	{ yyval.n = binNode('/', yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = intonly(yystack.l_mark[-2].n); intonly(yystack.l_mark[0].n); }
break;
case 89:
#line 185 "gram.y"
	{ yyval.n = binNode('%', yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = intonly(yystack.l_mark[-2].n); intonly(yystack.l_mark[0].n); }
break;
case 90:
#line 186 "gram.y"
	{ yyval.n = binNode('<', yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = 1; sametype(yystack.l_mark[-2].n, yystack.l_mark[0].n); noarray(yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 91:
#line 187 "gram.y"
	{ yyval.n = binNode('>', yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = 1; sametype(yystack.l_mark[-2].n, yystack.l_mark[0].n); noarray(yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 92:
#line 188 "gram.y"
	{ yyval.n = binNode(GE, yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = 1; sametype(yystack.l_mark[-2].n, yystack.l_mark[0].n); noarray(yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 93:
#line 189 "gram.y"
	{ yyval.n = binNode(LE, yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = 1; sametype(yystack.l_mark[-2].n, yystack.l_mark[0].n); noarray(yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 94:
#line 190 "gram.y"
	{ yyval.n = binNode(NE, yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = 1; sametype(yystack.l_mark[-2].n, yystack.l_mark[0].n); noarray(yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 95:
#line 191 "gram.y"
	{ yyval.n = binNode('=', yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = 1; sametype(yystack.l_mark[-2].n, yystack.l_mark[0].n); noarray(yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 96:
#line 192 "gram.y"
	{ yyval.n = binNode(ATTR, yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 97:
#line 193 "gram.y"
	{ yyval.n = binNode('&', yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = intonly(yystack.l_mark[-2].n); intonly(yystack.l_mark[0].n); }
break;
case 98:
#line 194 "gram.y"
	{ yyval.n = binNode('|', yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = intonly(yystack.l_mark[-2].n); intonly(yystack.l_mark[0].n); }
break;
case 99:
#line 195 "gram.y"
	{ yyval.n = uniNode('~', yystack.l_mark[0].n); yyval.n->info = intonly(yystack.l_mark[0].n); }
break;
case 100:
#line 196 "gram.y"
	{ yyval.n = nilNode('?'); }
break;
case 101:
#line 199 "gram.y"
	{ yyval.n = yystack.l_mark[0].n; yyval.n->info = yystack.l_mark[0].n->info; }
break;
case 102:
#line 200 "gram.y"
	{ yyval.n = yystack.l_mark[0].n; yyval.n->info = yystack.l_mark[0].n->info; }
break;
case 103:
#line 203 "gram.y"
	{ yyval.n = intNode(INTEGER, yystack.l_mark[0].i); yyval.n->info = 1; }
break;
case 104:
#line 206 "gram.y"
	{ yyval.n = yystack.l_mark[0].n; yyval.n->info = yystack.l_mark[0].n->info; }
break;
case 105:
#line 207 "gram.y"
	{ yyval.n = strNode(STR, yystack.l_mark[0].s); yyval.n->info = 2; }
break;
case 106:
#line 210 "gram.y"
	{ yyval.n = binNode(TWO_INTEGERS, yystack.l_mark[-1].n, yystack.l_mark[0].n); yyval.n->info = 2; }
break;
case 107:
#line 211 "gram.y"
	{ yyval.n = binNode(MORE_INTEGERS, yystack.l_mark[-1].n, yystack.l_mark[0].n); yyval.n->info = 2; }
break;
case 108:
#line 213 "gram.y"
	{ yyval.n = yystack.l_mark[0].n; yyval.n->info = yystack.l_mark[0].n->info; }
break;
case 109:
#line 214 "gram.y"
	{ yyval.n = binNode(',', yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = 3; }
break;
case 110:
#line 217 "gram.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 111:
#line 218 "gram.y"
	{ yyval.n = binNode(ARGS, yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
#line 1511 "y.tab.c"
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
