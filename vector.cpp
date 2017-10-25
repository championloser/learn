#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int arr[]={1,2,3,4,5,6,7,8};
	for(int i=0; i<8; ++i)cout<<*(arr+i)<<" ";
	cout<<endl;
	vector<int> numbers(arr, arr+8);
	cout<<"the size="<<numbers.size()<<endl;
	cout<<"the capacity="<<numbers.capacity()<<endl;
	vector<int>::iterator it;
	for(it=numbers.begin(); it<numbers.end(); ++it)
	{
		cout<<*it<<" ";
	}
	cout<<endl;

	return 0;
}
