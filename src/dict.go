package main

import (
	"fmt"
)

func main() {
	m := make(map[string]bool)
	m["fid_2821"] = true
	m["iswatermark"] = true
	m["logo"] = true
	m["loginfo"] = true
	m["sharpen"] = true
	m["saturation"] = true
	m["exdefn"] = true
	for k, _ := range m {
		fmt.Printf("k=%s\n", k)
	}
}
