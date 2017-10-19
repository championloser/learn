#include<iostream>
#include<log4cpp/FileAppender.hh>
#include<log4cpp/PatternLayout.hh>
#include<log4cpp/Priority.hh>
#include<log4cpp/Category.hh>
using namespace std;
using namespace log4cpp;
int main()
{
	FileAppender *fAppender=new FileAppender("fAppender","file.log");
	PatternLayout * pLayout=new PatternLayout();
	pLayout->setConversionPattern("%d: [%p] : %m%n");
	fAppender->setLayout(pLayout);

	Category & root=Category::getRoot();
	root.addAppender(fAppender);
	root.setPriority(Priority::DEBUG);
	
	root.error("This is an error message");
	root.warn("This is a warn message");
	Category::shutdown();
	return 0;
}
