/**********************************************************
 > Filename     : computer3.cpp
 > Author       : Jeyshon<jeyshon@qq.com>
 > Create time  : 2017-10-16 16:27:23
 > Last modified: 2017-10-16 17:03:17
**********************************************************/
#include<iostream>
#include<string.h>
using namespace std;
class Computer
{
public:
	Computer(const char *brand,float price);
	Computer(const Computer& rhs);
	Computer & operator=(const Computer &rhs);
	~Computer();
	void SetComputer(const char *brand,float price);
	void Print();
	void Print() const;
	static void func(Computer &rhs);
private:
	char *_brand;
	float _price;
	static float  _totalprice;
};
float Computer::_totalprice=0.0;
Computer::Computer(const char *brand,float price)
: _brand(new char[20]())
, _price(price)
{
	strcpy(_brand,brand);
	cout<<"Computer()"<<endl;
	_totalprice += _price;
}
Computer::Computer(const Computer& rhs)
: _brand(new char[20]())
, _price(rhs._price)
{
	cout<<"Computer(const Computer& rhs)"<<endl;
	strcpy(_brand,rhs._brand);
	_totalprice += _price;
}
Computer & Computer::operator=(const Computer &rhs)
{
	strcpy(_brand,rhs._brand);
	_price=rhs._price;
	return *this;
}
Computer::~Computer()
{
	delete [] _brand;
	cout<<"~Computer()"<<endl;
	_totalprice -= _price;
}
void Computer::SetComputer(const char *brand,float price)
{
	strcpy(_brand,brand);
	_price=price;
}
void Computer::Print()
{
	cout<<"Print()"<<endl;
	cout<<"brand:"<<_brand<<endl;
	cout<<"price:"<<_price<<endl;
	cout<<"totalprice:"<<_totalprice<<endl;
}
void Computer::Print() const
{
	cout<<"Print() const"<<endl;
	cout<<"brand:"<<_brand<<endl;
	cout<<"price:"<<_price<<endl;
	cout<<"totalprice:"<<_totalprice<<endl;
}
void Computer::func(Computer &rhs)
{
	cout<<"brand:"<<rhs._brand<<endl;
	cout<<"price:"<<rhs._price<<endl;
	cout<<"totalprice:"<<_totalprice<<endl;
}
int main()
{
	Computer com("liangxiang",5000.00);
	cout<<endl;
	Computer::func(com);

	//{
	//	Computer com1("sanxing",4000.00);
	//	com1.Print();
	//}
	//Computer com2("huasuo",3000.00);
	//com2.Print();

	//Computer com1(com);
	//com1.Print();
	
	//Computer com2("huipu",6000.23);
	//com2.Print();
	//com2=com;
	////com2.operator=(com);
	//com2.Print();

	return 0;
}
