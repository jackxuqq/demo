#!/bin/bash

clang++  -fsyntax-only -Xclang -ast-dump=json api_define/api.hpp > ./ast.json
cp ./src/build/astToPB ./
./astToPB ./ast.json
