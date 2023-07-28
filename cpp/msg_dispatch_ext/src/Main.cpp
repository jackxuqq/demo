#include <iostream>
#include "Dispatch.h"

void usage();

int main()
{
    usage();

    for (;;)
    {
        std::string cmd;
        std::cin >> cmd;
    
        std::string jsonReq;
        std::string jsonRsp;

        if (!constructReq(cmd, &jsonReq))
        {
            std::cout << "cmd [" << cmd << "] not found!" << std::endl;
            continue;
        }

        dispatch(cmd, jsonReq, &jsonRsp);

        std::cout << "jsonReq : [" << jsonReq << "]\n"
            << "jsonRsp : [" << jsonRsp << "]" << std::endl;
    }

}

void usage()
{
    std::cout << "Support Func List:\n";
    for (auto i = 0; i< LENGTH_OF_CMD; ++i)
    {
        std::cout << "\t" << g_cmd[i] << "\n";
    }
    std::cout << std::endl;
}
