package main

import "strings"
import "fmt"

func main() {
	str := "xuzewei"
	str2 := "jackxu"
	for _, v := range str2 {
		contain := strings.Contains(str, string(v))
		if contain {
			fmt.Printf("str:%s contain %s\n", str, string(v))
		} else {
			fmt.Printf("str:%s  not contain %s\n", str, string(v))
		}
	}
}
