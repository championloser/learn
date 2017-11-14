#ifndef __TASK_H__
#define __TASK_H__

#include<iostream>
using std::endl;
using std::cout;
namespace jjx
{
class Task
{
public:
	virtual ~Task(){cout<<"~Task()"<<endl;}
	virtual void process()=0;
};
}//end of namespace jjx

#endif
