#include<iostream>
#include<vector>
using namespace std;
int parition(vector<int>&A,int p,int q)
{
	int i=p-1;
	int j=p;
	for(;j<q;++j)
	{
		if(A[j]<A[q])
	    {
			++i;
			swap(A[j],A[i]);
		}
	}
	swap(A[q],A[i+1]);
	return i+1;
}
void quick_sort(vector<int>&A,int p,int q)
{
	if(p<q)
	{
		int r=parition(A,p,q);
		quick_sort(A,p,r-1);
		quick_sort(A,r+1,q);
	}

}
int main()
{
	vector<int>number{ 1,3,43,23,4,5,6,7,8,2,3,6,9,1 };
	int n = number.size();
	for (int i : number)
	{
		cout << i << " ";
	}
	cout<<endl;
	quick_sort(number, 0, n-1);
	for (int i : number)
	{
		cout << i << " ";
	}

}