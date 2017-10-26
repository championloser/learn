#include<iostream>
using std::cout;
using std::endl;
template <typename T>
class Singleton
{
private:
	class Recycle
	{
	public:
		Recycle(){cout<<"Recycle()"<<endl;}
		~Recycle()
		{
			cout<<"~Recycle()"<<endl;
			delete _pT;
		}
	};
public:
	static T * getInstance();
private:
	Singleton();
	static T *_pT;
	static Recycle _rec;
};
template <typename T>
T * Singleton<T>::getInstance()
{
	_rec;
	if(NULL==_pT){cout<<"getInstance()"<<endl;_pT=new T;}
	return _pT;
}
template <typename T>
T * Singleton<T>::_pT=NULL;
template <typename T>
typename Singleton<T>::Recycle Singleton<T>::_rec;
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
	return 0;
}
