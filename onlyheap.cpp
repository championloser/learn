#include<iostream>
#include<string.h>
#include<stdlib.h>
using std::cout;
using std::endl;
class Student
{
public:
	Student(int num,const char * name);
	void * operator new(size_t size);
	void operator delete(void * p);
	void printInfo();
	void setInfo(int num,const char* name);
	void destory();
private:
	~Student();
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
void Student::destory()
{
	delete this;
}
int main()
{
	//Student stu(200,"Jeyshon");
	//stu.printInfo();
	Student *pstu=new Student(100,"jiaxian");
	pstu->printInfo();
	pstu->destory();
	return 0;
}
