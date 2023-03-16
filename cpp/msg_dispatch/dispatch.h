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
	virtual ::google::protobuf::Message* CreateReq() = 0;
	virtual ::google::protobuf::Message* CreateRsp() = 0;
};

extern map<string, ModelAPI*> g_func_pool; 

// auto reg ModelAPI
class AutoRegister{
	public:
		AutoRegister(string cmd, ModelAPI* api){
			g_func_pool[cmd] = api;
		}
};

int dispatch(const string& cmd, const string& arg, string& ret);
