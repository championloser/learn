#include"ThreadPool.h"
#include"WordThread.h"
#include"Task.h"
#include<unistd.h>
#include<iostream>
using std::cout;
using std::endl;

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
{
	cout<<"~ThreadPool()"<<endl;
}
void ThreadPool::start()
{
	for(int idx=0; idx!=_pthNum; ++idx)
	{
		std::shared_ptr<Thread> pth(new WordThread(*this));
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
		cout<<"join"<<endl;
	}
}
void ThreadPool::addTask(Task *ptask)
{
	_taskQue.push(ptask);
}
Task * ThreadPool::getTask()
{
	return _taskQue.pop();
}
void ThreadPool::threadFun()
{
	while(!_isExit)
	{
		Task *ptask=getTask();
		if(ptask)ptask->process();
	}
}
}//end of namespace jjx
