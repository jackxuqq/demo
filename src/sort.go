package main

import "fmt"
import "sort"
import "strconv"

type diy [][]string

func (d diy) Len() int {
	return len(d)
}
func (d diy) Swap(i, j int) {
	d[i], d[j] = d[j], d[i]
}
func (d diy) Less(i, j int) bool {
	var n, m int
	n, _ = strconv.Atoi(d[i][0])
	m, _ = strconv.Atoi(d[j][0])
	return n < m
}

func main() {

	var d diy
	d = append(d, []string{"9", "val"})
	d = append(d, []string{"-1", "val"})
	d = append(d, []string{"105", "val"})
	d = append(d, []string{"3", "val"})
	d = append(d, []string{"2", "val2"})
	d = append(d, []string{"1", "val3"})
	sort.Sort(d)
	fmt.Printf("%+v\n", d)
}
