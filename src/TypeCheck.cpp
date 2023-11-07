#include "TypeCheck.h"
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <iostream>

// maps to store the type information. Feel free to design new data structures if you need.
typeMap g_token2Type; // global token ids to type
typeMap funcparam_token2Type; // func params token ids to type
typeMap func2retType;

paramMemberMap func2Param;
paramMemberMap struct2Members;

std::unordered_map<std::string, std::string> funcDecl;

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
        case A_programFnDeclStmtKind:
            check_VarDecl(out, ele->u.varDeclStmt);
            break;
        case A_programFnDefKind:
            check_FnDef(out, ele->u.fnDef);
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
    string name = *(fd->id);   
    /*  
        write your code here
        Hint: you may need to check if the function is already declared
    */
    check_mulParaNames(out, fd->paramDecl->varDecls);
    check_typeValid(out, fd->type);
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
    /*  
        write your code here 
        Hint: you may pay attention to the function parameters, local variables and global variables.
    */
    string name = *(fd->fnDecl->id);
    if (funcDecl.find(name) == funcDecl.end()){
        check_multiDecl(out, name, fd->pos);
        check_FnDecl(out, fd->fnDecl);
        func2Param[name] = fd->fnDecl->paramDecl->varDecls;
        funcDecl[name] = "func_def";
        func2retType[name] = fd->fnDecl->type;
    }
    else if (funcDecl[name] == "func_def")
    {
        check_FnDecl(out, fd->fnDecl);
        auto curList = fd->fnDecl->paramDecl->varDecls;
        auto prevList = func2Param[name];
        for (int i = 0; i < curList.size(); i++)
        {
            auto curNode = getVarDeclType(curList[i]);
            auto prevNode = getVarDeclType(prevList[i]);
            if (getVarDeclName(curList[i]) != getVarDeclName(prevList[i]))
            {
                error_print(out, curNode->pos, "The variable name is not the same as func declaration!");
            }
            if (check_aATypeSame(curNode, prevNode) == false)
            {
                error_print(out, curNode->pos, "The variable type is not the same as func declaration!");
            }
        }
        auto curReturnType = fd->fnDecl->type;
        auto prevReturnType = func2retType[name];
        if (check_aATypeSame(curReturnType, prevReturnType) == false)
        {
            error_print(out, curReturnType->pos, "The return variable type is not the same as func declaration!");
        }
        funcDecl[name] = "func_def";
        for (auto i : fd->fnDecl->paramDecl->varDecls)
        {
            func2Param[name].push_back(i);
        }
    }
    else if (funcDecl[name] == "func_def")
    {
        error_print(out, fd->pos, "Multiple func definition!");
    }

    
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


aA_type check_ArrayExpr(std::ostream* out, aA_arrayExpr ae){
    if(!ae)
        return nullptr;
    /*
        Example:
            a[1] = 0;
        Hint:
            check the validity of the array index
    */
    string arrName = *(ae->arr);
    aA_type arrType = idToType(out, ae->pos, arrName);
    if(arrType == nullptr)
        error_print(out, ae->pos, "Array name is not declared");
    if (arrType->is_array == false)
        error_print(out, ae->pos, "This variable " + arrName + " is a scalar type!");
    switch (ae->idx->kind){
        case (A_indexExprKind::A_numIndexKind):
        {
            aA_type retType = new aA_type_;
            retType->cur_scope = arrType->cur_scope;
            retType->is_array = false;
            retType->pos = arrType->pos;
            retType->type = arrType->type;
            retType->u = arrType->u;
            return retType;
        }
        break;
        case (A_indexExprKind::A_idIndexKind):
        {
            string bTypeName = *(ae->idx->u.id);
            aA_type bType = idToType(out, ae->idx->pos ,bTypeName);
            if (bType == nullptr)
                error_print(out, ae->idx->pos, "The name of the val in array brackets here is not declared!");
            if (bType->is_array == true)
                error_print(out, ae->idx->pos, "The name of the val in array brackets here is an array!");
            if (bType->type == A_dataType::A_structTypeKind)
                error_print(out, ae->idx->pos, "The name of the val in array brackets here is a struct!");
            aA_type retType = new aA_type_;
            retType->cur_scope = arrType->cur_scope;
            retType->is_array = false;
            retType->pos = arrType->pos;
            retType->type = arrType->type;
            retType->u = arrType->u;
            return retType;
        }

    }
    return nullptr;
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


aA_type check_BoolExpr(std::ostream* out, aA_boolExpr be){
    if(!be)
        return nullptr;
    switch (be->kind)
    {
    case A_boolExprType::A_boolBiOpExprKind:
        aA_type type1 = check_BoolExpr(out,be->u.boolBiOpExpr->left);
        aA_type type2 = check_BoolExpr(out,be->u.boolBiOpExpr->right);
        if(check_aATypeSame(getBoolType(),type1) == false)
                error_print(out,be->pos,"left val type and bool not same!");
        if(check_aATypeSame(getBoolType(), type2) == false)
            error_print(out,be->pos,"right val type and bool not same");
        aA_type retType = new aA_type_;
        retType->is_array=false;
        retType->is_bool=true;
        retType->pos=be->pos;
        return retType;
    case A_boolExprType::A_boolUnitKind:
        aA_type type1 = check_BoolUnit(out, be->u.boolUnit);
        if(check_aATypeSame(getBoolType(), type1)==false)
            error_print(out, be->pos, "val type and bool not same");
        return type1;
    default:
        break;
    }
    return nullptr;
}


aA_type check_BoolUnit(std::ostream* out, aA_boolUnit bu){
    if(!bu)
        return nullptr;
    switch (bu->kind)
    {
        case A_boolUnitType::A_comOpExprKind:{
            aA_type exprUnit1 = check_ExprUnit(out,bu->u.comExpr->left);
            aA_type exprUnit2 = check_ExprUnit(out,bu->u.comExpr->right);
            if(check_aATypeSame(exprUnit1,getIntType()) == false)
                error_print(out,bu->u.comExpr->left->pos,"Left expr type not int!");
            if(check_aATypeSame(exprUnit2,getIntType()) == false)
                error_print(out, bu->u.comExpr->right->pos, "Right expr type not int!");
            aA_type retType = new aA_type_;
            retType->is_array = false;
            retType->is_bool = true;
            retType->pos = bu->pos;
            return retType;
        }
        case A_boolUnitType::A_boolExprKind:
            return check_BoolExpr(out,bu->u.boolExpr);
        case A_boolUnitType::A_boolUOpExprKind:
            return check_BoolUnit(out,bu->u.boolUOpExpr->cond);
        default:
            break;
    }
    return nullptr;
}


aA_type check_ExprUnit(std::ostream* out, aA_exprUnit eu){
    // validate the expression unit and return the aA_type of it
    // you may need to check if the type of this expression matches with its 
    // leftvalue or rightvalue, so return its aA_type would be a good way. 
    // Feel free to change the design pattern if you need.
    if(!eu)
        return nullptr;
    aA_type ret = nullptr;
    switch (eu->kind)
    {
        case A_exprUnitType::A_idExprKind:{
            string name = *(eu->u.id);
            auto t = idToType(out,eu->pos,name);
            if (t == nullptr)
                error_print(out, eu->pos, name + " not found");
            return t;
        }
            break;
        case A_exprUnitType::A_numExprKind:{
            ret = new aA_type_;
            ret->is_array = false;
            ret->pos = eu->pos;
            ret->type = A_dataType::A_nativeTypeKind;
            ret->u.nativeType = A_nativeType::A_intTypeKind;
            return ret;
        }
            break;
        case A_exprUnitType::A_fnCallKind:{
            aA_type fnRetType = check_FnCall(out,eu->u.callExpr);
            if(check_aATypeSame(getIntType(),fnRetType) == false){
                error_print(out,eu->pos, "The func return type is not compatible with expr Unit");
            }
            return fnRetType;
        }
            break;
        case A_exprUnitType::A_arrayExprKind:{
            return check_ArrayExpr(out,eu->u.arrayExpr);
        }
            break;
        case A_exprUnitType::A_memberExprKind:{
            return check_MemberExpr(out,eu->u.memberExpr);
        }
            break;
        case A_exprUnitType::A_arithExprKind:{
            return check_arithExprValValid(out,eu->u.arithExpr);
        }
            break;
        case A_exprUnitType::A_arithUExprKind:{
            return check_ExprUnit(out,eu->u.arithUExpr->expr);
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

void check_multiDecl(std::ostream *out, string name, A_pos pos){
    if (g_token2Type.find(name) != g_token2Type.end())
    {
        error_print(out, pos, name + " dplicates with global variable");
    }
    // struct
    if (struct2Members.find(name) != struct2Members.end())
    {
        error_print(out, pos, name + " dplicates with struct variable");
    }
    if (funcDecl.find(name) != funcDecl.end())
    {
        error_print(out, pos, name + " dplicates with func name");
    }
    if (funcparam_token2Type.find(name) != funcparam_token2Type.end())
    {
        error_print(out, pos, name + " dplicates with func param");
    }
}

void check_mulParaNames(std::ostream *out, vector<aA_varDecl> varDeclList)
{
    vector<string> paramNames;
    for (auto varDecl : varDeclList)
    {
        check_varDeclValid(out, varDecl);
        string name = getVarDeclName(varDecl);
        for (auto paramName : paramNames)
        {
            if (name == paramName)
            {
                error_print(out, varDecl->pos, "Declared a same variable name!");
            }
        }
        paramNames.push_back(name);
    }
}

void check_typeValid(std::ostream *out, aA_type varType)
{
    if (varType == nullptr)
        return;
    string name = getATypeName(varType);
    if (name != "int" && struct2Members.find(name) == struct2Members.end())
        error_print(out, varType->pos, "Undeclared variable type!");
}

void check_varDeclValid(std::ostream *out, aA_varDecl varDecl)
{
    aA_type varType = getVarDeclType(varDecl);
    check_typeValid(out, varType);
}

bool check_aATypeSame(aA_type a, aA_type b)
{
    if(a->is_bool==true && b->is_bool==true)
        return true;
    else if(a->is_bool==true || b->is_bool==true)
        return false;
    else
    {
        if (a->is_array == b->is_array)
        {
            if (a->type == b->type)
            {
                if (a->type == A_dataType::A_nativeTypeKind)
                    return true;
                else
                {
                    if (*(a->u.structType) == *(b->u.structType))
                        return true;
                    else
                        return false;
                }
            }
            else
                return false;
        }
        else
            return false;
    }

}

string getATypeName(aA_type type)
{
    if(type->type == A_dataType::A_nativeTypeKind){
        return "int";
    }else if (type->type == A_dataType::A_structTypeKind)
    {
        return *(type->u.structType);
    }
    return "nulltype";
}

string getVarDeclName(aA_varDecl x){
    if(!x) 
        return nullptr;
    switch (x->kind)
    {
        
        case (A_varDeclType::A_varDeclArrayKind):
            return *(x->u.declArray->id);
        break;
        case (A_varDeclType::A_varDeclScalarKind):
            return *(x->u.declScalar->id);
        break;
    }
    return "";
}

aA_type getVarDeclType(aA_varDecl x){
    if(x->kind == A_varDeclType::A_varDeclScalarKind){
        x->u.declScalar->type->is_array = false;
        return x->u.declScalar->type;
    }
    else if (x->kind == A_varDeclType::A_varDeclArrayKind)
    {
        x->u.declArray->type->is_array = true;
        return x->u.declArray->type;
    }
    return nullptr;

}

aA_type check_FnCall(std::ostream *out, aA_fnCall fc)
{
    if (!fc)
        return nullptr;
    string fnName = *(fc->fn);
    if(func2retType.find(fnName) == func2retType.end())
        error_print(out,fc->pos,"Cannot find the corresponding func name "+ fnName);
    auto varDeclVec = func2Param[fnName];
    if(varDeclVec.size()!=fc->vals.size())
        error_print(out, fc->pos, "The fn Call stmt's parameters size are not equal to the func declaration's in fn name "+fnName);
    for(int i = 0;i < varDeclVec.size();i++){
        auto varDecl = varDeclVec[i];
        auto rightVal = fc->vals[i];
        if(!check_aATypeSame(getVarDeclType(varDecl), check_rightValValid(out,rightVal))){
            error_print(out, fc->pos, "The " + std::to_string(i) + " th parameter in fnCall doesn't match the one in fn declaration in fn name" + fnName);
        }
    }
    return func2retType[fnName];
}

aA_type check_rightValValid(std::ostream *out, aA_rightVal rightVal)
{
    if(rightVal == nullptr) return nullptr;
    switch (rightVal->kind)
    {
        case (A_rightValType::A_arithExprValKind):
        {
            return check_arithExprValValid(out, rightVal->u.arithExpr);
            break;
        }
        case (A_rightValType::A_boolExprValKind):
        {
            return check_BoolExpr(out,rightVal->u.boolExpr);
            break;
        }
    }
    return nullptr;
}

aA_type check_arithExprValValid(std::ostream *out, aA_arithExpr arithExpr)
{
    if(!arithExpr) 
        return nullptr;
    switch (arithExpr->kind)
    {
    case (A_arithExprType::A_exprUnitKind):
        return check_ExprUnit(out, arithExpr->u.exprUnit);
    }
    return nullptr;
}

aA_type getIntType(){
    aA_type intType = new aA_type_;
    intType->is_array=false;
    intType->type=A_dataType::A_nativeTypeKind;
    return intType;
}