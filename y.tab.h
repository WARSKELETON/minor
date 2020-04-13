#define INTEGER 257
#define CHAR 258
#define ID 259
#define STR 260
#define PROGRAM 261
#define MODULE 262
#define START 263
#define END 264
#define FUNCTION 265
#define PUBLIC 266
#define FORWARD 267
#define NUMBER 268
#define ARRAY 269
#define VOID 270
#define STRING 271
#define CONST 272
#define DONE 273
#define DO 274
#define IF 275
#define THEN 276
#define ELSE 277
#define ELIF 278
#define FI 279
#define FOR 280
#define UNTIL 281
#define STEP 282
#define REPEAT 283
#define STOP 284
#define RETURN 285
#define ATTR 286
#define NE 287
#define LE 288
#define GE 289
#define ADDR 290
#define UMINUS 291
#define NIL 292
#define DECLS 293
#define DECL 294
#define FUNCTYPE 295
#define QUALIFIER 296
#define VARS 297
#define VAR 298
#define SIZE 299
#define BODY 300
#define RETURN_EXPR 301
#define BLOCK 302
#define INSTRS 303
#define ARGS 304
#define LOCAL 305
#define CALL 306
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
