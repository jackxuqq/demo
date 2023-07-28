package main

import (
    "container/heap"
    "fmt"
)

type Hp []int

func(h *Hp)Push(v interface{}){
    *h = append(*h, v.(int))
}
func(h *Hp)Pop()interface{}{
    v:=(*h)[len(*h)-1]
    *h=(*h)[:len(*h)-1]
    return v
}
func (h Hp)Less(i,j int)bool{
    return h[i] > h[j]
}
func (h Hp)Len()int{
    return len(h)
}
func (h *Hp)Swap(i,j int){
    (*h)[i],(*h)[j] = (*h)[j],(*h)[i]
}
func main(){
    hp :=Hp{5,3,4}
    heap.Init(&hp)
    heap.Push(&hp,6)
    //hp.Push(7)
    //hp.Push(8)
    for ;hp.Len()>0; {
        fmt.Printf("%d\n", heap.Pop(&hp))
    }
}


/*
type IntHeap []int  // 定义一个类型

func (h IntHeap) Len() int { return len(h) }  // 绑定len方法,返回长度
func (h IntHeap) Less(i, j int) bool {  // 绑定less方法
    return h[i] > h[j]  // 如果h[i]<h[j]生成的就是小根堆，如果h[i]>h[j]生成的就是大根堆
}
func (h IntHeap) Swap(i, j int) {  // 绑定swap方法，交换两个元素位置
    h[i], h[j] = h[j], h[i]
}

func (h *IntHeap) Pop() interface{} {  // 绑定pop方法，从最后拿出一个元素并返回
    old := *h
    n := len(old)
    x := old[n-1]
    *h = old[0 : n-1]
    return x
}

func (h *IntHeap) Push(x interface{}) {  // 绑定push方法，插入新元素
    *h = append(*h, x.(int))
}
func main() {
    h := &IntHeap{}  // 创建slice
    //heap.Init(h)  // 初始化heap
    heap.Push(h, 1)
    heap.Push(h, 4)
    heap.Push(h, 3)
    heap.Push(h, 2)
    //fmt.Println(*h)
    for len(*h) > 0 {
        fmt.Printf("%d ", heap.Pop(h))
    }

}
 */