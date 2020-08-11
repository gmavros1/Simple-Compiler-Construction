/*
*	Γεώργιος Μαύρος 3360
*/

%{
#include <stdio.h>
#include <stdlib.h>

int yylex();
void yyerror(const char *s);

int line_num = 1;

#include "y.tab.h"
#define T_eof	0
%}


%option noyywrap 

letter 	[A-Za-z]
digit	[0-9]
id	letter(letter|digit|'_')*
num	[1-9]digit*('.'digit*)?
string 	'(digit|letter)*'
Empty 	[\t\r]|" "
line	[\n]

%%

line		{ line_num++ ; }

"mainclass"	{ printf("MAINCLASS ") ; return  MAINCLASS ; }

"public"	{ printf("PUBLIC ") ; return PUBLIC; }
	
"static"	{ printf("STATIC ") ; return STATIC ; }

"void"		{ printf("VOID ") ; return VOID ; }

"main"		{ printf("MAIN ") ; return MAIN ; }

"println"	{ printf("PRINTLN ") ; return PRINTLN ; }

"int"		{ printf("INT ") ; return INT ; }

"float"		{ printf("FLOAT ") ; return FLOAT ; }

"for"		{ printf("FOR ") ; return FOR ; }

"while"		{ printf("WHILE ") ; return WHILE ; }

"if"		{ printf("IF ") ; return IF ; }

"else"		{ printf("ELSE ") ; return ELSE ; }

";"		{ printf("Q ") ; return Q ; } 

"=="		{ printf("EQUAL ") ; return EQUAL ; }

"<="		{ printf("SMALLER ") ; return SMALLER ; }

">="		{ printf("BIGGER ") ; return BIGGER ; }

"!="		{ printf("NOTEQUAL ") ; return NOTEQUAL ; }

{id}		{ printf("ID ") ; return ID ; }

{num}		{ printf("NUM ") ; return NUM ; }

{string}	{ printf("STRING ") ; return STRING ; }

<<EOF>>		{ printf("EOF ") ; return EOF; }

. 		{ printf(" %d \n", line_num); yyerror("lexical error"); exit(1); }

{Empty}+	{ printf("EMPTY ") ; /* nothing */ }

[\(\)\{\}] 	{ return yytext[0] ; }


%%
