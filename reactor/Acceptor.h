#ifndef __ACCEPTOR_H__
#define __ACCEPTOR_H__

#include<string>
using std::string;

namespace jjx
{
class Socket;
class Connection;
class Acceptor
{
public:
	Acceptor(Socket &socket);
	Connection accept();
	int getSockFd();
	const string & getLocalIp();
	int getLocalPort();
private:
	Socket &_socket;
};
}//end namespace jjx
#endif
