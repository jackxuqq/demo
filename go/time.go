//该程序延时after的2种用法
package main

import (
	"fmt"
	"time"
)

func testTime() {
	var t time.Time
	t = time.Now()
	fmt.Println(t)
}

func testDuration() {
	d, _ := time.ParseDuration("1.5h")
	fmt.Println(d.Seconds(), d.Minutes())
}

func main() {

	t, err := time.ParseInLocation("2006-01-02 15:04:05", "", time.Local)
	fmt.Printf("err=%v ts=%d\n", err, t.Unix())
	fmt.Println(time.Now().Format("2022-6-19 13:09:00"))
	fmt.Println(time.Now().Format("2006-01-02 15:04:05"))
	fmt.Println(time.Now().Format("2006-01-01 15:04:05"))
	testTime()

	testDuration()
}
