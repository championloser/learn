/**********************************************************
 > Filename     : computer2.cpp
 > Author       : Jeyshon<jeyshon@qq.com>
 > Create time  : 2017-10-16 11:45:06
 > Last modified: 2017-10-16 11:45:17
**********************************************************/
#include<iostream>
#include<string.h>
using namespace std;
class Computer
{
public:
	Computer(const char *brand,float price);
	~Computer();
	Computer& operator=(const Computer &rhs);
	void setcomputer(const char *brand,float price);
	void print();
private:
	char *_brand;
	float _price;
};
Computer::Computer(const char *brand,float price)
:_brand(new char[50]())
,_price(price)
{
	strcpy(_brand,brand);
	cout<<"Comoputer()"<<endl;
}
Computer::~Computer()
{
	delete []_brand;
	cout<<"~Computer()"<<endl;
}
Computer& Computer::operator=(const Computer &rhs)
{
	strcpy(_brand,rhs._brand);
	_price=rhs._price;
	return *this;
}
void Computer::setcomputer(const char *brand,float price)
{
	strcpy(_brand,brand);
	_price=price;
}
void Computer::print()
{
	cout<<"("<<_brand<<","<<_price<<")"<<endl;
}
int main()
{
	Computer com("LENOVO",4500);
	com.print();
	Computer com2("HP",5000);
	com2.print();
	//com2=com;
	com2.operator=(com);
	com2.print();
	return 0;
}
