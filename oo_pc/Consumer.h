#ifndef __CONSUMER_H__
#define __CONSUMER_H__

#include"Thread.h"
#include<memory>

namespace jjx
{
class TaskQueue;
class Consumer : public Thread
{
public:
	Consumer(std::shared_ptr<TaskQueue> _ptq);
	void run();
private:
	std::shared_ptr<TaskQueue> _pTaskQue;
};
}//end of namespace jjx

#endif
