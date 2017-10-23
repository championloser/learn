 ///
 /// @file    cowString.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-07-28 11:02:25
 ///
 
#include <stdio.h>
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;


class String
{
	//设计模式之代理模式
	class CharProxy
	{
	public:
		CharProxy(String & str, size_t idx)
		: _str(str)
		, _idx(idx)
		{
		}
		CharProxy & operator=(const char & ch);

		operator char()
		{
			return _str._pstr[_idx];
		}

		//friend std::ostream & operator<<(std::ostream & os, const CharProxy & rhs);
	private:
		String & _str;
		size_t _idx;
	};
public:
	String();
	String(const char * pstr);
	String(const String & rhs);
	String & operator=(const String & rhs);

	~String();

	//char & operator[](size_t idx);
	CharProxy operator[](size_t idx);

	const char * c_str() const
	{	return _pstr;	}

	size_t size() const
	{	return strlen(_pstr);	}

	size_t refcount() const
	{	return _pstr[size() + 1];	}

	friend std::ostream & operator<<(std::ostream & os, const String & rhs);

private: 
	void initRefcount()
	{	_pstr[size() + 1] = 1;	}

	void increaseRefcount()
	{	++_pstr[size() + 1];	}

	void decreaseRefcount()
	{	--_pstr[size() + 1];	}

private:
	char * _pstr;
};

String::String()
: _pstr(new char[2]())
{
	cout << "String()" << endl;
	initRefcount();//表达了语义
}

String::String(const char * pstr)
: _pstr(new char[strlen(pstr) + 2]())
{
	cout << "String(const char *)" << endl;
	strcpy(_pstr, pstr);
	initRefcount();//先copy，再初始化refcount
}

String::String(const String & rhs)
: _pstr(rhs._pstr) //浅拷贝
{
	increaseRefcount();
}

String & String::operator=(const String & rhs)
{
	if(this != &rhs)
	{
		decreaseRefcount();//左操作数refcount减1
		if(refcount() == 0)
		{
			delete [] _pstr;//只有当refcount变为0时，才去回收左操作数的空间
			cout << "delete lhs._pstr" << endl;
		}

		_pstr = rhs._pstr;//再去做浅拷贝
		increaseRefcount();
	}
	return *this;
}

String::~String()
{
	decreaseRefcount();
	if(refcount() == 0)
	{
		delete [] _pstr;
		cout << "~String()" << endl;
	}
}

std::ostream & operator<<(std::ostream & os, const String & rhs)
{
	os << rhs._pstr;
	return os;
}

//问题: 下标访问运算符本身并不能区分出是读操作还是写操作?
#if 0
char & String::operator[](size_t idx)
{
	if(idx < size())
	{
		if(refcount() > 1)
		{
			decreaseRefcount();
			char * ptmp = new char[size() + 2]();//深拷贝
			strcpy(ptmp, _pstr);

			_pstr = ptmp;
			initRefcount();
		}
		return _pstr[idx];
	}
	else
	{
		static char nullchar = '\0';
		cout << "数组越界" << endl;
		return nullchar;
	}
}
#endif

String::CharProxy String::operator[](size_t idx)
{
	return CharProxy(*this, idx);
}

//写操作
String::CharProxy & String::CharProxy::operator=(const char & ch)
{
	if(_idx < _str.size())
	{
		if(_str.refcount() > 1)
		{
			_str.decreaseRefcount();	
			char * ptmp = new char[_str.size() + 2]();
			strcpy(ptmp, _str._pstr);

			_str._pstr = ptmp;//关键步骤
			_str.initRefcount();
		}
		_str._pstr[_idx] = ch;
	}
	return *this;
}


int main(void)
{
	String str;
	cout << str << endl;
	cout << "str's refcount = " << str.refcount() << endl;
	printf("&str = %p\n", str.c_str());

	String str2("hello,world");
	String str3(str2);
	cout << "str2 = " << str2 << endl;
	cout << "str3 = " << str3 << endl;
	cout << "str2's refcount = " << str2.refcount() << endl;
	cout << "str3's refcount = " << str3.refcount() << endl;
	printf("&str2 = %p\n", str2.c_str());
	printf("&str3 = %p\n", str3.c_str());
	cout << endl;

	str = str2;//str引用计数为1
	cout << "str = " << str << endl;
	cout << "str's refcount = " << str.refcount() << endl;
	cout << "str2's refcount = " << str2.refcount() << endl;
	cout << "str3's refcount = " << str3.refcount() << endl;
	printf("&str = %p\n", str.c_str());
	printf("&str2 = %p\n", str2.c_str());
	printf("&str3 = %p\n", str3.c_str());
	cout << "---------" << endl;

	String str4 = "wangdao";
	String str5(str4);
	cout << "str4 = " << str4 << endl;
	cout << "str5 = " << str5 << endl;
	printf("&str4 = %p\n", str4.c_str());
	printf("&str5 = %p\n", str5.c_str());
	cout << "str4's refcount = " << str4.refcount() << endl;
	cout << "str5's refcount = " << str5.refcount() << endl;
	cout << endl;

	str4 = str2;//str4引用计数为2
	cout << "str = " << str << endl;
	cout << "str's refcount = " << str.refcount() << endl;
	cout << "str2's refcount = " << str2.refcount() << endl;
	cout << "str3's refcount = " << str3.refcount() << endl;
	cout << "str4's refcount = " << str4.refcount() << endl;
	cout << "str5's refcount = " << str5.refcount() << endl;
	printf("&str = %p\n", str.c_str());
	printf("&str2 = %p\n", str2.c_str());
	printf("&str3 = %p\n", str3.c_str());
	printf("&str4 = %p\n", str4.c_str());
	printf("&str5 = %p\n", str5.c_str());

	cout << endl << "----做写操作" << endl;
	str[0] = 'X';
	cout << "str = " << str << endl;
	cout << "str's refcount = " << str.refcount() << endl;
	cout << "str2's refcount = " << str2.refcount() << endl;
	cout << "str3's refcount = " << str3.refcount() << endl;
	cout << "str4's refcount = " << str4.refcount() << endl;

	printf("&str = %p\n", str.c_str());
	printf("&str2 = %p\n", str2.c_str());
	printf("&str3 = %p\n", str3.c_str());
	printf("&str4 = %p\n", str4.c_str());

	cout << endl << "---做读操作" << endl;
	cout << str2[0] << endl;

	cout << "str2 = " << str2 << endl;
	cout << "str3 = " << str3 << endl;
	cout << "str4 = " << str4 << endl;
	cout << "str2's refcount = " << str2.refcount() << endl;
	cout << "str3's refcount = " << str3.refcount() << endl;
	cout << "str4's refcount = " << str4.refcount() << endl;

	printf("&str2 = %p\n", str2.c_str());
	printf("&str3 = %p\n", str3.c_str());
	printf("&str4 = %p\n", str4.c_str());

	return 0;
}
