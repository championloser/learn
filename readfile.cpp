#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main()
{
	fstream fs("file.txt");
	if(!fs.good())
	{
		cout<<"open file.txt error!"<<endl;
		return -1;
	}
	string line;
	while(fs>>line,!fs.eof())
	{
		cout<<line<<endl;
	}
	fs.close();
	return 0;
}
