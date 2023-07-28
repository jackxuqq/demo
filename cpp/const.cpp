#include <iostream>
#include <string>
#include <cstring>


void func1(const char** const p)
{
	*p = "ABC";
}

void func2(char ** p)
{
	*p = new char[10];
	memset(*p, 0, 10);
	strcpy(*p, "ABC");
}

int main()
{
    std::string str = "abc";
	const char* p;
	func1(&p);
	//coredump below
	//strcpy((char*)p, "abc");

	char* q;
	func2(&q);
	strcpy(q, "abc");
	std::cout << "q = " << q << std::endl;
}
