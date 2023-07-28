#include "ProtoGenerateImpl.hpp"
#include "ParseComment.hpp"

using namespace rapidjson;

int ProtoGenerateImpl::procCommFunc(const std::string& funcName, const std::string& header, int line)
{
    ApiParamTypeDescArr params;
    ApiParamTypeDescDict group;

    /*step1: parse func params*/
    RET_IF_ERR(_parseParams,funcName);

    /*step2: group params by attribute, and append default param*/
    _groupParams(header, line);

    /*step3: construct proto request and response define*/
    _constructReqRsp(funcName);

    /*step4: construct proto interface define*/
    _constructIfc(funcName);

    return 0;
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

            auto simpleType = TypeMapping::toSimpleType(qualType);
            auto originTypeName = TypeMapping::getOrigin(simpleType, qualType);
            param.init(simpleType, originTypeName, paramName);

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

void ProtoGenerateImpl::_groupParams(const std::string& header, int line)
{

    /*TODO: mock logic, first is in second is out */
    /*
    for (auto i = 0; i < m_params.size(); ++i)
    {
        if (i == 0)
        {
            m_params[i].setAttribute(ParamAttributeIn);
        }
        else
        {
            m_params[i].setAttribute(ParamAttributeOut);
        }
    }
    */

    ParseComment pc(header, line);
    pc.procParams();

    for (auto i = 0; i < m_params.size(); ++i)
    {
        auto attr = pc.getAttr(m_params[i].getName());
        m_params[i].setAttribute(attr);
    }

    pc.printf();

    /*assign m_group from m_params*/
    for (auto& p : m_params)
    {
        if (p.getAttribute() == ParamAttributeIn)
        {
            m_group[ParamDescGroupIn].push_back(p);
        }
        else
        {
            m_group[ParamDescGroupOut].push_back(p);
        }
    }

    return;
}

void ProtoGenerateImpl::_constructReqRsp(const std::string& funcName)
{
    auto innerFunc = [&](const std::string& suffix, const char* const groupKey,
                            std::string* params, std::string* deps) -> void {
        static std::unordered_map<std::string, bool> outputFlag;
        std::stringstream ssParams;
        std::stringstream ssDeps;
        int idx = 0;

        ssParams << "message " << funcName <<  suffix <<" {\n";

        /*add default filed ctx first*/
        ssParams << FOUR_SPACE << "OptContext" << " ctx = " << ++idx << ";\n";

        ApiParamTypeDescArr& inParams = m_group[groupKey];

        for (auto& p : inParams)
        {
            /*proc dependence struct*/
            for (auto d : p.getDeps())
            {
                if (auto itr = outputFlag.find(d.getName()); itr != outputFlag.end())
                {
                    /*avoid repeat output */
                    continue;
                }

                ssDeps << "message " << d.getName() << " {\n";
                auto iidx = 0;

                for (auto f : d.getFields())
                {
                    ssDeps << FOUR_SPACE << f.getTypeName() << " " << f.getName() << " = " << ++iidx << ";\n";
                }

                ssDeps << "}\n\n";
                outputFlag[d.getName()] = true;
            }

            ssParams << FOUR_SPACE << p.getTypeName() << " " << p.getName() << " = " << ++idx << ";\n";
        }

        ssParams << "}\n\n";
        *params = ssParams.str();
        *deps = ssDeps.str();
    };

    std::string req, rsp, reqDeps, rspDeps;
    innerFunc("Req", ParamDescGroupIn, &req, &reqDeps);
    innerFunc("Rsp", ParamDescGroupOut, &rsp, &rspDeps);
    m_pbRequest.push_back(req);
    m_pbResponse.push_back(rsp);
    m_pbDeps.push_back(reqDeps);
    m_pbDeps.push_back(rspDeps);
}

void ProtoGenerateImpl::_constructIfc(const std::string& funcName)
{
    std::stringstream ss;
    ss << FOUR_SPACE << "rpc " << funcName << "(" << funcName <<"Req) returns (" << funcName << "Rsp){}\n";
    m_pbInterface.push_back(ss.str());
    return;
}

void ProtoGenerateImpl::save()
{
    std::ofstream out("./proto/api.proto");

    out << "syntax = \"proto3\";\n\n";
    out << "message OptContext{\n"
        << FOUR_SPACE << "string m_userId = 1;\n"
        << FOUR_SPACE << "string m_modelId = 2;\n"
        << "}\n\n";

    for (auto& dep : m_pbDeps)
    {
        out << dep;
    }

    for (auto& req : m_pbRequest)
    {
        out << req;
    }

    for (auto& rsp : m_pbResponse)
    {
        out << rsp;
    }

    out << "service ModelEngine {\n";

    for (auto& ifc : m_pbInterface)
    {
        out << ifc;
    }

    out  << "}" << std::endl;
}

int ProtoGenerateImpl::procMemFunc(const std::string& className, const std::string& funcName)
{
    //not implement
    return 0;
}
