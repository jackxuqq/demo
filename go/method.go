package main

import "fmt"

type Person struct {
	age  int
	name string
}

func (p Person) Name() {
	fmt.Printf("In name addr of p = %p\n", &p)
	fmt.Println(p.name)
}
func (p *Person) Age() {
	fmt.Printf("In Age addr of p = %p\n", p)
	fmt.Println(p.age)
}

func GetName(p Person) {
	p.Name()
}
func GetAge(p *Person) {
	p.Age()
}

func test_1() {
	tmp := Person{100, "jackxu"}
	tmp2 := new(Person)
	tmp2.age = 200
	tmp2.name = "hahaha"
	//go语法糖替程序员自动加了& or  *,注意后者是copy了一个新对象的 而不是仅仅对指针求内容
	fmt.Printf("addr of tmp = %p\n", &tmp)
	tmp.Name()
	tmp.Age()
	tmp2.Name()
	tmp2.Age()

	//当做函数传递时 是否指针必须严格匹配
	GetName(tmp)
	GetName(*tmp2)
	GetAge(&tmp)
	GetAge(tmp2)
}

type Police interface {
	Spy()
	Travel()
}

type FBI struct {
	id   int
	name string
	exp  int
}

func (fbi FBI) Travel() {
	fmt.Println("I am travelling")
}

func (fbi *FBI) Spy() {
	fmt.Println("I am spyying")
	fbi.exp += 10
}

func Live(p Police) {
	p.Spy()
	p.Travel()
}

func Free(p Police) {
}

func test_2() {
	a := FBI{1, "jack", 0}
	a = a
	b := &FBI{2, "tom", 0}
	Live(b)
	//下面这行编译不通过, 因为FBI这个类型没实现police的全部接口 但是*FBI实现了
	//Live(a)

}

func main() {
	test_1()
	test_2()
}
