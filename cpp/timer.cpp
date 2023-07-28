#include <unistd.h>
#include <functional>
#include <chrono>
#include <thread>
#include <atomic>
#include <memory>
#include <mutex>
#include <condition_variable>
#include <iostream>

class Timer
{
public:
    Timer(): m_expired(false)
    {}

    Timer(const Timer& timer)
    {
        m_expired = timer.m_expired.load();
    }

    ~Timer()
    {
    }

    #if 0
    void start(int interval)
    {
        std::thread t([this, interval]() {
            std::unique_lock<std::mutex> locker(m_mutex);
            m_expired_cond.wait_for(locker, std::chrono::milliseconds(interval), [this] {return (m_expired == true);});
            m_expired = true;
            std::cout << "child thread done" << std::endl;
        });
        t.detach();
    }
    #endif
    /*milli second*/
    void start(int interval)
    {
        std::thread t([this,interval]()->void {
            usleep(interval * 1000);
            m_expired.store(true);
        });
        t.detach();
    }

    void stop()
    {
        m_expired.store(true);
    }

    bool isExpired()
    {
        return m_expired.load();
    }

private:
    std::atomic<bool> m_expired; // timer stopped status
};


void func()
{
    Timer  t;
    t.start(200000);
    //main thread
    for(auto i = 0; ; ++i)
    {
        if (t.isExpired() == true)
        {
            std::cout << "time up cancel" << std::endl;
            break;
        }
        usleep(100000);
        if (i >= 10)
        {
            std::cout << "work over done" << std::endl;
            t.stop();
            break;
        }
    }
}

int main()
{
    func();
    return 0;
}

