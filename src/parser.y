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
extern struct symtab *symlook(char *);

%}

/* Type of symbols */
%union {
	double dval;
	int ival;
}

%token T_MAINCLASS T_PUBLIC T_STATIC T_VOID T_MAIN T_PRINTLN T_INT T_FLOAT T_FOR T_WHILE T_IF T_EQUAL 
%token <ival> T_ID 
%token <ival> T_NUM 
%token T_SMALLER T_BIGGER T_NOTEQUAL T_ELSE   
	
%type <ival> ASSIGN_EXPR 
%type <ival> RVAL
%type <ival> TERM
%type <ival> FACTOR
%type <ival> EXPR

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

COMP_STMT 	: '{' STMT_LIST '}'
		;
	
STMT_LIST	: /* nothing */
		| STMT_LIST STMT
		;

STMT		: ASSIGN_STMT
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

TYPE		: T_INT {char *s="int" ; type =  strdup(s);}
		| T_FLOAT {char *s="flt" ; type =  strdup(s);}
		;

ID_LIST 	: T_ID { printf("\n\n******%s******\n\n", ids) ; symlook(ids); }',' ID_LIST 
		| T_ID { printf("\n\n******%s******\n\n", ids) ; symlook(ids); }
		;

NULL_STMT	: ';' 
		;

ASSIGN_STMT	: ASSIGN_EXPR ';'
		;

ASSIGN_EXPR	: T_ID {declarationCheck(ids);} '=' EXPR	{ char *tp = "int";
							  if (!strcmp(symtab[returnIndex(ids)].type, tp)){
								 symtab[returnIndex(ids)].valueI = $3 ;
								 printf("\n\n\nLOOOOOOOOOOOOOOOOL\n\n\n");
								printf("\n\n******%d******\n\n", $3) ;	
								}
							  else	
								 symtab[returnIndex(ids)].valueD = $3 ;
							}
		;

EXPR		: ASSIGN_EXPR
		| RVAL
		;

FOR_STMT 	: T_FOR '(' OPASSIGN_EXPR ';' OPBOOL_EXPR ';' OPASSIGN_EXPR ')' STMT
		;

OPASSIGN_EXPR	: /* nothing */
		| ASSIGN_EXPR
		;

OPBOOL_EXPR	: /* nothing */
		| BOOL_EXPR
		;

WHILE_STMT	: T_WHILE '(' BOOL_EXPR ')' STMT
		;

IF_STMT		: T_IF '(' BOOL_EXPR ')' STMT ELSE_PART
		;

ELSE_PART	: /* nothing */
		| T_ELSE STMT
		;

BOOL_EXPR	: EXPR C_OP EXPR
		;

C_OP		: T_EQUAL | '<' | '>' | T_SMALLER | T_BIGGER | T_NOTEQUAL
		;

RVAL		: RVAL '+' TERM	{ $$ = $1 + $3; }
		| RVAL '-' TERM	{ $$ = $1 - $3; }
		| TERM
		;

TERM		: TERM '*' FACTOR { $$ = $1 * $3; }
		| TERM '/' FACTOR { if ($3 == 0.0)
					yyerror("divide by zero");
				    else
					$$ = $1 / $3;
				 }
		| FACTOR
		;

FACTOR		: '(' EXPR ')' 	{ $$ = $2; }
		| '-' FACTOR   	{ $$ = -$2; }
		| T_ID		{ $$ = $1; }
		| T_NUM		{ $$ = $1; }
%%

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

struct symtab *symlook(char *s) {

    printf("Putting %s into the symbol table\n", s);
    //char *p;
    struct symtab *sp;
    for(sp = symtab; sp < &symtab[NSYMS]; sp++) {
        /* is it already here? */
        if(sp->name && !strcmp(sp->name, s))
        {
            yyerror("already in symbol table\n");
            exit(1);
            return sp;
        }
        if(!sp->name) { /* is it free */
            sp->name = strdup(s);
	    sp->valueI = 0;
	    sp->valueD = 0;
	    sp->type = strdup(type);
            return sp;
        }
        /* otherwise continue to next */
    }
    yyerror("Too many symbols");
    exit(1); /* cannot continue */
}


void yyerror (const char * msg)
{
  fprintf(stderr, "C-like : %s\n", msg);
  exit(1);
}

int main ()
{
#if YYDEBUG ==1
extern int yydebug;
yydebug=1;
#endif
  if(!yyparse()){
	printf("Compiled !!!\n");
   }
}
