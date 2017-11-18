#include"Acceptor.h"
#include"Socket.h"
#include"Connection.h"
#include<netinet/in.h>
#include<arpa/inet.h>
#include<string.h>

namespace jjx
{
Acceptor::Acceptor(Socket &socket)
: _socket(socket)
{}
Connection Acceptor::accept()
{
	struct sockaddr_in peerAddr;
	memset(&peerAddr, 0, sizeof(peerAddr));
	int addrlen=sizeof(peerAddr);
	int newfd=::accept(_socket.getSockFd(), (struct sockaddr*)&peerAddr, (unsigned int*)&addrlen);
	return Connection(newfd, ::inet_ntoa(peerAddr.sin_addr), ntohs(peerAddr.sin_port));
}
int Acceptor::getSockFd()
{
	return _socket.getSockFd();
}
const string & Acceptor::getLocalIp()
{
	return _socket.getLocalIp();
}
int Acceptor::getLocalPort()
{
	return _socket.getLocalPort();
}
}//end of namespace jjx
