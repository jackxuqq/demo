#include <iostream>
#include <string>
#include <map>

void dosamething()
{
        std::cout << "call dosamething." << std::endl;
}
class ABC {};

using FP = void (*)();
std::map<std::string, FP> factory;
#define DECLARE_FUNC(func) factory[#func] = func;


class Base
{
public:
    virtual void foo() = 0;
};

class A :public Base
{
public:
    virtual void foo()
    {
        std::cout << "A::foo" << std::endl;
    }
};

class B :public Base
{
public:
    virtual void foo()
    {
        std::cout << "B::foo" << std::endl;
    }
};


void func(Base* p)
{
    std::cout << typeid(*p).name() << std::endl;
}

int main()
{
#if 1
        FP f = dosamething;
        FP g = &dosamething;
        std::cout << "f=" << (void*)f << std::endl;
        std::cout << "g=" << (void*)g << std::endl;
        std::cout << typeid(dosamething).name() << std::endl;
        std::cout << typeid(f).name() << std::endl;
        std::cout << typeid(g).name() << std::endl;
        std::cout << typeid(ABC).name() << std::endl;
#endif
        DECLARE_FUNC(dosamething);
        for (auto curr : factory)
        {
                std::cout << "func_name:" << curr.first << "\tfunc_addr:" << (void*)curr.second << std::endl;
                curr.second();
        }


        A a;
        func(&a);
}
