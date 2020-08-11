/*
*	Γεώργιος Μαύρος 3360
*/

%{
#include <stdio.h>
#include <stdlib.h>

int yylex();
void yyerror (char const *);

%}

%token MAINCLASS PUBLIC STATIC VOID MAIN PRINTLN INT FLOAT FOR WHILE IF ELSE Q EQUAL SMALLER BIGGER NOTEQUAL ID NUM STRING

%left '(' ')'
%left '+' '-'
%left '*' '/'

%% 

PROGRAM 	: MAINCLASS ID '{' PUBLIC STATIC VOID MAIN '(' ')' COMP_STMT '}'
		;


COMP_STMT 	: '{' STMT_LIST'}'
		;
	

STMT_LIST	: STMT_LIST STMT
		| /* nothing */
		;

STMT		: ASSIGN_STMT
		| FOR_STMT
		| WHILE_STMT
		| IF_STMT
		| COMP_STMT
		| DECLARATION
		| NULL_STMT
		| PRINTLN '(' EXPR ')' Q
		;

DECLARATION	: TYPE ID_LIST Q
		;

TYPE		: INT
		| FLOAT
		;

ID_LIST 	: ID ',' ID_LIST
		|
		;

NULL_STMT	: Q
		;

ASSIGN_STMT	: ASSIGN_EXPR Q
		;

ASSIGN_EXPR	: ID '=' EXPR
		;

EXPR		: ASSIGN_EXPR
		| RVAL
		;

FOR_STMT 	: FOR '(' OPASSIGN_EXPR Q OPBOOL_EXPR Q OPASSIGN_EXPR ')' STMT
		;

OPASSIGN_EXPR	: ASSIGN_EXPR
		| /* nothing */
		;

OPBOOL_EXPR	: BOOL_EXPR
		| /* nothing */
		;

WHILE_STMT	: WHILE '(' BOOL_EXPR ')' STMT
		;

IF_STMT		: IF '(' BOOL_EXPR ')' STMT ELSE_PART
		;

ELSE_PART	: ELSE STMT
		| /* nothing */
		;

BOOL_EXPR	: EXPR C_OP EXPR
		;

C_OP		: EQUAL | '<' | '>' | SMALLER | BIGGER | NOTEQUAL
		;

RVAL		: RVAL '+' TERM
		| RVAL '-' TERM
		| TERM
		;

TERM		: TERM '*' FACTOR
		| TERM '/' FACTOR
		| FACTOR
		;

FACTOR		: '(' EXPR ')'
		| ID
		| NUM
		;

%%

void yyerror (const char * msg)
{
  fprintf(stderr, "C-like : %s\n", msg);
  exit(1);
}

int main ()
{
  if(!yyparse()){
	printf("Compiled !!!\n");
   }
}
