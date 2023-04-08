#include <iostream>
#include <string>

//example for https://github.com/AIGMix/AIGCJson
struct In {
	int a;
	int b;
	double c;
};

struct Out {
	int ret;
	std::string msg;
};

struct InExt {
	int a;
	int b;
	double c;

	std::string ext;
	void dosamething(){
		std::cout << "go go go" << std::endl;
	}
};

struct OutExt {
	int ret;
	std::string msg;

	std::string ext;
	void dosamething(){
		std::cout << "go go go" << std::endl;
	}
};

void func(const In& in, Out* out){
	std::cout << in.a << "\t" << in.b << "\t" << in.c << std::endl;
	out->ret = 100;
	out->msg = "OK";
}

int main(){
	InExt in;
	in.a = 100;
	in.b = 200;
	in.c = 8.88;
	in.ext = "ext";
	
	In* p =(In*)&in;

	OutExt out;
	func(*p, (Out*)&out);
	std::cout << "out.ret = " << out.ret << " out.msg = " << out.msg << std::endl;
}
