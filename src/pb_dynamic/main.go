package main

import (
	"encoding/json"
	"fmt"
	//"github.com/golang/protobuf/protoc-gen-go/descriptor"
	//"github.com/jhump/protoreflect/desc"
	"github.com/golang/protobuf/proto"
	"github.com/jhump/protoreflect/desc/protoparse"
	"github.com/jhump/protoreflect/dynamic"
)

func main() {

	var parser protoparse.Parser
	fileDescriptors, _ := parser.ParseFiles("./test.proto")
	// 因为只有一个文件，所以肯定只有一个 fileDescriptor
	fileDescriptor := fileDescriptors[0]
	msgDesc := fileDescriptor.GetMessageTypes()[0]
	var jsonStr = []byte(`{
		"id": 1234,
		"name": "test_name"
	}`)
	dmsg := dynamic.NewMessage(msgDesc)
	err := json.Unmarshal(jsonStr, &dmsg)
	if err != nil {
		fmt.Printf("Unmarsha1 fail, err:%v, jsonStr:%v\n", err, string(jsonStr))
		return
	}
	fmt.Printf("%+v\n", dmsg)
	data, _ := proto.Marshal(dmsg)
	fmt.Printf("len:%d, data:%v, string:%s\n", len(data), data, string(data))
}
