//select 主要用于试着去读取下ch看有无数据，没有也不会被阻塞
package main

import "fmt"
import "time"

func main() {

	ch := make(chan int, 2)

	go func() {
		ch <- 0
		ch <- 1
		for {
			select {
			case ch <- 2:
				fmt.Println("ok")
				close(ch)
				return
			default:
				fmt.Println("chan full")
			}
			time.Sleep(time.Nanosecond * 300000000) //sleep 300ms
		}
	}()

	go func() {
		time.Sleep(time.Second * 1)
		fmt.Println("begin read ch")
		for v := range ch {
			fmt.Println(v)
		}
	}()

	time.Sleep(time.Second * 3)
}
