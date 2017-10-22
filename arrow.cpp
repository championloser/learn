#include<iostream>
using namespace std;
class Data
{
public:
	Data()
	: _size(0)
	{}
	void length()
	{
		cout<<"size="<<_size<<endl;
	}
private:
	int _size;
};
class DataPtr
{
public:
	DataPtr()
	: _pData(new Data)
	{}
	Data * operator->()
	{
		return _pData;
	}
	Data & operator*()
	{
		return *_pData;
	}

private:
	Data *_pData;
};
class Third
{
public:
	Third()
	: _dp(new DataPtr)
	{}
	DataPtr & operator->()
	{
		return *_dp;
	}
private:
	DataPtr *_dp;
};
class Fourth
{
public:
	Fourth()
	: _th(new Third)
	{}
	Third & operator->()
	{
		return *_th;
	}
private:
	Third *_th;
};
int main()
{
	DataPtr dp;
	cout<<"Twice"<<endl;
	dp->length();
	dp.operator->()->length();
	(*dp).length();
	cout<<endl;

	DataPtr *pdp=new DataPtr();
	(*(*pdp)).length();
	cout<<endl;

	Third thi;
	cout<<"Third"<<endl;
	thi->length();
	thi.operator->().operator->()->length();
	cout<<endl;

	Fourth fou;
	cout<<"Fourth"<<endl;
	fou->length();
	fou.operator->().operator->().operator->()->length();
	return 0;
}
