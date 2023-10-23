%{
#include <stdio.h>
#include <string.h>
#include "TeaplAst.h"
#include "y.tab.hpp"
extern int line, col;
%}

<<<<<<< HEAD
<<<<<<< HEAD
%start COMMENT_SHORT COMMENT_LONG

%%

<<<<<<< HEAD
<COMMENT_SHORT>{
[\n\r] {  BEGIN INITIAL; line=line+1; col=0; }
. {  /* 单行注释 */ }
}

<COMMENT_LONG>{
"*/" {  BEGIN INITIAL;  }
[\n\r] { line=line+1; col=0;  }
. { /* 多行注释 */ }
}

<INITIAL>{
"//"  { BEGIN COMMENT_SHORT; }
"/*" { BEGIN COMMENT_LONG; }
[\n\r] { line=line+1; col=0; }
"->"    { yylval.pos = A_Pos(line, col); col+=yyleng; return ARROW; }
"+"	{ yylval.pos = A_Pos(line, col); col+=yyleng; return ADD; }
"-"	{ yylval.pos = A_Pos(line, col); col+=yyleng; return SUB; }
"*"	{ yylval.pos = A_Pos(line, col); col+=yyleng; return MUL; }
"/"	{ yylval.pos = A_Pos(line, col); col+=yyleng; return DIV; }

";"	{ yylval.pos = A_Pos(line, col); col+=yyleng; return SEMICOLON; }
","	{ yylval.pos = A_Pos(line, col); col+=yyleng; return COMMA; }
"struct"	{ yylval.pos = A_Pos(line, col); col+=yyleng; return STRUCT; }
"if"	{ yylval.pos = A_Pos(line, col); col+=yyleng; return IF; }
"else"	{ yylval.pos = A_Pos(line, col); col+=yyleng; return ELSE; }
"let"	{ yylval.pos = A_Pos(line, col); col+=yyleng; return LET; }
">="	{ yylval.pos = A_Pos(line, col); col+=yyleng; return LESS_EQ; }
">"	{ yylval.pos = A_Pos(line, col); col+=yyleng; return GREATER; }
"<="	{ yylval.pos = A_Pos(line, col); col+=yyleng; return GREATER_EQ; }
"<"	{ yylval.pos = A_Pos(line, col); col+=yyleng; return LESS; }
"=="	{ yylval.pos = A_Pos(line, col); col+=yyleng; return EQUAL; }
"!="	{ yylval.pos = A_Pos(line, col); col+=yyleng; return NOT_EQUAL; }
"="	{ yylval.pos = A_Pos(line, col); col+=yyleng; return ASSIGN; }
"("	{ yylval.pos = A_Pos(line, col); col+=yyleng; return LPAREN; }
")"	{ yylval.pos = A_Pos(line, col); col+=yyleng; return RPAREN; }
"["	{ yylval.pos = A_Pos(line, col); col+=yyleng; return LBRACKET; }
"]"	{ yylval.pos = A_Pos(line, col); col+=yyleng; return RBRACKET; }
"{"	{ yylval.pos = A_Pos(line, col); col+=yyleng; return LBRACE; }
"}"	{ yylval.pos = A_Pos(line, col); col+=yyleng; return RBRACE; }
"."	{ yylval.pos = A_Pos(line, col); col+=yyleng; return DOT; }
":"	{ yylval.pos = A_Pos(line, col); col+=yyleng; return COLON; }
"int"	{ yylval.pos = A_Pos(line, col); col+=yyleng; return INT; }
"&&"	{ yylval.pos = A_Pos(line, col); col+=yyleng; return AND; }
"||"	{ yylval.pos = A_Pos(line, col); col+=yyleng; return OR; }
"!"	{ yylval.pos = A_Pos(line, col); col+=yyleng; return NOT; }


"fn"	{ yylval.pos = A_Pos(line, col); col+=yyleng; return FN; }

"ret"	{ yylval.pos = A_Pos(line, col); col+=yyleng; return RET; }
"continue"	{ yylval.pos = A_Pos(line, col); col+=yyleng; return CONTINUE; }
"break"	{ yylval.pos = A_Pos(line, col); col+=yyleng; return BREAK; }
"while"	{ yylval.pos = A_Pos(line, col); col+=yyleng; return WHILE; }
[a-zA-Z]+([a-zA-Z0-9]*) 	{ 
    int len = yyleng;
    char* new_text = (char*)malloc((len+1)*sizeof(char));
    strcpy(new_text, yytext);
    new_text[len]='\0';
    yylval.tokenId = A_TokenId(A_Pos(line, col), new_text); col+=yyleng; return ID; 
}
([1-9]+[0-9]*)|[0]	{ yylval.tokenNum = A_TokenNum(A_Pos(line, col),atoi(yytext)); col+=yyleng; return NUM; }

" "   { col+=1; }
"\t" { col+=4; }

.	{ printf("词法错误: 未知字符: %s 在 %d 行 %d 列\n", yytext, line, col); }
}

%%
=======
// TODO:
// your lexer

%option noyywrap

%%
<<<<<<< HEAD
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
=======
%start COMMENT_SHORT COMMENT_LONG
>>>>>>> 703b848 (okk)

%%





=======
>>>>>>> 195a6e8 (11)
<COMMENT_SHORT>{
[\n\r] {  BEGIN INITIAL; line=line+1; col=0; }
. {  /* 单行注释 */ }
}
<<<<<<< HEAD
<<<<<<< HEAD
>>>>>>> 57849de (新尝试，有bug)
=======
>>>>>>> d01065b (架构已经差不多了，现在根据给出的Ast节点结构细调)
=======

<COMMENT_LONG>{
"*/" {  BEGIN INITIAL;  }
[\n\r] { line=line+1; col=0;  }
. { /* 多行注释 */ }
}

<INITIAL>{
"//"  { BEGIN COMMENT_SHORT; }
"/*" { BEGIN COMMENT_LONG; }
[\n\r] { line=line+1; col=0; }
"->"    { yylval.pos = A_Pos(line, col); col+=yyleng; return ARROW; }
"+"	{ yylval.pos = A_Pos(line, col); col+=yyleng; return ADD; }
"-"	{ yylval.pos = A_Pos(line, col); col+=yyleng; return SUB; }
"*"	{ yylval.pos = A_Pos(line, col); col+=yyleng; return MUL; }
"/"	{ yylval.pos = A_Pos(line, col); col+=yyleng; return DIV; }

";"	{ yylval.pos = A_Pos(line, col); col+=yyleng; return SEMICOLON; }
","	{ yylval.pos = A_Pos(line, col); col+=yyleng; return COMMA; }
"struct"	{ yylval.pos = A_Pos(line, col); col+=yyleng; return STRUCT; }
"if"	{ yylval.pos = A_Pos(line, col); col+=yyleng; return IF; }
"else"	{ yylval.pos = A_Pos(line, col); col+=yyleng; return ELSE; }
"let"	{ yylval.pos = A_Pos(line, col); col+=yyleng; return LET; }
">="	{ yylval.pos = A_Pos(line, col); col+=yyleng; return LESS_EQ; }
">"	{ yylval.pos = A_Pos(line, col); col+=yyleng; return GREATER; }
"<="	{ yylval.pos = A_Pos(line, col); col+=yyleng; return GREATER_EQ; }
"<"	{ yylval.pos = A_Pos(line, col); col+=yyleng; return LESS; }
"=="	{ yylval.pos = A_Pos(line, col); col+=yyleng; return EQUAL; }
"!="	{ yylval.pos = A_Pos(line, col); col+=yyleng; return NOT_EQUAL; }
"="	{ yylval.pos = A_Pos(line, col); col+=yyleng; return ASSIGN; }
"("	{ yylval.pos = A_Pos(line, col); col+=yyleng; return LPAREN; }
")"	{ yylval.pos = A_Pos(line, col); col+=yyleng; return RPAREN; }
"["	{ yylval.pos = A_Pos(line, col); col+=yyleng; return LBRACKET; }
"]"	{ yylval.pos = A_Pos(line, col); col+=yyleng; return RBRACKET; }
"{"	{ yylval.pos = A_Pos(line, col); col+=yyleng; return LBRACE; }
"}"	{ yylval.pos = A_Pos(line, col); col+=yyleng; return RBRACE; }
"."	{ yylval.pos = A_Pos(line, col); col+=yyleng; return DOT; }
":"	{ yylval.pos = A_Pos(line, col); col+=yyleng; return COLON; }
"int"	{ yylval.pos = A_Pos(line, col); col+=yyleng; return INT; }
"&&"	{ yylval.pos = A_Pos(line, col); col+=yyleng; return AND; }
"||"	{ yylval.pos = A_Pos(line, col); col+=yyleng; return OR; }
"!"	{ yylval.pos = A_Pos(line, col); col+=yyleng; return NOT; }


"fn"	{ yylval.pos = A_Pos(line, col); col+=yyleng; return FN; }

"ret"	{ yylval.pos = A_Pos(line, col); col+=yyleng; return RET; }
"continue"	{ yylval.pos = A_Pos(line, col); col+=yyleng; return CONTINUE; }
"break"	{ yylval.pos = A_Pos(line, col); col+=yyleng; return BREAK; }
"while"	{ yylval.pos = A_Pos(line, col); col+=yyleng; return WHILE; }
[a-zA-Z]+([a-zA-Z0-9]*) 	{ 
    int len = yyleng;
    char* new_text = (char*)malloc((len+1)*sizeof(char));
    strcpy(new_text, yytext);
    new_text[len]='\0';
    yylval.tokenId = A_TokenId(A_Pos(line, col), new_text); col+=yyleng; return ID; 
}
([1-9]+[0-9]*)|[0]	{ yylval.tokenNum = A_TokenNum(A_Pos(line, col),atoi(yytext)); col+=yyleng; return NUM; }

" "   { col+=1; }
"\t" { col+=4; }

.	{ printf("词法错误: 未知字符: %s 在 %d 行 %d 列\n", yytext, line, col); }
}

%%
>>>>>>> 703b848 (okk)
=======

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
>>>>>>> 57849de (新尝试，有bug)
