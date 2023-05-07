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

    int procCommFunc(const std::string& funcName);

    int procMemFunc(const std::string& className, const std::string& funcName);

    void printAll();

private:
    ProtoGenerateImpl* m_impl;
};
