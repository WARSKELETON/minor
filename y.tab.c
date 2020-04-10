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

void declare(Node *qualifier, int cnst, Node *type, char *name, Node *value);
void enter(Node *qualifier, int typ, char *name);
void function(Node *qualifier, Node *type, char *name, Node *body);
int nostring(Node *arg1, Node *arg2);
void noarray(Node *arg1, Node *arg2);
void sametype(Node *arg1, Node *arg2);
int intonly(Node *arg);
int noassign(Node *arg1, Node *arg2);
int checkargs(char *name, Node *args);
static int ncicl;
static char *fpar;
int typereturn;
int arraysize;
#line 28 "gram.y"
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
#line 60 "y.tab.c"

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
#define SIZE 298
#define BODY 299
#define RETURN_EXPR 300
#define BLOCK 301
#define INSTRS 302
#define ARGS 303
#define LOCAL 304
#define CALL 305
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
   21,   22,   22,   22,   22,   23,   23,   24,   24,   24,
   25,   25,   25,   25,   25,   25,   25,   25,   25,   25,
   25,   25,   25,   25,   25,   25,   25,   25,   25,   25,
   25,   25,   25,   25,   25,   26,   26,   27,   29,   29,
   29,   29,   28,   28,   30,   30,
};
static const YYINT yylen[] = {                            2,
    1,    1,    5,    4,    3,    2,    1,    3,    1,    5,
    4,    2,    3,    2,    4,    1,    3,    0,    7,    0,
    6,    0,    6,    0,    5,    1,    2,    1,    1,    1,
    1,    1,    3,    2,    2,    5,    2,    2,    5,    2,
    1,    1,    1,    2,    1,    2,    1,    0,    1,    2,
    3,    5,    8,    6,    7,    0,   10,    2,    2,    4,
    1,    1,    2,    1,    4,    1,    2,    0,    1,    1,
    2,    0,    1,    1,    2,    1,    2,    1,    4,    4,
    1,    3,    4,    3,    1,    1,    2,    2,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    2,    1,    1,    1,    1,    2,    1,
    2,    2,    1,    3,    1,    3,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,    1,    2,    0,    0,   30,   31,    0,
    0,    0,    0,    0,    7,    9,    0,    0,    6,    0,
  108,    0,  110,    0,    0,    0,    0,    0,  105,    0,
    0,   45,    0,    0,   76,    0,    0,    0,    0,    0,
   41,   42,   29,   43,    0,    0,   28,   38,    0,   37,
    0,    0,    0,    0,    0,    0,    5,    0,    0,    0,
    0,    0,    0,   88,    0,    0,    0,   87,    0,    4,
   44,    0,   50,   77,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   58,   59,  109,  111,    0,  112,    0,    0,    0,    0,
    0,    8,    0,    0,   17,    0,    0,    0,   84,    0,
    0,    0,    0,    0,   82,   51,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   15,    3,    0,
   11,    0,   83,    0,   79,   61,   62,    0,   69,    0,
    0,    0,   60,   80,    0,    0,    0,    0,   32,   26,
    0,   25,    0,    0,   39,   10,  114,    0,    0,    0,
    0,   52,   66,    0,   71,    0,   35,    0,   34,    0,
   21,   27,    0,   73,   47,    0,    0,   23,    0,    0,
    0,   54,   67,    0,    0,   33,   46,   75,   19,   55,
    0,    0,   56,    0,   65,   53,    0,   36,    0,   57,
};
static const YYINT yydgoto[] = {                          3,
    4,    5,   14,   15,  182,   31,   32,   33,   16,  162,
   45,   17,  158,  159,   18,   47,   35,  149,  173,  174,
  150,  185,  151,   60,   38,  105,   39,  107,   40,  111,
  163,  134,  164,  135,  207,
};
static const YYINT yysindex[] = {                      -182,
  261,   65,    0,    0,    0, 1328,  314,    0,    0, -252,
 -245, -239,  -67,  -56,    0,    0,   72, -262,    0,  -43,
    0,  -23,    0,  501,  501,   28,  501,  501,    0,  501,
 -230,    0, 1328,  -16,    0, 1245,  -34,  767, -219,  -61,
    0,    0,    0,    0, -207,  -93,    0,    0,   -4,    0,
 -192, 1328, -125,  -67, -175, -190,    0,  219,  501, -171,
  817,  934,   30,    0, -219,  -61,  446,    0,  945,    0,
    0,   66,    0,    0,  501,  501,  501,  501,  501,  501,
  501,  501,  501,  501,  501,  501,  501,  501,  501,  501,
    0,    0,    0,    0,  501,    0,    0, -127, -219, -190,
 -113,    0, -126, -190,    0, -219,  135,  101,    0, 1192,
   44,  974, 1165,  501,    0,    0, 1192, 1014, 1203,  446,
  174,  174,   12,   12,   12,   12,   -5,   -5,   94,   94,
   94,   94, 1064,  -55,   27,    0,  104,    0,    0, -190,
    0, -219,    0,  501,    0,    0,    0,  501,    0,   45,
 1165, 1075,    0,    0,  -64,  -44,  -40,  -41,    0,    0,
  319,    0,  -55,   27,    0,    0,    0, 1192, 1192, 1165,
  501,    0,    0,   92,    0,  501,    0,  131,    0,  -55,
    0,    0,  319,    0,    0, 1165,  -41,    0,  -45, 1102,
 1165,    0,    0, 1155, -219,    0,    0,    0,    0,    0,
 1165,  -29,    0,  157,    0,    0, 1165,    0,  -14,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,    0,   -7,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  -35,    0,    0,
    0,  -33,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   -7,    0,    0,    4,  778,    0,    3,   39,
    0,    0,    0,    0,    0,    0,    0,    0,  -39,    0,
  -25,   -7,    0,    0,   -1,    0,    0,    0,    0,   75,
    0,    0,  111,    0,    0,    0, 1233,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0, -144,    0,    0,    0,
    0,    0,    7,    0,    0,  -37,   11,   33,    0,   63,
    0,    0,  124,    0,    0,    0, 1299,    0, 1276, 1255,
  808,  905,  511,  612,  647,  682,  441,  476,  148,  334,
  371,  406,    0,    0,    0, -106,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   31,    0,    0,
  -94,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   35,    0,    0,    0,    0,    0,    0,  116,  285,  -15,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   35,    0,    0,   43,    0,    0,    0,    0,
  -15,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  124,    0,    0,    0,    0,    0,    5,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
    0,    0,  269,  235,    0,  240,  271,  149,    0,  -49,
  267,  311,  161,  154,  991,    0,  -21, -130,  167,    0,
  -96,  163,   19, 1430, 1587,  -65, 1543,    0,   47,    0,
    0,    0,    0,    0,    0,
};
#define YYTABLESIZE 1763
static const YYINT yytable[] = {                         78,
   76,   78,   53,   78,   78,   48,  113,   78,   78,   78,
   78,   78,   49,   78,   74,   53,   58,  180,   50,   40,
  175,  113,   56,   16,   36,   78,   78,   78,   78,   95,
  184,   89,   70,   14,  138,   86,   87,   21,  141,   86,
   86,   88,   73,   86,   86,   86,   86,   86,   89,   86,
   97,   36,  184,   87,   85,  198,   86,   12,   88,   78,
   78,   86,   86,   86,   86,   13,   21,   59,   23,  107,
   36,   85,   66,  189,  166,   85,   85,    1,    2,   85,
   85,   85,   85,   85,  143,   85,   99,  144,   90,   64,
   78,  106,  100,   72,  202,   86,   86,   85,   85,   85,
   85,   74,  108,  115,  205,   90,  115,   81,  181,  104,
  209,   81,   81,   75,  188,   81,   81,   81,   81,   81,
   59,   81,   20,   20,  116,   20,   86,   24,   24,   74,
  136,   85,   85,   81,   81,   81,   81,  199,    7,    8,
    9,   10,   11,   78,   12,   13,  108,   78,   78,  139,
  108,   78,   78,   78,   78,   78,  116,   78,  140,  116,
   18,   18,   85,   18,   74,   22,   22,   81,   81,   78,
   78,   78,   78,   41,   42,   43,   44,   70,  142,  186,
   92,   70,   70,   70,   92,   92,  108,   90,   92,   92,
   92,   92,   92,  177,   92,   21,  165,   94,   81,   10,
   11,  186,   12,   78,   78,   52,   92,   92,   92,   92,
   89,  155,  156,  178,  157,   87,   85,  179,   86,   57,
   88,  195,   40,   40,  113,  113,   16,   16,   78,   78,
  160,  161,  200,   81,   78,   82,   14,   14,   78,   78,
   92,   78,   78,   78,   78,   40,   78,   78,  206,  208,
   75,   78,   78,   78,   78,   48,   26,  210,   30,  109,
   12,   12,   68,   28,   86,   86,   49,   90,   13,   13,
   20,   92,  107,  107,   86,   86,   68,   86,   86,   86,
   86,   29,   86,   86,   21,   63,   23,  102,   86,   86,
   86,  101,   64,   64,  106,  106,   72,   72,  160,  161,
   85,   85,   64,   71,   74,   74,   64,   64,   64,  183,
   85,   85,   98,   85,   85,   85,   85,   46,   85,   85,
  170,  171,  172,  187,   85,   85,   85,   19,    7,    8,
    9,   10,   11,  196,   12,   13,   81,   81,   10,   11,
  193,   12,   54,   63,   27,  197,   81,   81,    0,   81,
   81,   81,   81,    0,   81,   81,   26,   21,   30,   94,
   81,   81,   81,   28,    0,    0,   93,  191,  171,  192,
   93,   93,   78,   78,   93,   93,   93,   93,   93,    0,
   93,   29,   78,   78,    0,   78,   78,   78,   78,    0,
   78,   78,   93,   93,   93,   93,   78,   78,   78,   68,
   68,   68,    0,   94,    0,    0,    0,   94,   94,   92,
   92,   94,   94,   94,   94,   94,    0,   94,    0,   92,
   92,    0,   92,   92,   92,   92,   93,   92,   92,   94,
   94,   94,   94,   92,   92,   92,    0,    0,   89,    0,
    0,    0,   89,   89,   27,    0,   89,   89,   89,   89,
   89,    0,   89,    0,    0,    0,    0,   93,    0,    0,
   83,   84,    0,   94,   89,   89,   89,   89,    0,    0,
    0,    0,    0,   90,    0,   21,   22,   23,   90,    0,
    0,   90,   89,   90,   90,   90,    0,   87,   85,    0,
   86,    0,   88,    0,   94,    0,    0,    0,   89,   90,
   90,   90,   90,    0,    0,   81,   80,   82,   91,    0,
    0,    0,    0,   91,    0,    0,   91,    0,   91,   91,
   91,    0,    6,    0,    7,    8,    9,   10,   11,   89,
   12,   13,    0,   90,   91,   91,   91,   91,   26,   90,
   30,    0,    0,   95,    0,   28,   63,   63,   95,    0,
    0,   95,    0,    0,   95,    0,   63,    0,    0,    0,
   63,   63,   63,   29,   90,    0,    0,    0,   91,   95,
   95,   95,   95,    0,    0,   21,   22,   23,    8,    9,
   41,   42,   43,   44,    0,   10,   11,    0,   12,    0,
    0,    0,   24,    0,    0,   93,   93,   25,    0,   91,
  146,  147,  148,   95,    0,   93,   93,    0,   93,   93,
   93,   93,    0,   93,   93,    0,    0,    0,    0,   93,
   93,   93,    0,    0,    0,    0,   27,    0,    0,    0,
    0,    0,   94,   94,   95,    0,    0,    0,    0,    0,
    0,    0,   94,   94,   96,   94,   94,   94,   94,   96,
   94,   94,   96,    0,    0,   96,   94,   94,   94,    0,
    0,    0,    0,    0,    0,    0,    0,   89,   89,    0,
   96,   96,   96,   96,    0,    0,    0,   89,   89,   98,
   89,   89,   89,   89,   98,   89,   89,   98,    0,    0,
   98,   89,   89,   89,    0,    0,    0,    0,    0,    0,
    0,    0,   90,   90,   96,   98,   98,   98,   98,    0,
    0,    0,   90,   90,   97,   90,   90,   90,   90,   97,
   90,   90,   97,    0,    0,   97,   90,   90,   90,    0,
    0,   79,   83,   84,    0,   96,    0,   91,   91,   98,
   97,   97,   97,   97,    0,    0,    0,   91,   91,    0,
   91,   91,   91,   91,    0,   91,   91,   21,   22,   23,
    0,   91,   91,   91,    0,    0,    0,    0,    0,    0,
   98,    0,   95,   95,   97,    0,    0,    0,    0,    0,
    0,    0,   95,   95,    0,   95,   95,   95,   95,    0,
   95,   95,    0,    0,    0,    0,   95,   95,   95,   92,
    0,    0,    0,   89,   78,   97,    0,    0,   87,   85,
   81,   86,    0,   88,   81,   81,    0,    0,    0,   81,
   81,    0,   81,    0,   81,   91,   81,   80,   82,    0,
    0,    0,    0,    0,    0,    0,   81,   81,   81,   81,
   99,    0,    0,    0,    0,   99,    0,    0,   99,    0,
    0,   99,    0,   89,   78,    0,    0,    0,   87,   85,
   90,   86,    0,   88,    0,    0,   99,    0,   99,    0,
    0,   81,    0,   96,   96,    0,   81,   80,   82,    0,
    0,    0,    0,   96,   96,    0,   96,   96,   96,   96,
   77,   96,   96,    0,    0,    0,    0,   96,   96,   96,
   99,   81,    0,    0,    0,    0,    0,    0,   98,   98,
   90,    0,    0,    0,    0,    0,    0,    0,   98,   98,
    0,   98,   98,   98,   98,    0,   98,   98,    0,    0,
    0,   99,   98,   98,   98,    0,    0,  100,    0,    0,
   77,    0,  100,   97,   97,  100,    0,    0,  100,    0,
    0,    0,    0,   97,   97,    0,   97,   97,   97,   97,
    0,   97,   97,  100,    0,  100,    0,   97,   97,   97,
   89,   78,    0,    0,    0,   87,   85,    0,   86,    0,
   88,   89,   78,    0,    0,  115,   87,   85,    0,   86,
    0,   88,    0,   81,   80,   82,   34,  100,    0,    0,
    0,    0,    0,   51,   81,   80,   82,   55,    0,    0,
   89,   78,    0,    0,    0,   87,   85,    0,   86,    0,
   88,    0,    0,   72,    0,    0,    0,   90,  100,    0,
    0,    0,    0,   81,   80,   82,    0,    0,   90,    0,
    0,    0,   34,    0,  103,    0,    0,    0,    0,    0,
   89,   78,   79,   83,   84,   87,   85,   77,   86,    0,
   88,    0,    0,   81,   81,   81,  145,   90,   77,   99,
   99,    0,  153,   81,   80,   82,    0,    0,    0,   99,
   99,    0,   99,   99,   99,   99,    0,   99,   99,    0,
    0,  113,    0,   99,    0,    0,    0,   77,    0,    0,
   89,   78,   79,   83,   84,   87,   85,   90,   86,    0,
   88,   89,   78,    0,    0,    0,   87,   85,    0,   86,
    0,   88,    0,   81,   80,   82,    0,    0,    0,    0,
    0,    0,    0,    0,   81,   80,   82,   77,   89,   78,
    0,    0,    0,   87,   85,    0,   86,    0,   88,    0,
    0,   34,    0,    0,    0,    0,  154,   90,    0,    0,
    0,   81,   80,   82,    0,    0,  100,  100,   90,    0,
    0,    0,    0,   72,    0,    0,  100,  100,    0,  100,
  100,  100,  100,    0,  100,  100,    0,   77,    0,    0,
  100,   89,   78,    0,    0,   90,   87,   85,   77,   86,
    0,   88,   26,    0,   30,    0,    0,    0,    0,   28,
    0,    0,    0,  114,   81,   80,   82,    0,    0,   79,
   83,   84,    0,    0,    0,   77,    0,   29,   89,   78,
   79,   83,   84,   87,   85,    0,   86,    0,   88,   89,
   78,    0,    0,    0,   87,   85,    0,   86,   90,   88,
    0,   81,   80,   82,    0,    0,    0,    0,    0,   79,
   83,   84,   81,   80,   82,  104,    0,    0,    0,    0,
  104,    0,    0,  104,    0,    0,  104,    0,   77,    0,
    0,    0,   26,    0,   30,   90,    0,  102,    0,   28,
   27,  104,  102,    0,    0,  102,   90,    0,  102,   79,
   83,   84,    0,    0,    0,    0,    0,   29,  103,    0,
    0,    0,    0,  102,    0,   77,  103,    0,    0,  103,
    0,    0,    0,    0,    0,  104,    0,    0,    0,    0,
    0,  101,    0,    0,  103,    0,    0,    0,    0,  101,
    0,    0,  101,    0,    0,    0,    0,  102,    0,   79,
   83,   84,    0,    0,    0,  176,  104,  101,    0,    0,
   79,   83,   84,    0,    0,   26,    0,   30,  103,    0,
   27,    0,   28,    0,    0,    0,  201,    0,  102,    0,
    0,    0,    0,    0,    0,    0,    0,   79,   83,   84,
   29,  101,    0,    0,    0,    0,    0,    0,    0,  103,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   21,   22,   23,    0,    0,    0,  203,    0,    0,
    0,    0,    0,    0,    0,   37,    0,    0,   24,    0,
   79,   83,   84,   25,    0,    0,  146,  147,  148,    0,
    0,    0,    0,   27,    0,   64,    0,    0,    0,    0,
    0,    0,   37,    0,    0,   37,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   79,   83,   84,
    0,   37,    0,    0,    0,    0,    0,    0,   79,   83,
   84,    0,    0,    0,  104,  104,    0,    0,    0,    0,
    0,   21,   22,   23,  104,  104,    0,  104,  104,  104,
  104,    0,  104,  104,    0,    0,  102,  102,   24,    0,
    0,    0,    0,   25,    0,    0,  102,  102,    0,  102,
  102,  102,  102,    0,  102,  102,    0,  103,  103,    0,
    0,    0,   37,    0,    0,    0,    0,  103,  103,    0,
  103,  103,  103,  103,    0,  103,  103,    0,    0,    0,
  101,  101,    0,    0,    0,    0,    0,    0,   65,    0,
  101,  101,    0,  101,  101,  101,  101,    0,  101,  101,
   37,   93,   96,    0,   21,   22,   23,    0,    0,    0,
   37,    0,    0,    0,   10,   11,    0,   12,  106,   37,
    0,   24,    0,    0,    0,    0,   25,   93,   96,    0,
   61,   62,   37,   67,   68,   37,   69,    0,    0,    0,
   37,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   37,    0,    0,    0,    0,    0,   37,    0,    0,    0,
    0,  137,  106,    0,  110,  112,  106,    0,   93,    0,
   96,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  117,  118,  119,  120,  121,  122,  123,  124,  125,
  126,  127,  128,  129,  130,  131,  132,    0,    0,    0,
    0,  133,  106,    0,  167,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  152,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  168,    0,    0,    0,  169,    0,    0,  204,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  190,    0,    0,
    0,    0,  194,
};
static const YYINT yycheck[] = {                         33,
   35,   35,   59,   37,   38,  258,   44,   41,   42,   43,
   44,   45,  258,   47,   36,   59,   40,   59,  258,   59,
  151,   59,  285,   59,    6,   59,   60,   61,   62,   91,
  161,   37,  263,   59,  100,   33,   42,  257,  104,   37,
   38,   47,   59,   41,   42,   43,   44,   45,   37,   47,
  258,   33,  183,   42,   43,  186,   45,   59,   47,   93,
   94,   59,   60,   61,   62,   59,  257,   91,  259,   59,
   52,   33,   26,  170,  140,   37,   38,  260,  261,   41,
   42,   43,   44,   45,   41,   47,   91,   44,   94,   59,
  124,   59,  285,   59,  191,   93,   94,   59,   60,   61,
   62,   59,   56,   41,  201,   94,   44,   33,  158,  285,
  207,   37,   38,  285,  164,   41,   42,   43,   44,   45,
   91,   47,  267,  268,   59,  270,  124,  272,  273,  151,
  258,   93,   94,   59,   60,   61,   62,  187,  264,  265,
  266,  267,  268,   33,  270,  271,  100,   37,   38,  263,
  104,   41,   42,   43,   44,   45,   41,   47,  285,   44,
  267,  268,  124,  270,  186,  272,  273,   93,   94,   59,
   60,   61,   62,  267,  268,  269,  270,  272,   44,  161,
   33,  276,  277,  278,   37,   38,  140,   94,   41,   42,
   43,   44,   45,  258,   47,  257,   93,  259,  124,  267,
  268,  183,  270,   93,   94,  262,   59,   60,   61,   62,
   37,  267,  268,  258,  270,   42,   43,  258,   45,  263,
   47,   91,  262,  263,  262,  263,  262,  263,  262,  263,
  272,  273,  278,   60,  124,   62,  262,  263,  272,  273,
   93,  275,  276,  277,  278,  285,  280,  281,  278,   93,
  285,  285,  286,  287,  288,  263,   38,  272,   40,   41,
  262,  263,  278,   45,  262,  263,  263,   94,  262,  263,
    2,  124,  262,  263,  272,  273,  272,  275,  276,  277,
  278,   63,  280,  281,  257,  258,  259,   53,  286,  287,
  288,   52,  262,  263,  262,  263,  262,  263,  272,  273,
  262,  263,  272,   33,  262,  263,  276,  277,  278,  161,
  272,  273,   46,  275,  276,  277,  278,    7,  280,  281,
  276,  277,  278,  163,  286,  287,  288,  263,  264,  265,
  266,  267,  268,  180,  270,  271,  262,  263,  267,  268,
  174,  270,  271,   59,  126,  183,  272,  273,   -1,  275,
  276,  277,  278,   -1,  280,  281,   38,  257,   40,  259,
  286,  287,  288,   45,   -1,   -1,   33,  276,  277,  278,
   37,   38,  262,  263,   41,   42,   43,   44,   45,   -1,
   47,   63,  272,  273,   -1,  275,  276,  277,  278,   -1,
  280,  281,   59,   60,   61,   62,  286,  287,  288,  276,
  277,  278,   -1,   33,   -1,   -1,   -1,   37,   38,  262,
  263,   41,   42,   43,   44,   45,   -1,   47,   -1,  272,
  273,   -1,  275,  276,  277,  278,   93,  280,  281,   59,
   60,   61,   62,  286,  287,  288,   -1,   -1,   33,   -1,
   -1,   -1,   37,   38,  126,   -1,   41,   42,   43,   44,
   45,   -1,   47,   -1,   -1,   -1,   -1,  124,   -1,   -1,
  287,  288,   -1,   93,   59,   60,   61,   62,   -1,   -1,
   -1,   -1,   -1,   33,   -1,  257,  258,  259,   38,   -1,
   -1,   41,   37,   43,   44,   45,   -1,   42,   43,   -1,
   45,   -1,   47,   -1,  124,   -1,   -1,   -1,   93,   59,
   60,   61,   62,   -1,   -1,   60,   61,   62,   33,   -1,
   -1,   -1,   -1,   38,   -1,   -1,   41,   -1,   43,   44,
   45,   -1,  262,   -1,  264,  265,  266,  267,  268,  124,
  270,  271,   -1,   93,   59,   60,   61,   62,   38,   94,
   40,   -1,   -1,   33,   -1,   45,  262,  263,   38,   -1,
   -1,   41,   -1,   -1,   44,   -1,  272,   -1,   -1,   -1,
  276,  277,  278,   63,  124,   -1,   -1,   -1,   93,   59,
   60,   61,   62,   -1,   -1,  257,  258,  259,  265,  266,
  267,  268,  269,  270,   -1,  267,  268,   -1,  270,   -1,
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
   -1,  286,  287,  288,   -1,  124,   -1,  262,  263,   93,
   59,   60,   61,   62,   -1,   -1,   -1,  272,  273,   -1,
  275,  276,  277,  278,   -1,  280,  281,  257,  258,  259,
   -1,  286,  287,  288,   -1,   -1,   -1,   -1,   -1,   -1,
  124,   -1,  262,  263,   93,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  272,  273,   -1,  275,  276,  277,  278,   -1,
  280,  281,   -1,   -1,   -1,   -1,  286,  287,  288,   33,
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
   -1,   47,   -1,   60,   61,   62,    6,   93,   -1,   -1,
   -1,   -1,   -1,   13,   60,   61,   62,   17,   -1,   -1,
   37,   38,   -1,   -1,   -1,   42,   43,   -1,   45,   -1,
   47,   -1,   -1,   33,   -1,   -1,   -1,   94,  124,   -1,
   -1,   -1,   -1,   60,   61,   62,   -1,   -1,   94,   -1,
   -1,   -1,   52,   -1,   54,   -1,   -1,   -1,   -1,   -1,
   37,   38,  286,  287,  288,   42,   43,  124,   45,   -1,
   47,   -1,   -1,  286,  287,  288,   93,   94,  124,  262,
  263,   -1,   59,   60,   61,   62,   -1,   -1,   -1,  272,
  273,   -1,  275,  276,  277,  278,   -1,  280,  281,   -1,
   -1,  275,   -1,  286,   -1,   -1,   -1,  124,   -1,   -1,
   37,   38,  286,  287,  288,   42,   43,   94,   45,   -1,
   47,   37,   38,   -1,   -1,   -1,   42,   43,   -1,   45,
   -1,   47,   -1,   60,   61,   62,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   60,   61,   62,  124,   37,   38,
   -1,   -1,   -1,   42,   43,   -1,   45,   -1,   47,   -1,
   -1,  161,   -1,   -1,   -1,   -1,   93,   94,   -1,   -1,
   -1,   60,   61,   62,   -1,   -1,  262,  263,   94,   -1,
   -1,   -1,   -1,  183,   -1,   -1,  272,  273,   -1,  275,
  276,  277,  278,   -1,  280,  281,   -1,  124,   -1,   -1,
  286,   37,   38,   -1,   -1,   94,   42,   43,  124,   45,
   -1,   47,   38,   -1,   40,   -1,   -1,   -1,   -1,   45,
   -1,   -1,   -1,  280,   60,   61,   62,   -1,   -1,  286,
  287,  288,   -1,   -1,   -1,  124,   -1,   63,   37,   38,
  286,  287,  288,   42,   43,   -1,   45,   -1,   47,   37,
   38,   -1,   -1,   -1,   42,   43,   -1,   45,   94,   47,
   -1,   60,   61,   62,   -1,   -1,   -1,   -1,   -1,  286,
  287,  288,   60,   61,   62,   33,   -1,   -1,   -1,   -1,
   38,   -1,   -1,   41,   -1,   -1,   44,   -1,  124,   -1,
   -1,   -1,   38,   -1,   40,   94,   -1,   33,   -1,   45,
  126,   59,   38,   -1,   -1,   41,   94,   -1,   44,  286,
  287,  288,   -1,   -1,   -1,   -1,   -1,   63,   33,   -1,
   -1,   -1,   -1,   59,   -1,  124,   41,   -1,   -1,   44,
   -1,   -1,   -1,   -1,   -1,   93,   -1,   -1,   -1,   -1,
   -1,   33,   -1,   -1,   59,   -1,   -1,   -1,   -1,   41,
   -1,   -1,   44,   -1,   -1,   -1,   -1,   93,   -1,  286,
  287,  288,   -1,   -1,   -1,  281,  124,   59,   -1,   -1,
  286,  287,  288,   -1,   -1,   38,   -1,   40,   93,   -1,
  126,   -1,   45,   -1,   -1,   -1,  275,   -1,  124,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  286,  287,  288,
   63,   93,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  124,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  257,  258,  259,   -1,   -1,   -1,  273,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,    6,   -1,   -1,  274,   -1,
  286,  287,  288,  279,   -1,   -1,  282,  283,  284,   -1,
   -1,   -1,   -1,  126,   -1,   26,   -1,   -1,   -1,   -1,
   -1,   -1,   33,   -1,   -1,   36,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  286,  287,  288,
   -1,   52,   -1,   -1,   -1,   -1,   -1,   -1,  286,  287,
  288,   -1,   -1,   -1,  262,  263,   -1,   -1,   -1,   -1,
   -1,  257,  258,  259,  272,  273,   -1,  275,  276,  277,
  278,   -1,  280,  281,   -1,   -1,  262,  263,  274,   -1,
   -1,   -1,   -1,  279,   -1,   -1,  272,  273,   -1,  275,
  276,  277,  278,   -1,  280,  281,   -1,  262,  263,   -1,
   -1,   -1,  113,   -1,   -1,   -1,   -1,  272,  273,   -1,
  275,  276,  277,  278,   -1,  280,  281,   -1,   -1,   -1,
  262,  263,   -1,   -1,   -1,   -1,   -1,   -1,   26,   -1,
  272,  273,   -1,  275,  276,  277,  278,   -1,  280,  281,
  151,   39,   40,   -1,  257,  258,  259,   -1,   -1,   -1,
  161,   -1,   -1,   -1,  267,  268,   -1,  270,   56,  170,
   -1,  274,   -1,   -1,   -1,   -1,  279,   65,   66,   -1,
   24,   25,  183,   27,   28,  186,   30,   -1,   -1,   -1,
  191,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  201,   -1,   -1,   -1,   -1,   -1,  207,   -1,   -1,   -1,
   -1,   99,  100,   -1,   58,   59,  104,   -1,  106,   -1,
  108,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   75,   76,   77,   78,   79,   80,   81,   82,   83,
   84,   85,   86,   87,   88,   89,   90,   -1,   -1,   -1,
   -1,   95,  140,   -1,  142,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  114,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  144,   -1,   -1,   -1,  148,   -1,   -1,  195,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  171,   -1,   -1,
   -1,   -1,  176,
};
#define YYFINAL 3
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 305
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
"NIL","DECLS","DECL","FUNCTYPE","QUALIFIER","VARS","VAR","SIZE","BODY",
"RETURN_EXPR","BLOCK","INSTRS","ARGS","LOCAL","CALL",0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"illegal-symbol",
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
"body : bodyvars blockfunc",
"body : blockfunc",
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
"blockfunc :",
"blockfunc : instrterm",
"blockfunc : instrs",
"blockfunc : instrs instrterm",
"instrs : instr",
"instrs : instrs instr",
"lvalue : ID",
"lvalue : ID '[' expr ']'",
"lvalue : string '[' expr ']'",
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
"string : integer integer",
"string : STR",
"string : string STR",
"string : string integer",
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
#line 231 "gram.y"

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
    /* TODO */
	int t1 = arg1->info, t2 = arg2->info;
    t1 = t1 % 5;
    t2 = t2 % 5;
	if (t1 == t2) return 0;
	if (t1 == 3 && t2 == 1) return 0; /* array := int */
	if (t1 == 1 && t2 == 3) return 0; /* int := array */
	if (t1 == 2 && t2 == 1) return 0; /* string := int* */
	if (t1 == 2 && arg2->attrib == INTEGER && arg2->value.i == 0)
		return 0; /* string := 0 */
	if (t1 > 10 && t1 < 20 && arg2->attrib == INTEGER && arg2->value.i == 0)
		return 0; /* pointer := 0 */
	return 1;
}

void declare(Node *qualifier, int cnst, Node *type, char *name, Node *value)
{
  int typ;
  if (!value) {
    if (qualifier) {
        if (qualifier->info == 1 && cnst) {
            yyerror("local constants must be initialised");
        }
    }
    return;
  }
  if (qualifier) {
      if (qualifier->info == 2) {
          yyerror("forward with declaration");
      }
  }
  if (value->attrib = INTEGER && value->value.i == 0 && type->value.i > 10)
  	return; /* NULL pointer */
  if ((typ = value->info) % 10 > 5) typ -= 5;
  if (type->info == 3) {
    if (LEFT_CHILD(type)->value.i != arraysize) {
        yyerror("array size doesn't correspond to attributions");
    }
  }
  else if (type->info != typ) {
    yyerror("wrong types in initialization");
  }
}

void enter(Node *qualifier, int typ, char *name) {
	fpar = malloc(32); /* 31 arguments, at most */
	fpar[0] = 0; /* argument count */
	if (IDfind(name, (long*)IDtest) < 20)
		IDnew(typ+20, name, (long)fpar);
	IDpush();
	if (typ != 4) IDnew(typ, name, 0);
}

void function(Node *qualifier, Node *type, char *name, Node *body)
{
	Node *bloco = LEFT_CHILD(body);
	IDpop();
    if (qualifier) {
        if (qualifier->info == 2 && bloco != 0) {
            yyerror("forward function with body");
        }
        if (qualifier->info == 1 && bloco == 0) {
            yyerror("not forward function without body");
        }
    }
    else if (bloco == 0) {
        yyerror("not forward function without body");
    }
	/* if (bloco != 0) {
		long par;
		int fwd = IDfind(name, &par);
		if (fwd > 40) yyerror("duplicate function");
		else IDreplace(fwd+40, name, par);
	} */
}

int checkargs(char *name, Node *args) {
	char *arg;
	int typ;
        if ((typ = IDsearch(name, (long*)&arg,IDlevel(),1)) < 20) {
		yyerror("ident not a function");
		return 0;
	}
	if (args == 0 && arg[0] == 0)
		;
	else if (args == 0 && arg[0] != 0)
		yyerror("function requires arguments");
	else if (args != 0 && arg[0] == 0)
		yyerror("function requires no arguments");
	else {
		int err = 0, null, i = arg[0], typ;
		do {
			Node *n;
			if (i == 0) {
				yyerror("too many arguments.");
				err = 1;
				break;
			}
			n = RIGHT_CHILD(args);
			typ = n->info;
			if (typ % 10 > 5) typ -= 5; /* remove CONST */
			null =  (n->attrib == INTEGER && n->value.i == 0 && arg[i] > 10) ? 1 : 0;
			if (!null && arg[i] != typ) {
				yyerror("wrong argument type");
				err = 1;
				break;
			}
			args = LEFT_CHILD(args);
			i--;
		} while (args->attrib != NIL);
		if (!err && i > 0)
			yyerror("missing arguments");
	}
	return typ % 20;
}
#line 941 "y.tab.c"

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
#line 57 "gram.y"
	{ printNode(yystack.l_mark[0].n,0,yynames); }
break;
case 2:
#line 58 "gram.y"
	{ printNode(yystack.l_mark[0].n,0,yynames); }
break;
case 3:
#line 61 "gram.y"
	{ yyval.n = binNode(PROGRAM, yystack.l_mark[-3].n, yystack.l_mark[-1].n); }
break;
case 4:
#line 62 "gram.y"
	{ yyval.n = uniNode(PROGRAM, yystack.l_mark[-1].n); }
break;
case 5:
#line 65 "gram.y"
	{ yyval.n = uniNode(MODULE, yystack.l_mark[-1].n); }
break;
case 6:
#line 66 "gram.y"
	{ yyval.n = nilNode(MODULE); }
break;
case 7:
#line 69 "gram.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 8:
#line 70 "gram.y"
	{ yyval.n = binNode(DECLS, yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 9:
#line 73 "gram.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 10:
#line 74 "gram.y"
	{ IDnew(yystack.l_mark[-2].n->info+5, RIGHT_CHILD(yystack.l_mark[-2].n)->value.s, 0); declare(yystack.l_mark[-4].n, 1, yystack.l_mark[-2].n, RIGHT_CHILD(yystack.l_mark[-2].n)->value.s, yystack.l_mark[0].n); yyval.n = binNode(QUALIFIER, yystack.l_mark[-4].n, binNode(VAR, yystack.l_mark[-2].n, yystack.l_mark[0].n)); }
break;
case 11:
#line 75 "gram.y"
	{ IDnew(yystack.l_mark[-2].n->info, RIGHT_CHILD(yystack.l_mark[-2].n)->value.s, 0); declare(yystack.l_mark[-3].n, 0, yystack.l_mark[-2].n, RIGHT_CHILD(yystack.l_mark[-2].n)->value.s, yystack.l_mark[0].n); yyval.n = binNode(QUALIFIER, yystack.l_mark[-3].n, binNode(VAR, yystack.l_mark[-2].n, yystack.l_mark[0].n)); }
break;
case 12:
#line 76 "gram.y"
	{ IDnew(yystack.l_mark[0].n->info, RIGHT_CHILD(yystack.l_mark[0].n)->value.s, 0); declare(yystack.l_mark[-1].n, 0, yystack.l_mark[0].n, RIGHT_CHILD(yystack.l_mark[0].n)->value.s, 0); yyval.n = binNode(DECL, yystack.l_mark[-1].n, yystack.l_mark[0].n); }
break;
case 13:
#line 77 "gram.y"
	{ IDnew(yystack.l_mark[0].n->info+5, RIGHT_CHILD(yystack.l_mark[0].n)->value.s, 0); declare(yystack.l_mark[-2].n, 1, yystack.l_mark[0].n, RIGHT_CHILD(yystack.l_mark[0].n)->value.s, 0); yyval.n = binNode(DECL, yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 14:
#line 78 "gram.y"
	{ IDnew(yystack.l_mark[0].n->info+5, RIGHT_CHILD(yystack.l_mark[0].n)->value.s, 0); declare(0, 1, yystack.l_mark[0].n, RIGHT_CHILD(yystack.l_mark[0].n)->value.s, 0); yyval.n = yystack.l_mark[0].n; }
break;
case 15:
#line 79 "gram.y"
	{ IDnew(yystack.l_mark[-2].n->info+5, RIGHT_CHILD(yystack.l_mark[-2].n)->value.s, 0); declare(0, 1, yystack.l_mark[-2].n, RIGHT_CHILD(yystack.l_mark[-2].n)->value.s, yystack.l_mark[0].n); yyval.n = binNode(DECL, yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 16:
#line 80 "gram.y"
	{ IDnew(yystack.l_mark[0].n->info, RIGHT_CHILD(yystack.l_mark[0].n)->value.s, 0); declare(0, 0, yystack.l_mark[0].n, RIGHT_CHILD(yystack.l_mark[0].n)->value.s, 0); yyval.n = yystack.l_mark[0].n; }
break;
case 17:
#line 81 "gram.y"
	{ IDnew(yystack.l_mark[-2].n->info, RIGHT_CHILD(yystack.l_mark[-2].n)->value.s, 0); declare(0, 0, yystack.l_mark[-2].n, RIGHT_CHILD(yystack.l_mark[-2].n)->value.s, yystack.l_mark[0].n); yyval.n = binNode(DECL, yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 18:
#line 84 "gram.y"
	{ enter(yystack.l_mark[-2].n, yystack.l_mark[-1].n->info, yystack.l_mark[0].s); typereturn = yystack.l_mark[-1].n->info; }
break;
case 19:
#line 84 "gram.y"
	{ yyval.n = binNode(QUALIFIER, yystack.l_mark[-5].n, binNode(FUNCTYPE, yystack.l_mark[-4].n, binNode(ID, strNode(ID, yystack.l_mark[-3].s), binNode(VARS, yystack.l_mark[-1].n, uniNode(END, yystack.l_mark[0].n))))); function(yystack.l_mark[-5].n, yystack.l_mark[-4].n, yystack.l_mark[-3].s, yystack.l_mark[0].n); }
break;
case 20:
#line 85 "gram.y"
	{ enter(0, yystack.l_mark[-1].n->info, yystack.l_mark[0].s); typereturn = yystack.l_mark[-1].n->info; }
break;
case 21:
#line 85 "gram.y"
	{ yyval.n = binNode(FUNCTYPE, yystack.l_mark[-4].n, binNode(ID, strNode(ID, yystack.l_mark[-3].s), binNode(VARS, yystack.l_mark[-1].n, uniNode(END, yystack.l_mark[0].n)))); function(0, yystack.l_mark[-4].n, yystack.l_mark[-3].s, yystack.l_mark[0].n); }
break;
case 22:
#line 86 "gram.y"
	{ enter(yystack.l_mark[-2].n, yystack.l_mark[-1].n->info, yystack.l_mark[0].s); typereturn = yystack.l_mark[-1].n->info; }
break;
case 23:
#line 86 "gram.y"
	{ yyval.n = binNode(QUALIFIER, yystack.l_mark[-4].n, binNode(FUNCTYPE, yystack.l_mark[-3].n, binNode(ID, strNode(ID, yystack.l_mark[-2].s), uniNode(END, yystack.l_mark[0].n)))); function(yystack.l_mark[-4].n, yystack.l_mark[-3].n, yystack.l_mark[-2].s, yystack.l_mark[0].n); }
break;
case 24:
#line 87 "gram.y"
	{ enter(0, yystack.l_mark[-1].n->info, yystack.l_mark[0].s); typereturn = yystack.l_mark[-1].n->info; }
break;
case 25:
#line 87 "gram.y"
	{ yyval.n = binNode(FUNCTYPE, yystack.l_mark[-3].n, binNode(ID, strNode(ID, yystack.l_mark[-2].s), uniNode(END, yystack.l_mark[0].n))); function(0, yystack.l_mark[-3].n, yystack.l_mark[-2].s, yystack.l_mark[0].n); }
break;
case 26:
#line 90 "gram.y"
	{ yyval.n = binNode(DO, 0, 0); }
break;
case 27:
#line 91 "gram.y"
	{ yyval.n = binNode(DO, yystack.l_mark[0].n, 0); }
break;
case 28:
#line 94 "gram.y"
	{ yyval.n = yystack.l_mark[0].n; yyval.n->info = yystack.l_mark[0].n->info; }
break;
case 29:
#line 95 "gram.y"
	{ yyval.n = nilNode(VOID); yyval.n->info = 4; }
break;
case 30:
#line 98 "gram.y"
	{ yyval.n = nilNode(PUBLIC); yyval.n->info = 1; }
break;
case 31:
#line 99 "gram.y"
	{ yyval.n = nilNode(FORWARD); yyval.n->info = 2; }
break;
case 32:
#line 102 "gram.y"
	{ yyval.n = binNode(VARS, yystack.l_mark[0].n, 0); }
break;
case 33:
#line 103 "gram.y"
	{ yyval.n = binNode(VARS, yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 34:
#line 106 "gram.y"
	{ yyval.n = binNode(VAR, uniNode(STRING, nilNode(STRING)), strNode(ID, yystack.l_mark[0].s)); IDnew(2, yystack.l_mark[0].s, 0); if (IDlevel() == 1) fpar[++fpar[0]] = 2; yyval.n->info = 2; }
break;
case 35:
#line 107 "gram.y"
	{ yyval.n = binNode(VAR, uniNode(NUMBER, nilNode(NUMBER)), strNode(ID, yystack.l_mark[0].s)); IDnew(1, yystack.l_mark[0].s, 0); if (IDlevel() == 1) fpar[++fpar[0]] = 1; yyval.n->info = 1; }
break;
case 36:
#line 108 "gram.y"
	{ yyval.n = binNode(VAR, uniNode(ARRAY, nilNode(ARRAY)), strNode(ID, yystack.l_mark[-3].s)); IDnew(3, yystack.l_mark[-3].s, 0); if (IDlevel() == 1) fpar[++fpar[0]] = 3; yyval.n->info = 3; }
break;
case 37:
#line 111 "gram.y"
	{ yyval.n = binNode(VAR, uniNode(STRING, nilNode(STRING)), strNode(ID, yystack.l_mark[0].s)); yyval.n->info = 2; }
break;
case 38:
#line 112 "gram.y"
	{ yyval.n = binNode(VAR, uniNode(NUMBER, nilNode(NUMBER)), strNode(ID, yystack.l_mark[0].s)); yyval.n->info = 1; }
break;
case 39:
#line 113 "gram.y"
	{ yyval.n = binNode(VAR, intNode(SIZE, yystack.l_mark[-1].n->value.i), strNode(ID, yystack.l_mark[-3].s)); yyval.n->info = 3; }
break;
case 40:
#line 114 "gram.y"
	{ yyval.n = binNode(VAR, uniNode(ARRAY, nilNode(ARRAY)), strNode(ID, yystack.l_mark[0].s)); yyval.n->info = 3; }
break;
case 41:
#line 117 "gram.y"
	{ yyval.n = nilNode(NUMBER); yyval.n->info = 1; }
break;
case 42:
#line 118 "gram.y"
	{ yyval.n = nilNode(ARRAY); yyval.n->info = 3; }
break;
case 43:
#line 119 "gram.y"
	{ yyval.n = nilNode(STRING); yyval.n->info = 2; }
break;
case 44:
#line 122 "gram.y"
	{ yyval.n = binNode(BODY, yystack.l_mark[-1].n, yystack.l_mark[0].n); }
break;
case 45:
#line 123 "gram.y"
	{ yyval.n = binNode(BODY, yystack.l_mark[0].n, 0); }
break;
case 46:
#line 126 "gram.y"
	{ yyval.n = binNode(BODY, yystack.l_mark[-1].n, yystack.l_mark[0].n); }
break;
case 47:
#line 127 "gram.y"
	{ yyval.n = binNode(BODY, yystack.l_mark[0].n, 0); }
break;
case 48:
#line 130 "gram.y"
	{ yyval.n = nilNode(NIL); }
break;
case 49:
#line 131 "gram.y"
	{ yyval.n = binNode(BODY, yystack.l_mark[0].n, 0); }
break;
case 50:
#line 134 "gram.y"
	{ IDnew(yystack.l_mark[-1].n->info, RIGHT_CHILD(yystack.l_mark[-1].n)->value.s, 0); yyval.n = binNode(VARS, yystack.l_mark[-1].n, 0); }
break;
case 51:
#line 135 "gram.y"
	{ IDnew(yystack.l_mark[-1].n->info, RIGHT_CHILD(yystack.l_mark[-1].n)->value.s, 0); yyval.n = binNode(VARS, yystack.l_mark[-2].n, yystack.l_mark[-1].n); }
break;
case 52:
#line 138 "gram.y"
	{ yyval.n = binNode(IF, yystack.l_mark[-3].n, yystack.l_mark[-1].n); if (yystack.l_mark[-3].n->info % 5 == 4) yyerror("condition as void expression"); }
break;
case 53:
#line 139 "gram.y"
	{ yyval.n = binNode(IF, yystack.l_mark[-6].n, binNode(THEN, yystack.l_mark[-4].n, binNode(ELIF, yystack.l_mark[-3].n, uniNode(ELSE, yystack.l_mark[-1].n)))); if (yystack.l_mark[-6].n->info % 5 == 4) yyerror("condition as void expression"); }
break;
case 54:
#line 140 "gram.y"
	{ yyval.n = binNode(IF, yystack.l_mark[-4].n, binNode(THEN, yystack.l_mark[-2].n, binNode(ELIF, yystack.l_mark[-1].n, 0))); if (yystack.l_mark[-4].n->info % 5 == 4) yyerror("condition as void expression"); }
break;
case 55:
#line 141 "gram.y"
	{ yyval.n = binNode(IF, yystack.l_mark[-5].n, binNode(THEN, yystack.l_mark[-3].n, uniNode(ELSE, yystack.l_mark[-1].n))); if (yystack.l_mark[-5].n->info % 5 == 4) yyerror("condition as void expression"); }
break;
case 56:
#line 142 "gram.y"
	{ ncicl++; }
break;
case 57:
#line 142 "gram.y"
	{ yyval.n = binNode(FOR, yystack.l_mark[-8].n, binNode(UNTIL, yystack.l_mark[-6].n, binNode(STEP, yystack.l_mark[-4].n, uniNode(DO, yystack.l_mark[-1].n)))); if (yystack.l_mark[-8].n->info % 5 == 4 || yystack.l_mark[-6].n->info % 5 == 4 || yystack.l_mark[-4].n->info % 5 == 4) yyerror("condition as void expression"); ncicl--; }
break;
case 58:
#line 143 "gram.y"
	{ yyval.n = yystack.l_mark[-1].n; }
break;
case 59:
#line 144 "gram.y"
	{ yyval.n = yystack.l_mark[-1].n; if (yystack.l_mark[-1].n->info % 5 == 4) yyerror("printing void expression"); }
break;
case 60:
#line 145 "gram.y"
	{ yyval.n = binNode('#', yystack.l_mark[-3].n, yystack.l_mark[-1].n); }
break;
case 61:
#line 148 "gram.y"
	{ yyval.n = nilNode(REPEAT); if (ncicl <= 0) yyerror("invalid repeat argument"); }
break;
case 62:
#line 149 "gram.y"
	{ yyval.n = nilNode(STOP); if (ncicl <= 0) yyerror("invalid stop argument"); }
break;
case 63:
#line 150 "gram.y"
	{ if (IDlevel() == 0 && yystack.l_mark[0].n->info != 1) yyerror("return non integer out of function"); if (IDlevel() > 0 && typereturn != yystack.l_mark[0].n->info) yyerror("return type differs from function type"); yyval.n = uniNode(RETURN_EXPR, yystack.l_mark[0].n); }
break;
case 64:
#line 151 "gram.y"
	{ if (IDlevel() == 0) yyerror("return void out of function"); if (typereturn != 4) yyerror("return type differs from function type"); yyval.n = nilNode(RETURN); }
break;
case 65:
#line 154 "gram.y"
	{ yyval.n = binNode(ELIF, yystack.l_mark[-2].n, yystack.l_mark[0].n); if (yystack.l_mark[-2].n->info % 5 == 4) yyerror("condition as void expression"); }
break;
case 66:
#line 157 "gram.y"
	{ yyval.n = binNode(ELIF, yystack.l_mark[0].n, 0); }
break;
case 67:
#line 158 "gram.y"
	{ yyval.n = binNode(ELIF, yystack.l_mark[-1].n, yystack.l_mark[0].n); }
break;
case 68:
#line 161 "gram.y"
	{ yyval.n = nilNode(NIL); }
break;
case 69:
#line 162 "gram.y"
	{ yyval.n = binNode(BLOCK, yystack.l_mark[0].n, 0); }
break;
case 70:
#line 163 "gram.y"
	{ yyval.n = binNode(BLOCK, yystack.l_mark[0].n, 0); }
break;
case 71:
#line 164 "gram.y"
	{ yyval.n = binNode(BLOCK, yystack.l_mark[-1].n, yystack.l_mark[0].n); }
break;
case 72:
#line 167 "gram.y"
	{ yyval.n = nilNode(NIL); }
break;
case 73:
#line 168 "gram.y"
	{ yyval.n = binNode(BLOCK, yystack.l_mark[0].n, 0); }
break;
case 74:
#line 169 "gram.y"
	{ yyval.n = binNode(BLOCK, yystack.l_mark[0].n, 0); if (IDlevel() > 0 && typereturn != 4) yyerror("non void function without return"); }
break;
case 75:
#line 170 "gram.y"
	{ yyval.n = binNode(BLOCK, yystack.l_mark[-1].n, yystack.l_mark[0].n); }
break;
case 76:
#line 173 "gram.y"
	{ yyval.n = binNode(INSTRS, yystack.l_mark[0].n, 0); }
break;
case 77:
#line 174 "gram.y"
	{ yyval.n = binNode(INSTRS, yystack.l_mark[-1].n, yystack.l_mark[0].n); }
break;
case 78:
#line 177 "gram.y"
	{ long pos; int typ = IDfind(yystack.l_mark[0].s, &pos); if (pos == 0) yyval.n = strNode(ID, yystack.l_mark[0].s); else yyval.n = intNode(LOCAL, pos); yyval.n->info = typ; }
break;
case 79:
#line 178 "gram.y"
	{ long pos; int typ = IDfind(yystack.l_mark[-3].s, &pos); 
                                        if (pos == 0) yyval.n = strNode(ID, yystack.l_mark[-3].s); else yyval.n = intNode(LOCAL, pos); 
                                        yyval.n = binNode('[', yystack.l_mark[-3].s, yystack.l_mark[-1].n); if (typ != 3 && typ != 2) yyerror("invalid indexation"); intonly(yystack.l_mark[-1].n); yyval.n->info = 1; }
break;
case 80:
#line 181 "gram.y"
	{ yyval.n = binNode('[', yystack.l_mark[-3].n, yystack.l_mark[-1].n); intonly(yystack.l_mark[-1].n); yyval.n->info = 1; }
break;
case 81:
#line 184 "gram.y"
	{ yyval.n = yystack.l_mark[0].n; yyval.n->info = yystack.l_mark[0].n->info; }
break;
case 82:
#line 185 "gram.y"
	{ yyval.n = yystack.l_mark[-1].n; yyval.n->info = yystack.l_mark[-1].n->info; }
break;
case 83:
#line 186 "gram.y"
	{ yyval.n = binNode(CALL, strNode(ID, yystack.l_mark[-3].s), yystack.l_mark[-1].n); long pos; int typ = IDfind(yystack.l_mark[-3].s, &pos); yyval.n->info = checkargs(yystack.l_mark[-3].s, yystack.l_mark[-1].n); }
break;
case 84:
#line 187 "gram.y"
	{ yyval.n = binNode(CALL, strNode(ID, yystack.l_mark[-2].s), nilNode(NIL)); long pos; int typ = IDfind(yystack.l_mark[-2].s, &pos); yyval.n->info = checkargs(yystack.l_mark[-2].s, 0); }
break;
case 85:
#line 188 "gram.y"
	{ yyval.n = yystack.l_mark[0].n; yyval.n->info = 2; }
break;
case 86:
#line 189 "gram.y"
	{ yyval.n = yystack.l_mark[0].n; yyval.n->info = 1; }
break;
case 87:
#line 190 "gram.y"
	{ yyval.n = uniNode(UMINUS, yystack.l_mark[0].n); yyval.n->info = yystack.l_mark[0].n->info; intonly(yystack.l_mark[0].n);}
break;
case 88:
#line 191 "gram.y"
	{ yyval.n = uniNode(ADDR, yystack.l_mark[0].n); yyval.n->info = 1; }
break;
case 89:
#line 192 "gram.y"
	{ yyval.n = binNode('^', yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = intonly(yystack.l_mark[-2].n); intonly(yystack.l_mark[0].n); }
break;
case 90:
#line 193 "gram.y"
	{ yyval.n = binNode('+', yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = intonly(yystack.l_mark[-2].n); intonly(yystack.l_mark[0].n); }
break;
case 91:
#line 194 "gram.y"
	{ yyval.n = binNode('-', yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = intonly(yystack.l_mark[-2].n); intonly(yystack.l_mark[0].n); }
break;
case 92:
#line 195 "gram.y"
	{ yyval.n = binNode('*', yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = intonly(yystack.l_mark[-2].n); intonly(yystack.l_mark[0].n); }
break;
case 93:
#line 196 "gram.y"
	{ yyval.n = binNode('/', yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = intonly(yystack.l_mark[-2].n); intonly(yystack.l_mark[0].n); }
break;
case 94:
#line 197 "gram.y"
	{ yyval.n = binNode('%', yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = intonly(yystack.l_mark[-2].n); intonly(yystack.l_mark[0].n); }
break;
case 95:
#line 198 "gram.y"
	{ yyval.n = binNode('<', yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = 1; sametype(yystack.l_mark[-2].n, yystack.l_mark[0].n); noarray(yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 96:
#line 199 "gram.y"
	{ yyval.n = binNode('>', yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = 1; sametype(yystack.l_mark[-2].n, yystack.l_mark[0].n); noarray(yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 97:
#line 200 "gram.y"
	{ yyval.n = binNode(GE, yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = 1; sametype(yystack.l_mark[-2].n, yystack.l_mark[0].n); noarray(yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 98:
#line 201 "gram.y"
	{ yyval.n = binNode(LE, yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = 1; sametype(yystack.l_mark[-2].n, yystack.l_mark[0].n); noarray(yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 99:
#line 202 "gram.y"
	{ yyval.n = binNode(NE, yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = 1; sametype(yystack.l_mark[-2].n, yystack.l_mark[0].n); noarray(yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 100:
#line 203 "gram.y"
	{ yyval.n = binNode('=', yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = 1; sametype(yystack.l_mark[-2].n, yystack.l_mark[0].n); noarray(yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 101:
#line 204 "gram.y"
	{ yyval.n = binNode(ATTR, yystack.l_mark[-2].n, yystack.l_mark[0].n); if (yyval.n->info % 10 > 5) yyerror("constant value to assignment"); if (noassign(yystack.l_mark[-2].n, yystack.l_mark[0].n)) yyerror("illegal assignment"); yyval.n->info = yystack.l_mark[-2].n->info; }
break;
case 102:
#line 205 "gram.y"
	{ yyval.n = binNode('&', yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = intonly(yystack.l_mark[-2].n); intonly(yystack.l_mark[0].n); }
break;
case 103:
#line 206 "gram.y"
	{ yyval.n = binNode('|', yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = intonly(yystack.l_mark[-2].n); intonly(yystack.l_mark[0].n); }
break;
case 104:
#line 207 "gram.y"
	{ yyval.n = uniNode('~', yystack.l_mark[0].n); yyval.n->info = intonly(yystack.l_mark[0].n); }
break;
case 105:
#line 208 "gram.y"
	{ yyval.n = nilNode('?'); yyval.n->info = 1; }
break;
case 106:
#line 211 "gram.y"
	{ yyval.n = yystack.l_mark[0].n; yyval.n->info = yystack.l_mark[0].n->info; }
break;
case 107:
#line 212 "gram.y"
	{ yyval.n = yystack.l_mark[0].n; yyval.n->info = yystack.l_mark[0].n->info; }
break;
case 108:
#line 215 "gram.y"
	{ yyval.n = intNode(INTEGER, yystack.l_mark[0].i); yyval.n->info = 1; }
break;
case 109:
#line 218 "gram.y"
	{ yyval.n = binNode(STR, yystack.l_mark[-1].n, yystack.l_mark[0].n); yyval.n->info = 2; }
break;
case 110:
#line 219 "gram.y"
	{ yyval.n = binNode(STR, strNode(STR, yystack.l_mark[0].s), 0); yyval.n->info = 2; }
break;
case 111:
#line 220 "gram.y"
	{ yyval.n = binNode(STR, yystack.l_mark[-1].n, yystack.l_mark[0].s); yyval.n->info = 2; }
break;
case 112:
#line 221 "gram.y"
	{ yyval.n = binNode(STR, yystack.l_mark[-1].n, yystack.l_mark[0].n); yyval.n->info = 2; }
break;
case 113:
#line 223 "gram.y"
	{ yyval.n = yystack.l_mark[0].n; yyval.n->info = yystack.l_mark[0].n->info; arraysize = 1; }
break;
case 114:
#line 224 "gram.y"
	{ yyval.n = binNode(',', yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = 3; arraysize++; }
break;
case 115:
#line 227 "gram.y"
	{ yyval.n = binNode(ARGS, nilNode(NIL), yystack.l_mark[0].n); }
break;
case 116:
#line 228 "gram.y"
	{ yyval.n = binNode(ARGS, yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
#line 1609 "y.tab.c"
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
