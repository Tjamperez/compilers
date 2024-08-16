#ifndef _GEN_ASSEMBLY_H
#define _GEN_ASSEMBLY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sym_table.h>
#include <sym_stack.h>

#define INITIAL_CAPACITY 16
#define NUM_REGISTERS 8
#define OPCODE_SIZE_OF_BUFFER 256 

typedef struct assembly_code_list {
    char** codes;    
    int size;        
    int capacity;    
} assembly_code_list_t;

typedef struct {
    char* reg;      
    bool in_use;    
} register_x86_t;

extern register_x86_t reg_pool[NUM_REGISTERS];
extern assembly_code_list_t* global_code_list;


assembly_code_list_t* create_assembly_code_list();
void append_assembly_code(assembly_code_list_t* list, const char* code);
void init_register_pool();
char* allocate_register();
void free_register(char* reg);
char* spill_register();
char* allocate_stack_space();
void free_assembly_code_list(assembly_code_list_t* list);
void generate_prologue(const char* function_name);
void generate_epilogue();
void print_assembly_code_list(const assembly_code_list_t *list);
void generate_global_variables(stack_of_tables_t* stack , assembly_code_list_t* global_code_list);
void print_all_assembly(assembly_code_list_t* assembly_list);
void generate_movq(const char* src, const char* dest, assembly_code_list_t* global_code_list);
void generate_assembly_prologue(const char* global_filename);
#endif //_GEN_ASSEMBLY_H
