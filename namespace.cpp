#include<iostream>
using namespace std;
int num=1000;
namespace B
{
	int num=5;
}
namespace A
{
	int num=100;
	void displayA()
	{
		cout<<"displayA()"<<endl;
		cout<<"B::num="<<B::num<<endl;
	}
}
namespace B
{
	void displayB(int num)
	{
		cout<<"displayB()"<<endl;
		cout<<"num="<<num<<endl;
		cout<<"A::num="<<A::num<<endl;
		cout<<"B::num="<<B::num<<endl;
		cout<<"::num="<<::num<<endl;
	}
}
void test()
{
	using A::displayA;
	using B::displayB;
	displayB(4);
	displayA();
}
int main()
{
	test();
	return 0;
}
