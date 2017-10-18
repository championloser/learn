/**********************************************************
 > Filename     : singleton.cpp
 > Author       : Jeyshon<jeyshon@qq.com>
 > Create time  : 2017-10-16 22:03:56
 > Last modified: 2017-10-17 11:43:50
**********************************************************/
#include<iostream>
#include<stdio.h>
using namespace std;
class Singleton
{
public:
	static Singleton* function();
	~Singleton()
	{
		cout<<"~Singleton()"<<endl;
	}
private:
	static Singleton* psingle;
	Singleton(){cout<<"Singleton()"<<endl;};
};
Singleton* Singleton::psingle=NULL;
Singleton* Singleton::function()
{
	if(psingle==NULL){psingle=new Singleton;return psingle;}
	else return psingle;
}
int main()
{
	Singleton *p=Singleton::function();
	Singleton *p1=Singleton::function();
	printf("%p\n",p);
	printf("%p\n",p1);
	delete p;
	return 0;
}
