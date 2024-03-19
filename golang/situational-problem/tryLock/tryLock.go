package main

import (
	"fmt"
	"sync/atomic"
)

// Go实现tryLock，加锁失败返回false，加锁成功返回true（用CAS实现）

type Lock struct {
	state int32
}

func (l *Lock) tryLock() bool {
	return atomic.CompareAndSwapInt32(&l.state, 0, 1)
}

func (l *Lock) unlock() {
	atomic.StoreInt32(&l.state, 0)
}

func main() {
	lock := Lock{}
	if lock.tryLock() {
		fmt.Println("try lock success")
	} else {
		fmt.Println("fail")
	}

	if lock.tryLock() {
		fmt.Println("try lock success")
	} else {
		fmt.Println("fail")
	}

	lock.unlock()
	if lock.tryLock() {
		fmt.Println("try lock success")
	} else {
		fmt.Println("fail")
	}
}
