package main

import "fmt"

func q_sort(s []int) {
	if len(s) <= 1 {
		return
	}

	last := 0
	target := s[0]
	pos := len(s) - 1
	for i := 1; i < len(s); i++ {
		if s[i] > target {
			found := false
			for j := pos; j > i; j-- {
				if s[j] <= target {
					s[i], s[j] = s[j], s[i]
					last = i
					found = true
					pos = j - 1
					break
				}
			}
			if found == false {
				break
			}
		} else {
			last = i
		}
	}
	s[0], s[last] = s[last], s[0]
	//第一轮完成
	q_sort(s[0:last])
	if last+1 <= len(s)-1 {
		q_sort(s[last+1:])
	}
}

func main() {

	array := []int{-4, 0, 7, 4, 9, -5, -1, 0, -7, -1}
	fmt.Println(array)
	q_sort(array)
	fmt.Println(array)
	return
}
