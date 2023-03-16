#include<iostream>
#include<string>
#include<map>
#include "dispatch.h"

using namespace std;

map<string, ModelAPI*> g_func_pool; 


int main(int c, char** v){
	auto cmd = "add";
	printf("in %s\n", __FUNCTION__);
	dispatch(cmd, "diy param");
	return 0;
}
