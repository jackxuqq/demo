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

    /*generate proto from common func*/
    int procCommFunc(const std::string& funcName);

    /*generate proto from member func*/
    int procMemFunc(const std::string& className, const std::string& funcName);

    /*for debug*/
    void printAll();

private:

    /*json format ast*/
    rapidjson::Document* m_doc{nullptr};

    /*contain proto request message define*/
    std::string m_pbRequest;

    /*contain proto reponse message define*/
    std::string m_pbResponse;

    /*contain proto interface define*/
    std::string m_pbInterface;

    /*interface all params desc*/
    ApiParamTypeDescArr m_params;

    /*params group by in or out*/
    ApiParamTypeDescDict m_group;

private:

    // parse func's paramters from json format ast
    int _parseParams(const std::string& funcName);

    // group params to [in]params group and [out]params group, btw add default param like ctx
    void _groupParams();

    // construct request proto message by [in]params group
    void _constructReq();

    // construct response proto message by [out]params group
    void _constructRsp();

    // construct interface by req and rsp
    void _constructIfc();
};
