#include"TcpClient.h"
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>

namespace jjx
{

TcpClient::TcpClient(const string &ip, int port)
: _sfd(socket(AF_INET, SOCK_STREAM, 0))
, _ip(ip)
, _port(port)
{}
TcpClient::~TcpClient()
{
	::close(_sfd);
}
int TcpClient::connnect()
{
	struct sockaddr_in serAddr;
	serAddr.sin_family=AF_INET;
	serAddr.sin_addr.s_addr=inet_addr(_ip.c_str());
	serAddr.sin_port=htons(_port);
	return ::connect(_sfd, (struct sockaddr*)&serAddr, sizeof(serAddr));
}
int TcpClient::send(const char *buf, int length)
{
	return ::send(_sfd, buf, length, 0);
}
int TcpClient::recv(char *buf, int length)
{
	return ::recv(_sfd, buf, length, 0);
}
//int TcpClient::send(const string &msg, int length)
//{
//	return sendn(msg.c_str(), length);
//}
//int TcpClient::send(const char *buf, int length)
//{
//	return sendn(buf, length);
//}
//int TcpClient::recv(string &msg, int length)
//{
//	if((int)msg.size()<length)msg.reserve(length);
//	msg.clear();
//	return recvn(&(*msg.begin()), length);
//}
//int TcpClient::recv(char *buf, int length)
//{
//	return recvn(buf, length);
//}
//int TcpClient::sendn(const char *buf, int length)
//{
//	int ret;
//	int sum=0;
//	while(sum<length)
//	{
//		ret=::send(_sfd, buf+sum, length-sum, 0);
//		if(ret<=0)break;
//		sum=sum+ret;
//	}
//	return sum;
//}
//int TcpClient::recvn(char *buf, int length)
//{
//	int ret;
//	int sum=0;
//	while(sum<length)
//	{
//		ret=::recv(_sfd, buf+sum, length-sum, 0);
//		if(ret<=0)break;
//		sum=sum+ret;
//	}
//	return sum;
//}
}//end of namespace jjx
