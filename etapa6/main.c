#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include "sym_stack.h"
#include "gen_assembly.h"

extern int yyparse(void);
extern int yylex_destroy(void);
void exporta(void *arvore);
const char* global_filename;

void *arvore = NULL;

int main(int argc, char **argv)
{
    global_filename = argv[0];

	int ret = yyparse();
	yylex_destroy();

	return ret;
}