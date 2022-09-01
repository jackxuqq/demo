package main

import (
	"fmt"
	"math"
)

func main() {
	var ret int32
	ret = -1 * (math.MinInt32 + 1)
	fmt.Printf("ret[%d]\n", ret)
	fmt.Printf("min_int[%d]\n", -math.MinInt32)
}
