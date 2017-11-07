#include<iostream>
#include<memory>
#include<math.h>
using std::cout;
using std::endl;
class Figure
{
public:
	virtual void display() const=0;
	virtual float area()=0;
	virtual ~Figure(){cout<<"~Figure()"<<endl;};
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
	~Rectangle()
	{
		cout<<"~Rectangle()"<<endl;
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
	~Triangle()
	{
		cout<<"~Triangle()"<<endl;
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
	~Circle()
	{
		cout<<"~Circle()"<<endl;
	}
private:
	float _ix;
};
void print(Figure &fig)
{
	fig.display();
	cout<<"the area="<<fig.area()<<endl;
}
//静态工厂模式
class StaticFactory
{
public:
	static Circle * createCircle()
	{
		//read config
		//....
		int radius=3;
		return new Circle(radius);
	}
	static Rectangle * createRectangle()
	{
		//read config
		//...
		int x=3;
		int y=4;
		return new Rectangle(x, y);
	}
	static Triangle * createTriangle()
	{
		//read config
		//...
		int x=3;
		int y=4;
		int z=5;
		return new Triangle(x, y, z);
	}
};
void testStaticFactory()
{
	std::unique_ptr<Figure> pcir(StaticFactory::createCircle());
	std::unique_ptr<Figure> prec(StaticFactory::createRectangle());
	std::unique_ptr<Figure> tria(StaticFactory::createTriangle());
	print(*pcir);
	print(*prec);
	print(*tria);
}
//工厂模式
class FigureFactory
{
public:
	virtual Figure * create()=0;
	virtual ~FigureFactory(){};
};
class CreateCircle : public FigureFactory
{
public:
	Figure * create()
	{
		//read config
		//...
		int radius=5;
		return new Circle(radius);
	}
};
class CreateRectangle : public FigureFactory
{
public:
	Figure * create()
	{
		//read config
		//...
		int x=3;
		int y=4;
		return new Rectangle(x, y);
	}
};
class CreateTriangle : public FigureFactory
{
public:
	Figure * create()
	{
		//read config
		//...
		int x=3;
		int y=4;
		int z=5;
		return new Triangle(x, y, z);
	}
};
void testFactory()
{
	std::unique_ptr<FigureFactory> TriFactory(new CreateTriangle());
	std::unique_ptr<FigureFactory> RecFactory(new CreateRectangle());
	std::unique_ptr<FigureFactory> CirFactory(new CreateCircle());

	std::unique_ptr<Figure> ptri(TriFactory->create());
	std::unique_ptr<Figure> prec(RecFactory->create());
	std::unique_ptr<Figure> pcir(CirFactory->create());
	print(*ptri);
	print(*prec);
	print(*pcir);
	
}
int main()
{
	//testStaticFactory();
	testFactory();
	cout<<"---------"<<endl;
	return 0;
}
