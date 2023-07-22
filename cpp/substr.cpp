#include <iostream>
#include <string>

void func(std::string& str, bool flag)
{
    if (auto pos = str.find("|"); pos != std::string::npos)
    {
        if (flag)
        {
            str = str.substr(0, pos);
        }
        else
        {
            str = str.substr(pos+1);
        }
    }
}

int main()
{
    std::string str = "char*|char**";
    func(str, true);
    std::cout << str << std::endl;

    std::string str2 = "char*|char**";
    func(str2, false);
    std::cout << str2 << std::endl;
    return 0;
}
