#include<stdlib.h>
#include<pthread.h>
#include<iostream>
using namespace std;
class Singleton
{
public:
	static Singleton * getInstance();
	static void singletonInit();
	static void destroy();
private:
	Singleton(){}
	~Singleton(){}
	static Singleton *pInstance;
	static pthread_once_t _onceControl;
};
//Singleton * Singleton::pInstance=Singleton::getInstance();
Singleton * Singleton::pInstance=NULL;
pthread_once_t Singleton::_onceControl=PTHREAD_ONCE_INIT;
Singleton * Singleton::getInstance()
{
	cout<<"getInstance()"<<endl;
	pthread_once(&_onceControl,singletonInit);
	return pInstance;
}
void Singleton::singletonInit()
{
	if(NULL==pInstance){atexit(destroy);pInstance=new Singleton;}
}
void Singleton::destroy()
{
	cout<<"destroy()"<<endl;
	delete pInstance;
}
int main()
{
	Singleton *p1=Singleton::getInstance();
	Singleton *p2=Singleton::getInstance();
	if(p1==p2)cout<<"true"<<endl;
	else cout<<"false"<<endl;
	return 0;
}
