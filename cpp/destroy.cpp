#include <iostream>
using namespace std;
class Info{
public:
	Info(const string& name){
		_name = name;
	}
	~Info(){
		cout << _name <<  " Destroy!" << endl;
	}
private:
	string _name;
};

void func(){
	Info a("a");
	Info b("b");
}

void func2(){
	Info* c = new Info("c");
	Info* d = new Info("d");
	delete c;
	delete d;
}
int main(){
	func();
	func2();
}
