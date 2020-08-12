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
id	[A-Za-z][A-Za-z0-9_]*
num	[1-9]digit*('.'digit*)?
string 	'(digit|letter)*'
Empty 	[[:space:]]

%%

[\(\)\{\}] 	{ printf("Brackets or par ") ; return yytext[0] ; }

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

{Empty}+	{ printf("EMPTY ") ; /* nothing */ }

. 		{ printf(" lexical error \n "); exit(1); }

<<EOF>>		{ printf("EOF ") ; return EOF; }


%%
