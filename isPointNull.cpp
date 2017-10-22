#include<iostream>
using namespace std;
class A
{};
static int *p;
static int i;
static A *pa;
int *str;
int main()
{
	static int *str1;
	static int a;
	if(NULL==str1)cout<<"true"<<endl;
	else cout<<"false"<<endl;
	cout<<a<<endl;
	return 0;
}
