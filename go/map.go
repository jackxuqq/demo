package main

import "fmt"

var m = map[int]int{}

func modify_map_v2(m map[string]int) {
	m = make(map[string]int)
	m["jackxu_v2"] = 200
	fmt.Println(m)
}

func test_map() {

	ages := make(map[string]int)
	ages["jack"] = 40
	ages["lily"] = 18

	/*
		ages := map[string] int {
			"jack":40,
			"lily":18,
		}
	*/
	for name, age := range ages {
		fmt.Println(name, age)
	}
	if ages["not_exist"] == 1 {
		fmt.Println("impossible")
	}
	fmt.Printf("len(map)= %d\n", len(ages))
}

func modify_map(m map[string]int) {
	m = make(map[string]int)
	m["jackxu"] = 100
}

func modify_map_v3(m map[int]int) {
	m[2] = 200
}

func modify_map_v4(m *map[int]int) {
	mm := make(map[int]int)
	mm[1000] = 1
	mm[2000] = 2
	mm[3000] = 3
	mm[4000] = 4
	mm[5000] = 5
	mm[6000] = 6
	*m = mm
}

func main() {
	/*
		var m map[string]int
		fmt.Println(m)
		modify_map(m)
		fmt.Println(m)
	*/
	m[1] = 100
	modify_map_v3(m)
	fmt.Println(m)
	modify_map_v4(&m)
	fmt.Println(m)

	m2 := make(map[byte][]*int)
	fmt.Println(m2)
}
