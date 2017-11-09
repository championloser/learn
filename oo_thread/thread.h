#ifndef __THREAD_H__
#define __THREAD_H__

#include<pthread.h>

namespace jjx
{
class Thread
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
	pthread_t _pthid;
	bool _isRunning;
};
}//end of namespace jjx
#endif
