package main

import (
	"fmt"
	"runtime"
	"time"
)

func init() {
	fmt.Println("Current Go Version:", runtime.Version())
}
func main() {
	runtime.GOMAXPROCS(10)

	count := 10
	for i := 0; i < count; i++ {
		go func() {
			fmt.Printf("[%d]", i)
		}()
	}
	fmt.Println("")
	time.Sleep(3 * time.Second)

	for i := 0; i < count; i++ {
		go func(i int) {
			fmt.Printf("-%d-", i)
		}(i)
	}
	fmt.Println("")
	time.Sleep(3 * time.Second)
}
