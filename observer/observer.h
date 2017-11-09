#include<iostream>
#include<list>
using std::cout;
using std::endl;
using std::list;
class Observer;
class Subject
{
public:
	void attach(Observer *observer);
	void detach(Observer *observer);
	void notify();
	virtual int getState() const=0;
	virtual void setState(int state)=0;
	virtual ~Subject(){}
protected:
	list<Observer *> _listObserver;
};
class ConcreateSubject : public Subject
{
public:
	ConcreateSubject()
	: _state(-1)
	{
		cout<<"ConcreateSubject()"<<endl;
	}
	int getState() const;
	void setState(int state);
private:
	int _state;
};
class Observer
{
public:
	virtual void update(Subject *subject)=0;
	virtual ~Observer(){}
};
class ConcreateObserver : public Observer
{
public:
	ConcreateObserver()
	: _state(-1)
	{}
	void update(Subject *subject);
private:
	int _state;
};
