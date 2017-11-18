#include"Timerfd.h"
#include"Thread.h"
#include<unistd.h>
#include<poll.h>
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
		struct pollfd fds;
		fds.fd=tfd;
		fds.events=POLLIN;
		while(ptim->isStart())
		{
			int ret=::poll(&fds, 1, 1000);
			if(ret<0){perror("::poll");break;}
			else if(ret==0)cout<<"poll timeout"<<endl;
			else{
				::read(tfd, &buf, sizeof(buf));
				cout<<"buf= "<<buf<<endl;
			}
		}
	}
};
int main()
{
	Task task;
	Timerfd tim(2,2);
	Thread thr(bind(&Task::process, &task, (void *)&tim));
	tim.start();
	thr.createThread();
	sleep(10);
	tim.stop();
	thr.joinThread();
	return 0;
}
