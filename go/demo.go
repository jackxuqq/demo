package main

import (
	"fmt"
	"strconv"
)

func restoreIpAddresses(s string) []string {
	res := make([]string, 0)
	path := make([]int, 0)
	dfs(s, 0, &path, &res)
	return res
}
func dfs(s string, pos int, path *[]int, res *[]string) {
	//fmt.Printf("path[%v]\n", *path)
	if len(*path) > 4 {
		return
	}
	if pos == len(s) {
		//fmt.Printf("path=[%v]\n", *path)
		if isValidIP(*path, s) {
			*res = append(*res, arrToStr(*path))
		}
		return
	}
	tmp, poses := getValidNum(s, pos)
	for i, _ := range tmp {
		*path = append(*path, tmp[i])
		dfs(s, poses[i], path, res)
		*path = (*path)[0 : len(*path)-1]
	}
}
func arrToStr(path []int) string {
	res := ""
	for _, v := range path {
		if res == "" {
			res = strconv.Itoa(v)
		} else {
			res = res + "." + strconv.Itoa(v)
		}
	}
	return res
}
func getValidNum(s string, pos int) (tmp []int, poses []int) {
	for curr := pos; curr < len(s); curr++ {
		num, _ := strconv.Atoi(string([]byte(s)[pos : curr+1]))
		if num >= 0 && num <= 255 {
			tmp = append(tmp, num)
			poses = append(poses, curr+1)
		} else {
			break
		}
	}
	//fmt.Printf("tmp[%v] poses[%v]\n", tmp, poses)
	return
}

func isValidIP(path []int, s string) bool {
	if len(path) != 4 {
		return false
	}
	tmp := ""
	for _, v := range path {
		tmp += strconv.Itoa(v)
	}
	if len(tmp) != len(s) {
		return false
	}
	return true
}

func main() {
	s := "111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111"
	res := restoreIpAddresses(s)
	fmt.Printf("res=[%v]\n", res)
	return
}
