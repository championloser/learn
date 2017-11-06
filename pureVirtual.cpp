#include<iostream>
using std::cout;
using std::endl;
class Base
{
public:
	virtual void display()=0;
	virtual void print()=0;
};
class Derived : public Base
{
public:
	//virtual void display()
	//{
	//	cout<<"Derived::display()"<<endl;
	//}
};
int main()
{
	cout<<sizeof(Derived)<<endl;
	return 0;
}
