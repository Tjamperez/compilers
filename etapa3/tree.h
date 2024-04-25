#ifndef _TREE_H_
#define _TREE_H_

typedef struct ast_tree {
  char *label;
  struct ast_tree **children;
} ast_tree_t;

/*
 * Função asd_new, cria um nó sem filhos com o label informado.
 */
ast_tree_t *ast_new(const char *label);

/*
 * Função asd_tree, libera recursivamente o nó e seus filhos.
 */
void ast_free(ast_tree_t *tree);

/*
 * Função asd_add_child, adiciona child como filho de tree.
 */
void ast_add_child(ast_tree_t *tree, ast_tree_t *child);

/*
 * Função asd_print, imprime recursivamente a árvore.
 */
void ast_print(ast_tree_t *tree);

/*
 * Função asd_print_graphviz, idem, em formato DOT
 */
void ast_print_graphviz (ast_tree_t *tree);

/*
 * Função para validar o resultado da operação aritmética, percorrendo a árvore recursivamente
*/
double evaluate_ast(ast_tree_t *node);


#endif //_TREE_H_