#include<iostream>
#include<vector>
#include<algorithm>
using std::cout;
using std::endl;
using std::vector;
//void function(int &elem)
//{
//	cout<<elem<<" ";
//}
int main()
{
	vector<int> numbers{1,2,3,4,5,6};
	for_each(numbers.begin(), numbers.end(), [](int &elem){
			cout<<elem<<" ";
	});
	cout<<endl;
	return 0;
}
