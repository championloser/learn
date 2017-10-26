/**********************************************************
  > Filename     : WordStatistic2.cpp
  > Author       : Jeysin<jeysin@qq.com>
  > Create time  : 2017-10-25 21:21:00
  > Last modified: 2017-10-25 21:21:00
 **********************************************************/
#include<iostream>
#include<map>
#include<fstream>
using namespace std;
class WordStatistic
{
public:
	void loadWord(const char *filename);
	void dumpWord(const char *filename);
	void display();
private:
	fstream *_pfs;
	ofstream *_pos;
	map<string, int> _totalItem;
};
void WordStatistic::loadWord(const char *filename)
{
	_pfs=new fstream(filename);
	pair<string,int> tmp;
	pair<map<string,int>::iterator, bool> ret;
	while(*_pfs>>(tmp.first),!(*_pfs).eof())
	{
		if((tmp.first[0]>='A' && tmp.first[0]<='Z') || (tmp.first[0]>='a' && tmp.first[0]<='z'))
		{
			tmp.second=1;
			ret=_totalItem.insert(tmp);
			if(!ret.second)++(ret.first->second);
		}
	}
	_pfs->close();
	delete _pfs;
	_pfs=NULL;
}
void WordStatistic::dumpWord(const char *filename)
{
	_pos=new ofstream(filename);
	map<string, int>::const_iterator it;
	for(it=_totalItem.begin(); it!=_totalItem.end(); ++it)
	{
		(*_pos)<<it->first<<" "<<it->second<<endl;
	}
	_pos->close();
	delete _pos;
	_pos=NULL;
}
void WordStatistic::display()
{
	map<string, int>::iterator it;
	for(it=_totalItem.begin(); it!=_totalItem.end(); ++it)
	{
		cout<<it->first<<" "<<it->second<<endl;	
	}	
}
int main()
{
	WordStatistic ws;
	cout<<"loadWord ..."<<endl;
	ws.loadWord("The_Holy_Bible.txt");
	cout<<"loadWord successfully"<<endl;
	cout<<"dumpWord ..."<<endl;
	ws.dumpWord("note.txt");
	cout<<"dumpWord successfully"<<endl;
	return 0;
}
