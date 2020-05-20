/*
generated at Wed May 20 15:35:57 2020
by $Id: pburg.c,v 2.5 2017/11/16 09:41:42 prs Exp $
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define PBURG_PREFIX "yy"
#define PBURG_VERSION "2.5"
#define MAX_COST 0x7fff
#if defined(__STDC__) || defined(__cplusplus)
#define YYCONST const
#else
#define YYCONST
#endif

#line 1 "minor.brg"

/*
 * selecção de instruções com postfix
 */
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"
#include "postfix.h"
#include "y.tab.h"
#include "minor.h"
#include "tabid.h"

#ifndef U_
#define U_ "_"
#endif

#define TRACE
static void yytrace(NODEPTR_TYPE p, int eruleno, int cost, int bestcost);

extern FILE *yyout;
static int forlbl[20], repeatlbl[20], stoplbl[20], forcnt; /* for labels */
int lbl;
int eliflbl;
static int pos;
static char* currentfunc;
static char *mklbl(int n) {
	static char buf[20];
	sprintf(buf, "%cL%d", n < 0 ? '.' : '_', n);
	return strcpy(malloc(strlen(buf)+1),buf);
}
static char *mkfunc(char *s) {
	static char buf[80];
	strcpy(buf, "_");
	strcat(buf, s);
	return buf;
}
static void outchars(Node *chars) {
	int first = 1;

	while (LEFT_CHILD(chars) || first) {
		first = 0;
		
		if (RIGHT_CHILD(chars)->info == tSTR) {
			char* s = RIGHT_CHILD(chars)->value.s;
			while (*s) fprintf(yyout, pfCHAR, (unsigned char)*s++);
		}
		if (RIGHT_CHILD(chars)->info == tINT) {
			fprintf(yyout, pfCHAR, RIGHT_CHILD(chars)->value.i);
		}
		
		chars = LEFT_CHILD(chars);
	}
	fprintf(yyout, pfCHAR, 0);
}
static void outstr(char *s) {
  while (*s) fprintf(yyout, pfCHAR, (unsigned char)*s++);
  fprintf(yyout, pfCHAR, 0);
}
static void pfPrint(int info) {
	if (tTYPE(info) == tINT) {
  		fprintf(yyout, pfCALL pfCALL pfTRASH, "_printi", "_println", 4);
	}
	if (tTYPE(info) == tSTR) {
  		fprintf(yyout, pfCALL pfCALL pfTRASH, "_prints", "_println", 4);
	}
}
static void getId(Node* nm) {
	int typ = 2, nmpos = 0;
	if (IDfind(nm->value.s, (void**)IDtest) >= 0) {
		if (nm->info >= tFUNC) {
			fprintf(yyout, pfCALL pfPUSH, mkfunc(nm->value.s));
		}
		else {
			fprintf(yyout, pfADDRV, nm->value.s);
		}
	}
	else {
		typ = IDfind(nm->value.s, (long*)&nmpos);
		fprintf(yyout, pfLOCV, nmpos);
	}
}
static void assignment(Node* nm) {
	int typ = 2, nmpos = 0;
	if (IDfind(nm->value.s, (void**)IDtest) >= 0) {
		fprintf(yyout, pfDUP pfADDRA, nm->value.s);
	}
	else {
		typ = IDfind(nm->value.s, (long*)&nmpos);
		fprintf(yyout, pfDUP pfLOCA, nmpos * (pfWORD/4));
	}
}
static void variable(Node *var) {
	Node* p = var->SUB(0);
	if (RIGHT_CHILD(p) == NIL) {
		fprintf(yyout, pfGLOBL pfBSS pfALIGN pfLABEL, LEFT_CHILD(p)->value.s, pfOBJ, LEFT_CHILD(p)->value.s);
	}
	else {
		if (var->info & tCNST) {
			fprintf(yyout, pfGLOBL pfRODATA pfALIGN pfLABEL, LEFT_CHILD(p)->value.s, pfOBJ, LEFT_CHILD(p)->value.s);
		}
		else {
			fprintf(yyout, pfGLOBL pfDATA pfALIGN pfLABEL, LEFT_CHILD(p)->value.s, pfOBJ, LEFT_CHILD(p)->value.s);
		}
		if (p->info == tINT)
			fprintf(yyout, pfINTEGER, RIGHT_CHILD(p)->value.i);
		if (p->info == tSTR) {
			char *l = mklbl(++lbl);
			fprintf(yyout, pfRODATA pfALIGN pfLABEL, l);
			outchars(RIGHT_CHILD(p));
			fprintf(yyout, pfDATA pfID, l);
		}
	}
}
static void function(char *name, int enter) {
  fprintf(yyout, pfTEXT pfALIGN pfGLOBL pfLABEL pfENTER, mkfunc(name), pfFUNC, mkfunc(name), enter * (pfWORD/4));
}
static void final() {
    fprintf(yyout, pfIMM pfPOP pfLEAVE pfRET pfLEAVE pfRET, 0);
    fprintf(yyout, pfEXTRN pfEXTRN pfEXTRN pfEXTRN, "_prints", "_printi", "_println", "_readi");
}
/* falta const type ftype */
/* expr: expr */
/* println ? 255 truncar */
#ifndef PANIC
#define PANIC yypanic
static void yypanic(YYCONST char *rot, YYCONST char *msg, int val) {
	fprintf(stderr, "Internal Error in %s: %s %d\nexiting...\n",
		rot, msg, val);
	exit(2);
}
#endif
static void yykids(NODEPTR_TYPE, int, NODEPTR_TYPE[]);
#define yyprogram_NT 1
#define yydecls_NT 2
#define yyfuncmain_NT 3
#define yymain_NT 4
#define yygdecls_NT 5
#define yydecl_NT 6
#define yyvardecl_NT 7
#define yyfuncname_NT 8
#define yyfargs_NT 9
#define yyeqbody_NT 10
#define yyfarg_NT 11
#define yyvdim_NT 12
#define yyfvar_NT 13
#define yyfvars_NT 14
#define yyeqint_NT 15
#define yyeqstr_NT 16
#define yyeqvec_NT 17
#define yyeqchars_NT 18
#define yyeqchar_NT 19
#define yychars_NT 20
#define yychar_NT 21
#define yyints_NT 22
#define yybody_NT 23
#define yymainfvars_NT 24
#define yyinstrs_NT 25
#define yybodyfvars_NT 26
#define yyret_NT 27
#define yyexpr_NT 28
#define yyloop_NT 29
#define yyblock_NT 30
#define yyforblock_NT 31
#define yyinstr_NT 32
#define yyif_NT 33
#define yyelifs_NT 34
#define yyelse_NT 35
#define yyinit_NT 36
#define yyforcond_NT 37
#define yypostexpr_NT 38
#define yyalloc_NT 39
#define yylval_NT 40
#define yycond_NT 41
#define yyifelse_NT 42
#define yytest_NT 43
#define yyassign_NT 44
#define yyand_NT 45
#define yyor_NT 46
#define yyexprs_NT 47

static YYCONST char *yyntname[] = {
	0,
	"program",
	"decls",
	"funcmain",
	"main",
	"gdecls",
	"decl",
	"vardecl",
	"funcname",
	"fargs",
	"eqbody",
	"farg",
	"vdim",
	"fvar",
	"fvars",
	"eqint",
	"eqstr",
	"eqvec",
	"eqchars",
	"eqchar",
	"chars",
	"char",
	"ints",
	"body",
	"mainfvars",
	"instrs",
	"bodyfvars",
	"ret",
	"expr",
	"loop",
	"block",
	"forblock",
	"instr",
	"if",
	"elifs",
	"else",
	"init",
	"forcond",
	"postexpr",
	"alloc",
	"lval",
	"cond",
	"ifelse",
	"test",
	"assign",
	"and",
	"or",
	"exprs",
	0
};

static YYCONST char *yytermname[] = {
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "", "", "", "", "",
	/* 34 */ "PRINT",
 "",
	/* 36 */ "ALLOC",
 "",
	/* 38 */ "MOD",
	/* 39 */ "AND",
 "",
	/* 41 */ "IDARGS",
 "",
	/* 43 */ "MUL",
	/* 44 */ "ADD",
	/* 45 */ "COMMA",
	/* 46 */ "SUB",
 "",
	/* 48 */ "DIV",
 "", "", "", "", "", "", "", "", "", "", "",
	/* 60 */ "STMT",
	/* 61 */ "LT",
	/* 62 */ "EQU",
	/* 63 */ "GT",
	/* 64 */ "READ",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "",
	/* 92 */ "INDEX",
 "", "",
	/* 95 */ "POW",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "",
	/* 125 */ "OR",
 "",
	/* 127 */ "NOT",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "", "", "", "", "", "",
	/* 258 */ "INT",
	/* 259 */ "CHAR",
	/* 260 */ "ID",
	/* 261 */ "STR",
	/* 262 */ "PROGRAM",
	/* 263 */ "MODULE",
	/* 264 */ "END",
	/* 265 */ "PUBLIC",
	/* 266 */ "FORWARD",
	/* 267 */ "STRING",
	/* 268 */ "NUMBER",
	/* 269 */ "ARRAY",
	/* 270 */ "FUNCTION",
	/* 271 */ "VOID",
	/* 272 */ "CONST",
	/* 273 */ "IF",
	/* 274 */ "THEN",
	/* 275 */ "FI",
	/* 276 */ "ELIF",
	/* 277 */ "ELSE",
	/* 278 */ "RETURN",
	/* 279 */ "START",
	/* 280 */ "FOR",
	/* 281 */ "UNTIL",
	/* 282 */ "STEP",
	/* 283 */ "DO",
	/* 284 */ "DONE",
	/* 285 */ "REPEAT",
	/* 286 */ "STOP",
	/* 287 */ "FARGS",
	/* 288 */ "CHARS",
	/* 289 */ "INTS",
	/* 290 */ "ADDR",
	/* 291 */ "VAR",
	/* 292 */ "ARGS",
	/* 293 */ "DECL",
	/* 294 */ "NIL",
	/* 295 */ "EQ",
	/* 296 */ "NE",
	/* 297 */ "GE",
	/* 298 */ "LE",
	/* 299 */ "UMINUS",
	""
};

struct yystate {
	short cost[48];
	struct {
		unsigned int yyprogram:2;
		unsigned int yydecls:2;
		unsigned int yyfuncmain:1;
		unsigned int yymain:1;
		unsigned int yygdecls:2;
		unsigned int yydecl:2;
		unsigned int yyvardecl:2;
		unsigned int yyfuncname:1;
		unsigned int yyfargs:2;
		unsigned int yyeqbody:2;
		unsigned int yyfarg:2;
		unsigned int yyvdim:2;
		unsigned int yyfvar:2;
		unsigned int yyfvars:2;
		unsigned int yyeqint:2;
		unsigned int yyeqstr:2;
		unsigned int yyeqvec:2;
		unsigned int yyeqchars:2;
		unsigned int yyeqchar:2;
		unsigned int yychars:2;
		unsigned int yychar:2;
		unsigned int yyints:2;
		unsigned int yybody:1;
		unsigned int yymainfvars:2;
		unsigned int yyinstrs:2;
		unsigned int yybodyfvars:2;
		unsigned int yyret:2;
		unsigned int yyexpr:5;
		unsigned int yyloop:2;
		unsigned int yyblock:1;
		unsigned int yyforblock:1;
		unsigned int yyinstr:3;
		unsigned int yyif:1;
		unsigned int yyelifs:2;
		unsigned int yyelse:2;
		unsigned int yyinit:1;
		unsigned int yyforcond:1;
		unsigned int yypostexpr:1;
		unsigned int yyalloc:1;
		unsigned int yylval:2;
		unsigned int yycond:1;
		unsigned int yyifelse:1;
		unsigned int yytest:1;
		unsigned int yyassign:2;
		unsigned int yyand:1;
		unsigned int yyor:1;
		unsigned int yyexprs:2;
	} rule;
};

static short yynts_0[] = { yydecls_NT, yyfuncmain_NT, yymain_NT, 0 };
static short yynts_1[] = { yydecls_NT, 0 };
static short yynts_2[] = { 0 };
static short yynts_3[] = { yygdecls_NT, 0 };
static short yynts_4[] = { yygdecls_NT, yydecl_NT, 0 };
static short yynts_5[] = { yydecl_NT, 0 };
static short yynts_6[] = { yyvardecl_NT, 0 };
static short yynts_7[] = { yyfuncname_NT, yyfargs_NT, yyeqbody_NT, 0 };
static short yynts_8[] = { yyvdim_NT, 0 };
static short yynts_9[] = { yyfarg_NT, 0 };
static short yynts_10[] = { yyfargs_NT, yyfarg_NT, 0 };
static short yynts_11[] = { yyfvar_NT, 0 };
static short yynts_12[] = { yyfvars_NT, yyfvar_NT, 0 };
static short yynts_13[] = { yyeqint_NT, 0 };
static short yynts_14[] = { yyeqstr_NT, 0 };
static short yynts_15[] = { yyvdim_NT, yyeqvec_NT, 0 };
static short yynts_16[] = { yyeqchars_NT, 0 };
static short yynts_17[] = { yyeqchar_NT, 0 };
static short yynts_18[] = { yyeqchars_NT, yyeqchar_NT, 0 };
static short yynts_19[] = { yychar_NT, 0 };
static short yynts_20[] = { yychars_NT, yychar_NT, 0 };
static short yynts_21[] = { yyints_NT, 0 };
static short yynts_22[] = { yybody_NT, 0 };
static short yynts_23[] = { yymainfvars_NT, yyinstrs_NT, 0 };
static short yynts_24[] = { yyfvars_NT, 0 };
static short yynts_25[] = { yybodyfvars_NT, yyinstrs_NT, yyret_NT, 0 };
static short yynts_26[] = { yyexpr_NT, 0 };
static short yynts_27[] = { yyret_NT, 0 };
static short yynts_28[] = { yyinstrs_NT, yyloop_NT, 0 };
static short yynts_29[] = { yyinstrs_NT, yyinstr_NT, 0 };
static short yynts_30[] = { yyif_NT, yyelifs_NT, yyelse_NT, 0 };
static short yynts_31[] = { yyinit_NT, yyforcond_NT, yyforblock_NT, yypostexpr_NT, 0 };
static short yynts_32[] = { yyalloc_NT, yylval_NT, 0 };
static short yynts_33[] = { yycond_NT, yyblock_NT, 0 };
static short yynts_34[] = { yytest_NT, 0 };
static short yynts_35[] = { yyelifs_NT, yyifelse_NT, 0 };
static short yynts_36[] = { yyblock_NT, 0 };
static short yynts_37[] = { yychars_NT, 0 };
static short yynts_38[] = { yylval_NT, 0 };
static short yynts_39[] = { yyexpr_NT, yyexpr_NT, 0 };
static short yynts_40[] = { yyand_NT, yyexpr_NT, 0 };
static short yynts_41[] = { yyor_NT, yyexpr_NT, 0 };
static short yynts_42[] = { yyexpr_NT, yyassign_NT, 0 };
static short yynts_43[] = { yyexprs_NT, 0 };
static short yynts_44[] = { yyexpr_NT, yyexprs_NT, 0 };

static short *yynts[] = {
	0,	/* 0 */
	yynts_0,	/* 1 */
	yynts_1,	/* 2 */
	yynts_2,	/* 3 */
	yynts_3,	/* 4 */
	yynts_4,	/* 5 */
	yynts_5,	/* 6 */
	yynts_6,	/* 7 */
	yynts_7,	/* 8 */
	yynts_2,	/* 9 */
	yynts_2,	/* 10 */
	yynts_8,	/* 11 */
	yynts_2,	/* 12 */
	yynts_9,	/* 13 */
	yynts_10,	/* 14 */
	yynts_2,	/* 15 */
	yynts_2,	/* 16 */
	yynts_2,	/* 17 */
	yynts_2,	/* 18 */
	yynts_8,	/* 19 */
	yynts_11,	/* 20 */
	yynts_12,	/* 21 */
	yynts_13,	/* 22 */
	yynts_14,	/* 23 */
	yynts_15,	/* 24 */
	yynts_2,	/* 25 */
	yynts_2,	/* 26 */
	yynts_2,	/* 27 */
	yynts_2,	/* 28 */
	yynts_2,	/* 29 */
	yynts_16,	/* 30 */
	yynts_17,	/* 31 */
	yynts_18,	/* 32 */
	yynts_2,	/* 33 */
	yynts_2,	/* 34 */
	yynts_2,	/* 35 */
	yynts_19,	/* 36 */
	yynts_20,	/* 37 */
	yynts_2,	/* 38 */
	yynts_2,	/* 39 */
	yynts_2,	/* 40 */
	yynts_2,	/* 41 */
	yynts_21,	/* 42 */
	yynts_2,	/* 43 */
	yynts_21,	/* 44 */
	yynts_2,	/* 45 */
	yynts_22,	/* 46 */
	yynts_23,	/* 47 */
	yynts_2,	/* 48 */
	yynts_24,	/* 49 */
	yynts_25,	/* 50 */
	yynts_2,	/* 51 */
	yynts_24,	/* 52 */
	yynts_2,	/* 53 */
	yynts_26,	/* 54 */
	yynts_2,	/* 55 */
	yynts_27,	/* 56 */
	yynts_2,	/* 57 */
	yynts_2,	/* 58 */
	yynts_28,	/* 59 */
	yynts_28,	/* 60 */
	yynts_2,	/* 61 */
	yynts_29,	/* 62 */
	yynts_30,	/* 63 */
	yynts_31,	/* 64 */
	yynts_26,	/* 65 */
	yynts_26,	/* 66 */
	yynts_32,	/* 67 */
	yynts_26,	/* 68 */
	yynts_33,	/* 69 */
	yynts_33,	/* 70 */
	yynts_34,	/* 71 */
	yynts_26,	/* 72 */
	yynts_34,	/* 73 */
	yynts_26,	/* 74 */
	yynts_26,	/* 75 */
	yynts_2,	/* 76 */
	yynts_35,	/* 77 */
	yynts_2,	/* 78 */
	yynts_36,	/* 79 */
	yynts_2,	/* 80 */
	yynts_26,	/* 81 */
	yynts_2,	/* 82 */
	yynts_26,	/* 83 */
	yynts_2,	/* 84 */
	yynts_2,	/* 85 */
	yynts_2,	/* 86 */
	yynts_37,	/* 87 */
	yynts_38,	/* 88 */
	yynts_2,	/* 89 */
	yynts_38,	/* 90 */
	yynts_39,	/* 91 */
	yynts_39,	/* 92 */
	yynts_39,	/* 93 */
	yynts_39,	/* 94 */
	yynts_39,	/* 95 */
	yynts_39,	/* 96 */
	yynts_39,	/* 97 */
	yynts_39,	/* 98 */
	yynts_39,	/* 99 */
	yynts_39,	/* 100 */
	yynts_39,	/* 101 */
	yynts_39,	/* 102 */
	yynts_40,	/* 103 */
	yynts_26,	/* 104 */
	yynts_41,	/* 105 */
	yynts_26,	/* 106 */
	yynts_26,	/* 107 */
	yynts_26,	/* 108 */
	yynts_42,	/* 109 */
	yynts_43,	/* 110 */
	yynts_26,	/* 111 */
	yynts_44,	/* 112 */
};


static YYCONST char *yystring[] = {
/* 0 */	0,
/* 1 */	"program: PROGRAM(decls,FUNCTION(funcmain,FARGS(NIL,main)))",
/* 2 */	"program: MODULE(decls)",
/* 3 */	"decls: NIL",
/* 4 */	"decls: gdecls",
/* 5 */	"gdecls: DECL(gdecls,decl)",
/* 6 */	"gdecls: DECL(NIL,decl)",
/* 7 */	"decl: VAR(vardecl)",
/* 8 */	"decl: FUNCTION(funcname,FARGS(fargs,eqbody))",
/* 9 */	"farg: NUMBER(ID,NIL)",
/* 10 */	"farg: STRING(ID,NIL)",
/* 11 */	"farg: ARRAY(ID,INTS(vdim,NIL))",
/* 12 */	"fargs: NIL",
/* 13 */	"fargs: ARGS(NIL,farg)",
/* 14 */	"fargs: ARGS(fargs,farg)",
/* 15 */	"funcname: END(ID,INT)",
/* 16 */	"funcmain: END(ID,INT)",
/* 17 */	"fvar: NUMBER(ID,NIL)",
/* 18 */	"fvar: STRING(ID,NIL)",
/* 19 */	"fvar: ARRAY(ID,INTS(vdim,NIL))",
/* 20 */	"fvars: ARGS(NIL,fvar)",
/* 21 */	"fvars: ARGS(fvars,fvar)",
/* 22 */	"vardecl: NUMBER(ID,eqint)",
/* 23 */	"vardecl: STRING(ID,eqstr)",
/* 24 */	"vardecl: ARRAY(ID,INTS(vdim,eqvec))",
/* 25 */	"vdim: NIL",
/* 26 */	"vdim: INT",
/* 27 */	"eqint: NIL",
/* 28 */	"eqint: INT",
/* 29 */	"eqstr: NIL",
/* 30 */	"eqstr: eqchars",
/* 31 */	"eqchars: CHARS(NIL,eqchar)",
/* 32 */	"eqchars: CHARS(eqchars,eqchar)",
/* 33 */	"eqchar: INT",
/* 34 */	"eqchar: CHAR",
/* 35 */	"eqchar: STR",
/* 36 */	"chars: CHARS(NIL,char)",
/* 37 */	"chars: CHARS(chars,char)",
/* 38 */	"char: INT",
/* 39 */	"char: CHAR",
/* 40 */	"char: STR",
/* 41 */	"eqvec: NIL",
/* 42 */	"eqvec: ints",
/* 43 */	"ints: INT",
/* 44 */	"ints: INTS(ints,INT)",
/* 45 */	"eqbody: NIL",
/* 46 */	"eqbody: body",
/* 47 */	"main: START(mainfvars,instrs)",
/* 48 */	"mainfvars: NIL",
/* 49 */	"mainfvars: fvars",
/* 50 */	"body: START(bodyfvars,STMT(instrs,ret))",
/* 51 */	"bodyfvars: NIL",
/* 52 */	"bodyfvars: fvars",
/* 53 */	"ret: RETURN(NIL)",
/* 54 */	"ret: RETURN(expr)",
/* 55 */	"ret: NIL",
/* 56 */	"loop: ret",
/* 57 */	"loop: REPEAT",
/* 58 */	"loop: STOP",
/* 59 */	"block: STMT(instrs,loop)",
/* 60 */	"forblock: STMT(instrs,loop)",
/* 61 */	"instrs: NIL",
/* 62 */	"instrs: STMT(instrs,instr)",
/* 63 */	"instr: FI(THEN(if,elifs),else)",
/* 64 */	"instr: FOR(UNTIL(init,forcond),STEP(forblock,postexpr))",
/* 65 */	"instr: PRINT(expr)",
/* 66 */	"instr: expr",
/* 67 */	"instr: ALLOC(alloc,lval)",
/* 68 */	"alloc: expr",
/* 69 */	"if: IF(cond,block)",
/* 70 */	"ifelse: IF(cond,block)",
/* 71 */	"init: test",
/* 72 */	"forcond: expr",
/* 73 */	"postexpr: test",
/* 74 */	"cond: expr",
/* 75 */	"test: expr",
/* 76 */	"elifs: NIL",
/* 77 */	"elifs: ELIF(elifs,ifelse)",
/* 78 */	"else: NIL",
/* 79 */	"else: block",
/* 80 */	"lval: ID",
/* 81 */	"lval: INDEX(expr,ID)",
/* 82 */	"assign: ID",
/* 83 */	"assign: INDEX(expr,ID)",
/* 84 */	"expr: CHARS(NIL,INT)",
/* 85 */	"expr: CHARS(NIL,CHAR)",
/* 86 */	"expr: CHARS(NIL,STR)",
/* 87 */	"expr: chars",
/* 88 */	"expr: lval",
/* 89 */	"expr: READ",
/* 90 */	"expr: ADDR(lval)",
/* 91 */	"expr: ADD(expr,expr)",
/* 92 */	"expr: SUB(expr,expr)",
/* 93 */	"expr: MUL(expr,expr)",
/* 94 */	"expr: DIV(expr,expr)",
/* 95 */	"expr: MOD(expr,expr)",
/* 96 */	"expr: POW(expr,expr)",
/* 97 */	"expr: EQU(expr,expr)",
/* 98 */	"expr: NE(expr,expr)",
/* 99 */	"expr: GE(expr,expr)",
/* 100 */	"expr: LE(expr,expr)",
/* 101 */	"expr: LT(expr,expr)",
/* 102 */	"expr: GT(expr,expr)",
/* 103 */	"expr: AND(and,expr)",
/* 104 */	"and: expr",
/* 105 */	"expr: OR(or,expr)",
/* 106 */	"or: expr",
/* 107 */	"expr: NOT(expr)",
/* 108 */	"expr: UMINUS(expr)",
/* 109 */	"expr: EQ(expr,assign)",
/* 110 */	"expr: IDARGS(ID,exprs)",
/* 111 */	"exprs: COMMA(expr,NIL)",
/* 112 */	"exprs: COMMA(expr,exprs)",
};

#ifndef TRACE
static void yytrace(NODEPTR_TYPE p, int eruleno, int cost, int bestcost)
{
	int op = OP_LABEL(p);
	YYCONST char *tname = yytermname[op] ? yytermname[op] : "?";
	fprintf(stderr, "0x%lx:%s matched %s with cost %d vs. %d\n", (long)p, tname, yystring[eruleno], cost, bestcost);
}
#endif

static short yydecode_program[] = {
	0,
	1,
	2,
};

static short yydecode_decls[] = {
	0,
	3,
	4,
};

static short yydecode_funcmain[] = {
	0,
	16,
};

static short yydecode_main[] = {
	0,
	47,
};

static short yydecode_gdecls[] = {
	0,
	5,
	6,
};

static short yydecode_decl[] = {
	0,
	7,
	8,
};

static short yydecode_vardecl[] = {
	0,
	22,
	23,
	24,
};

static short yydecode_funcname[] = {
	0,
	15,
};

static short yydecode_fargs[] = {
	0,
	12,
	13,
	14,
};

static short yydecode_eqbody[] = {
	0,
	45,
	46,
};

static short yydecode_farg[] = {
	0,
	9,
	10,
	11,
};

static short yydecode_vdim[] = {
	0,
	25,
	26,
};

static short yydecode_fvar[] = {
	0,
	17,
	18,
	19,
};

static short yydecode_fvars[] = {
	0,
	20,
	21,
};

static short yydecode_eqint[] = {
	0,
	27,
	28,
};

static short yydecode_eqstr[] = {
	0,
	29,
	30,
};

static short yydecode_eqvec[] = {
	0,
	41,
	42,
};

static short yydecode_eqchars[] = {
	0,
	31,
	32,
};

static short yydecode_eqchar[] = {
	0,
	33,
	34,
	35,
};

static short yydecode_chars[] = {
	0,
	36,
	37,
};

static short yydecode_char[] = {
	0,
	38,
	39,
	40,
};

static short yydecode_ints[] = {
	0,
	43,
	44,
};

static short yydecode_body[] = {
	0,
	50,
};

static short yydecode_mainfvars[] = {
	0,
	48,
	49,
};

static short yydecode_instrs[] = {
	0,
	61,
	62,
};

static short yydecode_bodyfvars[] = {
	0,
	51,
	52,
};

static short yydecode_ret[] = {
	0,
	53,
	54,
	55,
};

static short yydecode_expr[] = {
	0,
	84,
	85,
	86,
	87,
	88,
	89,
	90,
	91,
	92,
	93,
	94,
	95,
	96,
	97,
	98,
	99,
	100,
	101,
	102,
	103,
	105,
	107,
	108,
	109,
	110,
};

static short yydecode_loop[] = {
	0,
	56,
	57,
	58,
};

static short yydecode_block[] = {
	0,
	59,
};

static short yydecode_forblock[] = {
	0,
	60,
};

static short yydecode_instr[] = {
	0,
	63,
	64,
	65,
	66,
	67,
};

static short yydecode_if[] = {
	0,
	69,
};

static short yydecode_elifs[] = {
	0,
	76,
	77,
};

static short yydecode_else[] = {
	0,
	78,
	79,
};

static short yydecode_init[] = {
	0,
	71,
};

static short yydecode_forcond[] = {
	0,
	72,
};

static short yydecode_postexpr[] = {
	0,
	73,
};

static short yydecode_alloc[] = {
	0,
	68,
};

static short yydecode_lval[] = {
	0,
	80,
	81,
};

static short yydecode_cond[] = {
	0,
	74,
};

static short yydecode_ifelse[] = {
	0,
	70,
};

static short yydecode_test[] = {
	0,
	75,
};

static short yydecode_assign[] = {
	0,
	82,
	83,
};

static short yydecode_and[] = {
	0,
	104,
};

static short yydecode_or[] = {
	0,
	106,
};

static short yydecode_exprs[] = {
	0,
	111,
	112,
};

static int yyrule(void *state, int goalnt) {
	if (goalnt < 1 || goalnt > 47)
		PANIC("yyrule", "Bad goal nonterminal", goalnt);
	if (!state)
		return 0;
	switch (goalnt) {
	case yyprogram_NT:	return yydecode_program[((struct yystate *)state)->rule.yyprogram];
	case yydecls_NT:	return yydecode_decls[((struct yystate *)state)->rule.yydecls];
	case yyfuncmain_NT:	return yydecode_funcmain[((struct yystate *)state)->rule.yyfuncmain];
	case yymain_NT:	return yydecode_main[((struct yystate *)state)->rule.yymain];
	case yygdecls_NT:	return yydecode_gdecls[((struct yystate *)state)->rule.yygdecls];
	case yydecl_NT:	return yydecode_decl[((struct yystate *)state)->rule.yydecl];
	case yyvardecl_NT:	return yydecode_vardecl[((struct yystate *)state)->rule.yyvardecl];
	case yyfuncname_NT:	return yydecode_funcname[((struct yystate *)state)->rule.yyfuncname];
	case yyfargs_NT:	return yydecode_fargs[((struct yystate *)state)->rule.yyfargs];
	case yyeqbody_NT:	return yydecode_eqbody[((struct yystate *)state)->rule.yyeqbody];
	case yyfarg_NT:	return yydecode_farg[((struct yystate *)state)->rule.yyfarg];
	case yyvdim_NT:	return yydecode_vdim[((struct yystate *)state)->rule.yyvdim];
	case yyfvar_NT:	return yydecode_fvar[((struct yystate *)state)->rule.yyfvar];
	case yyfvars_NT:	return yydecode_fvars[((struct yystate *)state)->rule.yyfvars];
	case yyeqint_NT:	return yydecode_eqint[((struct yystate *)state)->rule.yyeqint];
	case yyeqstr_NT:	return yydecode_eqstr[((struct yystate *)state)->rule.yyeqstr];
	case yyeqvec_NT:	return yydecode_eqvec[((struct yystate *)state)->rule.yyeqvec];
	case yyeqchars_NT:	return yydecode_eqchars[((struct yystate *)state)->rule.yyeqchars];
	case yyeqchar_NT:	return yydecode_eqchar[((struct yystate *)state)->rule.yyeqchar];
	case yychars_NT:	return yydecode_chars[((struct yystate *)state)->rule.yychars];
	case yychar_NT:	return yydecode_char[((struct yystate *)state)->rule.yychar];
	case yyints_NT:	return yydecode_ints[((struct yystate *)state)->rule.yyints];
	case yybody_NT:	return yydecode_body[((struct yystate *)state)->rule.yybody];
	case yymainfvars_NT:	return yydecode_mainfvars[((struct yystate *)state)->rule.yymainfvars];
	case yyinstrs_NT:	return yydecode_instrs[((struct yystate *)state)->rule.yyinstrs];
	case yybodyfvars_NT:	return yydecode_bodyfvars[((struct yystate *)state)->rule.yybodyfvars];
	case yyret_NT:	return yydecode_ret[((struct yystate *)state)->rule.yyret];
	case yyexpr_NT:	return yydecode_expr[((struct yystate *)state)->rule.yyexpr];
	case yyloop_NT:	return yydecode_loop[((struct yystate *)state)->rule.yyloop];
	case yyblock_NT:	return yydecode_block[((struct yystate *)state)->rule.yyblock];
	case yyforblock_NT:	return yydecode_forblock[((struct yystate *)state)->rule.yyforblock];
	case yyinstr_NT:	return yydecode_instr[((struct yystate *)state)->rule.yyinstr];
	case yyif_NT:	return yydecode_if[((struct yystate *)state)->rule.yyif];
	case yyelifs_NT:	return yydecode_elifs[((struct yystate *)state)->rule.yyelifs];
	case yyelse_NT:	return yydecode_else[((struct yystate *)state)->rule.yyelse];
	case yyinit_NT:	return yydecode_init[((struct yystate *)state)->rule.yyinit];
	case yyforcond_NT:	return yydecode_forcond[((struct yystate *)state)->rule.yyforcond];
	case yypostexpr_NT:	return yydecode_postexpr[((struct yystate *)state)->rule.yypostexpr];
	case yyalloc_NT:	return yydecode_alloc[((struct yystate *)state)->rule.yyalloc];
	case yylval_NT:	return yydecode_lval[((struct yystate *)state)->rule.yylval];
	case yycond_NT:	return yydecode_cond[((struct yystate *)state)->rule.yycond];
	case yyifelse_NT:	return yydecode_ifelse[((struct yystate *)state)->rule.yyifelse];
	case yytest_NT:	return yydecode_test[((struct yystate *)state)->rule.yytest];
	case yyassign_NT:	return yydecode_assign[((struct yystate *)state)->rule.yyassign];
	case yyand_NT:	return yydecode_and[((struct yystate *)state)->rule.yyand];
	case yyor_NT:	return yydecode_or[((struct yystate *)state)->rule.yyor];
	case yyexprs_NT:	return yydecode_exprs[((struct yystate *)state)->rule.yyexprs];
	default:
		PANIC("yyrule", "Bad goal nonterminal", goalnt);
		return 0;
	}
}

static void yyclosure_gdecls(NODEPTR_TYPE, int);
static void yyclosure_fvars(NODEPTR_TYPE, int);
static void yyclosure_eqchars(NODEPTR_TYPE, int);
static void yyclosure_chars(NODEPTR_TYPE, int);
static void yyclosure_ints(NODEPTR_TYPE, int);
static void yyclosure_body(NODEPTR_TYPE, int);
static void yyclosure_ret(NODEPTR_TYPE, int);
static void yyclosure_expr(NODEPTR_TYPE, int);
static void yyclosure_block(NODEPTR_TYPE, int);
static void yyclosure_lval(NODEPTR_TYPE, int);
static void yyclosure_test(NODEPTR_TYPE, int);

static void yyclosure_gdecls(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 4, c + 1, p->cost[yydecls_NT]);
	if (c + 1 < p->cost[yydecls_NT]) {
		p->cost[yydecls_NT] = c + 1;
		p->rule.yydecls = 2;
	}
}

static void yyclosure_fvars(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 52, c + 1, p->cost[yybodyfvars_NT]);
	if (c + 1 < p->cost[yybodyfvars_NT]) {
		p->cost[yybodyfvars_NT] = c + 1;
		p->rule.yybodyfvars = 2;
	}
	yytrace(a, 49, c + 1, p->cost[yymainfvars_NT]);
	if (c + 1 < p->cost[yymainfvars_NT]) {
		p->cost[yymainfvars_NT] = c + 1;
		p->rule.yymainfvars = 2;
	}
}

static void yyclosure_eqchars(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 30, c + 1, p->cost[yyeqstr_NT]);
	if (c + 1 < p->cost[yyeqstr_NT]) {
		p->cost[yyeqstr_NT] = c + 1;
		p->rule.yyeqstr = 2;
	}
}

static void yyclosure_chars(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 87, c + 1, p->cost[yyexpr_NT]);
	if (c + 1 < p->cost[yyexpr_NT]) {
		p->cost[yyexpr_NT] = c + 1;
		p->rule.yyexpr = 4;
		yyclosure_expr(a, c + 1);
	}
}

static void yyclosure_ints(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 42, c + 1, p->cost[yyeqvec_NT]);
	if (c + 1 < p->cost[yyeqvec_NT]) {
		p->cost[yyeqvec_NT] = c + 1;
		p->rule.yyeqvec = 2;
	}
}

static void yyclosure_body(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 46, c + 1, p->cost[yyeqbody_NT]);
	if (c + 1 < p->cost[yyeqbody_NT]) {
		p->cost[yyeqbody_NT] = c + 1;
		p->rule.yyeqbody = 2;
	}
}

static void yyclosure_ret(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 56, c + 1, p->cost[yyloop_NT]);
	if (c + 1 < p->cost[yyloop_NT]) {
		p->cost[yyloop_NT] = c + 1;
		p->rule.yyloop = 1;
	}
}

static void yyclosure_expr(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 106, c + 1, p->cost[yyor_NT]);
	if (c + 1 < p->cost[yyor_NT]) {
		p->cost[yyor_NT] = c + 1;
		p->rule.yyor = 1;
	}
	yytrace(a, 104, c + 1, p->cost[yyand_NT]);
	if (c + 1 < p->cost[yyand_NT]) {
		p->cost[yyand_NT] = c + 1;
		p->rule.yyand = 1;
	}
	yytrace(a, 75, c + 1, p->cost[yytest_NT]);
	if (c + 1 < p->cost[yytest_NT]) {
		p->cost[yytest_NT] = c + 1;
		p->rule.yytest = 1;
		yyclosure_test(a, c + 1);
	}
	yytrace(a, 74, c + 1, p->cost[yycond_NT]);
	if (c + 1 < p->cost[yycond_NT]) {
		p->cost[yycond_NT] = c + 1;
		p->rule.yycond = 1;
	}
	yytrace(a, 72, c + 1, p->cost[yyforcond_NT]);
	if (c + 1 < p->cost[yyforcond_NT]) {
		p->cost[yyforcond_NT] = c + 1;
		p->rule.yyforcond = 1;
	}
	yytrace(a, 68, c + 1, p->cost[yyalloc_NT]);
	if (c + 1 < p->cost[yyalloc_NT]) {
		p->cost[yyalloc_NT] = c + 1;
		p->rule.yyalloc = 1;
	}
	yytrace(a, 66, c + 1, p->cost[yyinstr_NT]);
	if (c + 1 < p->cost[yyinstr_NT]) {
		p->cost[yyinstr_NT] = c + 1;
		p->rule.yyinstr = 4;
	}
}

static void yyclosure_block(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 79, c + 0, p->cost[yyelse_NT]);
	if (c + 0 < p->cost[yyelse_NT]) {
		p->cost[yyelse_NT] = c + 0;
		p->rule.yyelse = 2;
	}
}

static void yyclosure_lval(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 88, c + 0, p->cost[yyexpr_NT]);
	if (c + 0 < p->cost[yyexpr_NT]) {
		p->cost[yyexpr_NT] = c + 0;
		p->rule.yyexpr = 5;
		yyclosure_expr(a, c + 0);
	}
}

static void yyclosure_test(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 73, c + 1, p->cost[yypostexpr_NT]);
	if (c + 1 < p->cost[yypostexpr_NT]) {
		p->cost[yypostexpr_NT] = c + 1;
		p->rule.yypostexpr = 1;
	}
	yytrace(a, 71, c + 1, p->cost[yyinit_NT]);
	if (c + 1 < p->cost[yyinit_NT]) {
		p->cost[yyinit_NT] = c + 1;
		p->rule.yyinit = 1;
	}
}

static void yylabel(NODEPTR_TYPE a, NODEPTR_TYPE u) {
	int c;
	struct yystate *p;

	if (!a)
		PANIC("yylabel", "Null tree in", OP_LABEL(u));
	STATE_LABEL(a) = p = (struct yystate *)malloc(sizeof *p);
	memset(p, 0, sizeof *p);
	p->cost[1] =
	p->cost[2] =
	p->cost[3] =
	p->cost[4] =
	p->cost[5] =
	p->cost[6] =
	p->cost[7] =
	p->cost[8] =
	p->cost[9] =
	p->cost[10] =
	p->cost[11] =
	p->cost[12] =
	p->cost[13] =
	p->cost[14] =
	p->cost[15] =
	p->cost[16] =
	p->cost[17] =
	p->cost[18] =
	p->cost[19] =
	p->cost[20] =
	p->cost[21] =
	p->cost[22] =
	p->cost[23] =
	p->cost[24] =
	p->cost[25] =
	p->cost[26] =
	p->cost[27] =
	p->cost[28] =
	p->cost[29] =
	p->cost[30] =
	p->cost[31] =
	p->cost[32] =
	p->cost[33] =
	p->cost[34] =
	p->cost[35] =
	p->cost[36] =
	p->cost[37] =
	p->cost[38] =
	p->cost[39] =
	p->cost[40] =
	p->cost[41] =
	p->cost[42] =
	p->cost[43] =
	p->cost[44] =
	p->cost[45] =
	p->cost[46] =
	p->cost[47] =
		0x7fff;
	switch (OP_LABEL(a)) {
	case 33: /* PRINT */
		yylabel(LEFT_CHILD(a),a);
		/* instr: PRINT(expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + 3;
		yytrace(a, 65, c + 0, p->cost[yyinstr_NT]);
		if (c + 0 < p->cost[yyinstr_NT]) {
			p->cost[yyinstr_NT] = c + 0;
			p->rule.yyinstr = 3;
		}
		break;
	case 35: /* ALLOC */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* instr: ALLOC(alloc,lval) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyalloc_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yylval_NT] + 1;
		yytrace(a, 67, c + 0, p->cost[yyinstr_NT]);
		if (c + 0 < p->cost[yyinstr_NT]) {
			p->cost[yyinstr_NT] = c + 0;
			p->rule.yyinstr = 5;
		}
		break;
	case 37: /* MOD */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expr: MOD(expr,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 95, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 12;
			yyclosure_expr(a, c + 0);
		}
		break;
	case 38: /* AND */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expr: AND(and,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyand_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 103, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 20;
			yyclosure_expr(a, c + 0);
		}
		break;
	case 40: /* IDARGS */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		if (	/* expr: IDARGS(ID,exprs) */
			OP_LABEL(LEFT_CHILD(a)) == 259 /* ID */
		) {
			c = ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexprs_NT] + 1;
			yytrace(a, 110, c + 0, p->cost[yyexpr_NT]);
			if (c + 0 < p->cost[yyexpr_NT]) {
				p->cost[yyexpr_NT] = c + 0;
				p->rule.yyexpr = 25;
				yyclosure_expr(a, c + 0);
			}
		}
		break;
	case 42: /* MUL */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expr: MUL(expr,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 93, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 10;
			yyclosure_expr(a, c + 0);
		}
		break;
	case 43: /* ADD */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expr: ADD(expr,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 91, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 8;
			yyclosure_expr(a, c + 0);
		}
		break;
	case 44: /* COMMA */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		if (	/* exprs: COMMA(expr,NIL) */
			OP_LABEL(RIGHT_CHILD(a)) == 293 /* NIL */
		) {
			c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + 1;
			yytrace(a, 111, c + 0, p->cost[yyexprs_NT]);
			if (c + 0 < p->cost[yyexprs_NT]) {
				p->cost[yyexprs_NT] = c + 0;
				p->rule.yyexprs = 1;
			}
		}
		/* exprs: COMMA(expr,exprs) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexprs_NT] + 1;
		yytrace(a, 112, c + 0, p->cost[yyexprs_NT]);
		if (c + 0 < p->cost[yyexprs_NT]) {
			p->cost[yyexprs_NT] = c + 0;
			p->rule.yyexprs = 2;
		}
		break;
	case 45: /* SUB */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expr: SUB(expr,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 92, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 9;
			yyclosure_expr(a, c + 0);
		}
		break;
	case 47: /* DIV */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expr: DIV(expr,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 94, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 11;
			yyclosure_expr(a, c + 0);
		}
		break;
	case 59: /* STMT */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* block: STMT(instrs,loop) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyinstrs_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyloop_NT] + 1;
		yytrace(a, 59, c + 0, p->cost[yyblock_NT]);
		if (c + 0 < p->cost[yyblock_NT]) {
			p->cost[yyblock_NT] = c + 0;
			p->rule.yyblock = 1;
			yyclosure_block(a, c + 0);
		}
		/* forblock: STMT(instrs,loop) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyinstrs_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyloop_NT] + 1;
		yytrace(a, 60, c + 0, p->cost[yyforblock_NT]);
		if (c + 0 < p->cost[yyforblock_NT]) {
			p->cost[yyforblock_NT] = c + 0;
			p->rule.yyforblock = 1;
		}
		/* instrs: STMT(instrs,instr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyinstrs_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyinstr_NT] + 1;
		yytrace(a, 62, c + 0, p->cost[yyinstrs_NT]);
		if (c + 0 < p->cost[yyinstrs_NT]) {
			p->cost[yyinstrs_NT] = c + 0;
			p->rule.yyinstrs = 2;
		}
		break;
	case 60: /* LT */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expr: LT(expr,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 101, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 18;
			yyclosure_expr(a, c + 0);
		}
		break;
	case 61: /* EQU */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expr: EQU(expr,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 97, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 14;
			yyclosure_expr(a, c + 0);
		}
		break;
	case 62: /* GT */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expr: GT(expr,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 102, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 19;
			yyclosure_expr(a, c + 0);
		}
		break;
	case 63: /* READ */
		/* expr: READ */
		yytrace(a, 89, 1 + 0, p->cost[yyexpr_NT]);
		if (1 + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = 1 + 0;
			p->rule.yyexpr = 6;
			yyclosure_expr(a, 1 + 0);
		}
		break;
	case 91: /* INDEX */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		if (	/* lval: INDEX(expr,ID) */
			OP_LABEL(RIGHT_CHILD(a)) == 259 /* ID */
		) {
			c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + 1;
			yytrace(a, 81, c + 0, p->cost[yylval_NT]);
			if (c + 0 < p->cost[yylval_NT]) {
				p->cost[yylval_NT] = c + 0;
				p->rule.yylval = 2;
				yyclosure_lval(a, c + 0);
			}
		}
		if (	/* assign: INDEX(expr,ID) */
			OP_LABEL(RIGHT_CHILD(a)) == 259 /* ID */
		) {
			c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + 0;
			yytrace(a, 83, c + 0, p->cost[yyassign_NT]);
			if (c + 0 < p->cost[yyassign_NT]) {
				p->cost[yyassign_NT] = c + 0;
				p->rule.yyassign = 2;
			}
		}
		break;
	case 94: /* POW */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expr: POW(expr,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 96, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 13;
			yyclosure_expr(a, c + 0);
		}
		break;
	case 124: /* OR */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expr: OR(or,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyor_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 105, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 21;
			yyclosure_expr(a, c + 0);
		}
		break;
	case 126: /* NOT */
		yylabel(LEFT_CHILD(a),a);
		/* expr: NOT(expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 107, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 22;
			yyclosure_expr(a, c + 0);
		}
		break;
	case 257: /* INT */
		/* vdim: INT */
		yytrace(a, 26, 1 + 0, p->cost[yyvdim_NT]);
		if (1 + 0 < p->cost[yyvdim_NT]) {
			p->cost[yyvdim_NT] = 1 + 0;
			p->rule.yyvdim = 2;
		}
		/* eqint: INT */
		yytrace(a, 28, 1 + 0, p->cost[yyeqint_NT]);
		if (1 + 0 < p->cost[yyeqint_NT]) {
			p->cost[yyeqint_NT] = 1 + 0;
			p->rule.yyeqint = 2;
		}
		/* eqchar: INT */
		yytrace(a, 33, 1 + 0, p->cost[yyeqchar_NT]);
		if (1 + 0 < p->cost[yyeqchar_NT]) {
			p->cost[yyeqchar_NT] = 1 + 0;
			p->rule.yyeqchar = 1;
		}
		/* char: INT */
		yytrace(a, 38, 0 + 0, p->cost[yychar_NT]);
		if (0 + 0 < p->cost[yychar_NT]) {
			p->cost[yychar_NT] = 0 + 0;
			p->rule.yychar = 1;
		}
		/* ints: INT */
		yytrace(a, 43, 1 + 0, p->cost[yyints_NT]);
		if (1 + 0 < p->cost[yyints_NT]) {
			p->cost[yyints_NT] = 1 + 0;
			p->rule.yyints = 1;
			yyclosure_ints(a, 1 + 0);
		}
		break;
	case 258: /* CHAR */
		/* eqchar: CHAR */
		yytrace(a, 34, 1 + 0, p->cost[yyeqchar_NT]);
		if (1 + 0 < p->cost[yyeqchar_NT]) {
			p->cost[yyeqchar_NT] = 1 + 0;
			p->rule.yyeqchar = 2;
		}
		/* char: CHAR */
		yytrace(a, 39, 0 + 0, p->cost[yychar_NT]);
		if (0 + 0 < p->cost[yychar_NT]) {
			p->cost[yychar_NT] = 0 + 0;
			p->rule.yychar = 2;
		}
		break;
	case 259: /* ID */
		/* lval: ID */
		yytrace(a, 80, 1 + 0, p->cost[yylval_NT]);
		if (1 + 0 < p->cost[yylval_NT]) {
			p->cost[yylval_NT] = 1 + 0;
			p->rule.yylval = 1;
			yyclosure_lval(a, 1 + 0);
		}
		/* assign: ID */
		yytrace(a, 82, 0 + 0, p->cost[yyassign_NT]);
		if (0 + 0 < p->cost[yyassign_NT]) {
			p->cost[yyassign_NT] = 0 + 0;
			p->rule.yyassign = 1;
		}
		break;
	case 260: /* STR */
		/* eqchar: STR */
		yytrace(a, 35, 1 + 0, p->cost[yyeqchar_NT]);
		if (1 + 0 < p->cost[yyeqchar_NT]) {
			p->cost[yyeqchar_NT] = 1 + 0;
			p->rule.yyeqchar = 3;
		}
		/* char: STR */
		yytrace(a, 40, 0 + 0, p->cost[yychar_NT]);
		if (0 + 0 < p->cost[yychar_NT]) {
			p->cost[yychar_NT] = 0 + 0;
			p->rule.yychar = 3;
		}
		break;
	case 261: /* PROGRAM */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		if (	/* program: PROGRAM(decls,FUNCTION(funcmain,FARGS(NIL,main))) */
			OP_LABEL(RIGHT_CHILD(a)) == 269 && /* FUNCTION */
			OP_LABEL(RIGHT_CHILD(RIGHT_CHILD(a))) == 286 && /* FARGS */
			OP_LABEL(LEFT_CHILD(RIGHT_CHILD(RIGHT_CHILD(a)))) == 293 /* NIL */
		) {
			c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yydecls_NT] + ((struct yystate *)STATE_LABEL(LEFT_CHILD(RIGHT_CHILD(a))))->cost[yyfuncmain_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(RIGHT_CHILD(RIGHT_CHILD(a)))))->cost[yymain_NT] + 1;
			yytrace(a, 1, c + 0, p->cost[yyprogram_NT]);
			if (c + 0 < p->cost[yyprogram_NT]) {
				p->cost[yyprogram_NT] = c + 0;
				p->rule.yyprogram = 1;
			}
		}
		break;
	case 262: /* MODULE */
		yylabel(LEFT_CHILD(a),a);
		/* program: MODULE(decls) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yydecls_NT] + 1;
		yytrace(a, 2, c + 0, p->cost[yyprogram_NT]);
		if (c + 0 < p->cost[yyprogram_NT]) {
			p->cost[yyprogram_NT] = c + 0;
			p->rule.yyprogram = 2;
		}
		break;
	case 263: /* END */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		if (	/* funcname: END(ID,INT) */
			OP_LABEL(LEFT_CHILD(a)) == 259 && /* ID */
			OP_LABEL(RIGHT_CHILD(a)) == 257 /* INT */
		) {
			c = 1;
			yytrace(a, 15, c + 0, p->cost[yyfuncname_NT]);
			if (c + 0 < p->cost[yyfuncname_NT]) {
				p->cost[yyfuncname_NT] = c + 0;
				p->rule.yyfuncname = 1;
			}
		}
		if (	/* funcmain: END(ID,INT) */
			OP_LABEL(LEFT_CHILD(a)) == 259 && /* ID */
			OP_LABEL(RIGHT_CHILD(a)) == 257 /* INT */
		) {
			c = 1;
			yytrace(a, 16, c + 0, p->cost[yyfuncmain_NT]);
			if (c + 0 < p->cost[yyfuncmain_NT]) {
				p->cost[yyfuncmain_NT] = c + 0;
				p->rule.yyfuncmain = 1;
			}
		}
		break;
	case 264: /* PUBLIC */
		return;
	case 265: /* FORWARD */
		return;
	case 266: /* STRING */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		if (	/* farg: STRING(ID,NIL) */
			OP_LABEL(LEFT_CHILD(a)) == 259 && /* ID */
			OP_LABEL(RIGHT_CHILD(a)) == 293 /* NIL */
		) {
			c = 1;
			yytrace(a, 10, c + 0, p->cost[yyfarg_NT]);
			if (c + 0 < p->cost[yyfarg_NT]) {
				p->cost[yyfarg_NT] = c + 0;
				p->rule.yyfarg = 2;
			}
		}
		if (	/* fvar: STRING(ID,NIL) */
			OP_LABEL(LEFT_CHILD(a)) == 259 && /* ID */
			OP_LABEL(RIGHT_CHILD(a)) == 293 /* NIL */
		) {
			c = 1;
			yytrace(a, 18, c + 0, p->cost[yyfvar_NT]);
			if (c + 0 < p->cost[yyfvar_NT]) {
				p->cost[yyfvar_NT] = c + 0;
				p->rule.yyfvar = 2;
			}
		}
		if (	/* vardecl: STRING(ID,eqstr) */
			OP_LABEL(LEFT_CHILD(a)) == 259 /* ID */
		) {
			c = ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyeqstr_NT] + 1;
			yytrace(a, 23, c + 0, p->cost[yyvardecl_NT]);
			if (c + 0 < p->cost[yyvardecl_NT]) {
				p->cost[yyvardecl_NT] = c + 0;
				p->rule.yyvardecl = 2;
			}
		}
		break;
	case 267: /* NUMBER */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		if (	/* farg: NUMBER(ID,NIL) */
			OP_LABEL(LEFT_CHILD(a)) == 259 && /* ID */
			OP_LABEL(RIGHT_CHILD(a)) == 293 /* NIL */
		) {
			c = 1;
			yytrace(a, 9, c + 0, p->cost[yyfarg_NT]);
			if (c + 0 < p->cost[yyfarg_NT]) {
				p->cost[yyfarg_NT] = c + 0;
				p->rule.yyfarg = 1;
			}
		}
		if (	/* fvar: NUMBER(ID,NIL) */
			OP_LABEL(LEFT_CHILD(a)) == 259 && /* ID */
			OP_LABEL(RIGHT_CHILD(a)) == 293 /* NIL */
		) {
			c = 1;
			yytrace(a, 17, c + 0, p->cost[yyfvar_NT]);
			if (c + 0 < p->cost[yyfvar_NT]) {
				p->cost[yyfvar_NT] = c + 0;
				p->rule.yyfvar = 1;
			}
		}
		if (	/* vardecl: NUMBER(ID,eqint) */
			OP_LABEL(LEFT_CHILD(a)) == 259 /* ID */
		) {
			c = ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyeqint_NT] + 1;
			yytrace(a, 22, c + 0, p->cost[yyvardecl_NT]);
			if (c + 0 < p->cost[yyvardecl_NT]) {
				p->cost[yyvardecl_NT] = c + 0;
				p->rule.yyvardecl = 1;
			}
		}
		break;
	case 268: /* ARRAY */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		if (	/* farg: ARRAY(ID,INTS(vdim,NIL)) */
			OP_LABEL(LEFT_CHILD(a)) == 259 && /* ID */
			OP_LABEL(RIGHT_CHILD(a)) == 288 && /* INTS */
			OP_LABEL(RIGHT_CHILD(RIGHT_CHILD(a))) == 293 /* NIL */
		) {
			c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(RIGHT_CHILD(a))))->cost[yyvdim_NT] + 1;
			yytrace(a, 11, c + 0, p->cost[yyfarg_NT]);
			if (c + 0 < p->cost[yyfarg_NT]) {
				p->cost[yyfarg_NT] = c + 0;
				p->rule.yyfarg = 3;
			}
		}
		if (	/* fvar: ARRAY(ID,INTS(vdim,NIL)) */
			OP_LABEL(LEFT_CHILD(a)) == 259 && /* ID */
			OP_LABEL(RIGHT_CHILD(a)) == 288 && /* INTS */
			OP_LABEL(RIGHT_CHILD(RIGHT_CHILD(a))) == 293 /* NIL */
		) {
			c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(RIGHT_CHILD(a))))->cost[yyvdim_NT] + 1;
			yytrace(a, 19, c + 0, p->cost[yyfvar_NT]);
			if (c + 0 < p->cost[yyfvar_NT]) {
				p->cost[yyfvar_NT] = c + 0;
				p->rule.yyfvar = 3;
			}
		}
		if (	/* vardecl: ARRAY(ID,INTS(vdim,eqvec)) */
			OP_LABEL(LEFT_CHILD(a)) == 259 && /* ID */
			OP_LABEL(RIGHT_CHILD(a)) == 288 /* INTS */
		) {
			c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(RIGHT_CHILD(a))))->cost[yyvdim_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(RIGHT_CHILD(a))))->cost[yyeqvec_NT] + 1;
			yytrace(a, 24, c + 0, p->cost[yyvardecl_NT]);
			if (c + 0 < p->cost[yyvardecl_NT]) {
				p->cost[yyvardecl_NT] = c + 0;
				p->rule.yyvardecl = 3;
			}
		}
		break;
	case 269: /* FUNCTION */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		if (	/* decl: FUNCTION(funcname,FARGS(fargs,eqbody)) */
			OP_LABEL(RIGHT_CHILD(a)) == 286 /* FARGS */
		) {
			c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyfuncname_NT] + ((struct yystate *)STATE_LABEL(LEFT_CHILD(RIGHT_CHILD(a))))->cost[yyfargs_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(RIGHT_CHILD(a))))->cost[yyeqbody_NT] + 1;
			yytrace(a, 8, c + 0, p->cost[yydecl_NT]);
			if (c + 0 < p->cost[yydecl_NT]) {
				p->cost[yydecl_NT] = c + 0;
				p->rule.yydecl = 2;
			}
		}
		break;
	case 270: /* VOID */
		return;
	case 271: /* CONST */
		return;
	case 272: /* IF */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* if: IF(cond,block) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yycond_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyblock_NT] + 1;
		yytrace(a, 69, c + 0, p->cost[yyif_NT]);
		if (c + 0 < p->cost[yyif_NT]) {
			p->cost[yyif_NT] = c + 0;
			p->rule.yyif = 1;
		}
		/* ifelse: IF(cond,block) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yycond_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyblock_NT] + 0;
		yytrace(a, 70, c + 0, p->cost[yyifelse_NT]);
		if (c + 0 < p->cost[yyifelse_NT]) {
			p->cost[yyifelse_NT] = c + 0;
			p->rule.yyifelse = 1;
		}
		break;
	case 273: /* THEN */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		return;
	case 274: /* FI */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		if (	/* instr: FI(THEN(if,elifs),else) */
			OP_LABEL(LEFT_CHILD(a)) == 273 /* THEN */
		) {
			c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(LEFT_CHILD(a))))->cost[yyif_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(LEFT_CHILD(a))))->cost[yyelifs_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyelse_NT] + 1;
			yytrace(a, 63, c + 0, p->cost[yyinstr_NT]);
			if (c + 0 < p->cost[yyinstr_NT]) {
				p->cost[yyinstr_NT] = c + 0;
				p->rule.yyinstr = 1;
			}
		}
		break;
	case 275: /* ELIF */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* elifs: ELIF(elifs,ifelse) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyelifs_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyifelse_NT] + 1;
		yytrace(a, 77, c + 0, p->cost[yyelifs_NT]);
		if (c + 0 < p->cost[yyelifs_NT]) {
			p->cost[yyelifs_NT] = c + 0;
			p->rule.yyelifs = 2;
		}
		break;
	case 276: /* ELSE */
		return;
	case 277: /* RETURN */
		yylabel(LEFT_CHILD(a),a);
		if (	/* ret: RETURN(NIL) */
			OP_LABEL(LEFT_CHILD(a)) == 293 /* NIL */
		) {
			c = 1;
			yytrace(a, 53, c + 0, p->cost[yyret_NT]);
			if (c + 0 < p->cost[yyret_NT]) {
				p->cost[yyret_NT] = c + 0;
				p->rule.yyret = 1;
				yyclosure_ret(a, c + 0);
			}
		}
		/* ret: RETURN(expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 54, c + 0, p->cost[yyret_NT]);
		if (c + 0 < p->cost[yyret_NT]) {
			p->cost[yyret_NT] = c + 0;
			p->rule.yyret = 2;
			yyclosure_ret(a, c + 0);
		}
		break;
	case 278: /* START */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* main: START(mainfvars,instrs) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yymainfvars_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyinstrs_NT] + 1;
		yytrace(a, 47, c + 0, p->cost[yymain_NT]);
		if (c + 0 < p->cost[yymain_NT]) {
			p->cost[yymain_NT] = c + 0;
			p->rule.yymain = 1;
		}
		if (	/* body: START(bodyfvars,STMT(instrs,ret)) */
			OP_LABEL(RIGHT_CHILD(a)) == 59 /* STMT */
		) {
			c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yybodyfvars_NT] + ((struct yystate *)STATE_LABEL(LEFT_CHILD(RIGHT_CHILD(a))))->cost[yyinstrs_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(RIGHT_CHILD(a))))->cost[yyret_NT] + 1;
			yytrace(a, 50, c + 0, p->cost[yybody_NT]);
			if (c + 0 < p->cost[yybody_NT]) {
				p->cost[yybody_NT] = c + 0;
				p->rule.yybody = 1;
				yyclosure_body(a, c + 0);
			}
		}
		break;
	case 279: /* FOR */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		if (	/* instr: FOR(UNTIL(init,forcond),STEP(forblock,postexpr)) */
			OP_LABEL(LEFT_CHILD(a)) == 280 && /* UNTIL */
			OP_LABEL(RIGHT_CHILD(a)) == 281 /* STEP */
		) {
			c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(LEFT_CHILD(a))))->cost[yyinit_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(LEFT_CHILD(a))))->cost[yyforcond_NT] + ((struct yystate *)STATE_LABEL(LEFT_CHILD(RIGHT_CHILD(a))))->cost[yyforblock_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(RIGHT_CHILD(a))))->cost[yypostexpr_NT] + 1;
			yytrace(a, 64, c + 0, p->cost[yyinstr_NT]);
			if (c + 0 < p->cost[yyinstr_NT]) {
				p->cost[yyinstr_NT] = c + 0;
				p->rule.yyinstr = 2;
			}
		}
		break;
	case 280: /* UNTIL */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		return;
	case 281: /* STEP */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		return;
	case 282: /* DO */
		return;
	case 283: /* DONE */
		return;
	case 284: /* REPEAT */
		/* loop: REPEAT */
		yytrace(a, 57, 1 + 0, p->cost[yyloop_NT]);
		if (1 + 0 < p->cost[yyloop_NT]) {
			p->cost[yyloop_NT] = 1 + 0;
			p->rule.yyloop = 2;
		}
		break;
	case 285: /* STOP */
		/* loop: STOP */
		yytrace(a, 58, 1 + 0, p->cost[yyloop_NT]);
		if (1 + 0 < p->cost[yyloop_NT]) {
			p->cost[yyloop_NT] = 1 + 0;
			p->rule.yyloop = 3;
		}
		break;
	case 286: /* FARGS */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		return;
	case 287: /* CHARS */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		if (	/* eqchars: CHARS(NIL,eqchar) */
			OP_LABEL(LEFT_CHILD(a)) == 293 /* NIL */
		) {
			c = ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyeqchar_NT] + 1;
			yytrace(a, 31, c + 0, p->cost[yyeqchars_NT]);
			if (c + 0 < p->cost[yyeqchars_NT]) {
				p->cost[yyeqchars_NT] = c + 0;
				p->rule.yyeqchars = 1;
				yyclosure_eqchars(a, c + 0);
			}
		}
		/* eqchars: CHARS(eqchars,eqchar) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyeqchars_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyeqchar_NT] + 1;
		yytrace(a, 32, c + 0, p->cost[yyeqchars_NT]);
		if (c + 0 < p->cost[yyeqchars_NT]) {
			p->cost[yyeqchars_NT] = c + 0;
			p->rule.yyeqchars = 2;
			yyclosure_eqchars(a, c + 0);
		}
		if (	/* chars: CHARS(NIL,char) */
			OP_LABEL(LEFT_CHILD(a)) == 293 /* NIL */
		) {
			c = ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yychar_NT] + 1;
			yytrace(a, 36, c + 0, p->cost[yychars_NT]);
			if (c + 0 < p->cost[yychars_NT]) {
				p->cost[yychars_NT] = c + 0;
				p->rule.yychars = 1;
				yyclosure_chars(a, c + 0);
			}
		}
		/* chars: CHARS(chars,char) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yychars_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yychar_NT] + 1;
		yytrace(a, 37, c + 0, p->cost[yychars_NT]);
		if (c + 0 < p->cost[yychars_NT]) {
			p->cost[yychars_NT] = c + 0;
			p->rule.yychars = 2;
			yyclosure_chars(a, c + 0);
		}
		if (	/* expr: CHARS(NIL,INT) */
			OP_LABEL(LEFT_CHILD(a)) == 293 && /* NIL */
			OP_LABEL(RIGHT_CHILD(a)) == 257 /* INT */
		) {
			c = 1;
			yytrace(a, 84, c + 0, p->cost[yyexpr_NT]);
			if (c + 0 < p->cost[yyexpr_NT]) {
				p->cost[yyexpr_NT] = c + 0;
				p->rule.yyexpr = 1;
				yyclosure_expr(a, c + 0);
			}
		}
		if (	/* expr: CHARS(NIL,CHAR) */
			OP_LABEL(LEFT_CHILD(a)) == 293 && /* NIL */
			OP_LABEL(RIGHT_CHILD(a)) == 258 /* CHAR */
		) {
			c = 1;
			yytrace(a, 85, c + 0, p->cost[yyexpr_NT]);
			if (c + 0 < p->cost[yyexpr_NT]) {
				p->cost[yyexpr_NT] = c + 0;
				p->rule.yyexpr = 2;
				yyclosure_expr(a, c + 0);
			}
		}
		if (	/* expr: CHARS(NIL,STR) */
			OP_LABEL(LEFT_CHILD(a)) == 293 && /* NIL */
			OP_LABEL(RIGHT_CHILD(a)) == 260 /* STR */
		) {
			c = 1;
			yytrace(a, 86, c + 0, p->cost[yyexpr_NT]);
			if (c + 0 < p->cost[yyexpr_NT]) {
				p->cost[yyexpr_NT] = c + 0;
				p->rule.yyexpr = 3;
				yyclosure_expr(a, c + 0);
			}
		}
		break;
	case 288: /* INTS */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		if (	/* ints: INTS(ints,INT) */
			OP_LABEL(RIGHT_CHILD(a)) == 257 /* INT */
		) {
			c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyints_NT] + 1;
			yytrace(a, 44, c + 0, p->cost[yyints_NT]);
			if (c + 0 < p->cost[yyints_NT]) {
				p->cost[yyints_NT] = c + 0;
				p->rule.yyints = 2;
				yyclosure_ints(a, c + 0);
			}
		}
		break;
	case 289: /* ADDR */
		yylabel(LEFT_CHILD(a),a);
		/* expr: ADDR(lval) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yylval_NT] + 1;
		yytrace(a, 90, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 7;
			yyclosure_expr(a, c + 0);
		}
		break;
	case 290: /* VAR */
		yylabel(LEFT_CHILD(a),a);
		/* decl: VAR(vardecl) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyvardecl_NT] + 1;
		yytrace(a, 7, c + 0, p->cost[yydecl_NT]);
		if (c + 0 < p->cost[yydecl_NT]) {
			p->cost[yydecl_NT] = c + 0;
			p->rule.yydecl = 1;
		}
		break;
	case 291: /* ARGS */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		if (	/* fargs: ARGS(NIL,farg) */
			OP_LABEL(LEFT_CHILD(a)) == 293 /* NIL */
		) {
			c = ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyfarg_NT] + 1;
			yytrace(a, 13, c + 0, p->cost[yyfargs_NT]);
			if (c + 0 < p->cost[yyfargs_NT]) {
				p->cost[yyfargs_NT] = c + 0;
				p->rule.yyfargs = 2;
			}
		}
		/* fargs: ARGS(fargs,farg) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyfargs_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyfarg_NT] + 1;
		yytrace(a, 14, c + 0, p->cost[yyfargs_NT]);
		if (c + 0 < p->cost[yyfargs_NT]) {
			p->cost[yyfargs_NT] = c + 0;
			p->rule.yyfargs = 3;
		}
		if (	/* fvars: ARGS(NIL,fvar) */
			OP_LABEL(LEFT_CHILD(a)) == 293 /* NIL */
		) {
			c = ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyfvar_NT] + 1;
			yytrace(a, 20, c + 0, p->cost[yyfvars_NT]);
			if (c + 0 < p->cost[yyfvars_NT]) {
				p->cost[yyfvars_NT] = c + 0;
				p->rule.yyfvars = 1;
				yyclosure_fvars(a, c + 0);
			}
		}
		/* fvars: ARGS(fvars,fvar) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyfvars_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyfvar_NT] + 1;
		yytrace(a, 21, c + 0, p->cost[yyfvars_NT]);
		if (c + 0 < p->cost[yyfvars_NT]) {
			p->cost[yyfvars_NT] = c + 0;
			p->rule.yyfvars = 2;
			yyclosure_fvars(a, c + 0);
		}
		break;
	case 292: /* DECL */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* gdecls: DECL(gdecls,decl) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yygdecls_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yydecl_NT] + 1;
		yytrace(a, 5, c + 0, p->cost[yygdecls_NT]);
		if (c + 0 < p->cost[yygdecls_NT]) {
			p->cost[yygdecls_NT] = c + 0;
			p->rule.yygdecls = 1;
			yyclosure_gdecls(a, c + 0);
		}
		if (	/* gdecls: DECL(NIL,decl) */
			OP_LABEL(LEFT_CHILD(a)) == 293 /* NIL */
		) {
			c = ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yydecl_NT] + 1;
			yytrace(a, 6, c + 0, p->cost[yygdecls_NT]);
			if (c + 0 < p->cost[yygdecls_NT]) {
				p->cost[yygdecls_NT] = c + 0;
				p->rule.yygdecls = 2;
				yyclosure_gdecls(a, c + 0);
			}
		}
		break;
	case 293: /* NIL */
		/* decls: NIL */
		yytrace(a, 3, 1 + 0, p->cost[yydecls_NT]);
		if (1 + 0 < p->cost[yydecls_NT]) {
			p->cost[yydecls_NT] = 1 + 0;
			p->rule.yydecls = 1;
		}
		/* fargs: NIL */
		yytrace(a, 12, 1 + 0, p->cost[yyfargs_NT]);
		if (1 + 0 < p->cost[yyfargs_NT]) {
			p->cost[yyfargs_NT] = 1 + 0;
			p->rule.yyfargs = 1;
		}
		/* vdim: NIL */
		yytrace(a, 25, 1 + 0, p->cost[yyvdim_NT]);
		if (1 + 0 < p->cost[yyvdim_NT]) {
			p->cost[yyvdim_NT] = 1 + 0;
			p->rule.yyvdim = 1;
		}
		/* eqint: NIL */
		yytrace(a, 27, 1 + 0, p->cost[yyeqint_NT]);
		if (1 + 0 < p->cost[yyeqint_NT]) {
			p->cost[yyeqint_NT] = 1 + 0;
			p->rule.yyeqint = 1;
		}
		/* eqstr: NIL */
		yytrace(a, 29, 1 + 0, p->cost[yyeqstr_NT]);
		if (1 + 0 < p->cost[yyeqstr_NT]) {
			p->cost[yyeqstr_NT] = 1 + 0;
			p->rule.yyeqstr = 1;
		}
		/* eqvec: NIL */
		yytrace(a, 41, 1 + 0, p->cost[yyeqvec_NT]);
		if (1 + 0 < p->cost[yyeqvec_NT]) {
			p->cost[yyeqvec_NT] = 1 + 0;
			p->rule.yyeqvec = 1;
		}
		/* eqbody: NIL */
		yytrace(a, 45, 1 + 0, p->cost[yyeqbody_NT]);
		if (1 + 0 < p->cost[yyeqbody_NT]) {
			p->cost[yyeqbody_NT] = 1 + 0;
			p->rule.yyeqbody = 1;
		}
		/* mainfvars: NIL */
		yytrace(a, 48, 1 + 0, p->cost[yymainfvars_NT]);
		if (1 + 0 < p->cost[yymainfvars_NT]) {
			p->cost[yymainfvars_NT] = 1 + 0;
			p->rule.yymainfvars = 1;
		}
		/* bodyfvars: NIL */
		yytrace(a, 51, 1 + 0, p->cost[yybodyfvars_NT]);
		if (1 + 0 < p->cost[yybodyfvars_NT]) {
			p->cost[yybodyfvars_NT] = 1 + 0;
			p->rule.yybodyfvars = 1;
		}
		/* ret: NIL */
		yytrace(a, 55, 1 + 0, p->cost[yyret_NT]);
		if (1 + 0 < p->cost[yyret_NT]) {
			p->cost[yyret_NT] = 1 + 0;
			p->rule.yyret = 3;
			yyclosure_ret(a, 1 + 0);
		}
		/* instrs: NIL */
		yytrace(a, 61, 1 + 0, p->cost[yyinstrs_NT]);
		if (1 + 0 < p->cost[yyinstrs_NT]) {
			p->cost[yyinstrs_NT] = 1 + 0;
			p->rule.yyinstrs = 1;
		}
		/* elifs: NIL */
		yytrace(a, 76, 0 + 0, p->cost[yyelifs_NT]);
		if (0 + 0 < p->cost[yyelifs_NT]) {
			p->cost[yyelifs_NT] = 0 + 0;
			p->rule.yyelifs = 1;
		}
		/* else: NIL */
		yytrace(a, 78, 0 + 0, p->cost[yyelse_NT]);
		if (0 + 0 < p->cost[yyelse_NT]) {
			p->cost[yyelse_NT] = 0 + 0;
			p->rule.yyelse = 1;
		}
		break;
	case 294: /* EQ */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expr: EQ(expr,assign) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyassign_NT] + 1;
		yytrace(a, 109, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 24;
			yyclosure_expr(a, c + 0);
		}
		break;
	case 295: /* NE */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expr: NE(expr,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 98, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 15;
			yyclosure_expr(a, c + 0);
		}
		break;
	case 296: /* GE */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expr: GE(expr,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 99, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 16;
			yyclosure_expr(a, c + 0);
		}
		break;
	case 297: /* LE */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expr: LE(expr,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 100, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 17;
			yyclosure_expr(a, c + 0);
		}
		break;
	case 298: /* UMINUS */
		yylabel(LEFT_CHILD(a),a);
		/* expr: UMINUS(expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 108, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 23;
			yyclosure_expr(a, c + 0);
		}
		break;
	default:
		PANIC("yylabel", "Bad terminal", OP_LABEL(a));
	}
}

static void yykids(NODEPTR_TYPE p, int eruleno, NODEPTR_TYPE kids[]) {
	if (!p)
		PANIC("yykids", "Null tree in rule", eruleno);
	if (!kids)
		PANIC("yykids", "Null kids in", OP_LABEL(p));
	switch (eruleno) {
	case 1: /* program: PROGRAM(decls,FUNCTION(funcmain,FARGS(NIL,main))) */
		kids[0] = LEFT_CHILD(p);
		kids[1] = LEFT_CHILD(RIGHT_CHILD(p));
		kids[2] = RIGHT_CHILD(RIGHT_CHILD(RIGHT_CHILD(p)));
		break;
	case 111: /* exprs: COMMA(expr,NIL) */
	case 108: /* expr: UMINUS(expr) */
	case 107: /* expr: NOT(expr) */
	case 90: /* expr: ADDR(lval) */
	case 83: /* assign: INDEX(expr,ID) */
	case 81: /* lval: INDEX(expr,ID) */
	case 65: /* instr: PRINT(expr) */
	case 54: /* ret: RETURN(expr) */
	case 44: /* ints: INTS(ints,INT) */
	case 7: /* decl: VAR(vardecl) */
	case 2: /* program: MODULE(decls) */
		kids[0] = LEFT_CHILD(p);
		break;
	case 89: /* expr: READ */
	case 86: /* expr: CHARS(NIL,STR) */
	case 85: /* expr: CHARS(NIL,CHAR) */
	case 84: /* expr: CHARS(NIL,INT) */
	case 82: /* assign: ID */
	case 80: /* lval: ID */
	case 78: /* else: NIL */
	case 76: /* elifs: NIL */
	case 61: /* instrs: NIL */
	case 58: /* loop: STOP */
	case 57: /* loop: REPEAT */
	case 55: /* ret: NIL */
	case 53: /* ret: RETURN(NIL) */
	case 51: /* bodyfvars: NIL */
	case 48: /* mainfvars: NIL */
	case 45: /* eqbody: NIL */
	case 43: /* ints: INT */
	case 41: /* eqvec: NIL */
	case 40: /* char: STR */
	case 39: /* char: CHAR */
	case 38: /* char: INT */
	case 35: /* eqchar: STR */
	case 34: /* eqchar: CHAR */
	case 33: /* eqchar: INT */
	case 29: /* eqstr: NIL */
	case 28: /* eqint: INT */
	case 27: /* eqint: NIL */
	case 26: /* vdim: INT */
	case 25: /* vdim: NIL */
	case 18: /* fvar: STRING(ID,NIL) */
	case 17: /* fvar: NUMBER(ID,NIL) */
	case 16: /* funcmain: END(ID,INT) */
	case 15: /* funcname: END(ID,INT) */
	case 12: /* fargs: NIL */
	case 10: /* farg: STRING(ID,NIL) */
	case 9: /* farg: NUMBER(ID,NIL) */
	case 3: /* decls: NIL */
		break;
	case 106: /* or: expr */
	case 104: /* and: expr */
	case 88: /* expr: lval */
	case 87: /* expr: chars */
	case 79: /* else: block */
	case 75: /* test: expr */
	case 74: /* cond: expr */
	case 73: /* postexpr: test */
	case 72: /* forcond: expr */
	case 71: /* init: test */
	case 68: /* alloc: expr */
	case 66: /* instr: expr */
	case 56: /* loop: ret */
	case 52: /* bodyfvars: fvars */
	case 49: /* mainfvars: fvars */
	case 46: /* eqbody: body */
	case 42: /* eqvec: ints */
	case 30: /* eqstr: eqchars */
	case 4: /* decls: gdecls */
		kids[0] = p;
		break;
	case 112: /* exprs: COMMA(expr,exprs) */
	case 109: /* expr: EQ(expr,assign) */
	case 105: /* expr: OR(or,expr) */
	case 103: /* expr: AND(and,expr) */
	case 102: /* expr: GT(expr,expr) */
	case 101: /* expr: LT(expr,expr) */
	case 100: /* expr: LE(expr,expr) */
	case 99: /* expr: GE(expr,expr) */
	case 98: /* expr: NE(expr,expr) */
	case 97: /* expr: EQU(expr,expr) */
	case 96: /* expr: POW(expr,expr) */
	case 95: /* expr: MOD(expr,expr) */
	case 94: /* expr: DIV(expr,expr) */
	case 93: /* expr: MUL(expr,expr) */
	case 92: /* expr: SUB(expr,expr) */
	case 91: /* expr: ADD(expr,expr) */
	case 77: /* elifs: ELIF(elifs,ifelse) */
	case 70: /* ifelse: IF(cond,block) */
	case 69: /* if: IF(cond,block) */
	case 67: /* instr: ALLOC(alloc,lval) */
	case 62: /* instrs: STMT(instrs,instr) */
	case 60: /* forblock: STMT(instrs,loop) */
	case 59: /* block: STMT(instrs,loop) */
	case 47: /* main: START(mainfvars,instrs) */
	case 37: /* chars: CHARS(chars,char) */
	case 32: /* eqchars: CHARS(eqchars,eqchar) */
	case 21: /* fvars: ARGS(fvars,fvar) */
	case 14: /* fargs: ARGS(fargs,farg) */
	case 5: /* gdecls: DECL(gdecls,decl) */
		kids[0] = LEFT_CHILD(p);
		kids[1] = RIGHT_CHILD(p);
		break;
	case 110: /* expr: IDARGS(ID,exprs) */
	case 36: /* chars: CHARS(NIL,char) */
	case 31: /* eqchars: CHARS(NIL,eqchar) */
	case 23: /* vardecl: STRING(ID,eqstr) */
	case 22: /* vardecl: NUMBER(ID,eqint) */
	case 20: /* fvars: ARGS(NIL,fvar) */
	case 13: /* fargs: ARGS(NIL,farg) */
	case 6: /* gdecls: DECL(NIL,decl) */
		kids[0] = RIGHT_CHILD(p);
		break;
	case 50: /* body: START(bodyfvars,STMT(instrs,ret)) */
	case 8: /* decl: FUNCTION(funcname,FARGS(fargs,eqbody)) */
		kids[0] = LEFT_CHILD(p);
		kids[1] = LEFT_CHILD(RIGHT_CHILD(p));
		kids[2] = RIGHT_CHILD(RIGHT_CHILD(p));
		break;
	case 19: /* fvar: ARRAY(ID,INTS(vdim,NIL)) */
	case 11: /* farg: ARRAY(ID,INTS(vdim,NIL)) */
		kids[0] = LEFT_CHILD(RIGHT_CHILD(p));
		break;
	case 24: /* vardecl: ARRAY(ID,INTS(vdim,eqvec)) */
		kids[0] = LEFT_CHILD(RIGHT_CHILD(p));
		kids[1] = RIGHT_CHILD(RIGHT_CHILD(p));
		break;
	case 63: /* instr: FI(THEN(if,elifs),else) */
		kids[0] = LEFT_CHILD(LEFT_CHILD(p));
		kids[1] = RIGHT_CHILD(LEFT_CHILD(p));
		kids[2] = RIGHT_CHILD(p);
		break;
	case 64: /* instr: FOR(UNTIL(init,forcond),STEP(forblock,postexpr)) */
		kids[0] = LEFT_CHILD(LEFT_CHILD(p));
		kids[1] = RIGHT_CHILD(LEFT_CHILD(p));
		kids[2] = LEFT_CHILD(RIGHT_CHILD(p));
		kids[3] = RIGHT_CHILD(RIGHT_CHILD(p));
		break;
	default:
		PANIC("yykids", "Bad rule number", eruleno);
	}
}

static void yyreduce(NODEPTR_TYPE p, int goalnt)
{
  int eruleno = yyrule(STATE_LABEL(p), goalnt);
  short *nts = yynts[eruleno];
  NODEPTR_TYPE kids[4];
  int i;

  for (yykids(p, eruleno, kids), i = 0; nts[i]; i++)
    yyreduce(kids[i], nts[i]);

  switch(eruleno) {
	case 1: /* program: PROGRAM(decls,FUNCTION(funcmain,FARGS(NIL,main))) */
		fprintf(stderr, "0x%lx: line 132: program: PROGRAM(decls,FUNCTION(funcmain,FARGS(NIL,main)))\n",(long)p);
#line 132 "minor.brg"
{ final(); }
		break;
	case 2: /* program: MODULE(decls) */
		fprintf(stderr, "0x%lx: line 133: program: MODULE(decls)\n",(long)p);
#line 133 "minor.brg"
{}
		break;
	case 3: /* decls: NIL */
		fprintf(stderr, "0x%lx: line 135: decls: NIL\n",(long)p);
#line 135 "minor.brg"
{}
		break;
	case 4: /* decls: gdecls */
		fprintf(stderr, "0x%lx: line 136: decls: gdecls\n",(long)p);
#line 136 "minor.brg"
{}
		break;
	case 5: /* gdecls: DECL(gdecls,decl) */
		fprintf(stderr, "0x%lx: line 138: gdecls: DECL(gdecls,decl)\n",(long)p);
#line 138 "minor.brg"
{}
		break;
	case 6: /* gdecls: DECL(NIL,decl) */
		fprintf(stderr, "0x%lx: line 139: gdecls: DECL(NIL,decl)\n",(long)p);
#line 139 "minor.brg"
{}
		break;
	case 7: /* decl: VAR(vardecl) */
		fprintf(stderr, "0x%lx: line 141: decl: VAR(vardecl)\n",(long)p);
#line 141 "minor.brg"
{ variable(p); }
		break;
	case 8: /* decl: FUNCTION(funcname,FARGS(fargs,eqbody)) */
		fprintf(stderr, "0x%lx: line 142: decl: FUNCTION(funcname,FARGS(fargs,eqbody))\n",(long)p);
#line 142 "minor.brg"
{ fprintf(yyout, pfLEAVE pfRET); }
		break;
	case 9: /* farg: NUMBER(ID,NIL) */
		fprintf(stderr, "0x%lx: line 144: farg: NUMBER(ID,NIL)\n",(long)p);
#line 144 "minor.brg"
{ IDnew(RIGHT_CHILD(p)->info, LEFT_CHILD(p)->value.s, pos); pos += 4; }
		break;
	case 10: /* farg: STRING(ID,NIL) */
		fprintf(stderr, "0x%lx: line 145: farg: STRING(ID,NIL)\n",(long)p);
#line 145 "minor.brg"
{}
		break;
	case 11: /* farg: ARRAY(ID,INTS(vdim,NIL)) */
		fprintf(stderr, "0x%lx: line 146: farg: ARRAY(ID,INTS(vdim,NIL))\n",(long)p);
#line 146 "minor.brg"
{}
		break;
	case 12: /* fargs: NIL */
		fprintf(stderr, "0x%lx: line 148: fargs: NIL\n",(long)p);
#line 148 "minor.brg"
{ pos = 0; }
		break;
	case 13: /* fargs: ARGS(NIL,farg) */
		fprintf(stderr, "0x%lx: line 149: fargs: ARGS(NIL,farg)\n",(long)p);
#line 149 "minor.brg"
{ pos = 0; }
		break;
	case 14: /* fargs: ARGS(fargs,farg) */
		fprintf(stderr, "0x%lx: line 150: fargs: ARGS(fargs,farg)\n",(long)p);
#line 150 "minor.brg"
{}
		break;
	case 15: /* funcname: END(ID,INT) */
		fprintf(stderr, "0x%lx: line 152: funcname: END(ID,INT)\n",(long)p);
#line 152 "minor.brg"
{ IDpush(); pos = 8; currentfunc = LEFT_CHILD(p)->value.s; }
		break;
	case 16: /* funcmain: END(ID,INT) */
		fprintf(stderr, "0x%lx: line 153: funcmain: END(ID,INT)\n",(long)p);
#line 153 "minor.brg"
{ IDpush(); pos = 0; }
		break;
	case 17: /* fvar: NUMBER(ID,NIL) */
		fprintf(stderr, "0x%lx: line 155: fvar: NUMBER(ID,NIL)\n",(long)p);
#line 155 "minor.brg"
{ IDnew(RIGHT_CHILD(p)->info, LEFT_CHILD(p)->value.s, pos -= 4); }
		break;
	case 18: /* fvar: STRING(ID,NIL) */
		fprintf(stderr, "0x%lx: line 156: fvar: STRING(ID,NIL)\n",(long)p);
#line 156 "minor.brg"
{}
		break;
	case 19: /* fvar: ARRAY(ID,INTS(vdim,NIL)) */
		fprintf(stderr, "0x%lx: line 157: fvar: ARRAY(ID,INTS(vdim,NIL))\n",(long)p);
#line 157 "minor.brg"
{}
		break;
	case 20: /* fvars: ARGS(NIL,fvar) */
		fprintf(stderr, "0x%lx: line 159: fvars: ARGS(NIL,fvar)\n",(long)p);
#line 159 "minor.brg"
{}
		break;
	case 21: /* fvars: ARGS(fvars,fvar) */
		fprintf(stderr, "0x%lx: line 160: fvars: ARGS(fvars,fvar)\n",(long)p);
#line 160 "minor.brg"
{}
		break;
	case 22: /* vardecl: NUMBER(ID,eqint) */
		fprintf(stderr, "0x%lx: line 162: vardecl: NUMBER(ID,eqint)\n",(long)p);
#line 162 "minor.brg"
{}
		break;
	case 23: /* vardecl: STRING(ID,eqstr) */
		fprintf(stderr, "0x%lx: line 163: vardecl: STRING(ID,eqstr)\n",(long)p);
#line 163 "minor.brg"
{}
		break;
	case 24: /* vardecl: ARRAY(ID,INTS(vdim,eqvec)) */
		fprintf(stderr, "0x%lx: line 164: vardecl: ARRAY(ID,INTS(vdim,eqvec))\n",(long)p);
#line 164 "minor.brg"
{}
		break;
	case 25: /* vdim: NIL */
		fprintf(stderr, "0x%lx: line 166: vdim: NIL\n",(long)p);
#line 166 "minor.brg"
{}
		break;
	case 26: /* vdim: INT */
		fprintf(stderr, "0x%lx: line 167: vdim: INT\n",(long)p);
#line 167 "minor.brg"
{}
		break;
	case 27: /* eqint: NIL */
		fprintf(stderr, "0x%lx: line 169: eqint: NIL\n",(long)p);
#line 169 "minor.brg"
{}
		break;
	case 28: /* eqint: INT */
		fprintf(stderr, "0x%lx: line 170: eqint: INT\n",(long)p);
#line 170 "minor.brg"
{}
		break;
	case 29: /* eqstr: NIL */
		fprintf(stderr, "0x%lx: line 172: eqstr: NIL\n",(long)p);
#line 172 "minor.brg"
{}
		break;
	case 30: /* eqstr: eqchars */
		fprintf(stderr, "0x%lx: line 173: eqstr: eqchars\n",(long)p);
#line 173 "minor.brg"
{}
		break;
	case 31: /* eqchars: CHARS(NIL,eqchar) */
		fprintf(stderr, "0x%lx: line 175: eqchars: CHARS(NIL,eqchar)\n",(long)p);
#line 175 "minor.brg"
{}
		break;
	case 32: /* eqchars: CHARS(eqchars,eqchar) */
		fprintf(stderr, "0x%lx: line 176: eqchars: CHARS(eqchars,eqchar)\n",(long)p);
#line 176 "minor.brg"
{}
		break;
	case 33: /* eqchar: INT */
		fprintf(stderr, "0x%lx: line 178: eqchar: INT\n",(long)p);
#line 178 "minor.brg"
{}
		break;
	case 34: /* eqchar: CHAR */
		fprintf(stderr, "0x%lx: line 179: eqchar: CHAR\n",(long)p);
#line 179 "minor.brg"
{}
		break;
	case 35: /* eqchar: STR */
		fprintf(stderr, "0x%lx: line 180: eqchar: STR\n",(long)p);
#line 180 "minor.brg"
{}
		break;
	case 36: /* chars: CHARS(NIL,char) */
		fprintf(stderr, "0x%lx: line 182: chars: CHARS(NIL,char)\n",(long)p);
#line 182 "minor.brg"
{}
		break;
	case 37: /* chars: CHARS(chars,char) */
		fprintf(stderr, "0x%lx: line 183: chars: CHARS(chars,char)\n",(long)p);
#line 183 "minor.brg"
{}
		break;
	case 38: /* char: INT */
		fprintf(stderr, "0x%lx: line 185: char: INT\n",(long)p);
#line 185 "minor.brg"

		break;
	case 39: /* char: CHAR */
		fprintf(stderr, "0x%lx: line 186: char: CHAR\n",(long)p);
#line 186 "minor.brg"

		break;
	case 40: /* char: STR */
		fprintf(stderr, "0x%lx: line 187: char: STR\n",(long)p);
#line 187 "minor.brg"

		break;
	case 41: /* eqvec: NIL */
		fprintf(stderr, "0x%lx: line 189: eqvec: NIL\n",(long)p);
#line 189 "minor.brg"
{}
		break;
	case 42: /* eqvec: ints */
		fprintf(stderr, "0x%lx: line 190: eqvec: ints\n",(long)p);
#line 190 "minor.brg"
{}
		break;
	case 43: /* ints: INT */
		fprintf(stderr, "0x%lx: line 192: ints: INT\n",(long)p);
#line 192 "minor.brg"
{}
		break;
	case 44: /* ints: INTS(ints,INT) */
		fprintf(stderr, "0x%lx: line 193: ints: INTS(ints,INT)\n",(long)p);
#line 193 "minor.brg"
{}
		break;
	case 45: /* eqbody: NIL */
		fprintf(stderr, "0x%lx: line 195: eqbody: NIL\n",(long)p);
#line 195 "minor.brg"
{}
		break;
	case 46: /* eqbody: body */
		fprintf(stderr, "0x%lx: line 196: eqbody: body\n",(long)p);
#line 196 "minor.brg"
{}
		break;
	case 47: /* main: START(mainfvars,instrs) */
		fprintf(stderr, "0x%lx: line 198: main: START(mainfvars,instrs)\n",(long)p);
#line 198 "minor.brg"
{ IDpop(); }
		break;
	case 48: /* mainfvars: NIL */
		fprintf(stderr, "0x%lx: line 200: mainfvars: NIL\n",(long)p);
#line 200 "minor.brg"
{ function("main", 0); }
		break;
	case 49: /* mainfvars: fvars */
		fprintf(stderr, "0x%lx: line 201: mainfvars: fvars\n",(long)p);
#line 201 "minor.brg"
{ function("main", -pos); }
		break;
	case 50: /* body: START(bodyfvars,STMT(instrs,ret)) */
		fprintf(stderr, "0x%lx: line 203: body: START(bodyfvars,STMT(instrs,ret))\n",(long)p);
#line 203 "minor.brg"
{}
		break;
	case 51: /* bodyfvars: NIL */
		fprintf(stderr, "0x%lx: line 205: bodyfvars: NIL\n",(long)p);
#line 205 "minor.brg"
{ function(currentfunc, 0); }
		break;
	case 52: /* bodyfvars: fvars */
		fprintf(stderr, "0x%lx: line 206: bodyfvars: fvars\n",(long)p);
#line 206 "minor.brg"
{ function(currentfunc, -pos); }
		break;
	case 53: /* ret: RETURN(NIL) */
		fprintf(stderr, "0x%lx: line 208: ret: RETURN(NIL)\n",(long)p);
#line 208 "minor.brg"
{ fprintf(yyout, pfLEAVE pfRET); }
		break;
	case 54: /* ret: RETURN(expr) */
		fprintf(stderr, "0x%lx: line 209: ret: RETURN(expr)\n",(long)p);
#line 209 "minor.brg"
{ fprintf(yyout, pfPOP pfLEAVE pfRET); }
		break;
	case 55: /* ret: NIL */
		fprintf(stderr, "0x%lx: line 210: ret: NIL\n",(long)p);
#line 210 "minor.brg"
{}
		break;
	case 56: /* loop: ret */
		fprintf(stderr, "0x%lx: line 212: loop: ret\n",(long)p);
#line 212 "minor.brg"
{}
		break;
	case 57: /* loop: REPEAT */
		fprintf(stderr, "0x%lx: line 213: loop: REPEAT\n",(long)p);
#line 213 "minor.brg"
{ p->place = repeatlbl[forcnt]; fprintf(yyout, pfJMP, mklbl(p->place)); }
		break;
	case 58: /* loop: STOP */
		fprintf(stderr, "0x%lx: line 214: loop: STOP\n",(long)p);
#line 214 "minor.brg"
{ p->place = stoplbl[forcnt]; fprintf(yyout, pfJMP, mklbl(p->place)); }
		break;
	case 59: /* block: STMT(instrs,loop) */
		fprintf(stderr, "0x%lx: line 216: block: STMT(instrs,loop)\n",(long)p);
#line 216 "minor.brg"
{}
		break;
	case 60: /* forblock: STMT(instrs,loop) */
		fprintf(stderr, "0x%lx: line 217: forblock: STMT(instrs,loop)\n",(long)p);
#line 217 "minor.brg"
{ p->place = repeatlbl[forcnt]; fprintf(yyout, pfLABEL, mklbl(p->place)); }
		break;
	case 61: /* instrs: NIL */
		fprintf(stderr, "0x%lx: line 219: instrs: NIL\n",(long)p);
#line 219 "minor.brg"
{}
		break;
	case 62: /* instrs: STMT(instrs,instr) */
		fprintf(stderr, "0x%lx: line 220: instrs: STMT(instrs,instr)\n",(long)p);
#line 220 "minor.brg"
{}
		break;
	case 63: /* instr: FI(THEN(if,elifs),else) */
		fprintf(stderr, "0x%lx: line 222: instr: FI(THEN(if,elifs),else)\n",(long)p);
#line 222 "minor.brg"
{ fprintf(yyout, pfLABEL, mklbl(LEFT_CHILD(LEFT_CHILD(p))->place)); }
		break;
	case 64: /* instr: FOR(UNTIL(init,forcond),STEP(forblock,postexpr)) */
		fprintf(stderr, "0x%lx: line 223: instr: FOR(UNTIL(init,forcond),STEP(forblock,postexpr))\n",(long)p);
#line 223 "minor.brg"
{ fprintf(yyout, pfLABEL, mklbl(RIGHT_CHILD(LEFT_CHILD(p))->place)); }
		break;
	case 65: /* instr: PRINT(expr) */
		fprintf(stderr, "0x%lx: line 224: instr: PRINT(expr)\n",(long)p);
#line 224 "minor.brg"
{ pfPrint(p->info); }
		break;
	case 66: /* instr: expr */
		fprintf(stderr, "0x%lx: line 225: instr: expr\n",(long)p);
#line 225 "minor.brg"
{ /* TODO */ fprintf(yyout, pfTRASH, pfWORD); }
		break;
	case 67: /* instr: ALLOC(alloc,lval) */
		fprintf(stderr, "0x%lx: line 226: instr: ALLOC(alloc,lval)\n",(long)p);
#line 226 "minor.brg"
{ fprintf(yyout, pfSTORE); }
		break;
	case 68: /* alloc: expr */
		fprintf(stderr, "0x%lx: line 227: alloc: expr\n",(long)p);
#line 227 "minor.brg"
{ fprintf(yyout, pfIMM pfMUL pfALLOC pfSP, pfWORD); }
		break;
	case 69: /* if: IF(cond,block) */
		fprintf(stderr, "0x%lx: line 229: if: IF(cond,block)\n",(long)p);
#line 229 "minor.brg"
{ p->place = ++lbl; eliflbl = p->place; fprintf(yyout, pfJMP pfLABEL, mklbl(p->place), mklbl(LEFT_CHILD(p)->place)); }
		break;
	case 70: /* ifelse: IF(cond,block) */
		fprintf(stderr, "0x%lx: line 230: ifelse: IF(cond,block)\n",(long)p);
#line 230 "minor.brg"

		break;
	case 71: /* init: test */
		fprintf(stderr, "0x%lx: line 232: init: test\n",(long)p);
#line 232 "minor.brg"
{ p->place = forlbl[++forcnt] = ++lbl; repeatlbl[forcnt] = ++lbl; fprintf(yyout, pfLABEL, mklbl(p->place)); }
		break;
	case 72: /* forcond: expr */
		fprintf(stderr, "0x%lx: line 233: forcond: expr\n",(long)p);
#line 233 "minor.brg"
{ p->place = stoplbl[forcnt] = ++lbl; fprintf(yyout, pfJNZ, mklbl(p->place)); }
		break;
	case 73: /* postexpr: test */
		fprintf(stderr, "0x%lx: line 234: postexpr: test\n",(long)p);
#line 234 "minor.brg"
{ p->place = forlbl[forcnt--]; fprintf(yyout, pfJMP, mklbl(p->place)); }
		break;
	case 74: /* cond: expr */
		fprintf(stderr, "0x%lx: line 235: cond: expr\n",(long)p);
#line 235 "minor.brg"
{ p->place = ++lbl; fprintf(yyout, pfJZ, mklbl(p->place)); }
		break;
	case 75: /* test: expr */
		fprintf(stderr, "0x%lx: line 237: test: expr\n",(long)p);
#line 237 "minor.brg"
{ /* TODO */ fprintf(yyout, pfTRASH, pfWORD); }
		break;
	case 76: /* elifs: NIL */
		fprintf(stderr, "0x%lx: line 239: elifs: NIL\n",(long)p);
#line 239 "minor.brg"

		break;
	case 77: /* elifs: ELIF(elifs,ifelse) */
		fprintf(stderr, "0x%lx: line 240: elifs: ELIF(elifs,ifelse)\n",(long)p);
#line 240 "minor.brg"
{ p->place = eliflbl; fprintf(yyout, pfJMP pfLABEL, mklbl(p->place), mklbl(LEFT_CHILD(RIGHT_CHILD(p))->place)); }
		break;
	case 78: /* else: NIL */
		fprintf(stderr, "0x%lx: line 242: else: NIL\n",(long)p);
#line 242 "minor.brg"

		break;
	case 79: /* else: block */
		fprintf(stderr, "0x%lx: line 243: else: block\n",(long)p);
#line 243 "minor.brg"

		break;
	case 80: /* lval: ID */
		fprintf(stderr, "0x%lx: line 245: lval: ID\n",(long)p);
#line 245 "minor.brg"
{ getId(p); }
		break;
	case 81: /* lval: INDEX(expr,ID) */
		fprintf(stderr, "0x%lx: line 246: lval: INDEX(expr,ID)\n",(long)p);
#line 246 "minor.brg"
{}
		break;
	case 82: /* assign: ID */
		fprintf(stderr, "0x%lx: line 247: assign: ID\n",(long)p);
#line 247 "minor.brg"

		break;
	case 83: /* assign: INDEX(expr,ID) */
		fprintf(stderr, "0x%lx: line 248: assign: INDEX(expr,ID)\n",(long)p);
#line 248 "minor.brg"

		break;
	case 84: /* expr: CHARS(NIL,INT) */
		fprintf(stderr, "0x%lx: line 250: expr: CHARS(NIL,INT)\n",(long)p);
#line 250 "minor.brg"
{ fprintf(yyout, pfIMM, RIGHT_CHILD(p)->value.i); }
		break;
	case 85: /* expr: CHARS(NIL,CHAR) */
		fprintf(stderr, "0x%lx: line 251: expr: CHARS(NIL,CHAR)\n",(long)p);
#line 251 "minor.brg"
{ fprintf(yyout, pfIMM, RIGHT_CHILD(p)->value.i); }
		break;
	case 86: /* expr: CHARS(NIL,STR) */
		fprintf(stderr, "0x%lx: line 252: expr: CHARS(NIL,STR)\n",(long)p);
#line 252 "minor.brg"
{ lbl++; fprintf(yyout, pfRODATA pfALIGN pfLABEL, mklbl(lbl)); outstr(RIGHT_CHILD(p)->value.s); fprintf(yyout, pfTEXT pfADDR, mklbl(lbl)); }
		break;
	case 87: /* expr: chars */
		fprintf(stderr, "0x%lx: line 253: expr: chars\n",(long)p);
#line 253 "minor.brg"
{ lbl++; fprintf(yyout, pfRODATA pfALIGN pfLABEL, mklbl(lbl)); outchars(p); fprintf(yyout, pfTEXT pfADDR, mklbl(lbl)); }
		break;
	case 88: /* expr: lval */
		fprintf(stderr, "0x%lx: line 254: expr: lval\n",(long)p);
#line 254 "minor.brg"

		break;
	case 89: /* expr: READ */
		fprintf(stderr, "0x%lx: line 255: expr: READ\n",(long)p);
#line 255 "minor.brg"
{ fprintf(yyout, pfCALL pfPUSH, "_readi"); }
		break;
	case 90: /* expr: ADDR(lval) */
		fprintf(stderr, "0x%lx: line 256: expr: ADDR(lval)\n",(long)p);
#line 256 "minor.brg"
{}
		break;
	case 91: /* expr: ADD(expr,expr) */
		fprintf(stderr, "0x%lx: line 257: expr: ADD(expr,expr)\n",(long)p);
#line 257 "minor.brg"
{ fprintf(yyout, pfADD); }
		break;
	case 92: /* expr: SUB(expr,expr) */
		fprintf(stderr, "0x%lx: line 258: expr: SUB(expr,expr)\n",(long)p);
#line 258 "minor.brg"
{ fprintf(yyout, pfSUB); }
		break;
	case 93: /* expr: MUL(expr,expr) */
		fprintf(stderr, "0x%lx: line 259: expr: MUL(expr,expr)\n",(long)p);
#line 259 "minor.brg"
{ fprintf(yyout, pfMUL); }
		break;
	case 94: /* expr: DIV(expr,expr) */
		fprintf(stderr, "0x%lx: line 260: expr: DIV(expr,expr)\n",(long)p);
#line 260 "minor.brg"
{ fprintf(yyout, pfDIV); }
		break;
	case 95: /* expr: MOD(expr,expr) */
		fprintf(stderr, "0x%lx: line 261: expr: MOD(expr,expr)\n",(long)p);
#line 261 "minor.brg"
{ fprintf(yyout, pfMOD); }
		break;
	case 96: /* expr: POW(expr,expr) */
		fprintf(stderr, "0x%lx: line 262: expr: POW(expr,expr)\n",(long)p);
#line 262 "minor.brg"
{}
		break;
	case 97: /* expr: EQU(expr,expr) */
		fprintf(stderr, "0x%lx: line 263: expr: EQU(expr,expr)\n",(long)p);
#line 263 "minor.brg"
{ fprintf(yyout, pfEQ); }
		break;
	case 98: /* expr: NE(expr,expr) */
		fprintf(stderr, "0x%lx: line 264: expr: NE(expr,expr)\n",(long)p);
#line 264 "minor.brg"
{ fprintf(yyout, pfNE); }
		break;
	case 99: /* expr: GE(expr,expr) */
		fprintf(stderr, "0x%lx: line 265: expr: GE(expr,expr)\n",(long)p);
#line 265 "minor.brg"
{ fprintf(yyout, pfGE); }
		break;
	case 100: /* expr: LE(expr,expr) */
		fprintf(stderr, "0x%lx: line 266: expr: LE(expr,expr)\n",(long)p);
#line 266 "minor.brg"
{ fprintf(yyout, pfLE); }
		break;
	case 101: /* expr: LT(expr,expr) */
		fprintf(stderr, "0x%lx: line 267: expr: LT(expr,expr)\n",(long)p);
#line 267 "minor.brg"
{ fprintf(yyout, pfLT); }
		break;
	case 102: /* expr: GT(expr,expr) */
		fprintf(stderr, "0x%lx: line 268: expr: GT(expr,expr)\n",(long)p);
#line 268 "minor.brg"
{ fprintf(yyout, pfGT); }
		break;
	case 103: /* expr: AND(and,expr) */
		fprintf(stderr, "0x%lx: line 269: expr: AND(and,expr)\n",(long)p);
#line 269 "minor.brg"
{ fprintf(yyout, pfLABEL, mklbl(LEFT_CHILD(p)->place)); }
		break;
	case 104: /* and: expr */
		fprintf(stderr, "0x%lx: line 270: and: expr\n",(long)p);
#line 270 "minor.brg"
{ p->place = ++lbl; fprintf(yyout, pfDUP pfJZ pfTRASH, mklbl(p->place), pfWORD); }
		break;
	case 105: /* expr: OR(or,expr) */
		fprintf(stderr, "0x%lx: line 271: expr: OR(or,expr)\n",(long)p);
#line 271 "minor.brg"
{ fprintf(yyout, pfLABEL, mklbl(LEFT_CHILD(p)->place)); }
		break;
	case 106: /* or: expr */
		fprintf(stderr, "0x%lx: line 272: or: expr\n",(long)p);
#line 272 "minor.brg"
{ p->place = ++lbl; fprintf(yyout, pfDUP pfJNZ pfTRASH, mklbl(p->place), pfWORD); }
		break;
	case 107: /* expr: NOT(expr) */
		fprintf(stderr, "0x%lx: line 273: expr: NOT(expr)\n",(long)p);
#line 273 "minor.brg"
{ fprintf(yyout, pfIMM pfEQ, 0); }
		break;
	case 108: /* expr: UMINUS(expr) */
		fprintf(stderr, "0x%lx: line 274: expr: UMINUS(expr)\n",(long)p);
#line 274 "minor.brg"
{ fprintf(yyout, pfNEG); }
		break;
	case 109: /* expr: EQ(expr,assign) */
		fprintf(stderr, "0x%lx: line 275: expr: EQ(expr,assign)\n",(long)p);
#line 275 "minor.brg"
{ assignment(RIGHT_CHILD(p)); }
		break;
	case 110: /* expr: IDARGS(ID,exprs) */
		fprintf(stderr, "0x%lx: line 276: expr: IDARGS(ID,exprs)\n",(long)p);
#line 276 "minor.brg"
{ fprintf(yyout, pfCALL pfTRASH pfPUSH, mkfunc(LEFT_CHILD(p)->value.s), (int)(pfWORD*(RIGHT_CHILD(p)->place))); }
		break;
	case 111: /* exprs: COMMA(expr,NIL) */
		fprintf(stderr, "0x%lx: line 278: exprs: COMMA(expr,NIL)\n",(long)p);
#line 278 "minor.brg"
{ p->place = 1; }
		break;
	case 112: /* exprs: COMMA(expr,exprs) */
		fprintf(stderr, "0x%lx: line 279: exprs: COMMA(expr,exprs)\n",(long)p);
#line 279 "minor.brg"
{ p->place = ((LEFT_CHILD(p)->place) + (RIGHT_CHILD(p)->place)); }
		break;
	default: break;
  }
}

int yyselect(NODEPTR_TYPE p)
{
	yylabel(p,p);
	if (((struct yystate *)STATE_LABEL(p))->rule.yyprogram == 0) {
		fprintf(stderr, "No match for start symbol (%s).\n", yyntname[1]);
		return 1;
	}
	yyreduce(p, 1);
	return 0;
}


#line 281 "minor.brg"

extern char **yynames;
extern int trace, errors, debugNode;
void evaluate(Node *p) {
	if (errors) return;
	/* if (trace) */ printNode(p, stdout, yynames);
	if (!yyselect(p) && trace) printf("selection successful\n");
}

#ifndef NOTRACE
static void yytrace(NODEPTR_TYPE p, int eruleno, int cost, int bestcost)
{
	int op = OP_LABEL(p);
	YYCONST char *tname = yytermname[op] ? yytermname[op] : "?";
	if (debugNode) fprintf(stderr, "0x%p:%s matched %s with cost %d vs. %d\n", p, tname, yystring[eruleno], cost, bestcost);
	if (cost >= MAX_COST && bestcost >= MAX_COST) {
		fprintf(stderr, "0x%p:%s NO MATCH %s with cost %d vs. %d\n", p, tname, yystring[eruleno], cost, bestcost);
		printNode(p, stderr, yynames);
	}
}
#endif
