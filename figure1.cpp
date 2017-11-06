#include<math.h>
#include<iostream>
#include<functional>
using std::cout;
using std::endl;
using std::function;
using std::bind;
class Figure
{
public:
	void setCallBack1(function<void()> p)
	{
		_callBack1=p;
	}
	void setCallBack2(function<float()> p)
	{
		_callBack2=p;
	}
	void handleCallBack1()
	{
		_callBack1();
	}
	float  handleCallBack2()
	{
		return _callBack2();
	}
private:
	function<void()> _callBack1;
	function<float()> _callBack2;
};
class Rectangle
{
public:
	Rectangle(float x, float y)
	: _ix(x)
	, _iy(y)
	{}
	void display() const 
	{
		cout<<"Rectangle::display()"<<endl;
	}
	float area()
	{
		return _ix*_iy;
	}
private:
	float _ix;
	float _iy;
};
class Triangle
{
public:
	Triangle(float x, float y, float z)
	: _ix(x)
	, _iy(y)
	, _iz(z) 
	{}
	void display() const
	{
		cout<<"Triangle::display()"<<endl;
	}
	float area()
	{
		float halfc=(_ix+_iy+_iz)/2;
		return sqrt(halfc*(halfc-_ix)*(halfc-_iy)*(halfc-_iz));
	}
private:
	float _ix;
	float _iy;
	float _iz;
};
class Circle
{
public:
	Circle(float x)
	: _ix(x)
	{}
	void display() const
	{
		cout<<"Circle::display()"<<endl;
	}
	float area()
	{
		return (_ix/2)*(_ix/2)*3.14159;
	}
private:
	float _ix;
};
void display(Figure &fig)
{
	fig.handleCallBack1();
	cout<<"the area is "<<fig.handleCallBack2()<<endl;
}
int main()
{
	Rectangle tect(3, 4);
	Triangle tri(3, 4, 5);
	Circle cir(6);

	Figure fig;
	fig.setCallBack1(bind(&Rectangle::display, &tect));
	fig.setCallBack2(bind(&Rectangle::area, &tect));
	display(fig);

	fig.setCallBack1(bind(&Triangle::display, &tri));
	fig.setCallBack2(bind(&Triangle::area, &tri));
	display(fig);

	fig.setCallBack1(bind(&Circle::display, &cir));
	fig.setCallBack2(bind(&Circle::area, &cir));
	display(fig);
	return 0;
}
