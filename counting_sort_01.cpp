#include<iostream>
#include<vector>
using namespace std;
void counting_sort(int *A,int *B,int n)
{
	vector<int>C(100);
	for(int i=0;i<n;++i)
	{
		C[A[i]]++;//count every num
	}
	for(int i=1;i<n;++i)
	{
		C[i]=C[i-1]+C[i];//make sure where is the num
	}
	for(int i=n-1;i>=0;--i)
	{
		B[C[A[i]]-1]=A[i];
		--C[A[i]];
	}
}
int main()
{
	int A[]{1,0,3,4,5,6,6,7,6,6,7,7,5,4,3,4,4,3,19,39,2};
	int n=sizeof(A)/sizeof(A[0])+1;
	int *B=new int[n];
	counting_sort(A,B,n);
	for(int i=0;i<n;++i)
	{
		cout<<A[i]<<" ";
	}
	cout<<endl;
	for(int i=0;i<n;++i)
	{
		cout<<B[i]<<" ";
	}
	cout<<endl;
}