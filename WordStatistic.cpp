#include<iostream>
#include<vector>
#include<fstream>
using namespace std;
class Item
{
public:
	string _word;
	int _num;
	friend ostream & operator<<(ostream &out, const Item &rhs);
};
ostream & operator<<(ostream &out, const Item &rhs)
{
	out<<rhs._word<<" "<<rhs._num;
	return out;
}
class WordStatistic
{
public:
	void loadWord(const char *filename);
	void dumpWord(const char *filename);
	void display();
private:
	fstream *_pfs;
	ofstream *_pos;
	vector<Item> _totalItem;
};
void WordStatistic::loadWord(const char *filename)
{
	_pfs=new fstream(filename);
	Item tmp;
	while(*_pfs>>(tmp._word),!(*_pfs).eof())
	{
		tmp._num=1;
		vector<Item>::iterator it;
		for(it=_totalItem.begin(); it!=_totalItem.end(); ++it)
		{
			if(it->_word==tmp._word)
			{
				++(it->_num);
				break;
			}
		}
		if(it==_totalItem.end())_totalItem.push_back(tmp);
	}
	_pfs->close();
	delete _pfs;
	_pfs=NULL;
}
void WordStatistic::dumpWord(const char *filename)
{
	_pos=new ofstream(filename);
	vector<Item>::const_iterator it;
	for(it=_totalItem.begin(); it!=_totalItem.end(); ++it)
	{
		(*_pos)<<it->_word<<" "<<it->_num<<endl;
	}
	_pos->close();
	delete _pos;
	_pos=NULL;
}
void WordStatistic::display()
{
	vector<Item>::iterator it;
	for(it=_totalItem.begin(); it!=_totalItem.end(); ++it)
	{
		cout<<*it<<endl;
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
