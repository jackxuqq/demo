#include <future>
#include <vector>
#include <functional>
#include <thread>
#include <iostream>
#include <chrono>

using namespace std::chrono_literals;
// test for three kind async call in c++11


// use thread
void case1()
{
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
}

int main()
{
    case1();
    case2();
}
