#ifndef __THREAD_H__
#define __THREAD_H__

#include"Noncopyable.h"
#include<pthread.h>

namespace jjx
{
class Thread : private Noncopyable
{
public:
	Thread();
	virtual ~Thread();
	void start();
	void join();
protected:
	virtual void run()=0;
	static void * pthreadFunc(void *);
private:
	bool _isRunning;
	pthread_t _pthid;
};
}//end of namespace jjx

#endif
