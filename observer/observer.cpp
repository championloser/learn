#include"observer.h"
#include<iostream>
#include<algorithm>
void Subject::attach(Observer *observer)
{
	//list<Observer *>::iterator it;
	//for(it=_listObserver.begin(); it!=_listObserver.end(); ++it)
	//{
	//	if(*it==observer)break;
	//}
	//if(it==_listObserver.end())_listObserver.insert(_listObserver.begin(), observer);
	list<Observer *>::iterator ret=std::find(_listObserver.begin(), _listObserver.end(), observer);
	if(ret==_listObserver.end())_listObserver.push_back(observer);
}
void Subject::detach(Observer *observer)
{
	//list<Observer *>::iterator it;
	//for(it=_listObserver.begin(); it!=_listObserver.end(); ++it)
	//{
	//	if(*it==observer)
	//	{
	//		_listObserver.erase(it);
	//	}
	//}
	list<Observer *>::iterator ret=std::find(_listObserver.begin(), _listObserver.end(), observer);
	if(ret!=_listObserver.end())_listObserver.erase(ret);
}
int ConcreateSubject::getState() const
{
	return _state;
}
void ConcreateSubject::setState(int state)
{
	_state=state;
	notify();
}
void Subject::notify()
{
	cout<<"Notify all observers"<<endl;
	list<Observer *>::iterator it;
	for(it=_listObserver.begin(); it!=_listObserver.end(); ++it)
	{
		(*it)->update(this);
	}
}	
void ConcreateObserver::update(Subject * subject)
{
	int tmpstate=subject->getState();
	if(tmpstate!=_state)
	{
		_state=tmpstate;
		cout<<"状态已更新为:"<<_state<<endl;
	}
}
