#include "Define.hpp"

std::unordered_map<std::string, SimpleType> TypeMapping::m_index{
    {"int",FieldTypeInt32},
    {"long", FieldTypeInt64},
    {"float", FieldTypeFloat},
    {"double", FieldTypeDouble},
    {"char[]", FieldTypeString},
    {"%obj%", FieldTypeCustom},
    {"int[]", FieldTypeInt32Arr},
    {"long[]", FieldTypeInt64Arr},
    {"float[]", FieldTypeFloatArr},
    {"double[]", FieldTypeDoubleArr},
    {"char[][]", FieldTypeStringArr},
    {"%obj%[]", FieldTypeCustomArr}
};

std::unordered_map<SimpleType, std::string> TypeMapping::m_rindex{
    {FieldTypeInt32, "int32"},
    {FieldTypeInt64, "int64"},
    {FieldTypeFloat, "float"},
    {FieldTypeDouble, "double"},
    {FieldTypeString, "string"},
    {FieldTypeCustom, "%obj%"},
    {FieldTypeInt32Arr, "repeated int32"},
    {FieldTypeInt64Arr, "repeated int64"},
    {FieldTypeFloatArr, "repeated float"},
    {FieldTypeDoubleArr, "repeated double"},
    {FieldTypeStringArr, "repeated string"},
    {FieldTypeCustomArr, "repeated %obj%"}
};

/*
    fmt convert
    like:
        char[10] => char[]
        double[10] => double[]
        int * => int
        int ** => int[]
        obj * => obj
        obj ** => obj[]
*/
SimpleType TypeMapping::toSimpleType(const std::string& astType)
{
    std::string tmp;

    if (auto pos = astType.find("["); pos != std::string::npos)
    {
        tmp = astType.substr(0, pos) + "[]";
    }
    else if (auto pos = astType.find("**"); pos != std::string::npos)
    {
        tmp = astType.substr(0, pos) + "[]";
    }
    else if (auto pos = astType.find("*"); pos != std::string::npos)
    {
        tmp = astType.substr(0, pos);
    }
    else
    {
        tmp = astType;
    }

    if (auto itr = m_index.find(tmp); itr != m_index.end())
    {
        return itr->second;
    }

    if (tmp.find("[]") != std::string::npos)
    {
        return FieldTypeCustomArr;
    }

    return FieldTypeCustom;
}

void replace(std::string& src, const std::string& from, const std::string& to)
{
    auto pos = src.find(from);
    if (pos != std::string::npos)
    {
        std::string tmp;
        tmp = src.substr(0, pos);
        tmp += to;
        tmp += src.substr(pos+from.length());
        src = tmp;
    }
}

std::string TypeMapping::toString(SimpleType type, const std::string& origin)
{
    auto tmp = m_rindex[type];

    if (type == FieldTypeCustom || type == FieldTypeCustomArr)
    {
        replace(tmp,"%obj%", origin);
    }

    return tmp;
}


/*
    get origin type from complex type
    like:
        Account[10] => Account
        Person *    => Person
        Bank        => Bank
*/
std::string TypeMapping::getOrigin(SimpleType type, const std::string& astType)
{
    if (type != FieldTypeCustom && type != FieldTypeCustomArr)
    {
        return "";
    }

    int idx = 0;
    for(; idx < astType.length(); ++idx)
    {
        if (astType[idx] == ' ' || astType[idx] == '[')
        {
            break;
        }
    }

    if (idx == astType.length() - 1)
    {
        return astType;
    }

    return astType.substr(0, idx);
}


