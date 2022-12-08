package main

import (
	"fmt"
	_ "strconv"
)

func test() {
	s := "1234"
	for i := 0; i < len(s); i++ {
		fmt.Printf("%T\n", s[i])
	}
}

func modify(s *string) {
	(*s)[0] = 'a'
}
func main() {
	test()

	s := "1234"
	modify(&s)
	fmt.Printf("s:%s\n", s)
}
