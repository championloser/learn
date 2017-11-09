#ifndef __PRODUCER_H__
#define __PRODUCER_H__

#include"Thread.h"
#include<memory>

namespace jjx
{
class TaskQueue;
class Producer : public Thread
{
public:
	Producer(std::shared_ptr<TaskQueue> ptq);
	void run();
private:
	std::shared_ptr<TaskQueue> _pTaskQue;
};
}//end of namespace jjx

#endif
