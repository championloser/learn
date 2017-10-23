#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
using namespace std;
class String
{
private:
	class Char
	{
	public:
		Char(char **arr,int pos)
		: _parr(arr)
		, _pos(pos)
		{}
		Char & operator=(char rhs)
		{
			int len=strlen(*_parr);
			char *tmp=new char[len+2]();
			strcpy(tmp,*_parr);
			--(*_parr)[len+1];
			*_parr=tmp;
			(*_parr)[len+1]=1;
			(*_parr)[_pos]=rhs;
			return *this;
		}
		friend ostream & operator<<(ostream &out, const Char &rhs);
	private:
		char **_parr;
		int _pos;
	};
public:
	String();
	String(const char *);
	String(const String &);
	~String();
	char * c_str();
	int getRefCount()
	{
		return _arr[_size+1];
	}
	String & operator=(const String &rhs);
	//char & operator[](int);
	Char  operator[](int idx);
	friend ostream & operator<<(ostream &out, const String &rhs);
	friend ostream & operator<<(ostream &out, const Char &rhs);
private:
	void initRefCount()
	{
		_arr[_size+1]=1;
	}
	void increaseRefCount()
	{
		++_arr[_size+1];
	}
	void decreaseRefCount()
	{
		--_arr[_size+1];
	}
	char *_arr;
	int _size;
};
String::String()
: _arr(new char[2]())
, _size(0)
{
	initRefCount();
}
String::String(const char *arr)
: _arr(new char[strlen(arr)+2]())
, _size(strlen(arr))
{
	strcpy(_arr,arr);
	initRefCount();
}
String::String(const String &rhs)
: _arr(rhs._arr)
, _size(rhs._size)
{
	increaseRefCount();
}
String::~String()
{
	decreaseRefCount();
	if(0==getRefCount())delete [] _arr;
}
char * String::c_str()
{
	return _arr;
}
String & String::operator=(const String &rhs)
{
	decreaseRefCount();
	if(0==getRefCount())delete [] _arr;
	_arr=rhs._arr;
	_size=rhs._size;
	increaseRefCount();
	return *this;
}
//char & String::operator[](int idx)
//{
//	if(getRefCount()>1)
//	{
//		decreaseRefCount();
//		char *tmp=new char[_size+2]();
//		strcpy(tmp,_arr);
//		_arr=tmp;
//		initRefCount();
//	}
//	return _arr[idx];
//}
String::Char String::operator[](int idx)
{
	if(idx<_size+1)return Char(&_arr,idx);
	else {cout<<"数组访问越界"<<endl;exit(1);}
}
ostream & operator<<(ostream &out, const String &rhs)
{
	out<<rhs._arr;
	return out;
}
ostream & operator<<(ostream &out, const String::Char &rhs)
{
	out<<*(rhs._parr)[rhs._pos];
	return out;
}
int main()
{
	String str1="hello world";
	String str2(str1);
	String *str3=new String(str1);
	String str4="jiangjiaxian";
	printf("&str1=%p,RefCount=%d,",str1.c_str(),str1.getRefCount());cout<<"str1="<<str1<<endl;
	printf("&str2=%p,RefCount=%d,",str2.c_str(),str2.getRefCount());cout<<"str2="<<str2<<endl;
	printf("&str3=%p,RefCount=%d,",str3->c_str(),str3->getRefCount());cout<<"str3="<<*str3<<endl;
	printf("&str4=%p,RefCount=%d,",str4.c_str(),str4.getRefCount());cout<<"str4="<<str4<<endl;
	cout<<endl;

	str2=str4;
	printf("&str1=%p,RefCount=%d,",str1.c_str(),str1.getRefCount());cout<<"str1="<<str1<<endl;
	printf("&str2=%p,RefCount=%d,",str2.c_str(),str2.getRefCount());cout<<"str2="<<str2<<endl;
	printf("&str3=%p,RefCount=%d,",str3->c_str(),str3->getRefCount());cout<<"str3="<<*str3<<endl;
	printf("&str4=%p,RefCount=%d,",str4.c_str(),str4.getRefCount());cout<<"str4="<<str4<<endl;
	cout<<endl;

	cout<<str1[0]<<endl;
	printf("&str1=%p,RefCount=%d,",str1.c_str(),str1.getRefCount());cout<<"str1="<<str1<<endl;
	printf("&str2=%p,RefCount=%d,",str2.c_str(),str2.getRefCount());cout<<"str2="<<str2<<endl;
	printf("&str3=%p,RefCount=%d,",str3->c_str(),str3->getRefCount());cout<<"str3="<<*str3<<endl;
	printf("&str4=%p,RefCount=%d,",str4.c_str(),str4.getRefCount());cout<<"str4="<<str4<<endl;
	cout<<endl;

	str1[0]='H';
	printf("&str1=%p,RefCount=%d,",str1.c_str(),str1.getRefCount());cout<<"str1="<<str1<<endl;
	printf("&str2=%p,RefCount=%d,",str2.c_str(),str2.getRefCount());cout<<"str2="<<str2<<endl;
	printf("&str3=%p,RefCount=%d,",str3->c_str(),str3->getRefCount());cout<<"str3="<<*str3<<endl;
	printf("&str4=%p,RefCount=%d,",str4.c_str(),str4.getRefCount());cout<<"str4="<<str4<<endl;
	return 0;
}
