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
extern YYSTYPE yylval;
