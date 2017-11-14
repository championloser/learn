#ifndef __TCPSERVER_H__
#define __TCPSERVER_H__

#include<sys/types.h>
#include<sys/socket.h>
#include<string>
using std::string;
namespace jjx
{
class TcpConnect;
class TcpServer
{
public:
	TcpServer(const string &ip, int port);
	~TcpServer();
	TcpConnect accept();
	void reuseAddr();
	void reusePort();
private:
	void bind();
	void listen();
private:
	int _tcpfd;
	string _ip;
	int _port;
	bool _isReuseAddr;
	bool _isReusePort;
};
}//end of namespace jjx

#endif
