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
	void callBase1()
	{
		func(5);
	}
	void callBase2()
	{
		Base::func(10);
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
	void callSub1()
	{
		func(15);
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
void test2()
{
	Base bas;
	Sub sub;
	
	Base *p=&bas;
	p->callBase1();
	p->callBase2();

	p=&sub;
	p->callBase1();
	p->callBase2();
	//p->callSub1();
}
int main()
{
	//test0();
	//test1();
	test2();
	cout<<"sizeof(Base)="<<sizeof(Base)<<endl;
	cout<<"sizeof(Sub)="<<sizeof(Sub)<<endl;
	return 0;
}
