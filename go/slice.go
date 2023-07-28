package main

import "fmt"

func main() {
	/*
		ss := [][]int{{1, 1, 0, 0, 0}, {1, 1, 0, 0, 0}, {0, 0, 0, 1, 1}, {0, 0, 0, 1, 1}}
		fmt.Println(ss)

		fmt.Println(len(ss))
		fmt.Println(len(ss[0]))

		s := []int{0, 1, 2}
		for i := 0; i < len(s); i++ {
			if s[i] == 1 {
				s = append(s[0:i], s[i+1:]...)
			}
		}
		fmt.Println(s)
	*/
	var s2 []int
	fmt.Printf("len= %d\n", len(s2))
	s2 = append(s2, 1)
	fmt.Println(s2)
	var s3 = []int{0, 1, 0, 2, 0, 3, 0}
	for i := 0; i < len(s3); {
		if s3[i] == 0 {
			s3 = append(s3[:i], s3[i+1:]...)
		} else {
			i++
		}
	}
	fmt.Println(s3)
}
