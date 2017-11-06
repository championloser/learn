#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<memory>
#include<fstream>
#include<regex>
using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::map;
using std::vector;
using std::shared_ptr;
using std::set;
using std::ifstream;
class QueryResult;
class TextQuery
{
public:
	TextQuery(const string &filename);
	QueryResult query(const string &s);
	void displayMap();	//for debug
private:
	shared_ptr<vector<string>> _wm;
	shared_ptr<map<string, shared_ptr<set<int>>>> _lines;
	
};
TextQuery::TextQuery(const string &filename)
: _wm(new vector<string>)
, _lines(new map<string, shared_ptr<set<int>>>)
{
	ifstream ifs(filename);
	string line;
	std::regex reg("[A-Za-z]+");
	int lineNum=0;
	while(getline(ifs, line))
	{
		_wm->push_back(line);	
		auto word_begin=std::sregex_iterator(line.begin(), line.end(), reg);
		auto word_end=std::sregex_iterator();
		for(auto it=word_begin; it!=word_end; ++it)
		{
			//std::smatch mat=*it;
			//cout<<mat.str()<<endl;
			shared_ptr<set<int>> pset(new set<int>);
			pset->insert(lineNum);
			auto ret=_lines->insert(make_pair((*it).str(), pset));
			if(!ret.second)ret.first->second->insert(lineNum);
		}
		++lineNum;
	}
}
void TextQuery::displayMap()
{
	map<string, shared_ptr<set<int>>>::iterator it;
	for(it=_lines->begin(); it!=_lines->end(); ++it)
	{
		cout<<it->first<<" ";
		for(set<int>::iterator sit=it->second->begin(); sit!=it->second->end(); ++sit)
		cout<<*sit<<" ";
		cout<<endl;
	}
}
class QueryResult
{
	friend void print(const QueryResult &qr);
public:
	QueryResult(const string &s, shared_ptr<set<int>> lineNum, shared_ptr<vector<string>> file)
	: _sought(s)
	, _lineNum(lineNum)
	, _file(file)
	{}
private:
	string _sought;
	shared_ptr<set<int>> _lineNum;
	shared_ptr<vector<string>> _file;
};
QueryResult TextQuery::query(const string &s)
{
	map<string, shared_ptr<set<int>>>::iterator ret=_lines->find(s);
	static shared_ptr<set<int>> noneset(new set<int>);
	if(ret==_lines->end())return QueryResult(s, noneset, _wm);
	else return QueryResult(s, ret->second, _wm);
}
void print(const QueryResult &qr)
{
	cout<<"'"<<qr._sought<<"' occurs " <<qr._lineNum->size()<<" times"<<endl;
	for(set<int>::iterator it=qr._lineNum->begin(); it!=qr._lineNum->end(); ++it)
	{
		cout<<"\t(line "<<*it<<" ) "<<(*qr._file)[*it+1]<<endl;
	}
}
void runTextQuery(const string &filename)
{
	TextQuery tq(filename);
	string s;
	while(1)
	{
		cout<<"please input the word to look for, 'q' or 'exit' to quite:"<<endl;
		if(!(cin>>s) || s=="q" || s=="exit")break;
		print(tq.query(s));
	}
}
int main()
{
	runTextQuery("note1.txt");
	return 0;
}
