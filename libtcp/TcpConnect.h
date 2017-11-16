#ifndef __TCPCONNECT_H__
#define __TCPCONNECT_H__

#include<sys/types.h>
#include<sys/socket.h>
#include<string>
using std::string;

namespace jjx
{
class TcpConnect
{
public:
	TcpConnect(int newfd, const string &localIp, int localPort, const string &peerIp, int peerPort);
	int send(const char *buf, int length);
	int recv(char *buf, int length);
	//int send(const string &msg, int length);
	//int send(const char *buf, int length);
	//int recv(string &msg, int length);
	//int recv(char *buf, int length);
	const char * getLocalIp();
	const char * getPeerIp();
	int getLocalPort();
	int getPeerPort();
	int getNewfd();
private:
	//int sendn(const char *buf, int length);
	//int recvn(char *buf, int length);
private:
	int _newfd;
	string _localIp;
	int _localPort;
	string _peerIp;
	int _peerPort;
};
}//end of namespace jjx

#endif
