#pragma once

#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

enum ParamType
{
    FieldTypeInit = 0,
    FieldTypeInt32 = 1,
    FieldTypeInt64 = 2,
    FieldTypeFloat = 3,
    FieldTypeDouble = 4,
    FieldTypeString = 5,
    FieldTypeCustom = 6 //struct
};

enum ParamAttribute
{
    ParamAttributrInit = 0,
    ParamAttributeIn = 1,
    ParamAttributeOut = 2
};

const char* const  ParamDescGroupIn = "[in]";
const char* const  ParamDescGroupOut = "[out]";
const char* const  AST_KIND_FUNC = "FunctionDecl";
const char* const  AST_KIND_PARAM = "ParmVarDecl";
const char* const AST_KIND_STRUCT = "CXXRecordDecl";
const char* const AST_KIND_FIELD = "FieldDecl";
