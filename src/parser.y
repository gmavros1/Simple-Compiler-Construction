/*
*	Γεώργιος Μαύρος 3360
*/

%{
#include <stdio.h>
#include <stdlib.h>

int yylex();
void yyerror (char const *);

%}

%token T_MAINCLASS T_PUBLIC T_STATIC T_VOID T_MAIN T_PRINTLN T_INT T_FLOAT T_FOR T_WHILE T_IF T_EQUAL T_ID T_NUM T_SMALLER T_BIGGER T_NOTEQUAL T_ELSE T_STRING  

%left '(' ')'
%left '+' '-'
%left '*' '/'
%left '{' '}'
%left ';' ','
%left '<' '>'

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
		| T_ID
		;

NULL_STMT	: ';'
		;

ASSIGN_STMT	: ASSIGN_EXPR ';'
		;

ASSIGN_EXPR	: T_ID '=' EXPR
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

RVAL		: RVAL '+' TERM
		| RVAL '-' TERM
		| TERM
		;

TERM		: TERM '*' FACTOR
		| TERM '/' FACTOR
		| FACTOR
		;

FACTOR		: '(' EXPR ')'
		| T_ID
		| T_NUM
		;

%%

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
