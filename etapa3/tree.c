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
    return node;
}

void ast_free(tree_node_t *root) {
    if (root == NULL) return;
    for (int i = 0; i < root->num_children; i++) {
        ast_free(root->children[i]);
    }
    free(root->valor_lexico->token_value);
    free(root->valor_lexico);
    free(root->children);
    free(root);
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

void exporta(tree_node_t *node) {
    if (node == NULL) return;
    // Print the current node
    printf("Node %p [Type: %d, Value: %s]\n", (void*)node, node->valor_lexico->type, node->valor_lexico->token_value);
    for (int i = 0; i < node->num_children; i++) {
        printf("Child of %p -> %p\n", (void*)node, (void*)(node->children[i]));
        exporta(node->children[i]);
    }
}
