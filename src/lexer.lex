%{
#include <stdio.h>
#include <string.h>
#include "TeaplAst.h"
#include "y.tab.hpp"
extern int line, col;
%}
/*TODO:*/ 
/*your lexer*/

%start COMMENT_SHORT COMMENT_LONG

%%

<COMMENT_SHORT>{
[\n\r] {  BEGIN INITIAL; line=line+1; col=0; }
. {  /* ignore comment */ }
}

<COMMENT_LONG>{
"*/" {  BEGIN INITIAL;  }
[\n\r] { line=line+1; col=0;  }
. { /* ignore comment */ }
}

<INITIAL>{
"//"  { BEGIN COMMENT_SHORT; }
"/*" { BEGIN COMMENT_LONG; }
[\n\r] { line=line+1; col=0; }
"->"    { yylval.pos = A_Pos(line, col); col+=strlen(yytext); return ARROW; }
"+"	{ yylval.pos = A_Pos(line, col); col+=strlen(yytext); return ADD; }
"-"	{ yylval.pos = A_Pos(line, col); col+=strlen(yytext); return SUB; }
"*"	{ yylval.pos = A_Pos(line, col); col+=strlen(yytext); return MUL; }
"/"	{ yylval.pos = A_Pos(line, col); col+=strlen(yytext); return DIV; }

";"	{ yylval.pos = A_Pos(line, col); col+=strlen(yytext); return SEMICOLON; }
","	{ yylval.pos = A_Pos(line, col); col+=strlen(yytext); return COMMA; }
"struct"	{ yylval.pos = A_Pos(line, col); col+=strlen(yytext); return STRUCT; }
"if"	{ yylval.pos = A_Pos(line, col); col+=strlen(yytext); return IF; }
"else"	{ yylval.pos = A_Pos(line, col); col+=strlen(yytext); return ELSE; }
"let"	{ yylval.pos = A_Pos(line, col); col+=strlen(yytext); return LET; }
">="	{ yylval.pos = A_Pos(line, col); col+=strlen(yytext); return LESS_EQ; }
">"	{ yylval.pos = A_Pos(line, col); col+=strlen(yytext); return GREATER; }
"<="	{ yylval.pos = A_Pos(line, col); col+=strlen(yytext); return GREATER_EQ; }
"<"	{ yylval.pos = A_Pos(line, col); col+=strlen(yytext); return LESS; }
"=="	{ yylval.pos = A_Pos(line, col); col+=strlen(yytext); return EQUAL; }
"!="	{ yylval.pos = A_Pos(line, col); col+=strlen(yytext); return NOT_EQUAL; }
"="	{ yylval.pos = A_Pos(line, col); col+=strlen(yytext); return ASSIGN; }
"("	{ yylval.pos = A_Pos(line, col); col+=strlen(yytext); return LPAREN; }
")"	{ yylval.pos = A_Pos(line, col); col+=strlen(yytext); return RPAREN; }
"["	{ yylval.pos = A_Pos(line, col); col+=strlen(yytext); return LBRACKET; }
"]"	{ yylval.pos = A_Pos(line, col); col+=strlen(yytext); return RBRACKET; }
"{"	{ yylval.pos = A_Pos(line, col); col+=strlen(yytext); return LBRACE; }
"}"	{ yylval.pos = A_Pos(line, col); col+=strlen(yytext); return RBRACE; }
"."	{ yylval.pos = A_Pos(line, col); col+=strlen(yytext); return DOT; }
":"	{ yylval.pos = A_Pos(line, col); col+=strlen(yytext); return COLON; }
"int"	{ yylval.pos = A_Pos(line, col); col+=strlen(yytext); return INT; }
"&&"	{ yylval.pos = A_Pos(line, col); col+=strlen(yytext); return AND; }
"||"	{ yylval.pos = A_Pos(line, col); col+=strlen(yytext); return OR; }
"!"	{ yylval.pos = A_Pos(line, col); col+=strlen(yytext); return NOT; }


"fn"	{ yylval.pos = A_Pos(line, col); col+=strlen(yytext); return FN; }

"ret"	{ yylval.pos = A_Pos(line, col); col+=strlen(yytext); return RET; }
"continue"	{ yylval.pos = A_Pos(line, col); col+=strlen(yytext); return CONTINUE; }
"break"	{ yylval.pos = A_Pos(line, col); col+=strlen(yytext); return BREAK; }
"while"	{ yylval.pos = A_Pos(line, col); col+=strlen(yytext); return WHILE; }
[a-zA-Z]+([a-zA-Z0-9]*) 	{ 
    int len = strlen(yytext);
    char* new_text = (char*)malloc((len+1)*sizeof(char));
    strcpy(new_text, yytext);
    new_text[len]='\0';
    yylval.tokenId = A_TokenId(A_Pos(line, col), new_text); col+=strlen(yytext); return ID; 
}
([1-9]+[0-9]*)|[0]	{ yylval.tokenNum = A_TokenNum(A_Pos(line, col),atoi(yytext)); col+=strlen(yytext); return NUM; }

" "   { col+=1; }
"\t" { col+=4; }

.	{ printf("Unknown character:%s!! line=%d,col=%d\n",yytext,line,col); }
}

%%