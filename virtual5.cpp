#include<iostream>
using std::cout;
using std::endl;
class Base0
{
public:
	Base0()
	{
		cout<<"Base0()"<<endl;
		func1();
	}
	virtual void func1()
	{
		cout<<"Base0::func1()"<<endl;
	}
	virtual void func2()
	{
		cout<<"Base0::func2()"<<endl;
	}
	~Base0()
	{
		cout<<"~Base0()"<<endl;
		func2();
	}
private:
	int _ix;
};
class Base1 : public Base0
{
public:
	Base1()
	{
		cout<<"Base1()"<<endl;
		func1();
	}
	virtual void func1()
	{
		cout<<"Base1::func1()"<<endl;
	}
	virtual void func2()
	{
		cout<<"Base1::func2()"<<endl;
	}
	~Base1()
	{
		cout<<"~Base1()"<<endl;
		func2();
	}
private:
	int _ix;
};
class Sub : public Base1
{
public:
	Sub()
	{
		cout<<"Sub()"<<endl;
		func1();
	}
	virtual void func1()
	{
		cout<<"Sub::func1()"<<endl;
	}
	virtual void func2()
	{
		cout<<"Sub::func2()"<<endl;
	}
	~Sub()
	{
		cout<<"~Sub()"<<endl;
		func2();
	}
};
int main()
{
	Sub sub;
	return 0;
}
