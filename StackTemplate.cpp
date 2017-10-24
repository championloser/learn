#include<string.h>
#include<iostream>
using std::cout;
using std::endl;
template <typename T, int KSize=10>
class Stack
{
public:
	Stack()
	: _sta(new T[KSize]())
	, _top(0)
	, _size(0)
	{}
	~Stack()
	{
		delete _sta;
	}
	void push(const T &elem);
	void pop();
	T & top();
	void display();
	int size();
	bool isEmpty();
	bool isFull();
private:
	T *_sta;
	int _top;
	int _size;
};
template <typename T, int KSize>
void Stack<T,KSize>::push(const T &elem)
{
	if(!isFull())
	{
		_sta[_top]=elem;
		++_top;
		++_size;
	}
	else cout<<"Stack is already full"<<endl;
}
template <typename T, int KSize>
void Stack<T,KSize>::pop()
{
	if(!isEmpty())
	{
		--_top;
		--_size;
	}	
	else cout<<"Stack is already empty"<<endl;
}
template <typename T, int KSize>
T & Stack<T,KSize>::top()
{
	if(!isEmpty())
	{
		return _sta[_top-1];
	}
	else return _sta[0];
}
template <typename T, int KSize>
void Stack<T,KSize>::display()
{
	for(int i=0; i<_top; i++)cout<<_sta[i]<<" ";
	cout<<endl;
}
template <typename T, int KSize>
int Stack<T,KSize>::size()
{
	return _size;
}
template <typename T, int KSize>
bool Stack<T,KSize>::isEmpty()
{
	if(0==_top)return true;
	else return false;
}
template <typename T, int KSize>
bool Stack<T,KSize>::isFull()
{
	if(_top==KSize)return true;
	else return false;	
}
class Point
{
public:
	Point(int x=0,int y=0)
	: _ix(x)
	, _iy(y)
	{}
	Point & operator=(const Point &rhs)
	{
		_ix=rhs._ix;
		_iy=rhs._iy;
		return *this;
	}
	friend std::ostream & operator<<(std::ostream &out, const Point &rhs);
private:
	int _ix;
	int _iy;
};
std::ostream & operator<<(std::ostream &out, const Point &rhs)
{
	out<<"("<<rhs._ix<<","<<rhs._iy<<")";
	return out;
}
int test0()
{
	Stack<int,5> sta;
	cout<<"if stack empty?"<<sta.isEmpty()<<endl;
	for(int i=1; i<=6; i++)sta.push(i);
	sta.top()=1;
	sta.display();
	cout<<"if stack empty?"<<sta.isEmpty()<<endl;
	cout<<"if stack full?"<<sta.isFull()<<endl;
	cout<<"The size of Stack is "<<sta.size()<<endl;
	for(int i=1; i<=6; i++)sta.pop();
	sta.display();
	cout<<"if stack empty?"<<sta.isEmpty()<<endl;
	cout<<"if stack full?"<<sta.isFull()<<endl;
	cout<<"The size of Stack is "<<sta.size()<<endl;
	return 0;
}
int test1()
{
	Stack<Point> sta;
	cout<<"if stack empty?"<<sta.isEmpty()<<endl;
	for(int i=1; i<=11; i++)sta.push(Point(i,i+1));
	sta.display();
	cout<<"if stack empty?"<<sta.isEmpty()<<endl;
	cout<<"if stack full?"<<sta.isFull()<<endl;
	for(int i=1; i<=11; i++)sta.pop();
	sta.display();
	cout<<"if stack empty?"<<sta.isEmpty()<<endl;
	cout<<"if stack full?"<<sta.isFull()<<endl;
	return 0;
}
int main()
{
	test0();
	//test1();
	return 0;
}
