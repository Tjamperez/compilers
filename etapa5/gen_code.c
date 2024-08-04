#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "gen_code.h"

// Inicializar Operação
operation_t* initialize_operation(const char* label, iloc_opcode_t opcode, const char* op1, const char* op2, const char* op3) {
    operation_t* operation = (operation_t*)malloc(sizeof(operation_t));
    if (!operation) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    operation->label = label ? strdup(label) : NULL;
    operation->opcode = opcode;
    operation->op1 = op1 ? strdup(op1) : NULL;
    operation->op2 = op2 ? strdup(op2) : NULL;
    operation->op3 = op3 ? strdup(op3) : NULL;
    operation->next = NULL;
    return operation;
}


//Finalizar a arvore
operation_t* gen_wrapper_code(operation_t* code, char* main_label) {
    int op_counter = 0;
    for (operation_t* op=code; op!=NULL; op=op->next) {
        op_counter++;
    }

    operation_t* generated_code = initialize_operation(NULL, LOADI, strdup("1024"), strdup("rfp"), NULL);
    operation_t* generated_code2 = initialize_operation(NULL, LOADI, strdup("1024"), strdup("rsp"), NULL);
    char* op1 = malloc(10);
    sprintf(op1, "%d", op_counter + 4);
    operation_t* generated_code3 = initialize_operation(NULL, LOADI, op1, strdup("rbss"), NULL);
    operation_t* generated_code4 = initialize_operation(NULL, JUMPI, main_label, NULL, NULL);
    operation_t* generated_code5 = initialize_operation(NULL, HALT, NULL, NULL, NULL);

    append_operations(generated_code, generated_code2);
    append_operations(generated_code, generated_code3);
    append_operations(generated_code, generated_code4);
    append_operations(generated_code, code);
    append_operations(generated_code, generated_code5);

    return generated_code;
}

operation_t* fill_holes(operation_t* code) {
    int op_counter = 0;
    for (operation_t* op=code; op!=NULL; op=op->next) {
        op_counter++;
        if ((op->opcode == LOADI) && (op->op1 == NULL)) {
            op->op1 = (char*) malloc(10);
            sprintf(op->op1, "%d", op_counter+4);
        }
    }
    return code;
}

// Limpar Memória
void free_operation(operation_t* operation) {
    if (operation->label) free(operation->label);
    if (operation->op1) free(operation->op1);
    if (operation->op2) free(operation->op2);
    if (operation->op3) free(operation->op3);
    free(operation);
}


// Transformar o opcode em Label para display
const char* opcode_to_string(iloc_opcode_t opcode) {
    switch (opcode) {
        case NOP: return "nop";
        case ADD: return "add";
        case SUB: return "sub";
        case MULT: return "mult";
        case DIV: return "div";
        case ADDI: return "addI";
        case SUBI: return "subI";
        case RSUBI: return "rsubI";
        case MULTI: return "multI";
        case DIVI: return "divI";
        case RDIVI: return "rdivI";
        case LSHIFT: return "lshift";
        case LSHIFTI: return "lshiftI";
        case RSHIFT: return "rshift";
        case RSHIFTI: return "rshiftI";
        case AND: return "and";
        case ANDI: return "andI";
        case OR: return "or";
        case ORI: return "orI";
        case XOR: return "xor";
        case XORI: return "xorI";
        case LOADI: return "loadI";
        case LOAD: return "load";
        case LOADAI: return "loadAI";
        case LOADA0: return "loadA0";
        case CLOAD: return "cload";
        case CLOADAI: return "cloadAI";
        case CLOADA0: return "cloadA0";
        case STORE: return "store";
        case STOREAI: return "storeAI";
        case STOREAO: return "storeAO";
        case CSTORE: return "cstore";
        case CSTOREAI: return "cstoreAI";
        case CSTOREAO: return "cstoreAO";
        case I2I: return "i2i";
        case C2C: return "c2c";
        case C2I: return "c2i";
        case I2C: return "i2c";
        case JUMPI: return "jumpI";
        case JUMP: return "jump";
        case CBR: return "cbr";
        case CMP_LT: return "cmp_LT";
        case CMP_LE: return "cmp_LE";
        case CMP_EQ: return "cmp_EQ";
        case CMP_GE: return "cmp_GE";
        case CMP_GT: return "cmp_GT";
        case CMP_NE: return "cmp_NE";
        case HALT: return "halt";
        default: return "unknown";
    }
}

// operation_t* append_operations(operation_t* father_operation, operation_t* son_operation) {
//     if (father_operation == NULL) {
//         return son_operation;
//     }

//     if (son_operation == NULL) {
//         return father_operation;
//     }

//     operation_t* current = father_operation;
//     while (current->next != NULL) {
//         //fprintf(stderr, "Current operation: %p\n", current);
//         current = current->next;
//     }

//     current->next = son_operation;
//     return father_operation;
// }

operation_t* append_operations(operation_t* father_operation, operation_t* son_operation) {
    if (father_operation == NULL) {
        return son_operation;
    }

    if (son_operation == NULL) {
        return father_operation;
    }

    // Check for circular reference
    operation_t* current = son_operation;
    while (current != NULL) {
        if (current == father_operation) {
            fprintf(stderr, "Error: Circular reference detected when appending operations.\n");
            return father_operation;
        }
        current = current->next;
    }

    // Find the end of the father_operation list
    current = father_operation;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = son_operation;

    fprintf(stderr, "Appended operations: father_operation=%p, son_operation=%p\n", father_operation, son_operation);

    return father_operation;
}

void free_operations_list(operation_t* head) {
    operation_t* current = head;
    operation_t* next;
    while (current != NULL) {
        next = current->next;
        free_operation(current);
        current = next;
    }
}

// Geradora de Labels
char* generate_label(int *label_counter) {
    fprintf(stderr, "Debug message label\n");
    char *label = (char*)malloc(20 * sizeof(char));
    snprintf(label, 20, "L%d", (*label_counter)++);
    return label;
}

// Geradora de Temps
char* generate_temp(int *temp_counter) {
    fprintf(stderr, "Debug message temp\n");
    char *temp = (char*)malloc(20 * sizeof(char));
    snprintf(temp, 20, "t%d", (*temp_counter)++);
    return temp;
}