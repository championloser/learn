#include<string.h>
#include<iostream>
using std::cout;
using std::endl;
template <typename T, int Ksize>
class Stack
{
public:
	Stack()
	: _sta(new T[Ksize]())
	, _top(0)
	, _size(Ksize)
	{}
	void push(const T &elem)
	{
		if(!isFull())
		{
			_sta[_top]=elem;
			++_top;
		}
		else cout<<"Stack is already full"<<endl;
	}
	~Stack()
	{
		delete _sta;
	}
	void pop()
	{
		if(!isEmpty())
		{
			--_top;
		}	
		else cout<<"Stack is already empty"<<endl;
	}
	T & top()
	{
		if(!isEmpty())
		{
			return _sta[_top-1];
		}
		else return _sta[0];
	}
	void dispaly()
	{
		for(int i=0; i<_top; i++)cout<<_sta[i]<<" ";
		cout<<endl;
	}
	bool isEmpty()
	{
		if(0==_top)return true;
		else return false;
	}
	bool isFull()
	{
		if(_top==_size)return true;
		else return false;	
	}
private:
	T *_sta;
	int _top;
	int _size;
};
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
	sta.dispaly();
	cout<<"if stack empty?"<<sta.isEmpty()<<endl;
	cout<<"if stack full?"<<sta.isFull()<<endl;
	for(int i=1; i<=6; i++)sta.pop();
	sta.dispaly();
	cout<<"if stack empty?"<<sta.isEmpty()<<endl;
	cout<<"if stack full?"<<sta.isFull()<<endl;

	return 0;
}
int test1()
{
	Stack<Point,5> sta;
	cout<<"if stack empty?"<<sta.isEmpty()<<endl;
	for(int i=1; i<=6; i++)sta.push(Point(i,i+1));
	sta.dispaly();
	cout<<"if stack empty?"<<sta.isEmpty()<<endl;
	cout<<"if stack full?"<<sta.isFull()<<endl;
	for(int i=1; i<=6; i++)sta.pop();
	sta.dispaly();
	cout<<"if stack empty?"<<sta.isEmpty()<<endl;
	cout<<"if stack full?"<<sta.isFull()<<endl;
	return 0;
}
int main()
{
	//test0();
	test1();
	return 0;
}
