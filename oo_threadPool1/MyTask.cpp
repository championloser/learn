#include"MyTask.h"
#include<time.h>
#include<stdlib.h>
#include<unistd.h>
#include<iostream>
using std::cout;
using std::endl;

namespace jjx
{
void MyTask::process()
{
	srand(time(NULL));
	cout<<"process a random number: "<<rand()%100<<endl;
	sleep(1);
}
}//end of namespace jjx
