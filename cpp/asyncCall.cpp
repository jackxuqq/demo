#include <future>
#include <vector>
#include <functional>
#include <thread>
#include <iostream>
#include <chrono>

using namespace std::chrono_literals;
// test for three kind async call in c++11

class FormatCase
{
public:
    FormatCase(const std::string& caseName)
        :m_caseName(caseName)
    {
        std::cout << "++++++++++++++++begin[" << m_caseName << "]++++++++++++++++++++" << std::endl;
    }
    ~FormatCase()
    {
        std::cout << "------------------end[" << m_caseName << "]--------------------" << std::endl;
    }
private:
    std::string m_caseName;
};

#define FORMAT_CASE FormatCase _formtObj(__FUNCTION__);
// use thread
void case1()
{
    FORMAT_CASE;
    auto run = [](int& a){
        std::this_thread::sleep_for(1000ms);
        a++;
    };
    int a = 100;
    std::thread t(run, std::ref(a));

    for (auto i = 0; i < 5; i++)
    {
        std::cout << "main thread work 100ms." << std::endl;
        std::this_thread::sleep_for(100ms);
    }
    t.join();
    std::cout << "a:" << a << std::endl;
}

// use packaged_task
void case2()
{
    FORMAT_CASE;
    int a = 200;
    std::packaged_task<int()> task([&]()->int{
        std::this_thread::sleep_for(1000ms);
        a++;
        return a;
    });

    std::future<int> ret = task.get_future();
    std::thread t(std::move(task));

    for (auto i = 0; i < 5; i++)
    {
        std::cout << "main thread work 100ms." << std::endl;
        std::this_thread::sleep_for(100ms);
    }
    std::cout << "ret:" << ret.get() << std::endl;
    t.join();
}

// use promise
void case3()
{
    FORMAT_CASE;
    std::promise<int> expect;
    auto ret = expect.get_future();

    auto lambda = [](std::promise<int>& e){
        //do samething
        std::cout << "worker thread do something." << std::endl;
        for (auto i = 0; i < 10; ++i)
        {
            std::this_thread::sleep_for(100ms);
        }
        e.set_value(301);

        //do samething
        for (auto i = 0; i < 10; ++i)
        {
            std::this_thread::sleep_for(100ms);
        }
        std::cout << "worker thread exit." << std::endl;
    };

    std::thread t(lambda, std::ref(expect));
    auto val = ret.get();
    std::cout << "main thread got result:" << val << std::endl;

    t.join();
    std::cout << "main thread exit." << std::endl;
}

int main()
{
    case1();
    case2();
    case3();
}
