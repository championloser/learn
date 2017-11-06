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
#if 1
	virtual int func(int x)
	{
		cout<<"Sub::func(int x)"<<endl;
		return x;
	}
#endif
#if 0
	int func()
	{
		cout<<"Sub::func()"<<endl;
		return 0;
	}
#endif
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
int main()
{
	test0();
	cout<<"sizeof(Base)="<<sizeof(Base)<<endl;
	cout<<"sizeof(Sub)="<<sizeof(Sub)<<endl;
	return 0;
}
