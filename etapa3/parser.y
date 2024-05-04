    /* Arquivo feito por Thales Perez 00303035 e Vitor Vargas 00302162 */
%define parse.error verbose

%code requires { #include "tree.h" }

%union {
  val_lex_t *valor_lexico;
  tree_node_t *tree;
}

%{
#include <stdlib.h>
#include <stdio.h>

// Protótipos das funções necessárias
int yylex(void);
int yyerror(char const *s);
extern int get_line_number(void);
extern char *yytext;
extern void *arvore;
%}

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
%token TK_ERRO

%token <valor_lexico> TK_IDENTIFICADOR
%token <valor_lexico> TK_LIT_INT
%token <valor_lexico> TK_LIT_FLOAT
%token <valor_lexico> TK_LIT_FALSE
%token <valor_lexico> TK_LIT_TRUE

%type <tree> identificador
%type <tree> LITINT
%type <tree> LITFLOAT
%type <tree> LITTRUE
%type <tree> LITFALSE

%type <tree> programa
%type <tree> lista_de_elementos
%type <tree> elemento
%type <tree> declaracao_global
%type <tree> definicao_de_funcao
%type <tree> lista_identificador
%type <tree> tipo
%type <tree> cabecalho
%type <tree> lista_de_parametros
%type <tree> parametro
%type <tree> corpo
%type <tree> bloco_de_comandos
%type <tree> lista_de_comandos
%type <tree> comando_simples
%type <tree> declaracao_variavel
%type <tree> comando_atribuicao
%type <tree> comando_retorno
%type <tree> comando_controle_fluxo
%type <tree> condicional
%type <tree> loop
%type <tree> expressao
%type <tree> operando
%type <tree> operador
%type <tree> comparacao
%type <tree> adicaousub
%type <tree> op_adicaousub
%type <tree> multoudivoures
%type <tree> op_multoudivoures
%type <tree> unario
%type <tree> primario
%type <tree> chamada_funcao
%type <tree> lista_expressao
%type <tree> nome_func
%type <tree> literais
%type <tree> op_comparacao
%type <tree> INVERTSIG
%type <tree> NEGATE
%type <tree> MULTIPLY
%type <tree> DIVIDE
%type <tree> REMAINDER
%type <tree> ADD
%type <tree> SUBTRACT
%type <tree> GREATERTHAN
%type <tree> LESSTHAN
%type <tree> LESSEQUAL
%type <tree> GREATEREQUAL
%type <tree> EQUAL
%type <tree> NOTEQUAL
%type <tree> AND
%type <tree> OR
%type <tree> INT
%type <tree> FLOAT
%type <tree> BOOL
%type <tree> RETURN
%type <tree> IF
%type <tree> WHILE
%type <tree> ELSE

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
		{
			ast_add_child($$, $1);
		}
        | LITFLOAT
		{
			ast_add_child($$, $1);
		} 
        | LITFALSE
		{
			ast_add_child($$, $1);
		} 
        | LITTRUE
		{
			ast_add_child($$, $1);
		} 
        ;

//##########################
// Token LITINT
LITINT: TK_LIT_INT
	  {
			$$ = ast_new(NULL);
			$$->valor_lexico = $1;
	  }
	  ;

//##########################
// Token LITFLOAT
LITFLOAT: TK_LIT_FLOAT
		{
			$$ = ast_new(NULL);
			$$->valor_lexico = $1;
		}
		;

//##########################
// Token LITFALSE
LITFALSE: TK_LIT_FALSE
		{
			$$ = ast_new(NULL);
			$$->valor_lexico = $1;
		}
		;

//##########################
// Token LITTRUE
LITTRUE: TK_LIT_TRUE
	   {
			$$ = ast_new(NULL);
			$$->valor_lexico = $1;
	   }
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
