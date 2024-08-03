#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include "sym_stack.h"

extern int yyparse(void);
extern int yylex_destroy(void);
void exporta(void *arvore);

void *arvore = NULL;

int main(int argc, char **argv)
{
	int ret = yyparse();
	exporta(arvore);
	yylex_destroy();

	return ret;
}