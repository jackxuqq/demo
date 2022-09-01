package main

import "fmt"
import "time"

func adder() func(int) int {
	sum := 0
	return func(x int) int {
		//fmt.Println("====",sum,"=====")
		sum += x
		//fmt.Println("====",sum,"=====")
		return sum
	}
}

/*
func main() {
    pos, neg := adder(), adder()
    for i := 0; i < 3; i++ {
        fmt.Println(
            pos(i),
            neg(-2*i),
        )
    }
}
*/
type field struct {
	name string
}

func (p *field) print() {
	fmt.Println(p.name)
}

func main() {
	//case1
	data := []string{"one", "two", "three"}

	// 输出 three three three
	for _, v := range data {
		go func() {
			fmt.Println(v)
		}()
	}
	time.Sleep(1 * time.Second)

	//case 2
	// 输出 one two three 顺序不定
	//data2 := []*field{{"one"}, {"two"}, {"three"}}
	data2 := []*field{&field{"one"}, &field{"two"}, &field{"three"}}
	fmt.Println(len(data2))
	for _, v2 := range data2 {
		go func(f *field) {
			fmt.Printf("%#v\n", *f)
		}(v2)
	}
	time.Sleep(1 * time.Second)
}

/*
func main() {
    x := [3]int{1,2,3}

    func(arr [3]int) {
        arr[0] = 7
        fmt.Println(arr)    // [7 2 3]
    }(x)
    fmt.Println(x)            // [1 2 3]    // 并不是你以为的 [7 2 3]
}
*/
