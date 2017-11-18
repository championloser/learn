#include"Reactor.h"
#include"Acceptor.h"
#include"Connection.h"
#include<unistd.h>
#include<string.h>
#include<utility>
#include<iostream>
using std::cout;
using std::endl;

namespace jjx
{
Reactor::Reactor(Acceptor &acceptor)
: _isLooping(false)
, _acceptor(acceptor)
, _eventsList(10)
{
	_sfd=_acceptor.getSockFd();
	_epfd=::epoll_create(1);
	if(-1==_epfd){perror("::epoll_create");exit(EXIT_FAILURE);}
	addEpollinFd(_sfd);
}
Reactor::~Reactor()
{
	::close(_epfd);
}
int Reactor::loop()
{
	_isLooping=true;
	while(_isLooping)
	{
		int ret;
		do{
			ret=::epoll_wait(_epfd, &(*_eventsList.begin()), _eventsList.size(), 5000);
		}while(-1==ret && errno==EINTR);
		if(-1==ret)
		{
			perror("::epoll_wait");
			exit(EXIT_FAILURE);
		}else if(ret==(int)_eventsList.size())
		{
			_eventsList.resize(2*ret);//扩容
		}else if(0==ret)
		{
			cout<<"::epoll_wait: timeout"<<endl;
		}
		for(int i=0; i<ret; ++i)
		{
			if(_eventsList[i].data.fd==_sfd)//如果有新连接请求
			{
				shared_ptr<Connection> pCon(new Connection(_acceptor.accept()));
				_lisenMap.insert(std::make_pair(pCon->getNewFd(), pCon));//添加新Connection
				int fd=pCon->getNewFd();
				cout<<"fd="<<fd<<endl;
				addEpollinFd(fd);//将新的newfd注册至_epfd;
				shared_ptr<Argument> pArg(new Argument);//填参数
				pArg->_p=this;
				pArg->_pCon=pCon;
				_handleNewCon(pArg);//执行处理新连接的回调函数
			}else{
				if(_eventsList[i].events & EPOLLIN)//如果是有业务请求
				{
					int fd=_eventsList[i].data.fd;
					map<int, shared_ptr<Connection>>::iterator it=_lisenMap.find(fd);
					int ret=0;
					if(it!=_lisenMap.end())
					{
						shared_ptr<Argument> pArg(new Argument);
						pArg->_p=this;
						pArg->_pCon=it->second;
						ret=_business(pArg);//执行业务逻辑处理函数
					}
					if(ret<0)//如果对端关闭或连接断开，从epoll解注册，并从_listenMap中移除newfd
					{
						delEpollinFd(fd);
						_lisenMap.erase(it);
					}
				}
			}
		}
	}
	return 0;
}
int Reactor::unloop()
{
	_isLooping=false;
	return 0;
}
int Reactor::addEpollinFd(int fd)
{
	struct epoll_event event;
	memset(&event, 0, sizeof(event));
	event.events=EPOLLIN;
	event.data.fd=fd;
	int ret=::epoll_ctl(_epfd, EPOLL_CTL_ADD, fd, &event);
	if(-1==ret){perror("::epoll_ctl");exit(EXIT_FAILURE);}
	return ret;
}
int Reactor::delEpollinFd(int fd)
{
	struct epoll_event event;
	memset(&event, 0, sizeof(event));
	event.events=EPOLLIN;
	event.data.fd=fd;
	int ret=::epoll_ctl(_epfd, EPOLL_CTL_DEL, fd, &event);
	if(-1==ret){perror("::epoll_ctl");exit(EXIT_FAILURE);}
	return ret;
}
int Reactor::setBusiness(CallbackType &&cb)
{
	_business=cb;
	return 0;
}
int Reactor::setHandleNewCon(CallbackType &&cb)
{
	_handleNewCon=cb;
	return 0;
}
const string & Reactor::getLocalIp()
{
	return _acceptor.getLocalIp();
}
int Reactor::getLocalPort()
{
	return _acceptor.getLocalPort();
}
}//end of namespace jjx
