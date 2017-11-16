#ifndef __THREAD_H__
#define __THREAD_H__

#include<pthread.h>
#include<functional>

namespace jjx
{
class Thread
{
	typedef std::function<void(void)> CallbackFun;
public:
	Thread(CallbackFun &&cb);
	~Thread();
	int createThread();
	int joinThread();
	pthread_t getThreadId();
	void run();
private:
	static void * threadFunc(void *);
private:
	pthread_t _pthid;
	bool _isRunning;
	CallbackFun _cb;
};
}//end of jjx

#endif
