/*
*	Γεώργιος Μαύρος 3360
*/

%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"

int yylex();
void yyerror (char const *);

%}

%union {
	double dval;
	struct symtab *symp;
}

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

TYPE		: T_INT
		| T_FLOAT
		;

ID_LIST 	: T_ID ',' ID_LIST
		| T_ID { $1->value = 0; }
		;

NULL_STMT	: ';'
		;

ASSIGN_STMT	: ASSIGN_EXPR ';'
		;

ASSIGN_EXPR	: T_ID '=' EXPR	{ $1->value = $3; }
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
		| T_ID		{ $$ = $1->value; }
		| T_NUM		{ $$ = $1; }
		;

%%

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
