#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define NOT_LIT	 	 		0
#define LIT_TYPE_INT 		1
#define LIT_TYPE_BOOL 		2
#define LIT_TYPE_STRING		5


typedef struct val_lex{
int lineno;
int type;
char *token_value;
} val_lex_t;

val_lex_t* gen_val(int line, int type);

