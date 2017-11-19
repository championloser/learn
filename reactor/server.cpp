#include"Socket.h"
#include"Acceptor.h"
#include"Connection.h"
#include"ReactorThreadpool.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
using std::cout;
using std::endl;
using jjx::Socket;
using jjx::Acceptor;
using jjx::Connection;
using jjx::Task;
using jjx::ReactorThreadpool;

int HandleNewCon(shared_ptr<Connection> pCon)
{
	char buf[]="Welcome, I am Server";
	pCon->send(buf, strlen(buf));
	return 0;
}
int BusinessRecvData(void *p, shared_ptr<Connection> pCon)
{
	char buf[256];
	memset(buf, 0, sizeof(buf));
	pCon->recv(buf, sizeof(buf));//接收对端传来的数据
	shared_ptr<Task> pTask(new Task);//将数据打包成任务
	pTask->_message=buf;
	pTask->_pCon=pCon;
	ReactorThreadpool *pReaThrPool=(ReactorThreadpool*)p;
	//将任务绑定到_compute函数上，并将函数交给线程池处理
	pReaThrPool->addTaskToThreadPool(std::bind(pReaThrPool->_compute, pTask));
	return 0;
}
int Compute(void *p, shared_ptr<Task> pTask) 
{
	//计算线程的任务：计算发送过来的数据长度
	int length=strlen(pTask->_message.c_str());
	char buf[128];
	memset(buf, 0, sizeof(buf));
	sprintf(buf, "%s%d", " the size is ", length);
	pTask->_message=pTask->_message+buf;
	//将结果打包成任务放到任务队列
	ReactorThreadpool *pReaThrPool=(ReactorThreadpool*)p;
	pReaThrPool->addTaskToVeactor(pTask);
	//通过eventfd通知IO线程
	pReaThrPool->writeEventfd();
	return 0;
}
int BusinessSendData(void *p)
{
	ReactorThreadpool *pReaThrPool=(ReactorThreadpool*)p;
	//从vector中用副本换出任务
	shared_ptr<vector<shared_ptr<Task>>> pVectorTaskCopy=pReaThrPool->copyTaskFromVeactor();
	//将每个任务发送至目的地
	for(size_t i=0; i<(*pVectorTaskCopy).size(); ++i)
	{
		shared_ptr<Task> pTask=(*pVectorTaskCopy)[i];
		pTask->_pCon->send(pTask->_message.c_str(), pTask->_message.size());
	}
	return 0;
}
int DisConnect(shared_ptr<Connection> pCon)
{
	char buf[]="This Connection will break soon";
	pCon->send(buf, strlen(buf));
	return 0;
}
int main(int argc, char *argv[])
{
	if(argc!=3){cout<<"error argc"<<endl; return -1;}
	Socket soc(argv[1], atoi(argv[2]));
	soc.reuseAddr();
	soc.bind();
	soc.listen();
	Acceptor acc(soc);
	ReactorThreadpool reaThrPool(acc, 5, 10);
	reaThrPool.setHandleNewCon(::HandleNewCon);
	reaThrPool.setBusinessRecvData(::BusinessRecvData);
	reaThrPool.setBusinessSendData(::BusinessSendData);
	reaThrPool.setDisConnect(::DisConnect);
	reaThrPool.start();
	return 0;
}
