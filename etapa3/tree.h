#ifndef _TREE_H_
#define _TREE_H_
#include "val_lex.h"

typedef struct tree_node {
    val_lex_t *valor_lexico;
    struct tree_node **children;
    int num_children;
} tree_node_t;
/*
 * Função ast_new, cria um nó sem filhos com o valor léxico.
 */
tree_node_t *ast_new(val_lex_t *valor_lexico);

/*
 * Função ast_tree, libera recursivamente o nó e seus filhos, inclusive o valor lexico.
 */
void ast_free(tree_node_t *root);
/*
 * Função ast_add_child, adiciona child como filho de tree.
 */
void ast_add_child(tree_node_t *parent, tree_node_t *child);

/*
 * Função ast_print, imprime recursivamente a árvore.
 */
void ast_print_dot(tree_node_t *root, const char *filename);

#endif //_TREE_H_