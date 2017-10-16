/**********************************************************
 > Filename     : string.cpp
 > Author       : Jeyshon
 > Email        : Jeyshon@qq.com
 > Create time  : 2017-10-15 21:49:12
 > Last modified: 2017-10-16 18:11:36
**********************************************************/
#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
int main()
{
	string s1="hello,worldhello,world";
	cout<<s1<<endl;
	cout<<s1.data()<<endl;
	cout<<s1.c_str()<<endl;
	cout<<s1.length()<<endl;
	cout<<s1.size()<<endl;
	return 0;
}
