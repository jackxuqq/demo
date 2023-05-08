#pragma once

#include "Define.hpp"
#include "rapidjson/document.h"
#include "rapidjson/prettywriter.h"

#define RET_IF_ERR(func, param) if (auto ret = func(param); ret != 0) {\
                            return ret;\
                         }

#define JSON_HELPER_BASIC_CHECK(defaultValue) if (!val.IsObject()) {return defaultValue;}\
                                if (!val.HasMember(childName)) {return defaultValue;}

#define RET_IF_FETCH_ARR_ERR(doc, childName, varName, errcode) auto varName = JsonHelper::FetchArray(doc, childName);\
                                                               if (varName == nullptr){return errcode;}
#define RET_IF_FETCH_OBJ_ERR(doc, childName, varName, errcode) auto varName = JsonHelper::FetchObject(doc, childName);\
                                                               if (varName == nullptr){return errcode;}

#define RET_IF_FETCH_STR_ERR(doc, childName, varName, errcode) auto varName = JsonHelper::FetchString(doc, childName);\
                                                               if (varName == ""){return errcode;}

#define CONTINUE_IF_FETCH_STR_ERR(doc, childName, varName) auto varName = JsonHelper::FetchString(doc, childName);\
                                                               if (varName == ""){continue;}

/*rapidjson api helper*/
class JsonHelper
{
public:
    static const rapidjson::Value* FetchObject(const rapidjson::Value& val, const char* childName)
    {
        JSON_HELPER_BASIC_CHECK(nullptr);

        const auto& obj = val[childName];

        if (!obj.IsObject())
        {
            return nullptr;
        }

        return &(val[childName]);
    }

    static const rapidjson::Value* FetchArray(const rapidjson::Value& val, const char* childName)
    {
        JSON_HELPER_BASIC_CHECK(nullptr);

        const auto& obj = val[childName];

        if (!obj.IsArray())
        {
            return nullptr;
        }
        return &(val[childName]);
    }

    static std::string FetchString(const rapidjson::Value& val, const char* childName)
    {
        JSON_HELPER_BASIC_CHECK("");

        const auto& obj = val[childName];

        if (!obj.IsString())
        {
            return "";
        }

        return obj.GetString();
    }

    static double FetchDouble(const rapidjson::Value& val, const char* childName)
    {
        JSON_HELPER_BASIC_CHECK(0.0);

        const auto& obj = val[childName];

        if (!obj.IsDouble())
        {
            return 0.0;
        }

        return obj.GetDouble();
    }
};


class JsonAstUtils
{

public:

    /*
        get origin type from complex type
        like:
            Account[10] => Account
            Person *    => Person
            Bank        => Bank
    */
    static std::string getOrigin(const std::string& name)
    {
        int idx = 0;
        for(; idx < name.length(); ++idx)
        {
            if (name[idx] == ' ' || name[idx] == '[')
            {
                break;
            }
        }

        if (idx == name.length() - 1)
        {
            return name;
        }

        return name.substr(0, idx);
    }

    /*
        fmt char array
        like:
            char[10] => char[]
            char[100] => char[]
    */
    static std::string fmtCharArray(const std::string& type)
    {
        std::string ret;

        if (strstr(type.c_str(), "char[") != NULL)
        {
            ret = "char[]";
        }
        else
        {
            ret = type;
        }
        return ret;
    }
};

class NativeType
{
public:

    /*convert string native type to enum*/
    static ParamType convert(const std::string& type)
    {
        std::string ttype = JsonAstUtils::fmtCharArray(type);

        if (auto itr = m_supportType.find(ttype); itr != m_supportType.end())
        {
            return itr->second;
        }

        return FieldTypeInit;
    }

    static bool isNative(const std::string& type)
    {
        std::string ttype = JsonAstUtils::fmtCharArray(type);

        if (m_supportType.find(ttype) != m_supportType.end())
        {
            return true;
        }
        return false;
    }

private:
    static std::unordered_map<std::string, ParamType> m_supportType;
};
