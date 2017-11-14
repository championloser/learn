#include"ThreadPool.h"
#include<unistd.h>
#include"Thread.h"

namespace jjx
{
ThreadPool::ThreadPool(int pthSize, int taskSize)
: _isExit(false)
, _pthNum(pthSize)
, _taskNum(taskSize)
, _taskQue(_taskNum)
{
	_vecPth.reserve(_pthNum);
}
ThreadPool::~ThreadPool()
{}
void ThreadPool::start()
{
	for(int idx=0; idx!=_pthNum; ++idx)
	{
		std::shared_ptr<Thread> pth(new Thread(*this));
		_vecPth.push_back(pth);
	}
	for(auto pelem : _vecPth)
	{
		pelem->start();
	}
}
void ThreadPool::stop()
{
	while(_taskQue.size())
	{
		sleep(1);
	}
	_isExit=true;
	_taskQue.wakeup();
	for(auto pelem : _vecPth)
	{
		pelem->join();
	}
}
void ThreadPool::addTask(CallBack &&cb)
{
	_taskQue.push(cb);
}
ThreadPool::CallBack ThreadPool::getTask()
{
	return _taskQue.pop();
}
void ThreadPool::threadFun()
{
	while(!_isExit)
	{
		CallBack tmp=getTask();
		if(tmp)tmp();
	}
}
}//end of namespace jjx
