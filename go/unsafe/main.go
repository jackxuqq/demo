package main

import (
	"fmt"
	"github.com/util"
	"unsafe"
)

func main() {
	i := util.NewInfo(1001, 'M', 18, "")
	fmt.Printf("info = %v\n", *i)
	i.SetAddr("addr v1")
	fmt.Printf("info = %v\n", *i)

	//try modify private field compire fail
	//i.addr = "addr v2"

	//try unsafe package
	fmt.Printf("sizeof i=%d alignof i=%d\n", unsafe.Sizeof(*i), unsafe.Alignof(*i))
	paddr := (*string)(unsafe.Pointer(uintptr(unsafe.Pointer(i)) + 24))
	*paddr = "addr v2"
	fmt.Printf("info = %v\n", *i)
}
