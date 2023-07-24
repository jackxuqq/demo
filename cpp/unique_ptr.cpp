#include <iostream>
#include <memory>
using namespace std;

struct Info{
    Info(){
        cout << "construct a info" << endl;
    }
    ~Info(){
        cout << "destrory a info" << endl;
    }
    int notuse;
};

void test1(){
    unique_ptr<int> p(new int(5));
    cout << "p=" << *p << endl;
    unique_ptr<int> p2;
        p2 = move(p);
    cout << "p=" << p << endl;
    cout << "p2=" << *p2 << endl;
    p2.reset();
    cout << "p2=" << p2 << endl;
    p2.reset(new int(50));
    cout << "p2=" << *p2 << endl;

    unique_ptr<Info> p3(new Info());
    cout << "p3=" << p3->notuse << endl;
}


void test2(){
    unique_ptr<Info[]> p(new Info[10]);
    for (int i=0;i<10;i++){
        cout << "notuse=" << p[i].notuse << endl;
    }
    p.reset();
    cout << "p=" << p << endl;
}

int main(){
    test1();
    test2();
}
