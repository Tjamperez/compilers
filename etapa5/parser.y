    /* Arquivo feito por Thales Perez 00303035 e Vitor Vargas 00302162 */

    /* Bozhe, spasi menya, potomu chto nikto drugoy ne mozhet. */

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
#include "sym_table.h"
#include "tree.h"
#include "gen_code.h"


//Tamanho do Buffer para Operações

#define OPCODE_SIZE_OF_BUFFER 64


// Protótipos das funções necessárias
int yylex(void);
int yyerror(char const *s);
extern int get_line_number(void);

int symbol_type_now; // Mantemos conta de quem é o tipo do símbolo no momento

extern char *yytext;
extern void *arvore;
stack_of_tables_t *stack_of_tables;
char* current_function_label;
int args_counter = 0;
int initial_space = 0;
int final_space = 0;
int current_opcode = 0;
char* main_label;

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

%type <tree> identificador_func
%type <tree> identificador
%type <tree> call_identificador
%type <tree> LITINT
%type <tree> LITFLOAT
%type <tree> LITTRUE
%type <tree> LITFALSE


%type <tree> criar_pilha
%type <tree> fechar_pilha
%type <tree> criar_escopo
%type <tree> criar_escopo_global
%type <tree> fechar_escopo

%type <tree> raiz
%type <tree> programa
%type <tree> lista_de_elementos
%type <tree> elemento
%type <tree> declaracao_global
%type <tree> definicao_de_funcao
%type <tree> lista_identificador
%type <tree> lista_identificador_local
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
raiz: criar_pilha criar_escopo_global programa fechar_escopo fechar_pilha
{
    //fprintf(stderr, "Debug message raiz: criar_pilha criar_escopo_global programa fechar_escopo fechar_pilha\n");
    $$ = $3;
    if ($3 != NULL) {
        //fprintf(stderr, "Before appending programa: $$->code=%p, $3->code=%p\n\n", $$->code, $3->code);
        $$->code = append_node_operations($$, $3);
        $$->code = gen_wrapper_code($$->code , main_label);
        $$->code = fill_holes($$->code);
        //fprintf(stderr, "After appending programa: $$->code=%p\n\n", $$->code);
    }
    print_all_operations($3->code);
    arvore = $$;
}
;

//##########################
// Definição de programa
programa: lista_de_elementos
{
    //fprintf(stderr, "Debug message programa: lista_de_elementos\n");
    $$ = $1;
    if ($1 != NULL) {
        //fprintf(stderr, "Before appending lista_de_elementos: $$->code=%p, $1->code=%p\n\n", $$->code, $1->code);
        $$->code = append_operations($$->code, $1->code);
        //fprintf(stderr, "After appending lista_de_elementos: $$->code=%p\n\n", $$->code);
    }
}
| /* vazio */
{
    $$ = NULL; // Se não houver elementos, o programa é nulo
    arvore = NULL;
    //fprintf(stderr, "Empty arvore\n"); // Debug print
}
;

//##########################
// Lista de elementos
lista_de_elementos: elemento lista_de_elementos
{
    //fprintf(stderr, "Debug message lista_de_elementos: elemento lista_de_elementos\n");
    if ($1 == NULL) {
        $$ = $2; // Se o primeiro elemento for nulo, a lista de elementos é a segunda
    } else {
        if ($2 == NULL) {
            $$ = $1; // Se o segundo elemento for nulo, a lista de elementos é o primeiro
        } else {
            $$ = $1; // Caso contrário, o elementos é o primeiro elemento
            ast_add_child($$, $2); // Adiciona a lista_de_elementos como filho do primeiro
        }
    }
    if ($$ != NULL) {
        //fprintf(stderr, "Before appending ele lista_ele: $$->code=%p, $1->code=%p, $2->code=%p\n\n", $$->code, $1 != NULL ? $1->code : NULL, $2 != NULL ? $2->code : NULL);
        if ($1 != NULL) $$->code = append_operations($$->code, $1->code);
        if ($2 != NULL) $$->code = append_operations($$->code, $2->code);
        //fprintf(stderr, "After appending ele lista_ele: $$->code=%p\n\n", $$->code);
    }
}
| elemento
{
    //fprintf(stderr, "Debug message lista_de_elementos: elemento\n");
    $$ = $1;
    if ($$ != NULL) {
        //fprintf(stderr, "Before appending elemento: $$->code=%p, $1->code=%p\n\n", $$->code, $1->code);
        if ($$->code != $1->code) {
            $$->code = append_operations($$->code, $1->code);
        } else {
            //fprintf(stderr, "Skipped appending to avoid circular reference.\n\n");
        }
        //fprintf(stderr, "After appending elemento: $$->code=%p\n\n", $$->code);
    }
}
;

//##########################
// Elemento do programa
elemento: declaracao_global
{
    //fprintf(stderr, "Debug message elemento: declaracao_global\n");
    $$ = $1;
    if ($$ != NULL) {
        //fprintf(stderr, "Before appending dec_global: $$->code=%p, $1->code=%p\n\n", $$->code, $1->code);
        if ($$->code != $1->code) {
            $$->code = append_operations($$->code, $1->code);
        } else {
            //fprintf(stderr, "Skipped appending to avoid circular reference.\n\n");
        }
        //fprintf(stderr, "After appending dec_global: $$->code=%p\n\n", $$->code);
    }
}
| definicao_de_funcao
{
    //fprintf(stderr, "Debug message elemento: definicao_de_funcao\n");
    $$ = $1;
    if ($$ != NULL) {
        //fprintf(stderr, "Before appending def_func: $$->code=%p, $1->code=%p\n\n", $$->code, $1->code);
        if ($$->code != $1->code) {
            $$->code = append_operations($$->code, $1->code);
        } else {
            //fprintf(stderr, "Skipped appending to avoid circular reference.\n\n");
        }
        //fprintf(stderr, "After appending def_func: $$->code=%p\n\n", $$->code);
    }
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

//##########################
// Identificador para pegar nome da função e inserir na tabela global
identificador_func: TK_IDENTIFICADOR	
                  {
                        $$ = ast_new($1); // Cria um novo nó na árvore com o identificador
				        //printf("Added TK_IDENTIFICADOR to identificador\n"); // Debug print

						char *new_key = strdup($$->valor_lexico->token_value);

						if(find_symbol(stack_of_tables->tables[0], new_key) != NULL)
            			{
                			printf("[ERR_DECLARED] Funcao [%s] na linha %d ja foi declarada neste scope\n", new_key, get_line_number());
                			exit(ERR_DECLARED);
            			}

                        current_function_label = generate_label();

						insert_symbol(stack_of_tables->tables[0], new_key, create_symbol($$,TOKEN_NATURE_FUNCTION, symbol_type_now, strdup(current_function_label)));
                        
                        if (!strcmp(new_key, "main")) {
                            initial_space = 0;
                            final_space = 0;
                        } else {
                            initial_space = 12;
                            final_space = 4;
                        }
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
        symbol_type_now = TYPE_INT;

		//printf("Added INT to tipo\n"); // Debug print
	}
    | FLOAT
	{
		$$ = $1;
        symbol_type_now = TYPE_FLOAT;

		//printf("Added FLOAT to tipo\n"); // Debug print
	}
    | BOOL
	{
		$$ = $1;
        symbol_type_now = TYPE_BOOL;
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
                        char* new_key = strdup($3->valor_lexico->token_value);
                        //printf("In the Hood [%s]\n\n", new_key);
                        if(find_symbol(stack_of_tables->top, new_key) != NULL){
                            printf("[ERR_DECLARED] Var [%s] na linha %d ja foi declarada neste escopo\n", new_key, get_line_number());
                            exit(ERR_DECLARED);
                        }
                        insert_symbol(stack_of_tables->tables[0], new_key, create_symbol($3,TOKEN_NATURE_IDENTIFIER, symbol_type_now, NULL));
				   }
                   | identificador
				   {
					    $$ = $1;
                        char* new_key = strdup($1->valor_lexico->token_value);
                        //printf("In the Hood [%s]\n\n", new_key);
                        if(find_symbol(stack_of_tables->top, new_key) != NULL){
                            printf("[ERR_DECLARED] Var [%s] na linha %d ja foi declarada neste escopo\n", new_key, get_line_number());
                            exit(ERR_DECLARED);
                        }

                        insert_symbol(stack_of_tables->tables[0], new_key, create_symbol($1,TOKEN_NATURE_IDENTIFIER, symbol_type_now, NULL));
					    //printf("Added identificador to lista_identificador\n"); // Debug print
				   }
                   ;

//##########################
// Definição de função
definicao_de_funcao: cabecalho corpo fechar_escopo
				   {
                    //fprintf(stderr, "Debug message definicao_de_funcao: cabecalho corpo fechar_escopo\n");
                        //fprintf(stderr, "Before appending CAB: $$->code=%p, $1->code=%p, $2->code=%p\n\n", $$->code, $1->code, $2->code);
						$$ = $1; // Define a definição de função como o cabeçalho
						if ($2 != NULL){
							ast_add_child($$, $2); // Se houver corpo , adiciona o corpo como filho da definição de função
                            operation_t* generated_code1 = append_operations($1->code, $2->code);
                            //fprintf(stderr, "After appending CAB: $$->code=%p, $1->code=%p, $2->code=%p, generated_code1=%p\n\n", $$->code, $1->code, $2->code, generated_code1);
                            $$->code = generated_code1;
						}
						//printf("Added cabecalho and corpo to definicao_de_funcao\n"); // Debug print
                        else{
                            $$->code = $1->code;
                        }
				   }
                   ;

//##########################
// Cabeçalho da função
cabecalho:   criar_escopo '(' lista_de_parametros ')' OR tipo '/' identificador_func
		 {
            //fprintf(stderr, "Debug message cabecalho:   criar_escopo '(' lista_de_parametros ')' OR tipo '/' identificador_func\n");
			$$ = $8; // Define o cabeçalho como o identificador
			//printf("Added lista_de_parametros, tipo and identificador to cabecalho\n"); // Debug print

            char* identifier_key = strdup($8->valor_lexico->token_value);

            char* function_label = current_function_label;

            operation_t* generated_code1 = initialize_operation(function_label, NOP, NULL, NULL, NULL);

            if (strcmp(identifier_key, "main")) {
                    operation_t* generated_code2 = initialize_operation(NULL, I2I, strdup("rsp"), strdup("rfp"), NULL);
                    //fprintf(stderr, "Before appending identfunc: $$->code=%p, $8->code=%p, generated_code1=%p\n\n", $$->code, $8->code, generated_code1);
                    append_operations(generated_code1, generated_code2);
                    //fprintf(stderr, "After appending identfunc: $$->code=%p, $8->code=%p, generated_code1=%p\n\n", $$->code, $8->code, generated_code1);
            } else {
                    main_label = strdup(function_label);
            }

            char* op2 = (char*) malloc(OPCODE_SIZE_OF_BUFFER);
            sprintf(op2, "%d", initial_space + stack_of_tables->top->current_adress_displacement + final_space);
            operation_t* generated_code3 = initialize_operation(NULL, ADDI, strdup("rsp"), op2, strdup("rsp"));
            //fprintf(stderr, "Before appending identfunc: $$->code=%p, $8->code=%p, generated_code1=%p\n\n", $$->code, $8->code, generated_code1);
            append_operations(generated_code1, generated_code3);
            //fprintf(stderr, "After appending identfunc: $$->code=%p, $8->code=%p, generated_code1=%p\n\n", $$->code, $8->code, generated_code1);

            $$->code = generated_code1;
            //fprintf(stderr, "After generating cabecalho: $$->code=%p, $8->code=%p, generated_code1=%p\n\n", $$->code, $8->code, generated_code1);
		 }
         ;

//##########################
// Criar novo scope
criar_escopo_global: 
           {
                $$ = NULL;
                table_of_symbols_t *new_scope = create_table_of_symbols_global(stack_of_tables->top,true);
                push_scope(stack_of_tables,new_scope);
           }
           ;

criar_escopo: 
           {
                $$ = NULL;
                table_of_symbols_t *new_scope = create_table_of_symbols(stack_of_tables->top,false);
                push_scope(stack_of_tables,new_scope);
           }
           ;

//##########################
// Fechar Escopo
fechar_escopo: 
           {
                $$ = NULL;
                pop_scope(stack_of_tables);
           }
           ;		   

//##########################
// Criar primeira pilha
criar_pilha:
           {   
                $$ = NULL;
                stack_of_tables = create_stack_of_tables();
           }
           ;

//##########################
// Fechar primeira pilha
fechar_pilha:
           {   
                $$ = NULL;
                free_stack_of_tables(stack_of_tables);
           }
           ;

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
            char *new_key = strdup($2->valor_lexico->token_value);
            if(find_symbol(stack_of_tables->top, new_key) != NULL)
            {
               printf("[ERR_DECLARED] Funcao [%s] na linha %d ja foi declarada neste scope\n", new_key, get_line_number());
               exit(ERR_DECLARED);
            }
            insert_symbol(stack_of_tables->top, new_key, create_symbol($2,TOKEN_NATURE_IDENTIFIER, symbol_type_now, NULL));
            int nature = stack_of_tables->top->items[0]->content->nature;
			//printf("Added tipo and identificador to parametro\n"); // Debug print
		 }
         ;

// Corpo da função
corpo: '{' bloco_de_comandos '}' // Define o corpo como um bloco de comandos dentro de chaves
	 {
		$$ = $2;
		//printf("Added bloco_de_comandos to corpo\n"); // Debug print
	 }
	 | corpo'{' bloco_de_comandos '}'
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
                    //fprintf(stderr, "Debug message lista_de_comandos: comando_simples ','\n");
					$$ = $1; // O resultado é o comando simples
					//printf("Added comando_simples to lista_de_comandos\n"); // Debug print
				 }
                 | comando_simples ',' lista_de_comandos // Se houver mais de um comando simples
				 {
                    //fprintf(stderr, "Debug message lista_de_comandos: comando_simples ',' lista_de_comandos\n");
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
                            //fprintf(stderr, "Else Debug message lista_de_comandos: comando_simples ',' lista_de_comandos\n");
                            $$->code = append_operations($1->code, $3->code);
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
                    //fprintf(stderr, "Before appending comando: $$->code=%p, $1->code=%p\n\n", $$->code, $1->code);
					//printf("Added comando_atribuicao to comando_simples\n"); // Debug print
                    //fprintf(stderr, "After appending comando: $$->code=%p, $1->code=%p\n\n", $$->code, $1->code);
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
	       	   | criar_escopo corpo fechar_escopo
			   {
					$$ = $2;
					//printf("Added corpo to comando_simples\n"); // Debug print
			   }
               ;

//##########################
// Declaração de variável
declaracao_variavel: tipo lista_identificador_local
				   {
						$$ = NULL;
						//printf("Empty declaracao_variavel\n"); // Debug print
				   }
                   ;

lista_identificador_local: lista_identificador_local ';' identificador
				   {
					    $$ = $1; // Se houver uma lista de identificadores existente nós as mantemos
					    //printf("Added identificador and lista_identificador to lista_identificador\n"); // Debug print
                        char* new_key = strdup($3->valor_lexico->token_value);
                        //printf("In the Hood Local List[%s]\n\n", new_key);
                        if(find_symbol(stack_of_tables->top, new_key) != NULL){
                            printf("[ERR_DECLARED] Var [%s] na linha %d ja foi declarada neste escopo\n", new_key, get_line_number());
                            exit(ERR_DECLARED);
                         }
                        insert_symbol(stack_of_tables->top, new_key, create_symbol($3,TOKEN_NATURE_IDENTIFIER, symbol_type_now, NULL));
				   }
                   | identificador
				   {
					    $$ = $1;
                        char* new_key = strdup($1->valor_lexico->token_value);
                      
                        if(find_symbol(stack_of_tables->top, new_key) != NULL){
                            printf("[ERR_DECLARED] Var [%s] na linha %d ja foi declarada neste escopo\n", new_key, get_line_number());
                            exit(ERR_DECLARED);
                        }
                        //printf("In the Hood Local Ident[%s]\n\n", new_key);
                        insert_symbol(stack_of_tables->top, new_key, create_symbol($1,TOKEN_NATURE_IDENTIFIER, symbol_type_now, NULL));
					    //printf("Added identificador to lista_identificador\n"); // Debug print
				   }
                   ;

//##########################
// Comando de atribuição
comando_atribuicao: identificador '=' expressao 
				  {
                    //fprintf(stderr, "Debug message comando_atribuicao: identificador '=' expressao\n");
					$$ = ast_new_label_only("="); // Cria um novo nó com o rótulo "="
					ast_add_child($$, $1); // Adiciona o identificador como filho do nó
					ast_add_child($$, $3); // Adiciona a expressão como filho do nó
						
                    char* new_key = $1->valor_lexico->token_value;
							  
					symbol_t* result = search_symbol_stack(stack_of_tables, new_key);				
                    if(result == NULL){
                        printf("[ERR_UNDECLARED] Var [%s] na linha %d nao foi declarada\n", new_key, get_line_number());
                        exit(ERR_UNDECLARED);
                    }
                    else {
                        
                        int nature = result->nature;
                        //printf("Nature: [%d]\n\n", nature);
                        $$->node_type = result->data_type;
                            
                        if(nature == TOKEN_NATURE_FUNCTION){
                            printf("[ERR_VARIABLE] Funcao [%s] na linha %d esta sendo usada como variavel\n", new_key, get_line_number());
                            exit(ERR_FUNCTION);
                        }
                    }
                    $$->node_type = new_type($1,$3); // Adiciona novo tipo resultante             
					//printf("Added expressao to comando_atribuicao\n"); // Debug print
                    table_of_symbols_t *current_scope = search_stack_for_adress(stack_of_tables, new_key);
                    if(result){
                        //fprintf(stderr, "Before appending atribuicao: $$->code=%p, $3->code=%p\n\n", $$->code, $3->code);
                        int adress = result->adress_displacement;
                        char *temp = $3->temp;
                        char* op2;
                        if(current_scope->is_global)
                            op2 = strdup("rbss");
                        else
                            op2 = strdup("rfp");
                        char* op3 = (char*) malloc(sizeof(char) * OPCODE_SIZE_OF_BUFFER);
                        sprintf(op3, "%d", adress);
                        if(temp){
                            operation_t* generated_code = initialize_operation(NULL, STOREAI, strdup(temp), op2, op3);

                            print_operations(generated_code);

                            $$->code = append_operations($3->code, generated_code);
                            //fprintf(stderr, "After appending atribuicao: $$->code=%p, $3->code=%p\n\n", $$->code, $3->code);
                        }
                        else
                            $$->code = $3->code;
                    }
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
                //fprintf(stderr, "Debug message comando_retorno: RETURN expressao\n");
				char* op3 = (char*) malloc(OPCODE_SIZE_OF_BUFFER);
                sprintf(op3, "%d", initial_space + stack_of_tables->top->current_adress_displacement);
                operation_t* generated_code1 = initialize_operation(NULL, STOREAI, strdup($2->temp), strdup("rfp"), op3);
                //fprintf(stderr, "Generated operation 1: %p\n", (void*)generated_code1);

                operation_t* generated_code2 = initialize_operation(NULL, LOADAI, strdup("rfp"), strdup("0"), generate_temp());
                append_operations(generated_code1, generated_code2);
                //fprintf(stderr, "Appended operation 2: %p\n", (void*)generated_code2);

                operation_t* generated_code3 = initialize_operation(NULL, LOADAI, strdup("rfp"), strdup("4"), generate_temp());
                append_operations(generated_code1, generated_code3);
                //fprintf(stderr, "Appended operation 3: %p\n", (void*)generated_code3);

                operation_t* generated_code4 = initialize_operation(NULL, LOADAI, strdup("rfp"), strdup("8"), generate_temp());
                append_operations(generated_code1, generated_code4);
                //fprintf(stderr, "Appended operation 4: %p\n", (void*)generated_code4);

                operation_t* generated_code5 = initialize_operation(NULL, I2I, strdup(generated_code3->op3), strdup("rsp"), NULL);
                append_operations(generated_code1, generated_code5);
                //fprintf(stderr, "Appended operation 5: %p\n", (void*)generated_code5);

                operation_t* generated_code6 = initialize_operation(NULL, I2I, strdup(generated_code4->op3), strdup("rfp"), NULL);
                append_operations(generated_code1, generated_code6);
                //fprintf(stderr, "Appended operation 6: %p\n", (void*)generated_code6);

                //operation_t* generated_code7 = initialize_operation(NULL, JUMP, strdup(generated_code2->op3), NULL, NULL);
                //append_operations(generated_code1, generated_code7);
                //fprintf(stderr, "Appended operation 7: %p\n", (void*)generated_code7);

                $$->code = append_operations($2->code, generated_code1);
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
condicional: IF '(' expressao ')' criar_escopo corpo fechar_escopo
		   {
                //fprintf(stderr, "Debug message condicional: IF '(' expressao ')' criar_escopo corpo fechar_escopo\n");
				$$ = $1; // Define a condicional como o nó "if"
				ast_add_child($$, $3); // Adiciona a expressão como filho do nó "if"
				ast_add_child($$, $5); // Adiciona o corpo como filho do nó "if"
                $$->node_type = $3->node_type;
				//printf("Added expressao and corpo to condicional\n"); // Debug print

                char * true_label = generate_label();
                char * after_label = generate_label();
                
                char * temp = generate_temp();
                char * temp_opaque = generate_temp();

                char* op1 = (char*) malloc(sizeof(char) * OPCODE_SIZE_OF_BUFFER);
                sprintf(op1, "%d", 0);
                operation_t* generated_code1 = initialize_operation(NULL, LOADI, op1, temp, NULL);
                
                operation_t* generated_code2 = initialize_operation(NULL, CMP_NE, strdup($3->temp), strdup(temp), temp_opaque);
                append_operations(generated_code1, generated_code2);
                
                operation_t* generated_code3 = initialize_operation(NULL, CBR, strdup(temp_opaque), true_label, after_label);
                append_operations(generated_code1, generated_code3);
                
                operation_t* generated_code4 = initialize_operation(strdup(true_label), NOP, NULL, NULL, NULL);
                append_operations(generated_code1, generated_code4);
                if ($6 != NULL){
                    append_operations(generated_code1, $6->code);
                }
                operation_t* generated_code5 = initialize_operation(strdup(after_label), NOP, NULL, NULL, NULL);
                append_operations(generated_code1, generated_code5);

                $$->code = append_operations($3->code, generated_code1);

		   }
           | IF '(' expressao ')' criar_escopo corpo fechar_escopo ELSE criar_escopo corpo fechar_escopo
		   {
			//fprintf(stderr, "Debug message IF '(' expressao ')' criar_escopo corpo fechar_escopo ELSE criar_escopo corpo fechar_escopo\n");
            	$$ = $1;
				ast_add_child($$, $3); // Adiciona a expressão como filho do nó "if"
				ast_add_child($$, $5); // Adiciona o corpo do "if" como filho do nó "if"
				ast_add_child($$, $7); // Adiciona o nó "else" como filho do nó "if"
                $$->node_type = $3->node_type;
				//printf("Added expressao, corpo, and corpo to condicional\n"); // Debug print

                char * true_label = generate_label();
                char * false_label = generate_label();
                char * after_label = generate_label();
                
                char * temp = generate_temp();
                char * temp_opaque = generate_temp();

                char* op1 = (char*) malloc(sizeof(char) * OPCODE_SIZE_OF_BUFFER);
                sprintf(op1, "%d", 0);
                operation_t* generated_code1 = initialize_operation(NULL, LOADI, op1, temp, NULL);
                
                operation_t* generated_code2 = initialize_operation(NULL, CMP_NE, strdup($3->temp), strdup(temp), temp_opaque);
                append_operations(generated_code1, generated_code2);
                
                operation_t* generated_code3 = initialize_operation(NULL, CBR, strdup(temp_opaque), true_label, after_label);
                append_operations(generated_code1, generated_code3);
                
                operation_t* generated_code4 = initialize_operation(strdup(true_label), NOP, NULL, NULL, NULL);
                append_operations(generated_code1, generated_code4);

                if ($6 != NULL)
                    append_operations(generated_code1, $7->code);

                operation_t* generated_code5 = initialize_operation(NULL, JUMPI, after_label, NULL, NULL);
                append_operations(generated_code1, generated_code5);

                operation_t* generated_code6 = initialize_operation(strdup(false_label), NOP, NULL, NULL, NULL);
                append_operations(generated_code1, generated_code6);

                if ($10 != NULL)
                    append_operations(generated_code1, $11->code);

                operation_t* generated_code7 = initialize_operation(strdup(after_label), NOP, NULL, NULL, NULL);
				append_operations(generated_code1, generated_code7);

                $$->code = append_operations($3->code, generated_code1);
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
loop: WHILE '(' expressao ')' criar_escopo corpo fechar_escopo
	{
        //fprintf(stderr, "Debug message WHILE '(' expressao ')' criar_escopo corpo fechar_escopo\n");
		$$ = $1;
		ast_add_child($$, $3); // Adiciona a expressão como filho do nó "while"
		ast_add_child($$, $5); // Adiciona o corpo como filho do nó "while"
        $$->node_type = $3->node_type;
		//printf("Added expressao and corpo to loop\n"); // Debug print

        char* test_label = generate_label();
        char* true_label = generate_label();
        char* after_label = generate_label();
        
        char* temp = generate_temp();
        char* temp_opaque = generate_temp();
        char* op1 = strdup("0");
        operation_t* generated_code1 = initialize_operation(NULL, LOADI, op1, temp, NULL);

        operation_t* generated_code_test = initialize_operation(strdup(test_label), NOP, NULL, NULL, NULL);
        append_operations(generated_code1, generated_code_test);
        
        operation_t* generated_code2 = initialize_operation(NULL, CMP_NE, strdup($3->temp), strdup(temp), temp_opaque);
        append_operations(generated_code1, generated_code2);
        
        operation_t* generated_code3 = initialize_operation(NULL, CBR, strdup(temp_opaque), true_label, after_label);
        append_operations(generated_code1, generated_code3);
        
        operation_t* generated_code4 = initialize_operation(true_label, NOP, NULL, NULL, NULL);
        append_operations(generated_code1, generated_code4);

        if ($6 != NULL)
            append_operations(generated_code1, $6->code);

        operation_t* generated_code5 = initialize_operation(NULL, JUMPI, test_label, NULL, NULL);
        append_operations(generated_code1, generated_code5);

        operation_t* generated_code6 = initialize_operation(strdup(after_label), NOP, NULL, NULL, NULL);
        append_operations(generated_code1, generated_code6);

        $$->code = append_operations($3->code, generated_code1);
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
            //fprintf(stderr, "Debug message operando: operando OR operador\n");
			$$ = $2;
			ast_add_child($$, $1);
			ast_add_child($$, $3);
            $$->node_type = new_type($1,$3);
			//printf("Added operando and operador to operando\n"); // Debug print

            char* temp = generate_temp();
            operation_t* generated_code = initialize_operation(NULL, OR , strdup($1->temp), strdup($3->temp), strdup(temp));
            $$->code = append_operations($1->code, $3->code);
            $$->code = append_operations($$->code, generated_code);
            $$->temp = temp;
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
            //fprintf(stderr, "Debug message operador: operador AND comparacao_1\n");
			$$ = $2;
			ast_add_child($$, $1);
			ast_add_child($$, $3);
            $$->node_type = new_type($1,$3);
			//printf("Added operador and comparacao to operador\n"); // Debug print

            char* temp = generate_temp();
            operation_t* generated_code = initialize_operation(NULL, AND , strdup($1->temp), strdup($3->temp), strdup(temp));
            $$->code = append_operations($1->code, $3->code);
            $$->code = append_operations($$->code, generated_code);
            $$->temp = temp;

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
            //fprintf(stderr, "Debug message comparacao_1: comparacao_1 equal_or_not comparacao_2\n");
				$$ = $2;
				ast_add_child($$, $1);
				ast_add_child($$, $3);
                $$->node_type = new_type($1,$3);
				//printf("Added comparacao_1, equal_or_not, and comparacao_2 to comparacao_1\n"); // Debug print

                char* temp = generate_temp();

                current_opcode = get_opcode_from_string($2->valor_lexico->token_value);

                operation_t* generated_code = initialize_operation(NULL, current_opcode, strdup($1->temp), strdup($3->temp), strdup(temp));
                $$->code = append_operations($1->code, $3->code);
                $$->code = append_operations($$->code, generated_code);
                $$->temp = temp;
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
            //fprintf(stderr, "Debug message comparacao_2: comparacao_2 greater_or_less adicaousub\n");
				$$ = $2;
				ast_add_child($$, $1);
				ast_add_child($$, $3);
                $$->node_type = new_type($1,$3);
				//printf("Added comparacao_2, greater_or_less, and adicaousub to comparacao_2\n"); // Debug print

                char* temp = generate_temp();

                current_opcode = get_opcode_from_string($2->valor_lexico->token_value);

                operation_t* generated_code = initialize_operation(NULL, current_opcode, strdup($1->temp), strdup($3->temp), strdup(temp));
                $$->code = append_operations($1->code, $3->code);
                $$->code = append_operations($$->code, generated_code);
                $$->temp = temp;
		  }
          ;
greater_or_less:  GREATEREQUAL
			 {
				$$ = $1;
				//printf("Added EQUAL to op_adicaousub\n"); // Debug print
			 }
             | 	LESSEQUAL
			 {
				$$ = $1;
				//printf("Added NOTEQUAL to op_adicaousub\n"); // Debug print
			 }
			 |  GREATERTHAN
			 {
				$$ = $1;
				//printf("Added NOTEQUAL to op_adicaousub\n"); // Debug print
			 }
			 |  LESSTHAN
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
            //fprintf(stderr, "Debug message adicaousub: adicaousub op_adicaousub multoudivoures\n");
					$$ = $2;
					ast_add_child($$, $1);
					ast_add_child($$, $3);
                    $$->node_type = new_type($1,$3);
					//printf("Added adicaousub, op_adicaousub, and multoudivoures to adicaousub\n"); // Debug print

                    char* temp = generate_temp();

                    current_opcode = get_opcode_from_string($2->valor_lexico->token_value);

                    operation_t* generated_code = initialize_operation(NULL, current_opcode, strdup($1->temp), strdup($3->temp), strdup(temp));
                    $$->code = append_operations($1->code, $3->code);
                    $$->code = append_operations($$->code, generated_code);
                    $$->temp = temp;


		  }
          ;

//##########################
// Operação de adição e subtração
op_adicaousub: ADD
			 {
				$$ = $1;;
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
                //fprintf(stderr, "Debug message multoudivoures: multoudivoures op_multoudivoures unario\n");
					$$ = $2;
					ast_add_child($$, $1);
					ast_add_child($$, $3);
                    $$->node_type = new_type($1,$3);
					//printf("Added multoudivoures, op_multoudivoures, and unario to multoudivoures\n"); // Debug print

                    char* temp = generate_temp();

                    current_opcode = get_opcode_from_string($2->valor_lexico->token_value);

                    operation_t* generated_code = initialize_operation(NULL, current_opcode, strdup($1->temp), strdup($3->temp), strdup(temp));
                    $$->code = append_operations($1->code, $3->code);
                    $$->code = append_operations($$->code, generated_code);
                    $$->temp = temp;

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
            //fprintf(stderr, "Before appending primario: $$->code=%p, $1->code=%p\n\n", $$->code, $1->code);
			$$ = $1;
            
            //fprintf(stderr, "After appending primario: $$->code=%p, $1->code=%p\n\n", $$->code, $1->code);
			//printf("Added primario to unario\n"); // Debug print
	  }
      | INVERTSIG unario
	  {
			$$ = $1;
		    ast_add_child($$, $2);
            $$->node_type = $2->node_type;

            char* temp = generate_temp();
            operation_t* generated_code = initialize_operation(NULL, RSUBI, strdup($2->temp), strdup("0"), strdup(temp));
            $$->code = append_operations($2->code, generated_code);
            $$->temp = temp; // Store the result


		    //printf("Added INVERTSIG and unario to unario\n"); // Debug print
	  }
      | NEGATE unario
	  {
			$$ = $1;
		    ast_add_child($$, $2);
            $$->node_type = $2->node_type;
		    //printf("Added NEGATE and unario to unario\n"); // Debug print

            char* temp = generate_temp();
            operation_t* generated_code = initialize_operation(NULL, XORI, strdup("true"), strdup($2->temp), strdup(temp));
            $$->code = append_operations($2->code, generated_code);
            $$->temp = temp; // Store the result
	  }
      ;

//##########################
// Expressões primarias
primario: identificador
		{
            //fprintf(stderr, "Debug message primario: identificador\n");
            $$ = $1;
			//printf("Added identificador to primario\n");
            
			char* new_key = $1->valor_lexico->token_value;
							  
            symbol_t* result = search_symbol_stack(stack_of_tables, new_key);

            table_of_symbols_t* current_scope = search_stack_for_adress(stack_of_tables, new_key);

            //fprintf(stderr, "Debug message primario: identificadorPost\n");

            if(result){

                int adress = result->adress_displacement;

                //fprintf(stderr, "Debug message primario: identificadorResult\n");

                char* temp = generate_temp();

                char* op1;

                if(current_scope->is_global)
                    op1 = strdup("rbss");
                else
                    op1 = strdup("rfp");

                char* op2 = (char*) malloc(sizeof(char) * OPCODE_SIZE_OF_BUFFER);

                sprintf(op2, "%d", adress + initial_space);

                operation_t* generated_code = initialize_operation(NULL, LOADAI, op1, op2, strdup(temp));

                $$->temp = temp;
                //fprintf(stderr, "Before appending Identificador: $$->code=%p, $1->code=%p\n\n", $$->code, $1->code);
                $$->code = append_operations($$->code, generated_code);
                //fprintf(stderr, "After appending Identificador: $$->code=%p, $1->code=%p\n\n", $$->code, $1->code);
            }

			if(result == NULL){
               printf("[ERR_UNDECLARED] Var [%s] na linha %d nao foi declarada\n", new_key, get_line_number());
               exit(ERR_UNDECLARED);
            }
            else {
                int nature = result->nature;
                //printf("Nature: [%d]\n\n", nature);
                $$->node_type = result->data_type;
                    
                if(nature == TOKEN_NATURE_FUNCTION){
                    printf("[ERR_VARIABLE] Funcao [%s] na linha %d esta sendo usada como variavel\n", new_key, get_line_number());
                    exit(ERR_FUNCTION);
                }
            }
		}
        | literais
		{
            //fprintf(stderr, "Before appending literais: $$->code=%p, $1->code=%p\n\n", $$->code, $1->code);
			$$ = $1;
            //fprintf(stderr, "After appending literais: $$->code=%p, $1->code=%p\n\n", $$->code, $1->code);
			//printf("Added literais to primario\n"); // Debug print
		}
        | chamada_funcao
		{
			$$ = $1;
			//printf("Added chamada_funcao to primario\n"); // Debug print
		}
        | '(' expressao ')' // Loop de expressoes, menor prioridade de todos.
		{
			$$ = $2;
            $$->node_type = $2->node_type;
			//printf("Added expressao to primario\n"); // Debug print
		}
        ;

//##########################
// Chamada de função
chamada_funcao: nome_func '(' lista_de_argumentos ')'
			  {
                //fprintf(stderr, "Debug message chamada_funcao: nome_func '(' lista_de_argumentos ')'\n");
				$$ = $1;
				ast_add_child($$, $3);
                char *new_key = $1->valor_lexico->token_value;

                char *parsed_key = ast_parse_function_call(new_key);

                symbol_t* result = search_symbol_stack(stack_of_tables, parsed_key);
                if(result == NULL)
                {
                    printf("[ERR_UNDECLARED] Funcao [%s] na linha %d nao foi declarada\n", parsed_key, get_line_number());
    				exit(ERR_UNDECLARED);
                }
				//printf("Added nome_func and lista_de_argumentos to chamada_funcao\n"); // Debug print
                else
                {
                    int nature = result->nature;
                    //printf("Nature: [%d]\n\n", nature);
                    $$->node_type = result->data_type;
                    if(nature == TOKEN_NATURE_IDENTIFIER){
                        printf("[ERR_FUNCTION] Variavel [%s] na linha %d esta sendo usada como funcao\n", parsed_key, get_line_number());
                        exit(ERR_VARIABLE);
                    }
                }
			  }
			  | nome_func '('/*vazio*/')'
			  {
                //fprintf(stderr, "Debug message chamada_funcao:  nome_func '('/*vazio*/')'\n");
				$$ = $1;
				//printf("Added nome_func to chamada_funcao\n"); // Debug print
				char *new_key = $1->valor_lexico->token_value;

                char *parsed_key = ast_parse_function_call(new_key);

                symbol_t* result = search_symbol_stack(stack_of_tables, parsed_key);
                if(result == NULL)
                {
                    printf("[ERR_UNDECLARED] Funcao [%s] na linha %d nao foi declarada\n", parsed_key, get_line_number());
    				exit(ERR_UNDECLARED);
                }
				//printf("Added nome_func and lista_de_argumentos to chamada_funcao\n"); // Debug print
                else
                {
                    int nature = result->nature;
                    //printf("Nature: [%d]\n\n", nature);
                    $$->node_type = result->data_type;
                    if(nature == TOKEN_NATURE_IDENTIFIER){
                        printf("[ERR_FUNCTION] Variavel [%s] na linha %d esta sendo usada como funcao\n", parsed_key, get_line_number());
                        exit(ERR_VARIABLE);
                    }
                }
			  }
              ;

//##########################
// Lista de expressões
lista_de_argumentos: expressao
			   {
                //fprintf(stderr, "Before appending express: $$->code=%p, $1->code=%p\n\n", $$->code, $1->code);
                //fprintf(stderr, "Debug message lista_de_argumentos: expressao\n");
				$$ = $1;
                //fprintf(stderr, "After appending express: $$->code=%p, $1->code=%p\n\n", $$->code, $1->code);
				//printf("Added expressao to lista_de_argumentos\n"); // Debug print
			   }
               |  expressao ';'  lista_de_argumentos
			   {
				if ($3 == NULL)
				{
                    //fprintf(stderr, "Debug lista_de_argumentos: expressao ';'  lista_de_argumentos;\n");
					$$ = $1; 
				}
				else
				{
					if ($1 == NULL)
					{
                        //fprintf(stderr, "Else 1 Debug lista_de_argumentos: expressao ';'  lista_de_argumentos;\n");
						$$ = $3;
					}
					else
					{
                        //fprintf(stderr, "Else 2 Debug lista_de_argumentos: expressao ';'  lista_de_argumentos;\n");
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
            //fprintf(stderr, "Before appending LITINT: $$->code=%p, $1->code=%p\n\n", $$->code, $1->code);
			$$ = $1;
            //fprintf(stderr, "After appending LITINT: $$->code=%p, $1->code=%p\n\n", $$->code, $1->code);
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
            //fprintf(stderr, "Debug message LITINT: TK_LIT_INT\n");
			$$ = ast_new($1);
            $$->node_type = NODE_TYPE_INT;
            char* temp = generate_temp();
            $$->temp = temp;

            char* op1 = (char*) malloc(sizeof(char) * OPCODE_SIZE_OF_BUFFER);
            op1 = $$->valor_lexico->token_value;
            operation_t* generated_code = initialize_operation(NULL, LOADI, op1, strdup(temp), NULL);

            $$->code = append_operations($$->code, generated_code);

			//printf("Added TK_LIT_INT to LITINT\n"); // Debug print
	  }
	  ;

//##########################
// Token LITFLOAT
LITFLOAT: TK_LIT_FLOAT
		{
			$$ = ast_new($1);
            $$->node_type = NODE_TYPE_FLOAT;
			//printf("Added TK_LIT_FLOAT to LITFLOAT\n"); // Debug print
		}
		;

//##########################
// Token LITFALSE
LITFALSE: TK_LIT_FALSE
		{
			$$ = ast_new($1);
            $$->node_type = NODE_TYPE_BOOL;
			//printf("Added TK_LIT_FALSE to LITFALSE\n"); // Debug print
		}
		;

//##########################
// Token LITTRUE
LITTRUE: TK_LIT_TRUE
	   {
			$$ = ast_new($1);
            $$->node_type = NODE_TYPE_BOOL;
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