package main

import (
	"fmt"
)

func main() {
	var whatever [3]struct{}

	//for i := range whatever {
	for i := 0; i < len(whatever); i++ {
		defer func() {
			fmt.Println(i)
		}()
	}
}
