package main

import "fmt"

func main() {
	fmt.Println("vim-go")
}

func sumSubarrayMins(arr []int) int {
    //迭代过程最小的元素
    minest := 300000
    dp := make([][]int, len(arr))
    dp[0] = []int{arr[0]}
    //存放以a[i]结尾的连续子串的最小值之和
    res := make([]int, len(arr))
    res[0] = arr[0]
    ret := arr[0]
    if arr[0] < minest {
        minest = arr[0]
    }

    for i:=1;i<len(arr);i++{
        currRes := 0
        if arr[i] < minest {
            minest = arr[i]
        }
        if arr[i] >= minest {
            dp[i-1] = append(dp[i-1], arr[i])
            //直接求值
            currRes=res[i-1]+arr[i]
            ret+=currRes
            res[i] = currRes
            dp[i] = d[i-1]
        } else {
            dp[i-1] = append(dp[i-1], arr[i])
            //更新最小值
            for k,v:=range dp[i-1]{
                min := v
                if arr[i] < v {
                    min = arr[i]
                }
                dp[i-1][k] = min
                currRes += min
            }
            ret += currRes
            res[i] = currRes
            dp[i] = dp[i-1]
    }

    return ret % ( 1000000000 + 7 )
}
