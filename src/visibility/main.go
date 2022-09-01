package main

import "github.com/lib"

func main() {
	var o lib.Info
	//o.col1 = 1
	o.Col2 = "test string"
	lib.PrintInfo(&o)
}
