#include<iostream>
#include<typeinfo>


using namespace std;
class Base {
    public:
    virtual ~Base(){}
    int cnt;
};

class Child :public Base{
    public:
    int cnt2;
};

void proc(Base * p){
    if (typeid(*p) == typeid(Base)) {
        cout << "instance type :" << typeid(*p).name() << endl;
    }else if (typeid(*p) == typeid(Child)) {
        cout << "instance type :" << typeid(*p).name() << endl;
    }
}

int main(){
    Child * c = new Child();
    printf("addr of c =%x\n", c);
    printf("addr of c.cnt =%x\n", &(c->cnt));
    printf("addr of c.cnt2 =%x\n", &(c->cnt2));
    Base* b = c;
    proc(b);
    Base* d = new Base();
    proc(d);
}
