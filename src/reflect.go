package main

import (
	"fmt"
	"reflect"
)

/*
func do(val interface{}) {
	switch val.(type) {
	case int32:
		fmt.Printf("int32\n")
	case string:
		fmt.Printf("string\n")
	case []string:
		fmt.Printf("[]string\n")
	default:
		fmt.Printf("unknown type")
	}
}
*/

func do(obj *Person) {
	t := reflect.TypeOf(*obj)
	v := reflect.ValueOf(obj).Elem()
	for i := 0; i < t.NumField(); i++ {
		fmt.Printf("name[%s] tag[%s] json_tag[%s] fuzzy_match[%s] val[%v]\n",
			t.Field(i).Name, t.Field(i).Tag, t.Field(i).Tag.Get("json"), t.Field(i).Tag.Get("fuzzy_match"), v.Field(i).Interface())
		switch v.Field(i).Kind() {
		case reflect.Int32:
			v.Field(i).SetInt(222)
		}
	}
	fmt.Println(obj)
}

type Person struct {
	ID    string   `json:"id" fuzzy_match:"true"`
	Name  string   `json:"name"`
	Age   int32    `json:"age"`
	Email []string `json:"email"`
}

func main() {
	p := &Person{
		ID:   "111",
		Name: "jackxu",
		Age:  100,
	}
	do(p)
	fmt.Println(p)
}
