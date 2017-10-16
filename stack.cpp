/**********************************************************
 > Filename     : stack.cpp
 > Author       : Jeyshon<jeyshon@qq.com>
 > Create time  : 2017-10-16 19:40:53
 > Last modified: 2017-10-16 19:56:14
**********************************************************/
#include<iostream>
using namespace std;
class Stack
{
public:
	Stack();
	void push(int elem);
	void pop();
	int top();
	bool emty();
	bool full();

private:
	int _arr[10];
	int _num;
};
Stack::Stack()
: _num(0)
{}
void Stack::push(int elem)
{
	if(!full())
	{
		_arr[_num]=elem;
		_num++;
	}
}
void Stack::pop()
{
	if(!emty())
	{
		_num--;
	}
}
int Stack::top()
{
	return _arr[_num-1];
}
bool Stack::emty()
{
	if(_num==0)return true;
	else return false;
}
bool Stack::full()
{
	if(_num==sizeof(_arr)/4)return true;
	else return false;
}
int main()
{	Stack sta;
	sta.push(10);
	sta.push(12);
	sta.push(14);
	cout<<sta.top()<<endl;
	sta.pop();
	cout<<sta.top()<<endl;
	return 0;
}
