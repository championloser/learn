#include"Thread.h"

namespace jjx
{
Thread::Thread()
: _isRunning(false)
{}
Thread::~Thread()
{
	pthread_detach(_pthid);
}
void Thread::start()
{
	pthread_create(&_pthid, NULL, pthreadFunc, (void *)this);
	_isRunning=true;
}
void Thread::join()
{
	pthread_join(_pthid, NULL);
}
void * Thread::pthreadFunc(void *p)
{
	Thread *pth=static_cast<Thread *>(p);
	pth->run();
	return NULL;
}
}//end of namespace jj,
