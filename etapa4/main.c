#include <stdio.h>
#include "sym_stack.h"

extern int yyparse(void);
extern int yylex_destroy(void);
void exporta(void *arvore);

void *arvore = NULL;
table_of_symbols_t *global_sym_table = NULL;
stack_of_tables_t *stack_of_tables = NULL;

int main(int argc, char **argv)
{
    global_sym_table = initialize_symbol_table();
    stack_of_tables = create_stack_of_tables();
    push_scope(stack_of_tables,global_sym_table);

	int ret = yyparse();
	exporta(arvore);
	yylex_destroy();

    free_stack_of_tables(stack_of_tables);

	return ret;
}