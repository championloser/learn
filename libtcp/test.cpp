#include<string.h>
#include<iostream>
using std::cout;
using std::endl;
using std::string;
int main()
{
	string s="hello world";
	cout<<s.size()<<endl;
	int length=(int)s.size();
	char *pbuf=new char[length+4]();
	memcpy(pbuf, &length, 4);
	memcpy(pbuf+4, s.c_str(), s.size());

	int length1;
	memcpy(&length1, pbuf, 4);
	cout<<"length1= "<<length1<<endl;
	return 0;
}
