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

class StringUtils
{
public:

    /*trim beginning space and tail space*/
    static std::string trim(const std::string& s)
    {
        std::string ret;
        int begin = 0;
        int end = s.length() - 1;
        for (auto i = 0; i < s.length(); ++i)
        {
            if (s[i] == ' ' || s[i] == '\t')
            {
                ++begin;
            }
            else
            {
                break;
            }
        }

        for (auto i = s.length() - 1; i >= 0 && end >= begin; --i)
        {
            if (s[i] == ' ' || s[i] == '\t')
            {
                --end;
            }
            else
            {
                break;
            }
        }

        ret = s.substr(begin, end - begin + 1);
        return ret;
    }


    static std::vector<std::string> split(const std::string& src)
    {
        std::vector<std::string> ret;
        std::string tmp;

        for (auto i = 0; i < src.length(); ++i)
        {
            if (src[i] == ' '|| src[i] == '\t')
            {
                if (tmp.length() > 0)
                {
                    ret.push_back(tmp);
                    tmp = "";
                }
            }
            else
            {
                tmp += src[i];
            }

            if (i == src.length() - 1)
            {
                if (tmp.length() > 0)
                {
                    ret.push_back(tmp);
                }
            }
        }

        return ret;
    }
};

