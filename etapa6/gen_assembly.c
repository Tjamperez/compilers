#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "gen_assembly.h"

register_x86_t reg_pool[NUM_REGISTERS];
assembly_code_list_t* global_code_list;

assembly_code_list_t* create_assembly_code_list() {
    assembly_code_list_t* list = malloc(sizeof(assembly_code_list_t));
    if (!list) {
        perror("Failed to allocate assembly code list");
        exit(EXIT_FAILURE);
    }
    list->size = 0;
    list->capacity = INITIAL_CAPACITY;
    list->codes = malloc(list->capacity * sizeof(char*));
    if (!list->codes) {
        perror("Failed to allocate assembly code list buffer");
        free(list);
        exit(EXIT_FAILURE);
    }
    return list;
}

void append_assembly_code(assembly_code_list_t* list, const char* code) {
    if (list->size > 0 && strcmp(list->codes[list->size - 1], code) == 0) {
        return;
    }

    if (list->size >= list->capacity) {
        list->capacity *= 2;
        char** temp = realloc(list->codes, list->capacity * sizeof(char*));
        if (!temp) {
            perror("Failed to reallocate assembly code list buffer");
            exit(EXIT_FAILURE);
        }
        list->codes = temp;
    }

    list->codes[list->size] = strdup(code);
    if (!list->codes[list->size]) {
        perror("Failed to duplicate assembly code string");
        exit(EXIT_FAILURE);
    }
    list->size++;
}

void prepend_assembly_code(assembly_code_list_t* list, const char* code) {
    if (list->size > 0 && strcmp(list->codes[0], code) == 0) {
        return;
    }

    if (list->size >= list->capacity) {
        list->capacity *= 2;
        char** temp = realloc(list->codes, list->capacity * sizeof(char*));
        if (!temp) {
            perror("Failed to reallocate assembly code list buffer");
            exit(EXIT_FAILURE);
        }
        list->codes = temp;
    }

    memmove(&list->codes[1], &list->codes[0], list->size * sizeof(char*));

    list->codes[0] = strdup(code);
    if (!list->codes[0]) {
        perror("Failed to duplicate assembly code string");
        exit(EXIT_FAILURE);
    }
    list->size++;
}


void print_assembly_code_list(const assembly_code_list_t *list) {
    if (list == NULL) {
        fprintf(stderr, "Error: global_code_list is NULL\n");
        return;
    }

    fprintf(stderr, "Assembly Code List (size = %d, capacity = %d):\n", list->size, list->capacity);
    
    for (int i = 0; i < list->size; i++) {
        if (list->codes[i] != NULL) {
            fprintf(stderr, "Code[%d]: %s\n", i, list->codes[i]);
        } else {
            fprintf(stderr, "Code[%d]: NULL\n", i);
        }
    }
}

void init_register_pool() {
    const char* reg_names[NUM_REGISTERS] = {"%rax", "%rbx", "%rcx", "%rdx", "%rsi", "%rdi", "%r8", "%r9"};
    for (int i = 0; i < NUM_REGISTERS; i++) {
        reg_pool[i].reg = strdup(reg_names[i]);
        if (!reg_pool[i].reg) {
            perror("Failed to initialize register pool");
            exit(EXIT_FAILURE);
        }
        reg_pool[i].in_use = false;
    }
}

char* allocate_register() {
    for (int i = 0; i < NUM_REGISTERS; i++) {
        if (!reg_pool[i].in_use) {
                                                                //fprintf(stderr,"%s\n",reg_pool[i].reg); Debug Print for checking alocation of registers
            reg_pool[i].in_use = true;
            return reg_pool[i].reg;
        }
    }
    char* spilled_reg = spill_register();
    if (spilled_reg) {
        return allocate_register();
    } else {
        fprintf(stderr, "Error: No registers available to spill\n");
        exit(EXIT_FAILURE);
    }
}

void free_register(char* reg) {
    for (int i = 0; i < NUM_REGISTERS; i++) {
        if (strcmp(reg_pool[i].reg, reg) == 0) {
                                                                //fprintf(stderr,"%s\n",reg_pool[i].reg); Debug Print for checking alocation of registers
            reg_pool[i].in_use = false;
            return;
        }
    }
    fprintf(stderr, "Error: Attempted to free an unallocated register: %s\n", reg);
}

char* spill_register() {
    for (int i = 0; i < NUM_REGISTERS; i++) {
        //fprintf(stderr,"%s\n",reg_pool[i].reg)
        if (reg_pool[i].in_use) {
            char* spill_location = allocate_stack_space();
            char assembly_code[OPCODE_SIZE_OF_BUFFER];
            snprintf(assembly_code, sizeof(assembly_code), "\tmovq\t %s, %s", reg_pool[i].reg, spill_location);
            append_assembly_code(global_code_list, assembly_code);

            reg_pool[i].in_use = false;
            return reg_pool[i].reg;
        }
    }
    return NULL;
}

char* allocate_stack_space() {
    static int current_offset = -8;
    char* location = malloc(OPCODE_SIZE_OF_BUFFER);
    if (!location) {
        perror("Failed to allocate stack space");
        exit(EXIT_FAILURE);
    }
    snprintf(location, OPCODE_SIZE_OF_BUFFER, "%d(%%rbp)", current_offset);
    current_offset -= 8;
    return location;
}

void free_assembly_code_list(assembly_code_list_t* list) {
    if (list) {
        for (int i = 0; i < list->size; i++) {
            free(list->codes[i]);
        }
        free(list->codes);
        free(list);
    }
}

void generate_global_variables(stack_of_tables_t* stack, assembly_code_list_t* global_code_list) {
    table_of_symbols_t* global_table = stack->tables[0];
    char assembly_code[OPCODE_SIZE_OF_BUFFER];

    for (int i = 0; i < global_table->size; i++) {
        symbol_dictionary_t* symbol = global_table->items[i];

        //snprintf(assembly_code, sizeof(assembly_code), "\t.zero 4");
        //prepend_assembly_code(global_code_list, assembly_code);

        snprintf(assembly_code, sizeof(assembly_code), "%s:\t", symbol->key);
        prepend_assembly_code(global_code_list, assembly_code);

        snprintf(assembly_code, sizeof(assembly_code), "\t.size\t %s, %d", symbol->key, 4);
        prepend_assembly_code(global_code_list, assembly_code);

        snprintf(assembly_code, sizeof(assembly_code), "\t.type\t %s, @object", symbol->key);
        prepend_assembly_code(global_code_list, assembly_code);

        snprintf(assembly_code, sizeof(assembly_code), "\t.align\t 4");
        prepend_assembly_code(global_code_list, assembly_code);

        snprintf(assembly_code, sizeof(assembly_code), "\t.data\t");
        prepend_assembly_code(global_code_list, assembly_code);

        snprintf(assembly_code, sizeof(assembly_code), "\t.globl\t %s", symbol->key);
        prepend_assembly_code(global_code_list, assembly_code);
    }
}

void generate_prologue(const char* function_name) {

    char assembly_code[OPCODE_SIZE_OF_BUFFER];

    if (function_name == NULL) {
    fprintf(stderr, "Error: function_name is NULL\n");
    exit(EXIT_FAILURE);
    }

    snprintf(assembly_code, sizeof(assembly_code), "\t.globl\t %s", function_name);

    if (global_code_list == NULL) {
    fprintf(stderr, "Error: global_code_list is NULL\n");
    exit(EXIT_FAILURE);
    }

    append_assembly_code(global_code_list, assembly_code);

    snprintf(assembly_code, sizeof(assembly_code), "\t.type\t %s, @function", function_name);
    append_assembly_code(global_code_list, assembly_code);

    snprintf(assembly_code, sizeof(assembly_code), "%s:\t", function_name);
    append_assembly_code(global_code_list, assembly_code);

    snprintf(assembly_code, sizeof(assembly_code), "\tpushq\t %%rbp");
    append_assembly_code(global_code_list, assembly_code);

    snprintf(assembly_code, sizeof(assembly_code), "\tmovq\t %%rsp, %%rbp");
    append_assembly_code(global_code_list, assembly_code);

    //snprintf(assembly_code, sizeof(assembly_code), "\tsubq\t $16, %%rsp\n");
    //append_assembly_code(global_code_list, assembly_code);
}

void generate_epilogue() {

    char assembly_code[OPCODE_SIZE_OF_BUFFER];

    snprintf(assembly_code, sizeof(assembly_code), "\n\tmovq\t %%rbp, %%rsp");
    append_assembly_code(global_code_list, assembly_code);

    snprintf(assembly_code, sizeof(assembly_code), "\tpopq\t %%rbp");
    append_assembly_code(global_code_list, assembly_code);

    snprintf(assembly_code, sizeof(assembly_code), "\tret\t");
    append_assembly_code(global_code_list, assembly_code);
}

void print_all_assembly(assembly_code_list_t* assembly_list) {
    if (assembly_list == NULL) {
        return;
    }

    for (int i = 0; i < assembly_list->size; i++) {
        printf("%s\n", assembly_list->codes[i]);
    }
}

void generate_movq(const char* src, const char* dest, assembly_code_list_t* global_code_list) {

    char assembly_code[OPCODE_SIZE_OF_BUFFER];

    snprintf(assembly_code, sizeof(assembly_code), "\tmovq\t %s, %s", src, dest);  

    append_assembly_code(global_code_list, assembly_code);
}

void generate_assembly_prologue(const char* global_filename) {
    char assembly_code[OPCODE_SIZE_OF_BUFFER];

    snprintf(assembly_code, sizeof(assembly_code), "\t.text\t");
    prepend_assembly_code(global_code_list, assembly_code);

    if (global_filename) {
        snprintf(assembly_code, sizeof(assembly_code), "\t.file\t\"%s\"", global_filename);
        prepend_assembly_code(global_code_list, assembly_code);
    }
}