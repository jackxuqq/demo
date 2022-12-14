package main

import "fmt"

type Human interface {
	Say() string
}

type Man struct {
}

func (m *Man) Say() string {
	return "man"
}

func IsNil(h interface{}) bool {
	return h == nil
}

func main() {
	var a interface{}
	var b *Man
	var c *Man
	var d Human
	var e interface{}
	fmt.Printf("%v \n", a)
	fmt.Println(a)
	fmt.Printf("%v \n", b)
	fmt.Println(a == nil) // (1)
	a = b
	fmt.Printf("%v \n", a)
	e = a
	fmt.Println(a == nil) // (1)
	fmt.Println(e == nil) // (2)
	fmt.Println(a == c)   // (3)
	fmt.Println(a == d)   // (4)
	fmt.Println(c == d)   // (5)
	fmt.Println(e == b)   // (6)
	fmt.Println(IsNil(c)) // (7)
	fmt.Println(IsNil(d)) // (8)
}
