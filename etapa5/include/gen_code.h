#ifndef _GEN_CODE_H
#define _GEN_CODE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    NOP, // Não tem operação
    ADD, SUB, MULT, DIV, // Operações Aritméticas
    ADDI, SUBI, RSUBI, MULTI, DIVI, RDIVI, // Operações Aritméticas Imediatas
    LSHIFT, LSHIFTI, RSHIFT, RSHIFTI, // Operações de Deslocamento
    AND, ANDI, OR, ORI, XOR, XORI, // Operações Lógicas
    LOADI, LOAD, LOADAI, LOADA0, // Operações de Consulta
    CLOAD, CLOADAI, CLOADA0, // Operações de Consulta para Caractéres
    STORE, STOREAI, STOREAO, // Operações de Armazenamento
    CSTORE, CSTOREAI, CSTOREAO, // Operações de Armazenamento de Caractéres
    I2I, C2C, C2I, I2C, // Operações de Cópia e Mudança de Tipo de Instruções
    JUMPI, JUMP, CBR, // Operações de Pulo
    CMP_LT, CMP_LE, CMP_EQ, CMP_GE, CMP_GT, CMP_NE // Operações de Comparação
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

// Linkar operações
void append_operation(operation_t** head, operation_t* new_operation);

// Limpar todas operações
void free_operations_list(operation_t* head);

//Gerador de Temporários
char* generate_temp(int* temp_counter);

//Gerador de Labels
char* generate_label(int* label_counter);

#endif // _GEN_CODE_H