#ifndef __TASK_H__
#define __TASK_H__

namespace jjx
{
class Task
{
public:
	virtual ~Task(){}
	virtual void process()=0;
};
}//end of namespace jjx

#endif
