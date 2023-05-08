#pragma once

#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <sstream>
#include <fstream>

enum SimpleType
{
    FieldTypeInit = 0,
    FieldTypeInt32 = 1,
    FieldTypeInt64 = 2,
    FieldTypeFloat = 3,
    FieldTypeDouble = 4,
    FieldTypeString = 5,
    FieldTypeCustom = 6, //struct

    FieldTypeInt32Arr = 11,
    FieldTypeInt64Arr = 12,
    FieldTypeFloatArr = 13,
    FieldTypeDoubleArr = 14,
    FieldTypeStringArr = 15,
    FieldTypeCustomArr = 16
};

class TypeMapping
{
public:

    static SimpleType toSimpleType(const std::string& astType);

    static std::string toString(SimpleType type, const std::string& origin);

    static std::string getOrigin(SimpleType type, const std::string& astType);

private:

    static std::unordered_map<std::string, SimpleType> m_index;

    static std::unordered_map<SimpleType, std::string> m_rindex;
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

const char* const FOUR_SPACE = "    ";
