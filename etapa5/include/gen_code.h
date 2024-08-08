#ifndef _GEN_CODE_H
#define _GEN_CODE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    NOP, // Não tem operação
    ADD, SUB, MULT, DIV, //div, // Operações Aritméticas
    ADDI, SUBI, RSUBI, MULTI, DIVI, RDIVI, // Operações Aritméticas Imediatas
    LSHIFT, LSHIFTI, RSHIFT, RSHIFTI, // Operações de Deslocamento
    AND, ANDI, OR, ORI, XOR, XORI, // Operações Lógicas
    LOADI, LOAD, LOADAI, LOADA0, // Operações de Consulta
    CLOAD, CLOADAI, CLOADA0, // Operações de Consulta para Caractéres
    STORE, STOREAI, STOREAO, // Operações de Armazenamento
    CSTORE, CSTOREAI, CSTOREAO, // Operações de Armazenamento de Caractéres
    I2I, C2C, C2I, I2C, // Operações de Cópia e Mudança de Tipo de Instruções
    JUMPI, JUMP, CBR, // Operações de Pulo
    CMP_LT, CMP_LE, CMP_EQ, CMP_GE, CMP_GT, CMP_NE, // Operações de Comparação
    HALT
} iloc_opcode_t;

typedef struct operation {
    char* label;
    iloc_opcode_t opcode;
    char* op1;
    char* op2;
    char* op3;
    struct operation* next;
} operation_t;


// Inicializar Operação
operation_t* initialize_operation(const char* label, iloc_opcode_t opcode, const char* op1, const char* op2, const char* op3);

int get_opcode_from_string(const char* op);

void print_with_ascii(const char* str);

int compare_strings(const char* str1, const char* str2);

// Limpar Memória
void free_operation(operation_t* operation);

// Transformar o opcode em Label para display
const char* opcode_to_string(iloc_opcode_t opcode);

// Linkar Operações
operation_t* append_operations(operation_t* father_operation, operation_t* son_operation);

// Limpar todas operações
void free_operations_list(operation_t* head);

//Gerador de Temporários
char* generate_temp();

//Gerador de Labels
char* generate_label();

//Finalizar a Arvore
operation_t* gen_wrapper_code(operation_t* code, char* main_label);

operation_t* fill_holes(operation_t* code);

void print_operations(operation_t* op1);

void print_all_operations(operation_t* operation);

#endif // _GEN_CODE_H