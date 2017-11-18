#include"Epoll.h"
#include"TcpServer.h"
#include"TcpConnect.h"
#include<string.h>
#include<unistd.h>
#include<utility>
#include<iostream>
using std::cout;
using std::endl;

namespace jjx
{
Epoll::Epoll(TcpServer &tcpSer)
: _epfd(epoll_create(1))
, _sfd(tcpSer.getSfd())
, _tcpSer(tcpSer)	
, _eventsList(10)
{
	addEpollIn(_sfd);
}
int Epoll::addEpollIn(int fd)
{
	struct epoll_event event;
	memset(&event, 0, sizeof(event));
	event.events=EPOLLIN;
	event.data.fd=fd;
	int ret=epoll_ctl(_epfd, EPOLL_CTL_ADD, fd, &event);
	if(-1==ret){perror("::epoll_ctl");exit(EXIT_FAILURE);}
	return 0;
}
int Epoll::delEpollIn(int fd)
{
	struct epoll_event event;
	memset(&event, 0, sizeof(event));
	event.events=EPOLLIN;
	event.data.fd=fd;
	epoll_ctl(_epfd, EPOLL_CTL_DEL, fd, &event);
	return 0;
}
int Epoll::loop()
{
	while(true)
	{
		int ret;
		do{
			ret=::epoll_wait(_epfd, &(*_eventsList.begin()), (int)_eventsList.size(), -1);
		}while(-1==ret && errno==EINTR);
		if(-1==ret)
		{
			perror("::epoll_wait");
			exit(EXIT_FAILURE);
		}
		if(ret==(int)_eventsList.size())
		{
			_eventsList.resize(ret*2);//扩容
		}
		for(int i=0; i<ret; ++i)
		{
			if(_eventsList[i].data.fd==_sfd)//如果是有新的连接请求
			{
				if(_eventsList[i].events & EPOLLIN)
				{
					shared_ptr<TcpConnect> pTcpCon=_tcpSer.accept();
					int newfd=pTcpCon->getNewfd();
					addEpollIn(newfd);//注册至epoll
					_listenMap.insert(std::make_pair(newfd, pTcpCon));//记录一个新TcpConnect连接
					cout<<pTcpCon->getLocalIp()<<":"<<pTcpCon->getLocalPort()<<"--->"
					    <<pTcpCon->getPeerIp()<<":"<<pTcpCon->getPeerPort()<<endl;
				}
			}else{
				if(_eventsList[i].events & EPOLLIN)//如果是有业务请求
				{
					int ret=0;
					int fd=_eventsList[i].data.fd;
					map<int, shared_ptr<TcpConnect>>::iterator it=_listenMap.find(fd);
					if(it!=_listenMap.end())
					{
						ret=_handleBusiness((*it).second);//业务逻辑回调函数
					}
					if(ret<0)//如果对端关闭，将其从epoll中删除，并将其连接从_listenMap中移除
					{
						delEpollIn(fd);
						_listenMap.erase(it);
					}
				}
			}
		}
	}
	return 0;
}
int Epoll::setHandleBussiness(CallbackType cb)
{
	_handleBusiness=cb;
	return 0;
}
}//end of namespace jjx
