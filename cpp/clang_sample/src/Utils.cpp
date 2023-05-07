#include "Utils.hpp"

std::unordered_map<std::string, ParamType> NativeType::m_supportType{
    {"int",FieldTypeInt32},
    {"int32",FieldTypeInt32},
    {"int64", FieldTypeInt64},
    {"long", FieldTypeInt64},
    {"long long", FieldTypeInt64},
    {"long long int", FieldTypeInt64},
    {"float", FieldTypeFloat},
    {"double", FieldTypeDouble},
    {"char[]", FieldTypeString}
};
