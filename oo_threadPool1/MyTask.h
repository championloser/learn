#ifndef __MYTASK_H__
#define __MYTASK_H__

#include"Task.h"
#include<iostream>
using std::endl;
using std::cout;
namespace jjx
{
class MyTask : public Task
{
public:
	~MyTask(){cout<<"~MyTask()"<<endl;}
	void process();
};
}//end of namespace jjx
#endif
