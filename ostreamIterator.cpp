#include<iostream>
#include<iterator>
#include<vector>
#include<algorithm>
using std::cout;
using std::cin;
using std::endl;
using std::ostream_iterator;
using std::istream_iterator;
using std::vector;
using std::copy;
using std::back_inserter;
int test0()
{
	vector<int> numbers{1,2,3,4,5,6,7,8};
	//ostream_iterator<int> osi(cout, "\n");
	//copy(numbers.begin(), numbers.end(), osi);
	copy(numbers.begin(), numbers.end(), ostream_iterator<int>(cout, "\n"));
	return 0;
}
int test1()
{
	istream_iterator<int> isi(cin);
	vector<int> numbers(10);
	copy(isi, istream_iterator<int>(), numbers.begin());
	copy(numbers.begin(), numbers.end(), ostream_iterator<int>(cout, " "));
	return 0;
}
int test2()
{
	vector<int> numbers;
	istream_iterator<int> isi(cin);
	copy(isi, istream_iterator<int>(), back_inserter(numbers));
	//copy(numbers.begin(), numbers.end(), ostream_iterator<int>(cout, " "));
	for(auto &elem : numbers)
	{
		cout<<elem<<" ";
	}
	cout<<endl;
	return 0;
}
int main()
{
	//test0();
	//test1();
	test2();
	return 0;
}
