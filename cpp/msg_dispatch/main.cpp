#include<iostream>
#include<string>
#include<map>
#include "dispatch.h"
#include "demo.pb.h"
using namespace std;
map<string, ModelAPI*> g_func_pool; 

void test(){
	demo::AddReq req;
	req.set_num1(1);
	req.set_num2(2);
	string json;
	if (!proto_to_json(req, json)) {
		printf("proto to json fail\n");
		return;
	}
	printf("%s\n", json.c_str());
}

int main(int c, char** v){
	test();

	auto cmd = "Add";
	printf("in %s\n", __FUNCTION__);
	dispatch(cmd, "{\"num1\":1,\"num\":2}");

	return 0;
}
