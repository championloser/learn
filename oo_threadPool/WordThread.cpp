#include"WordThread.h"
#include"ThreadPool.h"

namespace jjx
{
WordThread::WordThread(ThreadPool &threadPool)
: _threadPool(threadPool)
{}
void WordThread::run()
{
	_threadPool.threadFun();
}
}//end of namespace jjx
