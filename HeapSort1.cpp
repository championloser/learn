#include<iostream>
using namespace std;
template <typename T, typename Compare=std::less<T> >
class HeapSort
{
public:
	HeapSort(T *arr, int size);
	void heapSort();
	void heapAdjust(int s, int m);
private:
	T *_arr;
	int _size;
	Compare _compare;
};
template <typename T, typename Compare>
HeapSort<T, Compare>::HeapSort(T *arr, int size)
: _arr(arr)
, _size(size)
{}
template <typename T, typename Compare>
void HeapSort<T, Compare>::heapAdjust(int s, int m)
{
	T tmp=_arr[s];
	for(int j=2*s+1; j<=m; j=2*j+1)
	{
		if(j<m && _compare(_arr[j], _arr[j+1]))++j;
		if(_compare(_arr[j], tmp))break;
		_arr[s]=_arr[j];
		s=j;
	}
	_arr[s]=tmp;
}
template <typename T, typename Compare>
void HeapSort<T, Compare>::heapSort()
{
	int i;
	T tmp;
	for(i=_size/2-1; i>=0; --i)heapAdjust(i,_size-1);
	for(i=_size-1; i>0; --i)
	{
		tmp=_arr[0];
		_arr[0]=_arr[i];
		_arr[i]=tmp;
		heapAdjust(0,i-1);
	}
}
struct Compare
{
	bool operator()(int &lhs, int &rhs)
	{
		return lhs>rhs;
	}
};
int test0()
{
	int arr[8]={49,38,65,97,76,13,27,49};
	for(int i=0; i<8; ++i)cout<<arr[i]<<" ";
	cout<<endl;
	HeapSort<int,std::less<int> > hs(arr,8);
	hs.heapSort();
	for(int i=0; i<8; ++i)cout<<arr[i]<<" ";
	cout<<endl;
	return 0;
}
int test1()
{
	int arr[8]={49,38,65,97,76,13,27,49};
	for(int i=0; i<8; ++i)cout<<arr[i]<<" ";
	cout<<endl;
	HeapSort<int,std::greater<int> > hs(arr,8);
	hs.heapSort();
	for(int i=0; i<8; ++i)cout<<arr[i]<<" ";
	cout<<endl;
	return 0;
}
int main()
{
	test0();
	cout<<endl;
	test1();
	return 0;
}
