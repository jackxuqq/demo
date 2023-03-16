#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>

#include <google/protobuf/message.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/descriptor.pb.h>
#include <google/protobuf/dynamic_message.h>
#include <google/protobuf/compiler/importer.h>
using namespace std;

class ModelAPI{
	public:
	virtual int Proc(::google::protobuf::Message* req, ::google::protobuf::Message* rsp) = 0;
};

extern map<string, ModelAPI*> g_func_pool; 


class AutoRegister{
	public:
		AutoRegister(string cmd, ModelAPI* api){
			g_func_pool[cmd] = api;
		}
};

void dispatch(string cmd, string arg);
