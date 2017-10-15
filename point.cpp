/**********************************************************
 > Filename     : point.cpp
 > Author       : Jeyshon
 > Email        : Jeyshon@qq.com
 > Create time  : 2017-10-15 21:49:05
 > Last modified: 2017-10-15 21:49:05
**********************************************************/
#include<iostream>
using namespace std;
class Point
{
public:
	Point(int x=0,int y=0)
	{_ix=x;_iy=y;}
	void print()
	{
		cout<<"("<<_ix<<","<<_iy<<")"<<endl;
	}
private:
	int _ix;
	int _iy;
};
int main()
{
	Point poi;
	poi.print();
	return 0;
}
