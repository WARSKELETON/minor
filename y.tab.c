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
#define INTEGERX 285
#define INTEGERLIST 286
#define ATTR 287
#define NE 288
#define LE 289
#define GE 290
#define ADDR 291
#define UMINUS 292
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
   21,   21,   21,   21,   11,   11,   27,   27,
};
static const YYINT yylen[] = {                            2,
    1,    1,    5,    3,    0,    1,    1,    3,    1,    4,
    3,    0,    2,    3,    5,    6,    1,    2,    1,    1,
    0,    1,    1,    0,    1,    1,    3,    2,    1,    1,
    1,    2,    1,    1,    2,    3,    5,    8,    6,    7,
    9,    2,    2,    4,    1,    1,    2,    1,    4,    1,
    2,    0,    1,    1,    2,    1,    2,    1,    4,    2,
    1,    3,    4,    3,    1,    2,    2,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    2,    1,    1,    1,    1,    3,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,    1,    2,    0,   22,   23,    0,    0,
    7,    9,    0,    0,    0,    0,    0,   29,   30,   31,
    0,    0,    0,    4,   20,    0,   19,   86,   58,   85,
    0,    0,   45,   46,    0,    0,    0,    0,    0,   84,
    0,    0,    0,   65,    0,   33,   34,   56,    0,    0,
   53,    0,    8,    0,    0,    0,   11,   28,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    3,   35,
    0,   32,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   42,   43,    0,
    0,    0,   57,   55,   10,   13,    0,   26,    0,    0,
    0,    0,   62,   36,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   64,    0,
    0,    0,    0,    0,    0,   17,    0,   16,    0,    0,
    0,   63,    0,   59,   44,    0,   18,   27,    0,    0,
   37,    0,   50,    0,    0,   15,    0,    0,    0,   39,
   51,    0,   40,    0,    0,    0,   49,   38,    0,   41,
};
static const YYINT yydgoto[] = {                          3,
    4,    5,    9,   42,   10,   11,   12,   13,   43,   57,
   44,   26,   99,  128,   23,  100,   45,   46,   47,   48,
   49,  142,   61,   51,  143,   52,  121,
};
static const YYINT yysindex[] = {                      -242,
  -99,  -99,    0,    0,    0, -187,    0,    0, -259,   -8,
    0,    0, -233, -210, -165, 1208,  -99,    0,    0,    0,
 -245,  -76, -191,    0,    0, -184,    0,    0,    0,    0,
  410,  410,    0,    0,  410,  410,  410,  410,  -36,    0,
  410, -168,   50,    0, 1208,    0,    0,    0,  800,  -34,
    0,  479,    0,  -76, -226, -146,    0,    0, -245,  896,
  -75,  907, 1195,   81,  263,   81,   40,  935,    0,    0,
   71,    0,  410,  410,  410,  410,  410,  410,  410,  410,
  410,  410,  410,  410,  410,  410,  101,    0,    0,  410,
  410,  410,    0,    0,    0,    0,   45,    0, -185,   86,
  479,  410,    0,    0, 1221,  263,  176,  176,  137,  137,
  137,  137,   12,   12,  -23,  -23,  -23,  -23,    0, 1195,
   -2, 1195,  985, 1011, -140,    0, 1208,    0, -245,  -27,
 1056,    0,  410,    0,    0, -226,    0,    0,  479,  410,
    0,  -16,    0,  410, 1195,    0, -121, 1115,  479,    0,
    0, 1168,    0,  479, -103,  479,    0,    0,  -96,    0,
};
static const YYINT yyrindex[] = {                         0,
  -65, -178,    0,    0,    0, -108,    0,    0,    0, -148,
    0,    0,    0,    0,    0,  -85, -142,    0,    0,    0,
    0,  -38,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  214,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  -29,    0,    0,    0,    0,  831,
    0,  444,    0,  -38,    0,    0,    0,    0, -149,    0,
    3,    0,  525,   39, 1095,   75,  -33,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0, -122,
   -9,    0,    0,    0, 1148, 1269,  731,  868,  467,  505,
  542,  642,  401,  437,  111,  148,  334,  371,    0,   25,
    0, 1289,    0,    0,   -4,    0,  -29,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  -95,    0,
    0,    0,    0,    0,   66,    0,    0,    0,  -95,    0,
    0,    0,    0,   -9,    0,  -84,    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
    0,    0,  185,   67,    0,  179,    0,  192,   11,  146,
  -42,    0,    0,    0,  186,    0,    0,  169,  -81,  163,
 1498,    0, 1347,  165,   78,    0,    0,
};
#define YYTABLESIZE 1642
static const YYINT yytable[] = {                         60,
   92,   60,   16,   60,   60,   39,   60,   60,   60,   60,
   60,   60,   96,   60,   56,   91,   87,    1,    2,  130,
   12,   18,   19,   22,   20,   60,   60,   60,   60,   52,
   28,   54,   30,   18,   19,   61,   20,   21,  132,   61,
   61,  133,   61,   61,   61,   61,   61,   61,   85,   61,
   17,   87,   24,   83,   14,   71,   91,  147,   84,   60,
   60,   61,   61,   61,   61,   87,   58,  155,   87,   98,
   86,   67,  157,   59,  159,   67,   67,    7,    8,   67,
   67,   67,   67,   67,    5,   67,  126,  127,   21,   21,
   60,   21,   21,  146,   69,   61,   61,   67,   67,   67,
   67,   18,   19,   25,   20,   86,   88,   66,   70,   88,
   97,   66,   66,    6,    6,   66,   66,   66,   66,   66,
   87,   66,   24,   24,   21,   21,   61,   21,   21,  104,
   91,   67,   67,   66,   66,   66,   66,  125,   36,  138,
   41,  119,   39,   71,  129,   38,  136,   71,   71,   25,
   25,   71,   71,   71,   71,   71,  153,   71,   21,   21,
   21,   21,   67,   40,    6,    7,    8,   66,   66,   71,
   71,   71,   71,   85,  158,  160,   87,   52,   83,   81,
   72,   82,   52,   84,   72,   72,   14,   52,   72,   72,
   72,   72,   72,  137,   72,   53,    5,   15,   66,   95,
   27,   21,   21,   71,   21,   21,   72,   72,   72,   72,
   55,   90,   85,   72,   93,   87,   94,   83,   81,  151,
   82,   29,   84,   12,   12,    0,   37,    0,   60,   60,
   86,    0,   52,   52,   71,   77,    0,   78,   60,   60,
   72,   60,   60,   60,   60,    0,   60,   60,  139,  140,
  141,    0,   90,   60,   60,   60,   60,   14,   14,  149,
  140,  150,    0,    0,   61,   61,   52,   52,   52,   86,
    0,   72,   48,    0,   61,   61,    0,   61,   61,   61,
   61,    0,   61,   61,    0,    0,    0,    0,    0,    0,
   61,   61,   61,    0,    0,    0,    0,    0,    0,   85,
   67,   67,   87,    0,   83,   81,    0,   82,    0,   84,
   67,   67,    0,   67,   67,   67,   67,    0,   67,   67,
    0,    0,   77,   76,   78,    0,   67,   67,   67,    0,
    0,    0,    0,    0,    0,    0,   66,   66,    0,    0,
    0,    0,    0,    0,    0,    0,   66,   66,    0,   66,
   66,   66,   66,    0,   66,   66,   86,   28,   29,   30,
    0,    0,   66,   66,   66,    0,   73,    0,    0,    0,
   73,   73,   71,   71,   73,   73,   73,   73,   73,    0,
   73,    0,   71,   71,    0,   71,   71,   71,   71,    0,
   71,   71,   73,   73,   73,   73,    0,    0,   71,   71,
   71,    0,    0,   68,    0,    0,    0,   68,   68,   72,
   72,   68,   68,   68,   68,   68,    0,   68,    0,   72,
   72,    0,   72,   72,   72,   72,   73,   72,   72,   68,
   68,   68,   68,   69,    0,   72,   72,   72,   69,    0,
    0,   69,    0,   69,   69,   69,    0,   36,    0,   41,
    0,   39,    0,    0,   38,    0,    0,   73,    0,   69,
   69,   69,   69,   68,   79,   80,    0,    0,    0,   70,
    0,    0,   40,    0,   70,   48,   48,   70,    0,   70,
   70,   70,    0,    0,    0,   48,    0,    0,    0,   48,
   48,   48,    0,   69,   68,   70,   70,   70,   70,   74,
    0,    0,   54,    0,   74,    0,    0,   74,    0,    0,
   74,    0,    0,    0,    0,    0,   36,    0,   41,    0,
   39,    0,    0,   38,   69,   74,   74,   74,   74,   70,
    0,    0,    0,    0,    0,   37,    0,   75,    0,    0,
    0,   40,   75,    0,    0,   75,    0,    0,   75,    0,
   75,   79,   80,    0,    0,    0,    0,    0,    0,   74,
   70,    0,    0,   75,   75,   75,   75,    0,    0,    0,
    0,    0,    0,    0,   77,    0,    0,    0,    0,   77,
    0,    0,   77,   47,    0,   77,    0,    0,    0,    0,
   74,    0,    0,    0,    0,   73,   73,   75,    0,    0,
   77,   77,   77,   77,   37,   73,   73,    0,   73,   73,
   73,   73,    0,   73,   73,    0,    0,    0,    0,    0,
    0,   73,   73,   73,    0,    0,    0,    0,   75,    0,
    0,    0,   68,   68,   77,    0,    0,    0,    0,    0,
    0,    0,   68,   68,    0,   68,   68,   68,   68,    0,
   68,   68,    0,    0,    0,    0,    0,    0,   68,   68,
   68,    0,   69,   69,    0,   77,   28,   29,   30,    0,
    0,    0,   69,   69,   76,   69,   69,   69,   69,   76,
   69,   69,   76,    0,    0,   76,    0,    0,   69,   69,
   69,    0,    0,    0,    0,    0,    0,    0,   70,   70,
   76,   76,   76,   76,    0,   54,   54,    0,   70,   70,
    0,   70,   70,   70,   70,   54,   70,   70,    0,   54,
   54,   54,    0,    0,   70,   70,   70,    0,   74,   74,
    0,    0,    0,    0,   76,   28,   29,   30,   74,   74,
    0,   74,   74,   74,   74,    0,   74,   74,    0,    0,
    0,    0,   31,    0,   74,   74,   74,   32,    0,    0,
   33,   34,   35,   78,    0,   76,   75,   75,   78,    0,
    0,   78,    0,    0,   78,    0,   75,   75,    0,   75,
   75,   75,   75,    0,   75,   75,   47,   47,    0,   78,
    0,   78,   75,   75,   75,    0,   47,    0,    0,    0,
   47,   47,   47,   77,   77,    0,    0,    0,    0,    0,
    0,    0,    0,   77,   77,    0,   77,   77,   77,   77,
    0,   77,   77,   78,    0,    0,    0,    0,    0,   77,
   77,   77,   89,    0,    0,    0,   85,   74,    0,   87,
    0,   83,   81,    0,   82,    0,   84,    0,    0,    0,
    0,    0,    0,    0,   78,    0,    0,    0,   88,   77,
   76,   78,    0,   61,    0,    0,    0,   61,   61,    0,
   61,    0,   61,   61,    0,   61,    0,   61,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   61,
   61,   61,   61,   86,    0,    0,    0,    0,    0,    0,
   79,    0,    0,   76,   76,   79,    0,    0,   79,    0,
    0,   79,    0,   76,   76,    0,   76,   76,   76,   76,
    0,   76,   76,   73,   61,    0,   79,    0,   79,   76,
   76,   76,   85,   74,    0,   87,    0,   83,   81,    0,
   82,    0,   84,   85,   74,    0,   87,    0,   83,   81,
    0,   82,    0,   84,   61,   77,   76,   78,    0,    0,
   79,    0,    0,    0,    0,    0,   77,   76,   78,    0,
    0,   85,   74,    0,   87,  103,   83,   81,    0,   82,
    0,   84,    0,    0,    0,    0,    0,    0,    0,   86,
    0,   79,   78,   78,   77,   76,   78,    0,    0,    0,
   86,    0,   78,   78,    0,   78,   78,   78,   78,    0,
   78,   78,    0,    0,    0,    0,    0,    0,   78,   73,
    0,   85,   74,    0,   87,    0,   83,   81,   86,   82,
   73,   84,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   77,   76,   78,   85,   74,    0,
   87,    0,   83,   81,    0,   82,    0,   84,   73,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  135,
   77,   76,   78,    0,    0,    0,    0,  134,   86,    0,
    0,    0,    0,    0,    0,    0,    0,   75,   79,   80,
    0,    0,   85,   74,    0,   87,    0,   83,   81,    0,
   82,    0,   84,    0,   86,    0,    0,    0,   73,    0,
    0,    0,    0,    0,    0,   77,   76,   78,   61,   61,
   61,    0,    0,    0,    0,    0,    0,   83,    0,   79,
   79,    0,   83,    0,   73,   83,    0,    0,   83,   79,
   79,    0,   79,   79,   79,   79,    0,   79,   79,   86,
    0,   85,   74,   83,   87,   79,   83,   81,    0,   82,
    0,   84,    0,    0,    0,    0,    0,    0,    0,    0,
  101,    0,    0,    0,   77,   76,   78,    0,    0,   73,
   82,    0,    0,   75,   79,   80,  102,   83,   82,    0,
    0,   82,    0,    0,   75,   79,   80,    0,    0,    0,
    0,    0,    0,    0,   85,   74,   82,   87,   86,   83,
   81,    0,   82,    0,   84,    0,    0,    0,   83,    0,
    0,    0,   75,   79,   80,    0,    0,   77,   76,   78,
    0,   85,   74,    0,   87,    0,   83,   81,   73,   82,
   82,   84,    0,    0,    0,   36,    0,   41,    0,   39,
    0,    0,   38,    0,   77,   76,   78,   85,   74,    0,
   87,   86,   83,   81,    0,   82,    0,   84,    0,    0,
   40,   82,   75,   79,   80,    0,    0,    0,    0,    0,
   77,   76,   78,    0,    0,    0,    0,    0,   86,    0,
    0,   73,    0,    0,    0,    0,    0,    0,   75,   79,
   80,   81,    0,    0,    0,    0,   81,    0,    0,   81,
    0,    0,   81,    0,   86,    0,    0,    0,   73,    0,
    0,   80,    0,    0,    0,    0,    0,   81,    0,   80,
    0,    0,   80,   37,    0,    0,  144,    0,    0,    0,
    0,    0,    0,   75,   79,   80,    0,   80,    0,    0,
    0,    0,    0,    0,    0,    0,   83,   83,    0,    0,
    0,   81,   50,    0,    0,    0,   83,   83,    0,   83,
   83,   83,   83,    0,   83,   83,    0,    0,    0,    0,
    0,   80,    0,    0,    0,   67,    0,    0,    0,  154,
    0,   50,   81,    0,    0,    0,    0,    0,   50,    0,
    0,    0,   75,   79,   80,    0,    0,    0,    0,   82,
   82,    0,    0,    0,    0,    0,    0,    0,    0,   82,
   82,    0,   82,   82,   82,   82,    0,   82,   82,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  156,    0,    0,    0,    0,    0,    0,   50,    0,    0,
    0,    0,    0,    0,    0,   75,   79,   80,    0,    0,
    0,    0,    0,    0,   28,   29,   30,    0,    0,    0,
    0,    0,    0,   50,   18,   19,    0,   20,    0,    0,
    0,   31,   75,   79,   80,   50,   32,    0,    0,   33,
   34,   35,    0,    0,    0,   50,    0,    0,    0,    0,
   50,    0,   50,    0,    0,    0,    0,    0,   75,   79,
   80,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   60,   62,
   81,   81,   63,   64,   65,   66,    0,    0,   68,    0,
   81,   81,    0,   81,   81,   81,   81,    0,   81,   81,
   80,   80,    0,    0,    0,    0,    0,    0,    0,    0,
   80,   80,    0,   80,   80,   80,   80,    0,   80,   80,
  105,  106,  107,  108,  109,  110,  111,  112,  113,  114,
  115,  116,  117,  118,  120,    0,    0,  122,  123,  124,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  131,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  145,    0,    0,    0,    0,    0,    0,  148,    0,    0,
    0,  152,
};
static const YYINT yycheck[] = {                         33,
   35,   35,  262,   37,   38,   42,   40,   41,   42,   43,
   44,   45,   55,   47,   91,   91,   40,  260,  261,  101,
   59,  267,  268,   13,  270,   59,   60,   61,   62,   59,
  257,   21,  259,  267,  268,   33,  270,  271,   41,   37,
   38,   44,   40,   41,   42,   43,   44,   45,   37,   47,
   59,   40,  263,   42,   59,   45,   91,  139,   47,   93,
   94,   59,   60,   61,   62,   41,  258,  149,   44,   59,
   94,   33,  154,  258,  156,   37,   38,  265,  266,   41,
   42,   43,   44,   45,  263,   47,  272,  273,  267,  268,
  124,  270,  271,  136,  263,   93,   94,   59,   60,   61,
   62,  267,  268,  269,  270,   94,   41,   33,   59,   44,
  257,   37,   38,  262,  263,   41,   42,   43,   44,   45,
   40,   47,  272,  273,  267,  268,  124,  270,  271,   59,
   91,   93,   94,   59,   60,   61,   62,   93,   38,  129,
   40,   41,   42,   33,   59,   45,  287,   37,   38,  272,
  273,   41,   42,   43,   44,   45,  278,   47,  267,  268,
  269,  270,  124,   63,  264,  265,  266,   93,   94,   59,
   60,   61,   62,   37,  278,  272,   40,  263,   42,   43,
   33,   45,  278,   47,   37,   38,    2,  272,   41,   42,
   43,   44,   45,  127,   47,   17,  262,    6,  124,   54,
   15,  267,  268,   93,  270,  271,   59,   60,   61,   62,
  287,  287,   37,   45,   52,   40,   52,   42,   43,  142,
   45,  258,   47,  262,  263,   -1,  126,   -1,  262,  263,
   94,   -1,  262,  263,  124,   60,   -1,   62,  272,  273,
   93,  275,  276,  277,  278,   -1,  280,  281,  276,  277,
  278,   -1,  287,  287,  288,  289,  290,  262,  263,  276,
  277,  278,   -1,   -1,  262,  263,  276,  277,  278,   94,
   -1,  124,   59,   -1,  272,  273,   -1,  275,  276,  277,
  278,   -1,  280,  281,   -1,   -1,   -1,   -1,   -1,   -1,
  288,  289,  290,   -1,   -1,   -1,   -1,   -1,   -1,   37,
  262,  263,   40,   -1,   42,   43,   -1,   45,   -1,   47,
  272,  273,   -1,  275,  276,  277,  278,   -1,  280,  281,
   -1,   -1,   60,   61,   62,   -1,  288,  289,  290,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  262,  263,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  272,  273,   -1,  275,
  276,  277,  278,   -1,  280,  281,   94,  257,  258,  259,
   -1,   -1,  288,  289,  290,   -1,   33,   -1,   -1,   -1,
   37,   38,  262,  263,   41,   42,   43,   44,   45,   -1,
   47,   -1,  272,  273,   -1,  275,  276,  277,  278,   -1,
  280,  281,   59,   60,   61,   62,   -1,   -1,  288,  289,
  290,   -1,   -1,   33,   -1,   -1,   -1,   37,   38,  262,
  263,   41,   42,   43,   44,   45,   -1,   47,   -1,  272,
  273,   -1,  275,  276,  277,  278,   93,  280,  281,   59,
   60,   61,   62,   33,   -1,  288,  289,  290,   38,   -1,
   -1,   41,   -1,   43,   44,   45,   -1,   38,   -1,   40,
   -1,   42,   -1,   -1,   45,   -1,   -1,  124,   -1,   59,
   60,   61,   62,   93,  289,  290,   -1,   -1,   -1,   33,
   -1,   -1,   63,   -1,   38,  262,  263,   41,   -1,   43,
   44,   45,   -1,   -1,   -1,  272,   -1,   -1,   -1,  276,
  277,  278,   -1,   93,  124,   59,   60,   61,   62,   33,
   -1,   -1,   59,   -1,   38,   -1,   -1,   41,   -1,   -1,
   44,   -1,   -1,   -1,   -1,   -1,   38,   -1,   40,   -1,
   42,   -1,   -1,   45,  124,   59,   60,   61,   62,   93,
   -1,   -1,   -1,   -1,   -1,  126,   -1,   33,   -1,   -1,
   -1,   63,   38,   -1,   -1,   41,   -1,   -1,   44,   -1,
  288,  289,  290,   -1,   -1,   -1,   -1,   -1,   -1,   93,
  124,   -1,   -1,   59,   60,   61,   62,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   33,   -1,   -1,   -1,   -1,   38,
   -1,   -1,   41,   59,   -1,   44,   -1,   -1,   -1,   -1,
  124,   -1,   -1,   -1,   -1,  262,  263,   93,   -1,   -1,
   59,   60,   61,   62,  126,  272,  273,   -1,  275,  276,
  277,  278,   -1,  280,  281,   -1,   -1,   -1,   -1,   -1,
   -1,  288,  289,  290,   -1,   -1,   -1,   -1,  124,   -1,
   -1,   -1,  262,  263,   93,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  272,  273,   -1,  275,  276,  277,  278,   -1,
  280,  281,   -1,   -1,   -1,   -1,   -1,   -1,  288,  289,
  290,   -1,  262,  263,   -1,  124,  257,  258,  259,   -1,
   -1,   -1,  272,  273,   33,  275,  276,  277,  278,   38,
  280,  281,   41,   -1,   -1,   44,   -1,   -1,  288,  289,
  290,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  262,  263,
   59,   60,   61,   62,   -1,  262,  263,   -1,  272,  273,
   -1,  275,  276,  277,  278,  272,  280,  281,   -1,  276,
  277,  278,   -1,   -1,  288,  289,  290,   -1,  262,  263,
   -1,   -1,   -1,   -1,   93,  257,  258,  259,  272,  273,
   -1,  275,  276,  277,  278,   -1,  280,  281,   -1,   -1,
   -1,   -1,  274,   -1,  288,  289,  290,  279,   -1,   -1,
  282,  283,  284,   33,   -1,  124,  262,  263,   38,   -1,
   -1,   41,   -1,   -1,   44,   -1,  272,  273,   -1,  275,
  276,  277,  278,   -1,  280,  281,  262,  263,   -1,   59,
   -1,   61,  288,  289,  290,   -1,  272,   -1,   -1,   -1,
  276,  277,  278,  262,  263,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  272,  273,   -1,  275,  276,  277,  278,
   -1,  280,  281,   93,   -1,   -1,   -1,   -1,   -1,  288,
  289,  290,   33,   -1,   -1,   -1,   37,   38,   -1,   40,
   -1,   42,   43,   -1,   45,   -1,   47,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  124,   -1,   -1,   -1,   59,   60,
   61,   62,   -1,   33,   -1,   -1,   -1,   37,   38,   -1,
   40,   -1,   42,   43,   -1,   45,   -1,   47,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   59,
   60,   61,   62,   94,   -1,   -1,   -1,   -1,   -1,   -1,
   33,   -1,   -1,  262,  263,   38,   -1,   -1,   41,   -1,
   -1,   44,   -1,  272,  273,   -1,  275,  276,  277,  278,
   -1,  280,  281,  124,   94,   -1,   59,   -1,   61,  288,
  289,  290,   37,   38,   -1,   40,   -1,   42,   43,   -1,
   45,   -1,   47,   37,   38,   -1,   40,   -1,   42,   43,
   -1,   45,   -1,   47,  124,   60,   61,   62,   -1,   -1,
   93,   -1,   -1,   -1,   -1,   -1,   60,   61,   62,   -1,
   -1,   37,   38,   -1,   40,   41,   42,   43,   -1,   45,
   -1,   47,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   94,
   -1,  124,  262,  263,   60,   61,   62,   -1,   -1,   -1,
   94,   -1,  272,  273,   -1,  275,  276,  277,  278,   -1,
  280,  281,   -1,   -1,   -1,   -1,   -1,   -1,  288,  124,
   -1,   37,   38,   -1,   40,   -1,   42,   43,   94,   45,
  124,   47,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   60,   61,   62,   37,   38,   -1,
   40,   -1,   42,   43,   -1,   45,   -1,   47,  124,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   59,
   60,   61,   62,   -1,   -1,   -1,   -1,   93,   94,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  288,  289,  290,
   -1,   -1,   37,   38,   -1,   40,   -1,   42,   43,   -1,
   45,   -1,   47,   -1,   94,   -1,   -1,   -1,  124,   -1,
   -1,   -1,   -1,   -1,   -1,   60,   61,   62,  288,  289,
  290,   -1,   -1,   -1,   -1,   -1,   -1,   33,   -1,  262,
  263,   -1,   38,   -1,  124,   41,   -1,   -1,   44,  272,
  273,   -1,  275,  276,  277,  278,   -1,  280,  281,   94,
   -1,   37,   38,   59,   40,  288,   42,   43,   -1,   45,
   -1,   47,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  275,   -1,   -1,   -1,   60,   61,   62,   -1,   -1,  124,
   33,   -1,   -1,  288,  289,  290,  280,   93,   41,   -1,
   -1,   44,   -1,   -1,  288,  289,  290,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   37,   38,   59,   40,   94,   42,
   43,   -1,   45,   -1,   47,   -1,   -1,   -1,  124,   -1,
   -1,   -1,  288,  289,  290,   -1,   -1,   60,   61,   62,
   -1,   37,   38,   -1,   40,   -1,   42,   43,  124,   45,
   93,   47,   -1,   -1,   -1,   38,   -1,   40,   -1,   42,
   -1,   -1,   45,   -1,   60,   61,   62,   37,   38,   -1,
   40,   94,   42,   43,   -1,   45,   -1,   47,   -1,   -1,
   63,  124,  288,  289,  290,   -1,   -1,   -1,   -1,   -1,
   60,   61,   62,   -1,   -1,   -1,   -1,   -1,   94,   -1,
   -1,  124,   -1,   -1,   -1,   -1,   -1,   -1,  288,  289,
  290,   33,   -1,   -1,   -1,   -1,   38,   -1,   -1,   41,
   -1,   -1,   44,   -1,   94,   -1,   -1,   -1,  124,   -1,
   -1,   33,   -1,   -1,   -1,   -1,   -1,   59,   -1,   41,
   -1,   -1,   44,  126,   -1,   -1,  281,   -1,   -1,   -1,
   -1,   -1,   -1,  288,  289,  290,   -1,   59,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  262,  263,   -1,   -1,
   -1,   93,   16,   -1,   -1,   -1,  272,  273,   -1,  275,
  276,  277,  278,   -1,  280,  281,   -1,   -1,   -1,   -1,
   -1,   93,   -1,   -1,   -1,   39,   -1,   -1,   -1,  275,
   -1,   45,  124,   -1,   -1,   -1,   -1,   -1,   52,   -1,
   -1,   -1,  288,  289,  290,   -1,   -1,   -1,   -1,  262,
  263,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  272,
  273,   -1,  275,  276,  277,  278,   -1,  280,  281,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  273,   -1,   -1,   -1,   -1,   -1,   -1,  101,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  288,  289,  290,   -1,   -1,
   -1,   -1,   -1,   -1,  257,  258,  259,   -1,   -1,   -1,
   -1,   -1,   -1,  127,  267,  268,   -1,  270,   -1,   -1,
   -1,  274,  288,  289,  290,  139,  279,   -1,   -1,  282,
  283,  284,   -1,   -1,   -1,  149,   -1,   -1,   -1,   -1,
  154,   -1,  156,   -1,   -1,   -1,   -1,   -1,  288,  289,
  290,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   31,   32,
  262,  263,   35,   36,   37,   38,   -1,   -1,   41,   -1,
  272,  273,   -1,  275,  276,  277,  278,   -1,  280,  281,
  262,  263,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  272,  273,   -1,  275,  276,  277,  278,   -1,  280,  281,
   73,   74,   75,   76,   77,   78,   79,   80,   81,   82,
   83,   84,   85,   86,   87,   -1,   -1,   90,   91,   92,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  102,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  133,   -1,   -1,   -1,   -1,   -1,   -1,  140,   -1,   -1,
   -1,  144,
};
#define YYFINAL 3
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 292
#define YYUNDFTOKEN 322
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
"UNTIL","STEP","REPEAT","STOP","RETURN","INTEGERX","INTEGERLIST","ATTR","NE",
"LE","GE","ADDR","UMINUS",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,"illegal-symbol",
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
"literal : STR",
"literal : INTEGER",
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
#line 183 "gram.y"

char **yynames =
#if YYDEBUG > 0
		 (char**)yyname;
#else
		 0;
#endif
#line 697 "y.tab.c"

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
