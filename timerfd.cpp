#include<sys/timerfd.h>
#include<unistd.h>
#include<stdio.h>
#include<iostream>
using std::cout;
using std::endl;
int main()
{
	int tfd=timerfd_create(CLOCK_REALTIME, 0);
	if(-1==tfd){perror("timerfd_create");return 0;}
	struct itimerspec new_time;
	new_time.it_value.tv_sec=1;
	new_time.it_value.tv_nsec=0;
	new_time.it_interval.tv_sec=1;
	new_time.it_interval.tv_nsec=0;
	int ret=timerfd_settime(tfd, 0, &new_time, NULL);
	if(ret!=0){perror("timerfd_settime");return 0;}
	long int buf;
	while(true)
	{
		read(tfd, &buf, sizeof(buf));
		cout<<(int)buf<<endl;
		sleep(4);
	}
	return 0;
}
