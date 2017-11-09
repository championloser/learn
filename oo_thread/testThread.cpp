#include"thread.h"
#include<iostream>
#include<time.h>
#include<unistd.h>
#include<stdlib.h>
#include<memory>
using std::cout;
using std::endl;
class Mythread : public jjx::Thread
{
public:
	void run()
	{
		while(true)
		{
		srand(time(NULL));
		cout<<"The random number is "<<rand()%100<<endl;
		sleep(1);
		}
	}
};
int main()
{
	std::unique_ptr<jjx::Thread> pth(new Mythread);
	pth->start();
	pth->join();
	return 0;
}
