package main

import "github.com/dao"

func main() {
	var user module.User
	db := dao.NewDB()
	db.Insert(user)
	var user2 module.User
	user2.Id = 1
	db.GetUser(&user2)
	fmt.Printf("%+v\n", user2)
}
