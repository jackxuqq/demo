#pragma once

#include "Utils.hpp"

struct SimpleStructDesc;
/* describ c++ simple type, like builtin type, struct type*/
struct SimpleTypeDesc
{

    /*get m_type */
    std::string getTypeName();

    /*init private member*/
    void init(ParamType type, const std::string& customTypeName, const std::string& name);

    /*print*/
    void print();

    /*make struct type's dependence type define*/
    int makeDeps(rapidjson::Document& doc);

    /*get m_name*/
    const std::string& getName()
    {
        return m_name;
    }

private:

    /*parse struct define from json*/
    int _parseStruct(rapidjson::Document& doc, const std::string& structName, SimpleStructDesc* ssDesc);

protected:

    /*builtin or custom*/
    ParamType m_type;

    /*builtin or custom*/
    std::string m_customTypeName;

    /*struct's name*/
    std::string m_name;

    /*struct type's dependence*/
    std::vector<SimpleStructDesc> m_deps;
};

struct SimpleStructDesc final
{
    /*for debug*/
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

    /*get m_name*/
    const std::string& getName()
    {
        return m_name;
    }

    /*set m_name*/
    void setName(const std::string& name)
    {
        m_name = name;
    }

    /*get m_fields*/
    std::vector<SimpleTypeDesc>& getFields()
    {
        return m_fields;
    }

    /*append into m_fields*/
    void appendField(const SimpleTypeDesc& field)
    {
        m_fields.push_back(field);
    }

private:

    /*struct name*/
    std::string m_name;

    /*field desc*/
    std::vector<SimpleTypeDesc> m_fields;
};

struct ApiParamTypeDesc :public SimpleTypeDesc
{
    void print()
    {
        std::cout << "\tm_attr:" << m_attr << "\n";
        SimpleTypeDesc::print();
    }

private:

    /*param attr: in or out*/
    ParamAttribute m_attr{ParamAttributrInit};
};

