/*
*	Γεώργιος Μαύρος 3360
*/

%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "parser.h"
#include "asCodeGen.h"

FILE *targetOut;
int varsCount = 0;
int ifCount = 0;
int loopCount = 0;
float expr1;
float expr2;
char *logicOp;
int yylex();
char *type;
void yyerror (char const *);
void declarationCheck(char *s);
int returnIndex(char *s);
extern void symlook(char *);
void printTable();

%}

/* Type of symbols */
%union { double dval; struct symtab *symp; }

%token T_MAINCLASS T_PUBLIC T_STATIC T_VOID T_MAIN T_PRINTLN T_INT T_FLOAT T_FOR T_WHILE T_IF T_EQUAL
%token <symp> T_ID
%token <dval> T_NUM
%token T_SMALLER T_BIGGER T_NOTEQUAL T_ELSE

%type <dval> ASSIGN_EXPR
%type <dval> RVAL
%type <dval> TERM
%type <dval> FACTOR
%type <dval> EXPR

%right '='
%left '<' '>'
%left '+' '-'
%left '*' '/'
%left '(' ')'
%left '{' '}'
%left ';' ','

%%

	PROGRAM 	: T_MAINCLASS T_ID '{' T_PUBLIC T_STATIC T_VOID T_MAIN '(' ')' COMP_STMT '}'
						;

COMP_STMT 	: '{' STMT_LIST '}' // scope (like stack)
						;

STMT_LIST		: /* nothing */
						| STMT_LIST STMT
						;

STMT 				: ASSIGN_STMT
						| FOR_STMT
						| WHILE_STMT
						| IF_STMT
						| COMP_STMT
						| DECLARATION
						| NULL_STMT
						| T_PRINTLN '(' EXPR ')' ';' {printOut(ids);}
						;

DECLARATION	: TYPE ID_LIST ';'
						;

TYPE				: T_INT {char *s="int" ; type =  strdup(s);}
						| T_FLOAT {char *s="flt" ; type =  strdup(s);}
						;

ID_LIST 		: T_ID { symlook(ids); varsCount++; declarationOut(ids); } ',' ID_LIST
						| T_ID { symlook(ids); varsCount++; declarationOut(ids); }
						;

NULL_STMT		: ';'
						;

ASSIGN_STMT	: ASSIGN_EXPR ';'
						;

ASSIGN_EXPR	: T_ID '=' EXPR	{	declarationCheck(ids);
															char *tp = "int";
														  if (!strcmp($1->type, tp)){
																	 $1->valueD = $3 ;
																	 $1->valueI = (int)($3+0.01);
															}
														  else	{
																	$1->valueD = $3 ;
															}
															assignOut($1->name, (int)($3+0.01));

														}
						;

EXPR				: ASSIGN_EXPR
						| RVAL
						;

FOR_STMT 		: T_FOR '(' OPASSIGN_EXPR ';' OPBOOL_EXPR ';' OPASSIGN_EXPR ')' STMT
						;

OPASSIGN_EXPR	: /* nothing */
							| ASSIGN_EXPR
							;

OPBOOL_EXPR		: /* nothing */
							| BOOL_EXPR
							;

WHILE_STMT		: T_WHILE '(' BOOL_EXPR ')' {fprintf(targetOut, "\n\taddi $t0, $zero, %d\n\taddi $t1, $zero, %d",(int)(expr1), (int)(expr2)); fprintf(targetOut,"\n\tWhile%d:", loopCount); whileOut(); }  STMT {fprintf(targetOut, "\n\n\tj While%d\n", loopCount); fprintf(targetOut, "\n\nExit%d:\n", loopCount);  loopCount++;}
							;

IF_STMT				: T_IF '(' BOOL_EXPR ')' { ifOut((int)(expr1), (int)(expr2)); } STMT {fprintf(targetOut, "\n\tj EndIf%d\n", ifCount); elseOut();} ELSE_PART { endif(); ifCount++;}
							;

ELSE_PART			: /* nothing */
							| T_ELSE  STMT
							;

BOOL_EXPR			: EXPR C_OP EXPR {expr1 = $1; expr2 = $3;}
							;

C_OP					: T_EQUAL { logicOp = strdup("bne"); }
							| '<' { logicOp = strdup("bgt");}
							| '>' { logicOp = strdup("blt");}
							| T_SMALLER { logicOp = strdup("bge");}
							| T_BIGGER { logicOp = strdup("ble");}
							| T_NOTEQUAL { logicOp = strdup("beq");}
							;

RVAL					: RVAL '+' TERM	{ $$ = $1 + $3; }
							| RVAL '-' TERM	{ $$ = $1 - $3; }
							| TERM
							;

TERM					: TERM '*' FACTOR { $$ = $1 * $3; }
	 						| TERM '/' FACTOR { if ($3 == 0)
																		yyerror("divide by zero");
							    								else
																		$$ = $1 / $3;
							 									}
				 			| FACTOR
				 			;

FACTOR				: '(' EXPR ')' 	{ $$ = $2; }
							| '-' FACTOR   	{ $$ = -$2; }
							| T_ID		{ $$ = $1->valueD; }
							| T_NUM		{ $$ = $1; }
%%

#include "asCodeGen.c"

void scopeHandle(char *c){
	if (!strcmp(c,"}")){
		struct symtab *st;
		for (st = &symtab[NSYMS-1]; st > symtab-1; st--) {
			if (!st->name){
				continue;
			}
			if (strcmp(st->name, "{")){
				st->name = '\0';
				st->valueI = 0;
				st->valueD = 0;
				st->type = '\0';
			}
			else{
				st->name = '\0';
				st->valueI = 0;
				st->valueD = 0;
				st->type = '\0';
				break;
			}
		}
	}
	else if(!strcmp(c,"{")){
		struct symtab *st;
		for(st = symtab; st < &symtab[NSYMS]; st++){
			if(!st->name){
				st->name = strdup("{" );
				break;
			}
		}
	}
	//printTable();
}

void printTable()
{
    printf("Print out the symbol table:\n\n");

    struct symtab *sp;
    for(sp = symtab; sp < &symtab[NSYMS]; sp++)
    {
        	printf("name: %s\t"
                "valueD: %f\t"
								"ValueI: %d\t"
		 						"Type: %s\t\n",
                sp->name,
                sp->valueD,
	        			sp->valueI,
								sp->type);
    }
}

int returnIndex(char *s){
    int counter = 0;
		int abstrctForSymbol=0;
		char *st = "{";
    struct symtab *sp;
    for(sp = symtab; sp < &symtab[NSYMS]; sp++) {
        /* is it already here? */
        if(sp->name && !strcmp(sp->name, s))
        {
            return counter-abstrctForSymbol;
        }
				if(sp->name && !strcmp(sp->name, st))
					abstrctForSymbol++;
				counter ++;
    }
}

void declarationCheck(char *s){
    int flag = 0;
    struct symtab *sp;
    for(sp = symtab; sp < &symtab[NSYMS]; sp++) {
        /* is it already here? */
        if(sp->name && !strcmp(sp->name, s))
        {
            flag = 1;
        }
    }
    if(!flag)
		yyerror("Variable has not be declared\n");
}

void symlook(char *s) {
    printf("Putting %s into the symbol table\n", s);
    struct symtab *sp;
    for(sp = symtab; sp < &symtab[NSYMS]; sp++) {
        /* is it already here? */
        if(sp->name && !strcmp(sp->name, s))
        {
            yyerror("already in symbol table\n");
            exit(1);
        }
        if(!sp->name) { /* is it free ? */
            sp->name = strdup(s);
	    			sp->valueI = 0;
	    			sp->valueD = 0;
	    			sp->type = strdup(type);
						break;
        }
        /* otherwise continue to next */
    }
		printTable();
}


void yyerror (const char * msg)
{
  	fprintf(stderr, "C-like : %s\n", msg);
  	exit(1);
}

struct symtab *returnStrucktPointer(char *n){
		struct symtab *sp;
		//sp = symtab;
		for(sp = symtab; sp < &symtab[NSYMS]; sp++) {
        if(sp->name && !strcmp(sp->name, n))
        {
            return sp;
        }
				if(!sp->name) {
      			break;
        }
    }
}


int main ()
{
	/*DEBUG TOOL*/
	#if YYDEBUG ==0
	extern int yydebug;
	yydebug=1;
	#endif


	/*TARGET CODE GENERATION*/
	targetOut = fopen("target.asm", "w");

	dataOut();

  if(!yyparse())
		printf("Parsed Successfully !!!\n");

	instructionsOut("\n\nli	$v0 10\n\tsyscall\n");
	instructionsOut("\nprintl:\n");
  instructionsOut("li $v0, 1\n \tmove $a0, $s0\n \tsyscall\n\n \tli $v0, 4\n \tla $a0, newLine\n \tsyscall\n\n \tjr $ra\n");

	fclose(targetOut);
}
