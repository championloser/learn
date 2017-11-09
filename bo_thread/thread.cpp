#include"thread.h"

namespace jjx
{
//Thread::Thread(std::function<void()> cb)
//: _isRunning(false)
//, _callBack(cb)
//{}
Thread::Thread(std::function<void()> &&cb)
: _isRunning(false)
, _callBack(std::move(cb))
{}
Thread::~Thread()
{
	pthread_detach(_pthid);
}
void Thread::start()
{
	_isRunning=true;
	pthread_create(&_pthid, NULL, pthreadFunc, this);
}
void Thread::join()
{
	pthread_join(_pthid, NULL);
}
void * Thread::pthreadFunc(void *p)
{
	Thread *pth=static_cast<Thread *>(p);
	pth->_callBack();
	return NULL;
}
}//end of namespace jjx
