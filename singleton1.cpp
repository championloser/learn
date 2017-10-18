/**********************************************************
 > Filename     : singleton1.cpp
 > Author       : Jeyshon<jeyshon@qq.com>
 > Create time  : 2017-10-16 22:03:56
 > Last modified: 2017-10-16 22:05:49
**********************************************************/
#include<iostream>
using namespace std;
class Singleton
{
public:
	static Singleton& function();
private:
	static Singleton* psingle;
	Singleton(){cout<<"Singleton()"<<endl;};
};
Singleton* Singleton::psingle=NULL;
Singleton& Singleton::function()
{
	if(psingle==NULL){psingle=new Singleton;return *psingle;}
	else return *psingle;
}
int main()
{
	Singleton &p=Singleton::function();
	Singleton &p1=Singleton::function();
	delete &p;
	return 0;
}
