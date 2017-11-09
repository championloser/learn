#ifndef __THREADPOOL_H__
#define __THREADPOOL_H__

#include"Thread.h"
#include"TaskQueue.h"
#include<memory>
#include<vector>

namespace jjx
{
class Task;
class ThreadPool
{
public:
	ThreadPool(int pthSize, int taskSize);
	~ThreadPool();
	void start();
	void stop();
	void addTask(Task *ptask);
	Task * getTask();
	void threadFun();
private:
	bool _isExit;
	int _pthNum;
	int _taskNum;
	std::vector<std::shared_ptr<Thread>> _vecPth;
	TaskQueue _taskQue;
};
}//end of namespace jjx

#endif
