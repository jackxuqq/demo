#include <iostream>
#include <fstream>
#include <sstream>

#include "ProtoGenerate.hpp"
#include "Utils.hpp"

int main(int c, char** v)
{
    if (c != 3)
    {
        std::cout << v[0]  << "\tast.json apilist.txt" << std::endl;
        exit(-1);
    }

    std::ifstream in(v[1]);
    std::ifstream apiList(v[2]);

    std::stringstream ss;
    ss << in.rdbuf();

    rapidjson::Document doc;
    if (doc.Parse(ss.str().c_str()).HasParseError())
    {
        std::cout << "parse json fail." << std::endl;
        exit(-2);
    }

    ProtoGenerate gen(&doc);

    std::string line;
    while (getline(apiList, line))
    {
        auto arr = StringUtils::split(line);
        if (arr.size() != 3)
        {
            std::cout << "arr.size" << arr.size() << std::endl;
            continue;
        }

        auto header = arr[0];
        int line = atoi(arr[1].c_str());
        auto funcName = arr[2];

        auto ret = gen.procCommFunc(funcName, header, line);
        if (ret != 0)
        {
            std::cout << "ret:" << ret << std::endl;
            exit(-3);
        }
    }
    gen.save();
    gen.printAll();
}
