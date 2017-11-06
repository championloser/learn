#include<iostream>
using std::cout;
using std::endl;
class A
{
public:
	A(int a)
	: _ia(a)
	{
		cout<<"A()"<<endl;
	}
	~A()
	{
		cout<<"~A()"<<endl;
	}
	int geta()
	{
		return _ia;
	}
private:
	int _ia;
};
class B1 : virtual public A
{
public:
	B1(int a, int b)
	: A(a)
	, _ib1(b)
	{
		cout<<"B1()"<<endl;
	}
	~B1()
	{
		cout<<"~B1()"<<endl;
	}
	int getb1()
	{
		return _ib1;
	}
private:
	int _ib1;
};
class B2 : virtual public A
{
public:
	B2(int a, int b)
	: A(a)
	, _ib2(b)
	{
		cout<<"B2()"<<endl;
	}
	~B2()
	{
		cout<<"~B2()"<<endl;
	}
	int getb2()
	{
		return _ib2;
	}
private:
	int _ib2;
};
class C : public B1, public B2
{
public:
	C(int a1, int b1, int a2, int b2)
	: A(a1)
	, B1(a1, b1)
	, B2(a2, b2)
	{
		cout<<"C()"<<endl;
	}
	~C()
	{
		cout<<"~C()"<<endl;
	}
};
int main()
{
	C c(1,2,3,4);
	cout<<"A::_ia="<<c.geta()<<endl;
	cout<<"B1::_ib1="<<c.getb1()<<endl;
	cout<<"B2::_ib2="<<c.getb2()<<endl;
	return 0;
}
