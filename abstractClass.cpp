#include<iostream>
using std::cout;
using std::endl;
class Base
{
public:
	void func()
	{
		cout<<"func::Base()"<<endl;
	}
protected:
	Base()
	{
		cout<<"Base()"<<endl;
	}
};
class Sub : public Base
{
};
int main()
{
	Sub sub;
	sub.func();
	return 0;
}
