#ifndef __TASKQUEUE_H__
#define __TASKQUEUE_H__

#include"MutexLock.h"
#include"Condition.h"
#include<queue>

namespace jjx
{
class TaskQueue
{
	typedef int ElemType;
public:
	TaskQueue(int size);
	~TaskQueue();
	void push(ElemType &elem);
	ElemType pop();
private:
	bool isFull();
	bool isEmpty();
private:
	int _queSize;
	int _queCapacity;
	MutexLock _mutexlock;
	Condition _notFullCond;
	Condition _notEmptyCond;
	std::queue<ElemType> _que;
};
}//end of namespace jjx

#endif
