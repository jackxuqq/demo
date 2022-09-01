package main

import "fmt"

func test() {
	s1 := []int{1, 2, 3, 4, 5}
	s2 := make([]int, len(s1))
	fmt.Println(s2)
	copy(s2, s1)
	fmt.Println(s2)
}
func main() {
	test()
}
