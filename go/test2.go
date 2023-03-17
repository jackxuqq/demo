package main

import "fmt"

func StrAdd(ss1 string, s2 string) string {
	s1 := []byte(ss1)
	flag := 0
	j := len(s1) - 1
	for i := len(s2) - 1; i >= 0 && j >= 0; i, j = i-1, j-1 {
		tmp := int(s1[i]-'0') + int(s2[i]-'0') + flag
		if tmp >= 10 {
			s1[i] = byte('0' + tmp%10)
			flag = 1
		} else {
			s1[i] = byte('0' + tmp)
			flag = 0
		}
	}
	if flag == 1 {
		for ; j >= 0 && flag; j-- {
			tmp := s[j] - '0' + flag
			if tmp >= 10 {
				s[j] = '0' + tmp%10
				flag = 1
			} else {
				s1[j] = '0' + tmp
				flag = 0
			}
		}
		if flag == 1 {
			return "1" + s1
		}
		return s1
	} else {
		return s1
	}
}

/*input 0000
output 0001 0002 0003...*/
func StrIncr(s string) string {
	flag := 0
	for i := len(s) - 1; i >= 0 && flag; i++ {
		tmp := s[i] - '0' + '1' - '0' + flag
		if tmp >= 10 {
			s[i] = '0' + tmp%10
			flag = 1
		} else {
			s[i] = '0' + tmp
			flag = 0
		}
	}
}

func main() {
	var str1, str2 string
	fmt.Scanln(&str1, &str2)
	tmp := make([]byte, len(str2))
	initStr := string(tmp)
	for ; initStr != str2; StrIncr(initStr) {
		str1 = StrAdd(str1)
	}
	fmt.Println(str1)
}
