package main

import "fmt"
import "strconv"

type LinkNode struct {
	value int
	next  *LinkNode
}

func CreateLink(arr []int) *LinkNode {
	var tmp []LinkNode = make([]LinkNode, 0, len(arr))
	for i := 0; i < len(arr); i++ {
		var node LinkNode
		node.value = arr[i]
		if len(tmp) > 0 {
			node.next = &(tmp[len(tmp)-1])
		} else {
			node.next = nil
		}
		tmp = append(tmp, node)
	}
	fmt.Println(tmp)
	return &tmp[len(tmp)-1]
}
func PrintLink(head *LinkNode) {
	for ; head != nil; head = head.next {
		fmt.Printf("%d->", head.value)
	}
	fmt.Println("nil")
}

func ReverseLink(head *LinkNode) *LinkNode {
	//add code here
	curr := head
	var tmp *LinkNode
	for {
		if curr == nil {
			return tmp
		}
		if curr.next == nil {
			curr.next = tmp
			return curr
		}
		tmp2 := curr.next
		tmp3 := curr.next.next
		curr.next.next = curr
		curr.next = tmp
		tmp = tmp2
		curr = tmp3
	}
}

func main() {
	var str string
	var arr []int
	fmt.Scanf("%s", &str)
	for i := 0; i < len(str); i++ {
		tmp, _ := strconv.Atoi(string(str[i]))
		arr = append(arr, tmp)
	}
	fmt.Println(arr)
	head := CreateLink(arr)
	PrintLink(head)
	head = ReverseLink(head)
	PrintLink(head)
}
