/**********************************************************
 > Filename     : new.cpp
 > Author       : Jeyshon
 > Email        : Jeyshon@qq.com
 > Create time  : 2017-10-15 21:48:54
 > Last modified: 2017-10-15 21:48:54
**********************************************************/
#include<iostream>
using namespace std;
int main()
{
	int *p=new int[10];
	for(int i=0;i<10;i++)
	{
		cout<<p[i]<<endl;
	}
	return 0;
}
