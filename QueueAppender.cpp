#include<iostream>
#include<log4cpp/OstreamAppender.hh>
#include<log4cpp/Category.hh>
#include<log4cpp/Priority.hh>
#include<log4cpp/StringQueueAppender.hh>
#include<log4cpp/PatternLayout.hh>
using namespace std;
using namespace log4cpp;
int main()
{
	StringQueueAppender * strQAppender=new StringQueueAppender("strQAppender");
	PatternLayout * pLayout=new PatternLayout();
	pLayout->setConversionPattern("%d: [%p] %c: %m%n");
	strQAppender->setLayout(pLayout);
	Category & root=Category::getRoot();
	Category & cate1=root.getInstance("cate1");
	cate1.addAppender(strQAppender);
	cate1.setPriority(Priority::DEBUG);
	cate1.error("This is an error message");
	cate1.warn("This is a warn message");
	cout<<"prinrf Queue message"<<endl;
	queue<string>& mystr=strQAppender->getQueue();
	while(!mystr.empty())
	{
		cout<<mystr.front();
		mystr.pop();
	}
	Category::shutdown();
	return 0;
}
