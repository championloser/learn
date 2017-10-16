/**********************************************************
 > Filename     : stringclass.cpp
 > Author       : Jeyshon<jeyshon@qq.com>
 > Create time  : 2017-10-16 17:44:04
 > Last modified: 2017-10-16 18:10:48
**********************************************************/
#include<iostream>
#include<string.h>
using namespace std;
class String
{
public:
	String();
	String(const char *p);
	String(const String &rhs);
	String & operator=(const String &rhs);
	void Print();
	int length();
	char* c_str();
	~String();
private:
	char *_str;
	int _len;
};
String::String()
: _str(new char[10]())
, _len(0)
{
}
String::String(const char *p)
: _str(new char[strlen(p)+1]())
, _len(strlen(p))
{
	cout<<"String(const char *p)"<<endl;
	strcpy(_str,p);
}
String::String(const String & rhs)
: _str(new char[strlen(rhs._str)+1])
, _len(rhs._len)
{
	cout<<"String(const String &rsh)"<<endl;
	strcpy(_str,rhs._str);
}
String & String::operator=(const String &rhs)
{
	delete [] _str;
	_str=new char[strlen(rhs._str)+1]();
	strcpy(_str,rhs._str);
	_len=rhs._len;
	return *this;
}
void String::Print()
{
	cout<<_str<<endl;
}
int String::length()
{
	return _len;
}
char* String::c_str()
{
	return _str;
}
String::~String()
{
	cout<<"~String()"<<endl;
	delete [] _str;
}
int main()
{
	//String str1("hello world");
	//char *tmp=str1.c_str();
	//str1.Print();
	//tmp[0]='H';
	//str1.Print();
	
	//String str1("hello world");
	//String str2(str1);
	//str2.Print();
	
	String str1;
	str1="hello world";
	str1.c_str()[0]='H';
	str1.Print();
	cout<<str1.length()<<endl;
	return 0;
}
