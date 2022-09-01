package main

import "fmt"
import "strconv"
import "sort"

func Find(a []int, input int) {
	//add code here
}
func main() {
	var a []int
	var str string
	fmt.Scanf("%s", &str)
	for i := 0; i < len(str); i++ {
		tmp, _ := strconv.Atoi(string(str[i]))
		a = append(a, tmp)
	}
	sort.Ints(a)
	fmt.Println(a)
	fmt.Println("input a number:")
	var input int
	fmt.Scanf("%d", &input)
	Find(a, input)
}
