package main

import (
	"fmt"
)

type List []int

func (l List) Len() int        { return len(l) }
func (l *List) Append(val int) { *l = append(*l, val) }

type Appender interface {
	Append(int)
}
type Lener interface {
	Len() int
}

func CountInto(a Appender, start, end int) {
	for i := start; i <= end; i++ {
		a.Append(i)
	}
}
func LongEnough(l Lener) bool {
	return l.Len()*10 > 42
}
func main() {
	//variable
	var a List
	a.Append(1) //this is a shothand of (&a).Append(1)
	fmt.Printf("%v (len:%d)\n", a, a.Len())
	pb := new(List)
	pb.Append(2)
	fmt.Printf("%v (len:%d)\n", pb, pb.Len())
	//interface
	var lst List
	CountInto(&lst, 1, 10)
	if LongEnough(lst) {
		fmt.Printf(" - lst is long enough\n")
	}
	// A pointer value
	plst := new(List)
	CountInto(plst, 1, 10)
	if LongEnough(plst) {
		fmt.Printf(" - plst is long enough\n")
	}
}
