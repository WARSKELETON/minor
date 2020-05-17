/*
generated at Sun May 17 23:49:54 2020
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

#ifndef U_
#define U_ "_"
#endif

#define TRACE
static void yytrace(NODEPTR_TYPE p, int eruleno, int cost, int bestcost);

extern FILE *yyout;
int lbl;
int eliflbl;
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
	if (info == tINT) {
  		fprintf(yyout, pfCALL pfCALL pfTRASH, "_printi", "_println", 4);
	}
	if (info == tSTR) {
  		fprintf(yyout, pfCALL pfCALL pfTRASH, "_prints", "_println", 4);
	}
}
/* expr: falta '?', falta const type ftype */
/* expr: expr */
/* println ? */
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
#define yymain_NT 3
#define yygdecls_NT 4
#define yydecl_NT 5
#define yyvardecl_NT 6
#define yyfvars_NT 7
#define yyeqbody_NT 8
#define yyfvar_NT 9
#define yyvdim_NT 10
#define yyeqint_NT 11
#define yyeqstr_NT 12
#define yyeqvec_NT 13
#define yyeqchars_NT 14
#define yyeqchar_NT 15
#define yychars_NT 16
#define yychar_NT 17
#define yyints_NT 18
#define yybody_NT 19
#define yyinstrs_NT 20
#define yyret_NT 21
#define yyexpr_NT 22
#define yyloop_NT 23
#define yyblock_NT 24
#define yyinstr_NT 25
#define yyif_NT 26
#define yyelifs_NT 27
#define yyelse_NT 28
#define yyalloc_NT 29
#define yylval_NT 30
#define yycond_NT 31
#define yyifelse_NT 32
#define yyexprs_NT 33

static YYCONST char *yyntname[] = {
	0,
	"program",
	"decls",
	"main",
	"gdecls",
	"decl",
	"vardecl",
	"fvars",
	"eqbody",
	"fvar",
	"vdim",
	"eqint",
	"eqstr",
	"eqvec",
	"eqchars",
	"eqchar",
	"chars",
	"char",
	"ints",
	"body",
	"instrs",
	"ret",
	"expr",
	"loop",
	"block",
	"instr",
	"if",
	"elifs",
	"else",
	"alloc",
	"lval",
	"cond",
	"ifelse",
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
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "",
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
	short cost[34];
	struct {
		unsigned int yyprogram:2;
		unsigned int yydecls:2;
		unsigned int yymain:2;
		unsigned int yygdecls:2;
		unsigned int yydecl:2;
		unsigned int yyvardecl:2;
		unsigned int yyfvars:2;
		unsigned int yyeqbody:2;
		unsigned int yyfvar:2;
		unsigned int yyvdim:2;
		unsigned int yyeqint:2;
		unsigned int yyeqstr:2;
		unsigned int yyeqvec:2;
		unsigned int yyeqchars:2;
		unsigned int yyeqchar:2;
		unsigned int yychars:2;
		unsigned int yychar:2;
		unsigned int yyints:2;
		unsigned int yybody:2;
		unsigned int yyinstrs:2;
		unsigned int yyret:2;
		unsigned int yyexpr:5;
		unsigned int yyloop:2;
		unsigned int yyblock:1;
		unsigned int yyinstr:3;
		unsigned int yyif:1;
		unsigned int yyelifs:2;
		unsigned int yyelse:2;
		unsigned int yyalloc:1;
		unsigned int yylval:2;
		unsigned int yycond:1;
		unsigned int yyifelse:1;
		unsigned int yyexprs:2;
	} rule;
};

static short yynts_0[] = { yydecls_NT, yymain_NT, 0 };
static short yynts_1[] = { yydecls_NT, 0 };
static short yynts_2[] = { 0 };
static short yynts_3[] = { yygdecls_NT, 0 };
static short yynts_4[] = { yygdecls_NT, yydecl_NT, 0 };
static short yynts_5[] = { yydecl_NT, 0 };
static short yynts_6[] = { yyvardecl_NT, 0 };
static short yynts_7[] = { yyfvars_NT, yyeqbody_NT, 0 };
static short yynts_8[] = { yyeqbody_NT, 0 };
static short yynts_9[] = { yyvdim_NT, 0 };
static short yynts_10[] = { yyfvar_NT, 0 };
static short yynts_11[] = { yyfvars_NT, yyfvar_NT, 0 };
static short yynts_12[] = { yyeqint_NT, 0 };
static short yynts_13[] = { yyeqstr_NT, 0 };
static short yynts_14[] = { yyvdim_NT, yyeqvec_NT, 0 };
static short yynts_15[] = { yyeqchars_NT, 0 };
static short yynts_16[] = { yyeqchar_NT, 0 };
static short yynts_17[] = { yyeqchars_NT, yyeqchar_NT, 0 };
static short yynts_18[] = { yychar_NT, 0 };
static short yynts_19[] = { yychars_NT, yychar_NT, 0 };
static short yynts_20[] = { yyints_NT, 0 };
static short yynts_21[] = { yybody_NT, 0 };
static short yynts_22[] = { yyfvars_NT, yyinstrs_NT, 0 };
static short yynts_23[] = { yyinstrs_NT, 0 };
static short yynts_24[] = { yyfvars_NT, yyinstrs_NT, yyret_NT, 0 };
static short yynts_25[] = { yyinstrs_NT, yyret_NT, 0 };
static short yynts_26[] = { yyexpr_NT, 0 };
static short yynts_27[] = { yyret_NT, 0 };
static short yynts_28[] = { yyinstrs_NT, yyloop_NT, 0 };
static short yynts_29[] = { yyinstrs_NT, yyinstr_NT, 0 };
static short yynts_30[] = { yyif_NT, yyelifs_NT, yyelse_NT, 0 };
static short yynts_31[] = { yyexpr_NT, yyexpr_NT, yyblock_NT, yyexpr_NT, 0 };
static short yynts_32[] = { yyalloc_NT, yylval_NT, 0 };
static short yynts_33[] = { yycond_NT, yyblock_NT, 0 };
static short yynts_34[] = { yyelifs_NT, yyifelse_NT, 0 };
static short yynts_35[] = { yyblock_NT, 0 };
static short yynts_36[] = { yychars_NT, 0 };
static short yynts_37[] = { yylval_NT, 0 };
static short yynts_38[] = { yyexpr_NT, yyexpr_NT, 0 };
static short yynts_39[] = { yyexpr_NT, yylval_NT, 0 };
static short yynts_40[] = { yyexprs_NT, 0 };
static short yynts_41[] = { yyexpr_NT, yyexprs_NT, 0 };

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
	yynts_8,	/* 9 */
	yynts_2,	/* 10 */
	yynts_2,	/* 11 */
	yynts_9,	/* 12 */
	yynts_10,	/* 13 */
	yynts_11,	/* 14 */
	yynts_12,	/* 15 */
	yynts_13,	/* 16 */
	yynts_14,	/* 17 */
	yynts_2,	/* 18 */
	yynts_2,	/* 19 */
	yynts_2,	/* 20 */
	yynts_2,	/* 21 */
	yynts_2,	/* 22 */
	yynts_15,	/* 23 */
	yynts_16,	/* 24 */
	yynts_17,	/* 25 */
	yynts_2,	/* 26 */
	yynts_2,	/* 27 */
	yynts_2,	/* 28 */
	yynts_18,	/* 29 */
	yynts_19,	/* 30 */
	yynts_2,	/* 31 */
	yynts_2,	/* 32 */
	yynts_2,	/* 33 */
	yynts_2,	/* 34 */
	yynts_20,	/* 35 */
	yynts_2,	/* 36 */
	yynts_20,	/* 37 */
	yynts_2,	/* 38 */
	yynts_21,	/* 39 */
	yynts_22,	/* 40 */
	yynts_23,	/* 41 */
	yynts_24,	/* 42 */
	yynts_25,	/* 43 */
	yynts_2,	/* 44 */
	yynts_26,	/* 45 */
	yynts_2,	/* 46 */
	yynts_27,	/* 47 */
	yynts_2,	/* 48 */
	yynts_2,	/* 49 */
	yynts_28,	/* 50 */
	yynts_2,	/* 51 */
	yynts_29,	/* 52 */
	yynts_30,	/* 53 */
	yynts_31,	/* 54 */
	yynts_26,	/* 55 */
	yynts_26,	/* 56 */
	yynts_32,	/* 57 */
	yynts_26,	/* 58 */
	yynts_33,	/* 59 */
	yynts_33,	/* 60 */
	yynts_26,	/* 61 */
	yynts_2,	/* 62 */
	yynts_34,	/* 63 */
	yynts_2,	/* 64 */
	yynts_35,	/* 65 */
	yynts_2,	/* 66 */
	yynts_26,	/* 67 */
	yynts_36,	/* 68 */
	yynts_37,	/* 69 */
	yynts_37,	/* 70 */
	yynts_38,	/* 71 */
	yynts_38,	/* 72 */
	yynts_38,	/* 73 */
	yynts_38,	/* 74 */
	yynts_38,	/* 75 */
	yynts_38,	/* 76 */
	yynts_38,	/* 77 */
	yynts_38,	/* 78 */
	yynts_38,	/* 79 */
	yynts_38,	/* 80 */
	yynts_38,	/* 81 */
	yynts_38,	/* 82 */
	yynts_38,	/* 83 */
	yynts_38,	/* 84 */
	yynts_26,	/* 85 */
	yynts_26,	/* 86 */
	yynts_39,	/* 87 */
	yynts_40,	/* 88 */
	yynts_26,	/* 89 */
	yynts_41,	/* 90 */
};


static YYCONST char *yystring[] = {
/* 0 */	0,
/* 1 */	"program: PROGRAM(decls,FUNCTION(END(ID,INT),FARGS(NIL,main)))",
/* 2 */	"program: MODULE(decls)",
/* 3 */	"decls: NIL",
/* 4 */	"decls: gdecls",
/* 5 */	"gdecls: DECL(gdecls,decl)",
/* 6 */	"gdecls: DECL(NIL,decl)",
/* 7 */	"decl: VAR(vardecl)",
/* 8 */	"decl: FUNCTION(END(ID,INT),FARGS(fvars,eqbody))",
/* 9 */	"decl: FUNCTION(END(ID,INT),FARGS(NIL,eqbody))",
/* 10 */	"fvar: NUMBER(ID,NIL)",
/* 11 */	"fvar: STRING(ID,NIL)",
/* 12 */	"fvar: ARRAY(ID,INTS(vdim,NIL))",
/* 13 */	"fvars: ARGS(NIL,fvar)",
/* 14 */	"fvars: ARGS(fvars,fvar)",
/* 15 */	"vardecl: NUMBER(ID,eqint)",
/* 16 */	"vardecl: STRING(ID,eqstr)",
/* 17 */	"vardecl: ARRAY(ID,INTS(vdim,eqvec))",
/* 18 */	"vdim: NIL",
/* 19 */	"vdim: INT",
/* 20 */	"eqint: NIL",
/* 21 */	"eqint: INT",
/* 22 */	"eqstr: NIL",
/* 23 */	"eqstr: eqchars",
/* 24 */	"eqchars: CHARS(NIL,eqchar)",
/* 25 */	"eqchars: CHARS(eqchars,eqchar)",
/* 26 */	"eqchar: INT",
/* 27 */	"eqchar: CHAR",
/* 28 */	"eqchar: STR",
/* 29 */	"chars: CHARS(NIL,char)",
/* 30 */	"chars: CHARS(chars,char)",
/* 31 */	"char: INT",
/* 32 */	"char: CHAR",
/* 33 */	"char: STR",
/* 34 */	"eqvec: NIL",
/* 35 */	"eqvec: ints",
/* 36 */	"ints: INT",
/* 37 */	"ints: INTS(ints,INT)",
/* 38 */	"eqbody: NIL",
/* 39 */	"eqbody: body",
/* 40 */	"main: START(fvars,instrs)",
/* 41 */	"main: START(NIL,instrs)",
/* 42 */	"body: START(fvars,STMT(instrs,ret))",
/* 43 */	"body: START(NIL,STMT(instrs,ret))",
/* 44 */	"ret: RETURN(NIL)",
/* 45 */	"ret: RETURN(expr)",
/* 46 */	"ret: NIL",
/* 47 */	"loop: ret",
/* 48 */	"loop: REPEAT",
/* 49 */	"loop: STOP",
/* 50 */	"block: STMT(instrs,loop)",
/* 51 */	"instrs: NIL",
/* 52 */	"instrs: STMT(instrs,instr)",
/* 53 */	"instr: FI(THEN(if,elifs),else)",
/* 54 */	"instr: FOR(UNTIL(expr,expr),STEP(block,expr))",
/* 55 */	"instr: PRINT(expr)",
/* 56 */	"instr: expr",
/* 57 */	"instr: ALLOC(alloc,lval)",
/* 58 */	"alloc: expr",
/* 59 */	"if: IF(cond,block)",
/* 60 */	"ifelse: IF(cond,block)",
/* 61 */	"cond: expr",
/* 62 */	"elifs: NIL",
/* 63 */	"elifs: ELIF(elifs,ifelse)",
/* 64 */	"else: NIL",
/* 65 */	"else: block",
/* 66 */	"lval: ID",
/* 67 */	"lval: INDEX(expr,ID)",
/* 68 */	"expr: chars",
/* 69 */	"expr: lval",
/* 70 */	"expr: ADDR(lval)",
/* 71 */	"expr: ADD(expr,expr)",
/* 72 */	"expr: SUB(expr,expr)",
/* 73 */	"expr: MUL(expr,expr)",
/* 74 */	"expr: DIV(expr,expr)",
/* 75 */	"expr: MOD(expr,expr)",
/* 76 */	"expr: POW(expr,expr)",
/* 77 */	"expr: EQU(expr,expr)",
/* 78 */	"expr: NE(expr,expr)",
/* 79 */	"expr: GE(expr,expr)",
/* 80 */	"expr: LE(expr,expr)",
/* 81 */	"expr: LT(expr,expr)",
/* 82 */	"expr: GT(expr,expr)",
/* 83 */	"expr: AND(expr,expr)",
/* 84 */	"expr: OR(expr,expr)",
/* 85 */	"expr: NOT(expr)",
/* 86 */	"expr: UMINUS(expr)",
/* 87 */	"expr: EQ(expr,lval)",
/* 88 */	"expr: IDARGS(ID,exprs)",
/* 89 */	"exprs: COMMA(expr,NIL)",
/* 90 */	"exprs: COMMA(expr,exprs)",
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

static short yydecode_main[] = {
	0,
	40,
	41,
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
	9,
};

static short yydecode_vardecl[] = {
	0,
	15,
	16,
	17,
};

static short yydecode_fvars[] = {
	0,
	13,
	14,
};

static short yydecode_eqbody[] = {
	0,
	38,
	39,
};

static short yydecode_fvar[] = {
	0,
	10,
	11,
	12,
};

static short yydecode_vdim[] = {
	0,
	18,
	19,
};

static short yydecode_eqint[] = {
	0,
	20,
	21,
};

static short yydecode_eqstr[] = {
	0,
	22,
	23,
};

static short yydecode_eqvec[] = {
	0,
	34,
	35,
};

static short yydecode_eqchars[] = {
	0,
	24,
	25,
};

static short yydecode_eqchar[] = {
	0,
	26,
	27,
	28,
};

static short yydecode_chars[] = {
	0,
	29,
	30,
};

static short yydecode_char[] = {
	0,
	31,
	32,
	33,
};

static short yydecode_ints[] = {
	0,
	36,
	37,
};

static short yydecode_body[] = {
	0,
	42,
	43,
};

static short yydecode_instrs[] = {
	0,
	51,
	52,
};

static short yydecode_ret[] = {
	0,
	44,
	45,
	46,
};

static short yydecode_expr[] = {
	0,
	68,
	69,
	70,
	71,
	72,
	73,
	74,
	75,
	76,
	77,
	78,
	79,
	80,
	81,
	82,
	83,
	84,
	85,
	86,
	87,
	88,
};

static short yydecode_loop[] = {
	0,
	47,
	48,
	49,
};

static short yydecode_block[] = {
	0,
	50,
};

static short yydecode_instr[] = {
	0,
	53,
	54,
	55,
	56,
	57,
};

static short yydecode_if[] = {
	0,
	59,
};

static short yydecode_elifs[] = {
	0,
	62,
	63,
};

static short yydecode_else[] = {
	0,
	64,
	65,
};

static short yydecode_alloc[] = {
	0,
	58,
};

static short yydecode_lval[] = {
	0,
	66,
	67,
};

static short yydecode_cond[] = {
	0,
	61,
};

static short yydecode_ifelse[] = {
	0,
	60,
};

static short yydecode_exprs[] = {
	0,
	89,
	90,
};

static int yyrule(void *state, int goalnt) {
	if (goalnt < 1 || goalnt > 33)
		PANIC("yyrule", "Bad goal nonterminal", goalnt);
	if (!state)
		return 0;
	switch (goalnt) {
	case yyprogram_NT:	return yydecode_program[((struct yystate *)state)->rule.yyprogram];
	case yydecls_NT:	return yydecode_decls[((struct yystate *)state)->rule.yydecls];
	case yymain_NT:	return yydecode_main[((struct yystate *)state)->rule.yymain];
	case yygdecls_NT:	return yydecode_gdecls[((struct yystate *)state)->rule.yygdecls];
	case yydecl_NT:	return yydecode_decl[((struct yystate *)state)->rule.yydecl];
	case yyvardecl_NT:	return yydecode_vardecl[((struct yystate *)state)->rule.yyvardecl];
	case yyfvars_NT:	return yydecode_fvars[((struct yystate *)state)->rule.yyfvars];
	case yyeqbody_NT:	return yydecode_eqbody[((struct yystate *)state)->rule.yyeqbody];
	case yyfvar_NT:	return yydecode_fvar[((struct yystate *)state)->rule.yyfvar];
	case yyvdim_NT:	return yydecode_vdim[((struct yystate *)state)->rule.yyvdim];
	case yyeqint_NT:	return yydecode_eqint[((struct yystate *)state)->rule.yyeqint];
	case yyeqstr_NT:	return yydecode_eqstr[((struct yystate *)state)->rule.yyeqstr];
	case yyeqvec_NT:	return yydecode_eqvec[((struct yystate *)state)->rule.yyeqvec];
	case yyeqchars_NT:	return yydecode_eqchars[((struct yystate *)state)->rule.yyeqchars];
	case yyeqchar_NT:	return yydecode_eqchar[((struct yystate *)state)->rule.yyeqchar];
	case yychars_NT:	return yydecode_chars[((struct yystate *)state)->rule.yychars];
	case yychar_NT:	return yydecode_char[((struct yystate *)state)->rule.yychar];
	case yyints_NT:	return yydecode_ints[((struct yystate *)state)->rule.yyints];
	case yybody_NT:	return yydecode_body[((struct yystate *)state)->rule.yybody];
	case yyinstrs_NT:	return yydecode_instrs[((struct yystate *)state)->rule.yyinstrs];
	case yyret_NT:	return yydecode_ret[((struct yystate *)state)->rule.yyret];
	case yyexpr_NT:	return yydecode_expr[((struct yystate *)state)->rule.yyexpr];
	case yyloop_NT:	return yydecode_loop[((struct yystate *)state)->rule.yyloop];
	case yyblock_NT:	return yydecode_block[((struct yystate *)state)->rule.yyblock];
	case yyinstr_NT:	return yydecode_instr[((struct yystate *)state)->rule.yyinstr];
	case yyif_NT:	return yydecode_if[((struct yystate *)state)->rule.yyif];
	case yyelifs_NT:	return yydecode_elifs[((struct yystate *)state)->rule.yyelifs];
	case yyelse_NT:	return yydecode_else[((struct yystate *)state)->rule.yyelse];
	case yyalloc_NT:	return yydecode_alloc[((struct yystate *)state)->rule.yyalloc];
	case yylval_NT:	return yydecode_lval[((struct yystate *)state)->rule.yylval];
	case yycond_NT:	return yydecode_cond[((struct yystate *)state)->rule.yycond];
	case yyifelse_NT:	return yydecode_ifelse[((struct yystate *)state)->rule.yyifelse];
	case yyexprs_NT:	return yydecode_exprs[((struct yystate *)state)->rule.yyexprs];
	default:
		PANIC("yyrule", "Bad goal nonterminal", goalnt);
		return 0;
	}
}

static void yyclosure_gdecls(NODEPTR_TYPE, int);
static void yyclosure_eqchars(NODEPTR_TYPE, int);
static void yyclosure_chars(NODEPTR_TYPE, int);
static void yyclosure_ints(NODEPTR_TYPE, int);
static void yyclosure_body(NODEPTR_TYPE, int);
static void yyclosure_ret(NODEPTR_TYPE, int);
static void yyclosure_expr(NODEPTR_TYPE, int);
static void yyclosure_block(NODEPTR_TYPE, int);
static void yyclosure_lval(NODEPTR_TYPE, int);

static void yyclosure_gdecls(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 4, c + 1, p->cost[yydecls_NT]);
	if (c + 1 < p->cost[yydecls_NT]) {
		p->cost[yydecls_NT] = c + 1;
		p->rule.yydecls = 2;
	}
}

static void yyclosure_eqchars(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 23, c + 1, p->cost[yyeqstr_NT]);
	if (c + 1 < p->cost[yyeqstr_NT]) {
		p->cost[yyeqstr_NT] = c + 1;
		p->rule.yyeqstr = 2;
	}
}

static void yyclosure_chars(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 68, c + 1, p->cost[yyexpr_NT]);
	if (c + 1 < p->cost[yyexpr_NT]) {
		p->cost[yyexpr_NT] = c + 1;
		p->rule.yyexpr = 1;
		yyclosure_expr(a, c + 1);
	}
}

static void yyclosure_ints(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 35, c + 1, p->cost[yyeqvec_NT]);
	if (c + 1 < p->cost[yyeqvec_NT]) {
		p->cost[yyeqvec_NT] = c + 1;
		p->rule.yyeqvec = 2;
	}
}

static void yyclosure_body(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 39, c + 1, p->cost[yyeqbody_NT]);
	if (c + 1 < p->cost[yyeqbody_NT]) {
		p->cost[yyeqbody_NT] = c + 1;
		p->rule.yyeqbody = 2;
	}
}

static void yyclosure_ret(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 47, c + 1, p->cost[yyloop_NT]);
	if (c + 1 < p->cost[yyloop_NT]) {
		p->cost[yyloop_NT] = c + 1;
		p->rule.yyloop = 1;
	}
}

static void yyclosure_expr(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 61, c + 1, p->cost[yycond_NT]);
	if (c + 1 < p->cost[yycond_NT]) {
		p->cost[yycond_NT] = c + 1;
		p->rule.yycond = 1;
	}
	yytrace(a, 58, c + 1, p->cost[yyalloc_NT]);
	if (c + 1 < p->cost[yyalloc_NT]) {
		p->cost[yyalloc_NT] = c + 1;
		p->rule.yyalloc = 1;
	}
	yytrace(a, 56, c + 1, p->cost[yyinstr_NT]);
	if (c + 1 < p->cost[yyinstr_NT]) {
		p->cost[yyinstr_NT] = c + 1;
		p->rule.yyinstr = 4;
	}
}

static void yyclosure_block(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 65, c + 0, p->cost[yyelse_NT]);
	if (c + 0 < p->cost[yyelse_NT]) {
		p->cost[yyelse_NT] = c + 0;
		p->rule.yyelse = 2;
	}
}

static void yyclosure_lval(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 69, c + 0, p->cost[yyexpr_NT]);
	if (c + 0 < p->cost[yyexpr_NT]) {
		p->cost[yyexpr_NT] = c + 0;
		p->rule.yyexpr = 2;
		yyclosure_expr(a, c + 0);
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
		0x7fff;
	switch (OP_LABEL(a)) {
	case 33: /* PRINT */
		yylabel(LEFT_CHILD(a),a);
		/* instr: PRINT(expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + 3;
		yytrace(a, 55, c + 0, p->cost[yyinstr_NT]);
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
		yytrace(a, 57, c + 0, p->cost[yyinstr_NT]);
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
		yytrace(a, 75, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 8;
			yyclosure_expr(a, c + 0);
		}
		break;
	case 38: /* AND */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expr: AND(expr,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 83, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 16;
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
			yytrace(a, 88, c + 0, p->cost[yyexpr_NT]);
			if (c + 0 < p->cost[yyexpr_NT]) {
				p->cost[yyexpr_NT] = c + 0;
				p->rule.yyexpr = 21;
				yyclosure_expr(a, c + 0);
			}
		}
		break;
	case 42: /* MUL */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expr: MUL(expr,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 73, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 6;
			yyclosure_expr(a, c + 0);
		}
		break;
	case 43: /* ADD */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expr: ADD(expr,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 71, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 4;
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
			yytrace(a, 89, c + 0, p->cost[yyexprs_NT]);
			if (c + 0 < p->cost[yyexprs_NT]) {
				p->cost[yyexprs_NT] = c + 0;
				p->rule.yyexprs = 1;
			}
		}
		/* exprs: COMMA(expr,exprs) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexprs_NT] + 1;
		yytrace(a, 90, c + 0, p->cost[yyexprs_NT]);
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
		yytrace(a, 72, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 5;
			yyclosure_expr(a, c + 0);
		}
		break;
	case 47: /* DIV */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expr: DIV(expr,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 74, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 7;
			yyclosure_expr(a, c + 0);
		}
		break;
	case 59: /* STMT */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* block: STMT(instrs,loop) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyinstrs_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyloop_NT] + 1;
		yytrace(a, 50, c + 0, p->cost[yyblock_NT]);
		if (c + 0 < p->cost[yyblock_NT]) {
			p->cost[yyblock_NT] = c + 0;
			p->rule.yyblock = 1;
			yyclosure_block(a, c + 0);
		}
		/* instrs: STMT(instrs,instr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyinstrs_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyinstr_NT] + 1;
		yytrace(a, 52, c + 0, p->cost[yyinstrs_NT]);
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
		yytrace(a, 81, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 14;
			yyclosure_expr(a, c + 0);
		}
		break;
	case 61: /* EQU */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expr: EQU(expr,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 77, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 10;
			yyclosure_expr(a, c + 0);
		}
		break;
	case 62: /* GT */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expr: GT(expr,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 82, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 15;
			yyclosure_expr(a, c + 0);
		}
		break;
	case 91: /* INDEX */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		if (	/* lval: INDEX(expr,ID) */
			OP_LABEL(RIGHT_CHILD(a)) == 259 /* ID */
		) {
			c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + 1;
			yytrace(a, 67, c + 0, p->cost[yylval_NT]);
			if (c + 0 < p->cost[yylval_NT]) {
				p->cost[yylval_NT] = c + 0;
				p->rule.yylval = 2;
				yyclosure_lval(a, c + 0);
			}
		}
		break;
	case 94: /* POW */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expr: POW(expr,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 76, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 9;
			yyclosure_expr(a, c + 0);
		}
		break;
	case 124: /* OR */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expr: OR(expr,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 84, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 17;
			yyclosure_expr(a, c + 0);
		}
		break;
	case 126: /* NOT */
		yylabel(LEFT_CHILD(a),a);
		/* expr: NOT(expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 85, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 18;
			yyclosure_expr(a, c + 0);
		}
		break;
	case 257: /* INT */
		/* vdim: INT */
		yytrace(a, 19, 1 + 0, p->cost[yyvdim_NT]);
		if (1 + 0 < p->cost[yyvdim_NT]) {
			p->cost[yyvdim_NT] = 1 + 0;
			p->rule.yyvdim = 2;
		}
		/* eqint: INT */
		yytrace(a, 21, 1 + 0, p->cost[yyeqint_NT]);
		if (1 + 0 < p->cost[yyeqint_NT]) {
			p->cost[yyeqint_NT] = 1 + 0;
			p->rule.yyeqint = 2;
		}
		/* eqchar: INT */
		yytrace(a, 26, 1 + 0, p->cost[yyeqchar_NT]);
		if (1 + 0 < p->cost[yyeqchar_NT]) {
			p->cost[yyeqchar_NT] = 1 + 0;
			p->rule.yyeqchar = 1;
		}
		/* char: INT */
		yytrace(a, 31, 1 + 0, p->cost[yychar_NT]);
		if (1 + 0 < p->cost[yychar_NT]) {
			p->cost[yychar_NT] = 1 + 0;
			p->rule.yychar = 1;
		}
		/* ints: INT */
		yytrace(a, 36, 1 + 0, p->cost[yyints_NT]);
		if (1 + 0 < p->cost[yyints_NT]) {
			p->cost[yyints_NT] = 1 + 0;
			p->rule.yyints = 1;
			yyclosure_ints(a, 1 + 0);
		}
		break;
	case 258: /* CHAR */
		/* eqchar: CHAR */
		yytrace(a, 27, 1 + 0, p->cost[yyeqchar_NT]);
		if (1 + 0 < p->cost[yyeqchar_NT]) {
			p->cost[yyeqchar_NT] = 1 + 0;
			p->rule.yyeqchar = 2;
		}
		/* char: CHAR */
		yytrace(a, 32, 1 + 0, p->cost[yychar_NT]);
		if (1 + 0 < p->cost[yychar_NT]) {
			p->cost[yychar_NT] = 1 + 0;
			p->rule.yychar = 2;
		}
		break;
	case 259: /* ID */
		/* lval: ID */
		yytrace(a, 66, 1 + 0, p->cost[yylval_NT]);
		if (1 + 0 < p->cost[yylval_NT]) {
			p->cost[yylval_NT] = 1 + 0;
			p->rule.yylval = 1;
			yyclosure_lval(a, 1 + 0);
		}
		break;
	case 260: /* STR */
		/* eqchar: STR */
		yytrace(a, 28, 1 + 0, p->cost[yyeqchar_NT]);
		if (1 + 0 < p->cost[yyeqchar_NT]) {
			p->cost[yyeqchar_NT] = 1 + 0;
			p->rule.yyeqchar = 3;
		}
		/* char: STR */
		yytrace(a, 33, 1 + 0, p->cost[yychar_NT]);
		if (1 + 0 < p->cost[yychar_NT]) {
			p->cost[yychar_NT] = 1 + 0;
			p->rule.yychar = 3;
		}
		break;
	case 261: /* PROGRAM */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		if (	/* program: PROGRAM(decls,FUNCTION(END(ID,INT),FARGS(NIL,main))) */
			OP_LABEL(RIGHT_CHILD(a)) == 269 && /* FUNCTION */
			OP_LABEL(LEFT_CHILD(RIGHT_CHILD(a))) == 263 && /* END */
			OP_LABEL(LEFT_CHILD(LEFT_CHILD(RIGHT_CHILD(a)))) == 259 && /* ID */
			OP_LABEL(RIGHT_CHILD(LEFT_CHILD(RIGHT_CHILD(a)))) == 257 && /* INT */
			OP_LABEL(RIGHT_CHILD(RIGHT_CHILD(a))) == 286 && /* FARGS */
			OP_LABEL(LEFT_CHILD(RIGHT_CHILD(RIGHT_CHILD(a)))) == 293 /* NIL */
		) {
			c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yydecls_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(RIGHT_CHILD(RIGHT_CHILD(a)))))->cost[yymain_NT] + 1;
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
		return;
	case 264: /* PUBLIC */
		return;
	case 265: /* FORWARD */
		return;
	case 266: /* STRING */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		if (	/* fvar: STRING(ID,NIL) */
			OP_LABEL(LEFT_CHILD(a)) == 259 && /* ID */
			OP_LABEL(RIGHT_CHILD(a)) == 293 /* NIL */
		) {
			c = 1;
			yytrace(a, 11, c + 0, p->cost[yyfvar_NT]);
			if (c + 0 < p->cost[yyfvar_NT]) {
				p->cost[yyfvar_NT] = c + 0;
				p->rule.yyfvar = 2;
			}
		}
		if (	/* vardecl: STRING(ID,eqstr) */
			OP_LABEL(LEFT_CHILD(a)) == 259 /* ID */
		) {
			c = ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyeqstr_NT] + 1;
			yytrace(a, 16, c + 0, p->cost[yyvardecl_NT]);
			if (c + 0 < p->cost[yyvardecl_NT]) {
				p->cost[yyvardecl_NT] = c + 0;
				p->rule.yyvardecl = 2;
			}
		}
		break;
	case 267: /* NUMBER */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		if (	/* fvar: NUMBER(ID,NIL) */
			OP_LABEL(LEFT_CHILD(a)) == 259 && /* ID */
			OP_LABEL(RIGHT_CHILD(a)) == 293 /* NIL */
		) {
			c = 1;
			yytrace(a, 10, c + 0, p->cost[yyfvar_NT]);
			if (c + 0 < p->cost[yyfvar_NT]) {
				p->cost[yyfvar_NT] = c + 0;
				p->rule.yyfvar = 1;
			}
		}
		if (	/* vardecl: NUMBER(ID,eqint) */
			OP_LABEL(LEFT_CHILD(a)) == 259 /* ID */
		) {
			c = ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyeqint_NT] + 1;
			yytrace(a, 15, c + 0, p->cost[yyvardecl_NT]);
			if (c + 0 < p->cost[yyvardecl_NT]) {
				p->cost[yyvardecl_NT] = c + 0;
				p->rule.yyvardecl = 1;
			}
		}
		break;
	case 268: /* ARRAY */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		if (	/* fvar: ARRAY(ID,INTS(vdim,NIL)) */
			OP_LABEL(LEFT_CHILD(a)) == 259 && /* ID */
			OP_LABEL(RIGHT_CHILD(a)) == 288 && /* INTS */
			OP_LABEL(RIGHT_CHILD(RIGHT_CHILD(a))) == 293 /* NIL */
		) {
			c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(RIGHT_CHILD(a))))->cost[yyvdim_NT] + 1;
			yytrace(a, 12, c + 0, p->cost[yyfvar_NT]);
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
			yytrace(a, 17, c + 0, p->cost[yyvardecl_NT]);
			if (c + 0 < p->cost[yyvardecl_NT]) {
				p->cost[yyvardecl_NT] = c + 0;
				p->rule.yyvardecl = 3;
			}
		}
		break;
	case 269: /* FUNCTION */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		if (	/* decl: FUNCTION(END(ID,INT),FARGS(fvars,eqbody)) */
			OP_LABEL(LEFT_CHILD(a)) == 263 && /* END */
			OP_LABEL(LEFT_CHILD(LEFT_CHILD(a))) == 259 && /* ID */
			OP_LABEL(RIGHT_CHILD(LEFT_CHILD(a))) == 257 && /* INT */
			OP_LABEL(RIGHT_CHILD(a)) == 286 /* FARGS */
		) {
			c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(RIGHT_CHILD(a))))->cost[yyfvars_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(RIGHT_CHILD(a))))->cost[yyeqbody_NT] + 1;
			yytrace(a, 8, c + 0, p->cost[yydecl_NT]);
			if (c + 0 < p->cost[yydecl_NT]) {
				p->cost[yydecl_NT] = c + 0;
				p->rule.yydecl = 2;
			}
		}
		if (	/* decl: FUNCTION(END(ID,INT),FARGS(NIL,eqbody)) */
			OP_LABEL(LEFT_CHILD(a)) == 263 && /* END */
			OP_LABEL(LEFT_CHILD(LEFT_CHILD(a))) == 259 && /* ID */
			OP_LABEL(RIGHT_CHILD(LEFT_CHILD(a))) == 257 && /* INT */
			OP_LABEL(RIGHT_CHILD(a)) == 286 && /* FARGS */
			OP_LABEL(LEFT_CHILD(RIGHT_CHILD(a))) == 293 /* NIL */
		) {
			c = ((struct yystate *)STATE_LABEL(RIGHT_CHILD(RIGHT_CHILD(a))))->cost[yyeqbody_NT] + 1;
			yytrace(a, 9, c + 0, p->cost[yydecl_NT]);
			if (c + 0 < p->cost[yydecl_NT]) {
				p->cost[yydecl_NT] = c + 0;
				p->rule.yydecl = 3;
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
		yytrace(a, 59, c + 0, p->cost[yyif_NT]);
		if (c + 0 < p->cost[yyif_NT]) {
			p->cost[yyif_NT] = c + 0;
			p->rule.yyif = 1;
		}
		/* ifelse: IF(cond,block) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yycond_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyblock_NT] + 0;
		yytrace(a, 60, c + 0, p->cost[yyifelse_NT]);
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
			yytrace(a, 53, c + 0, p->cost[yyinstr_NT]);
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
		yytrace(a, 63, c + 0, p->cost[yyelifs_NT]);
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
			yytrace(a, 44, c + 0, p->cost[yyret_NT]);
			if (c + 0 < p->cost[yyret_NT]) {
				p->cost[yyret_NT] = c + 0;
				p->rule.yyret = 1;
				yyclosure_ret(a, c + 0);
			}
		}
		/* ret: RETURN(expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 45, c + 0, p->cost[yyret_NT]);
		if (c + 0 < p->cost[yyret_NT]) {
			p->cost[yyret_NT] = c + 0;
			p->rule.yyret = 2;
			yyclosure_ret(a, c + 0);
		}
		break;
	case 278: /* START */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* main: START(fvars,instrs) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyfvars_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyinstrs_NT] + 1;
		yytrace(a, 40, c + 0, p->cost[yymain_NT]);
		if (c + 0 < p->cost[yymain_NT]) {
			p->cost[yymain_NT] = c + 0;
			p->rule.yymain = 1;
		}
		if (	/* main: START(NIL,instrs) */
			OP_LABEL(LEFT_CHILD(a)) == 293 /* NIL */
		) {
			c = ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyinstrs_NT] + 1;
			yytrace(a, 41, c + 0, p->cost[yymain_NT]);
			if (c + 0 < p->cost[yymain_NT]) {
				p->cost[yymain_NT] = c + 0;
				p->rule.yymain = 2;
			}
		}
		if (	/* body: START(fvars,STMT(instrs,ret)) */
			OP_LABEL(RIGHT_CHILD(a)) == 59 /* STMT */
		) {
			c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyfvars_NT] + ((struct yystate *)STATE_LABEL(LEFT_CHILD(RIGHT_CHILD(a))))->cost[yyinstrs_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(RIGHT_CHILD(a))))->cost[yyret_NT] + 1;
			yytrace(a, 42, c + 0, p->cost[yybody_NT]);
			if (c + 0 < p->cost[yybody_NT]) {
				p->cost[yybody_NT] = c + 0;
				p->rule.yybody = 1;
				yyclosure_body(a, c + 0);
			}
		}
		if (	/* body: START(NIL,STMT(instrs,ret)) */
			OP_LABEL(LEFT_CHILD(a)) == 293 && /* NIL */
			OP_LABEL(RIGHT_CHILD(a)) == 59 /* STMT */
		) {
			c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(RIGHT_CHILD(a))))->cost[yyinstrs_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(RIGHT_CHILD(a))))->cost[yyret_NT] + 1;
			yytrace(a, 43, c + 0, p->cost[yybody_NT]);
			if (c + 0 < p->cost[yybody_NT]) {
				p->cost[yybody_NT] = c + 0;
				p->rule.yybody = 2;
				yyclosure_body(a, c + 0);
			}
		}
		break;
	case 279: /* FOR */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		if (	/* instr: FOR(UNTIL(expr,expr),STEP(block,expr)) */
			OP_LABEL(LEFT_CHILD(a)) == 280 && /* UNTIL */
			OP_LABEL(RIGHT_CHILD(a)) == 281 /* STEP */
		) {
			c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(LEFT_CHILD(a))))->cost[yyexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(LEFT_CHILD(a))))->cost[yyexpr_NT] + ((struct yystate *)STATE_LABEL(LEFT_CHILD(RIGHT_CHILD(a))))->cost[yyblock_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(RIGHT_CHILD(a))))->cost[yyexpr_NT] + 1;
			yytrace(a, 54, c + 0, p->cost[yyinstr_NT]);
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
		yytrace(a, 48, 1 + 0, p->cost[yyloop_NT]);
		if (1 + 0 < p->cost[yyloop_NT]) {
			p->cost[yyloop_NT] = 1 + 0;
			p->rule.yyloop = 2;
		}
		break;
	case 285: /* STOP */
		/* loop: STOP */
		yytrace(a, 49, 1 + 0, p->cost[yyloop_NT]);
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
			yytrace(a, 24, c + 0, p->cost[yyeqchars_NT]);
			if (c + 0 < p->cost[yyeqchars_NT]) {
				p->cost[yyeqchars_NT] = c + 0;
				p->rule.yyeqchars = 1;
				yyclosure_eqchars(a, c + 0);
			}
		}
		/* eqchars: CHARS(eqchars,eqchar) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyeqchars_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyeqchar_NT] + 1;
		yytrace(a, 25, c + 0, p->cost[yyeqchars_NT]);
		if (c + 0 < p->cost[yyeqchars_NT]) {
			p->cost[yyeqchars_NT] = c + 0;
			p->rule.yyeqchars = 2;
			yyclosure_eqchars(a, c + 0);
		}
		if (	/* chars: CHARS(NIL,char) */
			OP_LABEL(LEFT_CHILD(a)) == 293 /* NIL */
		) {
			c = ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yychar_NT] + 1;
			yytrace(a, 29, c + 0, p->cost[yychars_NT]);
			if (c + 0 < p->cost[yychars_NT]) {
				p->cost[yychars_NT] = c + 0;
				p->rule.yychars = 1;
				yyclosure_chars(a, c + 0);
			}
		}
		/* chars: CHARS(chars,char) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yychars_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yychar_NT] + 1;
		yytrace(a, 30, c + 0, p->cost[yychars_NT]);
		if (c + 0 < p->cost[yychars_NT]) {
			p->cost[yychars_NT] = c + 0;
			p->rule.yychars = 2;
			yyclosure_chars(a, c + 0);
		}
		break;
	case 288: /* INTS */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		if (	/* ints: INTS(ints,INT) */
			OP_LABEL(RIGHT_CHILD(a)) == 257 /* INT */
		) {
			c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyints_NT] + 1;
			yytrace(a, 37, c + 0, p->cost[yyints_NT]);
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
		yytrace(a, 70, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 3;
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
		if (	/* fvars: ARGS(NIL,fvar) */
			OP_LABEL(LEFT_CHILD(a)) == 293 /* NIL */
		) {
			c = ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyfvar_NT] + 1;
			yytrace(a, 13, c + 0, p->cost[yyfvars_NT]);
			if (c + 0 < p->cost[yyfvars_NT]) {
				p->cost[yyfvars_NT] = c + 0;
				p->rule.yyfvars = 1;
			}
		}
		/* fvars: ARGS(fvars,fvar) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyfvars_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyfvar_NT] + 1;
		yytrace(a, 14, c + 0, p->cost[yyfvars_NT]);
		if (c + 0 < p->cost[yyfvars_NT]) {
			p->cost[yyfvars_NT] = c + 0;
			p->rule.yyfvars = 2;
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
		/* vdim: NIL */
		yytrace(a, 18, 1 + 0, p->cost[yyvdim_NT]);
		if (1 + 0 < p->cost[yyvdim_NT]) {
			p->cost[yyvdim_NT] = 1 + 0;
			p->rule.yyvdim = 1;
		}
		/* eqint: NIL */
		yytrace(a, 20, 1 + 0, p->cost[yyeqint_NT]);
		if (1 + 0 < p->cost[yyeqint_NT]) {
			p->cost[yyeqint_NT] = 1 + 0;
			p->rule.yyeqint = 1;
		}
		/* eqstr: NIL */
		yytrace(a, 22, 1 + 0, p->cost[yyeqstr_NT]);
		if (1 + 0 < p->cost[yyeqstr_NT]) {
			p->cost[yyeqstr_NT] = 1 + 0;
			p->rule.yyeqstr = 1;
		}
		/* eqvec: NIL */
		yytrace(a, 34, 1 + 0, p->cost[yyeqvec_NT]);
		if (1 + 0 < p->cost[yyeqvec_NT]) {
			p->cost[yyeqvec_NT] = 1 + 0;
			p->rule.yyeqvec = 1;
		}
		/* eqbody: NIL */
		yytrace(a, 38, 1 + 0, p->cost[yyeqbody_NT]);
		if (1 + 0 < p->cost[yyeqbody_NT]) {
			p->cost[yyeqbody_NT] = 1 + 0;
			p->rule.yyeqbody = 1;
		}
		/* ret: NIL */
		yytrace(a, 46, 1 + 0, p->cost[yyret_NT]);
		if (1 + 0 < p->cost[yyret_NT]) {
			p->cost[yyret_NT] = 1 + 0;
			p->rule.yyret = 3;
			yyclosure_ret(a, 1 + 0);
		}
		/* instrs: NIL */
		yytrace(a, 51, 1 + 0, p->cost[yyinstrs_NT]);
		if (1 + 0 < p->cost[yyinstrs_NT]) {
			p->cost[yyinstrs_NT] = 1 + 0;
			p->rule.yyinstrs = 1;
		}
		/* elifs: NIL */
		yytrace(a, 62, 0 + 0, p->cost[yyelifs_NT]);
		if (0 + 0 < p->cost[yyelifs_NT]) {
			p->cost[yyelifs_NT] = 0 + 0;
			p->rule.yyelifs = 1;
		}
		/* else: NIL */
		yytrace(a, 64, 0 + 0, p->cost[yyelse_NT]);
		if (0 + 0 < p->cost[yyelse_NT]) {
			p->cost[yyelse_NT] = 0 + 0;
			p->rule.yyelse = 1;
		}
		break;
	case 294: /* EQ */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expr: EQ(expr,lval) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yylval_NT] + 1;
		yytrace(a, 87, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 20;
			yyclosure_expr(a, c + 0);
		}
		break;
	case 295: /* NE */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expr: NE(expr,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 78, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 11;
			yyclosure_expr(a, c + 0);
		}
		break;
	case 296: /* GE */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expr: GE(expr,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 79, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 12;
			yyclosure_expr(a, c + 0);
		}
		break;
	case 297: /* LE */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expr: LE(expr,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 80, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 13;
			yyclosure_expr(a, c + 0);
		}
		break;
	case 298: /* UMINUS */
		yylabel(LEFT_CHILD(a),a);
		/* expr: UMINUS(expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 86, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 19;
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
	case 1: /* program: PROGRAM(decls,FUNCTION(END(ID,INT),FARGS(NIL,main))) */
		kids[0] = LEFT_CHILD(p);
		kids[1] = RIGHT_CHILD(RIGHT_CHILD(RIGHT_CHILD(p)));
		break;
	case 89: /* exprs: COMMA(expr,NIL) */
	case 86: /* expr: UMINUS(expr) */
	case 85: /* expr: NOT(expr) */
	case 70: /* expr: ADDR(lval) */
	case 67: /* lval: INDEX(expr,ID) */
	case 55: /* instr: PRINT(expr) */
	case 45: /* ret: RETURN(expr) */
	case 37: /* ints: INTS(ints,INT) */
	case 7: /* decl: VAR(vardecl) */
	case 2: /* program: MODULE(decls) */
		kids[0] = LEFT_CHILD(p);
		break;
	case 66: /* lval: ID */
	case 64: /* else: NIL */
	case 62: /* elifs: NIL */
	case 51: /* instrs: NIL */
	case 49: /* loop: STOP */
	case 48: /* loop: REPEAT */
	case 46: /* ret: NIL */
	case 44: /* ret: RETURN(NIL) */
	case 38: /* eqbody: NIL */
	case 36: /* ints: INT */
	case 34: /* eqvec: NIL */
	case 33: /* char: STR */
	case 32: /* char: CHAR */
	case 31: /* char: INT */
	case 28: /* eqchar: STR */
	case 27: /* eqchar: CHAR */
	case 26: /* eqchar: INT */
	case 22: /* eqstr: NIL */
	case 21: /* eqint: INT */
	case 20: /* eqint: NIL */
	case 19: /* vdim: INT */
	case 18: /* vdim: NIL */
	case 11: /* fvar: STRING(ID,NIL) */
	case 10: /* fvar: NUMBER(ID,NIL) */
	case 3: /* decls: NIL */
		break;
	case 69: /* expr: lval */
	case 68: /* expr: chars */
	case 65: /* else: block */
	case 61: /* cond: expr */
	case 58: /* alloc: expr */
	case 56: /* instr: expr */
	case 47: /* loop: ret */
	case 39: /* eqbody: body */
	case 35: /* eqvec: ints */
	case 23: /* eqstr: eqchars */
	case 4: /* decls: gdecls */
		kids[0] = p;
		break;
	case 90: /* exprs: COMMA(expr,exprs) */
	case 87: /* expr: EQ(expr,lval) */
	case 84: /* expr: OR(expr,expr) */
	case 83: /* expr: AND(expr,expr) */
	case 82: /* expr: GT(expr,expr) */
	case 81: /* expr: LT(expr,expr) */
	case 80: /* expr: LE(expr,expr) */
	case 79: /* expr: GE(expr,expr) */
	case 78: /* expr: NE(expr,expr) */
	case 77: /* expr: EQU(expr,expr) */
	case 76: /* expr: POW(expr,expr) */
	case 75: /* expr: MOD(expr,expr) */
	case 74: /* expr: DIV(expr,expr) */
	case 73: /* expr: MUL(expr,expr) */
	case 72: /* expr: SUB(expr,expr) */
	case 71: /* expr: ADD(expr,expr) */
	case 63: /* elifs: ELIF(elifs,ifelse) */
	case 60: /* ifelse: IF(cond,block) */
	case 59: /* if: IF(cond,block) */
	case 57: /* instr: ALLOC(alloc,lval) */
	case 52: /* instrs: STMT(instrs,instr) */
	case 50: /* block: STMT(instrs,loop) */
	case 40: /* main: START(fvars,instrs) */
	case 30: /* chars: CHARS(chars,char) */
	case 25: /* eqchars: CHARS(eqchars,eqchar) */
	case 14: /* fvars: ARGS(fvars,fvar) */
	case 5: /* gdecls: DECL(gdecls,decl) */
		kids[0] = LEFT_CHILD(p);
		kids[1] = RIGHT_CHILD(p);
		break;
	case 88: /* expr: IDARGS(ID,exprs) */
	case 41: /* main: START(NIL,instrs) */
	case 29: /* chars: CHARS(NIL,char) */
	case 24: /* eqchars: CHARS(NIL,eqchar) */
	case 16: /* vardecl: STRING(ID,eqstr) */
	case 15: /* vardecl: NUMBER(ID,eqint) */
	case 13: /* fvars: ARGS(NIL,fvar) */
	case 6: /* gdecls: DECL(NIL,decl) */
		kids[0] = RIGHT_CHILD(p);
		break;
	case 43: /* body: START(NIL,STMT(instrs,ret)) */
	case 17: /* vardecl: ARRAY(ID,INTS(vdim,eqvec)) */
	case 8: /* decl: FUNCTION(END(ID,INT),FARGS(fvars,eqbody)) */
		kids[0] = LEFT_CHILD(RIGHT_CHILD(p));
		kids[1] = RIGHT_CHILD(RIGHT_CHILD(p));
		break;
	case 9: /* decl: FUNCTION(END(ID,INT),FARGS(NIL,eqbody)) */
		kids[0] = RIGHT_CHILD(RIGHT_CHILD(p));
		break;
	case 12: /* fvar: ARRAY(ID,INTS(vdim,NIL)) */
		kids[0] = LEFT_CHILD(RIGHT_CHILD(p));
		break;
	case 42: /* body: START(fvars,STMT(instrs,ret)) */
		kids[0] = LEFT_CHILD(p);
		kids[1] = LEFT_CHILD(RIGHT_CHILD(p));
		kids[2] = RIGHT_CHILD(RIGHT_CHILD(p));
		break;
	case 53: /* instr: FI(THEN(if,elifs),else) */
		kids[0] = LEFT_CHILD(LEFT_CHILD(p));
		kids[1] = RIGHT_CHILD(LEFT_CHILD(p));
		kids[2] = RIGHT_CHILD(p);
		break;
	case 54: /* instr: FOR(UNTIL(expr,expr),STEP(block,expr)) */
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
	case 1: /* program: PROGRAM(decls,FUNCTION(END(ID,INT),FARGS(NIL,main))) */
		fprintf(stderr, "0x%lx: line 74: program: PROGRAM(decls,FUNCTION(END(ID,INT),FARGS(NIL,main)))\n",(long)p);
#line 74 "minor.brg"
{}
		break;
	case 2: /* program: MODULE(decls) */
		fprintf(stderr, "0x%lx: line 75: program: MODULE(decls)\n",(long)p);
#line 75 "minor.brg"
{}
		break;
	case 3: /* decls: NIL */
		fprintf(stderr, "0x%lx: line 77: decls: NIL\n",(long)p);
#line 77 "minor.brg"
{}
		break;
	case 4: /* decls: gdecls */
		fprintf(stderr, "0x%lx: line 78: decls: gdecls\n",(long)p);
#line 78 "minor.brg"
{}
		break;
	case 5: /* gdecls: DECL(gdecls,decl) */
		fprintf(stderr, "0x%lx: line 80: gdecls: DECL(gdecls,decl)\n",(long)p);
#line 80 "minor.brg"
{}
		break;
	case 6: /* gdecls: DECL(NIL,decl) */
		fprintf(stderr, "0x%lx: line 81: gdecls: DECL(NIL,decl)\n",(long)p);
#line 81 "minor.brg"
{}
		break;
	case 7: /* decl: VAR(vardecl) */
		fprintf(stderr, "0x%lx: line 83: decl: VAR(vardecl)\n",(long)p);
#line 83 "minor.brg"
{}
		break;
	case 8: /* decl: FUNCTION(END(ID,INT),FARGS(fvars,eqbody)) */
		fprintf(stderr, "0x%lx: line 84: decl: FUNCTION(END(ID,INT),FARGS(fvars,eqbody))\n",(long)p);
#line 84 "minor.brg"
{}
		break;
	case 9: /* decl: FUNCTION(END(ID,INT),FARGS(NIL,eqbody)) */
		fprintf(stderr, "0x%lx: line 85: decl: FUNCTION(END(ID,INT),FARGS(NIL,eqbody))\n",(long)p);
#line 85 "minor.brg"
{}
		break;
	case 10: /* fvar: NUMBER(ID,NIL) */
		fprintf(stderr, "0x%lx: line 87: fvar: NUMBER(ID,NIL)\n",(long)p);
#line 87 "minor.brg"
{}
		break;
	case 11: /* fvar: STRING(ID,NIL) */
		fprintf(stderr, "0x%lx: line 88: fvar: STRING(ID,NIL)\n",(long)p);
#line 88 "minor.brg"
{}
		break;
	case 12: /* fvar: ARRAY(ID,INTS(vdim,NIL)) */
		fprintf(stderr, "0x%lx: line 89: fvar: ARRAY(ID,INTS(vdim,NIL))\n",(long)p);
#line 89 "minor.brg"
{}
		break;
	case 13: /* fvars: ARGS(NIL,fvar) */
		fprintf(stderr, "0x%lx: line 91: fvars: ARGS(NIL,fvar)\n",(long)p);
#line 91 "minor.brg"
{}
		break;
	case 14: /* fvars: ARGS(fvars,fvar) */
		fprintf(stderr, "0x%lx: line 92: fvars: ARGS(fvars,fvar)\n",(long)p);
#line 92 "minor.brg"
{}
		break;
	case 15: /* vardecl: NUMBER(ID,eqint) */
		fprintf(stderr, "0x%lx: line 94: vardecl: NUMBER(ID,eqint)\n",(long)p);
#line 94 "minor.brg"
{}
		break;
	case 16: /* vardecl: STRING(ID,eqstr) */
		fprintf(stderr, "0x%lx: line 95: vardecl: STRING(ID,eqstr)\n",(long)p);
#line 95 "minor.brg"
{}
		break;
	case 17: /* vardecl: ARRAY(ID,INTS(vdim,eqvec)) */
		fprintf(stderr, "0x%lx: line 96: vardecl: ARRAY(ID,INTS(vdim,eqvec))\n",(long)p);
#line 96 "minor.brg"
{}
		break;
	case 18: /* vdim: NIL */
		fprintf(stderr, "0x%lx: line 98: vdim: NIL\n",(long)p);
#line 98 "minor.brg"
{}
		break;
	case 19: /* vdim: INT */
		fprintf(stderr, "0x%lx: line 99: vdim: INT\n",(long)p);
#line 99 "minor.brg"
{}
		break;
	case 20: /* eqint: NIL */
		fprintf(stderr, "0x%lx: line 101: eqint: NIL\n",(long)p);
#line 101 "minor.brg"
{}
		break;
	case 21: /* eqint: INT */
		fprintf(stderr, "0x%lx: line 102: eqint: INT\n",(long)p);
#line 102 "minor.brg"
{}
		break;
	case 22: /* eqstr: NIL */
		fprintf(stderr, "0x%lx: line 104: eqstr: NIL\n",(long)p);
#line 104 "minor.brg"
{}
		break;
	case 23: /* eqstr: eqchars */
		fprintf(stderr, "0x%lx: line 105: eqstr: eqchars\n",(long)p);
#line 105 "minor.brg"
{}
		break;
	case 24: /* eqchars: CHARS(NIL,eqchar) */
		fprintf(stderr, "0x%lx: line 107: eqchars: CHARS(NIL,eqchar)\n",(long)p);
#line 107 "minor.brg"
{}
		break;
	case 25: /* eqchars: CHARS(eqchars,eqchar) */
		fprintf(stderr, "0x%lx: line 108: eqchars: CHARS(eqchars,eqchar)\n",(long)p);
#line 108 "minor.brg"
{}
		break;
	case 26: /* eqchar: INT */
		fprintf(stderr, "0x%lx: line 110: eqchar: INT\n",(long)p);
#line 110 "minor.brg"
{}
		break;
	case 27: /* eqchar: CHAR */
		fprintf(stderr, "0x%lx: line 111: eqchar: CHAR\n",(long)p);
#line 111 "minor.brg"
{}
		break;
	case 28: /* eqchar: STR */
		fprintf(stderr, "0x%lx: line 112: eqchar: STR\n",(long)p);
#line 112 "minor.brg"
{}
		break;
	case 29: /* chars: CHARS(NIL,char) */
		fprintf(stderr, "0x%lx: line 114: chars: CHARS(NIL,char)\n",(long)p);
#line 114 "minor.brg"
{}
		break;
	case 30: /* chars: CHARS(chars,char) */
		fprintf(stderr, "0x%lx: line 115: chars: CHARS(chars,char)\n",(long)p);
#line 115 "minor.brg"
{}
		break;
	case 31: /* char: INT */
		fprintf(stderr, "0x%lx: line 117: char: INT\n",(long)p);
#line 117 "minor.brg"
{ fprintf(yyout, pfIMM, p->value.i); }
		break;
	case 32: /* char: CHAR */
		fprintf(stderr, "0x%lx: line 118: char: CHAR\n",(long)p);
#line 118 "minor.brg"
{}
		break;
	case 33: /* char: STR */
		fprintf(stderr, "0x%lx: line 119: char: STR\n",(long)p);
#line 119 "minor.brg"
{ lbl++; fprintf(yyout, pfRODATA pfALIGN pfLABEL, mklbl(lbl)); outstr(p->value.s); fprintf(yyout, pfTEXT pfADDR, mklbl(lbl)); }
		break;
	case 34: /* eqvec: NIL */
		fprintf(stderr, "0x%lx: line 121: eqvec: NIL\n",(long)p);
#line 121 "minor.brg"
{}
		break;
	case 35: /* eqvec: ints */
		fprintf(stderr, "0x%lx: line 122: eqvec: ints\n",(long)p);
#line 122 "minor.brg"
{}
		break;
	case 36: /* ints: INT */
		fprintf(stderr, "0x%lx: line 124: ints: INT\n",(long)p);
#line 124 "minor.brg"
{}
		break;
	case 37: /* ints: INTS(ints,INT) */
		fprintf(stderr, "0x%lx: line 125: ints: INTS(ints,INT)\n",(long)p);
#line 125 "minor.brg"
{}
		break;
	case 38: /* eqbody: NIL */
		fprintf(stderr, "0x%lx: line 127: eqbody: NIL\n",(long)p);
#line 127 "minor.brg"
{}
		break;
	case 39: /* eqbody: body */
		fprintf(stderr, "0x%lx: line 128: eqbody: body\n",(long)p);
#line 128 "minor.brg"
{}
		break;
	case 40: /* main: START(fvars,instrs) */
		fprintf(stderr, "0x%lx: line 130: main: START(fvars,instrs)\n",(long)p);
#line 130 "minor.brg"
{}
		break;
	case 41: /* main: START(NIL,instrs) */
		fprintf(stderr, "0x%lx: line 131: main: START(NIL,instrs)\n",(long)p);
#line 131 "minor.brg"
{}
		break;
	case 42: /* body: START(fvars,STMT(instrs,ret)) */
		fprintf(stderr, "0x%lx: line 133: body: START(fvars,STMT(instrs,ret))\n",(long)p);
#line 133 "minor.brg"
{}
		break;
	case 43: /* body: START(NIL,STMT(instrs,ret)) */
		fprintf(stderr, "0x%lx: line 134: body: START(NIL,STMT(instrs,ret))\n",(long)p);
#line 134 "minor.brg"
{}
		break;
	case 44: /* ret: RETURN(NIL) */
		fprintf(stderr, "0x%lx: line 136: ret: RETURN(NIL)\n",(long)p);
#line 136 "minor.brg"
{}
		break;
	case 45: /* ret: RETURN(expr) */
		fprintf(stderr, "0x%lx: line 137: ret: RETURN(expr)\n",(long)p);
#line 137 "minor.brg"
{}
		break;
	case 46: /* ret: NIL */
		fprintf(stderr, "0x%lx: line 138: ret: NIL\n",(long)p);
#line 138 "minor.brg"
{}
		break;
	case 47: /* loop: ret */
		fprintf(stderr, "0x%lx: line 140: loop: ret\n",(long)p);
#line 140 "minor.brg"
{}
		break;
	case 48: /* loop: REPEAT */
		fprintf(stderr, "0x%lx: line 141: loop: REPEAT\n",(long)p);
#line 141 "minor.brg"
{}
		break;
	case 49: /* loop: STOP */
		fprintf(stderr, "0x%lx: line 142: loop: STOP\n",(long)p);
#line 142 "minor.brg"
{}
		break;
	case 50: /* block: STMT(instrs,loop) */
		fprintf(stderr, "0x%lx: line 144: block: STMT(instrs,loop)\n",(long)p);
#line 144 "minor.brg"
{}
		break;
	case 51: /* instrs: NIL */
		fprintf(stderr, "0x%lx: line 146: instrs: NIL\n",(long)p);
#line 146 "minor.brg"
{}
		break;
	case 52: /* instrs: STMT(instrs,instr) */
		fprintf(stderr, "0x%lx: line 147: instrs: STMT(instrs,instr)\n",(long)p);
#line 147 "minor.brg"
{}
		break;
	case 53: /* instr: FI(THEN(if,elifs),else) */
		fprintf(stderr, "0x%lx: line 149: instr: FI(THEN(if,elifs),else)\n",(long)p);
#line 149 "minor.brg"
{ fprintf(yyout, pfLABEL, mklbl(LEFT_CHILD(LEFT_CHILD(p))->place)); }
		break;
	case 54: /* instr: FOR(UNTIL(expr,expr),STEP(block,expr)) */
		fprintf(stderr, "0x%lx: line 150: instr: FOR(UNTIL(expr,expr),STEP(block,expr))\n",(long)p);
#line 150 "minor.brg"
{}
		break;
	case 55: /* instr: PRINT(expr) */
		fprintf(stderr, "0x%lx: line 151: instr: PRINT(expr)\n",(long)p);
#line 151 "minor.brg"
{ pfPrint(p->info); }
		break;
	case 56: /* instr: expr */
		fprintf(stderr, "0x%lx: line 152: instr: expr\n",(long)p);
#line 152 "minor.brg"
{ /* TODO */ fprintf(yyout, pfTRASH, pfWORD); }
		break;
	case 57: /* instr: ALLOC(alloc,lval) */
		fprintf(stderr, "0x%lx: line 153: instr: ALLOC(alloc,lval)\n",(long)p);
#line 153 "minor.brg"
{ fprintf(yyout, pfSTORE); }
		break;
	case 58: /* alloc: expr */
		fprintf(stderr, "0x%lx: line 154: alloc: expr\n",(long)p);
#line 154 "minor.brg"
{ fprintf(yyout, pfIMM pfMUL pfALLOC pfSP, pfWORD); }
		break;
	case 59: /* if: IF(cond,block) */
		fprintf(stderr, "0x%lx: line 156: if: IF(cond,block)\n",(long)p);
#line 156 "minor.brg"
{ p->place = ++lbl; eliflbl = p->place; fprintf(yyout, pfJMP pfLABEL, mklbl(p->place), mklbl(LEFT_CHILD(p)->place)); }
		break;
	case 60: /* ifelse: IF(cond,block) */
		fprintf(stderr, "0x%lx: line 157: ifelse: IF(cond,block)\n",(long)p);
#line 157 "minor.brg"

		break;
	case 61: /* cond: expr */
		fprintf(stderr, "0x%lx: line 159: cond: expr\n",(long)p);
#line 159 "minor.brg"
{ p->place = ++lbl; fprintf(yyout, pfJZ, mklbl(p->place)); }
		break;
	case 62: /* elifs: NIL */
		fprintf(stderr, "0x%lx: line 161: elifs: NIL\n",(long)p);
#line 161 "minor.brg"

		break;
	case 63: /* elifs: ELIF(elifs,ifelse) */
		fprintf(stderr, "0x%lx: line 162: elifs: ELIF(elifs,ifelse)\n",(long)p);
#line 162 "minor.brg"
{ p->place = eliflbl; fprintf(yyout, pfJMP pfLABEL, mklbl(p->place), mklbl(LEFT_CHILD(RIGHT_CHILD(p))->place)); }
		break;
	case 64: /* else: NIL */
		fprintf(stderr, "0x%lx: line 164: else: NIL\n",(long)p);
#line 164 "minor.brg"

		break;
	case 65: /* else: block */
		fprintf(stderr, "0x%lx: line 165: else: block\n",(long)p);
#line 165 "minor.brg"

		break;
	case 66: /* lval: ID */
		fprintf(stderr, "0x%lx: line 167: lval: ID\n",(long)p);
#line 167 "minor.brg"
{ fprintf(yyout, pfADDRV, p->value.s); }
		break;
	case 67: /* lval: INDEX(expr,ID) */
		fprintf(stderr, "0x%lx: line 168: lval: INDEX(expr,ID)\n",(long)p);
#line 168 "minor.brg"
{}
		break;
	case 68: /* expr: chars */
		fprintf(stderr, "0x%lx: line 170: expr: chars\n",(long)p);
#line 170 "minor.brg"
{}
		break;
	case 69: /* expr: lval */
		fprintf(stderr, "0x%lx: line 171: expr: lval\n",(long)p);
#line 171 "minor.brg"

		break;
	case 70: /* expr: ADDR(lval) */
		fprintf(stderr, "0x%lx: line 172: expr: ADDR(lval)\n",(long)p);
#line 172 "minor.brg"
{}
		break;
	case 71: /* expr: ADD(expr,expr) */
		fprintf(stderr, "0x%lx: line 173: expr: ADD(expr,expr)\n",(long)p);
#line 173 "minor.brg"
{ fprintf(yyout, pfADD); }
		break;
	case 72: /* expr: SUB(expr,expr) */
		fprintf(stderr, "0x%lx: line 174: expr: SUB(expr,expr)\n",(long)p);
#line 174 "minor.brg"
{ fprintf(yyout, pfSUB); }
		break;
	case 73: /* expr: MUL(expr,expr) */
		fprintf(stderr, "0x%lx: line 175: expr: MUL(expr,expr)\n",(long)p);
#line 175 "minor.brg"
{ fprintf(yyout, pfMUL); }
		break;
	case 74: /* expr: DIV(expr,expr) */
		fprintf(stderr, "0x%lx: line 176: expr: DIV(expr,expr)\n",(long)p);
#line 176 "minor.brg"
{ fprintf(yyout, pfDIV); }
		break;
	case 75: /* expr: MOD(expr,expr) */
		fprintf(stderr, "0x%lx: line 177: expr: MOD(expr,expr)\n",(long)p);
#line 177 "minor.brg"
{ fprintf(yyout, pfMOD); }
		break;
	case 76: /* expr: POW(expr,expr) */
		fprintf(stderr, "0x%lx: line 178: expr: POW(expr,expr)\n",(long)p);
#line 178 "minor.brg"
{}
		break;
	case 77: /* expr: EQU(expr,expr) */
		fprintf(stderr, "0x%lx: line 179: expr: EQU(expr,expr)\n",(long)p);
#line 179 "minor.brg"
{ fprintf(yyout, pfEQ); }
		break;
	case 78: /* expr: NE(expr,expr) */
		fprintf(stderr, "0x%lx: line 180: expr: NE(expr,expr)\n",(long)p);
#line 180 "minor.brg"
{ fprintf(yyout, pfNE); }
		break;
	case 79: /* expr: GE(expr,expr) */
		fprintf(stderr, "0x%lx: line 181: expr: GE(expr,expr)\n",(long)p);
#line 181 "minor.brg"
{ fprintf(yyout, pfGE); }
		break;
	case 80: /* expr: LE(expr,expr) */
		fprintf(stderr, "0x%lx: line 182: expr: LE(expr,expr)\n",(long)p);
#line 182 "minor.brg"
{ fprintf(yyout, pfLE); }
		break;
	case 81: /* expr: LT(expr,expr) */
		fprintf(stderr, "0x%lx: line 183: expr: LT(expr,expr)\n",(long)p);
#line 183 "minor.brg"
{ fprintf(yyout, pfLT); }
		break;
	case 82: /* expr: GT(expr,expr) */
		fprintf(stderr, "0x%lx: line 184: expr: GT(expr,expr)\n",(long)p);
#line 184 "minor.brg"
{ fprintf(yyout, pfGT); }
		break;
	case 83: /* expr: AND(expr,expr) */
		fprintf(stderr, "0x%lx: line 185: expr: AND(expr,expr)\n",(long)p);
#line 185 "minor.brg"
{}
		break;
	case 84: /* expr: OR(expr,expr) */
		fprintf(stderr, "0x%lx: line 186: expr: OR(expr,expr)\n",(long)p);
#line 186 "minor.brg"
{}
		break;
	case 85: /* expr: NOT(expr) */
		fprintf(stderr, "0x%lx: line 187: expr: NOT(expr)\n",(long)p);
#line 187 "minor.brg"
{ fprintf(yyout, pfIMM pfEQ, 0); }
		break;
	case 86: /* expr: UMINUS(expr) */
		fprintf(stderr, "0x%lx: line 188: expr: UMINUS(expr)\n",(long)p);
#line 188 "minor.brg"
{ fprintf(yyout, pfNEG); }
		break;
	case 87: /* expr: EQ(expr,lval) */
		fprintf(stderr, "0x%lx: line 189: expr: EQ(expr,lval)\n",(long)p);
#line 189 "minor.brg"
{}
		break;
	case 88: /* expr: IDARGS(ID,exprs) */
		fprintf(stderr, "0x%lx: line 190: expr: IDARGS(ID,exprs)\n",(long)p);
#line 190 "minor.brg"
{}
		break;
	case 89: /* exprs: COMMA(expr,NIL) */
		fprintf(stderr, "0x%lx: line 192: exprs: COMMA(expr,NIL)\n",(long)p);
#line 192 "minor.brg"
{}
		break;
	case 90: /* exprs: COMMA(expr,exprs) */
		fprintf(stderr, "0x%lx: line 193: exprs: COMMA(expr,exprs)\n",(long)p);
#line 193 "minor.brg"
{}
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


#line 195 "minor.brg"

extern char **yynames;
extern int trace, errors, debugNode;
void evaluate(Node *p) {
	if (errors) return;
    if (trace) printNode(p, stdout, yynames);
    fprintf(yyout, pfTEXT pfALIGN pfGLOBL pfLABEL, "_main", pfFUNC, "_main");
	if (!yyselect(p) && trace) printf("selection successful\n");
    fprintf(yyout, pfIMM pfPOP pfRET pfDATA, 0);
    fprintf(yyout, pfEXTRN pfEXTRN pfEXTRN pfEXTRN, "_prints", "_printi", "_println", "_readi");
}

void variable(Node *p) {
	fprintf(yyout, pfGLOBL pfDATA pfALIGN pfLABEL, LEFT_CHILD(p)->value.s, pfOBJ, LEFT_CHILD(p)->value.s);
	if (p->info == tINT)
		fprintf(yyout, pfINTEGER, RIGHT_CHILD(p)->value.i);
	if (p->info == tSTR) {
		char *l = mklbl(++lbl);
		fprintf(yyout, pfRODATA pfALIGN pfLABEL, l);
		outchars(RIGHT_CHILD(p));
		fprintf(yyout, pfDATA pfID, l);
	}
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
