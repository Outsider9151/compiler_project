%{
#include <stdio.h>
#include <string.h>
#include "TeaplAst.h"
#include "y.tab.hpp"
extern int line, col;
%}

// TODO:
// your lexer

%option noyywrap

%%
[ \t]  ;  /* 跳过空白字符 */
\n     { line++; col = 1; }  /* 更新行号并重置字符位置 */
.      { col += yyleng; }  /* 更新字符位置 */

"let"      { yylval.str_val = strdup(yytext); return LET; }
"struct"   { yylval.str_val = strdup(yytext); return STRUCT_TYPE; }
"fn"       { yylval.str_val = strdup(yytext); return FN; }
"if"       { yylval.str_val = strdup(yytext); return IF; }
"else"     { yylval.str_val = strdup(yytext); return ELSE; }
"while"    { yylval.str_val = strdup(yytext); return WHILE; }
"return"   { yylval.str_val = strdup(yytext); return RET; }
"continue" { yylval.str_val = strdup(yytext); return CONTINUE; }
"break"    { yylval.str_val = strdup(yytext); return BREAK; }
"int"      { yylval.str_val = strdup(yytext); return NATIVE_TYPE; }

[0-9]+      { yylval.num = atoi(yytext); return NUM; }
[a-zA-Z][a-zA-Z0-9]*  { yylval.str = strdup(yytext); return ID; }

"+"      { yylval.str_val = strdup(yytext); return PLUS; }
"-"      { yylval.str_val = strdup(yytext); return MINUS; }
"*"      { yylval.str_val = strdup(yytext); return MULT; }
"/"      { yylval.str_val = strdup(yytext); return DIV; }
">"      { yylval.str_val = strdup(yytext); return GREATER; }
"<"      { yylval.str_val = strdup(yytext); return LESS; }
">="     { yylval.str_val = strdup(yytext); return GREATER_EQ; }
"<="     { yylval.str_val = strdup(yytext); return LESS_EQ; }
"=="     { yylval.str_val = strdup(yytext); return EQUAL; }
"!="     { yylval.str_val = strdup(yytext); return NOT_EQUAL; }
"&&"     { yylval.str_val = strdup(yytext); return AND; }
"||"     { yylval.str_val = strdup(yytext); return OR; }
"!"      { yylval.str_val = strdup(yytext); return NOT; }
"="      { yylval.str_val = strdup(yytext); return ASSIGN; }
";"      { yylval.str_val = strdup(yytext); return SEMICOLON; }
"("      { yylval.str_val = strdup(yytext); return LPAREN; }
")"      { yylval.str_val = strdup(yytext); return RPAREN; }
"{"      { yylval.str_val = strdup(yytext); return LBRACE; }
"}"      { yylval.str_val = strdup(yytext); return RBRACE; }
"["      { yylval.str_val = strdup(yytext); return LBRACKET; }
"]"      { yylval.str_val = strdup(yytext); return RBRACKET; }
","      { yylval.str_val = strdup(yytext); return COMMA; }
"."      { yylval.str_val = strdup(yytext); return DOT; }


"//"([^/\n]|\/[^/n]|\/\n[^/])*\n  ; /* 单行注释 */

"/*"([^*]|*[^/])*"*/"  ; /* 多行注释 */

.        { fprintf(stderr, "词法错误: 未知字符: %s 在 %d 行 %d 列\n", yytext, line, col); }

%%

int yywrap() {
    return 1;
}
