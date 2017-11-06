#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<fstream>
#include<memory>
#include<map>
#include<set>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::fstream;
using std::ifstream;
using std::shared_ptr;
using std::vector;
using std::map;
using std::set;
class QueryResult;
class TextQuery
{
public:
	using line_no=std::vector<std::string>::size_type;
	TextQuery(ifstream &);
	QueryResult query(const string &) const;
private:
	shared_ptr<vector<string>> file;
	map<string, shared_ptr<set<line_no>>> wm;
};
TextQuery::TextQuery(ifstream &is)
: file(new vector<string>)
{
	string text;
	while(getline(is, text))
	{
		file->push_back(text);
		int n=file->size()-1;
		std::istringstream line(text);
		string word;
		while(line>>word)
		{
			shared_ptr<set<line_no>> &lines=wm[word];
			if(!lines)lines.reset(new set<line_no>);
			lines->insert(n);
		}
	}
}
class QueryResult
{
	friend std::ostream & print(std::ostream&, const QueryResult&);
public:
	using line_no=std::vector<std::string>::size_type;
	QueryResult(std::string s, std::shared_ptr<std::set<line_no>> p, std::shared_ptr<std::vector<string>> f)
	: sought(s)
	, lines(p)
	, file(f)
	{}
private:
	std::string sought;
	std::shared_ptr<std::set<line_no>> lines;
	std::shared_ptr<std::vector<string>> file;
};
void runQueries(ifstream &infile)
{
	string s;
	TextQuery tq(infile);
	while(1)
	{
		cout<<"Please enter word to look for, or q to quit:"<<endl;
		if(!(cin>>s) || s=="q")break;
		print(cout,tq.query(s))<<endl;
	}
}
QueryResult TextQuery::query(const string &sought) const
{
	static shared_ptr<set<line_no>> nodata(new set<line_no>);
	auto loc=wm.find(sought);
	if(loc==wm.end())
		return QueryResult(sought, nodata, file);
	else
		return QueryResult(sought, loc->second, file);
}
string make_plural(int size, const string &str1, const string &str2)
{
	if(size>1)return str1+str2;
	else return str1;
}
std::ostream & print(std::ostream &os, const QueryResult &qr)
{
	os<<qr.sought<<" occurs "<<qr.lines->size()<<" "
	  <<make_plural(qr.lines->size(), "time", "s")<<endl;
	for(auto num : *qr.lines)
	{
		os<<"\t(line "<<num+1<<")"
		  <<*(qr.file->begin()+num)<<endl;
	}
	return os;
}
int main()
{
	ifstream fs("The_Holy_Bible.txt");
	runQueries(fs);
	return 0;
}
