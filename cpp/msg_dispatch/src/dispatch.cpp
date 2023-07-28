
#include "dispatch.h"
#include <google/protobuf/util/json_util.h>
#include "demo.pb.h"
using google::protobuf::util::JsonStringToMessage;

#pragma init_reg(lib) //init before common gloable obj
map<string, ModelAPI*> g_func_pool; 

bool _proto_to_json(const google::protobuf::Message& message, std::string& json) {
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    options.always_print_primitive_fields = true;
    options.preserve_proto_field_names = true;
    return MessageToJsonString(message, &json, options).ok();
}

bool _json_to_proto(const std::string& json, google::protobuf::Message& message) {
    return JsonStringToMessage(json, &message).ok();
}

int dispatch(const string& cmd, const string& arg, string& ret){
    if (g_func_pool.find(cmd) == g_func_pool.end()) {
        printf("cmd[%s] not found\n", cmd.c_str());
        return -1;
    }
    auto api = g_func_pool[cmd];

    ::google::protobuf::Message* req;    
    ::google::protobuf::Message* rsp;    
    req = api->CreateReq();
    rsp = api->CreateRsp();
    //printf("go here1 arg[%s]\n", arg.c_str());
    if (!_json_to_proto(arg, *req)){
        printf("json_to_proto fail arg[%s] not match pb desc\n", arg.c_str());
        return -2;
    }

    api->Proc(req, rsp);
    if (!_proto_to_json(*rsp, ret)){
        printf("proto_to_json fail\n");
        return -3;
    }
    return 0;
}

//====================================try dynamic parse pb============================
#if 0
::google::protobuf::Message* _dynamic_parse(const std::string& filename,
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

int dispatch_ext(const string& cmd, const string& arg, string& ret){
    if (g_func_pool.find(cmd) == g_func_pool.end()) {
        printf("cmd[%s] not found\n", cmd.c_str());
        return -1;
    }
    auto api = g_func_pool[cmd];
    auto req = _dynamic_parse("demo.proto", "demo." + cmd + "Req");
    auto rsp = _dynamic_parse("demo.proto", "demo." + cmd + "Rsp");

    if (!_json_to_proto(arg, *req)){
        printf("json_to_proto fail arg[%s] not match pb desc\n", arg.c_str());
        return -2;
    }

    api->Proc(req, rsp);
    if (!_proto_to_json(*rsp, ret)){
        printf("proto_to_json fail\n");
        return -3;
    }
    return 0;
}
#endif
