#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "sym_stack.h"


symbol_t* create_symbol(val_lex_t tree_node_values, int nature) {
    symbol_t *symbol = (symbol_t *)malloc(sizeof(symbol_t));
    symbol->tree_node_values = tree_node_values;
    symbol->nature = nature;
    symbol->following = NULL;
    return symbol;
}



int insert_symbol(table_of_symbols_t* table, const char* key, val_lex_t tree_node_values, int nature) {
    if (table->size == table->capacity) {
        table->capacity *= 2;
        table->items = (symbol_dictionary_t **)realloc(table->items, sizeof(symbol_dictionary_t *) * table->capacity);
    }
    symbol_t *symbol = create_symbol(tree_node_values, nature);
    symbol_dictionary_t *identity = create_symbol_dictionary(key, symbol);
    table->items[table->size++] = identity;
    return 0;
}


symbol_dictionary_t* create_symbol_dictionary(const char *key, symbol_t *content) {
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


symbol_t* find_symbol(table_of_symbols_t* table, const char* key) {
    for (int i = 0; i < table->size; i++) {
        if (strcmp(table->items[i]->key, key) == 0) {
            return table->items[i]->content;
        }
    }
    return NULL;
}


void free_symbol(symbol_t* symbol) {
    free((char *)symbol->tree_node_values.token_value);
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
    if (table->next) {
        cleanup_symbol_table(table->next); 
    }
    free_table_of_symbols(table);
}