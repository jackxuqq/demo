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
    int procCommFunc(const std::string& funcName, const std::string& header, int line);

    /*generate proto from member func*/
    int procMemFunc(const std::string& className, const std::string& funcName);

    /*save to a proto file*/
    void save();

    /*for debug*/
    void printAll();

private:

    /*json format ast*/
    rapidjson::Document* m_doc{nullptr};

    /*proto request message define*/
    std::vector<std::string> m_pbRequest;

    /*proto reponse message define*/
    std::vector<std::string> m_pbResponse;

    /*request and resonse dependence message define*/
    std::vector<std::string> m_pbDeps;

    /*proto interface define*/
    std::vector<std::string> m_pbInterface;

    /*interface all params desc*/
    ApiParamTypeDescArr m_params;

    /*params group by in or out*/
    ApiParamTypeDescDict m_group;

private:

    /* parse func's paramters from json format ast*/
    int _parseParams(const std::string& funcName);

    /* group params to [in]params group and [out]params group, btw add default param like ctx*/
    void _groupParams(const std::string& header, int line);

    /* construct request proto message by [in]params group */
    void _constructReqRsp(const std::string& funcName);

    /* construct interface by req and rsp */
    void _constructIfc(const std::string& funcName);

};
