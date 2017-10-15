/**********************************************************
 > Filename     : string.cpp
 > Author       : Jeyshon
 > Email        : Jeyshon@qq.com
 > Create time  : 2017-10-15 21:49:12
 > Last modified: 2017-10-15 23:10:08
**********************************************************/
#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
int main()
{
	string s1="hello,worldhello,world";
	const char *p=s1.c_str();
	const char *p1=s1.data();
	printf("%s\n",p);
	printf("%s\n",p1);
	return 0;
}
