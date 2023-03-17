package main

import "fmt"
import "os"
import "io"
import "bufio"
import "net/http"
import "sync"

func main() {

	var wg sync.WaitGroup
	wg.Add(5)
	//read url from file
	f, err := os.Open("./url.txt")
	if err != nil {
		fmt.Println("open fail!")
		return
	}
	url_chan := make(chan string, 10000)
	reader := bufio.NewReader(f)
	for {
		line, _, err := reader.ReadLine()
		if err != nil && err != io.EOF {
			fmt.Println("readline fail")
			return
		}
		if err == io.EOF {
			break
		}
		url_chan <- string(line)
	}
	fmt.Println("len=", len(url_chan))

	max_proc := 5
	for i := 0; i < max_proc; i++ {
		go func() {
			defer func() {
				wg.Done()
			}()
			url := <-url_chan
			rsp, _ := http.Get(url)
			fmt.Println(rsp)
		}()
	}
	wg.Wait()
}
