#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>
using std::cout;
using std::endl;
using std::vector;
using std::ostream_iterator;
int test0()
{
	vector<int> numbers{1,2,3,4,5,6,7};
	std::less<int> lt;
	//replace_if(numbers.begin(), numbers.end(), bind1st(lt, 3), 7);
	replace_if(numbers.begin(), numbers.end(), bind2nd(lt, 3), 7);
	for(auto &elem : numbers)
	{
		cout<<elem<<" ";
	}
	cout<<endl;
	return 0;
}
int test1()
{
	vector<int> numbers{1,2,3,99,5,6,99,8,9,99};
	copy(numbers.begin(), numbers.end(), ostream_iterator<int>(cout, " "));
	cout<<endl;
	//auto it=remove(numbers.begin(), numbers.end(), 99);
	//copy(numbers.begin(), numbers.end(), ostream_iterator<int>(cout, " "));
	//cout<<endl;
	//numbers.erase(it,numbers.end());
	//copy(numbers.begin(), numbers.end(), ostream_iterator<int>(cout, " "));
	//cout<<endl;
	numbers.erase(remove(numbers.begin(), numbers.end(), 99), numbers.end());
	copy(numbers.begin(), numbers.end(), ostream_iterator<int>(cout, " "));
	cout<<endl;
	return 0;
}
int main()
{
	//test0();
	test1();
	return 0;
}

