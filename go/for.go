package main

import (
	"fmt"
	"strconv"
)

func main() {
	for i := 1; i < 0; i++ {
		fmt.Printf("loop\n")
	}

	n, _ := strconv.Atoi(" 123")
	fmt.Printf("atoi(\" 123\") = %d\n", n)
}
