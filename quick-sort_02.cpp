#include<iostream>
#include<vector>
using namespace std;
int parition(vector<int>&A,int p,int q)
{
	int i=p-1,j=p;
	int  end_value=A[q];
	for(;j<q;++j)
	{
		if(A[j]<end_value)
			swap(A[j],A[++i]);
	}
	swap(A[i+1],A[q]);
return i+1;
}
void quick_sort(vector<int>&A,int p,int q)
{
	if(p<q)
	{
		int i=parition(A,p,q);
		quick_sort(A,p,i-1);
		quick_sort(A,i+1,q);
	}
}
int main() {
    int length;
    cin>>length;
    vector<int>array(length);
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
    quick_sort(array,0,length-1);
    for(int i=0;i<length;++i)
    {
    	cout<<array[i]<<" ";
    }
    cout<<endl;
    return 0;
}