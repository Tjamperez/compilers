// #include <stdio.h>
// extern int yyparse(void);
// extern int yylex_destroy(void);
// void *arvore = NULL;
// // void exporta(void *arvore);
// #include "tree.h"
// #include "val_lex.h"

// int main(int argc, char **argv)
// {
// 	// int ret = yyparse();
// 	// // Create some sample lexical values
// 	// val_lex_t *value1 = gen_val(1, 0, "Value1");
// 	// val_lex_t *value2 = gen_val(2, 1, "Value2");
// 	// val_lex_t *value3 = gen_val(3, 1, "Value3");

// 	// // Create tree nodes
// 	// tree_node_t *root = ast_new(value1);
// 	// tree_node_t *child1 = ast_new(value2);
// 	// tree_node_t *child2 = ast_new(value3);

// 	// // Link nodes together
// 	// ast_add_child(root, child1);
// 	// ast_add_child(root, child2);

// 	// // Call exporta function to print the tree
// 	// printf("Printing tree:\n");
// 	// exporta(root);

// 	// // Clean up memory
// 	// //exporta(arvore);
// 	// yylex_destroy();
// 	// return ret;
//}

#include <stdio.h>
extern int yyparse(void);
extern int yylex_destroy(void);
void *arvore = NULL;
void exporta(void *arvore);
int main(int argc, char **argv)
{
	int ret = yyparse();
	exporta(arvore);
	yylex_destroy();
	return ret;
}