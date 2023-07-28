package main

import "sync"
import "fmt"
import "time"
import "runtime"

func a(wg sync.WaitGroup) {
	i := 0
	for {
		i++
		if i%10000 == 0 {
			fmt.Println("loop 10000 times.")
		}
	}
	wg.Done()

}
func b() {
	for {
		time.Sleep(1 * time.Second)
		fmt.Println("sleep 1 second.")
	}
}
func main() {
	runtime.GOMAXPROCS(1)
	var wg sync.WaitGroup
	wg.Add(1)
	go a(wg)
	go b()
	wg.Wait()
}
