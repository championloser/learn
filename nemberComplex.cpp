/**********************************************************
  > Filename     : nemberComplex.cpp
  > Author       : Jeysin<jeysin@qq.com>
  > Create time  : 2017-10-20 17:26:54
  > Last modified: 2017-10-20 18:14:36
 **********************************************************/
#include<iostream>
using namespace std;
class Complex
{
public:
	Complex(int real, int imag);
	void printComplex();
	Complex operator+(const Complex &rhs);
	void operator+=(const Complex &rhs);
private:
	double _real;
	double _imag;
};
Complex::Complex(int real, int imag)
: _real(real)
, _imag(imag)
{}
void Complex::printComplex()
{
	if(_real==0 && _imag==0)cout<<"0";
	else if(_real!=0 && _imag==0)cout<<_real;
	else if(_real==0 && _imag!=0)cout<<_real<<"i";
	else if(_real!=0 && _imag!=0)
	{
		cout<<_real;
		if(_imag>0)cout<<"+"<<_imag<<"i";
		else cout<<_imag<<"i";
	}
	cout<<endl;
}
Complex Complex::operator+(const Complex &rhs)
{
	return Complex(_real+rhs._real,_imag+rhs._imag);
}
void Complex::operator+=(const Complex &rhs)
{
	_real=_real+rhs._real;
	_imag=_imag+rhs._imag;
}
int main()
{
	Complex com1(4,3);
	com1.printComplex();
	Complex com2(1,2);
	com2.printComplex();
	Complex com3=com1+com2;
	//Complex com3=com1.operator+(com2);
	com3.printComplex();

	com3+=com1;
	com3.printComplex();
	return 0;
}
