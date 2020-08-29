#define NSYMS 20 /* max nums of symbols */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char ids[25]; // Temp value for ids

/* Element of symbol table */
struct symtab {
	char *name;
	double valueD;
	int valueI;
	char *type;
} symtab[NSYMS];
/* 20 Symbols maximum */
