//模拟主协程启动了多个子协程分别处理数据后汇总，超时后及时喊停所有协程 及时释放资源
package main

import (
	"context"
	"fmt"
	"time"
)

const (
	UserIP = "user-ip"
)

func process1(ctx context.Context) {
	for {
		select {
		case <-ctx.Done():
			fmt.Println("process1 cancel")
			return
		default:
			fmt.Printf("process1 do some thing, user_ip=%s\n", ctx.Value(UserIP))
		}
		time.Sleep(time.Second * 1)
	}
}

func process2(ctx context.Context) {
	for {
		t, ok := ctx.Deadline()
		if ok && time.Now().After(t) {
			fmt.Println("process2 time is up")
			return
		}

		select {
		case <-ctx.Done():
			fmt.Println("process2 cancel")
			return
		default:
			fmt.Printf("process2 do some thing, user_ip=%s\n", ctx.Value(UserIP))
		}
		time.Sleep(time.Second * 1)
	}
}

func main() {
	ctx, _ := context.WithTimeout(context.Background(), time.Second*3)
	ctx = context.WithValue(ctx, UserIP, "127.0.0.1")
	go process1(ctx)

	go process2(ctx)

	//time.Sleep(time.Second * 2)
	//cancel()
	time.Sleep(time.Second * 5)

}
