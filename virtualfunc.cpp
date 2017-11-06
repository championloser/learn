#include<iostream>
using std::cout;
using std::endl;
using std::cin;
class Base
{
public:
	virtual int func(int x)
	{
		cout<<"Base::func(int x)"<<endl;
		return x;
	}
};
class Sub
: public Base
{
public:
	virtual int func(int x)
	{
		cout<<"Sub::func(int x)"<<endl;
		return x;
	}
};
void display(Base *p)
{
	p->func(10);
}
int main()
{
	Base base;
	Sub sub;
	//base.func(10);
	//sub.func(20);
	display(&base);
	display(&sub);
	return 0;
}
