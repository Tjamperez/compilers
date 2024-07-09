#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "sym_stack.h"


symbol_t* create_symbol(tree_node_t* tree_node, int nature, int data_type) {
    symbol_t *symbol = (symbol_t *)malloc(sizeof(symbol_t));
    symbol->tree_node = tree_node;
    symbol->data_type = data_type;
    symbol->nature = nature;
    symbol->following = NULL;
    return symbol;
}



int insert_symbol(table_of_symbols_t* table, char* key, symbol_t *symbol) {
    if (table->size == table->capacity) {
        table->capacity *= 2;
        table->items = (symbol_dictionary_t **)realloc(table->items, sizeof(symbol_dictionary_t *) * table->capacity);
        if (table->items == NULL) {
            // Handle realloc failure
            return -1;
        }
    }
    
    symbol_dictionary_t *identity = create_symbol_dictionary(key, symbol);
    if (identity == NULL) {
        return -1;
    }
    
    table->items[table->size++] = identity;
    return 0;
}


symbol_dictionary_t* create_symbol_dictionary(char *key, symbol_t *content) {
    symbol_dictionary_t *identity = (symbol_dictionary_t *)malloc(sizeof(symbol_dictionary_t));
    identity->key = key;
    identity->content = content;
    return identity;
}


table_of_symbols_t* create_table_of_symbols(table_of_symbols_t* parent) {
    table_of_symbols_t *table = (table_of_symbols_t *)malloc(sizeof(table_of_symbols_t));
    table->size = 0;
    table->capacity = 10;
    table->items = (symbol_dictionary_t **)malloc(sizeof(symbol_dictionary_t *) * table->capacity);
    table->next = NULL;
    table->parent = parent;
    return table;
}


symbol_t* find_symbol(table_of_symbols_t* table, char* key) {
    for (int i = 0; i < table->size; i++) {
        if (strcmp(table->items[i]->key, key) == 0) {
            return table->items[i]->content;
        }
    }
    return NULL;
}


void free_symbol(symbol_t* symbol) {
    free(symbol->tree_node);
    free(symbol);
}


void free_table_of_symbols(table_of_symbols_t* table) {
    for (int i = 0; i < table->size; i++) {
        free_symbol(table->items[i]->content);
        free((char *)table->items[i]->key);
        free(table->items[i]);
    }
    free(table->items);
    free(table);
}

table_of_symbols_t* initialize_symbol_table() {
    return create_table_of_symbols(NULL);
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