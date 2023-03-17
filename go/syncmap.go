package main

import (
	"fmt"
	"sync"
	"time"
)

func produce(m *sync.Map, wg *sync.WaitGroup) {
	for {
		time.Sleep(1 * time.Second)
		m.Store(time.Now(), "val")
	}
}

func consume(m *sync.Map, wg *sync.WaitGroup) {
	for {
		m.Range(func(keyT, valT interface{}) bool {
			m.Delete(keyT)
			fmt.Printf("consume key[%s] val[%s]\n", keyT, valT)
			return true
		})
		fmt.Println("end loop!")
		time.Sleep(2 * time.Second)
	}
}
func main() {
	sm := &sync.Map{}
	wg := &sync.WaitGroup{}
	wg.Add(1)
	go produce(sm, wg)
	wg.Add(1)
	go consume(sm, wg)
	wg.Wait()
}
