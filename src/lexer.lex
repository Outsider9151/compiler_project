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

[ \t]+      ; // 忽略空格和制表符
"//"[^(\n)]*  ; // 单行注释
"/*"([^*]|" *"[^/])*"*/" ; // 多行注释
"int"       { return INT; }
"let"       { return LET; }
"fn"        { return FN; }
"return"    { return RETURN; }
"if"        { return IF; }
"else"      { return ELSE; }
"while"     { return WHILE; }
"+"         { return PLUS; }
"-"         { return MINUS; }
"*"         { return MULTIPLY; }
"/"         { return DIVIDE; }
"=="        { return EQUAL; }
"!="        { return NOT_EQUAL; }
"<"         { return LESS_THAN; }
"<="        { return LESS_THAN_OR_EQUAL; }
">"         { return GREATER_THAN; }
">="        { return GREATER_THAN_OR_EQUAL; }
"&&"        { return LOGICAL_AND; }
"||"        { return LOGICAL_OR; }
"!"         { return LOGICAL_NOT; }
[a-zA-Z][a-zA-Z0-9]* { yylval.strval = strdup(yytext); return ID; }
":" { return COLON; }
"[" { return LBRACK; }
"]" { return RBRACK; }
[0-9]+ { yylval.numval = atoi(yytext); return NUMBER; }
"{"         { return OPEN_BRACE; }
"}"         { return CLOSE_BRACE; }
"("         { return OPEN_PAREN; }
")"         { return CLOSE_PAREN; }
"["         { return OPEN_BRACKET; }
"]"         { return CLOSE_BRACKET; }
";"         { return SEMICOLON; }
"="         { return ASSIGN; }
","         { return COMMA; }

IDENTIFIER { $$ = A_TokenId(A_Pos(@1, @2), strdup(yytext)); }
NUMBER { $$ = A_TokenNum(A_Pos(@1, @2), atoi(yytext)); }



%%

int yywrap() {
    return 1;
}