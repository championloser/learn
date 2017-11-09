#ifndef __CONSUMER_H__
#define __CONSUMER_H__

#include<memory>

namespace jjx
{
class TaskQueue;
class Consumer
{
public:
	void run(TaskQueue &tq);
};
}//end of namespace jjx

#endif
