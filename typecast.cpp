#include<iostream>
using namespace std;
class Point
{
public:
	Point(int x, int y)
	: _ix(x)
	, _iy(y)
	{}
	operator int();
	friend ostream & operator<<(ostream &out, const Point &rhs);
private:
	int _ix;
	int _iy;
};
ostream & operator<<(ostream &out, const Point &rhs)
{
	out<<"("<<rhs._ix<<","<<rhs._iy<<")";
	return out;
}
Point::operator int()
{
	return _iy;
}
int main()
{
	Point poi(1,2);
	cout<<poi<<endl;
	int i;
	i=poi;
	cout<<i<<endl;
	return 0;
}
