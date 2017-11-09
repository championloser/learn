#include"thread.h"

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
	_isRunning=true;
	pthread_create(&_pthid, NULL, pthreadFunc, (void *)this);
}
void * Thread::pthreadFunc(void *p)
{
	Thread *pth=static_cast<Thread *>(p);
	pth->run();
	return p;
}
void Thread::join()
{
	pthread_join(_pthid, NULL);
}
}//end of namespace jjx
