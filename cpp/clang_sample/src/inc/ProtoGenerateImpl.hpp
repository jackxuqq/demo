#pragma once
#include "SimpleTypeDesc.hpp"

class ProtoGenerateImpl
{
using  ApiParamTypeDescArr = std::vector<ApiParamTypeDesc>;
using  ApiParamTypeDescDict = std::unordered_map<std::string, std::vector<ApiParamTypeDesc> >;
public:

    ProtoGenerateImpl(rapidjson::Document* doc)
        :m_doc(doc)
    {
    }

    int procCommFunc(const std::string& funcName);

    int procMemFunc(const std::string& className, const std::string& funcName)
    {
        return 0; //not impl
    }

    void printAll()
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

private:

    rapidjson::Document* m_doc{nullptr};

    std::string m_pbRequest;

    std::string m_pbResponse;

    std::string m_pbInterface;

    ApiParamTypeDescArr m_params;

    ApiParamTypeDescDict m_group;

private:

    // parse func's paramters from json format ast
    int parseParams(const std::string& funcName);

    // group params to [in]params group and [out]params group, btw add default param like ctx
    void groupParams();

    // construct request proto message by [in]params group
    void constructReq();

    // construct response proto message by [out]params group
    void constructRsp();

    // construct interface by req and rsp
    void constructIfc();
};
