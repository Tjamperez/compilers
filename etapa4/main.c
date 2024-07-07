#include <stdio.h>
#include "sym_stack.h"

extern int yyparse(void);
extern int yylex_destroy(void);
void exporta(void *arvore);

void *arvore = NULL;
void *global_sym_table = NULL;
void *scope = NULL;

int main(int argc, char **argv)
{
    global_sym_table = initialize_symbol_table();
    scope = create_stack_of_tables();

	int ret = yyparse();
	exporta(arvore);
	yylex_destroy();

    free_stack_of_tables(scope);

	return ret;
}