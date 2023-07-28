package main

import (
    "fmt"
    "sort"
)

type VipInfo struct {
    uid  int64
    Level int8
    Score int64
    expTs int64
}

func main (){
    a := []int{1,3,5,7,9}
    fmt.Printf("ret=%d\n", sort.SearchInts(a, 3))
    fmt.Printf("ret=%d\n", sort.SearchInts(a, 4))
    fmt.Printf("ret=%d\n", sort.SearchInts(a, 10))
    fmt.Printf("ret=%d\n", sort.SearchInts(a, -1))
    fmt.Printf("---------------------------\n")
    var arr []VipInfo
    one := VipInfo{
        uid : 10000,
        Level : 2,
        Score : 1,
    }
    arr = append(arr, one)

    one = VipInfo{
        uid : 10001,
        Level : 2,
        Score : 2,
    }
    arr = append(arr, one)
    one = VipInfo{
        uid : 10002,
        Level : 3,
        Score : 100,
    }
    arr = append(arr, one)
    one = VipInfo{
        uid : 10003,
        Level : 4,
        Score : 200,
    }
    arr = append(arr, one)
    one = VipInfo{
        uid : 10004,
        Level : 5,
        Score : 300,
    }
    arr = append(arr, one)

    target := VipInfo{
        uid : 20001,
        Level : 6,
        Score : 1000,
    }
    fmt.Printf("ret=%d\n", SearchVipInfo(arr, target))
    target2 := VipInfo{
        uid : 20001,
        Level : 2,
        Score : 50,
    }
    fmt.Printf("ret=%d\n", SearchVipInfo(arr, target2))
}

func SearchVipInfo(arr []VipInfo, target VipInfo)int{
    return sort.Search(len(arr), func(i int)bool{
        return arr[i].Score >= target.Score
    })
}