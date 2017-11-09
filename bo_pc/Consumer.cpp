#include"Consumer.h"
#include"TaskQueue.h"
#include<unistd.h>
#include<iostream>
using std::cout;
using std::endl;

namespace jjx
{
void Consumer::run(TaskQueue &tq)
{
	int random;
	while(true)
	{
		random=tq.pop();
		cout<<"Consumer: consume a number: -"<<random<<endl;
		sleep(2);
	}
}
}//end of namespace jjx
