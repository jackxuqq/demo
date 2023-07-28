#include<iostream>
using namespace std;

class PSBase
{
public:
    virtual void func(const int i = 0)
    {
        cout << "i=" << i << endl;
    }
};

class PSDrived : public PSBase
{
public:
    virtual void func(const int i = 1)
    {
        cout << "child i=" << i << endl;
    }
};

int main()
{
    PSDrived d1;
    PSBase* p = new PSDrived;
    p->func();//期待缺省值
}
