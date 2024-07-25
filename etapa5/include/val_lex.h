#ifndef VAL_LEX_H
#define VAL_LEX_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define IDENTIFIER_TYPE 	0

#define LIT_TYPE_INT 		1
#define LIT_TYPE_FLOAT 		2
#define LIT_TYPE_BOOL		3

#define PR_TYPE_INT			4
#define PR_TYPE_FLOAT		5
#define PR_TYPE_BOOL		6
#define PR_TYPE_IF			7
#define PR_TYPE_ELSE		8
#define PR_TYPE_WHILE		9
#define PR_TYPE_RETURN		10

#define SPECIAL_CHAR		11

#define OC_TYPE_LE			12
#define OC_TYPE_GE			13
#define OC_TYPE_EQ			14
#define OC_TYPE_NE			15
#define OC_TYPE_AND			16
#define OC_TYPE_OR			17


typedef struct val_lex{
int lineno;
int type;
char *token_value;
} val_lex_t;

val_lex_t *gen_val(int line, int type, char *token);

#endif /* VAL_LEX_H */