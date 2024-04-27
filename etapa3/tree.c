#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "tree.h"
#define ARQUIVO_SAIDA "saida.dot"

tree_node_t *ast_new(val_lex_t *valor_lexico)
{
  tree_node_t *ret = NULL;
  ret = calloc(1, sizeof(tree_node_t));
  if (ret != NULL){
    ret->valor_lexico = valor_lexico;
    ret->children = NULL;
  }
  return ret;
}

void ast_free(tree_node_t *root) {
    if (root == NULL) {
        return;
    }
    
    for (int i = 0; i < root->num_children; i++) {
        ast_free(root->children[i]);
    }
    
    free(root->valor_lexico->token_value);
    free(root->valor_lexico);
    
    free(root->children);
    
    free(root);
}

void ast_add_child(tree_node_t *parent, tree_node_t *child) {
    if (parent == NULL || child == NULL) {
        return;
    }
    parent->num_children++;
    
    parent->children = realloc(parent->children, parent->num_children * sizeof(tree_node_t *));
    if (parent->children == NULL) {
        fprintf(stderr, "Error: Failed to reallocate memory for children array\n");
        exit(EXIT_FAILURE);
    }
    parent->children[parent->num_children - 1] = child;
}

void print_node(FILE *fp, tree_node_t *node) {
    fprintf(fp, "\"%p\" [label=\"", (void*)node);
    fprintf(fp, "Line: %d\\n", node->valor_lexico->lineno);
    fprintf(fp, "Type: %d\\n", node->valor_lexico->type);
    fprintf(fp, "Value: %s\"];\n", node->valor_lexico->token_value);
    
    for (int i = 0; i < node->num_children; i++) {
        fprintf(fp, "\"%p\" -> \"%p\";\n", (void*)node, (void*)(node->children[i]));
        print_node(fp, node->children[i]);
    }
}

void ast_print_dot(tree_node_t *root, const char *filename) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        fprintf(stderr, "Error: Unable to open file for writing\n");
        return;
    }
    
    fprintf(fp, "digraph AST {\n");
    
    if (root != NULL) {
        print_node(fp, root);
    }
    
    fprintf(fp, "}\n");
    
    fclose(fp);
}


