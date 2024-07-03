#include<iostream>
#include<climits>
using namespace std;
void merge_sort(int *A,int begin,int middle,int end)
{
	int n0=middle-begin+1;
	int n1=end-middle;
	int *left=new int[n0+1];
	int *right=new int [n1+1];
	for(int i=0;i<n0;++i)
	{
		left[i]=A[begin+i];
	} 
	for(int i=0;i<n1;++i)
	{
		right[i]=A[middle+i+1];
	}
	left[n0]=right[n1]=INT_MAX;
	int i=0,j=0;
	for(int k=begin;k<=end;++k)
	{
		if(left[i]<=right[j])
		{
			A[k]=left[i++];
		}
		else 
		{
			A[k]=right[j++];
		}
	}
	delete []left;
	delete []right;
}
void merge(int *A,int begin,int end)
{

	if(begin<end)
	{
		int middle=begin+(end-begin)/2;
		merge(A,begin,middle);
		merge(A,middle+1,end);
		merge_sort(A,begin,middle,end);
	}
}
int main() {
    int length;
    cin>>length;
    int *array=new int[length];
    for(int i=0;i<length;++i)
    {
    	cin>>array[i];
    }
    for(int i=0;i<length;++i)
    {
    	cout<<array[i]<<" ";
    }
    cout<<endl;
    cout<<"after sorting:"<<endl;
    merge(array,0,length-1);
    for(int i=0;i<length;++i)
    {
    	cout<<array[i]<<" ";
    }
    cout<<endl;
    return 0;
}