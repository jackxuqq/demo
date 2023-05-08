#!/bin/bash
#this script convert  c++ simple api to a proto interface

clang++  -fsyntax-only -Xclang -ast-dump=json api_define/api.hpp > api_define/ast.json
cp ./src/build/astToPB ./
./astToPB ./api_define/ast.json
rm -f ./astToPB
protoc --cpp_out=. --grpc_out=. --plugin=protoc-gen-grpc=/usr/bin/grpc_cpp_plugin proto/api.proto
vim -O ./proto/api.proto ./api_define/api.hpp
