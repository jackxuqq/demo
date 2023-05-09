#include "ProtoGenerate.hpp"
#include "ProtoGenerateImpl.hpp"

using namespace rapidjson;

ProtoGenerate::ProtoGenerate(rapidjson::Document* doc)
{
    m_impl = new ProtoGenerateImpl(doc);
}

ProtoGenerate::~ProtoGenerate()
{
    delete m_impl;
}

int ProtoGenerate::procCommFunc(const std::string& funcName, const std::string& header, int line)
{
    return m_impl->procCommFunc(funcName, header, line);
}

int ProtoGenerate::procMemFunc(const std::string& className, const std::string& funcName)
{
    return m_impl->procMemFunc(className, funcName);
}

void ProtoGenerate::save()
{
    m_impl->save();
}

void ProtoGenerate::printAll()
{
    m_impl->printAll();
}
