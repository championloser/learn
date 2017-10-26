#include<iostream>
using namespace std;
void HeapAdjust(int *arr, int s, int m)
{
	int tmp=arr[s];
	for(int j=2*s+1; j<=m; j=2*j+1)
	{
		if(j<m && arr[j]<arr[j+1])++j;
		if(tmp>arr[j])break;
		arr[s]=arr[j];
		s=j;
	}
	arr[s]=tmp;
}
void HeapSort(int *arr, int length)
{
	int i;
	int tmp;
	for(i=length/2-1; i>=0; --i)HeapAdjust(arr,i,length-1);
	for(i=length-1; i>0; --i)
	{
		tmp=arr[0];
		arr[0]=arr[i];
		arr[i]=tmp;
		HeapAdjust(arr,0,i-1);
	}
}
int main()
{
	int arr[8]={49,38,65,97,76,13,27,49};
	for(int i=0; i<8; ++i)cout<<arr[i]<<" ";
	cout<<endl;
	HeapSort(arr, 8);
	for(int i=0; i<8; ++i)cout<<arr[i]<<" ";
	cout<<endl;
	return 0;
}
