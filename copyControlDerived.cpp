#include<string.h>
#include<iostream>
using std::cout;
using std::endl;
class Base
{
public:
	Base(const char * arr)
	: _arr(new char[strlen(arr)+1]())
	{
		strcpy(_arr, arr);
	}
	Base(const Base &rhs)
	: _arr(new char[strlen(rhs._arr)+1]())
	{
		cout<<"Base(const Base &rhs)"<<endl;
		strcpy(_arr, rhs._arr);
	}
	void print()
	{
		cout<<"Base::_arr="<<_arr<<endl;
	}
	Base & operator=(const Base &rhs)
	{
		cout<<"operator=(cosnt Base &rhs)"<<endl;
		if(this!=&rhs)
		{
			delete [] _arr;
			_arr=new char[strlen(rhs._arr)+1]();
			strcpy(_arr, rhs._arr);
		}
		return *this;
	}
private:
	char *_arr;
};
class Derived
: public Base
{
public:
	Derived(const char *arr1, const char *arr2)
	: Base(arr1)
	, _arr(new char[strlen(arr2)+1]())
	{
		strcpy(_arr, arr2);
	}
	Derived(const Derived &rhs)
	: Base(rhs)
	, _arr(new char[strlen(rhs._arr)+1]())
	{
		strcpy(_arr, rhs._arr);
	}
	void print()
	{
		cout<<"Derived::_arr="<<_arr<<endl;
	}
	Derived & operator=(const Derived &rhs)
	{
		Base::operator=(rhs);
		cout<<"operator=(const Derived &rhs)"<<endl;
		if(this!=&rhs)
		{
			delete [] _arr;
			_arr=new char[strlen(rhs._arr)+1]();
			strcpy(_arr, rhs._arr);
		}
		return *this;
	}
private:
	char *_arr;
};
int test0()
{
	Derived der1("hello", "world");
	cout<<"der1: ";der1.Base::print();
	cout<<"der1: ";der1.print();
	Derived der2("jia", "xian");
	cout<<"der2: ";der2.Base::print();
	cout<<"der2: ";der2.print();
	cout<<endl;
	der2=der1;
	cout<<"der2: ";der2.Base::print();
	cout<<"der2: ";der2.print();
	return 0;
}
int test1()
{
	Derived der1("hello", "world");
	cout<<"der1: ";der1.Base::print();
	cout<<"der1: ";der1.print();
	Derived der2(der1);
	cout<<"der2: ";der2.Base::print();
	cout<<"der2: ";der2.print();
	return 0;
}
int main()
{
	//test0();
	test1();
	return 0;
}
