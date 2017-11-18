#ifndef __REACTOR_H__
#define __REACTOR_H__

#include<sys/epoll.h>
#include<map>
#include<memory>
#include<vector>
#include<functional>
using std::string;
using std::map;
using std::vector;
using std::shared_ptr;
using std::function;

namespace jjx
{
class Acceptor;
class Connection;
class Reactor;

typedef struct argument
{
	void *_p;
	shared_ptr<Connection> _pCon;
}Argument;

class Reactor
{
typedef function<int(shared_ptr<Argument>)> CallbackType;
public:
	Reactor(Acceptor &acceptor);
	~Reactor();
	int loop();
	int unloop();
	int addEpollinFd(int fd);
	int delEpollinFd(int fd);
	int setBusiness(CallbackType &&cb);
	int setHandleNewCon(CallbackType &&cb);
	const string & getLocalIp();
	int getLocalPort();
private:
	bool _isLooping;
	int _epfd;
	Acceptor &_acceptor;
	int _sfd;
	vector<struct epoll_event> _eventsList;
	map<int, shared_ptr<Connection>> _lisenMap;
	CallbackType _business;
	CallbackType _handleNewCon;
};
}//end of namespace jjx

#endif
