//该程序是想验证 有某些严重异常是无法捕捉的，例如 map并发写、还未加锁就解锁
package main

import "fmt"
import "sync"

var kv = map[string]string{}
var wg sync.WaitGroup
var lock sync.Mutex

func test_case1(syn bool) {
	wg.Add(1)
	go func(wg *sync.WaitGroup) {
		defer func() {
			err := recover()
			if err != nil {
				fmt.Printf("thread1 catch panic:%+v\n", err)
			}
			wg.Done()
		}()
		if syn {
			lock.Lock()
		}
		kv["abc"] = "abc"
		if syn {
			lock.Unlock()
		}
	}(&wg)
	wg.Add(1)
	go func(wg *sync.WaitGroup) {
		defer func() {
			err := recover()
			if err != nil {
				fmt.Printf("thread2 catch panic:%+v\n", err)
			}
			wg.Done()
		}()
		if syn {
			lock.Lock()
		}
		kv["abd"] = "abd"
		if syn {
			lock.Unlock()
		}
	}(&wg)
	wg.Wait()
	fmt.Println(kv)

}

func test_case2(lockFirst bool) {
	if lockFirst {
		lock.Lock()
	}
	lock.Unlock()
}

func main() {
	defer func() {
		err := recover()
		if err != nil {
			fmt.Printf("main catch panic:%+v\n", err)
		}
	}()

	test_case1(true)

	test_case2(false)
}
