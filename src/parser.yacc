%{
#include <stdio.h>
#include "TeaplAst.h"

extern A_pos pos;
extern A_program root;

extern int yylex(void);
extern "C"{
extern void yyerror(char *s); 
extern int  yywrap();
}

%}

// TODO:
// your parser

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

%token <pos> ADD
%token <pos> SUB
%token <pos> MUL
%token <pos> DIV
%token <pos> SEMICOLON
%token <pos> LPAREN
%token <pos> RPAREN
%token <pos> AND
%token <pos> OR
%token <pos> NOT
%token <pos> GREATER
%token <pos> LESS
%token <pos> GREATER_EQ
%token <pos> LESS_EQ
%token <pos> EQUAL
%token <pos> NOT_EQUAL
%token <pos> ASSIGN
%token <pos> FN_CALL
%token <pos> LET
%token <pos> COLON
%token <pos> COMMA
%token <pos> LBRACKET
%token <pos> RBRACKET
%token <pos> LBRACE
%token <pos> RBRACE
%token <pos> STRUCT
%token <pos> FN
%token <pos> ARROW
%token <pos> RET
%token <pos> DOT
%token <pos> NUM
%token <pos> ID
%token <pos> CONTINUE
%token <pos> BREAK
%token <pos> IF
%token <pos> ELSE
%token <pos> WHILE
%token <pos> NATIVE_TYPE
%token <pos> STRUCT_TYPE


%type <program> Program
%type <arithExpr> ArithExpr
%type <programElementList> ProgramElementList
%type <programElement> ProgramElement
%type <exprUnit> ExprUnit
%type <structDef> StructDef
%type <varDeclStmt> VarDeclStmt
%type <varDecl> VarDecl
%type <varDeclList> VarDeclList
%type <varDef> VarDef
%type <fnDeclStmt> FnDeclStmt
%type <fnDef> FnDef
%type <fnCall> FnCall
%type <boolExpr> BoolExpr
%type <boolUnit> BoolUnit
%type <comOp> ComOp
%type <assignStmt> AssignStmt
%type <leftVal> LeftVal
%type <rightVal> RightVal
%type <rightValList> RightValList
%type <type> Type


%start Program

%%                   /* beginning of rules section */

Program: ProgramElementList 
{  
  root = A_Program($1);
  $$ = A_Program($1);
}
;

ProgramElementList: ProgramElement ProgramElementList
{
  $$ = A_ProgramElementList($1, $2);
}
|
{
  $$ = NULL;
}
;

ProgramElement: VarDeclStmt
{
  $$ = A_ProgramVarDeclStmt($1->pos, $1);
}
| StructDef
{
  $$ = A_ProgramStructDef($1->pos, $1);
}
| FnDeclStmt
{
  $$ = A_ProgramFnDeclStmt($1->pos, $1);
}
| FnDef
{
  $$ = A_ProgramFnDef($1->pos, $1);
}
| SEMICOLON
{
  $$ = A_ProgramNullStmt($1);
}
;

ExprUnit: NUM
{
  $$ = A_Num($1->pos, $1);
}
| ID
{
  $$ = A_Id($1->pos, $1);
}
;



ArithExpr: ArithExpr ADD ArithExpr
{
  $$ = A_ArithBiOp_Expr($1->pos, A_ArithBiOpExpr($1->pos, A_add, $1, $3));
}
| ArithExpr SUB ArithExpr
{
  $$ = A_ArithBiOp_Expr($1->pos, A_ArithBiOpExpr($1->pos, A_sub, $1, $3));
}
| ArithExpr MUL ArithExpr
{
  $$ = A_ArithBiOp_Expr($1->pos, A_ArithBiOpExpr($1->pos, A_mul, $1, $3));
}
| ArithExpr DIV ArithExpr
{
  $$ = A_ArithBiOp_Expr($1->pos, A_ArithBiOpExpr($1->pos, A_div, $1, $3));
}
| ExprUnit
{
  $$ = A_ExprUnit($1->pos, $1);
}
;

ExprUnit: NUM
{
  $$ = A_NumExpr($1->pos, atoi($1->str_val));
}
| ID
{
  $$ = A_IdExpr($1->pos, $1->str_val);
}
| LPAREN ArithExpr RPAREN
{
  $$ = $2;
}
| FN_CALL LPAREN RPAREN
{
  $$ = A_FnCallExpr($1->pos, $1->str_val, NULL);
}
| ID LBRACKET ID RBRACKET
{
  $$ = A_ArrayAccessExpr($1->pos, $1->str_val, $3->str_val);
}
| ID DOT ID
{
  $$ = A_MemberAccessExpr($1->pos, $1->str_val, $3->str_val);
}
| SUB ExprUnit
{
  $$ = A_ArithUOp_Expr($1->pos, A_ArithUOpExpr($1->pos, A_neg, $2));
}
;


BoolExpr: BoolExpr AND BoolUnit
{
  $$ = A_BoolBiOpExpr($1->pos, A_bool_and, $1, $3);
}
| BoolExpr OR BoolUnit
{
  $$ = A_BoolBiOpExpr($1->pos, A_bool_or, $1, $3);
}
| BoolUnit
{
  $$ = $1;
}
;

BoolUnit: ExprUnit ComOp ExprUnit
{
  $$ = A_CompExpr($1->pos, $1, $3, $2);
}
| LPAREN BoolExpr RPAREN
{
  $$ = $2;
}
| NOT BoolUnit
{
  $$ = A_BoolUOpExpr($1->pos, A_not, $2);
}
;


ComOp: GREATER
{
  $$ = A_greater;
}
| LESS
{
  $$ = A_less;
}
| GREATER_EQ
{
  $$ = A_greater_eq;
}
| LESS_EQ
{
  $$ = A_less_eq;
}
| EQUAL
{
  $$ = A_equal;
}
| NOT_EQUAL
{
  $$ = A_not_equal;
}
;


AssignStmt: LeftVal ASSIGN RightVal SEMICOLON
{
  $$ = A_Assign_Stmt($1->pos, A_AssignStmt($1->pos, $1, $3));
}
;

LeftVal: ID
{
  $$ = A_LeftVal_Id($1->pos, $1);
}
| ID LBRACKET ID RBRACKET
{
  $$ = A_LeftVal_ArrayElem($1->pos, A_LeftValArrayElem($1->pos, $1, $3));
}
| ID DOT ID
{
  $$ = A_LeftVal_StructElem($1->pos, A_LeftValStructElem($1->pos, $1, $3));
}
;

RightVal: ArithExpr
{
  $$ = A_RightVal_ArithExpr($1->pos, $1);
}
| BoolExpr
{
  $$ = A_RightVal_BoolExpr($1->pos, $1);
}
;

FnCall: ID LPAREN RightValList RPAREN
{
  $$ = A_Fn_Call($1->pos, $1, $3);
}
;

RightValList: RightVal COMMA RightValList
{
  $$ = A_RightValList($1->pos, A_RightValList($1, $1, $3));
}
| RightVal
{
  $$ = A_RightValList($1->pos, A_RightValList($1, $1, NULL));
}
| /* 空产生式 */
{
  $$ = A_RightValList($1->pos, NULL);
}
;

VarDeclStmt: LET LPAREN VarDecl | VarDef RPAREN SEMICOLON
{
  if ($2->kind == A_Var_Def) {
    $$ = A_Var_DefStmt($2->pos, $2);
  } else {
    $$ = A_Var_DeclStmt($2->pos, $2);
  }
}
;

VarDecl: ID COLON Type
{
  $$ = A_Var_Decl($2->pos, $1, $3, NULL);
}
| ID LBRACKET NUM RBRACKET COLON Type
{
  $$ = A_Var_Decl($3->pos, $1, $5, $3);
}
| ID
{
  $$ = A_Var_Decl($1->pos, $1, NULL, NULL);
}
| ID LBRACKET NUM RBRACKET
{
  $$ = A_Var_Decl($3->pos, $1, NULL, $3);
}
;

VarDef: ID COLON Type ASSIGN RightVal
{
  $$ = A_Var_Def($2->pos, $1, $3, $5);
}
| ID ASSIGN RightVal
{
  $$ = A_Var_Def($2->pos, $1, NULL, $3);
}
| ID LBRACKET NUM RBRACKET COLON Type ASSIGN LBRACE RightValList RBRACE
{
  $$ = A_Var_Def($3->pos, $1, $5, $8);
}
| ID LBRACKET NUM RBRACKET ASSIGN LBRACE RightValList RBRACE
{
  $$ = A_Var_Def($3->pos, $1, NULL, $6);
}
;

Type: NATIVE_TYPE
{
  $$ = A_NativeType($1->pos, $1);
}
| STRUCT_TYPE
{
  $$ = A_StructType($1->pos, $1);
}
;

RightVal: ArithExpr
{
  $$ = A_RightVal_ArithExpr($1->pos, $1);
}
| BoolExpr
{
  $$ = A_RightVal_BoolExpr($1->pos, $1);
}
;

RightValList: RightVal COMMA RightValList
{
  $$ = A_RightValList($1->pos, A_RightValList($1, $1, $3));
}
| RightVal
{
  $$ = A_RightValList($1->pos, A_RightValList($1, $1, NULL));
}
| /* 空产生式 */
{
  $$ = A_RightValList($1->pos, NULL);
}
;

StructDef: STRUCT ID LBRACE VarDeclList RBRACE
{
  $$ = A_Struct_Def($2->pos, $2, $4);
}
;

VarDeclList: VarDeclList COMMA VarDecl
{
  $$ = A_VarDeclList($1->pos, $1, $3);
}
| VarDecl
{
  $$ = A_VarDeclList($1->pos, $1, NULL);
}
| /* 空产生式 */
{
  $$ = A_VarDeclList($1->pos, NULL, NULL);
}
;

FnDeclStmt: FnDecl SEMICOLON
{
  $$ = A_FnDeclStmt($1->pos, $1);
}
;

FnDecl: FN ID LPAREN paramDecl RPAREN
{
  $$ = A_FnDecl($2->pos, $2, $4, NULL);
}
| FN ID LPAREN paramDecl RPAREN ARROW Type
{
  $$ = A_FnDecl($2->pos, $2, $4, $6);
}
;

paramDecl: VarDecl COMMA paramDecl
{
  $$ = A_VarDeclList($1->pos, $1, $3);
}
| VarDecl
{
  $$ = A_VarDeclList($1->pos, $1, NULL);
}
| /* 空产生式 */
{
  $$ = A_VarDeclList($1->pos, NULL, NULL);
}
;

FnDef: FnDecl codeBlock
{
  $$ = A_FnDef($1->pos, $1, $2);
}
;

codeBlock: LBRACE statements RBRACE
{
  $$ = A_CodeBlockStmtList($1->pos, $2);
}
;

statements: statement statements
{
  $$ = A_StmtList($1->pos, $1, $2);
}
| statement
{
  $$ = A_StmtList($1->pos, $1, NULL);
}
| /* 空产生式 */
{
  $$ = NULL;
}
;

statement: VarDeclStmt
{
  $$ = A_Var_Decl_Stmt($1->pos, $1);
}
| AssignStmt
{
  $$ = A_Assign_Stmt($1->pos, $1);
}
| callStmt
{
  $$ = A_Call_Stmt($1->pos, $1);
}
| ifStmt
{
  $$ = A_If_Stmt($1->pos, $1);
}
| whileStmt
{
  $$ = A_While_Stmt($1->pos, $1);
}
| returnStmt
{
  $$ = A_Return_Stmt($1->pos, $1);
}
| continueStmt
{
  $$ = A_Continue_Stmt($1->pos, $1);
}
| breakStmt
{
  $$ = A_Break_Stmt($1->pos, $1);
}
| SEMICOLON
{
  $$ = A_Null_Stmt($1->pos);
}
;

callStmt: FnCall SEMICOLON
{
  $$ = A_Fn_Call_Stmt($1->pos, $1);
}
;

returnStmt: RET RightVal SEMICOLON
{
  $$ = A_Return_Stmt($1->pos, $2);
}
;

continueStmt: CONTINUE SEMICOLON
{
  $$ = A_Continue_Stmt($1->pos);
}
;

breakStmt: BREAK SEMICOLON
{
  $$ = A_Break_Stmt($1->pos);
}
;

ifStmt: IF LPAREN BoolExpr RPAREN codeBlock
{
  $$ = A_If_Stmt($1->pos, $3, $5, NULL);
}
| IF LPAREN BoolExpr RPAREN codeBlock ELSE codeBlock
{
  $$ = A_If_Stmt($1->pos, $3, $5, $7);
}
;

whileStmt: WHILE LPAREN BoolExpr RPAREN codeBlock
{
  $$ = A_While_Stmt($1->pos, $3, $5);
}
;


%%

extern "C"{
void yyerror(char * s)
{
  fprintf(stderr, "%s\n",s);
}
int yywrap()
{
  return(1);
}
}