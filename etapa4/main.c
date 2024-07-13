#include <stdio.h>
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

// ./etapa3 < entrada.txt  | grep 0x | ./output2dot.sh > saida.dot
// xdot saida.dot


// ./etapa3 < entrada.txt  | grep 0x | ./output2dot.sh | xdot -

// comandos para testar todo programa