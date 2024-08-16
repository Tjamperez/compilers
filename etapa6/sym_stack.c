#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "sym_stack.h"

// Criar a pilha.
stack_of_tables_t* create_stack_of_tables() {
    stack_of_tables_t *stack = (stack_of_tables_t *)malloc(sizeof(stack_of_tables_t));
    stack->size = 0;
    stack->capacity = 10;
    stack->tables = (table_of_symbols_t **)malloc(sizeof(table_of_symbols_t *) * stack->capacity);
    stack->top = NULL;
    return stack;
}


// Inserir na pilha.
int push_scope(stack_of_tables_t* stack, table_of_symbols_t *new_table) {

    if (stack->size == stack->capacity) {
        stack->capacity *= 2;
        stack->tables = (table_of_symbols_t **)realloc(stack->tables, sizeof(table_of_symbols_t *) * stack->capacity);
    }



    stack->tables[stack->size++] = new_table;
    stack->top = new_table;
    return 0;
}

// Retirar da pilha.
table_of_symbols_t* pop_scope(stack_of_tables_t* stack) {
    if (stack->size == 0) {
        return NULL; // Erro: não há escopo a ser retirado.
    }
    table_of_symbols_t *top_table = stack->tables[--stack->size];
    stack->top = (stack->size == 0) ? NULL : stack->tables[stack->size - 1];
    return top_table;
}

table_of_symbols_t* search_stack_for_address(stack_of_tables_t *stack, char* key) {

    if (stack->size == 0)
        return NULL;
    int thisScope = 0;
    symbol_t* symbol_found = NULL;
    for(thisScope = stack->size - 1; thisScope >= 0; thisScope--) {
        
    	symbol_found = find_symbol(stack->tables[thisScope], key);
    	
    	
    	if(symbol_found != NULL)
    		break;
    }
    
    return stack->tables[thisScope];
}

// Limpar memória da pilha.
void free_stack_of_tables(stack_of_tables_t* stack) {
    while (stack->size > 0) {
        pop_scope(stack);
    }
    free(stack->tables);
    free(stack);
}

// Procurar símbolo na pilha de tabelas de símbolos.
symbol_t* search_symbol_stack(stack_of_tables_t *stack, char* key) {

    if (stack->size == 0)
        return NULL;
    
    symbol_t* symbol_found = NULL;
    for(int thisScope = stack->size - 1; thisScope >= 0; thisScope--) {
        
    	symbol_found = find_symbol(stack->tables[thisScope], key);
    	
    	
    	if(symbol_found != NULL)
    		break;
    }
    
    return symbol_found;
}

// Checar natureza dos identificadores e ver se temos erro.
void check_identifiers(stack_of_tables_t *stack, int naturezaSymbolo, const char *identificador) {

	symbol_t *item = search_symbol_stack(stack,(char*)identificador);
	
	if(item != NULL) {
		int natureza = item->nature;
		
		if(naturezaSymbolo != natureza) {
			switch(natureza) {
				case TOKEN_NATURE_IDENTIFIER:
					exit(ERR_VARIABLE);
					break;
				case TOKEN_NATURE_FUNCTION:
					exit(ERR_FUNCTION);
					break;
                default:
                    //printf("Nunca deve acontecer\n\n");
                    break;
			}
		}
	}
} 


// Comparar tipos para retornar o novo tipo.
int check_types(tree_node_t* destiny_node, tree_node_t* origin_node) {
	int destino,origem;
    destino = destiny_node->node_type;
    origem = origin_node->node_type;
    //printf("Destino : %d\n\n", destino);
    //printf("Origem : %d\n\n", origem);
    
    switch (destino) {
    case NODE_TYPE_INT:
        switch (origem) {
            case NODE_TYPE_FLOAT:
                return NODE_TYPE_FLOAT;
            default:  // Inclui NODE_TYPE_INT, NODE_TYPE_BOOL, e qualquer outro caso.
                return NODE_TYPE_INT;
        }
    case NODE_TYPE_FLOAT:
        return NODE_TYPE_FLOAT; // Float é dominante em todos os casos.
    case NODE_TYPE_BOOL:
        switch (origem) {
            case NODE_TYPE_INT:
                return NODE_TYPE_INT;
            case NODE_TYPE_FLOAT:
                return NODE_TYPE_FLOAT;
            default:  // Inclui quaisquer casos que faltam, incluso NODE_TYPE_BOOL.
                return NODE_TYPE_BOOL;
        }
    
    default:
        //printf("Esse caso não deve acontecer.\n\n");
        return 10; // Erro generalizado.
    }


}

// Pegar o novo tipo e retornar.
int new_type(tree_node_t* destiny_node, tree_node_t* origin_node) {
	int tipoFinal  = check_types(destiny_node,origin_node);
	return tipoFinal;
}
