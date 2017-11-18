#include"Eventfd.h"
#include"Thread.h"
#include<unistd.h>
#include<poll.h>
#include<iostream>
#include<functional>
using std::cout;
using std::endl;
using std::bind;
using jjx::Thread;
using jjx::Eventfd;
class Task
{
public:
	void process(void *p)
	{
		Eventfd *peve=(Eventfd*)p;
		while(true)
		{
			peve->readEventfd();
			cout<<"child Thread: I am wakeup"<<endl;
		}
	}
};
int main()
{
	Task task;
	Eventfd eve;
	Thread thr(bind(&Task::process, &task, (void *)&eve));
	thr.createThread();
	while(true)
	{
		sleep(1);
		cout<<"main: writeEventfd"<<endl;
		eve.writeEventfd();
	}
	return 0;
}
