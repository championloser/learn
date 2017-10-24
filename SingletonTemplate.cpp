#include<iostream>
using std::cout;
using std::endl;
template <typename T>
class Singleton
{
public:
	static T * getInstance();
	static void destroy();
private:
	Singleton();
	static T *_pT;
};
template <typename T>
T * Singleton<T>::getInstance()
{
	if(NULL==_pT)_pT=new T;
	return _pT;
}
template <typename T>
void Singleton<T>::destroy()
{
	delete _pT;
	_pT=NULL;
}
template <typename T>
T * Singleton<T>::_pT=NULL;
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
class X
{
public:
	X(){}
private:
	int _ix;
};
int main()
{
	Point *p1=Singleton<Point>::getInstance();
	Point *p2=Singleton<Point>::getInstance();
	if(p1==p2)cout<<"true"<<endl;
	else cout<<"false"<<endl;
	Singleton<Point>::destroy();

	X *p3=Singleton<X>::getInstance();
	X *p4=Singleton<X>::getInstance();
	if(p3==p4)cout<<"true"<<endl;
	else cout<<"false"<<endl;
	Singleton<X>::destroy();

	int *p5=Singleton<int>::getInstance();
	int *p6=Singleton<int>::getInstance();
	if(p5==p6)cout<<"true"<<endl;
	else cout<<"false"<<endl;
	Singleton<int>::destroy();
	return 0;
}
