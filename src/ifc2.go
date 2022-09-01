package main

import "fmt"

func printSlice(s interface{}) {
	for i, v := range s.([]interface{}) {
		fmt.Printf("%d %v\n", i, v)
	}
}

func main() {
	s1 := []interface{}{}
	s1 = append(s1, 1)
	s1 = append(s1, 3)
	s1 = append(s1, 5)
	printSlice(s1)
}
