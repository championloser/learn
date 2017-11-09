#ifndef __PRODUCER_H__
#define __PRODUCER_H__

#include<memory>

namespace jjx
{
class TaskQueue;
class Producer
{
public:
	void run(TaskQueue &tq);
};
}//end of namespace jjx

#endif
