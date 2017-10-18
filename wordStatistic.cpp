/**********************************************************
 > Filename     : wordStatistic.cpp
 > Author       : Jeyshon<jeyshon@qq.com>
 > Create time  : 2017-10-17 22:12:26
 > Last modified: 2017-10-17 22:12:26
**********************************************************/
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
class Word
{
public:
	Word(string & word);
	void addNum();
	string & getWord();
	int getNum();
	Word * _next;
private:
	string _word;
	int _num;
};
Word::Word(string & word)
: _next(NULL)
, _word(word)
, _num(1)
{}
void Word::addNum()
{
	_num++;
}
string & Word::getWord()
{
	return _word;
}
int Word::getNum()
{
	return _num;
}	
void printTotalWord(Word * pword)
{
	while(NULL!=pword)
	{
		cout<<pword->getWord()<<" "<<pword->getNum()<<endl;
		pword=pword->_next;
	}
}
int firstNotLetter(const char * str)
{
	if((str[0]>='A' && str[0]<='Z')||(str[0]>='a' && str[0]<='z'))return 0;
	else return 1;
}
void printTotalWord1(Word * pword)
{
	while(NULL!=pword)
	{
		if(firstNotLetter(pword->getWord().c_str()))cout<<pword->getWord()<<" "<<pword->getNum()<<endl;
		pword=pword->_next;
	}
}
void writeToFile(fstream &fs,Word *pword)
{
	while(NULL!=pword)
	{
		fs<<pword->getWord()<<" "<<pword->getNum()<<endl;
		pword=pword->_next;
	}
}
int main(int argc,char *argv[])
{
	if(argc!=3)
	{
		cout<<"error argc!"<<endl;
		return -1;
	}
	fstream fs(argv[1]);
	if(!fs.good())
	{
		cout<<"open "<<argv[1]<<" error!"<<endl;
		return -1;
	}
	fstream fs1(argv[2]);
	if(!fs1.good())
	{
		cout<<"open "<<argv[2]<<" error!"<<endl;
		return -1;
	}
	Word * pword;
	string tmp;
	fs>>tmp;
	pword=new Word(tmp);

	Word * pw;
	while(fs>>tmp,!fs.eof())
	{
		if(firstNotLetter(tmp.c_str()))continue;//如果字串的第一个不是字母,则跳过
		pw=pword;
		while(1)
		{
			if(pw->getWord()==tmp){pw->addNum();break;}
			if(NULL==pw->_next)break;
			else pw=pw->_next;
		}
		if(NULL==pw->_next)
		{
			pw->_next=new Word(tmp);
		}
	}
	//printTotalWord1(pword);
	fs.close();
	cout<<"read "<<argv[1]<<" end"<<endl;
	cout<<"begin write to "<<argv[2]<<"..."<<endl;
	writeToFile(fs1,pword);
	cout<<"write to "<<argv[2]<<" successfully"<<endl;
	return 0;
}
