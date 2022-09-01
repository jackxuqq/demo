package main

import "fmt"

func f1() (result int) {
	defer func() {
		result++
	}()
	return 0
}

func f2() (r int) {
	t := 5
	defer func() {
		t = t + 5
	}()
	return t
}
func main() {
	fmt.Println(f1())
	fmt.Println(f2())
}
