#include<iostream>
using namespace std;
class Line
{
public:
	class LineImpl;
	Line(int x1, int y1, int x2, int y2);
	void printLine();
private:
	LineImpl *_pImpl;
};
class Line::LineImpl
{
private:
	class Point
	{
	public:
		Point(int x, int y)
		: _ix(x)
		, _iy(y)
		{}
		int getx() const 
		{return _ix;}
		int gety() const
		{return _iy;}
	private:
		int _ix;
		int _iy;
	};
public:
	LineImpl(int x1, int y1, int x2, int y2)
	: _poi1(x1,y1)
	, _poi2(x2,y2)
	{}
	void printLineImpl();
private:
	Point _poi1;
	Point _poi2;
};
void Line::LineImpl::printLineImpl()
{
	cout<<"("<<_poi1.getx()<<","<<_poi1.gety()<<")"
	    <<"---->"
	    <<"("<<_poi2.getx()<<","<<_poi2.gety()<<")"
	    <<endl;
}
Line::Line(int x1, int y1, int x2, int y2)
: _pImpl(new LineImpl(x1,y1,x2,y2))
{}
void Line::printLine()
{
	_pImpl->printLineImpl();
}
int main()
{
	Line line(1,2,3,4);
	line.printLine();
	return 0;
}
