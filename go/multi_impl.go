package main

import (
	"fmt"
)

type PersonR struct {
	name string
}

func (p *PersonR) do() {
	fmt.Printf("read only do method\n")
}

type PersonW struct {
	name string
}

func (p *PersonW) do() {
	fmt.Printf("wrire only do method\n")
}

type Person struct {
	PersonR
	PersonW
}

func main() {
	p := Person{}
	p.do()
}
