
#include "dispatch.h"

::google::protobuf::Message* DynamicParseFromPBFile(const std::string& filename,
	       		const std::string& classname){
    auto pos = filename.find_last_of('/');
    std::string path;
    std::string file;
    if(pos == std::string::npos) {
        file = filename;
    } else {
        path = filename.substr(0, pos);
        file = filename.substr(pos + 1);
    }

    ::google::protobuf::compiler::DiskSourceTree sourceTree;
    sourceTree.MapPath("", path);
    ::google::protobuf::compiler::Importer importer(&sourceTree, NULL);
    importer.Import(file);
    const ::google::protobuf::Descriptor *descriptor
        = importer.pool()->FindMessageTypeByName(classname);
    if(!descriptor) {
        return NULL;
    }
    ::google::protobuf::DynamicMessageFactory factory;
    const ::google::protobuf::Message *message
        = factory.GetPrototype(descriptor);
    if(!message) {
        return NULL;
    }
    ::google::protobuf::Message* msg = message->New();
    if(!msg) {
        return NULL;
    }
    return msg;
}

void dispatch(string cmd, string arg){
	if (g_func_pool.find(cmd) == g_func_pool.end()) {
		return;
	}
	auto api = g_func_pool[cmd];

	//cmd能找到 应该可以从pb文件找到对应的ProtoType
	printf("go here-1\n");
	auto req = DynamicParseFromPBFile("demo.proto", cmd + "Req");
	printf("go here0\n");
	auto rsp = DynamicParseFromPBFile("demo.proto", cmd + "Rsp");
	printf("go here1\n");
	req->ParseFromString(arg);
	printf("go here2\n");
	api->Proc(req, rsp);
	printf("go here3\n");
	string debug;
       	rsp->SerializeToString(&debug);
	printf("Rsp=%s\n", debug.c_str());
}
