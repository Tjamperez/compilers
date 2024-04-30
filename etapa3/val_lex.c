#include "val_lex.h"

#ifdef HAVE_LEX_YY_H
#include "lex.yy.h"  // Tirar erro do compilador pois lex só é gerado na compilação
#endif

val_lex_t *gen_val(int line, int type, const char *token) {
    // Alocamos memória para um novo objeto val_lex_t
    val_lex_t *new_val = malloc(sizeof(val_lex_t));
    
    // Verificamos se a alocação foi bem-sucedida
    if (new_val == NULL) {
        fprintf(stderr, "Erro: Falha ao alocar memória para val_lex_t\n");
        return NULL;
    }
    
    // Preenchemos os campos da estrutura com os valores fornecidos(literais ou identificadores)
    new_val->lineno = line;
    new_val->type = type;

	#ifdef HAVE_LEX_YY_H
    // Alocamos memória para armazenar uma cópia do token_value
    new_val->token_value = strdup(yytext);
    
    // Verificamos se a cópia do token_value foi bem-sucedida
    if (new_val->token_value == NULL) {
        fprintf(stderr, "Erro: Falha ao alocar memória para token_value\n");
        free(new_val);  // Libera a memória alocada para new_val
        return NULL;
    }
	// Handle error or provide alternative behavior if yytext is not available
	else{
		fprintf(stderr, "Erro: yytext não está definido (lex.yy.h não foi incluido)\n");
    	new_val->token_value = NULL;  // Set token_value to NULL or handle appropriately
	}
    	
    #endif
    // Retornamos o novo objeto val_lex_t criado para as próximas funções
    return new_val;
}