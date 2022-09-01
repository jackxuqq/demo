package main

import (
	"fmt"
	_ "sync"
	"time"
)

func main() {
	ch := make(chan int, 10) //创建一个无缓存channel

	//新建一个goroutine
	go func() {
		time.Sleep(time.Second * 1)
		for i := 0; i < 5; i++ {
			ch <- i //往通道写数据
		}
		time.Sleep(time.Second * 3)
		ch <- 99
	}()

	go func() {
		ch <- 10000
	}()

	time.Sleep(time.Second * 6)
	close(ch)
	for i := range ch {
		fmt.Println("num = ", i)
	}
}
