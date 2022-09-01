package lib

import "fmt"

type extField struct {
	ext map[string]string
}

type Info struct {
	col1 int
	Col2 string
	ext  extField
}

func PrintInfo(i *Info) {
	fmt.Printf("col1:%d, col2:%s ext:%+v\n", i.col1, i.Col2, i.ext)
}
