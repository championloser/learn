#include<math.h>
#include<iostream>
#include<string>
#include<vector>
#include<map>
using std::cout;
using std::endl;
using std::map;
using std::pair;
using std::string;
using std::vector;
using std::make_pair;
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
void test0()
{
	map<int,Point,std::greater<int> > mapIntStr{
		make_pair(5, Point(1,2)),
		make_pair(4, Point(2,3)),
		make_pair(6, Point(3,4)),
		make_pair(9, Point(-1,2))
	};
	map<int, string> mapInt2{
		make_pair(3, string("jiang")),
		make_pair(4, string("jiaxian"))
	};
	//cout<<mapInt2[1]<<endl;
	map<int, Point>::iterator mit;
	mit=mapIntStr.find(2);
	if(mit!=mapIntStr.end())
	{
		cout<<mit->second<<endl;
	}else{
		cout<<"not found"<<endl;
	}
	//map<int, Point>::const_iterator it;
	//for(it=mapIntStr.begin(); it!=mapIntStr.end(); ++it)
	//{
	//	cout<<it->first<<"--->"<<it->second<<endl;
	//}
}
void test1()
{
	vector<int> numbers{1,2,3,4,5,6};
	vector<int>::const_iterator it;
	for(it=numbers.begin(); it!=numbers.end(); ++it)
	{
		cout<<*it<<" ";
	}
	cout<<endl;
}
int main()
{
	test0();
	//test1();
	return 0;
}
