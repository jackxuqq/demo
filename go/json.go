package main

import (
	"encoding/json"
	"fmt"
)

func test1() {
	testCase := []string{
		`{
		"unknown":123
	}`,
		`{
		"unknown":"abc"
	}`,
		`{
		"unknown":[1,2,3]
	}`,
		`{
		"unknown":["aaa","bbb","ccc"]
	}`,
		`{
		"unknown":{
			"col1":123,
			"col2":"abc"
		}
	}`,
	}

	//test unmarshal
	var objs []interface{}
	for _, v := range testCase {
		var o interface{}
		err := json.Unmarshal([]byte(v),&o)
		fmt.Printf("err[%v] obj[%+v]\n", err, o)
		objs=append(objs, o)
	}

	//test marshal
	for _, v := range objs{
		str,_ := json.Marshal(v)
		fmt.Printf("str[%s]\n", string(str))
	}
}

func main() {
	test1()
}
