#ifndef __WORDTHREAD_H__
#define __WORDTHREAD_H__

#include"Thread.h"

namespace jjx
{
class ThreadPool;
class WordThread : public Thread
{
public:
	WordThread(ThreadPool &threadPool);
	void run();
private:
	ThreadPool &_threadPool;
};
}//end of namespace jjx

#endif
