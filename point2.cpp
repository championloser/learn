/**********************************************************
 > Filename     : point2.cpp
 > Author       : Jeyshon
 > Email        : jeyshon@qq.com
 > Create time  : 2017-10-16 09:31:44
 > Last modified: 2017-10-16 09:32:01
**********************************************************/
#include<iostream>
using namespace std;
class Point
{
public:
	Point(int x=2,int y=4);
	Point(const Point &p);
	~Point();
	void print();
	void setxy(int x,int y);
private:
	int _ix;
	int _iy;
};
Point::Point(int x,int y)
:_ix(x)
,_iy(y)
{
	cout<<"Point(int,int)"<<endl;
}
Point::Point(const Point &p)
:_ix(p._ix)
,_iy(p._iy)
{
	cout<<"Point(const Point &p)"<<endl;
}
Point::~Point()
{
	cout<<"~Point()"<<endl;
}
void Point::print()
{
	cout<<"("<<_ix<<","<<_iy<<")"<<endl;
}
void Point::setxy(int x,int y)
{
	_ix=x;
	_iy=y;
}
int main()
{
	Point poi(5,6);
	poi.print();
	Point poi1(poi);
	poi1.print();
	Point poi2(Point(1,2));
	poi2.print();
	return 0;
}
