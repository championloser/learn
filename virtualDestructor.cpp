#include<string.h>
#include<iostream>
using std::cout;
using std::endl;
class Base
{
public:
	Base(const char *arr)
	: _arr(new char[strlen(arr)+1]())
	{
		cout<<"Base()"<<endl;
		strcpy(_arr,arr);
	}
	virtual void display()
	{
		cout<<_arr<<endl;
	}
	virtual ~Base()
	{
		cout<<"~Base()"<<endl;
		delete [] _arr;
	}
private:
	char *_arr;
};
class Sub : public Base
{
public:
	Sub(const char *arr1, const char *arr2)
	: Base(arr1)
	, _arr(new char[strlen(arr2)+1]())
	{
		cout<<"Sub()"<<endl;
		strcpy(_arr, arr2);
	}
	void display()
	{
		cout<<_arr<<endl;
	}
	~Sub()
	{
		cout<<"~Sub()"<<endl;
		delete [] _arr;
	}
private:
	char *_arr;
};
int test0()
{
	Sub sub("hello", "world");
	sub.display();
	return 0;
}
int test1()
{
	Sub *psub=new Sub("hello", "world");
	psub->display();
	delete psub;
	return 0;
}
int test2()
{
	Base *p=new Sub("hello", "world");
	p->display();
	delete p;
	return 0;
}
int main()
{
	//test0();
	//test1();
	test2();
	return 0;
}
