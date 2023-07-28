package cache

import "fmt"
import "errors"
import "sync"
import "math/rand"
import "strconv"
import "time"

const (
	syncInterval = 5 // 5秒同步一次
)

var (
	kv     sync.Map
	syncTs int64
	kvLen  int
	rwlock sync.RWMutex
)

func init() {
	rand.Seed(time.Now().UnixNano())
	/*
		var once sync.Once
		once.Do(func() {
			go Sync()
		})
	*/
}

func Get(gid int, key string) (interface{}, error) {
	//更新缓存
	syncData(gid)

	rwlock.RLock()
	defer rwlock.RUnlock()
	ret, ok := kv.Load(key)
	if ok {
		return ret, nil
	}
	return nil, errors.New("key not exist")
}

func getRemoteData() (map[string]interface{}, error) {
	num := rand.Intn(10)
	num += 10

	ret := map[string]interface{}{}
	for i := 0; i < num; i++ {
		key := "key" + strconv.Itoa(i)
		val := "val" + strconv.Itoa(i)
		ret[key] = val
	}
	//模拟一半的概率失败
	k := rand.Intn(2)
	if k == 0 {
		return nil, errors.New("rcp fail")
	}
	return ret, nil
}

func syncData(gid int) {
	if !(time.Now().Unix()-syncTs > syncInterval) {
		return //未到同步时间
	}
	everLock := false

	defer func() {
		if everLock {
			rwlock.Unlock()
		}
	}()
	//没数据的时候要锁住读，不要反悔空
	if kvLen == 0 {
		rwlock.Lock()
		everLock = true
		if kvLen > 0 {
			return
		}
	}
	//step1:rpc get data
	remoteKv, err := getRemoteData()
	if err != nil {
		fmt.Printf("gid[%d] getRemoteData fail, err[%v]", gid, err)
		return
	}
	if len(remoteKv) == 0 {
		//如果一条数据都没拉到也是默认为失败
		fmt.Printf("gid[%d] getRemoteData fail, remoteKv empty", gid)
		return
	}
	//fmt.Printf("gid[%d] getRemoteData success", gid)

	//step2:clean old data
	keys := make([]string, 0)
	kv.Range(func(k, v interface{}) bool {
		keys = append(keys, k.(string))
		return true
	})

	//有数据的case处于性能考虑先让用旧的，内存切换微妙级
	if kvLen != 0 {
		rwlock.Lock()
		everLock = true
	}

	for i := 0; i < len(keys); i++ {
		kv.Delete(keys[i])
	}
	kvLen = 0

	//step3:store new data
	for k, v := range remoteKv {
		kv.Store(k, v)
		kvLen += 1
	}
	syncTs = time.Now().Unix()
}
