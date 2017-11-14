#include"TcpConnect.h"
#include<string.h>

namespace jjx
{
TcpConnect::TcpConnect(int newfd, string &localIp, int localPort, string &peerIp, int peerPort)
: _newfd(newfd)
, _localIp(localIp)
, _localPort(localPort)
, _peerIp(peerIp)
, _peerPort(peerPort)
, _pbuff(new char[BUFFSIZE]())
{}
int TcpConnect::send(const string &msg)
{
	memset(_pbuff, 0, BUFFSIZE);
	strncpy(_pbuff, msg.c_str(), BUFFSIZE);
	int ret;
	int sum=0;
	while(sum<BUFFSIZE)
	{
		ret=::send(_newfd, _pbuff+sum, BUFFSIZE-sum, 0);
		if(ret<=0)break;
		sum=sum+ret;
	}
	return sum;
}
int TcpConnect::recv(string &msg)
{
	memset(_pbuff, 0, BUFFSIZE);
	int ret;
	int sum=0;
	while(sum<BUFFSIZE)
	{
		ret=::recv(_newfd, _pbuff+sum, BUFFSIZE-sum, 0);
		if(ret<=0)break;
		sum=sum+ret;
	}
	msg=*_pbuff;
	return sum;
}
}//end of namespace jjx
