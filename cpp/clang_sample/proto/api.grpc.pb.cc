// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: proto/api.proto

#include "proto/api.pb.h"
#include "proto/api.grpc.pb.h"

#include <functional>
#include <grpcpp/support/async_stream.h>
#include <grpcpp/support/async_unary_call.h>
#include <grpcpp/impl/channel_interface.h>
#include <grpcpp/impl/client_unary_call.h>
#include <grpcpp/support/client_callback.h>
#include <grpcpp/support/message_allocator.h>
#include <grpcpp/support/method_handler.h>
#include <grpcpp/impl/rpc_service_method.h>
#include <grpcpp/support/server_callback.h>
#include <grpcpp/impl/server_callback_handlers.h>
#include <grpcpp/server_context.h>
#include <grpcpp/impl/service_type.h>
#include <grpcpp/support/sync_stream.h>

static const char* ModelEngine_method_names[] = {
  "/ModelEngine/GetPerson",
};

std::unique_ptr< ModelEngine::Stub> ModelEngine::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< ModelEngine::Stub> stub(new ModelEngine::Stub(channel, options));
  return stub;
}

ModelEngine::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options)
  : channel_(channel), rpcmethod_GetPerson_(ModelEngine_method_names[0], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::Status ModelEngine::Stub::GetPerson(::grpc::ClientContext* context, const ::GetPersonReq& request, ::GetPersonRsp* response) {
  return ::grpc::internal::BlockingUnaryCall< ::GetPersonReq, ::GetPersonRsp, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_GetPerson_, context, request, response);
}

void ModelEngine::Stub::async::GetPerson(::grpc::ClientContext* context, const ::GetPersonReq* request, ::GetPersonRsp* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::GetPersonReq, ::GetPersonRsp, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_GetPerson_, context, request, response, std::move(f));
}

void ModelEngine::Stub::async::GetPerson(::grpc::ClientContext* context, const ::GetPersonReq* request, ::GetPersonRsp* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_GetPerson_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::GetPersonRsp>* ModelEngine::Stub::PrepareAsyncGetPersonRaw(::grpc::ClientContext* context, const ::GetPersonReq& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::GetPersonRsp, ::GetPersonReq, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_GetPerson_, context, request);
}

::grpc::ClientAsyncResponseReader< ::GetPersonRsp>* ModelEngine::Stub::AsyncGetPersonRaw(::grpc::ClientContext* context, const ::GetPersonReq& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncGetPersonRaw(context, request, cq);
  result->StartCall();
  return result;
}

ModelEngine::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      ModelEngine_method_names[0],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< ModelEngine::Service, ::GetPersonReq, ::GetPersonRsp, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](ModelEngine::Service* service,
             ::grpc::ServerContext* ctx,
             const ::GetPersonReq* req,
             ::GetPersonRsp* resp) {
               return service->GetPerson(ctx, req, resp);
             }, this)));
}

ModelEngine::Service::~Service() {
}

::grpc::Status ModelEngine::Service::GetPerson(::grpc::ServerContext* context, const ::GetPersonReq* request, ::GetPersonRsp* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

