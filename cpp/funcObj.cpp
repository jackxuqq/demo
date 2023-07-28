#include <functional>
#include <iostream>

// test function object

// function container
int add(int a, int b)
{
    return a + b;
}

int addTree(int a, int b, int c)
{
    auto ret = a + b+ c;
    std::cout << "add ret:" << ret << std::endl;
    return ret;
}

class Add{
public:
    int operator()(int a, int b)
    {
        return a+b;
    }
};
typedef int(*AddPtr)(int,int);

// func obj for call back
void case1()
{
    class ABC
    {
        public:
            void proc(int a, int b, std::function<void(void)> cb)
            {
                //some logic process with a and b
                if (cb)
                {
                    //std::cout << "call cb func ret:" <<  cb(a, b) << std::endl;
                    cb();
                    std::cout << "call cb func" << std::endl;
                }
            }
    };

    // create function list begin
    ABC abc;
    std::vector<std::function<void()>> funcs;
    {
        // include func
        funcs.push_back([](){
            std::cout << "add ret:" << add(1,1) << std::endl;
        });

        // include func ptr
        AddPtr p;
        p = &add;
        funcs.push_back([=](){
            std::cout << "add ret:" << p(1,2) << std::endl;
        });

        // include fake func
        Add addInstance;
        funcs.push_back([=]()mutable{
            std::cout << "add ret:" << addInstance(1,3) << std::endl;
        });

        // include lambda expr
        funcs.push_back([](){
            auto c = 1 + 4;
            std::cout << "add ret:" << c << std::endl;
            return c;
        });

        // include bind expr
        auto temp = [](){
           auto bf =  std::bind(addTree, 1, 5, 0);
           bf();
        };
        funcs.push_back(temp);
    }
    // create function list end

    for (auto& func : funcs)
    {
        abc.proc(1, 2, func);
    }
}

int main()
{
    case1();
}
