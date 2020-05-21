/*
generated at Thu May 21 17:08:49 2020
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

char *dupstr(const char *s);

extern FILE *yyout;
static int forlbl[20], repeatlbl[20], stoplbl[20], forcnt; /* for labels */
static char *extrns[100]; /* emit externs at the end only */
static int initints;
static int extcnt;
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
static void outstr(char *s) {
  while (*s) fprintf(yyout, pfCHAR, (unsigned char)*s++);
  fprintf(yyout, pfCHAR, 0);
}
static void pfPrint(int info) {
	if (tTYPE(info) == tINT) {
  		fprintf(yyout, pfCALL pfTRASH, "_printi", 4);
	}
	if (tTYPE(info) == tSTR) {
  		fprintf(yyout, pfCALL pfTRASH, "_prints", 4);
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
static void getAllocId(Node* nm) {
	int typ = 2, nmpos = 0;
	if (IDfind(nm->value.s, (void**)IDtest) >= 0) {
		if (nm->info >= tFUNC) {
			fprintf(yyout, pfCALL pfPUSH, mkfunc(nm->value.s));
		}
		else {
			fprintf(yyout, pfADDR, nm->value.s);
		}
	}
	else {
		typ = IDfind(nm->value.s, (long*)&nmpos);
		fprintf(yyout, pfLOCAL, nmpos);
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
static int varCost(Node *var) {
	return var->info & tCNST ? 0x7fff : 1;
}
static int cnstCost(Node *var) {
	return var->info & tCNST ? 1 : 0x7fff;
}
static void function(char *name, int enter) {
  fprintf(yyout, pfTEXT pfALIGN pfGLOBL pfLABEL pfENTER, mkfunc(name), pfFUNC, mkfunc(name), enter * (pfWORD/4));
}
static void externsPrint() {
  int i;
  
  for (i = 0; i < extcnt; i++)
    if (extrns[i])
      fprintf(yyout, pfEXTRN, extrns[i]);
}
static void final() {
    fprintf(yyout, pfIMM pfPOP pfLEAVE pfRET, 0);
    fprintf(yyout, pfEXTRN pfEXTRN pfEXTRN, "_prints", "_printi", "_readi");
	externsPrint();
}
static void initRemaining(int dim) {
	while (dim - initints) {
		fprintf(yyout, pfINTEGER, 0);
		initints++;
	}
}
/* expr: expr */
/* 255 truncar */
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
#define yyconstvardecl_NT 8
#define yyfuncname_NT 9
#define yyfuncargs_NT 10
#define yyeqbody_NT 11
#define yyfarg_NT 12
#define yyvdim_NT 13
#define yyfargs_NT 14
#define yyfvar_NT 15
#define yyfvars_NT 16
#define yyvarid_NT 17
#define yyeqint_NT 18
#define yyeqstr_NT 19
#define yyarrayid_NT 20
#define yyeqvec_NT 21
#define yyconstid_NT 22
#define yyconstarrayid_NT 23
#define yyints_NT 24
#define yychars_NT 25
#define yyfirstchar_NT 26
#define yychar_NT 27
#define yybody_NT 28
#define yymainfvars_NT 29
#define yyinstrs_NT 30
#define yybodyfvars_NT 31
#define yyret_NT 32
#define yyexpr_NT 33
#define yyloop_NT 34
#define yyblock_NT 35
#define yyforblock_NT 36
#define yyinstr_NT 37
#define yyif_NT 38
#define yyelifs_NT 39
#define yyelse_NT 40
#define yyinit_NT 41
#define yyforcond_NT 42
#define yypostexpr_NT 43
#define yyalloc_NT 44
#define yyalloclval_NT 45
#define yycond_NT 46
#define yyifelse_NT 47
#define yytrashexpr_NT 48
#define yylval_NT 49
#define yylvec_NT 50
#define yylvecassign_NT 51
#define yyassign_NT 52
#define yyand_NT 53
#define yyor_NT 54
#define yyexprs_NT 55

static YYCONST char *yyntname[] = {
	0,
	"program",
	"decls",
	"funcmain",
	"main",
	"gdecls",
	"decl",
	"vardecl",
	"constvardecl",
	"funcname",
	"funcargs",
	"eqbody",
	"farg",
	"vdim",
	"fargs",
	"fvar",
	"fvars",
	"varid",
	"eqint",
	"eqstr",
	"arrayid",
	"eqvec",
	"constid",
	"constarrayid",
	"ints",
	"chars",
	"firstchar",
	"char",
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
	"alloclval",
	"cond",
	"ifelse",
	"trashexpr",
	"lval",
	"lvec",
	"lvecassign",
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
	short cost[56];
	struct {
		unsigned int yyprogram:2;
		unsigned int yydecls:2;
		unsigned int yyfuncmain:1;
		unsigned int yymain:1;
		unsigned int yygdecls:2;
		unsigned int yydecl:3;
		unsigned int yyvardecl:4;
		unsigned int yyconstvardecl:2;
		unsigned int yyfuncname:1;
		unsigned int yyfuncargs:1;
		unsigned int yyeqbody:1;
		unsigned int yyfarg:2;
		unsigned int yyvdim:1;
		unsigned int yyfargs:2;
		unsigned int yyfvar:2;
		unsigned int yyfvars:2;
		unsigned int yyvarid:1;
		unsigned int yyeqint:1;
		unsigned int yyeqstr:1;
		unsigned int yyarrayid:1;
		unsigned int yyeqvec:1;
		unsigned int yyconstid:1;
		unsigned int yyconstarrayid:1;
		unsigned int yyints:2;
		unsigned int yychars:2;
		unsigned int yyfirstchar:2;
		unsigned int yychar:2;
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
		unsigned int yyalloclval:2;
		unsigned int yycond:1;
		unsigned int yyifelse:1;
		unsigned int yytrashexpr:1;
		unsigned int yylval:2;
		unsigned int yylvec:1;
		unsigned int yylvecassign:1;
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
static short yynts_7[] = { yyconstvardecl_NT, 0 };
static short yynts_8[] = { yyfuncname_NT, yyfuncargs_NT, 0 };
static short yynts_9[] = { yyfuncname_NT, yyfuncargs_NT, yyeqbody_NT, 0 };
static short yynts_10[] = { yyvdim_NT, 0 };
static short yynts_11[] = { yyfarg_NT, 0 };
static short yynts_12[] = { yyfargs_NT, yyfarg_NT, 0 };
static short yynts_13[] = { yyfargs_NT, 0 };
static short yynts_14[] = { yyfvar_NT, 0 };
static short yynts_15[] = { yyfvars_NT, yyfvar_NT, 0 };
static short yynts_16[] = { yyvarid_NT, yyeqint_NT, 0 };
static short yynts_17[] = { yyvarid_NT, yyeqstr_NT, 0 };
static short yynts_18[] = { yyarrayid_NT, yyvdim_NT, yyeqvec_NT, 0 };
static short yynts_19[] = { yyarrayid_NT, yyeqvec_NT, 0 };
static short yynts_20[] = { yyconstid_NT, yyeqint_NT, 0 };
static short yynts_21[] = { yyconstid_NT, yyeqstr_NT, 0 };
static short yynts_22[] = { yyconstarrayid_NT, yyvdim_NT, yyeqvec_NT, 0 };
static short yynts_23[] = { yyints_NT, 0 };
static short yynts_24[] = { yychars_NT, 0 };
static short yynts_25[] = { yyfirstchar_NT, 0 };
static short yynts_26[] = { yychars_NT, yychar_NT, 0 };
static short yynts_27[] = { yybody_NT, 0 };
static short yynts_28[] = { yymainfvars_NT, yyinstrs_NT, 0 };
static short yynts_29[] = { yyfvars_NT, 0 };
static short yynts_30[] = { yybodyfvars_NT, yyinstrs_NT, yyret_NT, 0 };
static short yynts_31[] = { yyexpr_NT, 0 };
static short yynts_32[] = { yyret_NT, 0 };
static short yynts_33[] = { yyinstrs_NT, yyloop_NT, 0 };
static short yynts_34[] = { yyinstrs_NT, yyinstr_NT, 0 };
static short yynts_35[] = { yyif_NT, yyelifs_NT, yyelse_NT, 0 };
static short yynts_36[] = { yyinit_NT, yyforcond_NT, yyforblock_NT, yypostexpr_NT, 0 };
static short yynts_37[] = { yyalloc_NT, yyalloclval_NT, 0 };
static short yynts_38[] = { yycond_NT, yyblock_NT, 0 };
static short yynts_39[] = { yytrashexpr_NT, 0 };
static short yynts_40[] = { yyelifs_NT, yyifelse_NT, 0 };
static short yynts_41[] = { yyblock_NT, 0 };
static short yynts_42[] = { yyalloclval_NT, yyexpr_NT, 0 };
static short yynts_43[] = { yylvec_NT, yyexpr_NT, 0 };
static short yynts_44[] = { yylvecassign_NT, yyexpr_NT, 0 };
static short yynts_45[] = { yylval_NT, 0 };
static short yynts_46[] = { yyexpr_NT, yyexpr_NT, 0 };
static short yynts_47[] = { yyand_NT, yyexpr_NT, 0 };
static short yynts_48[] = { yyor_NT, yyexpr_NT, 0 };
static short yynts_49[] = { yyexpr_NT, yyassign_NT, 0 };
static short yynts_50[] = { yyexprs_NT, 0 };
static short yynts_51[] = { yyexpr_NT, yyexprs_NT, 0 };

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
	yynts_9,	/* 10 */
	yynts_2,	/* 11 */
	yynts_2,	/* 12 */
	yynts_10,	/* 13 */
	yynts_2,	/* 14 */
	yynts_11,	/* 15 */
	yynts_12,	/* 16 */
	yynts_13,	/* 17 */
	yynts_2,	/* 18 */
	yynts_2,	/* 19 */
	yynts_2,	/* 20 */
	yynts_2,	/* 21 */
	yynts_10,	/* 22 */
	yynts_14,	/* 23 */
	yynts_15,	/* 24 */
	yynts_16,	/* 25 */
	yynts_17,	/* 26 */
	yynts_18,	/* 27 */
	yynts_19,	/* 28 */
	yynts_2,	/* 29 */
	yynts_2,	/* 30 */
	yynts_10,	/* 31 */
	yynts_2,	/* 32 */
	yynts_2,	/* 33 */
	yynts_20,	/* 34 */
	yynts_21,	/* 35 */
	yynts_22,	/* 36 */
	yynts_2,	/* 37 */
	yynts_2,	/* 38 */
	yynts_2,	/* 39 */
	yynts_2,	/* 40 */
	yynts_23,	/* 41 */
	yynts_2,	/* 42 */
	yynts_23,	/* 43 */
	yynts_2,	/* 44 */
	yynts_24,	/* 45 */
	yynts_25,	/* 46 */
	yynts_26,	/* 47 */
	yynts_2,	/* 48 */
	yynts_2,	/* 49 */
	yynts_2,	/* 50 */
	yynts_2,	/* 51 */
	yynts_2,	/* 52 */
	yynts_2,	/* 53 */
	yynts_27,	/* 54 */
	yynts_28,	/* 55 */
	yynts_2,	/* 56 */
	yynts_29,	/* 57 */
	yynts_30,	/* 58 */
	yynts_2,	/* 59 */
	yynts_29,	/* 60 */
	yynts_2,	/* 61 */
	yynts_31,	/* 62 */
	yynts_2,	/* 63 */
	yynts_32,	/* 64 */
	yynts_2,	/* 65 */
	yynts_2,	/* 66 */
	yynts_33,	/* 67 */
	yynts_33,	/* 68 */
	yynts_2,	/* 69 */
	yynts_34,	/* 70 */
	yynts_35,	/* 71 */
	yynts_36,	/* 72 */
	yynts_31,	/* 73 */
	yynts_31,	/* 74 */
	yynts_37,	/* 75 */
	yynts_31,	/* 76 */
	yynts_38,	/* 77 */
	yynts_38,	/* 78 */
	yynts_39,	/* 79 */
	yynts_31,	/* 80 */
	yynts_39,	/* 81 */
	yynts_31,	/* 82 */
	yynts_31,	/* 83 */
	yynts_2,	/* 84 */
	yynts_40,	/* 85 */
	yynts_2,	/* 86 */
	yynts_41,	/* 87 */
	yynts_2,	/* 88 */
	yynts_42,	/* 89 */
	yynts_2,	/* 90 */
	yynts_43,	/* 91 */
	yynts_2,	/* 92 */
	yynts_2,	/* 93 */
	yynts_2,	/* 94 */
	yynts_44,	/* 95 */
	yynts_2,	/* 96 */
	yynts_2,	/* 97 */
	yynts_2,	/* 98 */
	yynts_24,	/* 99 */
	yynts_45,	/* 100 */
	yynts_2,	/* 101 */
	yynts_45,	/* 102 */
	yynts_46,	/* 103 */
	yynts_46,	/* 104 */
	yynts_46,	/* 105 */
	yynts_46,	/* 106 */
	yynts_46,	/* 107 */
	yynts_46,	/* 108 */
	yynts_46,	/* 109 */
	yynts_46,	/* 110 */
	yynts_46,	/* 111 */
	yynts_46,	/* 112 */
	yynts_46,	/* 113 */
	yynts_46,	/* 114 */
	yynts_47,	/* 115 */
	yynts_31,	/* 116 */
	yynts_48,	/* 117 */
	yynts_31,	/* 118 */
	yynts_31,	/* 119 */
	yynts_31,	/* 120 */
	yynts_49,	/* 121 */
	yynts_50,	/* 122 */
	yynts_31,	/* 123 */
	yynts_51,	/* 124 */
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
/* 8 */	"decl: VAR(constvardecl)",
/* 9 */	"decl: FUNCTION(funcname,FARGS(funcargs,NIL))",
/* 10 */	"decl: FUNCTION(funcname,FARGS(funcargs,eqbody))",
/* 11 */	"farg: NUMBER(ID,NIL)",
/* 12 */	"farg: STRING(ID,NIL)",
/* 13 */	"farg: ARRAY(ID,INTS(vdim,NIL))",
/* 14 */	"fargs: NIL",
/* 15 */	"fargs: ARGS(NIL,farg)",
/* 16 */	"fargs: ARGS(fargs,farg)",
/* 17 */	"funcargs: fargs",
/* 18 */	"funcname: END(ID,INT)",
/* 19 */	"funcmain: END(ID,INT)",
/* 20 */	"fvar: NUMBER(ID,NIL)",
/* 21 */	"fvar: STRING(ID,NIL)",
/* 22 */	"fvar: ARRAY(ID,INTS(vdim,NIL))",
/* 23 */	"fvars: ARGS(NIL,fvar)",
/* 24 */	"fvars: ARGS(fvars,fvar)",
/* 25 */	"vardecl: NUMBER(varid,eqint)",
/* 26 */	"vardecl: STRING(varid,eqstr)",
/* 27 */	"vardecl: ARRAY(arrayid,INTS(vdim,eqvec))",
/* 28 */	"vardecl: ARRAY(arrayid,INTS(NIL,eqvec))",
/* 29 */	"vardecl: NUMBER(ID,NIL)",
/* 30 */	"vardecl: STRING(ID,NIL)",
/* 31 */	"vardecl: ARRAY(ID,INTS(vdim,NIL))",
/* 32 */	"vardecl: ARRAY(ID,INTS(NIL,NIL))",
/* 33 */	"varid: ID",
/* 34 */	"constvardecl: NUMBER(constid,eqint)",
/* 35 */	"constvardecl: STRING(constid,eqstr)",
/* 36 */	"constvardecl: ARRAY(constarrayid,INTS(vdim,eqvec))",
/* 37 */	"constid: ID",
/* 38 */	"constarrayid: ID",
/* 39 */	"arrayid: ID",
/* 40 */	"vdim: INT",
/* 41 */	"eqvec: ints",
/* 42 */	"ints: INT",
/* 43 */	"ints: INTS(ints,INT)",
/* 44 */	"eqint: INT",
/* 45 */	"eqstr: chars",
/* 46 */	"chars: CHARS(NIL,firstchar)",
/* 47 */	"chars: CHARS(chars,char)",
/* 48 */	"firstchar: INT",
/* 49 */	"firstchar: CHAR",
/* 50 */	"firstchar: STR",
/* 51 */	"char: INT",
/* 52 */	"char: CHAR",
/* 53 */	"char: STR",
/* 54 */	"eqbody: body",
/* 55 */	"main: START(mainfvars,instrs)",
/* 56 */	"mainfvars: NIL",
/* 57 */	"mainfvars: fvars",
/* 58 */	"body: START(bodyfvars,STMT(instrs,ret))",
/* 59 */	"bodyfvars: NIL",
/* 60 */	"bodyfvars: fvars",
/* 61 */	"ret: RETURN(NIL)",
/* 62 */	"ret: RETURN(expr)",
/* 63 */	"ret: NIL",
/* 64 */	"loop: ret",
/* 65 */	"loop: REPEAT",
/* 66 */	"loop: STOP",
/* 67 */	"block: STMT(instrs,loop)",
/* 68 */	"forblock: STMT(instrs,loop)",
/* 69 */	"instrs: NIL",
/* 70 */	"instrs: STMT(instrs,instr)",
/* 71 */	"instr: FI(THEN(if,elifs),else)",
/* 72 */	"instr: FOR(UNTIL(init,forcond),STEP(forblock,postexpr))",
/* 73 */	"instr: PRINT(expr)",
/* 74 */	"instr: expr",
/* 75 */	"instr: ALLOC(alloc,alloclval)",
/* 76 */	"alloc: expr",
/* 77 */	"if: IF(cond,block)",
/* 78 */	"ifelse: IF(cond,block)",
/* 79 */	"init: trashexpr",
/* 80 */	"forcond: expr",
/* 81 */	"postexpr: trashexpr",
/* 82 */	"cond: expr",
/* 83 */	"trashexpr: expr",
/* 84 */	"elifs: NIL",
/* 85 */	"elifs: ELIF(elifs,ifelse)",
/* 86 */	"else: NIL",
/* 87 */	"else: block",
/* 88 */	"alloclval: ID",
/* 89 */	"alloclval: INDEX(alloclval,expr)",
/* 90 */	"lval: ID",
/* 91 */	"lval: INDEX(lvec,expr)",
/* 92 */	"lvec: ID",
/* 93 */	"lvecassign: ID",
/* 94 */	"assign: ID",
/* 95 */	"assign: INDEX(lvecassign,expr)",
/* 96 */	"expr: CHARS(NIL,INT)",
/* 97 */	"expr: CHARS(NIL,CHAR)",
/* 98 */	"expr: CHARS(NIL,STR)",
/* 99 */	"expr: chars",
/* 100 */	"expr: lval",
/* 101 */	"expr: READ",
/* 102 */	"expr: ADDR(lval)",
/* 103 */	"expr: ADD(expr,expr)",
/* 104 */	"expr: SUB(expr,expr)",
/* 105 */	"expr: MUL(expr,expr)",
/* 106 */	"expr: DIV(expr,expr)",
/* 107 */	"expr: MOD(expr,expr)",
/* 108 */	"expr: POW(expr,expr)",
/* 109 */	"expr: EQU(expr,expr)",
/* 110 */	"expr: NE(expr,expr)",
/* 111 */	"expr: GE(expr,expr)",
/* 112 */	"expr: LE(expr,expr)",
/* 113 */	"expr: LT(expr,expr)",
/* 114 */	"expr: GT(expr,expr)",
/* 115 */	"expr: AND(and,expr)",
/* 116 */	"and: expr",
/* 117 */	"expr: OR(or,expr)",
/* 118 */	"or: expr",
/* 119 */	"expr: NOT(expr)",
/* 120 */	"expr: UMINUS(expr)",
/* 121 */	"expr: EQ(expr,assign)",
/* 122 */	"expr: IDARGS(ID,exprs)",
/* 123 */	"exprs: COMMA(expr,NIL)",
/* 124 */	"exprs: COMMA(expr,exprs)",
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
	19,
};

static short yydecode_main[] = {
	0,
	55,
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
	10,
};

static short yydecode_vardecl[] = {
	0,
	25,
	26,
	27,
	28,
	29,
	30,
	31,
	32,
};

static short yydecode_constvardecl[] = {
	0,
	34,
	35,
	36,
};

static short yydecode_funcname[] = {
	0,
	18,
};

static short yydecode_funcargs[] = {
	0,
	17,
};

static short yydecode_eqbody[] = {
	0,
	54,
};

static short yydecode_farg[] = {
	0,
	11,
	12,
	13,
};

static short yydecode_vdim[] = {
	0,
	40,
};

static short yydecode_fargs[] = {
	0,
	14,
	15,
	16,
};

static short yydecode_fvar[] = {
	0,
	20,
	21,
	22,
};

static short yydecode_fvars[] = {
	0,
	23,
	24,
};

static short yydecode_varid[] = {
	0,
	33,
};

static short yydecode_eqint[] = {
	0,
	44,
};

static short yydecode_eqstr[] = {
	0,
	45,
};

static short yydecode_arrayid[] = {
	0,
	39,
};

static short yydecode_eqvec[] = {
	0,
	41,
};

static short yydecode_constid[] = {
	0,
	37,
};

static short yydecode_constarrayid[] = {
	0,
	38,
};

static short yydecode_ints[] = {
	0,
	42,
	43,
};

static short yydecode_chars[] = {
	0,
	46,
	47,
};

static short yydecode_firstchar[] = {
	0,
	48,
	49,
	50,
};

static short yydecode_char[] = {
	0,
	51,
	52,
	53,
};

static short yydecode_body[] = {
	0,
	58,
};

static short yydecode_mainfvars[] = {
	0,
	56,
	57,
};

static short yydecode_instrs[] = {
	0,
	69,
	70,
};

static short yydecode_bodyfvars[] = {
	0,
	59,
	60,
};

static short yydecode_ret[] = {
	0,
	61,
	62,
	63,
};

static short yydecode_expr[] = {
	0,
	96,
	97,
	98,
	99,
	100,
	101,
	102,
	103,
	104,
	105,
	106,
	107,
	108,
	109,
	110,
	111,
	112,
	113,
	114,
	115,
	117,
	119,
	120,
	121,
	122,
};

static short yydecode_loop[] = {
	0,
	64,
	65,
	66,
};

static short yydecode_block[] = {
	0,
	67,
};

static short yydecode_forblock[] = {
	0,
	68,
};

static short yydecode_instr[] = {
	0,
	71,
	72,
	73,
	74,
	75,
};

static short yydecode_if[] = {
	0,
	77,
};

static short yydecode_elifs[] = {
	0,
	84,
	85,
};

static short yydecode_else[] = {
	0,
	86,
	87,
};

static short yydecode_init[] = {
	0,
	79,
};

static short yydecode_forcond[] = {
	0,
	80,
};

static short yydecode_postexpr[] = {
	0,
	81,
};

static short yydecode_alloc[] = {
	0,
	76,
};

static short yydecode_alloclval[] = {
	0,
	88,
	89,
};

static short yydecode_cond[] = {
	0,
	82,
};

static short yydecode_ifelse[] = {
	0,
	78,
};

static short yydecode_trashexpr[] = {
	0,
	83,
};

static short yydecode_lval[] = {
	0,
	90,
	91,
};

static short yydecode_lvec[] = {
	0,
	92,
};

static short yydecode_lvecassign[] = {
	0,
	93,
};

static short yydecode_assign[] = {
	0,
	94,
	95,
};

static short yydecode_and[] = {
	0,
	116,
};

static short yydecode_or[] = {
	0,
	118,
};

static short yydecode_exprs[] = {
	0,
	123,
	124,
};

static int yyrule(void *state, int goalnt) {
	if (goalnt < 1 || goalnt > 55)
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
	case yyconstvardecl_NT:	return yydecode_constvardecl[((struct yystate *)state)->rule.yyconstvardecl];
	case yyfuncname_NT:	return yydecode_funcname[((struct yystate *)state)->rule.yyfuncname];
	case yyfuncargs_NT:	return yydecode_funcargs[((struct yystate *)state)->rule.yyfuncargs];
	case yyeqbody_NT:	return yydecode_eqbody[((struct yystate *)state)->rule.yyeqbody];
	case yyfarg_NT:	return yydecode_farg[((struct yystate *)state)->rule.yyfarg];
	case yyvdim_NT:	return yydecode_vdim[((struct yystate *)state)->rule.yyvdim];
	case yyfargs_NT:	return yydecode_fargs[((struct yystate *)state)->rule.yyfargs];
	case yyfvar_NT:	return yydecode_fvar[((struct yystate *)state)->rule.yyfvar];
	case yyfvars_NT:	return yydecode_fvars[((struct yystate *)state)->rule.yyfvars];
	case yyvarid_NT:	return yydecode_varid[((struct yystate *)state)->rule.yyvarid];
	case yyeqint_NT:	return yydecode_eqint[((struct yystate *)state)->rule.yyeqint];
	case yyeqstr_NT:	return yydecode_eqstr[((struct yystate *)state)->rule.yyeqstr];
	case yyarrayid_NT:	return yydecode_arrayid[((struct yystate *)state)->rule.yyarrayid];
	case yyeqvec_NT:	return yydecode_eqvec[((struct yystate *)state)->rule.yyeqvec];
	case yyconstid_NT:	return yydecode_constid[((struct yystate *)state)->rule.yyconstid];
	case yyconstarrayid_NT:	return yydecode_constarrayid[((struct yystate *)state)->rule.yyconstarrayid];
	case yyints_NT:	return yydecode_ints[((struct yystate *)state)->rule.yyints];
	case yychars_NT:	return yydecode_chars[((struct yystate *)state)->rule.yychars];
	case yyfirstchar_NT:	return yydecode_firstchar[((struct yystate *)state)->rule.yyfirstchar];
	case yychar_NT:	return yydecode_char[((struct yystate *)state)->rule.yychar];
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
	case yyalloclval_NT:	return yydecode_alloclval[((struct yystate *)state)->rule.yyalloclval];
	case yycond_NT:	return yydecode_cond[((struct yystate *)state)->rule.yycond];
	case yyifelse_NT:	return yydecode_ifelse[((struct yystate *)state)->rule.yyifelse];
	case yytrashexpr_NT:	return yydecode_trashexpr[((struct yystate *)state)->rule.yytrashexpr];
	case yylval_NT:	return yydecode_lval[((struct yystate *)state)->rule.yylval];
	case yylvec_NT:	return yydecode_lvec[((struct yystate *)state)->rule.yylvec];
	case yylvecassign_NT:	return yydecode_lvecassign[((struct yystate *)state)->rule.yylvecassign];
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
static void yyclosure_fargs(NODEPTR_TYPE, int);
static void yyclosure_fvars(NODEPTR_TYPE, int);
static void yyclosure_ints(NODEPTR_TYPE, int);
static void yyclosure_chars(NODEPTR_TYPE, int);
static void yyclosure_body(NODEPTR_TYPE, int);
static void yyclosure_ret(NODEPTR_TYPE, int);
static void yyclosure_expr(NODEPTR_TYPE, int);
static void yyclosure_block(NODEPTR_TYPE, int);
static void yyclosure_trashexpr(NODEPTR_TYPE, int);
static void yyclosure_lval(NODEPTR_TYPE, int);

static void yyclosure_gdecls(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 4, c + 1, p->cost[yydecls_NT]);
	if (c + 1 < p->cost[yydecls_NT]) {
		p->cost[yydecls_NT] = c + 1;
		p->rule.yydecls = 2;
	}
}

static void yyclosure_fargs(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 17, c + 1, p->cost[yyfuncargs_NT]);
	if (c + 1 < p->cost[yyfuncargs_NT]) {
		p->cost[yyfuncargs_NT] = c + 1;
		p->rule.yyfuncargs = 1;
	}
}

static void yyclosure_fvars(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 60, c + 1, p->cost[yybodyfvars_NT]);
	if (c + 1 < p->cost[yybodyfvars_NT]) {
		p->cost[yybodyfvars_NT] = c + 1;
		p->rule.yybodyfvars = 2;
	}
	yytrace(a, 57, c + 1, p->cost[yymainfvars_NT]);
	if (c + 1 < p->cost[yymainfvars_NT]) {
		p->cost[yymainfvars_NT] = c + 1;
		p->rule.yymainfvars = 2;
	}
}

static void yyclosure_ints(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 41, c + 1, p->cost[yyeqvec_NT]);
	if (c + 1 < p->cost[yyeqvec_NT]) {
		p->cost[yyeqvec_NT] = c + 1;
		p->rule.yyeqvec = 1;
	}
}

static void yyclosure_chars(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 99, c + 1, p->cost[yyexpr_NT]);
	if (c + 1 < p->cost[yyexpr_NT]) {
		p->cost[yyexpr_NT] = c + 1;
		p->rule.yyexpr = 4;
		yyclosure_expr(a, c + 1);
	}
	yytrace(a, 45, c + 1, p->cost[yyeqstr_NT]);
	if (c + 1 < p->cost[yyeqstr_NT]) {
		p->cost[yyeqstr_NT] = c + 1;
		p->rule.yyeqstr = 1;
	}
}

static void yyclosure_body(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 54, c + 1, p->cost[yyeqbody_NT]);
	if (c + 1 < p->cost[yyeqbody_NT]) {
		p->cost[yyeqbody_NT] = c + 1;
		p->rule.yyeqbody = 1;
	}
}

static void yyclosure_ret(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 64, c + 1, p->cost[yyloop_NT]);
	if (c + 1 < p->cost[yyloop_NT]) {
		p->cost[yyloop_NT] = c + 1;
		p->rule.yyloop = 1;
	}
}

static void yyclosure_expr(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 118, c + 1, p->cost[yyor_NT]);
	if (c + 1 < p->cost[yyor_NT]) {
		p->cost[yyor_NT] = c + 1;
		p->rule.yyor = 1;
	}
	yytrace(a, 116, c + 1, p->cost[yyand_NT]);
	if (c + 1 < p->cost[yyand_NT]) {
		p->cost[yyand_NT] = c + 1;
		p->rule.yyand = 1;
	}
	yytrace(a, 83, c + 1, p->cost[yytrashexpr_NT]);
	if (c + 1 < p->cost[yytrashexpr_NT]) {
		p->cost[yytrashexpr_NT] = c + 1;
		p->rule.yytrashexpr = 1;
		yyclosure_trashexpr(a, c + 1);
	}
	yytrace(a, 82, c + 1, p->cost[yycond_NT]);
	if (c + 1 < p->cost[yycond_NT]) {
		p->cost[yycond_NT] = c + 1;
		p->rule.yycond = 1;
	}
	yytrace(a, 80, c + 1, p->cost[yyforcond_NT]);
	if (c + 1 < p->cost[yyforcond_NT]) {
		p->cost[yyforcond_NT] = c + 1;
		p->rule.yyforcond = 1;
	}
	yytrace(a, 76, c + 1, p->cost[yyalloc_NT]);
	if (c + 1 < p->cost[yyalloc_NT]) {
		p->cost[yyalloc_NT] = c + 1;
		p->rule.yyalloc = 1;
	}
	yytrace(a, 74, c + 1, p->cost[yyinstr_NT]);
	if (c + 1 < p->cost[yyinstr_NT]) {
		p->cost[yyinstr_NT] = c + 1;
		p->rule.yyinstr = 4;
	}
}

static void yyclosure_block(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 87, c + 0, p->cost[yyelse_NT]);
	if (c + 0 < p->cost[yyelse_NT]) {
		p->cost[yyelse_NT] = c + 0;
		p->rule.yyelse = 2;
	}
}

static void yyclosure_trashexpr(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 81, c + 1, p->cost[yypostexpr_NT]);
	if (c + 1 < p->cost[yypostexpr_NT]) {
		p->cost[yypostexpr_NT] = c + 1;
		p->rule.yypostexpr = 1;
	}
	yytrace(a, 79, c + 1, p->cost[yyinit_NT]);
	if (c + 1 < p->cost[yyinit_NT]) {
		p->cost[yyinit_NT] = c + 1;
		p->rule.yyinit = 1;
	}
}

static void yyclosure_lval(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 100, c + 0, p->cost[yyexpr_NT]);
	if (c + 0 < p->cost[yyexpr_NT]) {
		p->cost[yyexpr_NT] = c + 0;
		p->rule.yyexpr = 5;
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
	p->cost[48] =
	p->cost[49] =
	p->cost[50] =
	p->cost[51] =
	p->cost[52] =
	p->cost[53] =
	p->cost[54] =
	p->cost[55] =
		0x7fff;
	switch (OP_LABEL(a)) {
	case 33: /* PRINT */
		yylabel(LEFT_CHILD(a),a);
		/* instr: PRINT(expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + 3;
		yytrace(a, 73, c + 0, p->cost[yyinstr_NT]);
		if (c + 0 < p->cost[yyinstr_NT]) {
			p->cost[yyinstr_NT] = c + 0;
			p->rule.yyinstr = 3;
		}
		break;
	case 35: /* ALLOC */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* instr: ALLOC(alloc,alloclval) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyalloc_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyalloclval_NT] + 1;
		yytrace(a, 75, c + 0, p->cost[yyinstr_NT]);
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
		yytrace(a, 107, c + 0, p->cost[yyexpr_NT]);
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
		yytrace(a, 115, c + 0, p->cost[yyexpr_NT]);
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
			yytrace(a, 122, c + 0, p->cost[yyexpr_NT]);
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
		yytrace(a, 105, c + 0, p->cost[yyexpr_NT]);
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
		yytrace(a, 103, c + 0, p->cost[yyexpr_NT]);
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
			yytrace(a, 123, c + 0, p->cost[yyexprs_NT]);
			if (c + 0 < p->cost[yyexprs_NT]) {
				p->cost[yyexprs_NT] = c + 0;
				p->rule.yyexprs = 1;
			}
		}
		/* exprs: COMMA(expr,exprs) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexprs_NT] + 1;
		yytrace(a, 124, c + 0, p->cost[yyexprs_NT]);
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
		yytrace(a, 104, c + 0, p->cost[yyexpr_NT]);
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
		yytrace(a, 106, c + 0, p->cost[yyexpr_NT]);
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
		yytrace(a, 67, c + 0, p->cost[yyblock_NT]);
		if (c + 0 < p->cost[yyblock_NT]) {
			p->cost[yyblock_NT] = c + 0;
			p->rule.yyblock = 1;
			yyclosure_block(a, c + 0);
		}
		/* forblock: STMT(instrs,loop) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyinstrs_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyloop_NT] + 1;
		yytrace(a, 68, c + 0, p->cost[yyforblock_NT]);
		if (c + 0 < p->cost[yyforblock_NT]) {
			p->cost[yyforblock_NT] = c + 0;
			p->rule.yyforblock = 1;
		}
		/* instrs: STMT(instrs,instr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyinstrs_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyinstr_NT] + 1;
		yytrace(a, 70, c + 0, p->cost[yyinstrs_NT]);
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
		yytrace(a, 113, c + 0, p->cost[yyexpr_NT]);
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
		yytrace(a, 109, c + 0, p->cost[yyexpr_NT]);
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
		yytrace(a, 114, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 19;
			yyclosure_expr(a, c + 0);
		}
		break;
	case 63: /* READ */
		/* expr: READ */
		yytrace(a, 101, 1 + 0, p->cost[yyexpr_NT]);
		if (1 + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = 1 + 0;
			p->rule.yyexpr = 6;
			yyclosure_expr(a, 1 + 0);
		}
		break;
	case 91: /* INDEX */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* alloclval: INDEX(alloclval,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyalloclval_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 89, c + 0, p->cost[yyalloclval_NT]);
		if (c + 0 < p->cost[yyalloclval_NT]) {
			p->cost[yyalloclval_NT] = c + 0;
			p->rule.yyalloclval = 2;
		}
		/* lval: INDEX(lvec,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yylvec_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 91, c + 0, p->cost[yylval_NT]);
		if (c + 0 < p->cost[yylval_NT]) {
			p->cost[yylval_NT] = c + 0;
			p->rule.yylval = 2;
			yyclosure_lval(a, c + 0);
		}
		/* assign: INDEX(lvecassign,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yylvecassign_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 95, c + 0, p->cost[yyassign_NT]);
		if (c + 0 < p->cost[yyassign_NT]) {
			p->cost[yyassign_NT] = c + 0;
			p->rule.yyassign = 2;
		}
		break;
	case 94: /* POW */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* expr: POW(expr,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 108, c + 0, p->cost[yyexpr_NT]);
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
		yytrace(a, 117, c + 0, p->cost[yyexpr_NT]);
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
		yytrace(a, 119, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 22;
			yyclosure_expr(a, c + 0);
		}
		break;
	case 257: /* INT */
		/* vdim: INT */
		yytrace(a, 40, 1 + 0, p->cost[yyvdim_NT]);
		if (1 + 0 < p->cost[yyvdim_NT]) {
			p->cost[yyvdim_NT] = 1 + 0;
			p->rule.yyvdim = 1;
		}
		/* ints: INT */
		yytrace(a, 42, 1 + 0, p->cost[yyints_NT]);
		if (1 + 0 < p->cost[yyints_NT]) {
			p->cost[yyints_NT] = 1 + 0;
			p->rule.yyints = 1;
			yyclosure_ints(a, 1 + 0);
		}
		/* eqint: INT */
		yytrace(a, 44, 1 + 0, p->cost[yyeqint_NT]);
		if (1 + 0 < p->cost[yyeqint_NT]) {
			p->cost[yyeqint_NT] = 1 + 0;
			p->rule.yyeqint = 1;
		}
		/* firstchar: INT */
		yytrace(a, 48, 1 + 0, p->cost[yyfirstchar_NT]);
		if (1 + 0 < p->cost[yyfirstchar_NT]) {
			p->cost[yyfirstchar_NT] = 1 + 0;
			p->rule.yyfirstchar = 1;
		}
		/* char: INT */
		yytrace(a, 51, 1 + 0, p->cost[yychar_NT]);
		if (1 + 0 < p->cost[yychar_NT]) {
			p->cost[yychar_NT] = 1 + 0;
			p->rule.yychar = 1;
		}
		break;
	case 258: /* CHAR */
		/* firstchar: CHAR */
		yytrace(a, 49, 1 + 0, p->cost[yyfirstchar_NT]);
		if (1 + 0 < p->cost[yyfirstchar_NT]) {
			p->cost[yyfirstchar_NT] = 1 + 0;
			p->rule.yyfirstchar = 2;
		}
		/* char: CHAR */
		yytrace(a, 52, 1 + 0, p->cost[yychar_NT]);
		if (1 + 0 < p->cost[yychar_NT]) {
			p->cost[yychar_NT] = 1 + 0;
			p->rule.yychar = 2;
		}
		break;
	case 259: /* ID */
		/* varid: ID */
		yytrace(a, 33, 1 + 0, p->cost[yyvarid_NT]);
		if (1 + 0 < p->cost[yyvarid_NT]) {
			p->cost[yyvarid_NT] = 1 + 0;
			p->rule.yyvarid = 1;
		}
		/* constid: ID */
		yytrace(a, 37, 1 + 0, p->cost[yyconstid_NT]);
		if (1 + 0 < p->cost[yyconstid_NT]) {
			p->cost[yyconstid_NT] = 1 + 0;
			p->rule.yyconstid = 1;
		}
		/* constarrayid: ID */
		yytrace(a, 38, 1 + 0, p->cost[yyconstarrayid_NT]);
		if (1 + 0 < p->cost[yyconstarrayid_NT]) {
			p->cost[yyconstarrayid_NT] = 1 + 0;
			p->rule.yyconstarrayid = 1;
		}
		/* arrayid: ID */
		yytrace(a, 39, 1 + 0, p->cost[yyarrayid_NT]);
		if (1 + 0 < p->cost[yyarrayid_NT]) {
			p->cost[yyarrayid_NT] = 1 + 0;
			p->rule.yyarrayid = 1;
		}
		/* alloclval: ID */
		yytrace(a, 88, 1 + 0, p->cost[yyalloclval_NT]);
		if (1 + 0 < p->cost[yyalloclval_NT]) {
			p->cost[yyalloclval_NT] = 1 + 0;
			p->rule.yyalloclval = 1;
		}
		/* lval: ID */
		yytrace(a, 90, 1 + 0, p->cost[yylval_NT]);
		if (1 + 0 < p->cost[yylval_NT]) {
			p->cost[yylval_NT] = 1 + 0;
			p->rule.yylval = 1;
			yyclosure_lval(a, 1 + 0);
		}
		/* lvec: ID */
		yytrace(a, 92, 1 + 0, p->cost[yylvec_NT]);
		if (1 + 0 < p->cost[yylvec_NT]) {
			p->cost[yylvec_NT] = 1 + 0;
			p->rule.yylvec = 1;
		}
		/* lvecassign: ID */
		yytrace(a, 93, 1 + 0, p->cost[yylvecassign_NT]);
		if (1 + 0 < p->cost[yylvecassign_NT]) {
			p->cost[yylvecassign_NT] = 1 + 0;
			p->rule.yylvecassign = 1;
		}
		/* assign: ID */
		yytrace(a, 94, 1 + 0, p->cost[yyassign_NT]);
		if (1 + 0 < p->cost[yyassign_NT]) {
			p->cost[yyassign_NT] = 1 + 0;
			p->rule.yyassign = 1;
		}
		break;
	case 260: /* STR */
		/* firstchar: STR */
		yytrace(a, 50, 1 + 0, p->cost[yyfirstchar_NT]);
		if (1 + 0 < p->cost[yyfirstchar_NT]) {
			p->cost[yyfirstchar_NT] = 1 + 0;
			p->rule.yyfirstchar = 3;
		}
		/* char: STR */
		yytrace(a, 53, 1 + 0, p->cost[yychar_NT]);
		if (1 + 0 < p->cost[yychar_NT]) {
			p->cost[yychar_NT] = 1 + 0;
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
			yytrace(a, 18, c + 0, p->cost[yyfuncname_NT]);
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
			yytrace(a, 19, c + 0, p->cost[yyfuncmain_NT]);
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
			yytrace(a, 12, c + 0, p->cost[yyfarg_NT]);
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
			yytrace(a, 21, c + 0, p->cost[yyfvar_NT]);
			if (c + 0 < p->cost[yyfvar_NT]) {
				p->cost[yyfvar_NT] = c + 0;
				p->rule.yyfvar = 2;
			}
		}
		/* vardecl: STRING(varid,eqstr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyvarid_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyeqstr_NT] + 1;
		yytrace(a, 26, c + 0, p->cost[yyvardecl_NT]);
		if (c + 0 < p->cost[yyvardecl_NT]) {
			p->cost[yyvardecl_NT] = c + 0;
			p->rule.yyvardecl = 2;
		}
		if (	/* vardecl: STRING(ID,NIL) */
			OP_LABEL(LEFT_CHILD(a)) == 259 && /* ID */
			OP_LABEL(RIGHT_CHILD(a)) == 293 /* NIL */
		) {
			c = 1;
			yytrace(a, 30, c + 0, p->cost[yyvardecl_NT]);
			if (c + 0 < p->cost[yyvardecl_NT]) {
				p->cost[yyvardecl_NT] = c + 0;
				p->rule.yyvardecl = 6;
			}
		}
		/* constvardecl: STRING(constid,eqstr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyconstid_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyeqstr_NT] + 1;
		yytrace(a, 35, c + 0, p->cost[yyconstvardecl_NT]);
		if (c + 0 < p->cost[yyconstvardecl_NT]) {
			p->cost[yyconstvardecl_NT] = c + 0;
			p->rule.yyconstvardecl = 2;
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
			yytrace(a, 11, c + 0, p->cost[yyfarg_NT]);
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
			yytrace(a, 20, c + 0, p->cost[yyfvar_NT]);
			if (c + 0 < p->cost[yyfvar_NT]) {
				p->cost[yyfvar_NT] = c + 0;
				p->rule.yyfvar = 1;
			}
		}
		/* vardecl: NUMBER(varid,eqint) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyvarid_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyeqint_NT] + 1;
		yytrace(a, 25, c + 0, p->cost[yyvardecl_NT]);
		if (c + 0 < p->cost[yyvardecl_NT]) {
			p->cost[yyvardecl_NT] = c + 0;
			p->rule.yyvardecl = 1;
		}
		if (	/* vardecl: NUMBER(ID,NIL) */
			OP_LABEL(LEFT_CHILD(a)) == 259 && /* ID */
			OP_LABEL(RIGHT_CHILD(a)) == 293 /* NIL */
		) {
			c = 1;
			yytrace(a, 29, c + 0, p->cost[yyvardecl_NT]);
			if (c + 0 < p->cost[yyvardecl_NT]) {
				p->cost[yyvardecl_NT] = c + 0;
				p->rule.yyvardecl = 5;
			}
		}
		/* constvardecl: NUMBER(constid,eqint) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyconstid_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyeqint_NT] + 1;
		yytrace(a, 34, c + 0, p->cost[yyconstvardecl_NT]);
		if (c + 0 < p->cost[yyconstvardecl_NT]) {
			p->cost[yyconstvardecl_NT] = c + 0;
			p->rule.yyconstvardecl = 1;
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
			yytrace(a, 13, c + 0, p->cost[yyfarg_NT]);
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
			yytrace(a, 22, c + 0, p->cost[yyfvar_NT]);
			if (c + 0 < p->cost[yyfvar_NT]) {
				p->cost[yyfvar_NT] = c + 0;
				p->rule.yyfvar = 3;
			}
		}
		if (	/* vardecl: ARRAY(arrayid,INTS(vdim,eqvec)) */
			OP_LABEL(RIGHT_CHILD(a)) == 288 /* INTS */
		) {
			c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyarrayid_NT] + ((struct yystate *)STATE_LABEL(LEFT_CHILD(RIGHT_CHILD(a))))->cost[yyvdim_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(RIGHT_CHILD(a))))->cost[yyeqvec_NT] + 1;
			yytrace(a, 27, c + 0, p->cost[yyvardecl_NT]);
			if (c + 0 < p->cost[yyvardecl_NT]) {
				p->cost[yyvardecl_NT] = c + 0;
				p->rule.yyvardecl = 3;
			}
		}
		if (	/* vardecl: ARRAY(arrayid,INTS(NIL,eqvec)) */
			OP_LABEL(RIGHT_CHILD(a)) == 288 && /* INTS */
			OP_LABEL(LEFT_CHILD(RIGHT_CHILD(a))) == 293 /* NIL */
		) {
			c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyarrayid_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(RIGHT_CHILD(a))))->cost[yyeqvec_NT] + 1;
			yytrace(a, 28, c + 0, p->cost[yyvardecl_NT]);
			if (c + 0 < p->cost[yyvardecl_NT]) {
				p->cost[yyvardecl_NT] = c + 0;
				p->rule.yyvardecl = 4;
			}
		}
		if (	/* vardecl: ARRAY(ID,INTS(vdim,NIL)) */
			OP_LABEL(LEFT_CHILD(a)) == 259 && /* ID */
			OP_LABEL(RIGHT_CHILD(a)) == 288 && /* INTS */
			OP_LABEL(RIGHT_CHILD(RIGHT_CHILD(a))) == 293 /* NIL */
		) {
			c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(RIGHT_CHILD(a))))->cost[yyvdim_NT] + 1;
			yytrace(a, 31, c + 0, p->cost[yyvardecl_NT]);
			if (c + 0 < p->cost[yyvardecl_NT]) {
				p->cost[yyvardecl_NT] = c + 0;
				p->rule.yyvardecl = 7;
			}
		}
		if (	/* vardecl: ARRAY(ID,INTS(NIL,NIL)) */
			OP_LABEL(LEFT_CHILD(a)) == 259 && /* ID */
			OP_LABEL(RIGHT_CHILD(a)) == 288 && /* INTS */
			OP_LABEL(LEFT_CHILD(RIGHT_CHILD(a))) == 293 && /* NIL */
			OP_LABEL(RIGHT_CHILD(RIGHT_CHILD(a))) == 293 /* NIL */
		) {
			c = 1;
			yytrace(a, 32, c + 0, p->cost[yyvardecl_NT]);
			if (c + 0 < p->cost[yyvardecl_NT]) {
				p->cost[yyvardecl_NT] = c + 0;
				p->rule.yyvardecl = 8;
			}
		}
		if (	/* constvardecl: ARRAY(constarrayid,INTS(vdim,eqvec)) */
			OP_LABEL(RIGHT_CHILD(a)) == 288 /* INTS */
		) {
			c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyconstarrayid_NT] + ((struct yystate *)STATE_LABEL(LEFT_CHILD(RIGHT_CHILD(a))))->cost[yyvdim_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(RIGHT_CHILD(a))))->cost[yyeqvec_NT] + 1;
			yytrace(a, 36, c + 0, p->cost[yyconstvardecl_NT]);
			if (c + 0 < p->cost[yyconstvardecl_NT]) {
				p->cost[yyconstvardecl_NT] = c + 0;
				p->rule.yyconstvardecl = 3;
			}
		}
		break;
	case 269: /* FUNCTION */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		if (	/* decl: FUNCTION(funcname,FARGS(funcargs,NIL)) */
			OP_LABEL(RIGHT_CHILD(a)) == 286 && /* FARGS */
			OP_LABEL(RIGHT_CHILD(RIGHT_CHILD(a))) == 293 /* NIL */
		) {
			c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyfuncname_NT] + ((struct yystate *)STATE_LABEL(LEFT_CHILD(RIGHT_CHILD(a))))->cost[yyfuncargs_NT] + 1;
			yytrace(a, 9, c + 0, p->cost[yydecl_NT]);
			if (c + 0 < p->cost[yydecl_NT]) {
				p->cost[yydecl_NT] = c + 0;
				p->rule.yydecl = 3;
			}
		}
		if (	/* decl: FUNCTION(funcname,FARGS(funcargs,eqbody)) */
			OP_LABEL(RIGHT_CHILD(a)) == 286 /* FARGS */
		) {
			c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyfuncname_NT] + ((struct yystate *)STATE_LABEL(LEFT_CHILD(RIGHT_CHILD(a))))->cost[yyfuncargs_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(RIGHT_CHILD(a))))->cost[yyeqbody_NT] + 1;
			yytrace(a, 10, c + 0, p->cost[yydecl_NT]);
			if (c + 0 < p->cost[yydecl_NT]) {
				p->cost[yydecl_NT] = c + 0;
				p->rule.yydecl = 4;
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
		yytrace(a, 77, c + 0, p->cost[yyif_NT]);
		if (c + 0 < p->cost[yyif_NT]) {
			p->cost[yyif_NT] = c + 0;
			p->rule.yyif = 1;
		}
		/* ifelse: IF(cond,block) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yycond_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyblock_NT] + 0;
		yytrace(a, 78, c + 0, p->cost[yyifelse_NT]);
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
			yytrace(a, 71, c + 0, p->cost[yyinstr_NT]);
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
		yytrace(a, 85, c + 0, p->cost[yyelifs_NT]);
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
			yytrace(a, 61, c + 0, p->cost[yyret_NT]);
			if (c + 0 < p->cost[yyret_NT]) {
				p->cost[yyret_NT] = c + 0;
				p->rule.yyret = 1;
				yyclosure_ret(a, c + 0);
			}
		}
		/* ret: RETURN(expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 62, c + 0, p->cost[yyret_NT]);
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
		yytrace(a, 55, c + 0, p->cost[yymain_NT]);
		if (c + 0 < p->cost[yymain_NT]) {
			p->cost[yymain_NT] = c + 0;
			p->rule.yymain = 1;
		}
		if (	/* body: START(bodyfvars,STMT(instrs,ret)) */
			OP_LABEL(RIGHT_CHILD(a)) == 59 /* STMT */
		) {
			c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yybodyfvars_NT] + ((struct yystate *)STATE_LABEL(LEFT_CHILD(RIGHT_CHILD(a))))->cost[yyinstrs_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(RIGHT_CHILD(a))))->cost[yyret_NT] + 1;
			yytrace(a, 58, c + 0, p->cost[yybody_NT]);
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
			yytrace(a, 72, c + 0, p->cost[yyinstr_NT]);
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
		yytrace(a, 65, 1 + 0, p->cost[yyloop_NT]);
		if (1 + 0 < p->cost[yyloop_NT]) {
			p->cost[yyloop_NT] = 1 + 0;
			p->rule.yyloop = 2;
		}
		break;
	case 285: /* STOP */
		/* loop: STOP */
		yytrace(a, 66, 1 + 0, p->cost[yyloop_NT]);
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
		if (	/* chars: CHARS(NIL,firstchar) */
			OP_LABEL(LEFT_CHILD(a)) == 293 /* NIL */
		) {
			c = ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyfirstchar_NT] + 1;
			yytrace(a, 46, c + 0, p->cost[yychars_NT]);
			if (c + 0 < p->cost[yychars_NT]) {
				p->cost[yychars_NT] = c + 0;
				p->rule.yychars = 1;
				yyclosure_chars(a, c + 0);
			}
		}
		/* chars: CHARS(chars,char) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yychars_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yychar_NT] + 1;
		yytrace(a, 47, c + 0, p->cost[yychars_NT]);
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
			yytrace(a, 96, c + 0, p->cost[yyexpr_NT]);
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
			yytrace(a, 97, c + 0, p->cost[yyexpr_NT]);
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
			yytrace(a, 98, c + 0, p->cost[yyexpr_NT]);
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
			yytrace(a, 43, c + 0, p->cost[yyints_NT]);
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
		yytrace(a, 102, c + 0, p->cost[yyexpr_NT]);
		if (c + 0 < p->cost[yyexpr_NT]) {
			p->cost[yyexpr_NT] = c + 0;
			p->rule.yyexpr = 7;
			yyclosure_expr(a, c + 0);
		}
		break;
	case 290: /* VAR */
		yylabel(LEFT_CHILD(a),a);
		/* decl: VAR(vardecl) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyvardecl_NT] + (varCost(a));
		yytrace(a, 7, c + 0, p->cost[yydecl_NT]);
		if (c + 0 < p->cost[yydecl_NT]) {
			p->cost[yydecl_NT] = c + 0;
			p->rule.yydecl = 1;
		}
		/* decl: VAR(constvardecl) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyconstvardecl_NT] + (cnstCost(a));
		yytrace(a, 8, c + 0, p->cost[yydecl_NT]);
		if (c + 0 < p->cost[yydecl_NT]) {
			p->cost[yydecl_NT] = c + 0;
			p->rule.yydecl = 2;
		}
		break;
	case 291: /* ARGS */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		if (	/* fargs: ARGS(NIL,farg) */
			OP_LABEL(LEFT_CHILD(a)) == 293 /* NIL */
		) {
			c = ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyfarg_NT] + 1;
			yytrace(a, 15, c + 0, p->cost[yyfargs_NT]);
			if (c + 0 < p->cost[yyfargs_NT]) {
				p->cost[yyfargs_NT] = c + 0;
				p->rule.yyfargs = 2;
				yyclosure_fargs(a, c + 0);
			}
		}
		/* fargs: ARGS(fargs,farg) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyfargs_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyfarg_NT] + 1;
		yytrace(a, 16, c + 0, p->cost[yyfargs_NT]);
		if (c + 0 < p->cost[yyfargs_NT]) {
			p->cost[yyfargs_NT] = c + 0;
			p->rule.yyfargs = 3;
			yyclosure_fargs(a, c + 0);
		}
		if (	/* fvars: ARGS(NIL,fvar) */
			OP_LABEL(LEFT_CHILD(a)) == 293 /* NIL */
		) {
			c = ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyfvar_NT] + 1;
			yytrace(a, 23, c + 0, p->cost[yyfvars_NT]);
			if (c + 0 < p->cost[yyfvars_NT]) {
				p->cost[yyfvars_NT] = c + 0;
				p->rule.yyfvars = 1;
				yyclosure_fvars(a, c + 0);
			}
		}
		/* fvars: ARGS(fvars,fvar) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyfvars_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyfvar_NT] + 1;
		yytrace(a, 24, c + 0, p->cost[yyfvars_NT]);
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
		yytrace(a, 14, 1 + 0, p->cost[yyfargs_NT]);
		if (1 + 0 < p->cost[yyfargs_NT]) {
			p->cost[yyfargs_NT] = 1 + 0;
			p->rule.yyfargs = 1;
			yyclosure_fargs(a, 1 + 0);
		}
		/* mainfvars: NIL */
		yytrace(a, 56, 1 + 0, p->cost[yymainfvars_NT]);
		if (1 + 0 < p->cost[yymainfvars_NT]) {
			p->cost[yymainfvars_NT] = 1 + 0;
			p->rule.yymainfvars = 1;
		}
		/* bodyfvars: NIL */
		yytrace(a, 59, 1 + 0, p->cost[yybodyfvars_NT]);
		if (1 + 0 < p->cost[yybodyfvars_NT]) {
			p->cost[yybodyfvars_NT] = 1 + 0;
			p->rule.yybodyfvars = 1;
		}
		/* ret: NIL */
		yytrace(a, 63, 1 + 0, p->cost[yyret_NT]);
		if (1 + 0 < p->cost[yyret_NT]) {
			p->cost[yyret_NT] = 1 + 0;
			p->rule.yyret = 3;
			yyclosure_ret(a, 1 + 0);
		}
		/* instrs: NIL */
		yytrace(a, 69, 1 + 0, p->cost[yyinstrs_NT]);
		if (1 + 0 < p->cost[yyinstrs_NT]) {
			p->cost[yyinstrs_NT] = 1 + 0;
			p->rule.yyinstrs = 1;
		}
		/* elifs: NIL */
		yytrace(a, 84, 0 + 0, p->cost[yyelifs_NT]);
		if (0 + 0 < p->cost[yyelifs_NT]) {
			p->cost[yyelifs_NT] = 0 + 0;
			p->rule.yyelifs = 1;
		}
		/* else: NIL */
		yytrace(a, 86, 0 + 0, p->cost[yyelse_NT]);
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
		yytrace(a, 121, c + 0, p->cost[yyexpr_NT]);
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
		yytrace(a, 110, c + 0, p->cost[yyexpr_NT]);
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
		yytrace(a, 111, c + 0, p->cost[yyexpr_NT]);
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
		yytrace(a, 112, c + 0, p->cost[yyexpr_NT]);
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
		yytrace(a, 120, c + 0, p->cost[yyexpr_NT]);
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
	case 123: /* exprs: COMMA(expr,NIL) */
	case 120: /* expr: UMINUS(expr) */
	case 119: /* expr: NOT(expr) */
	case 102: /* expr: ADDR(lval) */
	case 73: /* instr: PRINT(expr) */
	case 62: /* ret: RETURN(expr) */
	case 43: /* ints: INTS(ints,INT) */
	case 8: /* decl: VAR(constvardecl) */
	case 7: /* decl: VAR(vardecl) */
	case 2: /* program: MODULE(decls) */
		kids[0] = LEFT_CHILD(p);
		break;
	case 101: /* expr: READ */
	case 98: /* expr: CHARS(NIL,STR) */
	case 97: /* expr: CHARS(NIL,CHAR) */
	case 96: /* expr: CHARS(NIL,INT) */
	case 94: /* assign: ID */
	case 93: /* lvecassign: ID */
	case 92: /* lvec: ID */
	case 90: /* lval: ID */
	case 88: /* alloclval: ID */
	case 86: /* else: NIL */
	case 84: /* elifs: NIL */
	case 69: /* instrs: NIL */
	case 66: /* loop: STOP */
	case 65: /* loop: REPEAT */
	case 63: /* ret: NIL */
	case 61: /* ret: RETURN(NIL) */
	case 59: /* bodyfvars: NIL */
	case 56: /* mainfvars: NIL */
	case 53: /* char: STR */
	case 52: /* char: CHAR */
	case 51: /* char: INT */
	case 50: /* firstchar: STR */
	case 49: /* firstchar: CHAR */
	case 48: /* firstchar: INT */
	case 44: /* eqint: INT */
	case 42: /* ints: INT */
	case 40: /* vdim: INT */
	case 39: /* arrayid: ID */
	case 38: /* constarrayid: ID */
	case 37: /* constid: ID */
	case 33: /* varid: ID */
	case 32: /* vardecl: ARRAY(ID,INTS(NIL,NIL)) */
	case 30: /* vardecl: STRING(ID,NIL) */
	case 29: /* vardecl: NUMBER(ID,NIL) */
	case 21: /* fvar: STRING(ID,NIL) */
	case 20: /* fvar: NUMBER(ID,NIL) */
	case 19: /* funcmain: END(ID,INT) */
	case 18: /* funcname: END(ID,INT) */
	case 14: /* fargs: NIL */
	case 12: /* farg: STRING(ID,NIL) */
	case 11: /* farg: NUMBER(ID,NIL) */
	case 3: /* decls: NIL */
		break;
	case 118: /* or: expr */
	case 116: /* and: expr */
	case 100: /* expr: lval */
	case 99: /* expr: chars */
	case 87: /* else: block */
	case 83: /* trashexpr: expr */
	case 82: /* cond: expr */
	case 81: /* postexpr: trashexpr */
	case 80: /* forcond: expr */
	case 79: /* init: trashexpr */
	case 76: /* alloc: expr */
	case 74: /* instr: expr */
	case 64: /* loop: ret */
	case 60: /* bodyfvars: fvars */
	case 57: /* mainfvars: fvars */
	case 54: /* eqbody: body */
	case 45: /* eqstr: chars */
	case 41: /* eqvec: ints */
	case 17: /* funcargs: fargs */
	case 4: /* decls: gdecls */
		kids[0] = p;
		break;
	case 124: /* exprs: COMMA(expr,exprs) */
	case 121: /* expr: EQ(expr,assign) */
	case 117: /* expr: OR(or,expr) */
	case 115: /* expr: AND(and,expr) */
	case 114: /* expr: GT(expr,expr) */
	case 113: /* expr: LT(expr,expr) */
	case 112: /* expr: LE(expr,expr) */
	case 111: /* expr: GE(expr,expr) */
	case 110: /* expr: NE(expr,expr) */
	case 109: /* expr: EQU(expr,expr) */
	case 108: /* expr: POW(expr,expr) */
	case 107: /* expr: MOD(expr,expr) */
	case 106: /* expr: DIV(expr,expr) */
	case 105: /* expr: MUL(expr,expr) */
	case 104: /* expr: SUB(expr,expr) */
	case 103: /* expr: ADD(expr,expr) */
	case 95: /* assign: INDEX(lvecassign,expr) */
	case 91: /* lval: INDEX(lvec,expr) */
	case 89: /* alloclval: INDEX(alloclval,expr) */
	case 85: /* elifs: ELIF(elifs,ifelse) */
	case 78: /* ifelse: IF(cond,block) */
	case 77: /* if: IF(cond,block) */
	case 75: /* instr: ALLOC(alloc,alloclval) */
	case 70: /* instrs: STMT(instrs,instr) */
	case 68: /* forblock: STMT(instrs,loop) */
	case 67: /* block: STMT(instrs,loop) */
	case 55: /* main: START(mainfvars,instrs) */
	case 47: /* chars: CHARS(chars,char) */
	case 35: /* constvardecl: STRING(constid,eqstr) */
	case 34: /* constvardecl: NUMBER(constid,eqint) */
	case 26: /* vardecl: STRING(varid,eqstr) */
	case 25: /* vardecl: NUMBER(varid,eqint) */
	case 24: /* fvars: ARGS(fvars,fvar) */
	case 16: /* fargs: ARGS(fargs,farg) */
	case 5: /* gdecls: DECL(gdecls,decl) */
		kids[0] = LEFT_CHILD(p);
		kids[1] = RIGHT_CHILD(p);
		break;
	case 122: /* expr: IDARGS(ID,exprs) */
	case 46: /* chars: CHARS(NIL,firstchar) */
	case 23: /* fvars: ARGS(NIL,fvar) */
	case 15: /* fargs: ARGS(NIL,farg) */
	case 6: /* gdecls: DECL(NIL,decl) */
		kids[0] = RIGHT_CHILD(p);
		break;
	case 9: /* decl: FUNCTION(funcname,FARGS(funcargs,NIL)) */
		kids[0] = LEFT_CHILD(p);
		kids[1] = LEFT_CHILD(RIGHT_CHILD(p));
		break;
	case 58: /* body: START(bodyfvars,STMT(instrs,ret)) */
	case 36: /* constvardecl: ARRAY(constarrayid,INTS(vdim,eqvec)) */
	case 27: /* vardecl: ARRAY(arrayid,INTS(vdim,eqvec)) */
	case 10: /* decl: FUNCTION(funcname,FARGS(funcargs,eqbody)) */
		kids[0] = LEFT_CHILD(p);
		kids[1] = LEFT_CHILD(RIGHT_CHILD(p));
		kids[2] = RIGHT_CHILD(RIGHT_CHILD(p));
		break;
	case 31: /* vardecl: ARRAY(ID,INTS(vdim,NIL)) */
	case 22: /* fvar: ARRAY(ID,INTS(vdim,NIL)) */
	case 13: /* farg: ARRAY(ID,INTS(vdim,NIL)) */
		kids[0] = LEFT_CHILD(RIGHT_CHILD(p));
		break;
	case 28: /* vardecl: ARRAY(arrayid,INTS(NIL,eqvec)) */
		kids[0] = LEFT_CHILD(p);
		kids[1] = RIGHT_CHILD(RIGHT_CHILD(p));
		break;
	case 71: /* instr: FI(THEN(if,elifs),else) */
		kids[0] = LEFT_CHILD(LEFT_CHILD(p));
		kids[1] = RIGHT_CHILD(LEFT_CHILD(p));
		kids[2] = RIGHT_CHILD(p);
		break;
	case 72: /* instr: FOR(UNTIL(init,forcond),STEP(forblock,postexpr)) */
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
		fprintf(stderr, "0x%lx: line 131: program: PROGRAM(decls,FUNCTION(funcmain,FARGS(NIL,main)))\n",(long)p);
#line 131 "minor.brg"
{ final(); }
		break;
	case 2: /* program: MODULE(decls) */
		fprintf(stderr, "0x%lx: line 132: program: MODULE(decls)\n",(long)p);
#line 132 "minor.brg"
{}
		break;
	case 3: /* decls: NIL */
		fprintf(stderr, "0x%lx: line 134: decls: NIL\n",(long)p);
#line 134 "minor.brg"
{}
		break;
	case 4: /* decls: gdecls */
		fprintf(stderr, "0x%lx: line 135: decls: gdecls\n",(long)p);
#line 135 "minor.brg"
{}
		break;
	case 5: /* gdecls: DECL(gdecls,decl) */
		fprintf(stderr, "0x%lx: line 137: gdecls: DECL(gdecls,decl)\n",(long)p);
#line 137 "minor.brg"
{}
		break;
	case 6: /* gdecls: DECL(NIL,decl) */
		fprintf(stderr, "0x%lx: line 138: gdecls: DECL(NIL,decl)\n",(long)p);
#line 138 "minor.brg"
{}
		break;
	case 7: /* decl: VAR(vardecl) */
		fprintf(stderr, "0x%lx: line 140: decl: VAR(vardecl)\n",(long)p);
#line 140 "minor.brg"
{}
		break;
	case 8: /* decl: VAR(constvardecl) */
		fprintf(stderr, "0x%lx: line 141: decl: VAR(constvardecl)\n",(long)p);
#line 141 "minor.brg"
{}
		break;
	case 9: /* decl: FUNCTION(funcname,FARGS(funcargs,NIL)) */
		fprintf(stderr, "0x%lx: line 142: decl: FUNCTION(funcname,FARGS(funcargs,NIL))\n",(long)p);
#line 142 "minor.brg"
{ extrns[extcnt++] = dupstr(mkfunc(LEFT_CHILD(LEFT_CHILD(p))->value.s)); }
		break;
	case 10: /* decl: FUNCTION(funcname,FARGS(funcargs,eqbody)) */
		fprintf(stderr, "0x%lx: line 143: decl: FUNCTION(funcname,FARGS(funcargs,eqbody))\n",(long)p);
#line 143 "minor.brg"
{ fprintf(yyout, pfLEAVE pfRET); }
		break;
	case 11: /* farg: NUMBER(ID,NIL) */
		fprintf(stderr, "0x%lx: line 145: farg: NUMBER(ID,NIL)\n",(long)p);
#line 145 "minor.brg"
{ IDnew(-1, LEFT_CHILD(p)->value.s, pos); pos += 4; }
		break;
	case 12: /* farg: STRING(ID,NIL) */
		fprintf(stderr, "0x%lx: line 146: farg: STRING(ID,NIL)\n",(long)p);
#line 146 "minor.brg"
{ IDnew(-1, LEFT_CHILD(p)->value.s, pos); pos += 4; }
		break;
	case 13: /* farg: ARRAY(ID,INTS(vdim,NIL)) */
		fprintf(stderr, "0x%lx: line 147: farg: ARRAY(ID,INTS(vdim,NIL))\n",(long)p);
#line 147 "minor.brg"
{ IDnew(-1, LEFT_CHILD(p)->value.s, pos); pos += 4; }
		break;
	case 14: /* fargs: NIL */
		fprintf(stderr, "0x%lx: line 149: fargs: NIL\n",(long)p);
#line 149 "minor.brg"
{}
		break;
	case 15: /* fargs: ARGS(NIL,farg) */
		fprintf(stderr, "0x%lx: line 150: fargs: ARGS(NIL,farg)\n",(long)p);
#line 150 "minor.brg"
{}
		break;
	case 16: /* fargs: ARGS(fargs,farg) */
		fprintf(stderr, "0x%lx: line 151: fargs: ARGS(fargs,farg)\n",(long)p);
#line 151 "minor.brg"
{}
		break;
	case 17: /* funcargs: fargs */
		fprintf(stderr, "0x%lx: line 153: funcargs: fargs\n",(long)p);
#line 153 "minor.brg"
{ pos = 0; }
		break;
	case 18: /* funcname: END(ID,INT) */
		fprintf(stderr, "0x%lx: line 155: funcname: END(ID,INT)\n",(long)p);
#line 155 "minor.brg"
{ IDpush(); pos = 8; currentfunc = LEFT_CHILD(p)->value.s; }
		break;
	case 19: /* funcmain: END(ID,INT) */
		fprintf(stderr, "0x%lx: line 156: funcmain: END(ID,INT)\n",(long)p);
#line 156 "minor.brg"
{ IDpush(); pos = 0; }
		break;
	case 20: /* fvar: NUMBER(ID,NIL) */
		fprintf(stderr, "0x%lx: line 158: fvar: NUMBER(ID,NIL)\n",(long)p);
#line 158 "minor.brg"
{ IDnew(-1, LEFT_CHILD(p)->value.s, pos -= 4); }
		break;
	case 21: /* fvar: STRING(ID,NIL) */
		fprintf(stderr, "0x%lx: line 159: fvar: STRING(ID,NIL)\n",(long)p);
#line 159 "minor.brg"
{ IDnew(-1, LEFT_CHILD(p)->value.s, pos -= 4); }
		break;
	case 22: /* fvar: ARRAY(ID,INTS(vdim,NIL)) */
		fprintf(stderr, "0x%lx: line 160: fvar: ARRAY(ID,INTS(vdim,NIL))\n",(long)p);
#line 160 "minor.brg"
{ IDnew(-1, LEFT_CHILD(p)->value.s, pos -= 4); }
		break;
	case 23: /* fvars: ARGS(NIL,fvar) */
		fprintf(stderr, "0x%lx: line 162: fvars: ARGS(NIL,fvar)\n",(long)p);
#line 162 "minor.brg"
{}
		break;
	case 24: /* fvars: ARGS(fvars,fvar) */
		fprintf(stderr, "0x%lx: line 163: fvars: ARGS(fvars,fvar)\n",(long)p);
#line 163 "minor.brg"
{}
		break;
	case 25: /* vardecl: NUMBER(varid,eqint) */
		fprintf(stderr, "0x%lx: line 165: vardecl: NUMBER(varid,eqint)\n",(long)p);
#line 165 "minor.brg"
{}
		break;
	case 26: /* vardecl: STRING(varid,eqstr) */
		fprintf(stderr, "0x%lx: line 166: vardecl: STRING(varid,eqstr)\n",(long)p);
#line 166 "minor.brg"
{ fprintf(yyout, pfCHAR pfDATA pfID, 0, mklbl(RIGHT_CHILD(p)->place)); }
		break;
	case 27: /* vardecl: ARRAY(arrayid,INTS(vdim,eqvec)) */
		fprintf(stderr, "0x%lx: line 167: vardecl: ARRAY(arrayid,INTS(vdim,eqvec))\n",(long)p);
#line 167 "minor.brg"
{ initRemaining(LEFT_CHILD(RIGHT_CHILD(p))->value.i); }
		break;
	case 28: /* vardecl: ARRAY(arrayid,INTS(NIL,eqvec)) */
		fprintf(stderr, "0x%lx: line 168: vardecl: ARRAY(arrayid,INTS(NIL,eqvec))\n",(long)p);
#line 168 "minor.brg"
{}
		break;
	case 29: /* vardecl: NUMBER(ID,NIL) */
		fprintf(stderr, "0x%lx: line 169: vardecl: NUMBER(ID,NIL)\n",(long)p);
#line 169 "minor.brg"
{ if (LEFT_CHILD(p)->info & tFWD) extrns[extcnt++] = dupstr(LEFT_CHILD(p)->value.s); else fprintf(yyout, pfBSS pfALIGN pfLABEL pfBYTE, LEFT_CHILD(p)->value.s, pfWORD); }
		break;
	case 30: /* vardecl: STRING(ID,NIL) */
		fprintf(stderr, "0x%lx: line 170: vardecl: STRING(ID,NIL)\n",(long)p);
#line 170 "minor.brg"
{ if (LEFT_CHILD(p)->info & tFWD) extrns[extcnt++] = dupstr(LEFT_CHILD(p)->value.s); else fprintf(yyout, pfBSS pfALIGN pfLABEL, LEFT_CHILD(p)->value.s); }
		break;
	case 31: /* vardecl: ARRAY(ID,INTS(vdim,NIL)) */
		fprintf(stderr, "0x%lx: line 171: vardecl: ARRAY(ID,INTS(vdim,NIL))\n",(long)p);
#line 171 "minor.brg"
{ if (LEFT_CHILD(p)->info & tFWD) extrns[extcnt++] = dupstr(LEFT_CHILD(p)->value.s); else fprintf(yyout, pfBSS pfALIGN pfLABEL, LEFT_CHILD(p)->value.s); }
		break;
	case 32: /* vardecl: ARRAY(ID,INTS(NIL,NIL)) */
		fprintf(stderr, "0x%lx: line 172: vardecl: ARRAY(ID,INTS(NIL,NIL))\n",(long)p);
#line 172 "minor.brg"
{ if (LEFT_CHILD(p)->info & tFWD) extrns[extcnt++] = dupstr(LEFT_CHILD(p)->value.s); else fprintf(yyout, pfBSS pfALIGN pfLABEL, LEFT_CHILD(p)->value.s); }
		break;
	case 33: /* varid: ID */
		fprintf(stderr, "0x%lx: line 174: varid: ID\n",(long)p);
#line 174 "minor.brg"
{ fprintf(yyout, pfGLOBL pfDATA pfALIGN pfLABEL, p->value.s, pfOBJ, p->value.s); }
		break;
	case 34: /* constvardecl: NUMBER(constid,eqint) */
		fprintf(stderr, "0x%lx: line 176: constvardecl: NUMBER(constid,eqint)\n",(long)p);
#line 176 "minor.brg"
{}
		break;
	case 35: /* constvardecl: STRING(constid,eqstr) */
		fprintf(stderr, "0x%lx: line 177: constvardecl: STRING(constid,eqstr)\n",(long)p);
#line 177 "minor.brg"
{ fprintf(yyout, pfCHAR pfDATA pfID, 0, mklbl(RIGHT_CHILD(p)->place)); }
		break;
	case 36: /* constvardecl: ARRAY(constarrayid,INTS(vdim,eqvec)) */
		fprintf(stderr, "0x%lx: line 178: constvardecl: ARRAY(constarrayid,INTS(vdim,eqvec))\n",(long)p);
#line 178 "minor.brg"
{}
		break;
	case 37: /* constid: ID */
		fprintf(stderr, "0x%lx: line 180: constid: ID\n",(long)p);
#line 180 "minor.brg"
{ fprintf(yyout, pfGLOBL pfRODATA pfALIGN pfLABEL, p->value.s, pfOBJ, p->value.s); }
		break;
	case 38: /* constarrayid: ID */
		fprintf(stderr, "0x%lx: line 181: constarrayid: ID\n",(long)p);
#line 181 "minor.brg"
{ fprintf(yyout, pfGLOBL pfRODATA pfALIGN pfLABEL, p->value.s, pfOBJ, p->value.s); ++lbl; fprintf(yyout, pfID pfLABEL, mklbl(lbl), mklbl(lbl)); }
		break;
	case 39: /* arrayid: ID */
		fprintf(stderr, "0x%lx: line 183: arrayid: ID\n",(long)p);
#line 183 "minor.brg"
{ fprintf(yyout, pfGLOBL pfDATA pfALIGN pfLABEL, p->value.s, pfOBJ, p->value.s); ++lbl; fprintf(yyout, pfID pfLABEL, mklbl(lbl), mklbl(lbl)); }
		break;
	case 40: /* vdim: INT */
		fprintf(stderr, "0x%lx: line 185: vdim: INT\n",(long)p);
#line 185 "minor.brg"
{}
		break;
	case 41: /* eqvec: ints */
		fprintf(stderr, "0x%lx: line 187: eqvec: ints\n",(long)p);
#line 187 "minor.brg"
{}
		break;
	case 42: /* ints: INT */
		fprintf(stderr, "0x%lx: line 189: ints: INT\n",(long)p);
#line 189 "minor.brg"
{ fprintf(yyout, pfINTEGER, p->value.i); initints = 1; }
		break;
	case 43: /* ints: INTS(ints,INT) */
		fprintf(stderr, "0x%lx: line 190: ints: INTS(ints,INT)\n",(long)p);
#line 190 "minor.brg"
{ fprintf(yyout, pfINTEGER, RIGHT_CHILD(p)->value.i); initints++; }
		break;
	case 44: /* eqint: INT */
		fprintf(stderr, "0x%lx: line 192: eqint: INT\n",(long)p);
#line 192 "minor.brg"
{ fprintf(yyout, pfINTEGER, p->value.i); }
		break;
	case 45: /* eqstr: chars */
		fprintf(stderr, "0x%lx: line 194: eqstr: chars\n",(long)p);
#line 194 "minor.brg"
{}
		break;
	case 46: /* chars: CHARS(NIL,firstchar) */
		fprintf(stderr, "0x%lx: line 196: chars: CHARS(NIL,firstchar)\n",(long)p);
#line 196 "minor.brg"
{ p->place = RIGHT_CHILD(p)->place; }
		break;
	case 47: /* chars: CHARS(chars,char) */
		fprintf(stderr, "0x%lx: line 197: chars: CHARS(chars,char)\n",(long)p);
#line 197 "minor.brg"
{ p->place = LEFT_CHILD(p)->place; }
		break;
	case 48: /* firstchar: INT */
		fprintf(stderr, "0x%lx: line 199: firstchar: INT\n",(long)p);
#line 199 "minor.brg"
{ p->place = lbl++; fprintf(yyout, pfRODATA pfALIGN pfLABEL pfCHAR, mklbl(p->place), p->value.i); }
		break;
	case 49: /* firstchar: CHAR */
		fprintf(stderr, "0x%lx: line 200: firstchar: CHAR\n",(long)p);
#line 200 "minor.brg"
{ p->place = lbl++; fprintf(yyout, pfRODATA pfALIGN pfLABEL pfCHAR, mklbl(p->place), p->value.i); }
		break;
	case 50: /* firstchar: STR */
		fprintf(stderr, "0x%lx: line 201: firstchar: STR\n",(long)p);
#line 201 "minor.brg"
{ p->place = lbl++; fprintf(yyout, pfRODATA pfALIGN pfLABEL, mklbl(p->place)); outstr(p->value.s); }
		break;
	case 51: /* char: INT */
		fprintf(stderr, "0x%lx: line 203: char: INT\n",(long)p);
#line 203 "minor.brg"
{ fprintf(yyout, pfCHAR, p->value.i); }
		break;
	case 52: /* char: CHAR */
		fprintf(stderr, "0x%lx: line 204: char: CHAR\n",(long)p);
#line 204 "minor.brg"
{ fprintf(yyout, pfCHAR, p->value.i); }
		break;
	case 53: /* char: STR */
		fprintf(stderr, "0x%lx: line 205: char: STR\n",(long)p);
#line 205 "minor.brg"
{ outstr(p->value.s); }
		break;
	case 54: /* eqbody: body */
		fprintf(stderr, "0x%lx: line 207: eqbody: body\n",(long)p);
#line 207 "minor.brg"
{}
		break;
	case 55: /* main: START(mainfvars,instrs) */
		fprintf(stderr, "0x%lx: line 209: main: START(mainfvars,instrs)\n",(long)p);
#line 209 "minor.brg"
{ IDpop(); }
		break;
	case 56: /* mainfvars: NIL */
		fprintf(stderr, "0x%lx: line 211: mainfvars: NIL\n",(long)p);
#line 211 "minor.brg"
{ function("main", 0); }
		break;
	case 57: /* mainfvars: fvars */
		fprintf(stderr, "0x%lx: line 212: mainfvars: fvars\n",(long)p);
#line 212 "minor.brg"
{ function("main", -pos); }
		break;
	case 58: /* body: START(bodyfvars,STMT(instrs,ret)) */
		fprintf(stderr, "0x%lx: line 214: body: START(bodyfvars,STMT(instrs,ret))\n",(long)p);
#line 214 "minor.brg"
{}
		break;
	case 59: /* bodyfvars: NIL */
		fprintf(stderr, "0x%lx: line 216: bodyfvars: NIL\n",(long)p);
#line 216 "minor.brg"
{ function(currentfunc, 0); }
		break;
	case 60: /* bodyfvars: fvars */
		fprintf(stderr, "0x%lx: line 217: bodyfvars: fvars\n",(long)p);
#line 217 "minor.brg"
{ function(currentfunc, -pos); }
		break;
	case 61: /* ret: RETURN(NIL) */
		fprintf(stderr, "0x%lx: line 219: ret: RETURN(NIL)\n",(long)p);
#line 219 "minor.brg"
{ fprintf(yyout, pfLEAVE pfRET); }
		break;
	case 62: /* ret: RETURN(expr) */
		fprintf(stderr, "0x%lx: line 220: ret: RETURN(expr)\n",(long)p);
#line 220 "minor.brg"
{ fprintf(yyout, pfPOP pfLEAVE pfRET); }
		break;
	case 63: /* ret: NIL */
		fprintf(stderr, "0x%lx: line 221: ret: NIL\n",(long)p);
#line 221 "minor.brg"
{}
		break;
	case 64: /* loop: ret */
		fprintf(stderr, "0x%lx: line 223: loop: ret\n",(long)p);
#line 223 "minor.brg"
{}
		break;
	case 65: /* loop: REPEAT */
		fprintf(stderr, "0x%lx: line 224: loop: REPEAT\n",(long)p);
#line 224 "minor.brg"
{ p->place = repeatlbl[forcnt]; fprintf(yyout, pfJMP, mklbl(p->place)); }
		break;
	case 66: /* loop: STOP */
		fprintf(stderr, "0x%lx: line 225: loop: STOP\n",(long)p);
#line 225 "minor.brg"
{ p->place = stoplbl[forcnt]; fprintf(yyout, pfJMP, mklbl(p->place)); }
		break;
	case 67: /* block: STMT(instrs,loop) */
		fprintf(stderr, "0x%lx: line 227: block: STMT(instrs,loop)\n",(long)p);
#line 227 "minor.brg"
{}
		break;
	case 68: /* forblock: STMT(instrs,loop) */
		fprintf(stderr, "0x%lx: line 228: forblock: STMT(instrs,loop)\n",(long)p);
#line 228 "minor.brg"
{ p->place = repeatlbl[forcnt]; fprintf(yyout, pfLABEL, mklbl(p->place)); }
		break;
	case 69: /* instrs: NIL */
		fprintf(stderr, "0x%lx: line 230: instrs: NIL\n",(long)p);
#line 230 "minor.brg"
{}
		break;
	case 70: /* instrs: STMT(instrs,instr) */
		fprintf(stderr, "0x%lx: line 231: instrs: STMT(instrs,instr)\n",(long)p);
#line 231 "minor.brg"
{}
		break;
	case 71: /* instr: FI(THEN(if,elifs),else) */
		fprintf(stderr, "0x%lx: line 233: instr: FI(THEN(if,elifs),else)\n",(long)p);
#line 233 "minor.brg"
{ fprintf(yyout, pfLABEL, mklbl(LEFT_CHILD(LEFT_CHILD(p))->place)); }
		break;
	case 72: /* instr: FOR(UNTIL(init,forcond),STEP(forblock,postexpr)) */
		fprintf(stderr, "0x%lx: line 234: instr: FOR(UNTIL(init,forcond),STEP(forblock,postexpr))\n",(long)p);
#line 234 "minor.brg"
{ fprintf(yyout, pfLABEL, mklbl(RIGHT_CHILD(LEFT_CHILD(p))->place)); }
		break;
	case 73: /* instr: PRINT(expr) */
		fprintf(stderr, "0x%lx: line 235: instr: PRINT(expr)\n",(long)p);
#line 235 "minor.brg"
{ pfPrint(p->info); }
		break;
	case 74: /* instr: expr */
		fprintf(stderr, "0x%lx: line 236: instr: expr\n",(long)p);
#line 236 "minor.brg"
{ /* TODO */ fprintf(yyout, pfTRASH, pfWORD); }
		break;
	case 75: /* instr: ALLOC(alloc,alloclval) */
		fprintf(stderr, "0x%lx: line 237: instr: ALLOC(alloc,alloclval)\n",(long)p);
#line 237 "minor.brg"
{ fprintf(yyout, pfSTORE); }
		break;
	case 76: /* alloc: expr */
		fprintf(stderr, "0x%lx: line 238: alloc: expr\n",(long)p);
#line 238 "minor.brg"
{ fprintf(yyout, pfIMM pfMUL pfALLOC pfSP, pfWORD); }
		break;
	case 77: /* if: IF(cond,block) */
		fprintf(stderr, "0x%lx: line 240: if: IF(cond,block)\n",(long)p);
#line 240 "minor.brg"
{ p->place = ++lbl; eliflbl = p->place; fprintf(yyout, pfJMP pfLABEL, mklbl(p->place), mklbl(LEFT_CHILD(p)->place)); }
		break;
	case 78: /* ifelse: IF(cond,block) */
		fprintf(stderr, "0x%lx: line 241: ifelse: IF(cond,block)\n",(long)p);
#line 241 "minor.brg"

		break;
	case 79: /* init: trashexpr */
		fprintf(stderr, "0x%lx: line 243: init: trashexpr\n",(long)p);
#line 243 "minor.brg"
{ p->place = forlbl[++forcnt] = ++lbl; repeatlbl[forcnt] = ++lbl; fprintf(yyout, pfLABEL, mklbl(p->place)); }
		break;
	case 80: /* forcond: expr */
		fprintf(stderr, "0x%lx: line 244: forcond: expr\n",(long)p);
#line 244 "minor.brg"
{ p->place = stoplbl[forcnt] = ++lbl; fprintf(yyout, pfJNZ, mklbl(p->place)); }
		break;
	case 81: /* postexpr: trashexpr */
		fprintf(stderr, "0x%lx: line 245: postexpr: trashexpr\n",(long)p);
#line 245 "minor.brg"
{ p->place = forlbl[forcnt--]; fprintf(yyout, pfJMP, mklbl(p->place)); }
		break;
	case 82: /* cond: expr */
		fprintf(stderr, "0x%lx: line 246: cond: expr\n",(long)p);
#line 246 "minor.brg"
{ p->place = ++lbl; fprintf(yyout, pfJZ, mklbl(p->place)); }
		break;
	case 83: /* trashexpr: expr */
		fprintf(stderr, "0x%lx: line 248: trashexpr: expr\n",(long)p);
#line 248 "minor.brg"
{ /* TODO */ fprintf(yyout, pfTRASH, pfWORD); }
		break;
	case 84: /* elifs: NIL */
		fprintf(stderr, "0x%lx: line 250: elifs: NIL\n",(long)p);
#line 250 "minor.brg"

		break;
	case 85: /* elifs: ELIF(elifs,ifelse) */
		fprintf(stderr, "0x%lx: line 251: elifs: ELIF(elifs,ifelse)\n",(long)p);
#line 251 "minor.brg"
{ p->place = eliflbl; fprintf(yyout, pfJMP pfLABEL, mklbl(p->place), mklbl(LEFT_CHILD(RIGHT_CHILD(p))->place)); }
		break;
	case 86: /* else: NIL */
		fprintf(stderr, "0x%lx: line 253: else: NIL\n",(long)p);
#line 253 "minor.brg"

		break;
	case 87: /* else: block */
		fprintf(stderr, "0x%lx: line 254: else: block\n",(long)p);
#line 254 "minor.brg"

		break;
	case 88: /* alloclval: ID */
		fprintf(stderr, "0x%lx: line 256: alloclval: ID\n",(long)p);
#line 256 "minor.brg"
{ getAllocId(p); }
		break;
	case 89: /* alloclval: INDEX(alloclval,expr) */
		fprintf(stderr, "0x%lx: line 257: alloclval: INDEX(alloclval,expr)\n",(long)p);
#line 257 "minor.brg"
{ fprintf(yyout, pfIMM pfMUL pfADD pfLOAD, 4); }
		break;
	case 90: /* lval: ID */
		fprintf(stderr, "0x%lx: line 259: lval: ID\n",(long)p);
#line 259 "minor.brg"
{ getId(p); }
		break;
	case 91: /* lval: INDEX(lvec,expr) */
		fprintf(stderr, "0x%lx: line 260: lval: INDEX(lvec,expr)\n",(long)p);
#line 260 "minor.brg"
{ fprintf(yyout, pfIMM pfMUL pfADD pfLOAD, 4); }
		break;
	case 92: /* lvec: ID */
		fprintf(stderr, "0x%lx: line 261: lvec: ID\n",(long)p);
#line 261 "minor.brg"
{ getId(p); }
		break;
	case 93: /* lvecassign: ID */
		fprintf(stderr, "0x%lx: line 262: lvecassign: ID\n",(long)p);
#line 262 "minor.brg"
{ fprintf(yyout, pfDUP); getId(p); }
		break;
	case 94: /* assign: ID */
		fprintf(stderr, "0x%lx: line 263: assign: ID\n",(long)p);
#line 263 "minor.brg"
{ assignment(p); }
		break;
	case 95: /* assign: INDEX(lvecassign,expr) */
		fprintf(stderr, "0x%lx: line 264: assign: INDEX(lvecassign,expr)\n",(long)p);
#line 264 "minor.brg"
{ fprintf(yyout, pfIMM pfMUL pfADD pfSTORE, 4); }
		break;
	case 96: /* expr: CHARS(NIL,INT) */
		fprintf(stderr, "0x%lx: line 266: expr: CHARS(NIL,INT)\n",(long)p);
#line 266 "minor.brg"
{ fprintf(yyout, pfIMM, RIGHT_CHILD(p)->value.i); }
		break;
	case 97: /* expr: CHARS(NIL,CHAR) */
		fprintf(stderr, "0x%lx: line 267: expr: CHARS(NIL,CHAR)\n",(long)p);
#line 267 "minor.brg"
{ fprintf(yyout, pfIMM, RIGHT_CHILD(p)->value.i); }
		break;
	case 98: /* expr: CHARS(NIL,STR) */
		fprintf(stderr, "0x%lx: line 268: expr: CHARS(NIL,STR)\n",(long)p);
#line 268 "minor.brg"
{ lbl++; fprintf(yyout, pfRODATA pfALIGN pfLABEL, mklbl(lbl)); outstr(RIGHT_CHILD(p)->value.s); fprintf(yyout, pfTEXT pfADDR, mklbl(lbl)); }
		break;
	case 99: /* expr: chars */
		fprintf(stderr, "0x%lx: line 269: expr: chars\n",(long)p);
#line 269 "minor.brg"
{ fprintf(yyout, pfCHAR pfTEXT pfADDR, 0, mklbl(p->place)); }
		break;
	case 100: /* expr: lval */
		fprintf(stderr, "0x%lx: line 270: expr: lval\n",(long)p);
#line 270 "minor.brg"

		break;
	case 101: /* expr: READ */
		fprintf(stderr, "0x%lx: line 271: expr: READ\n",(long)p);
#line 271 "minor.brg"
{ fprintf(yyout, pfCALL pfPUSH, "_readi"); }
		break;
	case 102: /* expr: ADDR(lval) */
		fprintf(stderr, "0x%lx: line 272: expr: ADDR(lval)\n",(long)p);
#line 272 "minor.brg"
{}
		break;
	case 103: /* expr: ADD(expr,expr) */
		fprintf(stderr, "0x%lx: line 273: expr: ADD(expr,expr)\n",(long)p);
#line 273 "minor.brg"
{ fprintf(yyout, pfADD); }
		break;
	case 104: /* expr: SUB(expr,expr) */
		fprintf(stderr, "0x%lx: line 274: expr: SUB(expr,expr)\n",(long)p);
#line 274 "minor.brg"
{ fprintf(yyout, pfSUB); }
		break;
	case 105: /* expr: MUL(expr,expr) */
		fprintf(stderr, "0x%lx: line 275: expr: MUL(expr,expr)\n",(long)p);
#line 275 "minor.brg"
{ fprintf(yyout, pfMUL); }
		break;
	case 106: /* expr: DIV(expr,expr) */
		fprintf(stderr, "0x%lx: line 276: expr: DIV(expr,expr)\n",(long)p);
#line 276 "minor.brg"
{ fprintf(yyout, pfDIV); }
		break;
	case 107: /* expr: MOD(expr,expr) */
		fprintf(stderr, "0x%lx: line 277: expr: MOD(expr,expr)\n",(long)p);
#line 277 "minor.brg"
{ fprintf(yyout, pfMOD); }
		break;
	case 108: /* expr: POW(expr,expr) */
		fprintf(stderr, "0x%lx: line 278: expr: POW(expr,expr)\n",(long)p);
#line 278 "minor.brg"
{}
		break;
	case 109: /* expr: EQU(expr,expr) */
		fprintf(stderr, "0x%lx: line 279: expr: EQU(expr,expr)\n",(long)p);
#line 279 "minor.brg"
{ fprintf(yyout, pfEQ); }
		break;
	case 110: /* expr: NE(expr,expr) */
		fprintf(stderr, "0x%lx: line 280: expr: NE(expr,expr)\n",(long)p);
#line 280 "minor.brg"
{ fprintf(yyout, pfNE); }
		break;
	case 111: /* expr: GE(expr,expr) */
		fprintf(stderr, "0x%lx: line 281: expr: GE(expr,expr)\n",(long)p);
#line 281 "minor.brg"
{ fprintf(yyout, pfGE); }
		break;
	case 112: /* expr: LE(expr,expr) */
		fprintf(stderr, "0x%lx: line 282: expr: LE(expr,expr)\n",(long)p);
#line 282 "minor.brg"
{ fprintf(yyout, pfLE); }
		break;
	case 113: /* expr: LT(expr,expr) */
		fprintf(stderr, "0x%lx: line 283: expr: LT(expr,expr)\n",(long)p);
#line 283 "minor.brg"
{ fprintf(yyout, pfLT); }
		break;
	case 114: /* expr: GT(expr,expr) */
		fprintf(stderr, "0x%lx: line 284: expr: GT(expr,expr)\n",(long)p);
#line 284 "minor.brg"
{ fprintf(yyout, pfGT); }
		break;
	case 115: /* expr: AND(and,expr) */
		fprintf(stderr, "0x%lx: line 285: expr: AND(and,expr)\n",(long)p);
#line 285 "minor.brg"
{ fprintf(yyout, pfLABEL, mklbl(LEFT_CHILD(p)->place)); }
		break;
	case 116: /* and: expr */
		fprintf(stderr, "0x%lx: line 286: and: expr\n",(long)p);
#line 286 "minor.brg"
{ p->place = ++lbl; fprintf(yyout, pfDUP pfJZ pfTRASH, mklbl(p->place), pfWORD); }
		break;
	case 117: /* expr: OR(or,expr) */
		fprintf(stderr, "0x%lx: line 287: expr: OR(or,expr)\n",(long)p);
#line 287 "minor.brg"
{ fprintf(yyout, pfLABEL, mklbl(LEFT_CHILD(p)->place)); }
		break;
	case 118: /* or: expr */
		fprintf(stderr, "0x%lx: line 288: or: expr\n",(long)p);
#line 288 "minor.brg"
{ p->place = ++lbl; fprintf(yyout, pfDUP pfJNZ pfTRASH, mklbl(p->place), pfWORD); }
		break;
	case 119: /* expr: NOT(expr) */
		fprintf(stderr, "0x%lx: line 289: expr: NOT(expr)\n",(long)p);
#line 289 "minor.brg"
{ fprintf(yyout, pfIMM pfEQ, 0); }
		break;
	case 120: /* expr: UMINUS(expr) */
		fprintf(stderr, "0x%lx: line 290: expr: UMINUS(expr)\n",(long)p);
#line 290 "minor.brg"
{ fprintf(yyout, pfNEG); }
		break;
	case 121: /* expr: EQ(expr,assign) */
		fprintf(stderr, "0x%lx: line 291: expr: EQ(expr,assign)\n",(long)p);
#line 291 "minor.brg"
{}
		break;
	case 122: /* expr: IDARGS(ID,exprs) */
		fprintf(stderr, "0x%lx: line 292: expr: IDARGS(ID,exprs)\n",(long)p);
#line 292 "minor.brg"
{ fprintf(yyout, pfCALL pfTRASH pfPUSH, mkfunc(LEFT_CHILD(p)->value.s), (int)(pfWORD*(RIGHT_CHILD(p)->place))); }
		break;
	case 123: /* exprs: COMMA(expr,NIL) */
		fprintf(stderr, "0x%lx: line 294: exprs: COMMA(expr,NIL)\n",(long)p);
#line 294 "minor.brg"
{ p->place = 1; }
		break;
	case 124: /* exprs: COMMA(expr,exprs) */
		fprintf(stderr, "0x%lx: line 295: exprs: COMMA(expr,exprs)\n",(long)p);
#line 295 "minor.brg"
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


#line 297 "minor.brg"

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
