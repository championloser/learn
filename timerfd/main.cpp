#include"Timerfd.h"
#include"Thread.h"
#include<unistd.h>
#include<iostream>
#include<functional>
using std::cout;
using std::endl;
using std::bind;
using jjx::Thread;
using jjx::Timerfd;
class Task
{
public:
	void process(void *p)
	{
		Timerfd *ptim=(Timerfd*)p;
		int tfd=ptim->getTfd();
		long int buf;
		while(ptim->isStart())
		{
			::read(tfd, &buf, sizeof(buf));
			cout<<"buf="<<buf<<endl;
			sleep(1);
		}
	}
};
int main()
{
	Task task;
	Timerfd tim(2,1);
	Thread thr(bind(&Task::process, &task, (void *)&tim));
	tim.start();
	thr.createThread();
	sleep(10);
	tim.stop();//此处stop和read在多线程环境下存在时序问题，这里只是示范一下timerfd的用法
	thr.joinThread();
	return 0;
}
