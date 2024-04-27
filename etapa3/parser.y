    /* Arquivo feito por Thales Perez 00303035 e Vitor Vargas 00302162 */

%define parse.error verbose

%{

#include <stdlib.h>
#include <stdio.h>
#include "tree.h"

// Protótipos das funções necessárias
int yylex(void);
int yyerror(char const *s);
extern int get_line_number(void);
extern char *yytext;
extern void *tree;

%}

%union {
  val_lex_t valor_lexico;
  ast_tree_t *tree;
}

ast_tree_t *ast_root = NULL;

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
%token <valor_lexico> TK_IDENTIFICADOR
%token <valor_lexico> TK_LIT_INT
%token <valor_lexico> TK_LIT_FLOAT
%token <valor_lexico> TK_LIT_FALSE
%token <valor_lexico> TK_LIT_TRUE
%token TK_ERRO

programa: %type <tree> programa
lista_de_elementos: %type <tree> lista_de_elementos
elemento: %type <tree> elemento
definicao_de_funcao: %type <tree> definicao_de_funcao
cabecalho: %type <tree> cabecalho
lista_de_parametros: %type <tree> lista_de_parametros
parametro: %type <tree> parametro
corpo: %type <tree> corpo
bloco_de_comandos: %type <tree> bloco_de_comandos
lista_de_comandos: %type <tree> lista_de_comandos
comando_simples: %type <tree> comando_simples
declaracao_variavel: %type <tree> declaracao_variavel
comando_atribuicao: %type <tree> comando_atribuicao
chamada_funcao: %type <tree> chamada_funcao
comando_retorno: %type <tree> comando_retorno
condicional: %type <tree> condicional
loop: %type <tree> loop
expressao: %type <tree> expressao
operador: %type <tree> operador
unario: %type <tree> unario
operando: %type <tree> operando
primario: %type <tree> primario
lista_expressao: %type <tree> lista_expressao
nome_func: %type <tree> nome_func
literais: %type <tree> literais

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
INT: TK_PR_INT 
   ;

//##########################
// Token FLOAT
FLOAT: TK_PR_FLOAT 
	 ;

//##########################
// Token BOOL
BOOL: TK_PR_BOOL 
	;

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
OR: TK_OC_OR 
  ;

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

// Corpo da função
corpo: '{' bloco_de_comandos '}'
	 |  corpo '{' bloco_de_comandos '}'
     ;
	 
//##########################
// Bloco de Comandos que aceita vazio
bloco_de_comandos: /* vazio */
                 | lista_de_comandos
                 ;

//##########################
// Definição de lista de comandos simples
lista_de_comandos: comando_simples ','
                 | lista_de_comandos comando_simples ','
                 ;

//##########################
// Definição de comando simples
comando_simples: declaracao_variavel
               | comando_atribuicao
               | chamada_funcao
               | comando_retorno
               | comando_controle_fluxo
	       | corpo
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
RETURN: TK_PR_RETURN
	  ;
comando_retorno: RETURN expressao
			   ;

//##########################
// Comando de controle de fluxo
comando_controle_fluxo: condicional 
			      	  | loop 
					  ;

//##########################
// Comando de if e else
IF: TK_PR_IF 
  ;
ELSE: TK_PR_ELSE 
	;
condicional: IF '(' expressao ')' corpo
           | IF '(' expressao ')' corpo ELSE corpo 
		   ;

//##########################
// Comando de loop
WHILE: TK_PR_WHILE 
	 ;
loop: WHILE '(' expressao ')' corpo
	;

//##########################
// Definição expressões, compostas de operando e operador

expressao: operando 
		 ;

operando: operador
         | operando OR operador
         ;

//##########################
// Definição de termos
operador: comparacao
        | operador AND comparacao
        ;

//##########################
// Comparações
comparacao: adicaousub
          | comparacao op_comparacao adicaousub
          ;

//##########################
// Operadores de comparação
op_comparacao: LESSTHAN
             | GREATERTHAN
             | LESSEQUAL
             | GREATEREQUAL
             | EQUAL
             | NOTEQUAL
             ;

//##########################
// Adição ou subtração
adicaousub: multoudivoures
          | adicaousub op_adicaousub multoudivoures
          ;

//##########################
// Operação de adição e subtração
op_adicaousub: ADD
             | SUBTRACT
             ;

//##########################
// Multiplicação, divisão ou resto
multoudivoures: unario
              | multoudivoures op_multoudivoures unario
              ;

//##########################
// Operação de multiplicação,divisão ou resto
op_multoudivoures: MULTIPLY
                 | DIVIDE
                 | REMAINDER
                 ;

//##########################
// Operações unárias
unario: primario
      | INVERTSIG unario
      | NEGATE unario
      ;

//##########################
// Expressões primarias
primario: identificador
        | literais
        | chamada_funcao
        | '(' expressao ')'
        ;

//##########################
// Chamada de função
chamada_funcao: nome_func '(' lista_expressao ')'
			  | nome_func '('/*vazio*/')'
              ;

//##########################
// Lista de expressões
lista_expressao: expressao
               | lista_expressao ';' expressao
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
LITINT: TK_LIT_INT 
	  ;

//##########################
// Token LITFLOAT
LITFLOAT: TK_LIT_FLOAT 
		;

//##########################
// Token LITFALSE
LITFALSE: TK_LIT_FALSE 
		;

//##########################
// Token LITTRUE
LITTRUE: TK_LIT_TRUE 
	   ;

//##########################
// Tokens de operadores
INVERTSIG: '-' 
	     ;
NEGATE: '!' 
	  ;
MULTIPLY: '*' 
	    ;
DIVIDE: '/' 
	  ;
REMAINDER: '%' 
		 ;
ADD: '+' 
   ;
SUBTRACT: '-' 
		;
GREATERTHAN: '>' 
		   ;
LESSTHAN: '<' 
		;
LESSEQUAL: TK_OC_LE 
		 ;
GREATEREQUAL: TK_OC_GE 
			;
EQUAL: TK_OC_EQ 
	 ;
NOTEQUAL: TK_OC_NE 
		;
AND: TK_OC_AND 
   ;

%%

//##########################
// Função de tratamento de erro
int yyerror(char const *s){
    printf("%s on line %d \n", s, get_line_number());
    return 1;
}
