/*
generated at Sat May 16 19:20:19 2020
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
static void outstr(char *s) {
  while (*s) fprintf(yyout, pfCHAR, (unsigned char)*s++);
  fprintf(yyout, pfCHAR, 0);
}
/* expr: falta '?', falta const type ftype */
/* expr: expr */
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
#define yychars_NT 14
#define yychar_NT 15
#define yyints_NT 16
#define yybody_NT 17
#define yyinstrs_NT 18
#define yyret_NT 19
#define yyexpr_NT 20
#define yyloop_NT 21
#define yyblock_NT 22
#define yyinstr_NT 23
#define yyelifs_NT 24
#define yyelse_NT 25
#define yyalloc_NT 26
#define yylval_NT 27
#define yyexprs_NT 28

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
	"elifs",
	"else",
	"alloc",
	"lval",
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
	short cost[29];
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
		unsigned int yyelifs:2;
		unsigned int yyelse:2;
		unsigned int yyalloc:1;
		unsigned int yylval:2;
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
static short yynts_15[] = { yychars_NT, 0 };
static short yynts_16[] = { yychar_NT, 0 };
static short yynts_17[] = { yychars_NT, yychar_NT, 0 };
static short yynts_18[] = { yyints_NT, 0 };
static short yynts_19[] = { yybody_NT, 0 };
static short yynts_20[] = { yyfvars_NT, yyinstrs_NT, 0 };
static short yynts_21[] = { yyinstrs_NT, 0 };
static short yynts_22[] = { yyfvars_NT, yyinstrs_NT, yyret_NT, 0 };
static short yynts_23[] = { yyinstrs_NT, yyret_NT, 0 };
static short yynts_24[] = { yyexpr_NT, 0 };
static short yynts_25[] = { yyret_NT, 0 };
static short yynts_26[] = { yyinstrs_NT, yyloop_NT, 0 };
static short yynts_27[] = { yyinstrs_NT, yyinstr_NT, 0 };
static short yynts_28[] = { yyexpr_NT, yyblock_NT, yyelifs_NT, yyelse_NT, 0 };
static short yynts_29[] = { yyexpr_NT, yyexpr_NT, yyblock_NT, yyexpr_NT, 0 };
static short yynts_30[] = { yyalloc_NT, yylval_NT, 0 };
static short yynts_31[] = { yyelifs_NT, yyexpr_NT, yyblock_NT, 0 };
static short yynts_32[] = { yyblock_NT, 0 };
static short yynts_33[] = { yylval_NT, 0 };
static short yynts_34[] = { yyexpr_NT, yyexpr_NT, 0 };
static short yynts_35[] = { yyexpr_NT, yylval_NT, 0 };
static short yynts_36[] = { yyexprs_NT, 0 };
static short yynts_37[] = { yyexpr_NT, yyexprs_NT, 0 };

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
	yynts_2,	/* 29 */
	yynts_18,	/* 30 */
	yynts_2,	/* 31 */
	yynts_18,	/* 32 */
	yynts_2,	/* 33 */
	yynts_19,	/* 34 */
	yynts_20,	/* 35 */
	yynts_21,	/* 36 */
	yynts_22,	/* 37 */
	yynts_23,	/* 38 */
	yynts_2,	/* 39 */
	yynts_24,	/* 40 */
	yynts_2,	/* 41 */
	yynts_25,	/* 42 */
	yynts_2,	/* 43 */
	yynts_2,	/* 44 */
	yynts_26,	/* 45 */
	yynts_2,	/* 46 */
	yynts_27,	/* 47 */
	yynts_28,	/* 48 */
	yynts_29,	/* 49 */
	yynts_24,	/* 50 */
	yynts_24,	/* 51 */
	yynts_30,	/* 52 */
	yynts_24,	/* 53 */
	yynts_2,	/* 54 */
	yynts_31,	/* 55 */
	yynts_2,	/* 56 */
	yynts_32,	/* 57 */
	yynts_2,	/* 58 */
	yynts_24,	/* 59 */
	yynts_15,	/* 60 */
	yynts_33,	/* 61 */
	yynts_33,	/* 62 */
	yynts_34,	/* 63 */
	yynts_34,	/* 64 */
	yynts_34,	/* 65 */
	yynts_34,	/* 66 */
	yynts_34,	/* 67 */
	yynts_34,	/* 68 */
	yynts_34,	/* 69 */
	yynts_34,	/* 70 */
	yynts_34,	/* 71 */
	yynts_34,	/* 72 */
	yynts_34,	/* 73 */
	yynts_34,	/* 74 */
	yynts_34,	/* 75 */
	yynts_34,	/* 76 */
	yynts_24,	/* 77 */
	yynts_24,	/* 78 */
	yynts_35,	/* 79 */
	yynts_36,	/* 80 */
	yynts_24,	/* 81 */
	yynts_37,	/* 82 */
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
/* 23 */	"eqstr: chars",
/* 24 */	"chars: CHARS(NIL,char)",
/* 25 */	"chars: CHARS(chars,char)",
/* 26 */	"char: INT",
/* 27 */	"char: CHAR",
/* 28 */	"char: STR",
/* 29 */	"eqvec: NIL",
/* 30 */	"eqvec: ints",
/* 31 */	"ints: INT",
/* 32 */	"ints: INTS(ints,INT)",
/* 33 */	"eqbody: NIL",
/* 34 */	"eqbody: body",
/* 35 */	"main: START(fvars,instrs)",
/* 36 */	"main: START(NIL,instrs)",
/* 37 */	"body: START(fvars,STMT(instrs,ret))",
/* 38 */	"body: START(NIL,STMT(instrs,ret))",
/* 39 */	"ret: RETURN(NIL)",
/* 40 */	"ret: RETURN(expr)",
/* 41 */	"ret: NIL",
/* 42 */	"loop: ret",
/* 43 */	"loop: REPEAT",
/* 44 */	"loop: STOP",
/* 45 */	"block: STMT(instrs,loop)",
/* 46 */	"instrs: NIL",
/* 47 */	"instrs: STMT(instrs,instr)",
/* 48 */	"instr: FI(THEN(IF(expr,block),elifs),else)",
/* 49 */	"instr: FOR(UNTIL(expr,expr),STEP(block,expr))",
/* 50 */	"instr: PRINT(expr)",
/* 51 */	"instr: expr",
/* 52 */	"instr: ALLOC(alloc,lval)",
/* 53 */	"alloc: expr",
/* 54 */	"elifs: NIL",
/* 55 */	"elifs: ELIF(elifs,IF(expr,block))",
/* 56 */	"else: NIL",
/* 57 */	"else: block",
/* 58 */	"lval: ID",
/* 59 */	"lval: INDEX(expr,ID)",
/* 60 */	"expr: chars",
/* 61 */	"expr: lval",
/* 62 */	"expr: ADDR(lval)",
/* 63 */	"expr: ADD(expr,expr)",
/* 64 */	"expr: SUB(expr,expr)",
/* 65 */	"expr: MUL(expr,expr)",
/* 66 */	"expr: DIV(expr,expr)",
/* 67 */	"expr: MOD(expr,expr)",
/* 68 */	"expr: POW(expr,expr)",
/* 69 */	"expr: EQU(expr,expr)",
/* 70 */	"expr: NE(expr,expr)",
/* 71 */	"expr: GE(expr,expr)",
/* 72 */	"expr: LE(expr,expr)",
/* 73 */	"expr: LT(expr,expr)",
/* 74 */	"expr: GT(expr,expr)",
/* 75 */	"expr: AND(expr,expr)",
/* 76 */	"expr: OR(expr,expr)",
/* 77 */	"expr: NOT(expr)",
/* 78 */	"expr: UMINUS(expr)",
/* 79 */	"expr: EQ(expr,lval)",
/* 80 */	"expr: IDARGS(ID,exprs)",
/* 81 */	"exprs: COMMA(expr,NIL)",
/* 82 */	"exprs: COMMA(expr,exprs)",
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
	35,
	36,
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
	33,
	34,
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
	29,
	30,
};

static short yydecode_chars[] = {
	0,
	24,
	25,
};

static short yydecode_char[] = {
	0,
	26,
	27,
	28,
};

static short yydecode_ints[] = {
	0,
	31,
	32,
};

static short yydecode_body[] = {
	0,
	37,
	38,
};

static short yydecode_instrs[] = {
	0,
	46,
	47,
};

static short yydecode_ret[] = {
	0,
	39,
	40,
	41,
};

static short yydecode_expr[] = {
	0,
	60,
	61,
	62,
	63,
	64,
	65,
	66,
	67,
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
};

static short yydecode_loop[] = {
	0,
	42,
	43,
	44,
};

static short yydecode_block[] = {
	0,
	45,
};

static short yydecode_instr[] = {
	0,
	48,
	49,
	50,
	51,
	52,
};

static short yydecode_elifs[] = {
	0,
	54,
	55,
};

static short yydecode_else[] = {
	0,
	56,
	57,
};

static short yydecode_alloc[] = {
	0,
	53,
};

static short yydecode_lval[] = {
	0,
	58,
	59,
};

static short yydecode_exprs[] = {
	0,
	81,
	82,
};

static int yyrule(void *state, int goalnt) {
	if (goalnt < 1 || goalnt > 28)
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
	case yyelifs_NT:	return yydecode_elifs[((struct yystate *)state)->rule.yyelifs];
	case yyelse_NT:	return yydecode_else[((struct yystate *)state)->rule.yyelse];
	case yyalloc_NT:	return yydecode_alloc[((struct yystate *)state)->rule.yyalloc];
	case yylval_NT:	return yydecode_lval[((struct yystate *)state)->rule.yylval];
	case yyexprs_NT:	return yydecode_exprs[((struct yystate *)state)->rule.yyexprs];
	default:
		PANIC("yyrule", "Bad goal nonterminal", goalnt);
		return 0;
	}
}

static void yyclosure_gdecls(NODEPTR_TYPE, int);
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

static void yyclosure_chars(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 60, c + 1, p->cost[yyexpr_NT]);
	if (c + 1 < p->cost[yyexpr_NT]) {
		p->cost[yyexpr_NT] = c + 1;
		p->rule.yyexpr = 1;
		yyclosure_expr(a, c + 1);
	}
	yytrace(a, 23, c + 1, p->cost[yyeqstr_NT]);
	if (c + 1 < p->cost[yyeqstr_NT]) {
		p->cost[yyeqstr_NT] = c + 1;
		p->rule.yyeqstr = 2;
	}
}

static void yyclosure_ints(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 30, c + 1, p->cost[yyeqvec_NT]);
	if (c + 1 < p->cost[yyeqvec_NT]) {
		p->cost[yyeqvec_NT] = c + 1;
		p->rule.yyeqvec = 2;
	}
}

static void yyclosure_body(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 34, c + 1, p->cost[yyeqbody_NT]);
	if (c + 1 < p->cost[yyeqbody_NT]) {
		p->cost[yyeqbody_NT] = c + 1;
		p->rule.yyeqbody = 2;
	}
}

static void yyclosure_ret(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 42, c + 1, p->cost[yyloop_NT]);
	if (c + 1 < p->cost[yyloop_NT]) {
		p->cost[yyloop_NT] = c + 1;
		p->rule.yyloop = 1;
	}
}

static void yyclosure_expr(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 53, c + 1, p->cost[yyalloc_NT]);
	if (c + 1 < p->cost[yyalloc_NT]) {
		p->cost[yyalloc_NT] = c + 1;
		p->rule.yyalloc = 1;
	}
	yytrace(a, 51, c + 1, p->cost[yyinstr_NT]);
	if (c + 1 < p->cost[yyinstr_NT]) {
		p->cost[yyinstr_NT] = c + 1;
		p->rule.yyinstr = 4;
	}
}

static void yyclosure_block(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 57, c + 1, p->cost[yyelse_NT]);
	if (c + 1 < p->cost[yyelse_NT]) {
		p->cost[yyelse_NT] = c + 1;
		p->rule.yyelse = 2;
	}
}

static void yyclosure_lval(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 61, c + 0, p->cost[yyexpr_NT]);
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
		0x7fff;
	switch (OP_LABEL(a)) {
	case 33: /* PRINT */
		yylabel(LEFT_CHILD(a),a);
		/* instr: PRINT(expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + 3;
		yytrace(a, 50, c + 0, p->cost[yyinstr_NT]);
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
		yytrace(a, 52, c + 0, p->cost[yyinstr_NT]);
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
		yytrace(a, 67, c + 0, p->cost[yyexpr_NT]);
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
		yytrace(a, 75, c + 0, p->cost[yyexpr_NT]);
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
			yytrace(a, 80, c + 0, p->cost[yyexpr_NT]);
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
		yytrace(a, 65, c + 0, p->cost[yyexpr_NT]);
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
		yytrace(a, 63, c + 0, p->cost[yyexpr_NT]);
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
			yytrace(a, 81, c + 0, p->cost[yyexprs_NT]);
			if (c + 0 < p->cost[yyexprs_NT]) {
				p->cost[yyexprs_NT] = c + 0;
				p->rule.yyexprs = 1;
			}
		}
		/* exprs: COMMA(expr,exprs) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexprs_NT] + 1;
		yytrace(a, 82, c + 0, p->cost[yyexprs_NT]);
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
		yytrace(a, 64, c + 0, p->cost[yyexpr_NT]);
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
		yytrace(a, 66, c + 0, p->cost[yyexpr_NT]);
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
		yytrace(a, 45, c + 0, p->cost[yyblock_NT]);
		if (c + 0 < p->cost[yyblock_NT]) {
			p->cost[yyblock_NT] = c + 0;
			p->rule.yyblock = 1;
			yyclosure_block(a, c + 0);
		}
		/* instrs: STMT(instrs,instr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyinstrs_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyinstr_NT] + 1;
		yytrace(a, 47, c + 0, p->cost[yyinstrs_NT]);
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
		yytrace(a, 73, c + 0, p->cost[yyexpr_NT]);
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
		yytrace(a, 69, c + 0, p->cost[yyexpr_NT]);
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
		yytrace(a, 74, c + 0, p->cost[yyexpr_NT]);
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
			yytrace(a, 59, c + 0, p->cost[yylval_NT]);
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
		yytrace(a, 68, c + 0, p->cost[yyexpr_NT]);
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
		yytrace(a, 76, c + 0, p->cost[yyexpr_NT]);
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
		yytrace(a, 77, c + 0, p->cost[yyexpr_NT]);
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
		/* char: INT */
		yytrace(a, 26, 1 + 0, p->cost[yychar_NT]);
		if (1 + 0 < p->cost[yychar_NT]) {
			p->cost[yychar_NT] = 1 + 0;
			p->rule.yychar = 1;
		}
		/* ints: INT */
		yytrace(a, 31, 1 + 0, p->cost[yyints_NT]);
		if (1 + 0 < p->cost[yyints_NT]) {
			p->cost[yyints_NT] = 1 + 0;
			p->rule.yyints = 1;
			yyclosure_ints(a, 1 + 0);
		}
		break;
	case 258: /* CHAR */
		/* char: CHAR */
		yytrace(a, 27, 1 + 0, p->cost[yychar_NT]);
		if (1 + 0 < p->cost[yychar_NT]) {
			p->cost[yychar_NT] = 1 + 0;
			p->rule.yychar = 2;
		}
		break;
	case 259: /* ID */
		/* lval: ID */
		yytrace(a, 58, 1 + 0, p->cost[yylval_NT]);
		if (1 + 0 < p->cost[yylval_NT]) {
			p->cost[yylval_NT] = 1 + 0;
			p->rule.yylval = 1;
			yyclosure_lval(a, 1 + 0);
		}
		break;
	case 260: /* STR */
		/* char: STR */
		yytrace(a, 28, 1 + 0, p->cost[yychar_NT]);
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
		return;
	case 273: /* THEN */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		return;
	case 274: /* FI */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		if (	/* instr: FI(THEN(IF(expr,block),elifs),else) */
			OP_LABEL(LEFT_CHILD(a)) == 273 && /* THEN */
			OP_LABEL(LEFT_CHILD(LEFT_CHILD(a))) == 272 /* IF */
		) {
			c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(LEFT_CHILD(LEFT_CHILD(a)))))->cost[yyexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(LEFT_CHILD(LEFT_CHILD(a)))))->cost[yyblock_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(LEFT_CHILD(a))))->cost[yyelifs_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyelse_NT] + 1;
			yytrace(a, 48, c + 0, p->cost[yyinstr_NT]);
			if (c + 0 < p->cost[yyinstr_NT]) {
				p->cost[yyinstr_NT] = c + 0;
				p->rule.yyinstr = 1;
			}
		}
		break;
	case 275: /* ELIF */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		if (	/* elifs: ELIF(elifs,IF(expr,block)) */
			OP_LABEL(RIGHT_CHILD(a)) == 272 /* IF */
		) {
			c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyelifs_NT] + ((struct yystate *)STATE_LABEL(LEFT_CHILD(RIGHT_CHILD(a))))->cost[yyexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(RIGHT_CHILD(a))))->cost[yyblock_NT] + 1;
			yytrace(a, 55, c + 0, p->cost[yyelifs_NT]);
			if (c + 0 < p->cost[yyelifs_NT]) {
				p->cost[yyelifs_NT] = c + 0;
				p->rule.yyelifs = 2;
			}
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
			yytrace(a, 39, c + 0, p->cost[yyret_NT]);
			if (c + 0 < p->cost[yyret_NT]) {
				p->cost[yyret_NT] = c + 0;
				p->rule.yyret = 1;
				yyclosure_ret(a, c + 0);
			}
		}
		/* ret: RETURN(expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 40, c + 0, p->cost[yyret_NT]);
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
		yytrace(a, 35, c + 0, p->cost[yymain_NT]);
		if (c + 0 < p->cost[yymain_NT]) {
			p->cost[yymain_NT] = c + 0;
			p->rule.yymain = 1;
		}
		if (	/* main: START(NIL,instrs) */
			OP_LABEL(LEFT_CHILD(a)) == 293 /* NIL */
		) {
			c = ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyinstrs_NT] + 1;
			yytrace(a, 36, c + 0, p->cost[yymain_NT]);
			if (c + 0 < p->cost[yymain_NT]) {
				p->cost[yymain_NT] = c + 0;
				p->rule.yymain = 2;
			}
		}
		if (	/* body: START(fvars,STMT(instrs,ret)) */
			OP_LABEL(RIGHT_CHILD(a)) == 59 /* STMT */
		) {
			c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyfvars_NT] + ((struct yystate *)STATE_LABEL(LEFT_CHILD(RIGHT_CHILD(a))))->cost[yyinstrs_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(RIGHT_CHILD(a))))->cost[yyret_NT] + 1;
			yytrace(a, 37, c + 0, p->cost[yybody_NT]);
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
			yytrace(a, 38, c + 0, p->cost[yybody_NT]);
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
			yytrace(a, 49, c + 0, p->cost[yyinstr_NT]);
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
		yytrace(a, 43, 1 + 0, p->cost[yyloop_NT]);
		if (1 + 0 < p->cost[yyloop_NT]) {
			p->cost[yyloop_NT] = 1 + 0;
			p->rule.yyloop = 2;
		}
		break;
	case 285: /* STOP */
		/* loop: STOP */
		yytrace(a, 44, 1 + 0, p->cost[yyloop_NT]);
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
		if (	/* chars: CHARS(NIL,char) */
			OP_LABEL(LEFT_CHILD(a)) == 293 /* NIL */
		) {
			c = ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yychar_NT] + 1;
			yytrace(a, 24, c + 0, p->cost[yychars_NT]);
			if (c + 0 < p->cost[yychars_NT]) {
				p->cost[yychars_NT] = c + 0;
				p->rule.yychars = 1;
				yyclosure_chars(a, c + 0);
			}
		}
		/* chars: CHARS(chars,char) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yychars_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yychar_NT] + 1;
		yytrace(a, 25, c + 0, p->cost[yychars_NT]);
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
			yytrace(a, 32, c + 0, p->cost[yyints_NT]);
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
		yytrace(a, 62, c + 0, p->cost[yyexpr_NT]);
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
		yytrace(a, 29, 1 + 0, p->cost[yyeqvec_NT]);
		if (1 + 0 < p->cost[yyeqvec_NT]) {
			p->cost[yyeqvec_NT] = 1 + 0;
			p->rule.yyeqvec = 1;
		}
		/* eqbody: NIL */
		yytrace(a, 33, 1 + 0, p->cost[yyeqbody_NT]);
		if (1 + 0 < p->cost[yyeqbody_NT]) {
			p->cost[yyeqbody_NT] = 1 + 0;
			p->rule.yyeqbody = 1;
		}
		/* ret: NIL */
		yytrace(a, 41, 1 + 0, p->cost[yyret_NT]);
		if (1 + 0 < p->cost[yyret_NT]) {
			p->cost[yyret_NT] = 1 + 0;
			p->rule.yyret = 3;
			yyclosure_ret(a, 1 + 0);
		}
		/* instrs: NIL */
		yytrace(a, 46, 1 + 0, p->cost[yyinstrs_NT]);
		if (1 + 0 < p->cost[yyinstrs_NT]) {
			p->cost[yyinstrs_NT] = 1 + 0;
			p->rule.yyinstrs = 1;
		}
		/* elifs: NIL */
		yytrace(a, 54, 1 + 0, p->cost[yyelifs_NT]);
		if (1 + 0 < p->cost[yyelifs_NT]) {
			p->cost[yyelifs_NT] = 1 + 0;
			p->rule.yyelifs = 1;
		}
		/* else: NIL */
		yytrace(a, 56, 1 + 0, p->cost[yyelse_NT]);
		if (1 + 0 < p->cost[yyelse_NT]) {
			p->cost[yyelse_NT] = 1 + 0;
			p->rule.yyelse = 1;
		}
		break;
	case 294: /* EQ */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expr: EQ(expr,lval) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yylval_NT] + 1;
		yytrace(a, 79, c + 0, p->cost[yyexpr_NT]);
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
		yytrace(a, 70, c + 0, p->cost[yyexpr_NT]);
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
		yytrace(a, 71, c + 0, p->cost[yyexpr_NT]);
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
		yytrace(a, 72, c + 0, p->cost[yyexpr_NT]);
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
		yytrace(a, 78, c + 0, p->cost[yyexpr_NT]);
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
	case 81: /* exprs: COMMA(expr,NIL) */
	case 78: /* expr: UMINUS(expr) */
	case 77: /* expr: NOT(expr) */
	case 62: /* expr: ADDR(lval) */
	case 59: /* lval: INDEX(expr,ID) */
	case 50: /* instr: PRINT(expr) */
	case 40: /* ret: RETURN(expr) */
	case 32: /* ints: INTS(ints,INT) */
	case 7: /* decl: VAR(vardecl) */
	case 2: /* program: MODULE(decls) */
		kids[0] = LEFT_CHILD(p);
		break;
	case 58: /* lval: ID */
	case 56: /* else: NIL */
	case 54: /* elifs: NIL */
	case 46: /* instrs: NIL */
	case 44: /* loop: STOP */
	case 43: /* loop: REPEAT */
	case 41: /* ret: NIL */
	case 39: /* ret: RETURN(NIL) */
	case 33: /* eqbody: NIL */
	case 31: /* ints: INT */
	case 29: /* eqvec: NIL */
	case 28: /* char: STR */
	case 27: /* char: CHAR */
	case 26: /* char: INT */
	case 22: /* eqstr: NIL */
	case 21: /* eqint: INT */
	case 20: /* eqint: NIL */
	case 19: /* vdim: INT */
	case 18: /* vdim: NIL */
	case 11: /* fvar: STRING(ID,NIL) */
	case 10: /* fvar: NUMBER(ID,NIL) */
	case 3: /* decls: NIL */
		break;
	case 61: /* expr: lval */
	case 60: /* expr: chars */
	case 57: /* else: block */
	case 53: /* alloc: expr */
	case 51: /* instr: expr */
	case 42: /* loop: ret */
	case 34: /* eqbody: body */
	case 30: /* eqvec: ints */
	case 23: /* eqstr: chars */
	case 4: /* decls: gdecls */
		kids[0] = p;
		break;
	case 82: /* exprs: COMMA(expr,exprs) */
	case 79: /* expr: EQ(expr,lval) */
	case 76: /* expr: OR(expr,expr) */
	case 75: /* expr: AND(expr,expr) */
	case 74: /* expr: GT(expr,expr) */
	case 73: /* expr: LT(expr,expr) */
	case 72: /* expr: LE(expr,expr) */
	case 71: /* expr: GE(expr,expr) */
	case 70: /* expr: NE(expr,expr) */
	case 69: /* expr: EQU(expr,expr) */
	case 68: /* expr: POW(expr,expr) */
	case 67: /* expr: MOD(expr,expr) */
	case 66: /* expr: DIV(expr,expr) */
	case 65: /* expr: MUL(expr,expr) */
	case 64: /* expr: SUB(expr,expr) */
	case 63: /* expr: ADD(expr,expr) */
	case 52: /* instr: ALLOC(alloc,lval) */
	case 47: /* instrs: STMT(instrs,instr) */
	case 45: /* block: STMT(instrs,loop) */
	case 35: /* main: START(fvars,instrs) */
	case 25: /* chars: CHARS(chars,char) */
	case 14: /* fvars: ARGS(fvars,fvar) */
	case 5: /* gdecls: DECL(gdecls,decl) */
		kids[0] = LEFT_CHILD(p);
		kids[1] = RIGHT_CHILD(p);
		break;
	case 80: /* expr: IDARGS(ID,exprs) */
	case 36: /* main: START(NIL,instrs) */
	case 24: /* chars: CHARS(NIL,char) */
	case 16: /* vardecl: STRING(ID,eqstr) */
	case 15: /* vardecl: NUMBER(ID,eqint) */
	case 13: /* fvars: ARGS(NIL,fvar) */
	case 6: /* gdecls: DECL(NIL,decl) */
		kids[0] = RIGHT_CHILD(p);
		break;
	case 38: /* body: START(NIL,STMT(instrs,ret)) */
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
	case 55: /* elifs: ELIF(elifs,IF(expr,block)) */
	case 37: /* body: START(fvars,STMT(instrs,ret)) */
		kids[0] = LEFT_CHILD(p);
		kids[1] = LEFT_CHILD(RIGHT_CHILD(p));
		kids[2] = RIGHT_CHILD(RIGHT_CHILD(p));
		break;
	case 48: /* instr: FI(THEN(IF(expr,block),elifs),else) */
		kids[0] = LEFT_CHILD(LEFT_CHILD(LEFT_CHILD(p)));
		kids[1] = RIGHT_CHILD(LEFT_CHILD(LEFT_CHILD(p)));
		kids[2] = RIGHT_CHILD(LEFT_CHILD(p));
		kids[3] = RIGHT_CHILD(p);
		break;
	case 49: /* instr: FOR(UNTIL(expr,expr),STEP(block,expr)) */
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
		fprintf(stderr, "0x%lx: line 46: program: PROGRAM(decls,FUNCTION(END(ID,INT),FARGS(NIL,main)))\n",(long)p);
#line 46 "minor.brg"
{}
		break;
	case 2: /* program: MODULE(decls) */
		fprintf(stderr, "0x%lx: line 47: program: MODULE(decls)\n",(long)p);
#line 47 "minor.brg"
{}
		break;
	case 3: /* decls: NIL */
		fprintf(stderr, "0x%lx: line 49: decls: NIL\n",(long)p);
#line 49 "minor.brg"
{}
		break;
	case 4: /* decls: gdecls */
		fprintf(stderr, "0x%lx: line 50: decls: gdecls\n",(long)p);
#line 50 "minor.brg"
{}
		break;
	case 5: /* gdecls: DECL(gdecls,decl) */
		fprintf(stderr, "0x%lx: line 52: gdecls: DECL(gdecls,decl)\n",(long)p);
#line 52 "minor.brg"
{}
		break;
	case 6: /* gdecls: DECL(NIL,decl) */
		fprintf(stderr, "0x%lx: line 53: gdecls: DECL(NIL,decl)\n",(long)p);
#line 53 "minor.brg"
{}
		break;
	case 7: /* decl: VAR(vardecl) */
		fprintf(stderr, "0x%lx: line 55: decl: VAR(vardecl)\n",(long)p);
#line 55 "minor.brg"
{}
		break;
	case 8: /* decl: FUNCTION(END(ID,INT),FARGS(fvars,eqbody)) */
		fprintf(stderr, "0x%lx: line 56: decl: FUNCTION(END(ID,INT),FARGS(fvars,eqbody))\n",(long)p);
#line 56 "minor.brg"
{}
		break;
	case 9: /* decl: FUNCTION(END(ID,INT),FARGS(NIL,eqbody)) */
		fprintf(stderr, "0x%lx: line 57: decl: FUNCTION(END(ID,INT),FARGS(NIL,eqbody))\n",(long)p);
#line 57 "minor.brg"
{}
		break;
	case 10: /* fvar: NUMBER(ID,NIL) */
		fprintf(stderr, "0x%lx: line 59: fvar: NUMBER(ID,NIL)\n",(long)p);
#line 59 "minor.brg"
{}
		break;
	case 11: /* fvar: STRING(ID,NIL) */
		fprintf(stderr, "0x%lx: line 60: fvar: STRING(ID,NIL)\n",(long)p);
#line 60 "minor.brg"
{}
		break;
	case 12: /* fvar: ARRAY(ID,INTS(vdim,NIL)) */
		fprintf(stderr, "0x%lx: line 61: fvar: ARRAY(ID,INTS(vdim,NIL))\n",(long)p);
#line 61 "minor.brg"
{}
		break;
	case 13: /* fvars: ARGS(NIL,fvar) */
		fprintf(stderr, "0x%lx: line 63: fvars: ARGS(NIL,fvar)\n",(long)p);
#line 63 "minor.brg"
{}
		break;
	case 14: /* fvars: ARGS(fvars,fvar) */
		fprintf(stderr, "0x%lx: line 64: fvars: ARGS(fvars,fvar)\n",(long)p);
#line 64 "minor.brg"
{}
		break;
	case 15: /* vardecl: NUMBER(ID,eqint) */
		fprintf(stderr, "0x%lx: line 66: vardecl: NUMBER(ID,eqint)\n",(long)p);
#line 66 "minor.brg"
{}
		break;
	case 16: /* vardecl: STRING(ID,eqstr) */
		fprintf(stderr, "0x%lx: line 67: vardecl: STRING(ID,eqstr)\n",(long)p);
#line 67 "minor.brg"
{}
		break;
	case 17: /* vardecl: ARRAY(ID,INTS(vdim,eqvec)) */
		fprintf(stderr, "0x%lx: line 68: vardecl: ARRAY(ID,INTS(vdim,eqvec))\n",(long)p);
#line 68 "minor.brg"
{}
		break;
	case 18: /* vdim: NIL */
		fprintf(stderr, "0x%lx: line 70: vdim: NIL\n",(long)p);
#line 70 "minor.brg"
{}
		break;
	case 19: /* vdim: INT */
		fprintf(stderr, "0x%lx: line 71: vdim: INT\n",(long)p);
#line 71 "minor.brg"
{}
		break;
	case 20: /* eqint: NIL */
		fprintf(stderr, "0x%lx: line 73: eqint: NIL\n",(long)p);
#line 73 "minor.brg"
{}
		break;
	case 21: /* eqint: INT */
		fprintf(stderr, "0x%lx: line 74: eqint: INT\n",(long)p);
#line 74 "minor.brg"
{}
		break;
	case 22: /* eqstr: NIL */
		fprintf(stderr, "0x%lx: line 76: eqstr: NIL\n",(long)p);
#line 76 "minor.brg"
{}
		break;
	case 23: /* eqstr: chars */
		fprintf(stderr, "0x%lx: line 77: eqstr: chars\n",(long)p);
#line 77 "minor.brg"
{}
		break;
	case 24: /* chars: CHARS(NIL,char) */
		fprintf(stderr, "0x%lx: line 79: chars: CHARS(NIL,char)\n",(long)p);
#line 79 "minor.brg"
{}
		break;
	case 25: /* chars: CHARS(chars,char) */
		fprintf(stderr, "0x%lx: line 80: chars: CHARS(chars,char)\n",(long)p);
#line 80 "minor.brg"
{}
		break;
	case 26: /* char: INT */
		fprintf(stderr, "0x%lx: line 82: char: INT\n",(long)p);
#line 82 "minor.brg"
{ fprintf(yyout, pfIMM, p->value.i); }
		break;
	case 27: /* char: CHAR */
		fprintf(stderr, "0x%lx: line 83: char: CHAR\n",(long)p);
#line 83 "minor.brg"
{}
		break;
	case 28: /* char: STR */
		fprintf(stderr, "0x%lx: line 84: char: STR\n",(long)p);
#line 84 "minor.brg"
{}
		break;
	case 29: /* eqvec: NIL */
		fprintf(stderr, "0x%lx: line 86: eqvec: NIL\n",(long)p);
#line 86 "minor.brg"
{}
		break;
	case 30: /* eqvec: ints */
		fprintf(stderr, "0x%lx: line 87: eqvec: ints\n",(long)p);
#line 87 "minor.brg"
{}
		break;
	case 31: /* ints: INT */
		fprintf(stderr, "0x%lx: line 89: ints: INT\n",(long)p);
#line 89 "minor.brg"
{}
		break;
	case 32: /* ints: INTS(ints,INT) */
		fprintf(stderr, "0x%lx: line 90: ints: INTS(ints,INT)\n",(long)p);
#line 90 "minor.brg"
{}
		break;
	case 33: /* eqbody: NIL */
		fprintf(stderr, "0x%lx: line 92: eqbody: NIL\n",(long)p);
#line 92 "minor.brg"
{}
		break;
	case 34: /* eqbody: body */
		fprintf(stderr, "0x%lx: line 93: eqbody: body\n",(long)p);
#line 93 "minor.brg"
{}
		break;
	case 35: /* main: START(fvars,instrs) */
		fprintf(stderr, "0x%lx: line 95: main: START(fvars,instrs)\n",(long)p);
#line 95 "minor.brg"
{}
		break;
	case 36: /* main: START(NIL,instrs) */
		fprintf(stderr, "0x%lx: line 96: main: START(NIL,instrs)\n",(long)p);
#line 96 "minor.brg"
{}
		break;
	case 37: /* body: START(fvars,STMT(instrs,ret)) */
		fprintf(stderr, "0x%lx: line 98: body: START(fvars,STMT(instrs,ret))\n",(long)p);
#line 98 "minor.brg"
{}
		break;
	case 38: /* body: START(NIL,STMT(instrs,ret)) */
		fprintf(stderr, "0x%lx: line 99: body: START(NIL,STMT(instrs,ret))\n",(long)p);
#line 99 "minor.brg"
{}
		break;
	case 39: /* ret: RETURN(NIL) */
		fprintf(stderr, "0x%lx: line 101: ret: RETURN(NIL)\n",(long)p);
#line 101 "minor.brg"
{}
		break;
	case 40: /* ret: RETURN(expr) */
		fprintf(stderr, "0x%lx: line 102: ret: RETURN(expr)\n",(long)p);
#line 102 "minor.brg"
{}
		break;
	case 41: /* ret: NIL */
		fprintf(stderr, "0x%lx: line 103: ret: NIL\n",(long)p);
#line 103 "minor.brg"
{}
		break;
	case 42: /* loop: ret */
		fprintf(stderr, "0x%lx: line 105: loop: ret\n",(long)p);
#line 105 "minor.brg"
{}
		break;
	case 43: /* loop: REPEAT */
		fprintf(stderr, "0x%lx: line 106: loop: REPEAT\n",(long)p);
#line 106 "minor.brg"
{}
		break;
	case 44: /* loop: STOP */
		fprintf(stderr, "0x%lx: line 107: loop: STOP\n",(long)p);
#line 107 "minor.brg"
{}
		break;
	case 45: /* block: STMT(instrs,loop) */
		fprintf(stderr, "0x%lx: line 109: block: STMT(instrs,loop)\n",(long)p);
#line 109 "minor.brg"
{}
		break;
	case 46: /* instrs: NIL */
		fprintf(stderr, "0x%lx: line 111: instrs: NIL\n",(long)p);
#line 111 "minor.brg"
{}
		break;
	case 47: /* instrs: STMT(instrs,instr) */
		fprintf(stderr, "0x%lx: line 112: instrs: STMT(instrs,instr)\n",(long)p);
#line 112 "minor.brg"
{}
		break;
	case 48: /* instr: FI(THEN(IF(expr,block),elifs),else) */
		fprintf(stderr, "0x%lx: line 114: instr: FI(THEN(IF(expr,block),elifs),else)\n",(long)p);
#line 114 "minor.brg"
{}
		break;
	case 49: /* instr: FOR(UNTIL(expr,expr),STEP(block,expr)) */
		fprintf(stderr, "0x%lx: line 115: instr: FOR(UNTIL(expr,expr),STEP(block,expr))\n",(long)p);
#line 115 "minor.brg"
{}
		break;
	case 50: /* instr: PRINT(expr) */
		fprintf(stderr, "0x%lx: line 116: instr: PRINT(expr)\n",(long)p);
#line 116 "minor.brg"
{ fprintf(yyout, pfCALL pfCALL pfTRASH, "_printi", "_println", 4); }
		break;
	case 51: /* instr: expr */
		fprintf(stderr, "0x%lx: line 117: instr: expr\n",(long)p);
#line 117 "minor.brg"
{}
		break;
	case 52: /* instr: ALLOC(alloc,lval) */
		fprintf(stderr, "0x%lx: line 118: instr: ALLOC(alloc,lval)\n",(long)p);
#line 118 "minor.brg"
{ fprintf(yyout, pfSTORE); }
		break;
	case 53: /* alloc: expr */
		fprintf(stderr, "0x%lx: line 119: alloc: expr\n",(long)p);
#line 119 "minor.brg"
{ fprintf(yyout, pfIMM pfMUL pfALLOC pfSP, pfWORD); }
		break;
	case 54: /* elifs: NIL */
		fprintf(stderr, "0x%lx: line 121: elifs: NIL\n",(long)p);
#line 121 "minor.brg"
{}
		break;
	case 55: /* elifs: ELIF(elifs,IF(expr,block)) */
		fprintf(stderr, "0x%lx: line 122: elifs: ELIF(elifs,IF(expr,block))\n",(long)p);
#line 122 "minor.brg"
{}
		break;
	case 56: /* else: NIL */
		fprintf(stderr, "0x%lx: line 124: else: NIL\n",(long)p);
#line 124 "minor.brg"
{}
		break;
	case 57: /* else: block */
		fprintf(stderr, "0x%lx: line 125: else: block\n",(long)p);
#line 125 "minor.brg"
{}
		break;
	case 58: /* lval: ID */
		fprintf(stderr, "0x%lx: line 127: lval: ID\n",(long)p);
#line 127 "minor.brg"
{ fprintf(yyout, pfADDRV, p->value.s); }
		break;
	case 59: /* lval: INDEX(expr,ID) */
		fprintf(stderr, "0x%lx: line 128: lval: INDEX(expr,ID)\n",(long)p);
#line 128 "minor.brg"
{}
		break;
	case 60: /* expr: chars */
		fprintf(stderr, "0x%lx: line 130: expr: chars\n",(long)p);
#line 130 "minor.brg"
{}
		break;
	case 61: /* expr: lval */
		fprintf(stderr, "0x%lx: line 131: expr: lval\n",(long)p);
#line 131 "minor.brg"

		break;
	case 62: /* expr: ADDR(lval) */
		fprintf(stderr, "0x%lx: line 132: expr: ADDR(lval)\n",(long)p);
#line 132 "minor.brg"
{}
		break;
	case 63: /* expr: ADD(expr,expr) */
		fprintf(stderr, "0x%lx: line 133: expr: ADD(expr,expr)\n",(long)p);
#line 133 "minor.brg"
{ fprintf(yyout, pfADD); }
		break;
	case 64: /* expr: SUB(expr,expr) */
		fprintf(stderr, "0x%lx: line 134: expr: SUB(expr,expr)\n",(long)p);
#line 134 "minor.brg"
{ fprintf(yyout, pfSUB); }
		break;
	case 65: /* expr: MUL(expr,expr) */
		fprintf(stderr, "0x%lx: line 135: expr: MUL(expr,expr)\n",(long)p);
#line 135 "minor.brg"
{ fprintf(yyout, pfMUL); }
		break;
	case 66: /* expr: DIV(expr,expr) */
		fprintf(stderr, "0x%lx: line 136: expr: DIV(expr,expr)\n",(long)p);
#line 136 "minor.brg"
{ fprintf(yyout, pfDIV); }
		break;
	case 67: /* expr: MOD(expr,expr) */
		fprintf(stderr, "0x%lx: line 137: expr: MOD(expr,expr)\n",(long)p);
#line 137 "minor.brg"
{ fprintf(yyout, pfMOD); }
		break;
	case 68: /* expr: POW(expr,expr) */
		fprintf(stderr, "0x%lx: line 138: expr: POW(expr,expr)\n",(long)p);
#line 138 "minor.brg"
{}
		break;
	case 69: /* expr: EQU(expr,expr) */
		fprintf(stderr, "0x%lx: line 139: expr: EQU(expr,expr)\n",(long)p);
#line 139 "minor.brg"
{ fprintf(yyout, pfEQ); }
		break;
	case 70: /* expr: NE(expr,expr) */
		fprintf(stderr, "0x%lx: line 140: expr: NE(expr,expr)\n",(long)p);
#line 140 "minor.brg"
{ fprintf(yyout, pfNE); }
		break;
	case 71: /* expr: GE(expr,expr) */
		fprintf(stderr, "0x%lx: line 141: expr: GE(expr,expr)\n",(long)p);
#line 141 "minor.brg"
{ fprintf(yyout, pfGE); }
		break;
	case 72: /* expr: LE(expr,expr) */
		fprintf(stderr, "0x%lx: line 142: expr: LE(expr,expr)\n",(long)p);
#line 142 "minor.brg"
{ fprintf(yyout, pfLE); }
		break;
	case 73: /* expr: LT(expr,expr) */
		fprintf(stderr, "0x%lx: line 143: expr: LT(expr,expr)\n",(long)p);
#line 143 "minor.brg"
{ fprintf(yyout, pfLT); }
		break;
	case 74: /* expr: GT(expr,expr) */
		fprintf(stderr, "0x%lx: line 144: expr: GT(expr,expr)\n",(long)p);
#line 144 "minor.brg"
{ fprintf(yyout, pfGT); }
		break;
	case 75: /* expr: AND(expr,expr) */
		fprintf(stderr, "0x%lx: line 145: expr: AND(expr,expr)\n",(long)p);
#line 145 "minor.brg"
{}
		break;
	case 76: /* expr: OR(expr,expr) */
		fprintf(stderr, "0x%lx: line 146: expr: OR(expr,expr)\n",(long)p);
#line 146 "minor.brg"
{}
		break;
	case 77: /* expr: NOT(expr) */
		fprintf(stderr, "0x%lx: line 147: expr: NOT(expr)\n",(long)p);
#line 147 "minor.brg"
{ fprintf(yyout, pfIMM pfEQ, 0); }
		break;
	case 78: /* expr: UMINUS(expr) */
		fprintf(stderr, "0x%lx: line 148: expr: UMINUS(expr)\n",(long)p);
#line 148 "minor.brg"
{ fprintf(yyout, pfNEG); }
		break;
	case 79: /* expr: EQ(expr,lval) */
		fprintf(stderr, "0x%lx: line 149: expr: EQ(expr,lval)\n",(long)p);
#line 149 "minor.brg"
{}
		break;
	case 80: /* expr: IDARGS(ID,exprs) */
		fprintf(stderr, "0x%lx: line 150: expr: IDARGS(ID,exprs)\n",(long)p);
#line 150 "minor.brg"
{}
		break;
	case 81: /* exprs: COMMA(expr,NIL) */
		fprintf(stderr, "0x%lx: line 152: exprs: COMMA(expr,NIL)\n",(long)p);
#line 152 "minor.brg"
{}
		break;
	case 82: /* exprs: COMMA(expr,exprs) */
		fprintf(stderr, "0x%lx: line 153: exprs: COMMA(expr,exprs)\n",(long)p);
#line 153 "minor.brg"
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


#line 155 "minor.brg"

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
		outstr(RIGHT_CHILD(RIGHT_CHILD(p))->value.s);
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
