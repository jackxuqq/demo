#!/bin/bash
#this script convert  c++ simple api to a proto interface

procFunc()
{
    clang++  -fsyntax-only -Xclang -ast-dump=json ./api_define/api.hpp > api_define/ast.json
    cp ./src/build/astToPB ./
    ./astToPB ./api_define/ast.json $1
    rm -f ./astToPB
    protoc --cpp_out=. --grpc_out=. --plugin=protoc-gen-grpc=/usr/bin/grpc_cpp_plugin proto/api.proto
    #vim -O ./proto/api.proto ./api_define/api.hpp
}

API_FILES=(./api_define/api.hpp)
API_LIST=./apiList.txt

main()
{
    touch ${API_LIST}
    cp /dev/null ${API_LIST}

    for file in ${API_FILES};do
        grep -n  "int [a-z,A-Z,_]\{1,\}(" $file > ./.tmp
        while read line
        do
            #echo $line
            num=`echo $line | awk -F ":" '{print $1}'`
            api=`echo $line | awk -F ":" '{print $2}'|grep -o "[a-z,A-Z,_]\{1,\}("|awk -F "(" '{print $1}'`

            #echo $file
            #echo $num
            #echo $api
            printf "%s %s %s\n" $file $num $api >> ${API_LIST}
        done < ./.tmp
    done
    rm -f ./.tmp

    procFunc ${API_LIST}
}

main
