#include<iostream>
#include<log4cpp/Category.hh>
#include<log4cpp/OstreamAppender.hh>
#include<log4cpp/Priority.hh>
#include<log4cpp/PatternLayout.hh>
using namespace std;
using namespace log4cpp;
int main()
{
	OstreamAppender * osAppender=new OstreamAppender("osAppender",&cout);
	PatternLayout *pLayout=new PatternLayout();
	pLayout->setConversionPattern("%d: [%p] %c: %m%n");
	osAppender->setLayout(pLayout);
	Category & root=Category::getRoot();
	Category & infoCategory=root.getInstance("infoCategory");
	infoCategory.addAppender(osAppender);
	infoCategory.setPriority(Priority::DEBUG);
	infoCategory.error("This is an error message");
	infoCategory.warn("This is a warn message");
	infoCategory.emerg("This is a emerg message");
	Category::shutdown();
	return 0;
}
