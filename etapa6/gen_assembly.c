#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "gen_assembly.h"


assembly_code_list_t* create_assembly_code_list() {
    assembly_code_list_t* list = malloc(sizeof(assembly_code_list_t));
    list->size = 0;
    list->capacity = INITIAL_CAPACITY;
    list->codes = malloc(list->capacity * sizeof(char*));
    return list;
}

void append_assembly_code(assembly_code_list_t* list, const char* code) {

    if (list->size >= list->capacity) {
        list->capacity *= 2;
        list->codes = realloc(list->codes, list->capacity * sizeof(char*));
    }

    list->codes[list->size] = strdup(code);
    list->size++;
}

// Function to initialize the register pool
void init_register_pool() {
    const char* reg_names[NUM_REGISTERS] = {"%rax", "%rbx", "%rcx", "%rdx", "%rsi", "%rdi", "%r8", "%r9"};
    for (int i = 0; i < NUM_REGISTERS; i++) {
        reg_pool[i].reg = strdup(reg_names[i]);
        reg_pool[i].in_use = false;
    }
}

// Function to allocate a register
char* allocate_register() {
    for (int i = 0; i < NUM_REGISTERS; i++) {
        if (!reg_pool[i].in_use) {
            reg_pool[i].in_use = true;
            return reg_pool[i].reg;
        }
    }
    
    return NULL;
}


void free_register(char* reg) {
    for (int i = 0; i < NUM_REGISTERS; i++) {
        if (strcmp(reg_pool[i].reg, reg) == 0) {
            reg_pool[i].in_use = false;
            break;
        }
    }
}
