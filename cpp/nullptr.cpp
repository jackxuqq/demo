#include <iostream>

int main()
{
    char* p = (char*)malloc(1024);
    p = 0;
    if (p == nullptr)
    {
        std::cout << "nullptr eq 0" << std::endl;
    }
    else
    {
        std::cout << "nullptr not eq 0" << std::endl;
    }
}
