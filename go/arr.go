package main

import "fmt"

func test_var() {
	//var
	var str string = "abc"
	var i int
	var f = 1.23
	g := 123
	fmt.Println("str=", str)
	fmt.Println("i=", i)
	fmt.Println("f=", f)
	fmt.Println("g=", g)
	k, l := 2, 3
	k, l = l, k
	fmt.Println("k=", k, "l=", l)
}

func test_arr() {
	var a [100]int
	fmt.Println(a[0])
	fmt.Println(a[len(a)-1])

	var arr [3]int = [3]int{1, 2, 3}
	for i, v := range arr {
		fmt.Printf("%d %d\n", i, v)
	}
}

func main() {
	//test_var()
	test_arr()
}
