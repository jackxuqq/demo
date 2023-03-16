#include<iostream>
#include<string>
#include<map>
#include "dispatch.h"
#include "demo.pb.h"
using namespace std;

int main(int c, char** v){
	string input("{\"num1\":1,\"num2\":2}");
	string output;
	string cmd = "Add";

	dispatch(cmd, input, output);
	printf("input[%s] output[%s]\n", input.c_str(), output.c_str());
	return 0;
}

/*
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
	demo::AddReq req2;
	string json2("{\"num1\":1,\"num2\":2}");
	json_to_proto(json2, req2);
	printf("req.num1=%d req.num2=%d\n", req2.num1(), req2.num2());
}
*/
