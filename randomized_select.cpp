#include<iostream>
#include<vector>
#include<cstdlib>
#include<algorithm>
#include<ctime>
using namespace std;
int parition(vector<int>&arr,int p,int q)
{

	int random_index=rand()%(q-p+1)+p;
	swap(arr[random_index], arr[q]);
	int last_ele=arr[q];
	int n=q-p+1;
	int j=p-1;
	for(int i=p;i<q;++i)
	{
		if(arr[i]<last_ele)
		{
			++j;
			swap(arr[j],arr[i]);
		}
	}
	swap(arr[j+1],arr[q]);
	return j+1;
}
// find the rst max element in p to q
int select(vector<int>&arr,int p,int q,int r)
{
	if(p>q)
	{
		cout<<"error,input again";
	}
	while(p<q)
	{
		int place=parition(arr,p,q);
		int k=place-p+1;
		if(k==r)
		{
			return arr[place];
		}
		else if(k>r)
		{
			q=place-1;
		}
		else
		{
			p=place+1;
		}
	}
	return arr[p];
}
int main()
{
	vector<int>number{1,24,5,4,3,421,4213,2,3,1214,22,23,1,23};
	int n=number.size();
	srand(time(nullptr));
	int res=select(number,0,n-1,3);
	cout<<res<<endl;
}

