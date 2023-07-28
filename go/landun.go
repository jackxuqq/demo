package main

import "fmt"
import "errors"

func test_err() (err error) {
	ret, err := test_func()
	fmt.Printf("%+v\n", ret)
	return
}

func test_func() (ret int, err error) {
	return -1, errors.New("some error!")
}

func main() {
	err := test_err()
	fmt.Printf("%+v\n", err)
}
