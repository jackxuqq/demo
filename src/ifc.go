package main

import "fmt"

func min(a int, b int) int {
	if a < b {
		return a
	}
	return b
}
func init() {
	fmt.Println("init")
}

type Writer interface {
	Write(bff []byte) (int, error)
}

type Reader interface {
	Read(buf []byte) (int, error)
}

type StringIO struct {
	_buf []byte
}

func (p *StringIO) Write(buf []byte) (int, error) {
	if p._buf == nil {
		p._buf = make([]byte, 100)
		//fmt.Println("len(p._buf) = ", len(p._buf), " cap(p._buf) = ", cap(p._buf))
	}
	copy(p._buf, buf)
	return len(p._buf), nil
}

func strlen(s string) int {
	i := 0
	for _, k := range s {
		if k != 0 {
			i++
		} else {
			break
		}
	}
	return i
}

func (p *StringIO) Read(buf []byte) (int, error) {
	//str := string(p._buf)
	//tmp := fmt.Sprintf("%s", string(p._buf))
	//fmt.Printf("%+v,%T, len(tmp)=%d\n", tmp, tmp, len(tmp))
	//fmt.Println("strlen=",strlen(string(p._buf)))
	t_s := p._buf[:strlen(string(p._buf))]
	copy(buf, t_s)
	return min(len(buf), len(t_s)), nil
}

type NetIO struct {
}

func (p *NetIO) Write(buff []byte) (int, error) {
	return 0, nil
}

func (p *NetIO) Read(buff []byte) (int, error) {
	return 0, nil
}

func main() {
	var ifc_r Reader
	var ifc_w Writer
	var str_io = new(StringIO)

	//ok 因为StringIO实现了Write方法
	ifc_w = str_io
	s := "hello"
	ifc_w.Write([]byte(s))
	buf := make([]byte, 100)
	len, _ := str_io.Read(buf)
	fmt.Println("read ", len, " bytes:", string(buf))

	//error 因为ifc_w未实现Read方法
	//ifc_r = ifc_w

	//ok 因为类型断言提取了str_io的值，StringIO实现了Read方法
	ifc_r, ok := ifc_w.(*StringIO)
	if ok {
		fmt.Printf("%+v\n", ifc_r)
		// ok
		len, _ := ifc_r.Read(buf)
		fmt.Println("read ", len, " bytes:", string(buf))

		// error
		//ifc_r.Write([]byte("abc"))
	}
}
