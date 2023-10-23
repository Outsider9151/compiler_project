%{
#include <stdio.h>
#include "TeaplAst.h"

extern A_program root;
extern int yylex(void);

void yyerror(const char *s);
%}

%union {
  A_pos pos;
  A_program program;
  A_programElementList programElementList;
  A_programElement programElement;
  A_arithExpr arithExpr;
  A_exprUnit exprUnit;
  A_structDef structDef;
  A_varDeclStmt varDeclStmt;
  A_fnDeclStmt fnDeclStmt;
  A_fnDef fnDef;
}

%token <pos> IDENTIFIER
%token <pos> NUMBER
%token <pos> SEMICOLON
%token <pos> LET
%token <pos> FN
%token <pos> STRUCT
%token <pos> OPEN_BRACE
%token <pos> CLOSE_BRACE
%token <pos> OPEN_PAREN
%token <pos> CLOSE_PAREN
%token <pos> COLON
%token <pos> COMMA
%token <pos> ADD
%token <pos> SUB
%token <pos> MUL
%token <pos> DIV


%type <program> Program
%type <programElement> ProgramElement
%type <varDeclStmt> VarDeclStmt
%type <fnDeclStmt> FnDeclStmt
%type <fnDef> FnDef
%type <varDecl> VarDecl
%type <paramDecl> ParamDecl
%type <codeBlock> CodeBlock
%type <arithExpr> ArithExpr
%type <exprUnit> ExprUnit
%type <structDef> StructDef


%start Program

%%

Program: ProgramElement
{
  root = A_Program($1->pos, $1);
  $$ = root;
}
;

ProgramElement: VarDeclStmt
{
  $$ = A_ProgramVarDeclStmt($1->pos, $1);
}
| FnDeclStmt
{
  $$ = A_ProgramFnDeclStmt($1->pos, $1);
}
| FnDef
{
  $$ = A_ProgramFnDef($1->pos, $1);
}
| StructDef
{
  $$ = A_ProgramStructDef($1->pos, $1);
}
| SEMICOLON
{
  // Handle empty statement
  $$ = A_ProgramNullStmt($1->pos);
}
;

ProgramElementList:
  ProgramElement
  | ProgramElementList ProgramElement
  ;


VarDeclStmt: LET VarDecl SEMICOLON
{
  $$ = A_VarDeclStmt($2->pos, $2);
}
;

FnDeclStmt: FN IDENTIFIER OPEN_PAREN ParamDecl CLOSE_PAREN SEMICOLON
{
  $$ = A_FnDeclStmt($2->pos, $2, $4);
}
;

FnDef: FN IDENTIFIER OPEN_PAREN ParamDecl CLOSE_PAREN CodeBlock
{
  $$ = A_FnDef($2->pos, $2, $4, $6);
}
;

ParamDecl: VarDecl
{
  $$ = A_ParamDecl(A_VarDeclList($1, NULL));
}
| ParamDecl COMMA VarDecl
{
  A_varDeclList varDecls = A_VarDeclList($3, $1->u.varDeclList);
  $$ = A_ParamDecl(varDecls);
}
;

CodeBlock: OPEN_BRACE ProgramElementList CLOSE_BRACE
{
  $$ = A_CodeBlock($1->pos, $2); // 用$2代表代码块内的语法元素
}
;

VarDecl: IDENTIFIER COLON IDENTIFIER
{
  $$ = A_VarDeclScalar($1->pos, $1->name, A_NativeType($3->pos, A_intTypeKind)); 
}
| IDENTIFIER OPEN_BRACE NUMBER CLOSE_BRACE
{
  $$ = A_VarDeclArray($1->pos, $1->name, atoi($3), A_NativeType($5->pos, A_intTypeKind)); // 将字符串$3转换为整数
}
| IDENTIFIER OPEN_BRACE NUMBER CLOSE_BRACE OPEN_BRACE ExprUnit CLOSE_BRACE
{
  $$ = A_VarDeclArray($1->pos, $1->name, atoi($3), A_NativeType($5->pos, A_intTypeKind), $7);
}
;



ArithExpr: ArithExpr ADD ArithExpr
{
  $$ = A_ArithBiOpExpr($1->pos, A_add, $1, $3);
}
| ArithExpr SUB ArithExpr
{
  $$ = A_ArithBiOpExpr($1->pos, A_sub, $1, $3);
}
| NUMBER
{
  $$ = A_ArithExprVal($1->pos, A_arithBiOpExprKind, A_ArithNumExpr($1->pos, $1->val));
}
;

ExprUnit: IDENTIFIER
{
  $$ = A_ArithExprVal($1->pos, A_idExprKind, A_IdExprUnit($1->pos, $1->name));
}
| NUMBER
{
  $$ = A_ArithExprVal($1->pos, A_numExprKind, A_ArithNumExpr($1->pos, $1->val));
}
;

StructDef: STRUCT IDENTIFIER OPEN_BRACE VarDeclStmt CLOSE_BRACE SEMICOLON
{
  $$ = A_StructDef($2->pos, $2, A_VarDeclStmt(A_VarDeclList($4, NULL)));
}
;


%%

void yyerror(const char *s)
{
  fprintf(stderr, "Syntax error: %s\n", s);
}

int main()
{
  yyparse();
  // Now you can use the 'root' variable to access the generated AST.
  return 0;
}
