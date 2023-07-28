#include <iostream>
#include <functional>


void func(int& a)
{
    a+=10;
}

int main()
{
    int a = 100;
    //int& d = std::move(a);
    int&& b = std::move(a);
    std::cout << "b:" << b << std::endl;

    func(b);
    //func(std::move(a));
    std::cout << "b:" << b << std::endl;
}
