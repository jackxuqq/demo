package main

import "time"

type BigObj struct {
	buff [4096000]byte
}

func testCase() {
	m := make(map[int]*BigObj)
	for i := 0; i < 10000; i++ {
		tmp := BigObj{}
		m[i] = &tmp
	}
}

func main() {
	for {
		testCase()
		time.Sleep(time.Second * 1)
	}
}
