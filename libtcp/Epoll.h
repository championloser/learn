#ifndef __EPOLL_H__
#define __EPOLL_H__

#include<sys/epoll.h>
#include<memory>
#include<map>
#include<vector>
#include<functional>
using std::shared_ptr;
using std::map;
using std::vector;

namespace jjx
{
class TcpServer;
class TcpConnect;
class Epoll
{
	typedef std::function<int(shared_ptr<TcpConnect>)> CallbackType;
public:
	Epoll(TcpServer &tcpSer);
	int addEpollIn(int fd);
	int delEpollIn(int fd);
	int loop();
	int setHandleBussiness(CallbackType cb);
private:
	CallbackType _handleBusiness;
private:
	int _epfd;
	int _sfd;
	TcpServer &_tcpSer;
	vector<struct epoll_event> _eventsList;
	map<int, shared_ptr<TcpConnect>> _listenMap; 
};
}//end of namespace jjx

#endif
