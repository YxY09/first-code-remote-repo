#include<iostream>
using namespace std;
void insertion_sort(int *arr,int size)
{
	for(int i=1;i<size;++i)
		{
			int key=arr[i];
			int j=i-1;
			while(j>=0&&arr[j]>key)
			{
				arr[j+1]=arr[j];
				--j;
			}
			arr[j+1]=key;
			

		}
}
int main()
{
	int arr[]={1,4,2,1,2,4,5,12,3,12,3,4,12,3,12};
	int n=sizeof(arr)/sizeof(arr[0]);
	for(int i=0;i<n;++i)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	insertion_sort(arr,n);
	for(int i=0;i<n;++i)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}