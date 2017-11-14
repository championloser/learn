#ifndef __TCPCONNECT_H__
#define __TCPCONNECT_H__

#include<sys/types.h>
#include<sys/socket.h>
#include<string>
using std::string;

#define BUFFSIZE 1024

namespace jjx
{
class TcpConnect
{
public:
	TcpConnect(int newfd, string &localIp, int localPort, string &peerIp, int peerPort);
	int send(const string &msg);
	int recv(string &msg);
private:
	int _newfd;
	string _localIp;
	int _localPort;
	string _peerIp;
	int _peerPort;
	char *_pbuff;//length=BUFFSIZE
};
}//end of namespace jjx

#endif
