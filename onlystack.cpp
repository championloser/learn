/**********************************************************
 > Filename     : onlystack.cpp
 > Author       : Jeyshon<jeyshon@qq.com>
 > Create time  : 2017-10-17 21:11:06
 > Last modified: 2017-10-17 21:11:06
**********************************************************/
#include<iostream>
#include<string.h>
#include<stdlib.h>
using std::cout;
using std::endl;
class Student
{
public:
	Student(int num,const char * name);
	~Student();
	void printInfo();
	void setInfo(int num,const char* name);
private:
	void * operator new(size_t size);
	void operator delete(void * p);
	int _num;
	char *_name;
};
Student::Student(int num,const char * name)
: _num(num)
, _name(new char[strlen(name)+1]())
{
	strcpy(_name,name);
}
Student::~Student()
{
	cout<<"~Student()"<<endl;
	delete [] _name;
}
void * Student::operator new(size_t size)
{
	cout<<"operator new(size_t size)"<<endl;
	return malloc(size);
}
void Student::operator delete(void *p)
{
	cout<<"operator delete(void *p)"<<endl;
	free(p);
	p=NULL;
}
void Student::printInfo()
{
	cout<<"num:"<<_num<<endl;
	cout<<"name:"<<_name<<endl;
}
void Student::setInfo(int num,const char * name)
{
	_num=num;
	strcpy(_name,name);
}
int main()
{
	Student stu(200,"Jeyshon");
	stu.printInfo();
	//Student *pstu=new Student(100,"jiaxian");
	//pstu->printInfo();
	return 0;
}
