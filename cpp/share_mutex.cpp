#include <iostream>
#include <syncstream>
#include <thread>
#include <string>
#include <mutex>
#include <shared_mutex>

using namespace std;


class Counter
{
    public:
        Counter()
            :m_count(0)
        {}
        void Add(int i)
        {
            unique_lock lock(m_mutex);
            m_count += i;
        }
        int Get()
        {
            shared_lock lock(m_mutex);
            return m_count;
        }
        void Print(int i)
        {
            unique_lock lock(m_mutex);
            cout << "count = " << i << endl;
        }
    private:
        int m_count;
        shared_mutex m_mutex;
};

void procRead(Counter& c)
{
    std::osyncstream bout(std::cout);
    cout << "count=" << c.Get() << endl;
    //c.Print(c.Get());
}

void procWrite(Counter& c,int num)
{
        c.Add(num);
}

int main()
{
        Counter c;
        thread t1(procRead, std::ref(c));
        thread t2(procRead, std::ref(c));
        thread t3(procRead, std::ref(c));
        thread t4(procWrite, std::ref(c), 10);
        thread t5(procRead, std::ref(c));

        t1.join();
        t2.join();
        t3.join();
        t4.join();
        t5.join();

        cout << "thread over" << endl;
        return 0;
}

