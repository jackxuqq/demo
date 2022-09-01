package main

import "fmt"

func coinChange(coins []int, amount int) int {
	coin := make(map[int]int)
	res := make(map[int]int)
	for _, v := range coins {
		coin[v] = 1
		res[v] = 1
	}
	return help(coin, amount, res)
}

func help(coin map[int]int, amt int, res map[int]int) (ret int) {
	ret = -1
	/*
		defer func() {
			fmt.Printf("help amt[%d] ret[%d] res[%v]\n", amt, ret, res)
		}()
	*/
	if amt == 0 {
		ret = 0
		return
	}
	if amt < 0 {
		ret = -1
		return
	}
	v, ok := res[amt]
	if ok {
		ret = v
		return
	}
	found := false
	for k, _ := range coin {
		temp := help(coin, amt-k, res)
		if temp == -1 {
			//not found case
			continue
		} else {
			//>=0 case
			if ret == -1 {
				ret = temp + 1
				found = true
			} else {
				if temp+1 < ret {
					ret = temp + 1
					found = true
				}
			}
		}
	}
	if found {
		res[amt] = ret
	}
	return
}

func main() {
	arr := []int{186, 419, 83, 408}
	fmt.Println(coinChange(arr[:], 6249))
}
