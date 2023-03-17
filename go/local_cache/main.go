package main

import (
	"fmt"
	"math/rand"
	"strconv"
	"sync"
	"time"

	"github.com/cache"
)

func Worker(gid int, wg *sync.WaitGroup) {
	for i := 0; i < 1000; i++ {
		key := "key" + strconv.Itoa(rand.Intn(10))
		val, err := cache.Get(gid, key)
		fmt.Printf("gid[%d] key[%v], err[%v] val[%v]\n", gid, key, err, val)
		time.Sleep(time.Nanosecond * 10000000)
	}
	wg.Done()
}

/*
func Goid() int {
	defer func() {
		if err := recover(); err != nil {
			fmt.Println("panic recover:panic info:%v", err)
		}
	}()

	var buf [64]byte
	n := runtime.Stack(buf[:], false)
	idField := strings.Fields(strings.TrimPrefix(string(buf[:n]), "goroutine "))[0]
	id, err := strconv.Atoi(idField)
	if err != nil {
		panic(fmt.Sprintf("cannot get goroutine id: %v", err))
	}
	return id
}
*/

func main() {
	var wg sync.WaitGroup

	for i := 0; i < 10; i++ {
		wg.Add(1)
		go Worker(i, &wg)
	}
	wg.Wait()
}
