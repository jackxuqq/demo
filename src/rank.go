package main

import "fmt"

type RankItem struct {
	tagID string
	title string
	heat  int
	pos   int
}

func initRank() []RankItem {
	var ret []RankItem
	for i := 0; i < 10; i++ {
		item := RankItem{
			tagID: fmt.Sprintf("tagID_%d", i+1),
			title: fmt.Sprintf("test_title_%d", i+1),
			heat:  100 + i + 1,
		}

		ret = append(ret, item)
	}
	return ret
}

func insertRank(insert []RankItem, initRank []RankItem) []RankItem {
	for _, v := range insert {
		//delete old one
		for i, item := range initRank {
			if v.tagID == item.tagID {
				initRank = append(initRank[:i], initRank[i+1:]...)
				v.title = item.title
				v.heat = item.heat
				break
			}
		}

		//insert new one
		initRank = append(initRank[:v.pos-1], append([]RankItem{v}, initRank[v.pos-1:]...)...)
	}
	return initRank
}

func main() {
	rank := initRank()

	var insert []RankItem
	one := RankItem{
		tagID: "tagID_10",
		pos:   1,
	}
	insert = append(insert, one)

	two := RankItem{
		tagID: "tagID_2",
		pos:   2,
	}
	insert = append(insert, two)
	ret := insertRank(insert, rank)
	for _, v := range ret {
		fmt.Println(v)
	}
}
