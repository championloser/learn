#ifndef __THREAD_H__
#define __THREAD_H__

#include"Noncopyable.h"
#include<pthread.h>
#include<functional>

namespace jjx
{
class Thread : private Noncopyable
{
	typedef std::function<void()> CallBackFun;
public:
	Thread(CallBackFun &&cb);
	~Thread();
	void start();
	void join();
protected:
	static void * pthreadFunc(void *);
private:
	bool _isRunning;
	pthread_t _pthid;
	CallBackFun _cb;
};
}//end of namespace jjx

#endif
