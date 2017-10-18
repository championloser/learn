#include<iostream>
#include<log4cpp/OstreamAppender.hh>
#include<log4cpp/BasicLayout.hh>
#include<log4cpp/Category.hh>
using namespace std;
using namespace log4cpp;
int main()
{
	OstreamAppender * osAppender=new OstreamAppender("osAppender",&cout);
	osAppender->setLayout(new BasicLayout());
	Category & root=Category::getRoot();
	root.addAppender(osAppender);
	root.setPriority(Priority::DEBUG);

	root.error("This is an error message");
	root.debug("This is a debug message");
	root.warn("This is a warn message");

	Category::shutdown();
	return 0;
}
