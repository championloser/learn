#include"Consumer.h"
#include"TaskQueue.h"
#include<unistd.h>
#include<iostream>
using std::cout;
using std::endl;

namespace jjx
{
Consumer::Consumer(std::shared_ptr<TaskQueue> ptq)
: _pTaskQue(ptq)
{}
void Consumer::run()
{
	int random;
	while(true)
	{
		random=_pTaskQue->pop();
		cout<<"Consumer: consume a number: -"<<random<<endl;
		sleep(2);
	}
}
}//end of namespace jjx
