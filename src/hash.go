package main

import "fmt"

type LinkNode struct {
	key  int
	val  int
	pre  *LinkNode
	next *LinkNode
}

type Hash struct {
	data []*LinkNode
}

func (h *Hash) Insert(key int, value int) {
	idx := key % len(h.data)
	p := h.data[idx]
	var pre *LinkNode
	for ; p != nil; p = p.next {
		pre = p
		if p.key == key {
			p.val = value
			return
		}
	}
	node := LinkNode{
		key: key,
		val: value,
	}
	if pre != nil {
		pre.next = &node
		node.pre = pre
	} else {
		h.data[idx] = &node
	}
}

func (h *Hash) Get(key int) int {
	idx := key % len(h.data)
	if h.data[idx] == nil {
		return -1
	}
	for p := h.data[idx]; p != nil; p = p.next {
		if p.key == key {
			return p.val
		}
	}
	return -1
}

func main() {
	var h Hash
	h.data = make([]*LinkNode, 10)
	h.Insert(1, 10)
	h.Insert(2, 20)
	h.Insert(2, 30)
	h.Insert(4, 40)
	fmt.Printf("go here!\n")
	fmt.Printf("key[%d] = %d\n", 1, h.Get(1))
	fmt.Printf("key[%d] = %d\n", 2, h.Get(2))
	fmt.Printf("key[%d] = %d\n", 3, h.Get(3))
	fmt.Printf("key[%d] = %d\n", 4, h.Get(4))
}
