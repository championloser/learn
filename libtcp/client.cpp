#include"TcpClient.h"
#include<stdlib.h>
#include<iostream>
#include<string.h>
using std::cout;
using std::endl;
using std::cin;
using std::string;
using jjx::TcpClient;
int main(int argc, char *argv[])
{
	if(argc!=3){cout<<"error argc"<<endl; return 0;}
	TcpClient tc(argv[1], atoi(argv[2]));
	tc.connnect();

	char buf[256];
	while(true)
	{
		memset(buf, 0, sizeof(buf));
		cin>>buf;
		tc.send(buf, strlen(buf));
		memset(buf, 0, sizeof(buf));
		tc.recv(buf, 256);
		cout<<buf<<endl;
	}
	return 0;
}
