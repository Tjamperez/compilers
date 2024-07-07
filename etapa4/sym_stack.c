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
int push_scope(stack_of_tables_t* stack) {
    if (stack->size == stack->capacity) {
        stack->capacity *= 2;
        stack->tables = (table_of_symbols_t **)realloc(stack->tables, sizeof(table_of_symbols_t *) * stack->capacity);
    }
    table_of_symbols_t *new_table = create_table_of_symbols(stack->top);
    stack->tables[stack->size++] = new_table;
    stack->top = new_table;
    return 0;
}

// Retirar da pilha.
table_of_symbols_t* pop_scope(stack_of_tables_t* stack) {
    if (stack->size == 0) {
        return NULL; // Erro: não a escopo a ser retirado.
    }
    table_of_symbols_t *top_table = stack->tables[--stack->size];
    stack->top = (stack->size == 0) ? NULL : stack->tables[stack->size - 1];
    return top_table;
}

// Limpar memória da pilha.
void free_stack_of_tables(stack_of_tables_t* stack) {
    while (stack->size > 0) {
        pop_scope(stack);
    }
    free(stack->tables);
    free(stack);
}

symbol_dictionary_t* search_symbol_stack(stack_of_tables_t *stack, char* key) {

    if (stack->size == 0)
        return NULL;
    
    symbol_dictionary_t* symbol_found = NULL;
    for(int thisScope = stack->size - 1; thisScope >= 0; thisScope--) {
        
    	symbol_found = find_symbol(stack->tables[thisScope], key);
    	
    	
    	if(symbol_found != NULL)
    		break;
    }
    
    return symbol_found;
}

void check_identifiers(stack_of_tables_t *stack, int naturezaSymbolo, const char *identificador) {

	symbol_dictionary_t *item = search_symbol_stack(stack,identificador);
	
	if(item != NULL) {
		int natureza = item->content->nature;
		
		if(naturezaSymbolo != natureza) {
			switch(natureza) {
				case TOKEN_NATURE_IDENTIFIER:
					exit(ERR_VARIABLE);
					break;
				case TOKEN_NATURE_FUNCTION:
					exit(ERR_FUNCTION);
					break;
                default:
                    printf("Wtf?");
                    break;
			}
		}
	}
} 

int check_types(val_lex_t *val_lex_1 , val_lex_t *val_lex_2) {
	int type_1, type_2;
    type_1 = val_lex_1->type;
    type_2 = val_lex_2->type;

	switch (type_1) {
    case LIT_TYPE_BOOL:
        switch (type_2) {
            case LIT_TYPE_INT:
                return LIT_TYPE_INT;
            case LIT_TYPE_FLOAT:
                return LIT_TYPE_FLOAT;
            default: // Qualquer caso que cair aqui é bool.
                return LIT_TYPE_BOOL;
        }
    case LIT_TYPE_FLOAT:
        return LIT_TYPE_FLOAT; // Float é extremamente dominante.
    case LIT_TYPE_INT:
        switch (type_2) {
            case LIT_TYPE_FLOAT:
                return LIT_TYPE_FLOAT;
            default:
                return LIT_TYPE_INT; // Qualquer caso que cair aqui é int, seja um bool ou int.
        }
    default:
        // Qualquer coisa que cair aqui é porque não deu bom...
        break;
}
}

int new_type(tree_node_t* nodo_origem, tree_node_t* nodo_destino) {
	int origem, destino;
    origem = nodo_origem->valor_lexico->type;
    destino = nodo_destino->valor_lexico->type;

	int tipoFinal  = check_types(nodo_destino,nodo_origem);
	
	check_types(nodo_destino,nodo_origem);
		
	return tipoFinal;
}
