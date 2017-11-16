#include"TcpConnect.h"
#include<string.h>

namespace jjx
{
TcpConnect::TcpConnect(int newfd, const string &localIp, int localPort, const string &peerIp, int peerPort)
: _newfd(newfd)
, _localIp(localIp)
, _localPort(localPort)
, _peerIp(peerIp)
, _peerPort(peerPort)
{}
int TcpConnect::send(const char *buf, int length)
{
	return ::send(_newfd, buf, length, 0);
}
int TcpConnect::recv(char *buf, int length)
{
	return ::recv(_newfd, buf, length, 0);
}
//int TcpConnect::send(const string &msg, int length)
//{
//	return sendn(msg.c_str(), length);
//}
//int TcpConnect::send(const char *buf, int length)
//{
//	return sendn(buf, length);
//}
//int TcpConnect::recv(string &msg, int length)
//{
//	if((int)msg.size()<length)msg.reserve(length);
//	msg.clear();
//	return recvn(&(*msg.begin()), length);
//}
//int TcpConnect::recv(char *buf, int length)
//{
//	return recvn(buf, length);
//}
const char * TcpConnect::getLocalIp()
{
	return _localIp.c_str();
}
const char * TcpConnect::getPeerIp()
{
	return _peerIp.c_str();
}
int TcpConnect::getLocalPort()
{
	return _localPort;
}
int TcpConnect::getPeerPort()
{
	return _peerPort;
}
int TcpConnect::getNewfd()
{
	return _newfd;
}
//int TcpConnect::sendn(const char *buf, int length)
//{
//	int ret;
//	int sum=0;
//	while(sum<length)
//	{
//		ret=::send(_newfd, buf+sum, length-sum, 0);
//		if(ret<=0)break;
//		sum=sum+ret;
//	}
//	return sum;
//}
//int TcpConnect::recvn(char *buf, int length)
//{
//	int ret;
//	int sum=0;
//	while(sum<length)
//	{
//		ret=::recv(_newfd, buf+sum, length-sum, 0);
//		if(ret<=0)break;
//		sum=sum+ret;
//	}
//	return sum;
//}
}//end of namespace jjx
