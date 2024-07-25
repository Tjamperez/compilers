#ifndef _TREE_H_
#define _TREE_H_
#include "val_lex.h"

#define  NODE_TYPE_INT 1
#define  NODE_TYPE_FLOAT 2
#define  NODE_TYPE_BOOL 3
#define  NODE_TYPE_UNDECLARED 4


typedef struct tree_node {
    val_lex_t *valor_lexico;
    struct tree_node **children;
    int node_type;
    int data_type;
    int num_children;
} tree_node_t;

// Cria um nó sem filhos com o valor léxico.
tree_node_t *ast_new(val_lex_t *valor_lexico);

// Libera recursivamente o nó e seus filhos, incluindo o valor lexico.
void ast_free(tree_node_t *root);

// Adiciona child como filho de tree.
void ast_add_child(tree_node_t *parent, tree_node_t *child);

// Função para exportar a árvore em saída padrão.
void exporta(void *arvore);

tree_node_t *ast_new_label_only(char *label);

tree_node_t *ast_new_call_func(val_lex_t *valor_lexico);

char* ast_parse_function_call(char *token_value);

#endif //_TREE_H_
