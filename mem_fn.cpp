#include<iostream>
#include<vector>
#include<functional>
#include<iterator>
#include<algorithm>
using std::cout;
using std::endl;
using std::vector;
using std::ostream_iterator;
using std::ostream;
using std::for_each;
class Number
{
public:
	Number(int x)
	: _value(x)
	{}
	bool isEnve()
	{
		return !(_value%2);
	}
	bool isPrime()
	{
		if(1==_value)return false;
		for(int i=2;i<=_value/2; ++i)
		{
			if(!(_value%2))return false;
		}
		return true;
	}
	void display()
	{
		cout<<_value<<" ";
	}
	friend ostream & operator<<(ostream &out, const Number &rhs);
private:
	int _value;
};
ostream & operator<<(ostream &out, const Number &rhs)
{
	out<<rhs._value;
	return out;
}
int main()
{
	vector<Number> numbers;
	for(int idx=1; idx<14; ++idx)
	{
		numbers.push_back(Number(idx));
	}
	//copy(numbers.begin(), numbers.end(), ostream_iterator<Number>(cout, " "));
	//cout<<endl;
	for_each(numbers.begin(), numbers.end(), std::mem_fn(&Number::display));
	cout<<endl;
	numbers.erase(remove_if(numbers.begin(), numbers.end(), std::mem_fn(&Number::isPrime)), numbers.end());
	for_each(numbers.begin(), numbers.end(), std::mem_fn(&Number::display));
	cout<<endl;
	return 0;
}
