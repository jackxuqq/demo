package main

import (
	"fmt"
	"net/url"
)

func main() {

	url_args := url.Values{}
	url_args.Set("name", "jackxu")
	url_args.Set("age", "98")

	fmt.Printf("%#v\n", url_args)
	fmt.Printf("%#v\n", url_args.Encode())
}
