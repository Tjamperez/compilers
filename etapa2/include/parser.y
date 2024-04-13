    /* Arquivo feito por Thales Perez 00303035 e Vitor Vargas 000000 */

%{
#include <stdlib.h>
#include <stdio.h>

// Protótipos das funções necessárias
int yylex(void);
int yyerror(char const *s);
extern int get_line_number(void);
extern char *yytext;
%}

// Definição dos tokens
%token TK_PR_INT
%token TK_PR_FLOAT
%token TK_PR_BOOL
%token TK_PR_IF
%token TK_PR_ELSE
%token TK_PR_WHILE
%token TK_PR_RETURN
%token TK_OC_LE
%token TK_OC_GE
%token TK_OC_EQ
%token TK_OC_NE
%token TK_OC_AND
%token TK_OC_OR
%token TK_IDENTIFICADOR
%token TK_LIT_INT
%token TK_LIT_FLOAT
%token TK_LIT_FALSE
%token TK_LIT_TRUE
%token TK_ERRO

%%

//##########################
// Definição de programa
programa: lista_de_elementos
        | /* vazio */
        ;

//##########################
// Lista de elementos
lista_de_elementos: lista_de_elementos elemento
                  | elemento
                  ;

//##########################
// Elemento do programa
elemento: declaracao_global
        | definicao_de_funcao
        ;

//##########################
// Declaração global de variável
declaracao_global: tipo lista_identificador ','
                  ;

//##########################
// Identificador
identificador: TK_IDENTIFICADOR
              ;

//##########################
// Tipos de dados
tipo: INT
    | FLOAT
    | BOOL
    ;

//##########################
// Token INT
INT: TK_PR_INT ;

//##########################
// Token FLOAT
FLOAT: TK_PR_FLOAT ;

//##########################
// Token BOOL
BOOL: TK_PR_BOOL ;

//##########################
// Lista de identificadores
lista_identificador: lista_identificador ';' identificador
                    | identificador
                    ;

//##########################
// Definição de função
definicao_de_funcao: cabecalho corpo
                    ;

//##########################
// Cabeçalho da função
cabecalho: '(' lista_de_parametros ')' OR tipo '/' identificador
         ;

//##########################
// Token OR
OR: TK_OC_OR ;

//##########################
// Lista de parâmetros
lista_de_parametros: lista_de_parametros ';' parametro
                    | parametro
                    | /* vazio */
                    ;

//##########################
// Parâmetro da função
parametro: tipo identificador
         ;

//##########################
// Corpo da função
corpo: '{' bloco_de_comandos '}'
     ;

//##########################
// Bloco de comandos
bloco_de_comandos: bloco_de_comandos ',' comando_simples
                 | comando_simples_com_virgula
                 | /* vazio */
                 ;

//##########################
// Bloco de comandos obrigatório
bloco_de_comandos_obrigatorio: bloco_de_comandos_obrigatorio ',' comando_simples
                              | comando_simples_com_virgula
                              ;

//##########################
// Comando simples com virgula
comando_simples_com_virgula: declaracao_variavel ','
               | comando_atribuicao ','
               | chamada_funcao ','
               | comando_retorno ','
               | comando_controle_fluxo ','
			   ;

//##########################
// Comando simples sem virgula
comando_simples: declaracao_variavel
               | comando_atribuicao
               | chamada_funcao
               | comando_retorno
               | comando_controle_fluxo
			   ;

//##########################
// Declaração de variável
declaracao_variavel: tipo lista_identificador
                    ;

//##########################
// Comando de atribuição
comando_atribuicao: identificador '=' expressao
                   ;

//##########################
// Comando de retorno
RETURN: TK_PR_RETURN ;
comando_retorno: RETURN expressao ;

//##########################
// Comando de controle de fluxo
comando_controle_fluxo: condicional 
						| loop 
						;

//##########################
// Comando de if e else
IF: TK_PR_IF ;
ELSE: TK_PR_ELSE ;
condicional: IF '(' expressao ')' bloco_de_comandos_obrigatorio
           | IF '(' expressao ')' bloco_de_comandos_obrigatorio ELSE bloco_de_comandos_obrigatorio 
		   ;

//##########################
// Comando de loop
WHILE: TK_PR_WHILE ;
loop: WHILE '(' expressao ')' bloco_de_comandos 
	;

//##########################
// Expressão
expressao: termo
         | expressao OR termo
         ;

//##########################
// Termo
termo: fator
     | termo AND fator
     ;

//##########################
// Fator
fator: comparacao
     | fator EQUAL comparacao
     | fator NOTEQUAL comparacao
     | fator LESSTHAN comparacao
     | fator LESSEQUAL comparacao
     | fator GREATERTHAN comparacao
     | fator GREATEREQUAL comparacao
     ;

//##########################
// Comparação
comparacao: adicaousub
          | comparacao ADD adicaousub
          | comparacao SUBTRACT adicaousub
          ;

//##########################
// Adição ou Subtração
adicaousub: multoudivoures
      | adicaousub ADD multoudivoures
      | adicaousub SUBTRACT multoudivoures
      ;

//##########################
// Multiplicação ou Divisão ou Resto
multoudivoures: unario
             | multoudivoures MULTIPLY unario
             | multoudivoures DIVIDE unario
             | multoudivoures REMAINDER unario
             ;

//##########################
// Unário
unario: primario
      | INVERTSIG unario
      | NEGATE unario
      ;

//##########################
// Primário
primario: identificador
         | literais
         | chamada_funcao
         | '(' expressao ')'
         ;

//##########################
// Chamada de função
chamada_funcao: nome_func '(' lista_expressao ')'
              ;

//##########################
// Lista de expressões
lista_expressao: expressao
               | lista_expressao ',' expressao
               ;

//##########################
// Nome da função
nome_func: identificador
         ;

//##########################
// Literais (tokens)
literais: LITINT 
        | LITFLOAT 
        | LITFALSE 
        | LITTRUE 
        ;

//##########################
// Token LITINT
LITINT: TK_LIT_INT ;

//##########################
// Token LITFLOAT
LITFLOAT: TK_LIT_FLOAT ;

//##########################
// Token LITFALSE
LITFALSE: TK_LIT_FALSE ;

//##########################
// Token LITTRUE
LITTRUE: TK_LIT_TRUE ;

//##########################
// Tokens de operadores
INVERTSIG: '-' ;
NEGATE: '!' ;
MULTIPLY: '*' ;
DIVIDE: '/' ;
REMAINDER: '%' ;
ADD: '+' ;
SUBTRACT: '-' ;
GREATERTHAN: '>' ;
LESSTHAN: '<' ;
LESSEQUAL: TK_OC_LE ;
GREATEREQUAL: TK_OC_GE ;
EQUAL: TK_OC_EQ ;
NOTEQUAL: TK_OC_NE ;
AND: TK_OC_AND ;

%%

//##########################
// Função de tratamento de erro
int yyerror(char const *s){
    printf("%s on line %d Token UNKNOWN \"%s\" \n", s, get_line_number(), yytext);
    return 1;
}
