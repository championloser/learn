#include<string.h>
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<sstream>
using std::cout;
using std::endl;
using std::vector;
using std::map;
using std::set;
using std::pair;
using std::string;
using std::fstream;
using std::stringstream;
using std::istringstream;
class WordInfo
{
public:
	int _num;
	set<int> _lineNum;
};
class TextQuery
{
public:
	void readFile(const char *filename);
	void queryWord(const string &word);
private:
	map<string, WordInfo> _word;
	vector<string> _line;
};
string refine(string &tmpword)
{
	for(size_t i=0; i<tmpword.size(); ++i)
	{
		if(!((tmpword[i]>='A' && tmpword[i]<='Z')||(tmpword[i]>='a' && tmpword[i]<='z')))
		{tmpword[i]='\0';break;}
	}
	char *newword=new char[tmpword.size()]();
	strcpy(newword,tmpword.c_str());
	return string(newword);
}
void TextQuery::readFile(const char *filename)
{
	fstream fs(filename);	
	string line;
	string tmpword;
	string word;
	int lineNum=0;
	while(getline(fs, line), !fs.eof())
	{
		_line.push_back(line);
		istringstream iss(line);
		while(iss>>tmpword)
		{
			if((tmpword[0]>='A' && tmpword[0]<='Z')||(tmpword[0]>='a' && tmpword[0]<='z'))
			{
				word=refine(tmpword);
				WordInfo winfo;
				winfo._num=1;
				winfo._lineNum.insert(lineNum);	
				pair<string, WordInfo> t(word, winfo);
				pair<map<string, WordInfo>::iterator, bool> ret=_word.insert(t);
				if(ret.second==false)
				{
					++(ret.first->second._num);
					ret.first->second._lineNum.insert(lineNum);
				}
			}
		}
		++lineNum;
	}
	//map<string, WordInfo>::iterator it;
	//for(it=_word.begin(); it!=_word.end(); ++it)
	//{
	//	cout<<it->first<<" "<<it->second._num<<" ";
	//	set<int>::iterator sit;
	//	for(sit=it->second._lineNum.begin(); sit!=it->second._lineNum.end(); ++sit)
	//	{
	//		cout<<*sit<<" ";
	//	}
	//	cout<<endl;
	//}
}
void TextQuery::queryWord(const string &word)
{
	map<string, WordInfo>::iterator it;
	it=_word.find(word);
	if(it==_word.end())cout<<"not found!"<<endl;
	else {
		cout<<"'"<<word<<"' occurs "<<it->second._num<<" times."<<endl;
		set<int>::iterator sit;
		for(sit=it->second._lineNum.begin(); sit!=it->second._lineNum.end(); ++sit)
		{
			cout<<"\t(line "<<*sit+1<<") "<<_line[*sit]<<endl;
		}
	}
}
int main(int argc, char *argv[])
{
	if(argc!=3){cout<<"argc error"<<endl; return 0;}
	TextQuery tq;
	tq.readFile(argv[1]);
	tq.queryWord(argv[2]);
	return 0;
}
