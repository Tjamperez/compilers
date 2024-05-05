	/*Created by: Thales Perez 00303035 e Vitor Vargas 00302162 */

%{
#include "parser.tab.h"
#include "val_lex.h"
#include  <string.h>
int get_line_number();
%}

    /* Options for scanner.l */

%option noyywrap
%option yylineno
%x COMMENT

%%
    /* Catch the compilers reserved words and return the token */

"int" {yylval.valor_lexico = gen_val (get_line_number() , PR_TYPE_INT , strdup(yytext)); return TK_PR_INT; }
"float" {yylval.valor_lexico = gen_val (get_line_number() , PR_TYPE_FLOAT , strdup(yytext)); return TK_PR_FLOAT; }
"bool" {yylval.valor_lexico = gen_val (get_line_number() , PR_TYPE_BOOL , strdup(yytext)); return TK_PR_BOOL; }
"if" {yylval.valor_lexico = gen_val (get_line_number() , PR_TYPE_IF , strdup(yytext)); return TK_PR_IF; }
"else" {yylval.valor_lexico = gen_val (get_line_number() , PR_TYPE_ELSE , strdup(yytext)); return TK_PR_ELSE; }
"while" {yylval.valor_lexico = gen_val (get_line_number() , PR_TYPE_WHILE , strdup(yytext)); return TK_PR_WHILE; }
"return" {yylval.valor_lexico = gen_val (get_line_number() , PR_TYPE_RETURN , strdup(yytext)); return TK_PR_RETURN; }

    /* Catch C-style comments of either a single  or multiple lines and return nothing */

	/* Ignore single-line comment */
\/\/.*

\/\*  {BEGIN(COMMENT); }
<COMMENT>[^*\n]* { /* DO NOTHING */ } /* Increment yylineno */
<COMMENT>[ \n\t]   ; /* Increment yylineno */
<COMMENT>"*"+[^*/\n]*	{ /* DO NOTHING */ }/* eat up '*'s not followed by '/'s */

<COMMENT>"*"+"/"  {BEGIN(INITIAL); } /* Increment yylineno */

    /* Catch the compilers special characters and return the token */

[-!*/%+<>\{\}()=,;] {yylval.valor_lexico = gen_val (get_line_number() , SPECIAL_CHAR , strdup(yytext)); return yytext[0];}

    /* Actually make yylineno function */


[ \n\t]   ;      { /* Ignore newline,tab,whitespace characters */ }

    /* Catch the compilers compound operators and return the token */

"<=" {yylval.valor_lexico = gen_val (get_line_number() , OC_TYPE_LE , strdup(yytext)); return TK_OC_LE; }
">=" {yylval.valor_lexico = gen_val (get_line_number() , OC_TYPE_GE , strdup(yytext)); return TK_OC_GE; }
"==" {yylval.valor_lexico = gen_val (get_line_number() , OC_TYPE_EQ , strdup(yytext)); return TK_OC_EQ; }
"!=" {yylval.valor_lexico = gen_val (get_line_number() , OC_TYPE_NE , strdup(yytext)); return TK_OC_NE; }
"&"  {yylval.valor_lexico = gen_val (get_line_number() , OC_TYPE_AND , strdup(yytext)); return TK_OC_AND; }
"|"  {yylval.valor_lexico = gen_val (get_line_number() , OC_TYPE_OR , strdup(yytext)); return TK_OC_OR; }

    /* Catch the compilers literals and return the token */

[0-9]+    {yylval.valor_lexico = gen_val (get_line_number() , LIT_TYPE_INT , strdup(yytext)); return TK_LIT_INT; }
[0-9]*\.[0-9]+    { yylval.valor_lexico = gen_val (get_line_number() , LIT_TYPE_FLOAT , strdup(yytext)); return TK_LIT_FLOAT; }
"false"     {yylval.valor_lexico = gen_val (get_line_number() , LIT_TYPE_BOOL , strdup(yytext)) ; return TK_LIT_FALSE; }
"true"      {yylval.valor_lexico = gen_val (get_line_number() , LIT_TYPE_BOOL , strdup(yytext)) ; return TK_LIT_TRUE; }

    /* Catch the compilers identificator and return the token */

[_a-z][_a-z0-9]* {yylval.valor_lexico = gen_val (get_line_number() , IDENTIFIER_TYPE , strdup(yytext)) ; return TK_IDENTIFICADOR; }

    /* Catch anything with that is not one of the aforementioned lexems and return the error token */

.   { return TK_ERRO; }


%%
    /* Get_line_number finction using flex provided yyleno and return it */

int get_line_number(void) {
    return yylineno;
}
