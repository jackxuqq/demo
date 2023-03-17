package main

import (
	"errors"
	"fmt"
)

func foo(e error) {
	e = errors.New("error 1")
}

func main() {
	var e error
	foo(e)
	fmt.Printf("e = %v\n", e)
}
