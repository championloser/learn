#include"observer.h"
#include<iostream>
#include<memory>
using std::cout;
using std::endl;
int main()
{
	std::shared_ptr<Subject> psubject(new ConcreateSubject()); 
	Observer * pobserver1=new ConcreateObserver();
	Observer * pobserver2=new ConcreateObserver();
	Observer * pobserver3=new ConcreateObserver();
	psubject->attach(pobserver1);
	psubject->attach(pobserver2);
	psubject->attach(pobserver3);
	psubject->setState(3);
	psubject->detach(pobserver1);
	psubject->setState(4);
	delete pobserver1;
	delete pobserver2;
	delete pobserver3;
	return 0;
}
