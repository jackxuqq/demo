package main

import (
	"fmt"
	"sort"
)

func combinationSum4(nums []int, target int) int {
	sort.Ints(nums)
	ret := 0
	dfs(nums, target, &ret)
	return ret
}
func dfs(nums []int, target int, ret *int) {
	for _, v := range nums {
		if target-v == 0 {
			*ret += 1
			return //?
		} else if target-v > 0 {
			dfs(nums, target-v, ret)
		} else {
			return
		}
	}
}
func main() {
	nums := []int{1, 2, 3}
	target := 35
	fmt.Printf("combinationSum4=%d\n", combinationSum4(nums, target))
}
