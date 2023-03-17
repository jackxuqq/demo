package main

import (
	"container/heap"
	"fmt"
	"sort"
)

func main() {
	arr := []int{4, 5, 2, 3, 1}
	topN(arr, 3)

}

type Heap struct {
	sort.IntSlice
}

func (h *Heap) Push(v interface{}) {
	h.IntSlice = append(h.IntSlice, v.(int))
}
func (h *Heap) Pop() interface{} {
	if h.Len() > 0 {
		ret := h.IntSlice[len(h.IntSlice)-1]
		h.IntSlice = h.IntSlice[:len(h.IntSlice)-1]
		return ret
	}
	return -1
}

func topN(nums []int, k int) {
	var h Heap
	heap.Init(&h)
	for i, _ := range nums {
		heap.Push(&h, nums[i])
	}
	for i := 0; i < k; i++ {
		fmt.Printf("%d\n", heap.Pop(&h).(int))
	}
}
