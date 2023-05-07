#pragma once

#include "Utils.hpp"

struct SimpleStructDesc;
/* describ c++ simple type, like builtin type, struct type*/
struct SimpleTypeDesc
{
    ParamType m_type;              /*builtin or custom*/
    std::string m_customTypeName;  /*struct's name*/
    std::string m_name;            /*param's name*/
    std::vector<SimpleStructDesc> m_deps;
    std::string getTypeName();

    void init(ParamType type, const std::string& customTypeName, const std::string& name);
    void print();
    int makeDeps(rapidjson::Document& doc);
    int parseStruct(rapidjson::Document& doc, const std::string& structName, SimpleStructDesc* desc);
};

struct SimpleStructDesc
{
    std::string m_name;
    std::vector<SimpleTypeDesc> m_fields;
    void print()
    {
        std::cout << "struct:" << m_name << "{" << std::endl;
        for (auto i = 0; i < m_fields.size(); ++i)
        {
            if (i != 0)
            {
                std::cout << "----------------------------------------" << std::endl;
            }
            m_fields[i].print();
        }
        std::cout << "}" << std::endl;
    }
};

struct ApiParamTypeDesc :public SimpleTypeDesc
{
    ParamAttribute m_attr{ParamAttributrInit};         /*in or out*/
    void print()
    {
        std::cout << "\tm_attr:" << m_attr << "\n";
        SimpleTypeDesc::print();
    }
};

