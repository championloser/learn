#include<iostream>
#include<set>
#include<map>
#include<vector>
#include<fstream>
using namespace std;
class Item
{
public:
	string _word;
	int _num;
	friend ostream & operator<<(ostream &out, const Item &rhs);
	friend bool operator>(const Item &lhs, const Item &rhs);
	friend bool operator<(const Item &lhs, const Item &rhs);
};
ostream & operator<<(ostream &out, const Item &rhs)
{
	out<<rhs._word<<" "<<rhs._num;
	return out;
}
bool operator>(const Item &lhs, const Item &rhs)
{
	return lhs._num>rhs._num;	
}
bool operator<(const Item &lhs, const Item &rhs)
{
	return lhs._num<rhs._num;	
}
//class Compare
//{
//public:
//	bool operator()(const pair<int, Item> &lhs, const pair<int, Item> &rhs)
//	{
//		return lhs.second._num>rhs.second._num;
//	}
//};
class Compare
{
public:
	bool operator()(const Item &lhs, const Item &rhs)
	{
		return lhs._num>rhs._num;
	}
};
class WordStatistic
{
public:
	void loadWord(const char *filename);
	void dumpWord(const char *filename);
	void display();
private:
	fstream *_pfs;
	ofstream *_pos;
	map<int, Item> _totalItem;
};
void WordStatistic::loadWord(const char *filename)
{
	_pfs=new fstream(filename);
	Item tmp;
	int count=0;
	while(*_pfs>>(tmp._word),!(*_pfs).eof())
	{
		tmp._num=1;
		map<int, Item>::iterator it;
		for(it=_totalItem.begin(); it!=_totalItem.end(); ++it)
		{
			if((it->second)._word==tmp._word)
			{
				++((it->second)._num);
				break;
			}
		}
		if(it==_totalItem.end())
		{
			_totalItem.insert(make_pair(count,tmp));
		}
		++count;
	}
	_pfs->close();
	delete _pfs;
	_pfs=NULL;
}
void WordStatistic::dumpWord(const char *filename)
{
	_pos=new ofstream(filename);
	map<int, Item>::const_iterator it;
	for(it=_totalItem.begin(); it!=_totalItem.end(); ++it)
	{
		(*_pos)<<(it->second)._word<<" "<<(it->second)._num<<endl;
	}
	_pos->close();
	delete _pos;
	_pos=NULL;
}
void WordStatistic::display()
{
	map<int, Item>::iterator it;
	for(it=_totalItem.begin(); it!=_totalItem.end(); ++it)
	{
		cout<<(it->second)._word<<" "<<(it->second)._num<<endl;	
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
