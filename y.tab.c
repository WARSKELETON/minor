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
#define ADDR 285
#define UMINUS 286
#define LE 287
#define GE 288
#define NE 289
#define ATTR 290
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    0,    1,    2,    3,    3,    5,    5,    6,    6,
    6,    6,    6,    7,   13,   13,   11,   11,    8,    8,
    8,   12,   12,   15,   15,    9,   14,   14,   14,    4,
    4,    4,    4,   17,   16,   16,   19,   19,   19,   19,
   19,   19,   19,   19,   19,   19,   19,   22,   21,   21,
   18,   18,   23,   23,   23,   20,   20,   20,   20,   20,
   20,   20,   20,   20,   20,   20,   20,   20,   20,   20,
   20,   20,   20,   20,   20,   20,   20,   10,   10,   24,
   24,
};
static const YYINT yylen[] = {                            2,
    1,    1,    5,    3,    0,    1,    1,    3,    1,    5,
    3,    4,    2,    6,    1,    2,    1,    1,    0,    1,
    1,    0,    1,    1,    3,    2,    1,    1,    1,    0,
    2,    1,    1,    2,    2,    3,    5,    8,    6,    7,
    9,    2,    2,    1,    1,    2,    1,    4,    1,    2,
    0,    2,    1,    4,    2,    1,    3,    4,    3,    1,
    2,    2,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    2,    1,    1,    1,
    3,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,    1,    2,    0,   20,   21,    0,    0,
    7,    9,    0,    0,    0,    0,    0,   27,   28,   29,
    0,    0,    0,    4,   18,    0,   17,    0,    0,    0,
   32,    0,    8,    0,    0,   26,    0,    3,   35,    0,
   31,   78,   53,   79,    0,    0,   44,   45,    0,    0,
    0,    0,    0,    0,   60,    0,    0,    0,    0,   12,
   24,    0,    0,   36,    0,    0,    0,    0,   55,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   42,   43,    0,    0,
   10,   15,    0,   14,    0,   51,    0,   57,   59,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   76,    0,   74,   16,   25,    0,    0,
   58,    0,   54,   51,    0,   37,   52,    0,   49,    0,
    0,    0,    0,   51,   39,   50,    0,   40,   51,    0,
   51,    0,   38,    0,   41,
};
static const YYINT yydgoto[] = {                          3,
    4,    5,    9,   28,   10,   11,   12,   13,   29,   55,
   26,   62,   94,   23,   63,   30,   31,   32,  127,   57,
  128,  129,   58,  101,
};
static const YYINT yysindex[] = {                      -118,
 -129, -129,    0,    0,    0, -120,    0,    0, -259,  -38,
    0,    0, -234, -238,  -97, -202, -129,    0,    0,    0,
 -202, -260, -226,    0,    0, -220,    0, -215,   14, -202,
    0,  896,    0, -219, -240,    0, -202,    0,    0,   26,
    0,    0,    0,    0,   80,   80,    0,    0,  -22,   80,
  -27,   80,   80,   80,    0,    0,  142,  -69, -240,    0,
    0, -117,   33,    0,  494,  505,  758,  541,    0,  789,
  -36,  789,   12,   80,   80,   80,   80,   80,   80,   80,
   80,   80,   80,   80,   80,   80,    0,    0,   80,   80,
    0,    0, -202,    0, -202,    0,   80,    0,    0,  758,
   31,  675,  675,  675,  784,  784,  -37,  -37,  -37,  -37,
  -36,  -36,  -34,    0,  552,    0,    0,    0,  954,  588,
    0,   80,    0,    0,   80,    0,    0, -100,    0,   80,
  758, 1246,  632,    0,    0,    0,  728,    0,    0, 1314,
    0,  896,    0, 1342,    0,
};
static const YYINT yyrindex[] = {                         0,
 -160, -110,    0,    0,    0,  -77,    0,    0,    0,  -49,
    0,    0,    0,    0,    0, 1354, -144,    0,    0,    0,
    0,  -53,    0,    0,    0,    0,    0,    0,    0, 1216,
    0,    0,    0,   10,    0,    0,  -45,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0, 1140,    0,
    0,    0,    0,    0,    0, 1274,    0,  -33,    0,    0,
    0,    0,  -15,    0,    0,    0, 1187,    0,    0, 1020,
   37, 1048,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0, 1303,    0,    0,    0,    0,    0,    0,   45,
    0,  914,  943,  990,  846,  885,  175,  380,  427,  467,
   72,  107,    2,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   59,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  -82,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
    0,    0,   92,    8,    0,   89,    0,  115,   46,   -4,
    0,    0,    0,  114,    0,    0,  109,  -83,  127, 1594,
    0,   34,  113,    0,
};
#define YYTABLESIZE 1724
static const YYINT yytable[] = {                         56,
   85,   85,   16,   56,   56,   13,   56,   56,   56,   56,
   56,   56,  119,   56,   51,   54,   42,   50,   44,   51,
   17,   89,   52,   84,   24,   56,   56,   56,   56,   35,
   60,   36,   18,   19,   75,   20,   21,   37,   75,   75,
  132,   75,   75,   75,   75,   75,   75,   38,   75,   54,
  140,   50,   99,   51,   91,  142,   52,  144,   22,   56,
   75,   75,   75,   75,   18,   19,   34,   20,   11,   77,
   59,  121,   39,   77,  122,   40,   77,   77,   77,   77,
   77,   77,   61,   77,   64,   80,   86,   86,   80,   86,
   56,   95,   56,   14,   75,   77,   77,   77,   77,   81,
  117,    5,   81,   53,   72,   33,   19,   19,   72,   19,
   19,   72,   72,   72,   72,   72,   72,   54,   72,   50,
   15,   51,   19,   19,   52,   19,   19,   75,   27,   77,
   72,   72,   72,   72,    6,    7,    8,   53,   41,   73,
  118,    1,    2,   73,    7,    8,   73,   73,   73,   73,
   73,   73,    5,   73,   92,   93,   19,   19,   56,   19,
   19,  136,   77,   69,   72,   73,   73,   73,   73,   18,
   19,   25,   20,    0,   88,  134,  125,  135,   76,   85,
    0,   73,    0,   74,   77,    0,   78,    0,   75,   19,
   19,   19,   19,   48,   48,   48,    0,   72,    0,   73,
   87,   79,   84,   80,    0,   53,    0,   68,   13,   13,
    0,   68,    6,    6,   68,   68,   68,   68,   68,   68,
   90,   68,    0,   56,   56,   56,   22,   22,   56,   56,
   43,    0,   73,   68,   68,    0,   68,    0,   56,   56,
   56,   56,   56,   56,   56,   56,   56,   56,   56,   56,
   56,   83,    0,   56,   56,   56,   23,   23,   75,   75,
   75,    0,    0,   75,   75,   86,    0,   68,   42,   43,
   44,   11,   11,   75,   75,   75,   75,   75,   75,   75,
   75,   75,   75,   75,   75,   75,    0,    0,   75,   75,
   75,    0,    0,   77,   77,   77,    0,    0,   77,   77,
   68,    0,    0,    0,    0,    0,    0,    0,   77,   77,
   77,   77,   77,   77,   77,   77,   77,   77,   77,   77,
   77,    0,    0,   77,   77,   77,    0,    0,   72,   72,
   72,    0,    0,   72,   72,    0,   42,   43,   44,    0,
    0,    0,    0,   72,   72,   72,   72,   72,   72,   72,
   72,   72,   72,   72,   72,   72,    0,    0,   72,   72,
   72,    0,    0,   73,   73,   73,    0,    0,   73,   73,
    0,    0,    0,    0,    0,    0,    0,    0,   73,   73,
   73,   73,   73,   73,   73,   73,   73,   73,   73,   73,
   73,    0,    0,   73,   73,   73,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   69,    0,    0,    0,   69,    0,    0,   69,
   69,   69,   69,   69,   69,    0,   69,    0,   81,   82,
   83,   68,   68,   68,    0,    0,   68,   68,   69,   69,
    0,   69,    0,    0,    0,    0,   68,   68,   68,   68,
   68,   68,   68,   68,   68,   68,   68,   68,   68,   71,
    0,   68,   68,   71,    0,    0,   71,   71,   71,   71,
   71,   71,   69,   71,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   71,   71,    0,   71,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   70,
    0,    0,    0,   70,    0,   69,   70,   70,   70,   70,
   70,   70,    0,   70,    0,    0,    0,    0,    0,   71,
    0,    0,    0,    0,    0,   70,   70,    0,   70,    0,
   76,   85,    0,   73,    0,   74,   77,    0,   78,    0,
   75,   76,   85,    0,   73,    0,   74,   77,    0,   78,
    0,   75,   71,   79,   84,   80,    0,    0,    0,   70,
    0,    0,    0,    0,   79,   84,   80,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   76,   85,    0,
   73,   98,   74,   77,    0,   78,    0,   75,   76,   85,
    0,   73,   70,   74,   77,    0,   78,    0,   75,    0,
   79,   84,   80,    0,    0,    0,    0,    0,    0,    0,
    0,   79,   84,   80,    0,    0,    0,   86,    0,    0,
    0,    0,    0,    0,   76,   85,    0,   73,   86,   74,
   77,    0,   78,    0,   75,    0,   69,   69,   69,    0,
    0,   69,   69,    0,  123,    0,    0,   79,   84,   80,
    0,   69,   69,   69,   69,   69,   69,   69,   69,   69,
   69,   69,   69,   69,   86,    0,   69,   69,   76,   85,
    0,   73,    0,   74,   77,   86,   78,    0,   75,    0,
    0,    0,    0,   71,   71,   71,    0,    0,   71,   71,
    0,   79,   84,   80,    0,    0,    0,    0,   71,   71,
   71,   71,   71,   71,   71,   71,   71,   71,   71,   71,
   71,   86,   85,   71,   71,    0,    0,   77,    0,   78,
    0,    0,    0,   70,   70,   70,    0,    0,   70,   70,
    0,    0,    0,    0,   79,   84,   80,    0,   70,   70,
   70,   70,   70,   70,   70,   70,   70,   70,   70,   70,
   70,    0,    0,   70,   70,   86,    0,    0,    0,    0,
    0,    0,    0,    0,   76,   85,    0,   73,   96,   74,
   77,    0,   78,    0,   75,    0,    0,    0,    0,    0,
   81,   82,   83,    0,   97,    0,    0,   79,   84,   80,
    0,   81,   82,   83,   76,   85,    0,   73,   86,   74,
   77,    0,   78,    0,   75,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   79,   84,   80,
    0,   85,    0,    0,    0,   76,   85,   81,   82,   83,
   74,   77,    0,   78,    0,   75,    0,    0,   81,   82,
   83,    0,    0,   79,   84,   80,    0,    0,   79,   84,
   80,   86,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  130,    0,
    0,    0,    0,    0,   81,   82,   83,    0,   63,    0,
    0,   86,   63,    0,    0,   63,   63,   63,   63,   63,
   63,    0,   63,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   63,    0,  139,   86,    0,    0,
    0,    0,   86,    0,    0,    0,    0,   64,   81,   82,
   83,   64,    0,    0,   64,   64,   64,   64,   64,   64,
    0,   64,    0,   54,    0,   50,    0,   51,   63,    0,
   52,    0,    0,   64,    0,    0,   65,    0,    0,    0,
   65,    0,    0,   65,   65,   65,    0,   65,    0,    0,
   65,   81,   82,   83,    0,    0,    0,    0,    0,    0,
    0,   63,   65,    0,    0,   66,    0,   64,    0,   66,
    0,    0,   66,   66,   66,    0,   66,    0,    0,   66,
    0,   54,    0,   50,    0,   51,    0,    0,   52,    0,
  141,   66,    0,    0,    0,    0,   65,    0,    0,    0,
   64,    0,    0,    0,   81,   82,   83,    0,    0,    0,
    0,   53,   67,    0,    0,    0,   67,    0,    0,   67,
   67,   67,    0,   67,    0,   66,   67,    0,    0,   65,
    0,    0,    0,    0,   81,   82,   83,    0,   67,    0,
    0,    0,   61,    0,    0,    0,    0,    0,    0,   61,
   61,    0,    0,   61,    0,    0,    0,    0,   66,    0,
   81,   82,   83,    0,    0,   81,   82,   83,   61,   53,
   62,    0,   67,    0,    0,    0,    0,   62,   62,    0,
    0,   62,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   63,   63,   63,    0,   62,   63,   63,    0,
    0,    0,   61,    0,    0,   67,    0,   63,   63,   63,
   63,   63,   63,   63,   63,   63,   63,   63,   63,   63,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   62,   64,   64,   64,    0,   61,   64,   64,    0,    0,
    0,    0,   42,   43,   44,    0,   64,   64,   64,   64,
   64,   64,   64,   64,   64,   64,   64,   64,   64,   45,
   65,   65,   65,   62,   46,   65,   65,   47,   48,   49,
    0,    0,    0,    0,    0,   65,   65,   65,   65,   65,
   65,   65,   65,   65,   65,   65,   65,   65,   47,   66,
   66,   66,    0,    0,   66,   66,    0,    0,    0,    0,
   42,   43,   44,    0,   66,   66,   66,   66,   66,   66,
   66,   66,   66,   66,   66,   66,   66,   45,    0,  124,
  125,  126,   46,    0,    0,   47,   48,   49,    0,    0,
    0,    0,    0,    0,    0,   46,   67,   67,   67,    0,
    0,   67,   67,   51,    0,   51,    0,   51,    0,    0,
   51,   67,   67,   67,   67,   67,   67,   67,   67,   67,
   67,   67,   67,   67,   33,    0,   61,   61,   61,    0,
    0,   61,   61,   54,    0,   50,    0,   51,    0,    0,
   52,   61,   61,   61,   61,   61,   61,   61,   61,   61,
   61,   61,   61,   61,   62,   62,   62,    0,    0,   62,
   62,   52,   46,   52,    0,   52,    0,    0,   52,   62,
   62,   62,   62,   62,   62,   62,   62,   62,   62,   62,
   62,   62,   34,    0,    0,    0,    0,    0,    0,    0,
   51,   51,   51,    0,   51,    0,    0,   51,    0,    0,
    0,   54,    0,   50,    0,   51,    0,    0,   52,    0,
    0,   30,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   53,    0,    0,    0,    0,    0,    0,    0,   54,
    0,   50,    0,   51,    0,    0,   52,    0,    0,    0,
    0,   51,    0,   51,    0,   51,    0,    0,   51,   52,
    0,   47,   47,    0,    0,    0,    0,    0,    0,    0,
    0,   47,    0,   47,    0,   47,   47,   47,   47,    0,
    0,   47,   47,   47,    0,    0,    0,    0,   51,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   53,
    0,    0,    0,   46,   46,   46,    0,    0,   46,   46,
    0,    0,    0,    0,    0,    0,    0,    0,   46,    0,
   46,    0,   46,   46,   46,   46,    0,   53,   46,   46,
   46,    0,   51,   51,   51,    0,    0,   33,   33,   51,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   51,
    0,    0,    0,    0,   51,    0,    0,   51,   51,   51,
    0,    0,   42,   43,   44,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   45,
    0,    0,    0,  138,   46,    0,    0,   47,   48,   49,
   52,   52,   52,    0,    0,   34,   34,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   52,    0,    0,
    0,    0,   52,    0,    0,   52,   52,   52,    0,   51,
   51,   51,    0,    0,   30,   30,    0,    0,    0,    0,
   42,   43,   44,    0,    0,    0,   51,    0,    0,    0,
    0,   51,    0,    0,   51,   51,   51,   45,    0,    0,
    0,  143,   46,    0,    0,   47,   48,   49,   42,   43,
   44,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   51,   51,   51,  145,    0,   45,   30,    0,    0,    0,
   46,    0,    0,   47,   48,   49,    0,   51,    0,    0,
    0,    0,   51,    0,    0,   51,   51,   51,   65,   66,
    0,    0,   67,   68,    0,   70,   71,   72,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  100,  102,  103,  104,
  105,  106,  107,  108,  109,  110,  111,  112,  113,  114,
    0,    0,  115,  116,    0,    0,    0,    0,    0,    0,
  120,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  131,    0,    0,  133,    0,
    0,    0,    0,  137,
};
static const YYINT yycheck[] = {                         33,
   38,   38,  262,   37,   38,   59,   40,   41,   42,   43,
   44,   45,   96,   47,   42,   38,  257,   40,  259,   42,
   59,   91,   45,   61,  263,   59,   60,   61,   62,  290,
   35,  258,  267,  268,   33,  270,  271,  258,   37,   38,
  124,   40,   41,   42,   43,   44,   45,  263,   47,   38,
  134,   40,   41,   42,   59,  139,   45,  141,   13,   93,
   59,   60,   61,   62,  267,  268,   21,  270,   59,   33,
  290,   41,   59,   37,   44,   30,   40,   41,   42,   43,
   44,   45,   37,   47,   59,   41,  124,  124,   44,  124,
  124,   59,  126,    2,   93,   59,   60,   61,   62,   41,
   93,  262,   44,  126,   33,   17,  267,  268,   37,  270,
  271,   40,   41,   42,   43,   44,   45,   38,   47,   40,
    6,   42,  267,  268,   45,  270,  271,  126,   15,   93,
   59,   60,   61,   62,  264,  265,  266,  126,   30,   33,
   95,  260,  261,   37,  265,  266,   40,   41,   42,   43,
   44,   45,  263,   47,  272,  273,  267,  268,   32,  270,
  271,  128,  126,   51,   93,   59,   60,   61,   62,  267,
  268,  269,  270,   -1,   33,  276,  277,  278,   37,   38,
   -1,   40,   -1,   42,   43,   -1,   45,   -1,   47,  267,
  268,  269,  270,  276,  277,  278,   -1,  126,   -1,   93,
   59,   60,   61,   62,   -1,  126,   -1,   33,  262,  263,
   -1,   37,  262,  263,   40,   41,   42,   43,   44,   45,
  290,   47,   -1,  257,  258,  259,  272,  273,  262,  263,
  258,   -1,  126,   59,   60,   -1,   62,   -1,  272,  273,
  274,  275,  276,  277,  278,  279,  280,  281,  282,  283,
  284,  289,   -1,  287,  288,  289,  272,  273,  257,  258,
  259,   -1,   -1,  262,  263,  124,   -1,   93,  257,  258,
  259,  262,  263,  272,  273,  274,  275,  276,  277,  278,
  279,  280,  281,  282,  283,  284,   -1,   -1,  287,  288,
  289,   -1,   -1,  257,  258,  259,   -1,   -1,  262,  263,
  126,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  272,  273,
  274,  275,  276,  277,  278,  279,  280,  281,  282,  283,
  284,   -1,   -1,  287,  288,  289,   -1,   -1,  257,  258,
  259,   -1,   -1,  262,  263,   -1,  257,  258,  259,   -1,
   -1,   -1,   -1,  272,  273,  274,  275,  276,  277,  278,
  279,  280,  281,  282,  283,  284,   -1,   -1,  287,  288,
  289,   -1,   -1,  257,  258,  259,   -1,   -1,  262,  263,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  272,  273,
  274,  275,  276,  277,  278,  279,  280,  281,  282,  283,
  284,   -1,   -1,  287,  288,  289,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   33,   -1,   -1,   -1,   37,   -1,   -1,   40,
   41,   42,   43,   44,   45,   -1,   47,   -1,  287,  288,
  289,  257,  258,  259,   -1,   -1,  262,  263,   59,   60,
   -1,   62,   -1,   -1,   -1,   -1,  272,  273,  274,  275,
  276,  277,  278,  279,  280,  281,  282,  283,  284,   33,
   -1,  287,  288,   37,   -1,   -1,   40,   41,   42,   43,
   44,   45,   93,   47,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   59,   60,   -1,   62,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   33,
   -1,   -1,   -1,   37,   -1,  126,   40,   41,   42,   43,
   44,   45,   -1,   47,   -1,   -1,   -1,   -1,   -1,   93,
   -1,   -1,   -1,   -1,   -1,   59,   60,   -1,   62,   -1,
   37,   38,   -1,   40,   -1,   42,   43,   -1,   45,   -1,
   47,   37,   38,   -1,   40,   -1,   42,   43,   -1,   45,
   -1,   47,  126,   60,   61,   62,   -1,   -1,   -1,   93,
   -1,   -1,   -1,   -1,   60,   61,   62,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   37,   38,   -1,
   40,   41,   42,   43,   -1,   45,   -1,   47,   37,   38,
   -1,   40,  126,   42,   43,   -1,   45,   -1,   47,   -1,
   60,   61,   62,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   60,   61,   62,   -1,   -1,   -1,  124,   -1,   -1,
   -1,   -1,   -1,   -1,   37,   38,   -1,   40,  124,   42,
   43,   -1,   45,   -1,   47,   -1,  257,  258,  259,   -1,
   -1,  262,  263,   -1,   93,   -1,   -1,   60,   61,   62,
   -1,  272,  273,  274,  275,  276,  277,  278,  279,  280,
  281,  282,  283,  284,  124,   -1,  287,  288,   37,   38,
   -1,   40,   -1,   42,   43,  124,   45,   -1,   47,   -1,
   -1,   -1,   -1,  257,  258,  259,   -1,   -1,  262,  263,
   -1,   60,   61,   62,   -1,   -1,   -1,   -1,  272,  273,
  274,  275,  276,  277,  278,  279,  280,  281,  282,  283,
  284,  124,   38,  287,  288,   -1,   -1,   43,   -1,   45,
   -1,   -1,   -1,  257,  258,  259,   -1,   -1,  262,  263,
   -1,   -1,   -1,   -1,   60,   61,   62,   -1,  272,  273,
  274,  275,  276,  277,  278,  279,  280,  281,  282,  283,
  284,   -1,   -1,  287,  288,  124,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   37,   38,   -1,   40,  275,   42,
   43,   -1,   45,   -1,   47,   -1,   -1,   -1,   -1,   -1,
  287,  288,  289,   -1,  280,   -1,   -1,   60,   61,   62,
   -1,  287,  288,  289,   37,   38,   -1,   40,  124,   42,
   43,   -1,   45,   -1,   47,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   60,   61,   62,
   -1,   38,   -1,   -1,   -1,   37,   38,  287,  288,  289,
   42,   43,   -1,   45,   -1,   47,   -1,   -1,  287,  288,
  289,   -1,   -1,   60,   61,   62,   -1,   -1,   60,   61,
   62,  124,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  281,   -1,
   -1,   -1,   -1,   -1,  287,  288,  289,   -1,   33,   -1,
   -1,  124,   37,   -1,   -1,   40,   41,   42,   43,   44,
   45,   -1,   47,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   59,   -1,  275,  124,   -1,   -1,
   -1,   -1,  124,   -1,   -1,   -1,   -1,   33,  287,  288,
  289,   37,   -1,   -1,   40,   41,   42,   43,   44,   45,
   -1,   47,   -1,   38,   -1,   40,   -1,   42,   93,   -1,
   45,   -1,   -1,   59,   -1,   -1,   33,   -1,   -1,   -1,
   37,   -1,   -1,   40,   41,   42,   -1,   44,   -1,   -1,
   47,  287,  288,  289,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  126,   59,   -1,   -1,   33,   -1,   93,   -1,   37,
   -1,   -1,   40,   41,   42,   -1,   44,   -1,   -1,   47,
   -1,   38,   -1,   40,   -1,   42,   -1,   -1,   45,   -1,
  273,   59,   -1,   -1,   -1,   -1,   93,   -1,   -1,   -1,
  126,   -1,   -1,   -1,  287,  288,  289,   -1,   -1,   -1,
   -1,  126,   33,   -1,   -1,   -1,   37,   -1,   -1,   40,
   41,   42,   -1,   44,   -1,   93,   47,   -1,   -1,  126,
   -1,   -1,   -1,   -1,  287,  288,  289,   -1,   59,   -1,
   -1,   -1,   33,   -1,   -1,   -1,   -1,   -1,   -1,   40,
   41,   -1,   -1,   44,   -1,   -1,   -1,   -1,  126,   -1,
  287,  288,  289,   -1,   -1,  287,  288,  289,   59,  126,
   33,   -1,   93,   -1,   -1,   -1,   -1,   40,   41,   -1,
   -1,   44,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  257,  258,  259,   -1,   59,  262,  263,   -1,
   -1,   -1,   93,   -1,   -1,  126,   -1,  272,  273,  274,
  275,  276,  277,  278,  279,  280,  281,  282,  283,  284,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   93,  257,  258,  259,   -1,  126,  262,  263,   -1,   -1,
   -1,   -1,  257,  258,  259,   -1,  272,  273,  274,  275,
  276,  277,  278,  279,  280,  281,  282,  283,  284,  274,
  257,  258,  259,  126,  279,  262,  263,  282,  283,  284,
   -1,   -1,   -1,   -1,   -1,  272,  273,  274,  275,  276,
  277,  278,  279,  280,  281,  282,  283,  284,   59,  257,
  258,  259,   -1,   -1,  262,  263,   -1,   -1,   -1,   -1,
  257,  258,  259,   -1,  272,  273,  274,  275,  276,  277,
  278,  279,  280,  281,  282,  283,  284,  274,   -1,  276,
  277,  278,  279,   -1,   -1,  282,  283,  284,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   59,  257,  258,  259,   -1,
   -1,  262,  263,   38,   -1,   40,   -1,   42,   -1,   -1,
   45,  272,  273,  274,  275,  276,  277,  278,  279,  280,
  281,  282,  283,  284,   59,   -1,  257,  258,  259,   -1,
   -1,  262,  263,   38,   -1,   40,   -1,   42,   -1,   -1,
   45,  272,  273,  274,  275,  276,  277,  278,  279,  280,
  281,  282,  283,  284,  257,  258,  259,   -1,   -1,  262,
  263,   38,  126,   40,   -1,   42,   -1,   -1,   45,  272,
  273,  274,  275,  276,  277,  278,  279,  280,  281,  282,
  283,  284,   59,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   38,  126,   40,   -1,   42,   -1,   -1,   45,   -1,   -1,
   -1,   38,   -1,   40,   -1,   42,   -1,   -1,   45,   -1,
   -1,   59,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  126,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   38,
   -1,   40,   -1,   42,   -1,   -1,   45,   -1,   -1,   -1,
   -1,   38,   -1,   40,   -1,   42,   -1,   -1,   45,  126,
   -1,  262,  263,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  272,   -1,  274,   -1,  276,  277,  278,  279,   -1,
   -1,  282,  283,  284,   -1,   -1,   -1,   -1,  126,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  126,
   -1,   -1,   -1,  257,  258,  259,   -1,   -1,  262,  263,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  272,   -1,
  274,   -1,  276,  277,  278,  279,   -1,  126,  282,  283,
  284,   -1,  257,  258,  259,   -1,   -1,  262,  263,  126,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  274,
   -1,   -1,   -1,   -1,  279,   -1,   -1,  282,  283,  284,
   -1,   -1,  257,  258,  259,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  274,
   -1,   -1,   -1,  278,  279,   -1,   -1,  282,  283,  284,
  257,  258,  259,   -1,   -1,  262,  263,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  274,   -1,   -1,
   -1,   -1,  279,   -1,   -1,  282,  283,  284,   -1,  257,
  258,  259,   -1,   -1,  262,  263,   -1,   -1,   -1,   -1,
  257,  258,  259,   -1,   -1,   -1,  274,   -1,   -1,   -1,
   -1,  279,   -1,   -1,  282,  283,  284,  274,   -1,   -1,
   -1,  278,  279,   -1,   -1,  282,  283,  284,  257,  258,
  259,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  257,  258,  259,  272,   -1,  274,  263,   -1,   -1,   -1,
  279,   -1,   -1,  282,  283,  284,   -1,  274,   -1,   -1,
   -1,   -1,  279,   -1,   -1,  282,  283,  284,   45,   46,
   -1,   -1,   49,   50,   -1,   52,   53,   54,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   73,   74,   75,   76,
   77,   78,   79,   80,   81,   82,   83,   84,   85,   86,
   -1,   -1,   89,   90,   -1,   -1,   -1,   -1,   -1,   -1,
   97,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  122,   -1,   -1,  125,   -1,
   -1,   -1,   -1,  130,
};
#define YYFINAL 3
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 290
#define YYUNDFTOKEN 317
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"'!'",0,0,0,"'%'","'&'",0,"'('","')'","'*'","'+'","','","'-'",0,"'/'",0,0,0,0,0,
0,0,0,0,0,0,"';'","'<'","'='","'>'","'?'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,"'['",0,"']'","'^'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,"'|'",0,"'~'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"INTEGER","ID","STR","PROGRAM",
"MODULE","START","END","FUNCTION","PUBLIC","FORWARD","NUMBER","ARRAY","VOID",
"STRING","CONST","DONE","DO","IF","THEN","ELSE","ELIF","FI","FOR","UNTIL",
"STEP","REPEAT","STOP","RETURN","ADDR","UMINUS","LE","GE","NE","ATTR",0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"illegal-symbol",
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
"decl : qualifier CONST var ATTR literal",
"decl : qualifier CONST var",
"decl : qualifier var ATTR literal",
"decl : qualifier var",
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
"body :",
"body : bodyvars bodyinstrs",
"body : bodyinstrs",
"body : bodyvars",
"bodyinstrs : instrs instr",
"bodyvars : var ';'",
"bodyvars : bodyvars var ';'",
"instr : IF rvalue THEN instrs FI",
"instr : IF rvalue THEN instrs elifs ELSE instrs FI",
"instr : IF rvalue THEN instrs elifs FI",
"instr : IF rvalue THEN instrs ELSE instrs FI",
"instr : FOR rvalue UNTIL rvalue STEP rvalue DO instrs DONE",
"instr : rvalue ';'",
"instr : rvalue '!'",
"instr : REPEAT",
"instr : STOP",
"instr : RETURN rvalue",
"instr : RETURN",
"elif : ELIF rvalue THEN instrs",
"elifs : elif",
"elifs : elifs elif",
"instrs :",
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
"literal : INTEGER",
"literal : STR",
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
#line 170 "gram.y"

char **yynames =
#if YYDEBUG > 0
		 (char**)yyname;
#else
		 0;
#endif
#line 700 "y.tab.c"

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
