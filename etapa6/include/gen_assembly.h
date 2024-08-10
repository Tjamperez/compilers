#ifndef _GEN_ASSEMBLY_H
#define _GEN_ASSEMBLY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gen_code.h"

#define INITIAL_CAPACITY 16
#define NUM_REGISTERS 8

typedef struct assembly_code_list {
    char** codes;    // Array of assembly code strings
    int size;        // Current size
    int capacity;    // Allocated capacity
} assembly_code_list_t;

// Structure for managing register allocation
typedef struct {
    char* reg;      // Name of the register
    bool in_use;    // Whether the register is currently in use
} register_t;

// Global variables for register pool
register_t reg_pool[NUM_REGISTERS];

assembly_code_list_t* create_assembly_code_list();

void append_assembly_code(assembly_code_list_t* list, const char* code);

void init_register_pool();

char* allocate_register();

void free_register(char* reg);

#endif