package main

import "fmt"

type One struct {
	col1 int
	col2 string
}

func main() {
	var one One
	one.col1 = 1
	fmt.Println(one)
}
