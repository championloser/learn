#include<iostream>
using std::cout;
using std::endl;
class Base
{
public:
	virtual void print()
	{
		cout<<"Base::print()"<<endl;
	}
};
class Derived : public Base
{
public:
	virtual void print()
	{
		cout<<"Derived::print()"<<endl;
	}
private:
	int _ix;
};
void display(Base &bas)
{
	bas.print();
}
int test0()
{
	Base bas;
	Derived der;
	display(bas);
	display(der);
	return 0;
}
int main()
{
	cout<<"sizeof(Base)="<<sizeof(Base)<<endl;
	cout<<"sizeof(Derived)="<<sizeof(Derived)<<endl;
}
