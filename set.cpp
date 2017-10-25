#include<math.h>
#include<iostream>
#include<set>
using std::cout;
using std::endl;
using std::set;
using std::multiset;
void test0()
{
	set<int, std::greater<int>> setInt{1,4,5,6,7,3,1,8,4,2};
	set<int>::const_iterator it;
	for(it=setInt.begin(); it!=setInt.end(); ++it)
	{
		cout<<*it<<" ";
	}
	cout<<endl;
}
void test1()
{
	multiset<int, std::greater<int>> multisetInt{1,4,5,6,7,3,1,8,4,2};
	multiset<int>::const_iterator it;
	for(it=multisetInt.begin(); it!=multisetInt.end(); ++it)
	{
		cout<<*it<<" ";
	}
	cout<<endl;
}
class Point
{
public:
	Point(int x, int y)
	: _ix(x)
	, _iy(y)
	{}
	float getDistance() const;
	friend std::ostream & operator<<(std::ostream &out, const Point &rhs);
	friend bool operator<(const Point &lhs, const Point &rhs);
	friend bool operator>(const Point &lhs, const Point &rhs);
private:
	int _ix;
	int _iy;
};
float Point::getDistance() const
{
	return sqrt(_ix*_ix+_iy*_iy);
}
std::ostream & operator<<(std::ostream &out, const Point &rhs)
{
	out<<"("<<rhs._ix<<","<<rhs._iy<<")";
	return out;
}
bool operator<(const Point &lhs, const Point &rhs)
{
	return lhs.getDistance()<rhs.getDistance();
}
bool operator>(const Point &lhs, const Point &rhs)
{
	return lhs.getDistance()>rhs.getDistance();
}
void test2()
{
	set<Point, std::less<Point>> setPoint{
		Point(1,2),
		Point(2,3),
		Point(3,4),
		Point(-1,0),
		Point(-2,1)
	};
	set<Point>::const_iterator it;
	for(it=setPoint.begin(); it!=setPoint.end(); ++it)
	{
		cout<<*it<<" ";
	}
	cout<<endl;
}
void test3()
{
	set<Point, std::greater<Point>> setPoint{
		Point(1,2),
		Point(2,3),
		Point(3,4),
		Point(-1,0),
		Point(-2,1)
	};
	set<Point>::const_iterator it;
	for(it=setPoint.begin(); it!=setPoint.end(); ++it)
	{
		cout<<*it<<" ";
	}
	cout<<endl;
}
int main()
{
	//test0();
	//test1();
	test2();
	test3();
	return 0;
}
