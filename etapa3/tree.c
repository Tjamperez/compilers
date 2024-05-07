#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "tree.h"

tree_node_t *ast_new(val_lex_t *valor_lexico) {
    tree_node_t *ret = calloc(1, sizeof(tree_node_t));
    if (ret) {
        ret->valor_lexico = valor_lexico;
		//printf("\n\n\n\n\nTesting ast_new  %s\n\n\n\n\n",ret->valor_lexico->token_value); //print test
        ret->children = NULL;
        ret->num_children = 0;
    }
    return ret;
}

tree_node_t *ast_new_label_only(char *label) {
    tree_node_t *ret = calloc(1, sizeof(tree_node_t));
	val_lex_t *aux = calloc(1, sizeof(val_lex_t));
    if (ret) {
		aux->token_value = label;
        ret->valor_lexico =  aux;
		//printf("\n\n\n\n\nTesting ast_new  %s\n\n\n\n\n",ret->valor_lexico->token_value); //print test
        ret->children = NULL;
        ret->num_children = 0;
    }
    return ret;
}

void ast_free(tree_node_t *tree)
{
  if (tree != NULL){
    int i;
    for (i = 0; i < tree->num_children; i++){
      ast_free(tree->children[i]);
    }
    free(tree->children);
    free(tree->valor_lexico);
    free(tree);
  }else{
    printf("Erro: %s recebeu parâmetro tree = %p.\n", __FUNCTION__, tree);
  }
}



void ast_add_child(tree_node_t *parent, tree_node_t *child) {
    if (parent == NULL || child == NULL) return;
    parent->num_children++;
    parent->children = realloc(parent->children, parent->num_children * sizeof(tree_node_t *));
    if (!parent->children) {
        fprintf(stderr, "Error reallocating memory\n");
        exit(EXIT_FAILURE);
    }
    parent->children[parent->num_children - 1] = child;
	//printf("\n\n\n\n\testing ast_add_child  %d\n\n\n\n\n",parent->num_children); //print test
	//printf("\n\n\n\n\ntesting ast_add_child token value   %s\n\n\n\n\n",parent->children[parent->num_children - 1]->valor_lexico->token_value); //print test
}

// Exporta mais elaborada
void exporta(void *arvore) {
    if (arvore == NULL)
        return;
    tree_node_t *root = (tree_node_t *)arvore;

    if (root->valor_lexico != NULL) {
        printf("%p [label=\"%s\"];\n", (void *)root, root->valor_lexico->token_value);
    } else {
        printf("%p [label=\"<NULL>\"];\n", (void *)root);
    }
    for (int i = 0; i < root->num_children; i++) {
        printf("%p, %p\n", (void *)root, (void *)(root->children[i]));
    }
    for (int i = 0; i < root->num_children; i++) {
        exporta(root->children[i]);
    }
}
//Exporta turbinado

// void exporta_helper(tree_node_t *node, int depth) {
//     if (node == NULL) return;
//     // Print the current node
//     printf("Node %p [Line: %d, Type: %d, Value: %s]\n", (void*)node, node->valor_lexico->lineno, node->valor_lexico->type, node->valor_lexico->token_value);
//     for (int i = 0; i < node->num_children; i++) {
//         for (int j = 0; j < depth; j++) {
//             printf("  "); // Indentation for better visualization
//         }
//         printf("Child of %p -> %p\n", (void*)node, (void*)(node->children[i]));
//         exporta_helper(node->children[i], depth + 1);
//     }
// }

// void exporta(tree_node_t *node) {
//     printf("Printing tree:\n");
//     exporta_helper(node, 0);
// }