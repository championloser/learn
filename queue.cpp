/**********************************************************
 > Filename     : queue.cpp
 > Author       : Jeyshon<jeyshon@qq.com>
 > Create time  : 2017-10-16 19:56:49
 > Last modified: 2017-10-16 19:56:49
**********************************************************/
#include<iostream>
using namespace std;
class Queue
{
public:
	Queue();
	void push(int elem);
	void pop();
	void print();
	int front();
	int back();
	bool emty();
	bool full();
private:
	int _arr[5];
	int _front;
	int _back;
};
Queue::Queue()
: _front(0)
, _back(0)
{}
void Queue::push(int elem)
{
	if(!full())
	{
		_arr[_back]=elem;
		_back++;
	}
}
void Queue::pop()
{
	if(!emty())
	{
		_front++;
	}
	if(_front==_back || _front==sizeof(_arr)/4)
	{
		_front=0;
		_back=0;
	}
}
void Queue::print()
{
	cout<<_front<<","<<_back<<endl;
}
int Queue::front()
{
	if(!emty())return _arr[_front];
	else return 0;
}
int Queue::back()
{
	if(!emty())return _arr[_back-1];
	else return 0;
}
bool Queue::emty()
{
	if(_front==_back)return true;
	else return false;
}
bool Queue::full()
{
	if(_back==sizeof(_arr)/4)return true;
	else return false;
}
int main()
{
	Queue que;
	que.push(23);
	que.push(34);
	que.push(45);
	que.push(56);
	que.push(78);
	que.push(89);
	que.push(100);
	cout<<que.front()<<endl;
	cout<<que.back()<<endl;
	que.pop();
	cout<<que.front()<<endl;
	cout<<que.back()<<endl;
	return 0;
}
