#include"ThreadPool.h"
#include"MyTask.h"
#include"Task.h"
#include<unistd.h>
#include<iostream>
using std::cout;
using std::endl;
using jjx::ThreadPool;
using jjx::MyTask;
using jjx::Task;
int main()
{
	ThreadPool thPool(5, 10);
	thPool.start();
	Task * ptask=new MyTask;
	for(int i=0; i<20; ++i)
	{
		thPool.addTask(ptask);
		cout<<"add a task : "<<i+1<<endl;
	}
	thPool.stop();
	delete ptask;
	cout<<"end"<<endl;
	return 0;
}
