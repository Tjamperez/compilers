#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "tree.h"

tree_node_t *ast_new(val_lex_t *valor_lexico) {
    tree_node_t *ret = calloc(1, sizeof(tree_node_t));
    if (ret) {
        ret->valor_lexico = valor_lexico;
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
}

void print_node(FILE *fp, tree_node_t *node) {
    if (!node) return;
    fprintf(fp, "\"%p\" [label=\"Type: %d\\nValue: %s\"];\n",
            (void*)node, node->valor_lexico->type, node->valor_lexico->token_value);

    for (int i = 0; i < node->num_children; i++) {
        fprintf(fp, "\"%p\" -> \"%p\";\n", (void*)node, (void*)(node->children[i]));
        print_node(fp, node->children[i]);  // Recursive call to print children
    }
}


void ast_print_dot(tree_node_t *root, const char *filename) {
    FILE *fp = fopen(filename, "w");
    if (!fp) {
        fprintf(stderr, "Error opening file\n");
        return;
    }
    fprintf(fp, "digraph AST {\n");
    if (root) {
        print_node(fp, root);
    }
    fprintf(fp, "}\n");
    fclose(fp);
}

void exporta(tree_node_t *arvore) {
    if (arvore == NULL) return;

    // Print o label do nodo da árvore
    printf("%p [label=\"%s\"];\n", (void*)arvore, arvore->valor_lexico->token_value);

    // Print os filhos do nodo
    for (int i = 0; i < arvore->num_children; i++) {
        printf("%p, %p\n", (void*)arvore, (void*)(arvore->children[i]));
    }

    // Chama recusivamente os filhos dos nodos
    for (int i = 0; i < arvore->num_children; i++) {
        exporta(arvore->children[i]);
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