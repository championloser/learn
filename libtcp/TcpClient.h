#ifndef __TCPCLIENT_H__
#define __TCPCLIENT_H__

#include<string>
using std::string;

namespace jjx
{
class TcpClient
{
public:
	TcpClient(const string &ip, int port);
	~TcpClient();
	int connnect();
	int send(const char *buf, int length);
	int recv(char *buf, int length);
	//int send(const string &msg, int length);
	//int send(const char *buf, int length);
	//int recv(string &msg, int length);
	//int recv(char *buf, int length);
private:
	//int sendn(const char *buf, int length);
	//int recvn(char *buf, int length);
private:
	int _sfd;
	string _ip;
	int _port;
};
}//enf of namespace jjx
#endif
