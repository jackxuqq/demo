package main

import "fmt"
import "os"

func append_slice_1(my_s []int) {
	my_s = append(my_s, 1)
	my_s = append(my_s, 2)
	my_s = append(my_s, 3)
	//my_s = append(my_s, 4)
	my_s[0] = 100
	fmt.Println(my_s)
}

func append_slice_2(my_s *[]int) {
	*my_s = append(*my_s, 1)
	*my_s = append(*my_s, 2)
	*my_s = append(*my_s, 3)
	//my_s = append(my_s, 4)
	fmt.Println(*my_s)
}

func append_map_1(my_m map[int]int) {
	my_m[0] = 0
	my_m[1] = 1
	my_m[2] = 2
}

func main() {
	fmt.Println(os.Args[0])
	//test_slice()
	my_s := make([]int, 0, 4)
	my_s = append(my_s, 0)
	append_slice_1(my_s)
	fmt.Println(my_s)
	append_slice_2(&my_s)
	fmt.Println(my_s)

	for i := 0; i < 1; i++ {
		my_m := make(map[int]int)
		append_map_1(my_m)
		fmt.Println(my_m)
	}
}
