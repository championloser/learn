#include<iostream>
#include<algorithm>
#include<vector>
#include<list>
#include<iterator>
using std::cout;
using std::endl;
using std::vector;
using std::list;
using std::copy;
using std::ostream_iterator;
using std::back_insert_iterator;
using std::front_insert_iterator;
using std::insert_iterator;
template <typename Container>
void printContainer(Container &con)
{
	typename Container::iterator it;
	for(it=con.begin(); it!=con.end(); ++it)
	{
		cout<<*it<<" ";
	}
	cout<<endl;
	//for(auto &elem : con)
	//{
	//	cout<<elem<<" ";
	//}
	//cout<<endl;
}
int main()
{
	vector<int> numbers{1,2,3};
	list<int> listInt;
	copy(numbers.begin(), numbers.end(), ostream_iterator<int>(cout, " "));
	cout<<endl;
	copy(numbers.begin(), numbers.end(), back_insert_iterator<list<int> >(listInt));
	printContainer(listInt);
	copy(numbers.begin(), numbers.end(), front_insert_iterator<list<int> >(listInt));
	printContainer(listInt);
	copy(numbers.begin(), numbers.end(), insert_iterator<list<int> >(listInt, ++listInt.begin()));
	printContainer(listInt);
	return 0;
}
