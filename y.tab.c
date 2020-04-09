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
#define BODYVARS 299
#define RETURN_EXPR 300
#define ELIFS 301
#define INSTRS_INSTRTERM 302
#define INSTRS 303
#define TWO_INTEGERS 304
#define MORE_INTEGERS 305
#define ARGS 306
#define LOCAL 307
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    0,    1,    1,    2,    2,    3,    3,    4,    4,
    4,    4,    4,    4,    4,    4,    4,   31,    9,   32,
    9,   33,    9,   34,    9,   10,   10,   11,   11,   12,
   12,   13,   13,   14,   14,   14,   15,   15,   15,   16,
   16,   16,    6,    6,    5,    5,    7,    7,    8,    8,
   17,   17,   17,   17,   35,   17,   17,   17,   17,   18,
   18,   18,   18,   19,   20,   20,   21,   21,   21,   21,
   22,   22,   23,   23,   24,   24,   24,   24,   24,   24,
   24,   24,   24,   24,   24,   24,   24,   24,   24,   24,
   24,   24,   24,   24,   24,   24,   24,   24,   24,   25,
   25,   26,   28,   28,   29,   29,   27,   27,   30,   30,
};
static const YYINT yylen[] = {                            2,
    1,    1,    5,    4,    3,    2,    1,    3,    1,    5,
    4,    2,    3,    2,    4,    1,    3,    0,    7,    0,
    6,    0,    6,    0,    5,    1,    2,    1,    1,    1,
    1,    1,    3,    2,    2,    5,    2,    2,    5,    1,
    1,    1,    2,    1,    2,    1,    0,    1,    2,    3,
    5,    8,    6,    7,    0,   10,    2,    2,    4,    1,
    1,    2,    1,    4,    1,    2,    0,    1,    1,    2,
    1,    2,    1,    4,    1,    3,    4,    3,    1,    1,
    2,    2,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    2,    1,    1,
    1,    1,    1,    1,    2,    2,    1,    3,    1,    3,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,    1,    2,    0,    0,   30,   31,    0,
    0,    0,    0,    0,    7,    9,    0,    0,    6,    0,
  102,   73,  104,    0,    0,    0,    0,    0,   99,    0,
    0,   44,    0,    0,   71,    0,    0,    0,    0,   79,
    0,   40,   41,   29,   42,    0,    0,   28,   38,    0,
   37,    0,    0,    0,    0,    0,    0,    5,    0,    0,
    0,    0,    0,    0,    0,    4,   43,    0,   49,   72,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   57,   58,
  105,  106,    0,    0,    0,    0,    0,    8,    0,    0,
   17,    0,    0,  100,    0,    0,   76,   50,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   78,    0,    0,    0,    0,
    0,    0,   15,    3,    0,   11,    0,   60,   61,    0,
   68,    0,    0,    0,   74,   59,   77,    0,    0,    0,
    0,    0,   32,   26,    0,   25,    0,    0,   39,   10,
  108,    0,    0,    0,   51,   65,    0,   70,    0,    0,
   35,    0,   34,    0,   21,   27,    0,   46,    0,   23,
    0,    0,    0,   53,   66,    0,    0,   33,   45,   19,
   54,    0,    0,   55,    0,   64,   52,    0,   36,    0,
   56,
};
static const YYINT yydgoto[] = {                          3,
    4,    5,   14,   15,  176,   31,   32,   33,   16,  156,
   46,   17,  152,  153,   18,   48,   35,  141,  166,  167,
  142,  143,   59,   38,  101,   39,  103,   40,   41,  128,
  157,  129,  158,  130,  198,
};
static const YYINT yysindex[] = {                      -114,
 1073,   65,    0,    0,    0,  876, -127,    0,    0, -240,
 -233, -225, -139,  -44,    0,    0,   72, -247,    0,  -57,
    0,    0,    0,  970,  970, -206,  970,  970,    0,  970,
 -190,    0,  876,   28,    0,  219,  -34,  767, -146,    0,
 -146,    0,    0,    0,    0, -144, -165,    0,    0,   35,
    0, -161,  876,  396, -139, -155, -150,    0,  -88,  817,
  934,   66, 1155,  119,  945,    0,    0,  106,    0,    0,
  970,  970,  970,  970,  970,  970,  970,  970,  970,  970,
  970,  970,  970,  970,  970,  970,  970,  501,    0,    0,
    0,    0,    0,  -75, -146, -150,  -69,    0,  -98, -150,
    0, -146,  144,    0, 1149,  970,    0,    0, 1229,  974,
 1069, 1240, 1155,  174,  174,  137,  137,  137,  137,   -5,
   -5,  -23,  -23,  -23,  -23,    0, 1229,  -21,  -92, -122,
    0,  103,    0,    0, -150,    0, -146,    0,    0,  970,
    0, -222, 1149, 1080,    0,    0,    0,  970,  -60,  -55,
  -45,  -46,    0,    0,  319,    0,  -92, -122,    0,    0,
    0, 1229, 1149,  970,    0,    0, -183,    0,  970, 1229,
    0,  121,    0,  -92,    0,    0,  319,    0,  -46,    0,
  -63, 1111, 1149,    0,    0, 1203, -146,    0,    0,    0,
    0, 1149,  -58,    0,  135,    0,    0, 1149,    0,  -39,
    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,    0,  -31,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  -40,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  -31,    0,    0,  -17,  778,    0,  -33,    0,
    3,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  -25,  -31,    0,    0,   -1,    0,    0,   39,    0,
    0,   75, 1270,  111,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0, -106,    0,    0,    0,    0,    0,    7,    0,
    0,  -38,   11,    0,  -76,    0,    0,    0, 1321,    0,
    0, 1193, 1292,  808,  905,  511,  612,  647,  682,  441,
  476,  148,  334,  371,  406,    0,   34,    0,    0,    0,
  187,    0,    0,    0,    0,    0,    0,    0,    0,   31,
    0,    0,  285,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   33,    0,    0,    0,    0,    0,
    0,  784,  -29,    0,    0,    0,    0,    0,    0,   44,
    0,    0,    0,    0,    0,    0,   33,    0,    0,    0,
    0,    0,  -29,    0,    0,    0,    0,    0,    0,    0,
    0,  -76,    0,    0,    0,    0,    0,  -22,    0,    0,
    0,
};
static const YYINT yygindex[] = {                         0,
    0,    0,  250,  202,    0,  205,  227,  108,    0, -128,
  220,  264,  120,  112,  352,    0,  -20,  142,  125,    0,
 -124,   16, 1394, 1551,   25,  431,    0,   10,    0,    0,
    0,    0,    0,    0,    0,
};
#define YYTABLESIZE 1720
static const YYINT yytable[] = {                         80,
   73,   54,   72,   80,   80,  107,   80,   80,   80,   80,
   80,   80,  174,   80,   54,   70,   88,   49,   16,  147,
  107,   36,  148,  175,   50,   80,   80,   80,   80,  180,
  178,   86,   51,   14,   88,  103,   84,   57,  181,  103,
  103,   85,  103,  103,  103,  103,  103,  103,   36,  103,
  190,   22,  189,  163,  164,  165,   72,   12,  193,   80,
   80,  103,  103,  103,  103,   13,  104,  196,   36,  101,
   87,   75,   66,  200,  109,   75,   75,  109,   75,   75,
   75,   75,   75,   75,  110,   75,   69,  110,   87,   63,
   80,   67,  183,  164,  184,  103,  103,   75,   75,   75,
   75,   42,   43,   44,   45,  104,   21,   82,   23,  104,
   21,   82,   82,   93,   82,   82,   82,   82,   82,   82,
  133,   82,   70,   96,  136,   95,  103,   10,   11,  100,
   12,   75,   75,   82,   82,   82,   82,    8,    9,   42,
   43,   44,   45,   81,  104,    1,    2,   81,   81,  154,
  155,   81,   81,   81,   81,   81,   72,   81,   88,  160,
   20,   20,   75,   20,  108,   24,   24,   82,   82,   81,
   81,   81,   81,   86,  149,  150,   88,  151,   84,   82,
   86,   83,  131,   85,   86,   86,  135,  137,   86,   86,
   86,   86,   86,  134,   86,  159,   71,  171,   82,   67,
   67,   67,  172,   81,   81,   58,   86,   86,   86,   86,
   86,  187,  173,   88,  191,   84,   82,   53,   83,  197,
   85,   16,   16,  107,  107,  154,  155,  199,   80,   80,
   87,   47,  201,   78,   81,   79,   14,   14,   80,   80,
   86,   80,   80,   80,   80,   48,   80,   80,   67,   67,
   71,   20,   80,   80,   80,   98,   26,   97,   30,   67,
   12,   12,  177,   28,  103,  103,   94,   87,   13,   13,
   47,   86,  101,  101,  103,  103,  179,  103,  103,  103,
  103,   29,  103,  103,  168,  188,    0,    0,  103,  103,
  103,  185,   63,   63,   67,   67,    0,    0,    0,    0,
   75,   75,   63,    0,    0,    0,   63,   63,   63,    0,
   75,   75,    0,   75,   75,   75,   75,    0,   75,   75,
    0,    0,    0,    0,   75,   75,   75,   19,    7,    8,
    9,   10,   11,    0,   12,   13,   82,   82,   10,   11,
    0,   12,   55,   69,   27,    0,   82,   82,    0,   82,
   82,   82,   82,    0,   82,   82,   26,   34,   30,    0,
   82,   82,   82,   28,   52,    0,   87,    0,   56,    0,
   87,   87,   81,   81,   87,   87,   87,   87,   87,    0,
   87,   29,   81,   81,   68,   81,   81,   81,   81,    0,
   81,   81,   87,   87,   87,   87,   81,   81,   81,    0,
    0,    0,    0,   88,   34,    0,   99,   88,   88,   86,
   86,   88,   88,   88,   88,   88,    0,   88,    0,   86,
   86,    0,   86,   86,   86,   86,   87,   86,   86,   88,
   88,   88,   88,   86,   86,   86,    0,    0,   83,    0,
    0,    0,   83,   83,   27,    0,   83,   83,   83,   83,
   83,    0,   83,   18,   18,    0,   18,   87,   22,   22,
   80,   81,    0,   88,   83,   83,   83,   83,    0,   91,
    0,   92,    0,   84,    0,   21,   22,   23,   84,    0,
    0,   84,    0,   84,   84,   84,    0,  102,    0,    0,
    0,    0,   24,    0,   88,    0,    0,   25,   83,   84,
   84,   84,   84,    0,    0,    0,   34,    0,   85,    0,
    0,    0,    0,   85,    0,    0,   85,    0,   85,   85,
   85,    0,    0,    0,    0,  132,  102,    0,   68,   83,
  102,    0,   91,   84,   85,   85,   85,   85,   26,    0,
   30,  126,    0,   89,    0,   28,   69,   69,   89,    0,
    0,   89,    0,    0,   89,    0,   69,    0,    0,    0,
   69,   69,   69,   29,   84,  102,    0,  161,   85,   89,
   89,   89,   89,    0,    0,   21,   22,   23,    0,    0,
    0,    0,    0,    0,    0,   10,   11,    0,   12,    0,
    0,    0,   24,    0,    0,   87,   87,   25,    0,   85,
  138,  139,  140,   89,    0,   87,   87,    0,   87,   87,
   87,   87,    0,   87,   87,    0,    0,  195,    0,   87,
   87,   87,    0,    0,    0,    0,   27,    0,    0,    0,
    0,    0,   88,   88,   89,    0,    0,    0,    0,    0,
    0,    0,   88,   88,   90,   88,   88,   88,   88,   90,
   88,   88,   90,    0,    0,   90,   88,   88,   88,    7,
    8,    9,   10,   11,    0,   12,   13,   83,   83,    0,
   90,   90,   90,   90,    0,    0,    0,   83,   83,   92,
   83,   83,   83,   83,   92,   83,   83,   92,    0,    0,
   92,   83,   83,   83,    0,    0,    0,    0,    0,    0,
    0,    0,   84,   84,   90,   92,   92,   92,   92,    0,
    0,    0,   84,   84,   91,   84,   84,   84,   84,   91,
   84,   84,   91,    0,    0,   91,   84,   84,   84,    0,
    0,    0,    0,    0,    0,   90,    0,   85,   85,   92,
   91,   91,   91,   91,    0,    0,    0,   85,   85,    0,
   85,   85,   85,   85,    0,   85,   85,   21,   22,   23,
    0,   85,   85,   85,    0,    0,    0,    0,    0,    0,
   92,    0,   89,   89,   91,    0,    0,    0,    0,    0,
    0,    0,   89,   89,    0,   89,   89,   89,   89,    0,
   89,   89,    0,    0,    0,    0,   89,   89,   89,   90,
    0,    0,    0,   86,   75,   91,   88,    0,   84,   82,
   75,   83,    0,   85,   75,   75,    0,   75,    0,   75,
   75,    0,   75,    0,   75,   89,   78,   77,   79,    0,
    0,    0,    0,    0,    0,    0,   75,   75,   75,   75,
   93,    0,   62,    0,    0,   93,    0,    0,   93,    0,
    0,   93,    0,   86,   75,    0,   88,    0,   84,   82,
   87,   83,    0,   85,    0,    0,   93,    0,   93,    0,
    0,   75,    0,   90,   90,    0,   78,   77,   79,    0,
    0,    0,    0,   90,   90,    0,   90,   90,   90,   90,
   74,   90,   90,    0,    0,    0,    0,   90,   90,   90,
   93,   75,    0,    0,    0,    0,    0,    0,   92,   92,
   87,    0,    0,   26,    0,   30,    0,    0,   92,   92,
   28,   92,   92,   92,   92,    0,   92,   92,    0,    0,
    0,   93,   92,   92,   92,    0,    0,   94,   29,    0,
   74,    0,   94,   91,   91,   94,    0,    0,   94,    0,
    0,    0,    0,   91,   91,    0,   91,   91,   91,   91,
    0,   91,   91,   94,    0,   94,    0,   91,   91,   91,
   86,   75,    0,   88,    0,   84,   82,    0,   83,    0,
   85,   86,   75,    0,   88,  107,   84,   82,    0,   83,
    0,   85,    0,   78,   77,   79,    0,   94,    0,    0,
    0,   27,    0,    0,   78,   77,   79,   26,    0,   30,
   86,   75,    0,   88,   28,   84,   82,    0,   83,    0,
   85,    0,    0,    0,    0,    0,    0,   87,   94,    0,
    0,    0,   29,   78,   77,   79,    0,    0,   87,    0,
    0,    0,    0,    0,    0,   62,   62,    0,    0,    0,
    0,    0,   76,   80,   81,   62,    0,   74,    0,   62,
   62,   62,    0,   75,   75,   75,  145,   87,   74,   93,
   93,    0,    0,    0,    0,    0,    0,    0,    0,   93,
   93,    0,   93,   93,   93,   93,    0,   93,   93,    0,
    0,  105,    0,   93,    0,   27,    0,   74,    0,    0,
    0,    0,   76,   80,   81,   86,   75,    0,   88,    0,
   84,   82,    0,   83,    0,   85,   86,   75,    0,   88,
    0,   84,   82,    0,   83,    0,   85,  146,   78,   77,
   79,    0,   21,   22,   23,    0,    0,    0,    0,   78,
   77,   79,   10,   11,    0,   12,    0,   86,   75,   24,
   88,    0,   84,   82,   25,   83,    0,   85,    0,    0,
    0,    0,   87,    0,    0,    0,   94,   94,    0,    0,
   78,   77,   79,   87,    0,    0,   94,   94,    0,   94,
   94,   94,   94,    0,   94,   94,   26,    0,   30,    0,
   94,   86,   74,   28,   88,    0,   84,   82,    0,   83,
    0,   85,    0,   74,   87,    0,    0,    0,    0,    0,
    0,   29,    0,  106,   78,   77,   79,    0,    0,   76,
   80,   81,    0,    0,    0,   97,   21,   22,   23,    0,
   76,   80,   81,   97,   74,    0,   97,    0,    0,   86,
   75,    0,   88,    0,   84,   82,    0,   83,   87,   85,
    0,   97,    0,    0,    0,    0,    0,    0,    0,   76,
   80,   81,   78,   77,   79,   86,   75,    0,   88,    0,
   84,   82,    0,   83,   27,   85,   86,   75,    0,   88,
    0,   84,   82,    0,   83,   97,   85,    0,   78,   77,
   79,    0,    0,    0,    0,    0,   87,    0,    0,   78,
   77,   79,   98,    0,    0,    0,    0,   98,    0,    0,
   98,    0,    0,   98,    0,    0,   97,    0,    0,    0,
    0,    0,   87,    0,   96,    0,   74,    0,   98,   96,
    0,    0,   96,   87,    6,   96,    7,    8,    9,   10,
   11,    0,   12,   13,    0,    0,    0,    0,    0,    0,
   96,    0,   74,   95,   76,   80,   81,    0,    0,    0,
  169,   95,   98,    0,   95,   76,   80,   81,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   95,
    0,    0,    0,    0,   96,  192,    0,    0,    0,    0,
    0,    0,    0,   98,    0,    0,   76,   80,   81,   37,
    0,    0,    0,    0,    0,   21,   22,   23,    0,    0,
    0,    0,    0,   95,    0,   96,    0,    0,    0,   62,
    0,    0,   24,    0,    0,    0,   37,   25,    0,   37,
  138,  139,  140,    0,    0,    0,    0,    0,    0,    0,
   76,   80,   81,    0,    0,    0,   37,    0,    0,    0,
    0,    0,    0,    0,   97,   97,    0,    0,    0,    0,
    0,    0,    0,    0,   97,   97,    0,   97,   97,   97,
   97,    0,   97,   97,    0,  194,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   76,   80,
   81,    0,    0,    0,    0,    0,    0,    0,   37,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   76,   80,   81,    0,    0,    0,
    0,    0,    0,    0,    0,   76,   80,   81,    0,    0,
    0,   98,   98,    0,    0,    0,   37,    0,    0,    0,
    0,   98,   98,    0,   98,   98,   98,   98,   37,   98,
   98,    0,    0,   96,   96,    0,   37,    0,    0,    0,
    0,    0,    0,   96,   96,    0,   96,   96,   96,   96,
   37,   96,   96,    0,   60,   61,   37,   63,   64,    0,
   65,    0,   95,   95,    0,   37,    0,    0,    0,    0,
    0,   37,   95,   95,    0,   95,   95,   95,   95,    0,
   95,   95,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  109,  110,  111,  112,  113,  114,  115,  116,  117,
  118,  119,  120,  121,  122,  123,  124,  125,  127,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  144,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  162,    0,    0,    0,    0,    0,    0,    0,  170,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  182,    0,    0,    0,    0,  186,
};
static const YYINT yycheck[] = {                         33,
   35,   59,   91,   37,   38,   44,   40,   41,   42,   43,
   44,   45,   59,   47,   59,   36,   40,  258,   59,   41,
   59,    6,   44,  152,  258,   59,   60,   61,   62,  158,
  155,   37,  258,   59,   40,   33,   42,  285,  163,   37,
   38,   47,   40,   41,   42,   43,   44,   45,   33,   47,
  179,  258,  177,  276,  277,  278,   91,   59,  183,   93,
   94,   59,   60,   61,   62,   59,   57,  192,   53,   59,
   94,   33,  263,  198,   41,   37,   38,   44,   40,   41,
   42,   43,   44,   45,   41,   47,   59,   44,   94,   59,
  124,   59,  276,  277,  278,   93,   94,   59,   60,   61,
   62,  267,  268,  269,  270,   96,  257,   33,  259,  100,
  257,   37,   38,  258,   40,   41,   42,   43,   44,   45,
   96,   47,  143,  285,  100,   91,  124,  267,  268,  285,
  270,   93,   94,   59,   60,   61,   62,  265,  266,  267,
  268,  269,  270,   33,  135,  260,  261,   37,   38,  272,
  273,   41,   42,   43,   44,   45,   91,   47,   40,  135,
  267,  268,  124,  270,   59,  272,  273,   93,   94,   59,
   60,   61,   62,   37,  267,  268,   40,  270,   42,   43,
   33,   45,  258,   47,   37,   38,  285,   44,   41,   42,
   43,   44,   45,  263,   47,   93,  285,  258,  124,  276,
  277,  278,  258,   93,   94,  263,   59,   60,   61,   62,
   37,   91,  258,   40,  278,   42,   43,  262,   45,  278,
   47,  262,  263,  262,  263,  272,  273,   93,  262,  263,
   94,  263,  272,   60,  124,   62,  262,  263,  272,  273,
   93,  275,  276,  277,  278,  263,  280,  281,  278,  272,
  285,    2,  286,  287,  288,   54,   38,   53,   40,   33,
  262,  263,  155,   45,  262,  263,   47,   94,  262,  263,
    7,  124,  262,  263,  272,  273,  157,  275,  276,  277,
  278,   63,  280,  281,  143,  174,   -1,   -1,  286,  287,
  288,  167,  262,  263,  262,  263,   -1,   -1,   -1,   -1,
  262,  263,  272,   -1,   -1,   -1,  276,  277,  278,   -1,
  272,  273,   -1,  275,  276,  277,  278,   -1,  280,  281,
   -1,   -1,   -1,   -1,  286,  287,  288,  263,  264,  265,
  266,  267,  268,   -1,  270,  271,  262,  263,  267,  268,
   -1,  270,  271,   59,  126,   -1,  272,  273,   -1,  275,
  276,  277,  278,   -1,  280,  281,   38,    6,   40,   -1,
  286,  287,  288,   45,   13,   -1,   33,   -1,   17,   -1,
   37,   38,  262,  263,   41,   42,   43,   44,   45,   -1,
   47,   63,  272,  273,   33,  275,  276,  277,  278,   -1,
  280,  281,   59,   60,   61,   62,  286,  287,  288,   -1,
   -1,   -1,   -1,   33,   53,   -1,   55,   37,   38,  262,
  263,   41,   42,   43,   44,   45,   -1,   47,   -1,  272,
  273,   -1,  275,  276,  277,  278,   93,  280,  281,   59,
   60,   61,   62,  286,  287,  288,   -1,   -1,   33,   -1,
   -1,   -1,   37,   38,  126,   -1,   41,   42,   43,   44,
   45,   -1,   47,  267,  268,   -1,  270,  124,  272,  273,
  287,  288,   -1,   93,   59,   60,   61,   62,   -1,   39,
   -1,   41,   -1,   33,   -1,  257,  258,  259,   38,   -1,
   -1,   41,   -1,   43,   44,   45,   -1,   57,   -1,   -1,
   -1,   -1,  274,   -1,  124,   -1,   -1,  279,   93,   59,
   60,   61,   62,   -1,   -1,   -1,  155,   -1,   33,   -1,
   -1,   -1,   -1,   38,   -1,   -1,   41,   -1,   43,   44,
   45,   -1,   -1,   -1,   -1,   95,   96,   -1,  177,  124,
  100,   -1,  102,   93,   59,   60,   61,   62,   38,   -1,
   40,   41,   -1,   33,   -1,   45,  262,  263,   38,   -1,
   -1,   41,   -1,   -1,   44,   -1,  272,   -1,   -1,   -1,
  276,  277,  278,   63,  124,  135,   -1,  137,   93,   59,
   60,   61,   62,   -1,   -1,  257,  258,  259,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  267,  268,   -1,  270,   -1,
   -1,   -1,  274,   -1,   -1,  262,  263,  279,   -1,  124,
  282,  283,  284,   93,   -1,  272,  273,   -1,  275,  276,
  277,  278,   -1,  280,  281,   -1,   -1,  187,   -1,  286,
  287,  288,   -1,   -1,   -1,   -1,  126,   -1,   -1,   -1,
   -1,   -1,  262,  263,  124,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  272,  273,   33,  275,  276,  277,  278,   38,
  280,  281,   41,   -1,   -1,   44,  286,  287,  288,  264,
  265,  266,  267,  268,   -1,  270,  271,  262,  263,   -1,
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
  268,   -1,  270,  271,   -1,   -1,   -1,   -1,   -1,   -1,
   59,   -1,  124,   33,  286,  287,  288,   -1,   -1,   -1,
  281,   41,   93,   -1,   44,  286,  287,  288,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   59,
   -1,   -1,   -1,   -1,   93,  275,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  124,   -1,   -1,  286,  287,  288,    6,
   -1,   -1,   -1,   -1,   -1,  257,  258,  259,   -1,   -1,
   -1,   -1,   -1,   93,   -1,  124,   -1,   -1,   -1,   26,
   -1,   -1,  274,   -1,   -1,   -1,   33,  279,   -1,   36,
  282,  283,  284,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  286,  287,  288,   -1,   -1,   -1,   53,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  262,  263,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  272,  273,   -1,  275,  276,  277,
  278,   -1,  280,  281,   -1,  273,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  286,  287,
  288,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  105,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  286,  287,  288,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  286,  287,  288,   -1,   -1,
   -1,  262,  263,   -1,   -1,   -1,  143,   -1,   -1,   -1,
   -1,  272,  273,   -1,  275,  276,  277,  278,  155,  280,
  281,   -1,   -1,  262,  263,   -1,  163,   -1,   -1,   -1,
   -1,   -1,   -1,  272,  273,   -1,  275,  276,  277,  278,
  177,  280,  281,   -1,   24,   25,  183,   27,   28,   -1,
   30,   -1,  262,  263,   -1,  192,   -1,   -1,   -1,   -1,
   -1,  198,  272,  273,   -1,  275,  276,  277,  278,   -1,
  280,  281,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   71,   72,   73,   74,   75,   76,   77,   78,   79,
   80,   81,   82,   83,   84,   85,   86,   87,   88,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  106,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  140,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  148,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  164,   -1,   -1,   -1,   -1,  169,
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
"NIL","DECLS","DECL","FUNCTYPE","QUALIFIER","VARS","VAR","BODY","BODYVARS",
"RETURN_EXPR","ELIFS","INSTRS_INSTRTERM","INSTRS","TWO_INTEGERS",
"MORE_INTEGERS","ARGS","LOCAL",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,"illegal-symbol",
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
"expr : expr '(' args ')'",
"expr : expr '(' ')'",
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
#line 220 "gram.y"

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
#line 860 "y.tab.c"

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
	{ yyval.n = yystack.l_mark[0].n; }
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
#line 113 "gram.y"
	{ yyval.n = nilNode(NUMBER); yyval.n->info = 1; }
break;
case 41:
#line 114 "gram.y"
	{ yyval.n = nilNode(ARRAY); yyval.n->info = 3; }
break;
case 42:
#line 115 "gram.y"
	{ yyval.n = nilNode(STRING); yyval.n->info = 2; }
break;
case 43:
#line 118 "gram.y"
	{ yyval.n = binNode(BODY, yystack.l_mark[-1].n, yystack.l_mark[0].n); }
break;
case 44:
#line 119 "gram.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 45:
#line 122 "gram.y"
	{ yyval.n = binNode(BODY, yystack.l_mark[-1].n, yystack.l_mark[0].n); }
break;
case 46:
#line 123 "gram.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 47:
#line 126 "gram.y"
	{ yyval.n = nilNode(NIL); }
break;
case 48:
#line 127 "gram.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 49:
#line 130 "gram.y"
	{ yyval.n = yystack.l_mark[-1].n; }
break;
case 50:
#line 131 "gram.y"
	{ yyval.n = binNode(BODYVARS, yystack.l_mark[-2].n, yystack.l_mark[-1].n); }
break;
case 51:
#line 134 "gram.y"
	{ yyval.n = binNode(IF, yystack.l_mark[-3].n, yystack.l_mark[-1].n); }
break;
case 52:
#line 135 "gram.y"
	{ yyval.n = binNode(IF, yystack.l_mark[-6].n, binNode(THEN, yystack.l_mark[-4].n, binNode(ELIF, yystack.l_mark[-3].n, uniNode(ELSE, yystack.l_mark[-1].n)))); }
break;
case 53:
#line 136 "gram.y"
	{ yyval.n = binNode(IF, yystack.l_mark[-4].n, binNode(THEN, yystack.l_mark[-2].n, uniNode(ELIF, yystack.l_mark[-1].n))); }
break;
case 54:
#line 137 "gram.y"
	{ yyval.n = binNode(IF, yystack.l_mark[-5].n, binNode(THEN, yystack.l_mark[-3].n, uniNode(ELSE, yystack.l_mark[-1].n))); }
break;
case 55:
#line 138 "gram.y"
	{ ncicl++; }
break;
case 56:
#line 138 "gram.y"
	{ yyval.n = binNode(FOR, yystack.l_mark[-8].n, binNode(UNTIL, yystack.l_mark[-6].n, binNode(STEP, yystack.l_mark[-4].n, uniNode(DO, yystack.l_mark[-2].n)))); ncicl--; }
break;
case 57:
#line 139 "gram.y"
	{ yyval.n = yystack.l_mark[-1].n; }
break;
case 58:
#line 140 "gram.y"
	{ yyval.n = yystack.l_mark[-1].n; }
break;
case 59:
#line 141 "gram.y"
	{ yyval.n = binNode('#', yystack.l_mark[-3].n, yystack.l_mark[-1].n); }
break;
case 60:
#line 144 "gram.y"
	{ yyval.n = nilNode(REPEAT); if (ncicl <= 0) yyerror("invalid repeat argument"); }
break;
case 61:
#line 145 "gram.y"
	{ yyval.n = nilNode(STOP); if (ncicl <= 0) yyerror("invalid stop argument"); }
break;
case 62:
#line 146 "gram.y"
	{ yyval.n = uniNode(RETURN_EXPR, yystack.l_mark[0].n); }
break;
case 63:
#line 147 "gram.y"
	{ yyval.n = nilNode(RETURN); }
break;
case 64:
#line 150 "gram.y"
	{ yyval.n = binNode(ELIF, yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 65:
#line 153 "gram.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 66:
#line 154 "gram.y"
	{ yyval.n = binNode(ELIFS, yystack.l_mark[-1].n, yystack.l_mark[0].n); }
break;
case 67:
#line 157 "gram.y"
	{ yyval.n = nilNode(NIL); }
break;
case 68:
#line 158 "gram.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 69:
#line 159 "gram.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 70:
#line 160 "gram.y"
	{ yyval.n = binNode(INSTRS_INSTRTERM, yystack.l_mark[-1].n, yystack.l_mark[0].n); }
break;
case 71:
#line 163 "gram.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 72:
#line 164 "gram.y"
	{ yyval.n = binNode(INSTRS, yystack.l_mark[-1].n, yystack.l_mark[0].n); }
break;
case 73:
#line 167 "gram.y"
	{ long pos; int typ = IDfind(yystack.l_mark[0].s, &pos); if (pos == 0) yyval.n = strNode(ID, yystack.l_mark[0].s); else yyval.n = intNode(LOCAL, pos); yyval.n->info = typ; }
break;
case 74:
#line 168 "gram.y"
	{ yyval.n = binNode('[', yystack.l_mark[-3].n, yystack.l_mark[-1].n); }
break;
case 75:
#line 171 "gram.y"
	{ yyval.n = yystack.l_mark[0].n; yyval.n->info = yystack.l_mark[0].n->info; }
break;
case 76:
#line 172 "gram.y"
	{ yyval.n = yystack.l_mark[-1].n; }
break;
case 77:
#line 173 "gram.y"
	{ yyval.n = binNode('(', yystack.l_mark[-3].n, yystack.l_mark[-1].n); }
break;
case 78:
#line 174 "gram.y"
	{ yyval.n = yystack.l_mark[-2].n; }
break;
case 79:
#line 175 "gram.y"
	{ yyval.n = yystack.l_mark[0].n; yyval.n->info = 2; }
break;
case 80:
#line 176 "gram.y"
	{ yyval.n = yystack.l_mark[0].n; yyval.n->info = 1; }
break;
case 81:
#line 177 "gram.y"
	{ yyval.n = uniNode(UMINUS, yystack.l_mark[0].n); yyval.n->info = yystack.l_mark[0].n->info; intonly(yystack.l_mark[0].n);}
break;
case 82:
#line 178 "gram.y"
	{ yyval.n = uniNode(ADDR, yystack.l_mark[0].n); }
break;
case 83:
#line 179 "gram.y"
	{ yyval.n = binNode('^', yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = intonly(yystack.l_mark[-2].n); intonly(yystack.l_mark[0].n); }
break;
case 84:
#line 180 "gram.y"
	{ yyval.n = binNode('+', yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = intonly(yystack.l_mark[-2].n); intonly(yystack.l_mark[0].n); }
break;
case 85:
#line 181 "gram.y"
	{ yyval.n = binNode('-', yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = intonly(yystack.l_mark[-2].n); intonly(yystack.l_mark[0].n); }
break;
case 86:
#line 182 "gram.y"
	{ yyval.n = binNode('*', yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = intonly(yystack.l_mark[-2].n); intonly(yystack.l_mark[0].n); }
break;
case 87:
#line 183 "gram.y"
	{ yyval.n = binNode('/', yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = intonly(yystack.l_mark[-2].n); intonly(yystack.l_mark[0].n); }
break;
case 88:
#line 184 "gram.y"
	{ yyval.n = binNode('%', yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = intonly(yystack.l_mark[-2].n); intonly(yystack.l_mark[0].n); }
break;
case 89:
#line 185 "gram.y"
	{ yyval.n = binNode('<', yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = 1; sametype(yystack.l_mark[-2].n, yystack.l_mark[0].n); noarray(yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 90:
#line 186 "gram.y"
	{ yyval.n = binNode('>', yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = 1; sametype(yystack.l_mark[-2].n, yystack.l_mark[0].n); noarray(yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 91:
#line 187 "gram.y"
	{ yyval.n = binNode(GE, yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = 1; sametype(yystack.l_mark[-2].n, yystack.l_mark[0].n); noarray(yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 92:
#line 188 "gram.y"
	{ yyval.n = binNode(LE, yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = 1; sametype(yystack.l_mark[-2].n, yystack.l_mark[0].n); noarray(yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 93:
#line 189 "gram.y"
	{ yyval.n = binNode(NE, yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = 1; sametype(yystack.l_mark[-2].n, yystack.l_mark[0].n); noarray(yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 94:
#line 190 "gram.y"
	{ yyval.n = binNode('=', yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = 1; sametype(yystack.l_mark[-2].n, yystack.l_mark[0].n); noarray(yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 95:
#line 191 "gram.y"
	{ yyval.n = binNode(ATTR, yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 96:
#line 192 "gram.y"
	{ yyval.n = binNode('&', yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = intonly(yystack.l_mark[-2].n); intonly(yystack.l_mark[0].n); }
break;
case 97:
#line 193 "gram.y"
	{ yyval.n = binNode('|', yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = intonly(yystack.l_mark[-2].n); intonly(yystack.l_mark[0].n); }
break;
case 98:
#line 194 "gram.y"
	{ yyval.n = uniNode('~', yystack.l_mark[0].n); yyval.n->info = intonly(yystack.l_mark[0].n); }
break;
case 99:
#line 195 "gram.y"
	{ yyval.n = nilNode('?'); }
break;
case 100:
#line 198 "gram.y"
	{ yyval.n = yystack.l_mark[0].n; yyval.n->info = yystack.l_mark[0].n->info; }
break;
case 101:
#line 199 "gram.y"
	{ yyval.n = yystack.l_mark[0].n; yyval.n->info = yystack.l_mark[0].n->info; }
break;
case 102:
#line 202 "gram.y"
	{ yyval.n = intNode(INTEGER, yystack.l_mark[0].i); yyval.n->info = 1; }
break;
case 103:
#line 205 "gram.y"
	{ yyval.n = yystack.l_mark[0].n; yyval.n->info = yystack.l_mark[0].n->info; }
break;
case 104:
#line 206 "gram.y"
	{ yyval.n = strNode(STR, yystack.l_mark[0].s); yyval.n->info = 2; }
break;
case 105:
#line 209 "gram.y"
	{ yyval.n = binNode(TWO_INTEGERS, yystack.l_mark[-1].n, yystack.l_mark[0].n); yyval.n->info = 2; }
break;
case 106:
#line 210 "gram.y"
	{ yyval.n = binNode(MORE_INTEGERS, yystack.l_mark[-1].n, yystack.l_mark[0].n); yyval.n->info = 2; }
break;
case 107:
#line 212 "gram.y"
	{ yyval.n = yystack.l_mark[0].n; yyval.n->info = yystack.l_mark[0].n->info; }
break;
case 108:
#line 213 "gram.y"
	{ yyval.n = binNode(',', yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = 3; }
break;
case 109:
#line 216 "gram.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 110:
#line 217 "gram.y"
	{ yyval.n = binNode(ARGS, yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
#line 1502 "y.tab.c"
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
