#include"TcpServer.h"
#include"TcpConnect.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>

#define MAXLINK 1024

namespace jjx
{
TcpServer::TcpServer(const string &ip, int port)
: _sfd(socket(AF_INET, SOCK_STREAM, 0))
, _ip(ip)
, _port(port)
, _isReuseAddr(false)
, _isReusePort(false)
{}
TcpServer::~TcpServer()
{
	::close(_sfd);
}
TcpConnect TcpServer::accept()
{
	struct sockaddr_in peerAddr;
	memset(&peerAddr, 0, sizeof(peerAddr));
	int addrlen=sizeof(peerAddr);
	int newfd=::accept(_sfd, (struct sockaddr*)&peerAddr, (unsigned int *)&addrlen);
	return TcpConnect(newfd, _ip, _port, inet_ntoa(peerAddr.sin_addr), ntohs(peerAddr.sin_port));
}
void TcpServer::reuseAddr()
{
	if(_isReuseAddr==false)
	{
		int reuse=1;
		int ret=::setsockopt(_sfd, SOL_SOCKET, SO_REUSEADDR, (const void*)&reuse, sizeof(int));
		if(-1==ret)
		{
			perror("::setsockopt");
			::close(_sfd);
			exit(EXIT_FAILURE);
		}
		_isReuseAddr=true;
	}
}
void TcpServer::reusePort()
{
	if(_isReusePort==false)
	{
		int reuse=1;
		int ret=::setsockopt(_sfd, SOL_SOCKET, SO_REUSEPORT, (const void *)&reuse, sizeof(int));
		if(-1==ret)
		{
			perror("::setsockopt");
			::close(_sfd);
			exit(EXIT_FAILURE);
		}
	}
	_isReusePort=true;
}
void TcpServer::bind()
{
	struct sockaddr_in localAddr;
	memset(&localAddr, 0, sizeof(localAddr));
	localAddr.sin_family=AF_INET;
	localAddr.sin_addr.s_addr=inet_addr(_ip.c_str());
	localAddr.sin_port=htons(_port);

	int ret=::bind(_sfd, (struct sockaddr*)&localAddr, sizeof(localAddr));
	if(-1==ret)
	{
		perror("::bind");
		::close(_sfd);
		exit(EXIT_FAILURE);
	}
}
void TcpServer::listen()
{
	int ret=::listen(_sfd, MAXLINK);
	if(-1==ret)
	{
		perror("::listen");
		::close(_sfd);
		exit(EXIT_FAILURE);
	}
}
int TcpServer::getSfd()
{
	return _sfd;
}
}//end of namespace jjx
