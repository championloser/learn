#include<iostream>
using std::cout;
using std::endl;
template <typename T1, typename T2>
T1 add(T1 a, T2 b)
{
	return a+b;
}
int main()
{
	cout<<add(1,5.3)<<endl;
	return 0;
}

