#include"TcpServer.h"
#include"TcpConnect.h"
#include<stdlib.h>
#include<iostream>
using std::cout;
using std::endl;
using jjx::TcpConnect;
using jjx::TcpServer;
int main(int argc, char *argv[])
{
	if(argc!=3){cout<<"error argc"<<endl;return 0;}
	string ip(argv[1]);
	TcpServer ts(ip, atoi(argv[2]));
	TcpConnect tc=ts.accept();
	cout<<"after accept"<<endl;
	return 0;
}
