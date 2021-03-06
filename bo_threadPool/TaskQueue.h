#ifndef __TASKQUEUE_H__
#define __TASKQUEUE_H__

#include"MutexLock.h"
#include"Condition.h"
#include<functional>
#include<queue>

namespace jjx
{
class Task;
class TaskQueue
{
	typedef std::function<void()> ElemType;
public:
	TaskQueue(int size);
	~TaskQueue();
	void push(ElemType &elem);
	ElemType pop();
	int size();
	void wakeup();
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
	bool _flag;
};
}//end of namespace jjx

#endif
