/*
*	Γεώργιος Μαύρος 3360
*/

%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"

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
						| T_PRINTLN '(' EXPR ')' ';'
						;

DECLARATION	: TYPE ID_LIST ';'
						;

TYPE				: T_INT {char *s="int" ; type =  strdup(s);}
						| T_FLOAT {char *s="flt" ; type =  strdup(s);}
						;

ID_LIST 		: T_ID { printf("\n\n******%s******\n\n", ids) ; symlook(ids); } ',' ID_LIST
						| T_ID { printf("\n\n******%s******\n\n", ids) ; symlook(ids); }
						;

NULL_STMT		: ';'
						;

ASSIGN_STMT	: ASSIGN_EXPR ';'
						;

ASSIGN_EXPR	: T_ID '=' EXPR	{  //$1->valueD = $3;
															declarationCheck(ids);
															char *tp = "int";
														  if (!strcmp($1->type, tp)){
																	 $1->valueD = $3 ;
																	 $1->valueI = (int)($3+0.01);
																	 printf("\n\nASSIGN_EXPR	\n%f\n%s\n\n", $3, ids );
																	 /*printf("\n\n\nLOOOOOOOOOOOOOOOOL  %f %s \n\n\n", $3, &ids );*/
															}
														  else	{
																	$1->valueD = $3 ;
																	printf("\n\nASSIGN_EXPR	\n%f\n%s\n\n", $3, ids );
															}

														}
						;

EXPR				: ASSIGN_EXPR
						| RVAL { printf("\n\nEXPR\n%f\n\n\n", $1 );}
						;

FOR_STMT 		: T_FOR '(' OPASSIGN_EXPR ';' OPBOOL_EXPR ';' OPASSIGN_EXPR ')' STMT
						;

OPASSIGN_EXPR	: /* nothing */
							| ASSIGN_EXPR
							;

OPBOOL_EXPR		: /* nothing */
							| BOOL_EXPR
							;

WHILE_STMT		: T_WHILE '(' BOOL_EXPR ')' STMT
							;

IF_STMT				: T_IF '(' BOOL_EXPR ')' STMT ELSE_PART
							;

ELSE_PART			: /* nothing */
							| T_ELSE STMT
							;

BOOL_EXPR			: EXPR C_OP EXPR
							;

C_OP					: T_EQUAL | '<' | '>' | T_SMALLER | T_BIGGER | T_NOTEQUAL
							;

RVAL					: RVAL '+' TERM	{ $$ = $1 + $3; printf("\n\n%f + %f\n\n",$1, $3 ); }
							| RVAL '-' TERM	{ $$ = $1 - $3; }
							| TERM { printf("\n\nRVAL\n%f\n%s\n\n", $1, ids );}
							;

TERM					: TERM '*' FACTOR { $$ = $1 * $3; }
	 						| TERM '/' FACTOR { if ($3 == 0)
																		yyerror("divide by zero");
							    								else
																		$$ = $1 / $3;
							 									}
				 			| FACTOR { printf("\n\nTERM\n%f\n%s\n\n", $1, ids );}
				 			;

FACTOR				: '(' EXPR ')' 	{ $$ = $2; }
							| '-' FACTOR   	{ $$ = -$2; }
							| T_ID		{ $$ = $1->valueD;
													printf("\n\nFACTOR\n%s\n%f\n\n", $1->name, $1->valueD );
												}
							| T_NUM		{ $$ = $1;  printf("\n\n%f\n\n", $1 ); }
%%

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
	printTable();
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
    struct symtab *sp;
    for(sp = symtab; sp < &symtab[NSYMS]; sp++) {
        /* is it already here? */
        if(sp->name && !strcmp(sp->name, s))
        {
            return counter;
        }
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
	#if YYDEBUG ==0
	extern int yydebug;
	yydebug=1;
	#endif

  if(!yyparse()){
	printf("Compiled !!!\n");
   }
}
