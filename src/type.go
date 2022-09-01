package main

import "fmt"

type PTR_INT_ARR *[]int

type Person struct {
	name string
	age  int
}

func (p *Person) SetAge(age int) {
	p.age = age
}
func (p Person) SetName(name string) {
	p.name = name
}

func main() {

	list := make([]PTR_INT_ARR, 0)
	list = append(list, nil)
	arr := make([]int, 0)
	list = append(list, &arr)
	fmt.Println(list)

	p := Person{}
	p.SetAge(10)
	p.SetName("jjj")
	fmt.Println(p)

}
