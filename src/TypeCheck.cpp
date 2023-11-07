#include "TypeCheck.h"
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <iostream>

// maps to store the type information. Feel free to design new data structures if you need.
typeMap g_token2Type; // global token ids to type
typeMap funcparam_token2Type; // func params token ids to type

paramMemberMap func2Param;
paramMemberMap struct2Members;


// private util functions. You can use these functions to help you debug.
void error_print(std::ostream* out, A_pos p, string info)
{
    *out << "Typecheck error in line " << p->line << ", col " << p->col << ": " << info << std::endl;
    exit(0);
}


void print_token_map(typeMap* map){
    for(auto it = map->begin(); it != map->end(); it++){
        std::cout << it->first << " : ";
        switch (it->second->type)
        {
        case A_dataType::A_nativeTypeKind:
            switch (it->second->u.nativeType)
            {
            case A_nativeType::A_intTypeKind:
                std::cout << "int";
                break;
            default:
                break;
            }
            break;
        case A_dataType::A_structTypeKind:
            std::cout << *(it->second->u.structType);
            break;
        default:
            break;
        }
        std::cout << std::endl;
    }
}


// public functions
// This is the entrace of this file.
void check_Prog(std::ostream* out, aA_program p)
{
    // p is the root of AST tree.
    for (auto ele : p->programElements)
    {
    /*
        Write your code here.

        Hint: 
        1. Design the order of checking the program elements to meet the requirements that funtion declaration and global variable declaration can be used anywhere in the program.

        2. Many types of statements indeed collapse to some same units, so a good abstract design will help you reduce the amount of your code.
    */    
        switch (ele->kind)
        {
        case A_programElementType::A_programFnDeclStmtKind:
            check_VarDecl(out, ele->u.varDeclStmt);
            break;
        
        default:
            break;
        }
    }

    for (auto ele : p->programElements)
    {

    }
    
    for (auto ele : p->programElements)
    {
            
    }

    (*out) << "Typecheck passed!" << std::endl;
    return;
}

std::unordered_map<std::string, std::string> variableTypes; // A map to store variable types
std::unordered_set<std::string> declaredNames; // A set to keep track of declared variable names

// Check if a variable name is already declared
bool isNameDeclared(const std::string& varName) {
    return declaredNames.find(varName) != declaredNames.end();
}

// Check if a variable type is valid
bool isTypeValid(aA_type varType) {
    if (!varType) {
        return false; // No type provided, invalid
    }

    if (varType->u.nativeType == A_nativeType::A_intTypeKind) {
        return true; // Integer type (e.g., 'int') is valid
    }
    return false; // Invalid type by default
}

void check_RightVal(std::ostream* out, aA_rightVal rightVal, aA_type varType) {
    if (!rightVal) {
        *out << "Error: Missing initialization value." << std::endl;
    } else {
        // 根据 A_rightValType 的值来判断 rightVal 的类型
        switch (rightVal->kind) {
            case A_arithExprValKind:
                if (varType && varType->u.nativeType == A_nativeType::A_intTypeKind) {
                    // 处理整数类型初始化
                } else {
                    *out << "Error: Type mismatch. Expected an integer value." << std::endl;
                }
                break;

            default:
                *out << "Error: Unsupported value type." << std::endl;
                break;
        }
    }
}
void check_VarDecl(std::ostream* out, aA_varDeclStmt vd)
{
    // variable declaration statement 
    if (!vd)
        return;
    string name;
    if (vd->kind == A_varDeclStmtType::A_varDeclKind){
        // if declaration only 
        // Example:
        //   let a:int;
        //   let a[5]:int;
        
        /* write your code here*/
        aA_varDecl varDecl = vd->u.varDecl;
        if (varDecl->kind == A_varDeclType::A_varDeclScalarKind) {
            // Handle variable declaration without initialization
            aA_varDeclScalar varDeclScalar = varDecl->u.declScalar;
            
            // Extract type and variable name from varDeclScalar
            aA_type varType = varDeclScalar->type;
            std::string varName = *varDeclScalar->id; // Dereference the std::string*

            // Check if the variable name is unique
            if (isNameDeclared(varName)) {
                *out << "Error: Variable '" << varName << "' is already declared." << std::endl;
            } else {
                declaredNames.insert(varName);

                if (!isTypeValid(varType)) {
                    *out << "Error: Invalid type for variable '" << varName << "'." << std::endl;
                }
            }
        }
        
        else if (vd->kind == A_varDeclType::A_varDeclArrayKind) {
            // Handle array declaration (if needed)
        }

    }
    else if (vd->kind == A_varDeclStmtType::A_varDefKind){
        // if both declaration and initialization 
        // Example:
        //   let a:int = 5;
        
        /* write your code here */
        aA_varDef varDef = vd->u.varDef;
        if (varDef->kind == A_varDefType::A_varDefScalarKind) {
            // Handle variable declaration with initialization
            aA_varDefScalar varDefScalar = varDef->u.defScalar;

            // Extract type, variable name, and initialization expression
            aA_type varType = varDefScalar->type;
            std::string varName = *varDefScalar->id; // Dereference the std::string*
            aA_rightVal initialValue = varDefScalar->val;

            if (isNameDeclared(varName)) {
                *out << "Error: Variable '" << varName << "' is already declared." << std::endl;
            } else {
                declaredNames.insert(varName);

                if (!isTypeValid(varType)) {
                    *out << "Error: Invalid type for variable '" << varName << "'." << std::endl;
                }

                check_RightVal(out, varDefScalar->val, varType);
            }
        }
        else if (varDef->kind == A_varDefType::A_varDefArrayKind) {
            // Handle array declaration with initialization (if needed)
        }
    }
    return;
}


void check_StructDef(std::ostream* out, aA_structDef sd)
{
    if (!sd)
        return;
    // structure definition
    // Example:
    //      struct A{
    //          a:int;
    //          b:int;
    //      }
    
    /* write your code here */
    // Get structure name and fields
     // Get structure name and fields
    std::string structName = *sd->id;
    vector<aA_varDecl> fields = sd->varDecls;

    // Initialize a set to store field names for uniqueness checking
    std::unordered_set<std::string> fieldNames;

    for (aA_varDecl field : fields) {
        if (field->kind == A_varDeclType::A_varDeclScalarKind) {
            aA_varDeclScalar fieldScalar = field->u.declScalar;

            // Get field type and name
            aA_type fieldType = fieldScalar->type;
            std::string fieldName = *fieldScalar->id; // Dereference the std::string*

            // Check if the field name is unique within the structure
            if (fieldNames.count(fieldName) > 0) {
                *out << "Error: Field '" << fieldName << "' is already declared in the structure '" << structName << "'." << std::endl;
            } else {
                fieldNames.insert(fieldName);
            }

            // Check if the field type is valid
            if (!isTypeValid(fieldType)) {
                *out << "Error: Invalid type for field '" << fieldName << "' in the structure '" << structName << "'." << std::endl;
            }
        } else if (field->kind == A_varDeclType::A_varDeclArrayKind) {
            // Handle array declaration (if needed)
            // You can add array-specific type checking here
        }
    }
    
    return;

}

void check_FnDecl(std::ostream* out, aA_fnDecl fd)
{
    // Example:
    //      fn main(a:int, b:int)->int
    if (!fd)
        return;
        
    /*  
        write your code here
        Hint: you may need to check if the function is already declared
    */
    return;
}


void check_FnDeclStmt(std::ostream* out, aA_fnDeclStmt fd)
{
    // Example:
    //      fn main(a:int, b:int)->int;
    if (!fd)
        return;
    check_FnDecl(out, fd->fnDecl);
    return;
}


void check_FnDef(std::ostream* out, aA_fnDef fd)
{
    // Example:
    //      fn main(a:int, b:int)->int{
    //          let c:int;
    //          c = a + b;
    //          return c;
    //      }
    if (!fd)
        return;
    check_FnDecl(out, fd->fnDecl);
    /*  
        write your code here 
        Hint: you may pay attention to the function parameters, local variables and global variables.
    */
    return;
}


void check_CodeblockStmt(std::ostream* out, aA_codeBlockStmt cs){
    if(!cs)
        return;
    switch (cs->kind)
    {
    case A_codeBlockStmtType::A_varDeclStmtKind:
        check_VarDecl(out, cs->u.varDeclStmt);
        break;
    case A_codeBlockStmtType::A_assignStmtKind:
        check_AssignStmt(out, cs->u.assignStmt);
        break;
    case A_codeBlockStmtType::A_ifStmtKind:
        check_IfStmt(out, cs->u.ifStmt);
        break;
    case A_codeBlockStmtType::A_whileStmtKind:
        check_WhileStmt(out, cs->u.whileStmt);
        break;
    case A_codeBlockStmtType::A_callStmtKind:
        check_CallStmt(out, cs->u.callStmt);
        break;
    case A_codeBlockStmtType::A_returnStmtKind:
        check_ReturnStmt(out, cs->u.returnStmt);
        break;
    default:
        break;
    }
    return;
}


void check_AssignStmt(std::ostream* out, aA_assignStmt as){
    if(!as)
        return;
    string name;
    switch (as->leftVal->kind)
    {
        case A_leftValType::A_varValKind:{
            /* write your code here */
        }
            break;
        case A_leftValType::A_arrValKind:{
            /* write your code here */
        }
            break;
        case A_leftValType::A_memberValKind:{
            /* write your code here */
        }
            break;
    }
    return;
}


void check_ArrayExpr(std::ostream* out, aA_arrayExpr ae){
    if(!ae)
        return;
    /*
        Example:
            a[1] = 0;
        Hint:
            check the validity of the array index
    */
}


aA_type check_MemberExpr(std::ostream* out, aA_memberExpr me){
    // check if the member exists and return the tyep of the member
    // you may need to check if the type of this expression matches with its 
    // leftvalue or rightvalue, so return its aA_type would be a good way. Feel 
    // free to change the design pattern if you need.
    if(!me)
        return nullptr;
    /*
        Example:
            a.b
    */
    return nullptr;
}


void check_IfStmt(std::ostream* out, aA_ifStmt is){
    if(!is)
        return;
    check_BoolExpr(out, is->boolExpr);
    for(aA_codeBlockStmt s : is->ifStmts){
        check_CodeblockStmt(out, s);
    }
    for(aA_codeBlockStmt s : is->elseStmts){
        check_CodeblockStmt(out, s);
    }
    return;
}


void check_BoolExpr(std::ostream* out, aA_boolExpr be){
    if(!be)
        return;
    switch (be->kind)
    {
    case A_boolExprType::A_boolBiOpExprKind:
        /* write your code here */
        break;
    case A_boolExprType::A_boolUnitKind:
        check_BoolUnit(out, be->u.boolUnit);
        break;
    default:
        break;
    }
    return;
}


void check_BoolUnit(std::ostream* out, aA_boolUnit bu){
    if(!bu)
        return;
    switch (bu->kind)
    {
        case A_boolUnitType::A_comOpExprKind:{
            /* write your code here */
        }
            break;
        case A_boolUnitType::A_boolExprKind:
            /* write your code here */
            break;
        case A_boolUnitType::A_boolUOpExprKind:
            /* write your code here */
            break;
        default:
            break;
    }
    return;
}


aA_type check_ExprUnit(std::ostream* out, aA_exprUnit eu){
    // validate the expression unit and return the aA_type of it
    // you may need to check if the type of this expression matches with its 
    // leftvalue or rightvalue, so return its aA_type would be a good way. 
    // Feel free to change the design pattern if you need.
    if(!eu)
        return nullptr;
    aA_type ret;
    switch (eu->kind)
    {
        case A_exprUnitType::A_idExprKind:{
            /* write your code here */
        }
            break;
        case A_exprUnitType::A_numExprKind:{
            /* write your code here */
        }
            break;
        case A_exprUnitType::A_fnCallKind:{
            /* write your code here */
        }
            break;
        case A_exprUnitType::A_arrayExprKind:{
            /* write your code here */
        }
            break;
        case A_exprUnitType::A_memberExprKind:{
            /* write your code here */
        }
            break;
        case A_exprUnitType::A_arithExprKind:{
            /* write your code here */
        }
            break;
        case A_exprUnitType::A_arithUExprKind:{
            /* write your code here */
        }
            break;
    }
    return ret;
}


void check_FuncCall(std::ostream* out, aA_fnCall fc){
    if(!fc)
        return;
    // Example:
    //      foo(1, 2);

    /* write your code here */
    return ;
}


void check_WhileStmt(std::ostream* out, aA_whileStmt ws){
    if(!ws)
        return;
    check_BoolExpr(out, ws->boolExpr);
    for(aA_codeBlockStmt s : ws->whileStmts){
        check_CodeblockStmt(out, s);
    }
    return;
}


void check_CallStmt(std::ostream* out, aA_callStmt cs){
    if(!cs)
        return;
    check_FuncCall(out, cs->fnCall);
    return;
}


void check_ReturnStmt(std::ostream* out, aA_returnStmt rs){
    if(!rs)
        return;
    return;
}

