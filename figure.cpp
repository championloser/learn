#include<math.h>
#include<iostream>
using std::cout;
using std::endl;
class Figure
{
public:
	virtual void display() const=0;
	virtual float area()=0;
};
class Rectangle : public Figure
{
public:
	Rectangle(float x, float y)
	: _ix(x)
	, _iy(y)
	{}
	virtual void display() const 
	{
		cout<<"Rectangle::display()"<<endl;
	}
	virtual float area()
	{
		return _ix*_iy;
	}
private:
	float _ix;
	float _iy;
};
class Triangle : public Figure
{
public:
	Triangle(float x, float y, float z)
	: _ix(x)
	, _iy(y)
	, _iz(z) 
	{}
	virtual void display() const
	{
		cout<<"Triangle::display()"<<endl;
	}
	virtual float area()
	{
		float halfc=(_ix+_iy+_iz)/2;
		return sqrt(halfc*(halfc-_ix)*(halfc-_iy)*(halfc-_iz));
	}
private:
	float _ix;
	float _iy;
	float _iz;
};
class Circle : public Figure
{
public:
	Circle(float x)
	: _ix(x)
	{}
	virtual void display() const
	{
		cout<<"Circle::display()"<<endl;
	}
	virtual float area()
	{
		return (_ix/2)*(_ix/2)*3.14159;
	}
private:
	float _ix;
};
void print(Figure &fig)
{
	fig.display();
	cout<<"the area="<<fig.area()<<endl;
}
int main()
{
	Rectangle tect(3, 4);
	Triangle tri(3, 4, 5);
	Circle cir(6);
	print(tect);
	print(tri);
	print(cir);
	return 0;
}
