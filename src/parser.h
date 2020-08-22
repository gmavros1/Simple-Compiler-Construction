#define NSYMS 20 /* max nums of symbols */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct symtab {
	char *name;
	double value;
} symtab[NSYMS];


