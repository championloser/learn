#include<iostream>
#include<functional>
using std::cout;
using std::endl;
using std::bind;
using std::function;
int func(int x, int y)
{
	return x+y;
}
struct Foo
{
	Foo()
	: _x(10)
	{}
	int add(int x, int y)
	{
		return x+y;
	}
	int _x;
};
int test0()
{
	std::function<int(int)> f1=bind(func, 2, std::placeholders::_1);
	cout<<f1(2)<<endl;
	auto f2=bind(func, 3, 4);
	cout<<f2()<<endl;
	return 0;
}
int test1()
{
	typedef int (*Function)(int, int);
	Function f1=func;
	cout<<f1(1,2)<<endl;
	return 0;
}
int test2()
{
	//function<int(int)> f1=bind(func, 2, std::placeholders::_1);	
	//cout<<f1(2)<<endl;
	Foo foo;
	function<int(int)> f2=bind(&Foo::add, &foo, 2, std::placeholders::_1);
	cout<<f2(3)<<endl;

	function<int()> f3=bind(&Foo::add, &foo, 2, 4);
	cout<<f3()<<endl;
	return 0;
}
void display(int n1, int n2, int n3, const int &n4, int n5)
{
	cout<<n1<<" "<<n2<<" "<<n3<<" "<<n4<<" "<<n5<<endl; 
}
int test3()
{
	using namespace std::placeholders;
	int n=6;
	auto f1=bind(display, _2, _1, 4, std::cref(n), n);
	f1(11,22,33,44,55,66);
	cout<<n<<endl;
	return 0;
}
int test4()
{
	Foo foo;
	auto f1=bind(&Foo::_x, &foo);
	cout<<f1()<<endl;
	return 0;
}
int main()
{
	//test0();
	//test1();
	//test2();
	//test3();
	test4();
	return 0;
}
