#include"Thread.h"
#include"Producer.h"
#include"Consumer.h"
#include"TaskQueue.h"
#include<iostream>
#include<memory>
#include<functional>
using std::cout;
using std::endl;
using jjx::TaskQueue;
using jjx::Producer;
using jjx::Consumer;
using jjx::Thread;
int main()
{
	TaskQueue tq(10);
	Thread pthPro(std::bind(&Producer::run, Producer(), std::ref(tq)));
	Thread pthCon(std::bind(&Consumer::run, Consumer(), std::ref(tq)));
	pthPro.start();
	pthCon.start();
	pthPro.join();
	pthCon.join();
	return 0;
}
