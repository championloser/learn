#include"Thread.h"
#include"ThreadPool.h"

namespace jjx
{
Thread::Thread(ThreadPool &threadPool)
: _isRunning(false)
, _threadPool(threadPool)
{}
Thread::~Thread()
{
	if(_isRunning)pthread_detach(_pthid);
}
void Thread::start()
{
	pthread_create(&_pthid, NULL, threadFunc, (void *)this);
	_isRunning=true;
}
void Thread::join()
{
	pthread_join(_pthid, NULL);
	_isRunning=false;
}
void * Thread::threadFunc(void *p)
{
	Thread *pth=static_cast<Thread *>(p);
	pth->run();
	return NULL;
}
void Thread::run()
{
	_threadPool.threadFun();
}
}//end of namespace jj,
