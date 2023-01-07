package util

type Info struct {
	id   int
	sex  byte
	age  int
	addr string
}

func (i *Info) SetAddr(addr string) {
	i.addr = addr
}

func NewInfo(id int, sex byte, age int, addr string) *Info {
	return &Info{
		id:   id,
		sex:  sex,
		age:  age,
		addr: addr,
	}
}
