#include <iostream>
#include <fstream>
#include <sstream>

#include "ProtoGenerate.hpp"


int main(int c, char** v)
{
    if (c != 2)
    {
        std::cout << v[0]  << "\tast.json" << std::endl;
        exit(-1);
    }

    std::ifstream in(v[1]);
    std::stringstream ss;
    ss << in.rdbuf();

    rapidjson::Document doc;
    if (doc.Parse(ss.str().c_str()).HasParseError())
    {
        std::cout << "parse json fail." << std::endl;
        exit(-2);
    }

    std::string funcName = "GetPerson";
    ProtoGenerate gen(&doc);
    auto ret = gen.procCommFunc(funcName);
    if (ret != 0)
    {
        std::cout << "ret:" << ret << std::endl;
        exit(-3);
    }
    gen.printAll();
}
