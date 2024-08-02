#ifndef _SYM_TABLE_H_
#define _SYM_TABLE_H_

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tree.h"

#define TOKEN_NATURE_IDENTIFIER 1
#define TOKEN_NATURE_FUNCTION 2

#define TYPE_INT 1
#define TYPE_FLOAT 2
#define TYPE_BOOL 3

// Estrutura do símbolo
typedef struct symbol{
    tree_node_t* tree_node;
    int nature;
    int data_type;
    int adress_displacement;
    struct symbol *following;
    char* label;
} symbol_t;

// Estrutura do par chave,conteudo do símbolo
typedef struct symbol_dictionary{
    char *key;
    symbol_t *content;
} symbol_dictionary_t;

// Estrutura da lista de símbolos
typedef struct table_of_symbols {
    int size;
    int capacity;
    int current_adress_displacement;
    int base_displacement;
    bool is_global;
    symbol_dictionary_t **items;
    struct table_of_symbols *next;
    struct table_of_symbols *parent;
} table_of_symbols_t;

// Cria e inicializa uma nova tabela de símbolos, possivelmente vinculada a uma tabela pai.
table_of_symbols_t* create_table_of_symbols(table_of_symbols_t* parent);

//Funçã opara criar símbolo
symbol_t* create_symbol(tree_node_t* tree_node, int nature, int data_type);

// Insere um novo símbolo na tabela de símbolos especificada.
int insert_symbol(table_of_symbols_t* table, char* key, symbol_t *symbol);

// Busca um símbolo na tabela de símbolos especificada pelo seu lexema (chave).
symbol_t* find_symbol(table_of_symbols_t* table, char* key);

// Libera a memória associada a um símbolo.
void free_symbol(symbol_t* symbol);

// Libera a memória associada à tabela de símbolos
void free_table_of_symbols(table_of_symbols_t* table);

// Libera a memória associada a uma tabela de símbolos e todos os seus símbolos.
void cleanup_symbol_table(table_of_symbols_t* table);

//Inicializa a pilha de tabela de símbolos.
table_of_symbols_t* initialize_symbol_table();

//Cria o dicionário pro símbolo.
symbol_dictionary_t* create_symbol_dictionary(char *key, symbol_t *content);

#endif // _SYM_TABLE_H_