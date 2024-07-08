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
#include "sym_stack.h"

// Protótipos das funções necessárias
int yylex(void);
int yyerror(char const *s);
extern int get_line_number(void);
extern char *yytext;
extern void *arvore;
extern void *global_sym_table;
extern void *scope;
%}

%token  TK_PR_INT
%token  TK_PR_FLOAT
%token  TK_PR_BOOL
%token  TK_PR_IF
%token  TK_PR_ELSE
%token  TK_PR_WHILE
%token  TK_PR_RETURN
%token  TK_OC_LE
%token  TK_OC_GE
%token  TK_OC_EQ
%token  TK_OC_NE
%token  TK_OC_AND
%token  TK_OC_OR
%token  TK_ERRO

%token '='
%token '<'
%token '>'
%token '+'
%token '*'
%token '/'
%token '%'
%token '!'
%token '-'

%token <valor_lexico> TK_IDENTIFICADOR
%token <valor_lexico> TK_LIT_INT
%token <valor_lexico> TK_LIT_FLOAT
%token <valor_lexico> TK_LIT_FALSE
%token <valor_lexico> TK_LIT_TRUE

%type <tree> identificador
%type <tree> call_identificador
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
%type <tree> greater_or_less
%type <tree> equal_or_not
%type <tree> adicaousub
%type <tree> op_adicaousub
%type <tree> multoudivoures
%type <tree> op_multoudivoures
%type <tree> unario
%type <tree> primario
%type <tree> chamada_funcao
%type <tree> lista_de_argumentos
%type <tree> nome_func
%type <tree> literais
%type <tree> comparacao_1
%type <tree> comparacao_2
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
		{
			$$ = $1;
			arvore = $$;
			//printf("Created ARVORE node\n"); // Debug print
		}
		| /* vazio */
		{
			$$ = NULL; // Se não houver elementos, o programa é nulo
			arvore = NULL;
			//printf("Empty arvore\n"); // Debug print
		}
        ;

//##########################
// Lista de elementos
lista_de_elementos: elemento lista_de_elementos
				  {
					if ($1 == NULL)
						 {
						 	$$ = $2; // Se o primeiro elemento for nulo, a lista de elementos é a segunda
						 }
					else
					{
						if ($2 == NULL) // Se o segundo elemento for nulo, a lista de elementos é o primeiro
						{
							$$ = $1;
						}
						else
						{
							$$ = $1; // Caso contrário, o elementos é o primeiro elemento
							ast_add_child($$, $2); // Adiciona a lista_de_elementos como filho do primeiro
							//printf("Added elemento to lista_de_elementos\n"); // Debug print
						}
					}	
				  }
                  | elemento
				  {
					$$ = $1;
					//printf("Added elemento to lista_de_elementos\n"); // Debug print
				  }
                  ;

//##########################
// Elemento do programa
elemento: declaracao_global
		{
			$$ = $1;
			//printf("Added declaracao_global to elemento\n"); // Debug print
		}
        | definicao_de_funcao
		{
			$$ = $1;
			//printf("Added definicao_de_funcao to elemento\n"); // Debug print
		}
        ;

//##########################
// Declaração global de variável
declaracao_global: tipo lista_identificador ','
				 {
					$$ = NULL; // Não há ações associadas à declaração global
					//printf("Added tipo and lista_identificador to declaracao_global\n"); // Debug print
				 }
                 ;

//##########################
// Identificador
identificador: TK_IDENTIFICADOR
			 {
				$$ = ast_new($1); // Cria um novo nó na árvore com o identificador
				//printf("Added TK_IDENTIFICADOR to identificador\n"); // Debug print
			 }
             ;
call_identificador: TK_IDENTIFICADOR
			{
				$$ = ast_new_call_func($1); // Cria um novo nó representando uma chamada de função com o identificador
				//printf("Added TK_IDENTIFICADOR to identificador\n"); // Debug print
			}

//##########################
// Tipos de dados
tipo: INT
	{
		$$ = $1;
		//printf("Added INT to tipo\n"); // Debug print
	}
    | FLOAT
	{
		$$ = $1;
		//printf("Added FLOAT to tipo\n"); // Debug print
	}
    | BOOL
	{
		$$ = $1;
		//printf("Added BOOL to tipo\n"); // Debug print
	}
    ;

//##########################
// Token INT
INT: TK_PR_INT
   {
		$$ = NULL; // Espero que seja null mesmo.
		//printf("Empty INT\n"); // Debug print
   }
   ;

//##########################
// Token FLOAT
FLOAT: TK_PR_FLOAT
	 {
		$$ = NULL; // Espero que seja null mesmo.
		//printf("Empty FLOAT\n"); // Debug print
	 }
	 ;

//##########################
// Token BOOL
BOOL: TK_PR_BOOL
	{
		$$ = NULL; // Espero que seja null mesmo.
		//printf("Empty BOOL\n"); // Debug print
	}
	;


//##########################
// Lista de identificadores
lista_identificador: lista_identificador ';' identificador
				   {
					 $$ = $1; // Se houver uma lista de identificadores existente nós as mantemos
					 //printf("Added identificador and lista_identificador to lista_identificador\n"); // Debug print
				   }
                   | identificador
				   {
					 $$ = $1;
					 //printf("Added identificador to lista_identificador\n"); // Debug print
				   }
                   ;

//##########################
// Definição de função
definicao_de_funcao: cabecalho corpo
				   {

						$$ = $1; // Define a definição de função como o cabeçalho
						if ($2 != NULL){
							ast_add_child($$, $2); // Se houver corpo , adiciona o corpo como filho da definição de função
						}
                        free_table_of_symbols(pop_scope(scope));
						//printf("Added cabecalho and corpo to definicao_de_funcao\n"); // Debug print
				   }
                   ;

//##########################
// Cabeçalho da função
cabecalho:   criar_scope '(' lista_de_parametros ')' OR tipo '/' identificador
		 {
			$$ = $8; // Define o cabeçalho como o identificador

            const char* new_key = strdup($8->valor_lexico->token_value);

            if(find_symbol(scope, new_key) != NULL)
            {
                printf("[ERR_DECLARED] Funcao [%s] na linha %d ja foi declarada neste scope\n", new_key, get_line_number());
                exit(ERR_DECLARED);
            }

            insert_symbol(scope, new_key, create_symbol($8,TOKEN_NATURE_FUNCTION));

			//printf("Added lista_de_parametros, tipo and identificador to cabecalho\n"); // Debug print
		 }
         ;

//##########################
// Criar novo scope
criar_scope: 
           {
                push_scope(scope);
           }
//##########################
// Token OR
OR: TK_OC_OR
  {
  	$$ = ast_new_label_only("|");
	//printf("Label OR\n"); // Debug print
  }
  ;

//##########################
// Lista de parâmetros
lista_de_parametros: lista_de_parametros ';' parametro
					{
						if ($1 = NULL){ // Se não houver parâmetros existentes
							$$ = $3; // O resultado é o parâmetro atual
						}
						else 
						{
							if ($3 == NULL) // Se não houver mais parâmetros
							{
								$$ = $1; // O resultado é a lista de parâmetros existentes
							}
							else 
							{
								 $$ = $1; // O resultado é a lista de parâmetros existentes
							}
						}
						//printf("Added parametro to lista_de_parametros\n"); // Debug print
					}
                   | parametro
				   {
						$$ = $1;
						//printf("Added parametro to lista_de_parametros\n"); // Debug print
				   }
                   | /* vazio */ // Se não houver parâmetros
				   {
						$$ = NULL;
						//printf("lista_de_parametros is empty\n"); // Debug print
				   }
                   ;

//##########################
// Parâmetro da função
parametro: tipo identificador // Define o parâmetro como um tipo e um identificador
         {
			$$ = $1;
			ast_add_child($$, $2);
			//printf("Added tipo and identificador to parametro\n"); // Debug print
		 }
         ;

// Corpo da função
corpo: '{' bloco_de_comandos '}' // Define o corpo como um bloco de comandos dentro de chaves
	 {
		$$ = $2;
		//printf("Added bloco_de_comandos to corpo\n"); // Debug print
	 }
	 |  corpo '{' bloco_de_comandos '}'
	 {
		$$ = $1;
		ast_add_child($$, $3);
		//printf("Added bloco_de_comandos to corpo\n"); // Debug print
	 }
     ;
	 
//##########################
// Bloco de Comandos que aceita vazio
bloco_de_comandos: /* vazio */ // Se o bloco de comandos estiver vazio
				 {
					$$ = NULL;
					//printf("Empty bloco_de_comandos\n"); // Debug print
				 }
                 | lista_de_comandos // Se houver uma lista de comandos
				 {
					$$ = $1;
					//printf("Added lista_de_comandos to bloco_de_comandos\n"); // Debug print
				 }
                 ;

//##########################
// Definição de lista de comandos simples
lista_de_comandos: comando_simples ','  // Se houver apenas um comando simples
				 {
					$$ = $1; // O resultado é o comando simples
					//printf("Added comando_simples to lista_de_comandos\n"); // Debug print
				 }
                 | comando_simples ',' lista_de_comandos // Se houver mais de um comando simples
				 {
					if ($3 == NULL)  // Se não houver mais comandos na lista
					{
            			$$ = $1; // O resultado é o primeiro comando simples
        		    }
					else
					{
						if ($1 == NULL)  // Se não houver mais comandos na lista
						{
            				$$ = $3;  // O resultado é a lista restante de comandos
        		    	}
						else
				 		{
							$$ = $1; // O resultado é o primeiro comando simples
            				ast_add_child($1, $3); // Adiciona a lista restante de comandos como filho do primeiro comando simples
       			  		}
					} 	
				 }
                 ;

//##########################
// Definição de comando simples
comando_simples: declaracao_variavel
			   {
					$$ = $1;
					//printf("Added declaracao_variavel to comando_simples\n"); // Debug print
			   }
               | comando_atribuicao
			   {
					$$ = $1;
					//printf("Added comando_atribuicao to comando_simples\n"); // Debug print
			   }
               | chamada_funcao
			   {
					$$ = $1;
					//printf("Added comando_funcao to comando_simples\n"); // Debug print
			   }
               | comando_retorno
			   {
					$$ = $1;
					//printf("Added comando_retorno to comando_simples\n"); // Debug print
			   }
               | comando_controle_fluxo
			   {
					$$ = $1;
					//printf("Added comando_controle_fluxo to comando_simples\n"); // Debug print
			   }
	       	   | corpo
			   {
					$$ = $1;
					//printf("Added corpo to comando_simples\n"); // Debug print
			   }
               ;

//##########################
// Declaração de variável
declaracao_variavel: tipo lista_identificador
				   {
						$$ = NULL;
						//printf("Empty declaracao_variavel\n"); // Debug print
				   }
                   ;

//##########################
// Comando de atribuição
comando_atribuicao: identificador '=' expressao 
				  {
					$$ = ast_new_label_only("="); // Cria um novo nó com o rótulo "="
					ast_add_child($$, $1); // Adiciona o identificador como filho do nó
					ast_add_child($$, $3); // Adiciona a expressão como filho do nó
					//printf("Added expressao to comando_atribuicao\n"); // Debug print
				  }
                  ;

//##########################
// Comando de retorno
RETURN: TK_PR_RETURN
	  {
		$$ = ast_new_label_only("return"); // Cria um novo nó com o rótulo "return"
		//printf("Label RETURN\n"); // Debug print
	  }
	  ;
comando_retorno: RETURN expressao
			   {
					$$ = $1;
					ast_add_child($$, $2);
					//printf("Added expressao to comando_retorno\n"); // Debug print
			   }
			   ;

//##########################
// Comando de controle de fluxo
comando_controle_fluxo: condicional
					  {
						$$ = $1;
						//printf("Added condicional to comando_controle_fluxo\n"); // Debug print
					  }
			      	  | loop
					  {
						$$ = $1;
						//printf("Added loop to comando_controle_fluxo\n"); // Debug print
					  } 
					  ;

//##########################
// Comando de if e else
IF: TK_PR_IF
  {
  	$$ = ast_new_label_only("if"); // Cria um novo nó com o rótulo "if"
	//printf("Label IF\n"); // Debug print
  }
  ;
ELSE: TK_PR_ELSE
	{
		$$ = NULL; // Cria um novo nó com o rótulo "else"
		//printf("Label ELSE\n"); // Debug print
	}
	;
condicional: IF '(' expressao ')' corpo
		   {
				$$ = $1; // Define a condicional como o nó "if"
				ast_add_child($$, $3); // Adiciona a expressão como filho do nó "if"
				ast_add_child($$, $5); // Adiciona o corpo como filho do nó "if"
				//printf("Added expressao and corpo to condicional\n"); // Debug print
		   }
           | IF '(' expressao ')' corpo ELSE corpo 
		   {
				$$ = $1;
				ast_add_child($$, $3); // Adiciona a expressão como filho do nó "if"
				ast_add_child($$, $5); // Adiciona o corpo do "if" como filho do nó "if"
				ast_add_child($$, $7); // Adiciona o nó "else" como filho do nó "if"
				//printf("Added expressao, corpo, and corpo to condicional\n"); // Debug print
		   }
		   ;

//##########################
// Comando de loop
WHILE: TK_PR_WHILE 
	 {
		$$ = ast_new_label_only("while"); // Cria um novo nó com o rótulo "while"
		//printf("Label WHILE\n"); // Debug print
	 }
	 ;
loop: WHILE '(' expressao ')' corpo
	{
		$$ = $1;
		ast_add_child($$, $3); // Adiciona a expressão como filho do nó "while"
		ast_add_child($$, $5); // Adiciona o corpo como filho do nó "while"
		//printf("Added expressao and corpo to loop\n"); // Debug print
	}
	;

//##########################
// Definição expressões, compostas de operando e operador

//Esta parte do código implementa a parta da 
//linguagem de expressões aritméticas e lógicas.
//Seguindo as especificações da etapa2
//com as precedências aninhadas para 
//criar uma estrutura hierárquica que 
//reflete a hierarquia de operadores na linguagem de expressões.

expressao: operando
		 {
			$$ = $1;
			//printf("Added operando to expressao\n"); // Debug print
		 }
		 ;

operando: operador
		{
			$$ = $1;
			//printf("Added operador to operando\n"); // Debug print
		}
        | operando OR operador
		{
			$$ = $2;
			ast_add_child($$, $1);
			ast_add_child($$, $3);
			//printf("Added operando and operador to operando\n"); // Debug print
		}
        ;

//##########################
// Definição de termos
operador: comparacao_1
		{
			$$ = $1;
			//printf("Added comparacao to operador\n"); // Debug print
		}
        | operador AND comparacao_1
		{
			$$ = $2;
			ast_add_child($$, $1);
			ast_add_child($$, $3);
			//printf("Added operador and comparacao to operador\n"); // Debug print
		}
        ;

//##########################
// Comparações NOTEQUAL e EQUAL
comparacao_1: comparacao_2
		  {
				$$ = $1;
				//printf("Added comparacao_1 to comparacao_2\n"); // Debug print
		  }
          |   comparacao_1 equal_or_not comparacao_2
		  {
				$$ = $2;
				ast_add_child($$, $1);
				ast_add_child($$, $3);
				//printf("Added comparacao_1, equal_or_not, and comparacao_2 to comparacao_1\n"); // Debug print
		  }
          ;
equal_or_not:  EQUAL
			 {
				$$ = $1;
				//printf("Added EQUAL to op_adicaousub\n"); // Debug print
			 }
             | NOTEQUAL
			 {
				$$ = $1;
				//printf("Added NOTEQUAL to op_adicaousub\n"); // Debug print
			 }
             ;

//##########################
// Comparações de GREATEREQUAL,LESSEQUAL,GREATERTHAN,LESSTHAN
comparacao_2: adicaousub
		  {
				$$ = $1;
				//printf("Added adicaousub to comparacao_2\n"); // Debug print
		  }
          |   comparacao_2 greater_or_less adicaousub

		  {
				$$ = $2;
				ast_add_child($$, $1);
				ast_add_child($$, $3);
				//printf("Added comparacao_2, greater_or_less, and adicaousub to comparacao_2\n"); // Debug print
		  }
          ;
greater_or_less:  GREATEREQUAL
			 {
				$$ = $1;
				//printf("Added EQUAL to op_adicaousub\n"); // Debug print
			 }
             | 	  LESSEQUAL
			 {
				$$ = $1;
				//printf("Added NOTEQUAL to op_adicaousub\n"); // Debug print
			 }
			 | 	  GREATERTHAN
			 {
				$$ = $1;
				//printf("Added NOTEQUAL to op_adicaousub\n"); // Debug print
			 }
			 | 	  LESSTHAN
			 {
				$$ = $1;
				//printf("Added NOTEQUAL to op_adicaousub\n"); // Debug print
			 }
             ;

//##########################
// Adição ou subtração
adicaousub: multoudivoures
		  {
				$$ = $1;
				//printf("Added multoudivoures to adicaousub\n"); // Debug print
		  }
          | adicaousub op_adicaousub multoudivoures
		  {
					$$ = $2;
					ast_add_child($$, $1);
					ast_add_child($$, $3);
					//printf("Added adicaousub, op_adicaousub, and multoudivoures to adicaousub\n"); // Debug print
		  }
          ;

//##########################
// Operação de adição e subtração
op_adicaousub: ADD
			 {
				$$ = $1;
				//printf("Added ADD to op_adicaousub\n"); // Debug print
			 }
             | SUBTRACT
			 {
				$$ = $1;
				//printf("Added SUBTRACT to op_adicaousub\n"); // Debug print
			 }
             ;

//##########################
// Multiplicação, divisão ou resto
multoudivoures: unario
			  {
					$$ = $1;
					//printf("Added unario to multoudivoures\n"); // Debug print
			  }
              | multoudivoures op_multoudivoures unario
			  {
					$$ = $2;
					ast_add_child($$, $1);
					ast_add_child($$, $3);
					//printf("Added multoudivoures, op_multoudivoures, and unario to multoudivoures\n"); // Debug print
			  }
              ;

//##########################
// Operação de multiplicação,divisão ou resto
op_multoudivoures: MULTIPLY
				 {
					$$ = $1;
					//printf("Added MULTIPLY to op_multoudivoures\n"); // Debug print
				 }
                 | DIVIDE
				 {
					$$ = $1;
					//printf("Added DIVIDE to op_multoudivoures\n"); // Debug print
				 }
                 | REMAINDER
				 {
					$$ = $1;
					//printf("Added REMAINDER to op_multoudivoures\n"); // Debug print
				 }
                 ;

//##########################
// Operações unárias
unario: primario
	  {
			$$ = $1;
			//printf("Added primario to unario\n"); // Debug print
	  }
      | INVERTSIG unario
	  {
			$$ = $1;
		    ast_add_child($$, $2);
		    //printf("Added INVERTSIG and unario to unario\n"); // Debug print
	  }
      | NEGATE unario
	  {
			$$ = $1;
		    ast_add_child($$, $2);
		    //printf("Added NEGATE and unario to unario\n"); // Debug print
	  }
      ;

//##########################
// Expressões primarias
primario: identificador
		{
			$$ = $1;
			//printf("Added identificador to primario\n");
		}
        | literais
		{
			$$ = $1;
			//printf("Added literais to primario\n"); // Debug print
		}
        | chamada_funcao
		{
			$$ = $1;
			//printf("Added chamada_funcao to primario\n"); // Debug print
		}
        | '(' expressao ')'
		{
			$$ = $2;
			//printf("Added expressao to primario\n"); // Debug print
		}
        ;

//##########################
// Chamada de função
chamada_funcao: nome_func '(' lista_de_argumentos ')'
			  {
				$$ = $1;
				ast_add_child($$, $3);
				//printf("Added nome_func and lista_de_argumentos to chamada_funcao\n"); // Debug print
			  }
			  | nome_func '('/*vazio*/')'
			  {
				$$ = $1;
				//printf("Added nome_func to chamada_funcao\n"); // Debug print
			  }
              ;

//##########################
// Lista de expressões
lista_de_argumentos: expressao
			   {
				$$ = $1;
				//printf("Added expressao to lista_de_argumentos\n"); // Debug print
			   }
               |  expressao ';'  lista_de_argumentos
			   {
				if ($3 == NULL)
				{
					$$ = $1; 
				}
				else
				{
					if ($1 == NULL)
					{
						$$ = $3;
					}
					else
					{
						$$ = $1;
						ast_add_child($1, $3);
					}
				}
				//printf("Added lista_de_argumentos and expressao to lista_de_argumentos\n"); // Debug print
			   }
               ;

//##########################
// Nome da função
nome_func: call_identificador
		 {
			$$ = $1;
			//printf("Added identificador to nome_func\n"); // Debug print
		 }
         ;

//##########################
// Literais (tokens)
literais: LITINT
		{
			$$ = $1;
			//printf("Added LITINT to literais\n"); // Debug print
		}
        | LITFLOAT
		{
			$$ = $1;
			//printf("Added LITFLOAT to literais\n"); // Debug print
		} 
        | LITFALSE
		{
			$$ = $1;
			//printf("Added LITFALSE to literais\n"); // Debug print
		} 
        | LITTRUE
		{
			$$ = $1;
			//printf("Added LITTRUE to literais\n"); // Debug print
		} 
        ;

//##########################
// Token LITINT
LITINT: TK_LIT_INT
	  {
			$$ = ast_new($1);
			//printf("Added TK_LIT_INT to LITINT\n"); // Debug print
	  }
	  ;

//##########################
// Token LITFLOAT
LITFLOAT: TK_LIT_FLOAT
		{
			$$ = ast_new($1);
			//printf("Added TK_LIT_FLOAT to LITFLOAT\n"); // Debug print
		}
		;

//##########################
// Token LITFALSE
LITFALSE: TK_LIT_FALSE
		{
			$$ = ast_new($1);
			//printf("Added TK_LIT_FALSE to LITFALSE\n"); // Debug print
		}
		;

//##########################
// Token LITTRUE
LITTRUE: TK_LIT_TRUE
	   {
			$$ = ast_new($1);
			//printf("Added TK_LIT_TRUE to LITTRUE\n"); // Debug print
	   }
	   ;

//##########################
// Tokens de operadores
INVERTSIG: '-'
		 {
				$$ = ast_new_label_only("-");
				//printf("Label INVERTSIG\n"); // Debug print
		 }
	     ;
NEGATE: '!'
	  {
			$$ = ast_new_label_only("!");
			//printf("Label NEGATE\n"); // Debug print
	  }
	  ;
MULTIPLY: '*'
		{
			$$ = ast_new_label_only("*");
			//printf("Label MULTIPLY\n"); // Debug print
		}
	    ;
DIVIDE: '/'
	  {
			$$ = ast_new_label_only("/");
			//printf("Label DIVIDE\n"); // Debug print
	  }
	  ;
REMAINDER: '%'
		 {
				$$ = ast_new_label_only("%");
				//printf("Label REMAINDER\n"); // Debug print
		 }
		 ;
ADD: '+'
   {
		$$ = ast_new_label_only("+");
		//printf("Label ADD\n"); // Debug print
   }
   ;
SUBTRACT: '-'
		{
			$$ = ast_new_label_only("-");
			//printf("Label SUBTRACT\n"); // Debug print
		}
		;
GREATERTHAN: '>'
		   {
				$$ = ast_new_label_only(">");
				//printf("Label GREATERTHAN\n"); // Debug print
		   }
		   ;
LESSTHAN: '<'
		{
			$$ = ast_new_label_only("<");
			//printf("Label LESSTHAN\n"); // Debug print
		}
		;
LESSEQUAL: TK_OC_LE 
		 {
		 	$$ = ast_new_label_only("<=");
			//printf("Label 'LESSEQUAL'\n"); // Debug print
		 }
		 ;
GREATEREQUAL: TK_OC_GE 
			{
				$$ = ast_new_label_only(">=");
				//printf("Label 'GREATEREQUAL'\n"); // Debug print
			}
			;
EQUAL: TK_OC_EQ 
	 {
		$$ = ast_new_label_only("==");
		//printf("Label 'EQUAL'\n"); // Debug print
	 }
	 ;
NOTEQUAL: TK_OC_NE 
		{
			$$ = ast_new_label_only("!=");
			//printf("Label 'NOTEQUAL'\n"); // Debug print
		}
		;
AND: TK_OC_AND 
   {
		$$ = ast_new_label_only("&");
		//printf("Label 'AND'\n"); // Debug print
   }
   ;
%%

//##########################
// Função de tratamento de erro
int yyerror(char const *s){
    printf("%s on line %d \n", s, get_line_number());
    return 1;
}