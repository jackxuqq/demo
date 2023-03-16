#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(int a, int b){
	return a>b;
}
void intSort(){
	vector<int> arr = {1,6,0,4,5};
	//sort(arr.begin(), arr.end(), comp);
	sort(arr.begin(), arr.end(), 
			[](int a, int b)->bool{return a< b;});
	for (int i=0;i<arr.size();i++){
		cout << arr[i] << endl;
	}
}

struct Info {
	string name;
	int age;
	int grade;
	Info(string n, int a, int g){
		this->name = n;
		this->age = a;
		this->grade = g;
	}
};

bool comp2(Info a, Info b){
	if (a.age != b.age) {
		return a.age < b.age;
	}
	return a.grade < b.grade;
}
void infoSort(){
	vector<Info> arr;
	Info a("jack", 18, 3);
	Info b("rose", 18, 2);
	Info c("tom", 19, 1);
	arr.push_back(a);
	arr.push_back(b);
	arr.push_back(c);
	for (auto p=arr.begin();p!=arr.end();p++){
		cout << p->name << "\t"
			<< p->age << "\t"
			<< p->grade << endl;
	}
	sort(arr.begin(), arr.end(), comp2);
	for (auto p=arr.begin();p!=arr.end();p++){
		cout << p->name << "\t"
			<< p->age << "\t"
			<< p->grade << endl;
	}
}

int main(){
	intSort();
	infoSort();
	return 0;
}
