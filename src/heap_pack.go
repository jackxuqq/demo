package main

import "container/heap"
import "fmt"

type Person struct {
	id   int
	name string
}

type Persons []Person

func (h *Persons) Push(v interface{}) {
	*h = append(*h, v.(Person))
}

func (h *Persons) Pop() interface{} {
	v := (*h)[len(*h)-1]
	*h = (*h)[:len(*h)-1]
	return v
}

func (h *Persons) Len() int {
	return len(*h)
}

func (h *Persons) Less(i, j int) bool {
	return (*h)[i].id < (*h)[j].id
}

func (h *Persons) Swap(i, j int) {
	(*h)[i], (*h)[j] = (*h)[j], (*h)[i]
}

func main() {
	ps := &Persons{{id: 5, name: "rose"}, {id: 10, name: "tom"}}
	heap.Init(ps)
	one := Person{id: 1, name: "jack"}
	heap.Push(ps, one)
	fmt.Println(*ps)
	for (*ps).Len() > 0 {
		fmt.Printf("%v ", heap.Pop(ps))
	}
	fmt.Println()
}
