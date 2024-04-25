	/*Created by: Thales Perez 00303035 e Vitor Vargas 00302162 */

%{
#include "parser.tab.h"
%}

    /* Options for scanner.l */

%option noyywrap
%option yylineno
%x COMMENT

%%
    /* Catch the compilers reserved words and return the token */

"int" { return TK_PR_INT; }
"float" { return TK_PR_FLOAT; }
"bool" {return TK_PR_BOOL; }
"if" {return TK_PR_IF; }
"else" {return TK_PR_ELSE; }
"while" {return TK_PR_WHILE; }
"return" {return TK_PR_RETURN; }

    /* Catch C-style comments of either a single  or multiple lines and return nothing */

	/* Ignore single-line comment */
\/\/.*

\/\*  {BEGIN(COMMENT); }
<COMMENT>[^*\n]* { /* DO NOTHING */ } /* Increment yylineno */
<COMMENT>[ \n\t]   ; /* Increment yylineno */
<COMMENT>"*"+[^*/\n]*	{ /* DO NOTHING */ }/* eat up '*'s not followed by '/'s */

<COMMENT>"*"+"/"  {BEGIN(INITIAL); } /* Increment yylineno */

    /* Catch the compilers special characters and return the token */

[-!*/%+<>\{\}()=,;] {return yytext[0];}

    /* Actually make yylineno function */


[ \n\t]   ;      { /* Ignore newline,tab,whitespace characters */ }

    /* Catch the compilers compound operators and return the token */

"<=" {return TK_OC_LE; }
">=" {return TK_OC_GE; }
"==" {return TK_OC_EQ; }
"!=" {return TK_OC_NE; }
"&" {return TK_OC_AND; }
"|" {return TK_OC_OR; }

    /* Catch the compilers literals and return the token */

[0-9]+    {return TK_LIT_INT; }
[0-9]*\.[0-9]+    {return TK_LIT_FLOAT; }
"false"     {return TK_LIT_FALSE; }
"true"      {return TK_LIT_TRUE; }

    /* Catch the compilers identificator and return the token */

[_a-z][_a-z0-9]* {return TK_IDENTIFICADOR; }

    /* Catch anything with that is not one of the aforementioned lexems and return the error token */

.   { return TK_ERRO; }


%%
    /* Get_line_number finction using flex provided yyleno and return it */

int get_line_number(void) {
    return yylineno;
}
