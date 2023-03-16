
#include "dispatch.h"
#include <google/protobuf/util/json_util.h>
#include "demo.pb.h"
using google::protobuf::util::JsonStringToMessage;

bool proto_to_json(const google::protobuf::Message& message, std::string& json) {
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    options.always_print_primitive_fields = true;
    options.preserve_proto_field_names = true;
    return MessageToJsonString(message, &json, options).ok();
}

bool json_to_proto(const std::string& json, google::protobuf::Message& message) {
    return JsonStringToMessage(json, &message).ok();
}

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
		printf("cmd[%s] not found\n", cmd.c_str());
		return;
	}
	auto api = g_func_pool[cmd];

	//cmd能找到 应该可以从pb文件找到对应的ProtoType
	demo::AddReq req;
	//auto req = DynamicParseFromPBFile("demo.proto", "demo." + cmd + "Req");
	auto rsp = DynamicParseFromPBFile("demo.proto", "demo." + cmd + "Rsp");
	/*
	if (req == NULL) {
		printf("req is null\n");
		return;
	}
	*/
	printf("go here1 arg[%s]\n", arg.c_str());
	//if (json_to_proto(arg, req)){
	if (json_to_proto(arg, req)){
		printf("ParseFromString fail arg[%s] not match pb desc\n", arg.c_str());
		return;
	}
	printf("go here2 req.num1=%d req.num2=%d\n", req.num1(), req.num2());
	//printf("go here2\n");
	api->Proc(&req, rsp);
	printf("go here3\n");
}
