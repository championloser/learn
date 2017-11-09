#include"Thread.h"
#include"Producer.h"
#include"Consumer.h"
#include"TaskQueue.h"
#include<iostream>
#include<memory>
using std::cout;
using std::endl;
using jjx::TaskQueue;
using jjx::Producer;
using jjx::Consumer;
using jjx::Thread;
int main()
{
	std::shared_ptr<TaskQueue> ptq(new TaskQueue(10));
	std::shared_ptr<Thread> pthPro(new Producer(ptq));
	std::shared_ptr<Thread> pthCon(new Consumer(ptq));
	pthPro->start();
	pthCon->start();
	pthPro->join();
	pthCon->join();
	return 0;
}
