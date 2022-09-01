package main

import (
	"fmt"
	"reflect"
)

func PrintPerson(name string, age int) {
	fmt.Printf("name[%s] age[%d]\n", name, age)
}

type Person struct {
	name string
	age  int
}

func PrintPersonV2(p Person) {
	fmt.Printf("%+v\n", p)
}

func CallFunc(Func interface{}, args []interface{}) {
	defer func() {
		err := recover()
		if err != nil {
			fmt.Printf("CallFunc fail[%v]\n", err)
		}
		return
	}()

	value := reflect.ValueOf(Func)
	if value.Kind() != reflect.Func {
		fmt.Printf("Func is not function\n")
		return
	}
	params := make([]reflect.Type, 0)
	for i := 0; i < value.Type().NumIn(); i++ {
		tmp := value.Type().In(i)
		params = append(params, tmp)
	}
	if len(args) != len(params) {
		fmt.Printf("args number not match\n")
		return
	}
	argVals := make([]reflect.Value, 0)
	for i := 0; i < len(args); i++ {
		switch params[i] {
		/*
			case reflect.TypeOf(int(0)):
				l := args[i].(int)
				argVals = append(argVals, reflect.ValueOf(l))
			case reflect.TypeOf(string("")):
				s := args[i].(string)
				argVals = append(argVals, reflect.ValueOf(s))
		*/
		default:
			//fmt.Printf("unsupport type %s[%s]\n", params[i].Kind(), params[i].Name())
			argVals = append(argVals, reflect.ValueOf(args[i]))
		}
	}
	value.Call(argVals)
}

func main() {
	CallFunc(PrintPerson, []interface{}{"jackxu", "99"})
	p := Person{
		name: "rose",
		age:  18,
	}
	CallFunc(PrintPersonV2, []interface{}{p})
}
