#ifndef __TCPSERVER_H__
#define __TCPSERVER_H__

#include<sys/types.h>
#include<sys/socket.h>
#include<string>
#include<memory>
using std::string;
using std::shared_ptr;
namespace jjx
{
class TcpConnect;
class TcpServer
{
public:
	TcpServer(const string &ip, int port);
	~TcpServer();
	void bind();
	void listen();
	shared_ptr<TcpConnect> accept();
	void reuseAddr();
	void reusePort();
	int getSfd();
private:
	int _sfd;
	string _ip;
	int _port;
	bool _isReuseAddr;
	bool _isReusePort;
};
}//end of namespace jjx

#endif
