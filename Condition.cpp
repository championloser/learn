/**********************************************************
  > Filename     : Condition.cpp
  > Author       : Jeyshon<jeyshon@qq.com>
  > Create time  : 2017-10-19 20:35:57
  > Last modified: 2017-10-19 20:36:03
 **********************************************************/
#include<iostream>
#include<pthread.h>
using namespace std;
class Condition
{
public:
	Condition();
	void wait();
	void notify();
	void notifyAll();
private:
	pthread_mutex_t _mutex;
	pthread_cond_t _cond;
};
Condition::Condition()
{
	pthread_mutex_init(&_mutex,NULL);
	pthread_cond_init(&_cond,NULL);
}
void Condition::wait()
{
	pthread_mutex_lock(&_mutex);
	pthread_cond_wait(&_cond,&_mutex);
	pthread_mutex_unlock(&_mutex);
}
void Condition::notify()
{
	pthread_cond_signal(&_cond);
}
void Condition::notifyAll()
{
	pthread_cond_broadcast(&_cond);
}
int main()
{
	Condition con;
	con.wait();
	cout<<"jiangjiaxian"<<endl;
	con.notify();
	return 0;
}
