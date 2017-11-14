#include"ThreadPool.h"
#include<unistd.h>
#include<time.h>
#include<stdlib.h>
#include<iostream>
#include<functional>
using std::cout;
using std::endl;
using jjx::ThreadPool;
class Task
{
public:
	void run()
	{
		srand(time(NULL));
		cout<<"process a random number : "<<rand()%100<<endl;
		sleep(1);
	}
};
void run()
{
	srand(time(NULL));
	cout<<"process a random number : "<<rand()%100<<endl;
	sleep(1);
}
int main()
{
	ThreadPool thPool(5, 10);
	thPool.start();
	for(int i=0; i<20; ++i)
	{
		thPool.addTask(std::bind(&Task::run, Task()));
		cout<<"add a task : "<<i+1<<endl;
	}
	thPool.stop();
	return 0;
}
