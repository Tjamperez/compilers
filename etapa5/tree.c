#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "tree.h"

// Função para criar um novo nó na árvore, com um valor léxico fornecido
tree_node_t *ast_new(val_lex_t *valor_lexico) {
    tree_node_t *ret = calloc(1, sizeof(tree_node_t));
    if (ret) {
        ret->valor_lexico = valor_lexico;
        ret->children = NULL;
        ret->node_type = NODE_TYPE_UNDECLARED;
        ret->num_children = 0;
    }
    return ret;
}

// Função para criar um novo nó na árvore com apenas um rótulo (sem valor léxico)
tree_node_t *ast_new_label_only(char *label) {
    tree_node_t *ret = calloc(1, sizeof(tree_node_t));
    val_lex_t *aux = calloc(1, sizeof(val_lex_t));
    if (ret) {
        aux->token_value = label;
        ret->valor_lexico =  aux;
        ret->children = NULL;
        ret->num_children = 0;
    }
    return ret;
}

// Função para criar um novo nó representando uma chamada de função
tree_node_t *ast_new_call_func(val_lex_t *valor_lexico) {
    tree_node_t *ret = calloc(1, sizeof(tree_node_t));
    val_lex_t *aux_val = calloc(1, sizeof(val_lex_t));

    *aux_val = *valor_lexico;

    char *result = malloc(strlen("call ") + strlen(aux_val->token_value) + 1);
    if (result) {
        strcpy(result, "call ");
        strcat(result, aux_val->token_value);
        aux_val->token_value = result;

        if (ret) {
            ret->valor_lexico = aux_val;
            ret->children = NULL;
            ret->num_children = 0;
        }
    } else {
        fprintf(stderr, "Failed to allocate memory for result.\n");
        free(aux_val);
        free(ret);
        ret = NULL;
    }

    return ret;
}

// Função para liberar a memória alocada para a árvore
void ast_free(tree_node_t *tree) {
    if (tree != NULL) {
        int i;
        for (i = 0; i < tree->num_children; i++) {
            ast_free(tree->children[i]);
        }
        free(tree->children);
        free(tree->valor_lexico);
        free(tree);
    } else {
        printf("Erro: %s recebeu parâmetro tree = %p.\n", __FUNCTION__, tree);
    }
}

// Função para adicionar um filho a um nó na árvore
void ast_add_child(tree_node_t *parent, tree_node_t *child) {
    if (parent == NULL || child == NULL) return;
    parent->num_children++;
    parent->children = realloc(parent->children, parent->num_children * sizeof(tree_node_t *));
    if (!parent->children) {
        fprintf(stderr, "Error: Falha ao realocar memória\n");
        exit(EXIT_FAILURE);
    }
    parent->children[parent->num_children - 1] = child;
}

// Função para retirarmos o call da chamada de função para analise na tabela
char* ast_parse_function_call(char *token_value) {
    
    char *function_name = strstr(token_value, " ");
    
    if (function_name != NULL) {
        // Pulamos o espaço
        function_name++;
    }
    
    return function_name;
}



// Função para exportar a árvore para visualização
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

//Função para passar os nodos para concatenação
operation_t* append_node_operation(tree_node_t* father_node, tree_node_t* son_node) {
    if (father_node == NULL) {
        if (son_node == NULL) {
            return NULL;
        }
        return son_node->code;
    }
    if (son_node == NULL) {
        return father_node->code;
    }
    operation_t* temp = append_operation(father_node->code, son_node->code);
    return temp;
}
