package main

import "fmt"
import "strconv"
import "sort"

func Find(a []int, input int) {
	fmt.Println(a, input)
	for i, j := 0, len(a)-1; ; {
		if i >= j {
			break
		}
		k := (j + i) / 2
		fmt.Printf("k=%d i=%d j=%d\n", k, i, j)
		if a[k] == input {
			fmt.Printf("found pos[%d]\n", k)
			break
		} else if a[k] < input {
			i = k
		} else {
			j = k
		}
		fmt.Println("loop one")
	}
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
