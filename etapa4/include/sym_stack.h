#ifndef _SYM_STACK_H_
#define _SYM_STACK_H_

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "sym_table.h"

#define ERR_UNDECLARED 10 //2.2
#define ERR_DECLARED 11 //2.2
#define ERR_VARIABLE 20 //2.3
#define ERR_FUNCTION 21 //2.3

typedef struct stack_of_tables {
    table_of_symbols_t *top; // Topo da pilha
    table_of_symbols_t **tables; // Ponteiro para o array que armazena os elementos da pilha
    int size; // Tamanho atual da pilha
    int capacity; // Capacidade máxima da pilha
} stack_of_tables_t;

// Inicializa uma nova pilha de tabelas de símbolos.
stack_of_tables_t* create_stack_of_tables();

// Cria uma nova tabela de símbolos e a empilha na pilha de escopos.
int push_scope(stack_of_tables_t* stack);

// Desempilha a tabela de símbolos do escopo atual e libera a memória associada.
table_of_symbols_t* pop_scope(stack_of_tables_t* stack);

// Libera toda a memória associada à pilha de tabelas de símbolos.
void free_stack_of_tables(stack_of_tables_t* stack);

int check_types(val_lex_t *val_lex_1 , val_lex_t *val_lex_2);


#endif // _SYM_STACK_H_