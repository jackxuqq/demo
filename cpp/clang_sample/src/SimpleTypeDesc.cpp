#include "SimpleTypeDesc.hpp"

using namespace rapidjson;

std::string SimpleTypeDesc::getTypeName()
{
    switch(this->m_type)
    {
            case FieldTypeInt32:
                    return  "int32";
            case FieldTypeInt64:
                    return "int64";
            case FieldTypeString:
                    return "string";
            case FieldTypeFloat:
                    return "float";
            case FieldTypeDouble:
                    return "double";
            case FieldTypeCustom:
                    return this->m_customTypeName;
            default:
                    return "";
    }
    return "";
}

void SimpleTypeDesc::init(ParamType type, const std::string& customTypeName, const std::string& name)
{
    m_type = type;
    m_customTypeName = customTypeName;
    m_name = name;
}

int SimpleTypeDesc::parseStruct(Document& doc,const std::string& structName, SimpleStructDesc* desc)
{
    std::string rawStructName = getRawStructName(structName);
    RET_IF_FETCH_ARR_ERR(doc, "inner", inner, -11);

    for (auto i = 0; i < inner->Size(); ++i)
    {
        const rapidjson::Value& obj = (*inner)[i];

        RET_IF_FETCH_STR_ERR(obj, "kind", kind, -12);

        if (kind != AST_KIND_STRUCT)
        {
            continue;
        }

        RET_IF_FETCH_STR_ERR(obj, "name", sName, -13);

        if (sName != rawStructName)
        {
            continue;
        }

        RET_IF_FETCH_ARR_ERR(obj, "inner", structInner, -14);

        for (auto c = 0; c < structInner->Size(); ++c)
        {
            auto& fobj = (*structInner)[c];

            RET_IF_FETCH_STR_ERR(fobj, "kind", fkind, -15);

            if (fkind != AST_KIND_FIELD)
            {
                continue;
            }

            RET_IF_FETCH_STR_ERR(fobj, "name", paramName, -16);

            RET_IF_FETCH_OBJ_ERR(fobj, "type", typeObj, -17);

            RET_IF_FETCH_STR_ERR(*typeObj, "qualType", qualType, -18);

            //to SimpleTypeDesc
            SimpleTypeDesc fieldDesc;
            if (NativeType::isNative(qualType))
            {
                fieldDesc.init(NativeType::convert(qualType), "", paramName);
            }
            else
            {
                fieldDesc.init(FieldTypeCustom, qualType, paramName);
            }
            desc->m_fields.push_back(fieldDesc);
        }
        desc->m_name = rawStructName;
        return 0;
    }

    std::cout << "rawStructName:" << rawStructName << std::endl;
    return -1000;
}

int SimpleTypeDesc::makeDeps(Document& doc)
{
    std::vector<SimpleStructDesc> deps;
    std::unordered_map<std::string, bool> hash;

    if (this->m_type != FieldTypeCustom)
    {
        return 0;
    }

    std::vector<std::string> list{this->m_customTypeName};
    while (!list.empty())
    {
        std::vector<std::string> tmp;
        for (auto& curr : list)
        {
            SimpleStructDesc desc;
            auto ret = parseStruct(doc, curr, &desc);

            if (ret != 0)
            {
                return ret;
            }

            if (hash.find(desc.m_name) == hash.end())
            {
                deps.push_back(desc);
                hash[desc.m_name] = true;
            }
            else
            {
                for (auto itr = deps.begin(); itr != deps.end(); ++itr)
                {
                    if (itr->m_name == desc.m_name)
                    {
                        deps.erase(itr);
                        break;
                    }

                }
                deps.push_back(desc);
            }

            for (auto& field : desc.m_fields)
            {
                if (field.m_type == FieldTypeCustom)
                {
                    tmp.push_back(field.m_customTypeName);
                }
            }
        }
        list = tmp;
    }

    for (auto itr = deps.rbegin(); itr != deps.rend(); ++itr)
    {
        this->m_deps.push_back(*itr);
    }

    return 0;
}

void SimpleTypeDesc::print()
{
    std::cout << "\tm_type:" << getTypeName() << "\n"
        << "\tm_name:" << m_name << std::endl;

    if (m_deps.size() > 0)
    {
        std::cout << "total " << m_deps.size() << " depend:" << std::endl;
    }
    for (auto& desc : m_deps)
    {
        desc.print();
    }
}
