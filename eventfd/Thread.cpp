#include"Thread.h"

namespace jjx
{
Thread::Thread(CallbackFun &&cb)
: _isRunning(false) 
, _cb(cb)
{}
Thread::~Thread()
{
	if(_isRunning)pthread_detach(_pthid);
}
int Thread::createThread()
{
	return pthread_create(&_pthid, NULL, threadFunc, (void*)this);
}
int Thread::joinThread()
{
	return pthread_join(_pthid, NULL);
}
pthread_t Thread::getThreadId()
{
	return _pthid;
}
void * Thread::threadFunc(void *p)
{
	Thread *pth=(Thread*)p;
	pth->run();
	return NULL;
}
void Thread::run()
{
	if(_cb)_cb();
}
}//end of namespace jjx
