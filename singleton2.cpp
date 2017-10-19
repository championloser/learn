/**********************************************************
 > Filename     : singleton2.cpp
 > Author       : Jeyshon<jeyshon@qq.com>
 > Create time  : 2017-10-17 11:50:25
 > Last modified: 2017-10-17 12:16:20
**********************************************************/
#include<iostream>
#include<stdio.h>
using namespace std;
class Singleton
{
public:
	static Singleton * getInstance();
	~Singleton()
	{cout<<"~Singleton()"<<endl;}
private:
	Singleton(){cout<<"Singleton()"<<endl;}
	static Singleton * pInstance;

	class Recycle
	{
	public:
		Recycle(){cout<<"Recycle()"<<endl;};
		~Recycle()
		{
			cout<<"~Recycle()"<<endl;
			delete Singleton::pInstance;
		}
	};
	static Recycle rec;
};
Singleton::Recycle Singleton::rec;//静态数据成员类外初始化,否则连Recycle的构造函数都不会执行
Singleton * Singleton::pInstance=NULL;
Singleton * Singleton::getInstance()
{
	if(NULL==pInstance)pInstance=new Singleton;
	return pInstance;
}
int main()
{
	Singleton *p1=Singleton::getInstance();
	Singleton *p2=Singleton::getInstance();
	printf("%p\n",p1);
	printf("%p\n",p2);
	return 0;
}
