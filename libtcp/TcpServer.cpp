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
: _tcpfd(socket(AF_INET, SOCK_STREAM, 0))
, _ip(ip)
, _port(port)
, _isReuseAddr(false)
, _isReusePort(false)
{
	bind();
	listen();
}
TcpServer::~TcpServer()
{
	::close(_tcpfd);
}
TcpConnect TcpServer::accept()
{
	struct sockaddr_in peerAddr;
	memset(&peerAddr, 0, sizeof(peerAddr));
	int addrlen=sizeof(peerAddr);
	int newfd=::accept(_tcpfd, (struct sockaddr*)&peerAddr, (unsigned int *)&addrlen);
	string peerIp(inet_ntoa(peerAddr.sin_addr));
	int peerPort=(int)ntohs(peerAddr.sin_port);
	return TcpConnect(newfd, _ip, _port, peerIp, peerPort);
}
void TcpServer::reuseAddr()
{
	if(_isReuseAddr==false)
	{
		int reuse=1;
		int ret=::setsockopt(_tcpfd, SOL_SOCKET, SO_REUSEADDR, (const void*)&reuse, sizeof(int));
		if(-1==ret)
		{
			perror("::setsockopt");
			::close(_tcpfd);
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
		int ret=::setsockopt(_tcpfd, SOL_SOCKET, SO_REUSEPORT, (const void *)&reuse, sizeof(int));
		if(-1==ret)
		{
			perror("::setsockopt");
			::close(_tcpfd);
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

	int ret=::bind(_tcpfd, (struct sockaddr*)&localAddr, sizeof(localAddr));
	if(-1==ret)
	{
		perror("::bind");
		::close(_tcpfd);
		exit(EXIT_FAILURE);
	}
}
void TcpServer::listen()
{
	int ret=::listen(_tcpfd, MAXLINK);
	if(-1==ret)
	{
		perror("::listen");
		::close(_tcpfd);
		exit(EXIT_FAILURE);
	}
}
}//end of namespace jjx
