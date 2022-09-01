package main

import "fmt"
import _ "strconv"

func test() {
	s := "1234"
	for i := 0; i < len(s); i++ {
		fmt.Printf("%T\n", s[i])
	}
}
func main() {
	test()
}
