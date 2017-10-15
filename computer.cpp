/**********************************************************
 > Filename     : computer.cpp
 > Author       : Jeyshon
 > Email        : Jeyshon@qq.com
 > Create time  : 2017-10-15 21:37:46
 > Last modified: 2017-10-15 21:48:33
**********************************************************/
#include<iostream>
#include<string>
using namespace std;
class Computer
{
public:
	void print()
	{
		cout<<"brand="<<_brand<<endl;
		cout<<"price="<<_price<<endl;
	}
	void setprice(double price)
	{
		_price=price;
	}
	void setbrand(string brand)
	{
		_brand=brand;
	}
private:
	double _price;
	string _brand;
};
struct A
{
	void seta(int a)
	{_a=a;}
	void print()
	{cout<<"_a="<<_a<<endl;}
	int _a;
};
int main()
{
	Computer com;
	com.setprice(234.45);
	com.setbrand("LENOVO");
	com.print();
	A abc;
	abc.seta(7);
	abc._a=3;
	abc.print();
	return 0;
}
