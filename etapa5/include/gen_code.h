#ifndef _GEN_CODE_H
#define _GEN_CODE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    nop, // Não tem operação
    add, sub, mult, div, // Operações Aritméticas
    addi, subi, rsubi, multi, divi, rdivi, // Operações Aritméticas Imediatas
    lshift, lshifti, rshift, rshifti, // Operações de Deslocamento
    and, andi, or, ori, xor, xori, // Operações Lógicas
    loadi, load, loadai, loada0, // Operações de Consulta
    cload, cloadai, cloada0, // Operações de Consulta para Caractéres
    store, storeai, storeao, // Operações de Armazenamento
    cstore, cstoreai, cstoreao, // Operações de Armazenamento de Caractéres
    i2i, c2c, c2i, i2c, // Operações de Cópia e Mudança de Tipo de Instruções
    jumpi, jump, cbr, // Operações de Pulo
    cmp_lt, cmp_le, cmp_eq, cmp_ge, cmp_gt, cmp_ne // Operações de Comparação
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

// Limpar Memória
void free_operation(operation_t* operation);

// Transformar o opcode em Label para display
const char* opcode_to_string(iloc_opcode_t opcode);

// Linkar Operações
operation_t* append_operation(operation_t* father_operation, operation_t* son_operation);

// Limpar todas operações
void free_operations_list(operation_t* head);

//Gerador de Temporários
char* generate_temp(int* temp_counter);

//Gerador de Labels
char* generate_label(int* label_counter);

#endif // _GEN_CODE_H