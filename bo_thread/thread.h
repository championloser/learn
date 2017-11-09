#ifndef __THREAD_H__
#define __THREAD_H__

#include<pthread.h>
#include<functional>

namespace jjx
{
class Thread
{
public:
	//Thread(std::function<void()> cb);
	Thread(std::function<void()> &&cb);
	~Thread();
	void start();
	void join();
private:
	static void * pthreadFunc(void *);
private:
	pthread_t _pthid;
	bool _isRunning;
	std::function<void()> _callBack;
};
}//end of namespace jjx
#endif

