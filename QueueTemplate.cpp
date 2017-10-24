#include<iostream>
using std::cout;
using std::endl;
template <typename T, int KSize=10>
class Queue
{
public:
	Queue()
	: _que(new T[KSize]())
	, _front(0)
	, _back(0)
	, _size(0)
	{}
	~Queue()
	{
		delete _que;
	}
	void push(const T &elem);
	void pop();
	void display();
	T front();
	T back();
	int size();
	bool isEmpty();
	bool isFull();
private:
	T *_que;
	int _front;
	int _back;
	int _size;
};
template <typename T, int KSize>
void Queue<T,KSize>::push(const T &elem)
{
	if(!isFull())
	{
		_que[_back]=elem;
		_back=(_back+1)%KSize;
		++_size;
	}
	else cout<<"Queue is already full"<<endl;
}
template <typename T, int KSize>
void Queue<T,KSize>::pop()
{
	if(!isEmpty())
	{
		_front=(_front+1)%KSize;
		--_size;
	}
	else cout<<"Queue is already empty"<<endl;
}
template <typename T, int KSize>
void Queue<T,KSize>::display()
{
	for(int i=_front; i!=_back; i=(i+1)%KSize)
		cout<<_que[i]<<" ";
	cout<<endl;
}
template <typename T, int KSize>
T Queue<T,KSize>::front()
{
	return _que[_front];
}
template <typename T, int KSize>
T Queue<T,KSize>::back()
{
	return _que[(_back+KSize-1)%KSize];
}
template <typename T, int KSize>
int Queue<T,KSize>::size()
{
	return _size;
}
template <typename T, int KSize>
bool Queue<T,KSize>::isEmpty()
{
	if(_front==_back)return true;
	else return false;
}
template <typename T, int KSize>
bool Queue<T,KSize>::isFull()
{
	if(_front==(_back+1)%KSize)return true;
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
	Queue<int,5> que;
	cout<<"if queue is empty?"<<que.isEmpty()<<endl;
	cout<<"if queue is full?"<<que.isFull()<<endl;
	cout<<"the size of queue is "<<que.size()<<endl;
	cout<<endl;

	for(int i=1; i<=6; i++)que.push(i);
	que.display();
	cout<<que.back()<<endl;
	cout<<"if queue is empty?"<<que.isEmpty()<<endl;
	cout<<"if queue is full?"<<que.isFull()<<endl;
	cout<<"the size of queue is "<<que.size()<<endl;
	cout<<endl;

	for(int i=1; i<=6; i++)que.pop();
	que.display();
	cout<<"if queue is empty?"<<que.isEmpty()<<endl;
	cout<<"if queue is full?"<<que.isFull()<<endl;
	cout<<"the size of queue is "<<que.size()<<endl;
	return 0;
}
int test1()
{
	Queue<Point,5> que;
	cout<<"if queue is empty?"<<que.isEmpty()<<endl;
	cout<<"if queue is full?"<<que.isFull()<<endl;
	cout<<"the size of queue is "<<que.size()<<endl;
	cout<<endl;

	for(int i=1; i<=6; i++)que.push(Point(i, i+1));
	que.display();
	cout<<que.back()<<endl;
	cout<<"if queue is empty?"<<que.isEmpty()<<endl;
	cout<<"if queue is full?"<<que.isFull()<<endl;
	cout<<"the size of queue is "<<que.size()<<endl;
	cout<<endl;

	for(int i=1; i<=6; i++)que.pop();
	que.display();
	cout<<"if queue is empty?"<<que.isEmpty()<<endl;
	cout<<"if queue is full?"<<que.isFull()<<endl;
	cout<<"the size of queue is "<<que.size()<<endl;
	return 0;
	return 0;
}
int main()
{
	//test0();
	test1();
	return 0;
}
