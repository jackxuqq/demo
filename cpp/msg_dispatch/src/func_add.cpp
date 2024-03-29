#include<iostream>
#include<string>
#include<map>
#include "dispatch.h"
#include "demo.pb.h"

using namespace std;
// model calc api
class FuncAdd :public ModelAPI{
    int Proc(::google::protobuf::Message* req, ::google::protobuf::Message* rsp){
        demo::AddReq* rreq = (demo::AddReq*)req;
        demo::AddRsp* rrsp = (demo::AddRsp*)rsp;
        rrsp->set_ret(rreq->num1() + rreq->num2());
        //printf("add num1=%d num2=%d result=%d\n",  rreq->num1(), rreq->num2(), rrsp->ret());
        return 0;
    }

    ::google::protobuf::Message* CreateReq(){
        return new demo::AddReq;
    }

    ::google::protobuf::Message* CreateRsp(){
        return new demo::AddRsp;
    }
};

// only register obj, without any other use
AutoRegister _reg("Add", new FuncAdd);

