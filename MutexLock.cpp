#include<iostream>
#include<pthread.h>
using namespace std;
class MutexLock
{
public:
	MutexLock();
	void lock();
	void unlock();
private:
	pthread_mutex_t _mutex;
};
MutexLock::MutexLock()
{
	pthread_mutex_init(&_mutex,NULL);
}
void MutexLock::lock()
{
	pthread_mutex_lock(&_mutex);
}
void MutexLock::unlock()
{
	pthread_mutex_unlock(&_mutex);
}
int main()
{
	MutexLock mut;
	mut.lock();
	cout<<"jiangjiaxian"<<endl;
	mut.unlock();
	return 0;
}
