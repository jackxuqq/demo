#include <vector>
#include <iostream>

int main()
{
    char* p = new char[0];
    if (p != nullptr)
    {
        std::cout << "p = " << std::hex << (void*)p <<  std::endl;
    }

    int* i =  new int[10];
    std::vector<int> vec(i, i+10);
    for (auto k : vec)
    {
        std::cout << "k = " << k << std::endl;
    }
    return 0;
}
