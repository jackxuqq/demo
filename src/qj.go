package main

import "fmt"

func GetZH(money int, coin_arr []int) int {
	//
	return -1
}

func main() {
	money := 0
	fmt.Scan(&money)
	coin_arr := make([]int, 0)
	coin_num := 0
	fmt.Scan(&coin_num)
	for i := 0; i < coin_num; i++ {
		tmp := 0
		fmt.Scan(&tmp)
		coin_arr = append(coin_arr, tmp)
	}
	fmt.Println(coin_arr)
	fmt.Println(GetZH(money, coin_arr))
}
