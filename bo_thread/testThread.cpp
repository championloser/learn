#include"thread.h"
#include<time.h>
#include<unistd.h>
#include<stdlib.h>
#include<iostream>
using std::cout;
using std::endl;
class Mythread
{
public:
	void run()
	{
		srand(time(NULL));
		while(true)
		{
			cout<<"The random number is "<<rand()%100<<endl;
			sleep(1);
		}
	}
};
void getRandom()
{
	srand(time(NULL));
	while(true)
	{
		cout<<"The random number is "<<rand()%100<<endl;
		sleep(1);
	}
}
int main()
{
	//Mythread mth;
	//jjx::Thread th(std::bind(&Mythread::run, &mth));
	
	//jjx::Thread th(getRandom);
	
	jjx::Thread th(std::bind(&Mythread::run, Mythread()));
	th.start();
	th.join();
	return 0;
}
