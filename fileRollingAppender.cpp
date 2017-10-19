#include<iostream>
#include<log4cpp/FileAppender.hh>
#include<log4cpp/RollingFileAppender.hh>
#include<log4cpp/Category.hh>
#include<log4cpp/Priority.hh>
#include<log4cpp/PatternLayout.hh>
using namespace std;
using namespace log4cpp;
int main()
{
	FileAppender *fAppender=new FileAppender("fAppender","file.log");
	RollingFileAppender *rfAppender=new RollingFileAppender("rfAppender","rolling.log",5*1024,1);

	PatternLayout *pLayout1=new PatternLayout();
	pLayout1->setConversionPattern("%d: [%p] : %m%n");
	fAppender->setLayout(pLayout1);

	PatternLayout *pLayout2=new PatternLayout();
	pLayout2->setConversionPattern("%d: [%p] : %m%n");
	rfAppender->setLayout(pLayout2);

	Category &root=Category::getRoot().getInstance("root");
	root.addAppender(fAppender);
	root.addAppender(rfAppender);
	root.setPriority(Priority::DEBUG);
	for(int i=0;i<300;i++)
	{
		root.warn("This is a warn message");
	}
	Category::shutdown();
	return 0;
}
