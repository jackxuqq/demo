package main

import (
	"fmt"
	"sync"
)

func main() {

	m := map[string]string{
		"a": "1",
		"b": "2",
		"c": "3",
	}

	var wg sync.WaitGroup

	for k, v := range m {
		wg.Add(1)
		go func(val string) {
			defer wg.Done()
			fmt.Printf("%s = %s %s %s\n", k, v, m[k], val)
		}(v)
	}

	wg.Wait()
}
