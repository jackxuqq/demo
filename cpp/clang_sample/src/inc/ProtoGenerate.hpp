#pragma once

#include <string>
#include "rapidjson/document.h"
#include "rapidjson/prettywriter.h"

class ProtoGenerateImpl;

class ProtoGenerate
{
public:

    ProtoGenerate(rapidjson::Document* doc);

    virtual ~ProtoGenerate();

    /*generate proto from common func*/
    int procCommFunc(const std::string& funcName);

    /*generate proto from member func*/
    int procMemFunc(const std::string& className, const std::string& funcName);

    /*for debug*/
    void printAll();

private:
    ProtoGenerateImpl* m_impl;
};
