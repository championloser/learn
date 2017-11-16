#include"TcpServer.h"
#include"TcpConnect.h"
#include"Epoll.h"
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<memory>
using std::cout;
using std::cin;
using std::endl;
using jjx::TcpConnect;
using jjx::TcpServer;
using jjx::Epoll;

int handleBussiness(std::shared_ptr<TcpConnect> pTcpCon)
{
	int ret;
	char buf[256];
	memset(buf, 0, sizeof(buf));
	ret=pTcpCon->recv(buf, 256);
	if(ret<=0)return -1;
	cout<<buf<<endl;
	memset(buf, 0, sizeof(buf));
	strcpy(buf, "I am server");
	ret=pTcpCon->send(buf, strlen(buf));
	if(ret<=0)return -1;
	return 0;
}
int main(int argc, char *argv[])
{
	if(argc!=3){cout<<"error argc"<<endl;return 0;}
	TcpServer tcpSer(argv[1], atoi(argv[2]));
	tcpSer.reuseAddr();
	tcpSer.bind();
	tcpSer.listen();
	Epoll epo(tcpSer);
	epo.setHandleBussiness(handleBussiness);
	epo.loop();
	return 0;
}
