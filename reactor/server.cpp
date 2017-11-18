#include"Socket.h"
#include"Acceptor.h"
#include"Connection.h"
#include"Reactor.h"
#include<stdlib.h>
#include<string.h>
#include<iostream>
using std::cout;
using std::endl;
using jjx::Socket;
using jjx::Acceptor;
using jjx::Connection;
using jjx::Reactor;
using jjx::Argument;

int HandleNewCon(shared_ptr<Argument> pArg)
{
	Reactor *pRec=(Reactor*)pArg->_p;
	cout<<pRec->getLocalIp()<<":"<<pRec->getLocalPort()<<"--->"
	    <<pArg->_pCon->getPeerIp()<<":"<<pArg->_pCon->getPeerPort()
	    <<endl;
	char buf[]="Welcome, I am server";
	pArg->_pCon->send(buf, ::strlen(buf));
	return 0;
}
int Business(shared_ptr<Argument> pArg)
{
	char buf[256];
	memset(buf, 0, sizeof(buf));
	int ret=pArg->_pCon->recv(buf, sizeof(buf));
	if(ret<=0)return -1;
	memset(buf, 0, sizeof(buf));
	strcpy(buf, "I am server");
	ret=pArg->_pCon->send(buf, strlen(buf));
	if(ret<=0)return -1;
	return 0;
}
int DisConnect(shared_ptr<Argument> pArg)
{
	Reactor *pRec=(Reactor*)pArg->_p;
	cout<<"Disconnect: ";
	cout<<pRec->getLocalIp()<<":"<<pRec->getLocalPort()<<"--->"
	    <<pArg->_pCon->getPeerIp()<<":"<<pArg->_pCon->getPeerPort()
	    <<endl;
	return 0;
}
int main(int argc, char *argv[])
{
	if(argc!=3){cout<<"error argc"<<endl; return -1;}
	Socket soc(argv[1], atoi(argv[2]));
	soc.reuseAddr();
	soc.bind();
	soc.listen();
	Acceptor acc(soc);
	Reactor rea(acc);
	rea.setBusiness(Business);
	rea.setHandleNewCon(HandleNewCon);
	rea.setDisConnect(DisConnect);
	rea.loop();
	return 0;
}
