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
