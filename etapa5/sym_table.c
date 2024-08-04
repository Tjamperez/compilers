#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "sym_stack.h"


symbol_t* create_symbol(tree_node_t* tree_node, int nature, int data_type, char* label) {
    symbol_t *symbol = (symbol_t *)malloc(sizeof(symbol_t));
    symbol->tree_node = tree_node;
    symbol->data_type = data_type;
    symbol->nature = nature;
    symbol->following = NULL;
    symbol->label = label;
    return symbol;
}

int insert_symbol(table_of_symbols_t* table, char* key, symbol_t *symbol) {

    if (table->size == table->capacity) {
        table->capacity *= 2;
        table->items = (symbol_dictionary_t **)realloc(table->items, sizeof(symbol_dictionary_t *) * table->capacity);
        if (table->items == NULL) {
            return -1;
        }
    }
    //fprintf(stderr, "Debug MISERY\n");
    symbol->adress_displacement = table->current_adress_displacement;

    symbol_dictionary_t *identity = (symbol_dictionary_t *)malloc(sizeof(symbol_dictionary_t));
    if (identity == NULL) {
        return -1;
    }
    //fprintf(stderr, "Debug PAIN\n");
    identity->key = strdup(key);
    identity->content = symbol;

    table->items[table->size++] = identity;

    //fprintf(stderr, "Debug DEATH\n");

    table->current_adress_displacement += sizeof(symbol_t); 

    return 0;
}


symbol_dictionary_t* create_symbol_dictionary(char *key, symbol_t *content) {
    symbol_dictionary_t *identity = (symbol_dictionary_t *)malloc(sizeof(symbol_dictionary_t));
    identity->key = key;
    identity->content = content;
    return identity;
}


table_of_symbols_t* create_table_of_symbols(table_of_symbols_t* parent , bool globality) {
    table_of_symbols_t *table = (table_of_symbols_t *)malloc(sizeof(table_of_symbols_t));
    table->size = 0;
    table->capacity = 10;
    table->current_adress_displacement = 0;
    table-> base_displacement = 0;
    table->items = (symbol_dictionary_t **)malloc(sizeof(symbol_dictionary_t *) * table->capacity);
    table->next = NULL;
    table->parent = parent;
    table->is_global = globality;
    return table;
}

table_of_symbols_t* create_table_of_symbols_global(table_of_symbols_t* parent , bool globality) {
    table_of_symbols_t *table = (table_of_symbols_t *)malloc(sizeof(table_of_symbols_t));
    table->size = 0;
    table->capacity = 10;
    table->current_adress_displacement = 0;
    table-> base_displacement = 16;
    table->items = (symbol_dictionary_t **)malloc(sizeof(symbol_dictionary_t *) * table->capacity);
    table->next = NULL;
    table->parent = parent;
    table->is_global = globality;
    return table;
}


symbol_t* find_symbol(table_of_symbols_t* table, char* key) {
    for (int i = 0; i < table->size; i++) {
        if (strcmp(table->items[i]->key, key) == 0) {
            //printf("\n\n%s\n\n", table->items[i]->content->tree_node->valor_lexico->token_value);
            return table->items[i]->content;
        }
    }
    return NULL;
}


void free_symbol(symbol_t* symbol) {
    free(symbol->tree_node);
    free(symbol);
}


void free_table_of_symbols(table_of_symbols_t* table) {  // Why does this cause Seg fault sometimes and not the others????
    for (int i = 0; i < table->size; i++) {
        free_symbol(table->items[i]->content);
        free((char *)table->items[i]->key);
        free(table->items[i]);
    }
    free(table->items);
    free(table);
}

table_of_symbols_t* initialize_symbol_table() {
    return create_table_of_symbols(NULL,false);
}

void cleanup_symbol_table(table_of_symbols_t* table) {
    if (table == NULL) {
        return;
    }
    
    if (table->next) {
        cleanup_symbol_table(table->next);
    }
    
    free_table_of_symbols(table);
}

symbol_t* delete_symbol(table_of_symbols_t* table, char* key) {
    for (int i = 0; i < table->size; i++) {
        if (strcmp(table->items[i]->key, key) == 0) {
            symbol_t* deleted_symbol = table->items[i]->content;

           
            free((char*)table->items[i]->key);
            free(table->items[i]);

            for (int j = i; j < table->size - 1; j++) {
                table->items[j] = table->items[j + 1];
            }

            table->size--;

            return deleted_symbol;
        }
    }

    return NULL;
}