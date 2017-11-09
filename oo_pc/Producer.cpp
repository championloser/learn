#include"Producer.h"
#include"TaskQueue.h"
#include<time.h>
#include<stdlib.h>
#include<unistd.h>
#include<iostream>
using std::cout;
using std::endl;

namespace jjx
{
Producer::Producer(std::shared_ptr<TaskQueue> ptq)
: _pTaskQue(ptq)
{}
void Producer::run()
{
	srand(time(NULL));
	int random;
	while(true)
	{
		random=rand()%100;
		_pTaskQue->push(random);
		cout<<"Producer: produce a number: +"<<random<<endl;
		sleep(1);
	}
}
}//end of namespace jjx
