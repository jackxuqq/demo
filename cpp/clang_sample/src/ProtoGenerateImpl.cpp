#include "ProtoGenerateImpl.hpp"

using namespace rapidjson;

int ProtoGenerateImpl::procCommFunc(const std::string& funcName)
{
    ApiParamTypeDescArr params;
    ApiParamTypeDescDict group;

    //step1: parse func params.
    RET_IF_ERR(_parseParams,funcName);

    //step2: group params by attribute, and append default param.
    _groupParams();

    //step3: construct proto request define
    _constructReq();

    //step4: construct proto response define
    _constructRsp();

    //step5: construct proto interface define
    _constructIfc();

    return 0;
}

int ProtoGenerateImpl::_parseParams(const std::string& funcName)
{
    //assign m_params from m_doc
    Document& doc = *m_doc;

    RET_IF_FETCH_ARR_ERR(doc, "inner", inner, -1);

    for (auto i = 0; i < inner->Size(); ++i)
    {
        const rapidjson::Value& obj = (*inner)[i];

        RET_IF_FETCH_STR_ERR(obj, "kind", kind, -2);

        if (kind != AST_KIND_FUNC)
        {
            continue;
        }

        RET_IF_FETCH_STR_ERR(obj, "name", fName, -3);

        if (fName != funcName)
        {
            continue;
        }

        RET_IF_FETCH_ARR_ERR(obj, "inner", funcInner, -4);

        for (auto c = 0; c < funcInner->Size(); ++c)
        {
            auto& fobj = (*funcInner)[c];

            RET_IF_FETCH_STR_ERR(fobj, "kind", fkind, -5);

            if (fkind != AST_KIND_PARAM)
            {
                continue;
            }

            RET_IF_FETCH_STR_ERR(fobj, "name", paramName, -6);

            RET_IF_FETCH_OBJ_ERR(fobj, "type", typeObj, -7);

            RET_IF_FETCH_STR_ERR(*typeObj, "qualType", qualType, -8);

            //to ApiParamTypeDesc
            ApiParamTypeDesc param;

            if (NativeType::isNative(qualType))
            {
                param.init(NativeType::convert(qualType), "", paramName);
            }
            else
            {
                param.init(FieldTypeCustom, qualType, paramName);
            }

            auto ret = param.makeDeps(doc);

            if (ret != 0)
            {
                return ret;
            }

            this->m_params.push_back(param);
        }

        return 0;
    }

    return -100;
}

void ProtoGenerateImpl::_groupParams()
{
    //assign m_group from m_params
    return;
}

void ProtoGenerateImpl::_constructReq()
{
    //assign m_pbRequest from m_group[ApiParamTypeDescGroupIn]
    return;
}

void ProtoGenerateImpl::_constructRsp()
{
    //assign m_pbResponse from m_group[ApiParamTypeDescGroupOut]
    return;
}

void ProtoGenerateImpl::_constructIfc()
{
    //assign m_pbInterface from m_pbRequest and m_pbResponse
    return;
}

void ProtoGenerateImpl::printAll()
{
    std::cout << "total " << m_params.size() << " params:\n";
    for (auto i = 0; i < m_params.size(); ++i)
    {
        if (i != 0)
        {
            std::cout << "----------------------------------------" << std::endl;
        }
        m_params[i].print();
    }
}

int ProtoGenerateImpl::procMemFunc(const std::string& className, const std::string& funcName)
{
    //not implement
    return 0;
}
