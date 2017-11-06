#include<iostream>
using std::cout;
using std::endl;
class Base
{
public:
	virtual int func(int x)
	{
		cout<<"Base::func(int x)"<<endl;
		return x;
	}
};
class Sub : public Base
{
public:
	virtual int func(int x)
	{
		cout<<"Sub::func(int x)"<<endl;
		return x;
	}
};
void display(Base &bas)
{
	bas.func(10);
}
void test0()
{
	Base bas;
	Sub sub;
	display(bas);
	display(sub);
}
void test1()
{
	Base bas;
	Sub sub;
	bas.func(10);
	sub.func(30);
}
int main()
{
	//test0();
	test1();
	cout<<"sizeof(Base)="<<sizeof(Base)<<endl;
	cout<<"sizeof(Sub)="<<sizeof(Sub)<<endl;
	return 0;
}
