#include<iostream>
#include<log4cpp/Category.hh>
#include<log4cpp/PatternLayout.hh>
#include<log4cpp/Priority.hh>
#include<log4cpp/RollingFileAppender.hh>
using namespace std;
using namespace log4cpp;
int main()
{
	RollingFileAppender *rfAppender=new RollingFileAppender("rfAppender","rolling.log",1024*1024,1);
	PatternLayout *pLayout=new PatternLayout();
	pLayout->setConversionPattern("%d: [%p] : %m%n");
	rfAppender->setLayout(pLayout);
	Category &root=Category::getRoot();
	root.addAppender(rfAppender);
	root.setPriority(Priority::DEBUG);
	root.error("This is an error message");
	root.warn("This is a warn message");
	Category::shutdown();
	
	return 0;
}
