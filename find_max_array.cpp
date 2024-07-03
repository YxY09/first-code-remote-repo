#include<iostream>
#include<climits>
using namespace std;
int find_max_crossing_arr(int *array,int middle,int p,int q)
{
	int left_sum=-INT_MAX,right_sum=-INT_MAX;
	int sum=0;
	for(int i=middle;i>=p;--i)
	{
		sum+=array[i];
		if(sum>left_sum)
			left_sum=sum;
		else
			break;
	}
	sum=0;
	for(int i=middle+1;i<=q;++i)
	{
		sum+=array[i];
		if(sum>right_sum)
		{
			right_sum=sum;
		}
		else
			break;
	}
	return right_sum+left_sum;
}
int find_max_arr(int *arr,int p, int q)
{
	if(p==q)
		return arr[p];
	int mid=p+(q-p)/2;
	int left_max=find_max_arr(arr,p,mid+1);
	int right_max=find_max_arr(arr,mid+1,q);
	int crossing_max=find_max_crossing_arr(arr,mid,p,q);
	return max(max(left_max,right_max),crossing_max);
}
int find_max_arr_with_x(int *arr,int size)
{
	int max=0;
	for(int i=0;i<size;++i)
	{
		max=max+arr[i]>max?max+arr[i]:arr[i];
	}
	return max;
}
int main()
{
    int arr[] = {5, -7, 9, 2, -4, 3, -8, 6, 1, -2, 7, -3, 4, -6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int max_sum = find_max_arr(arr, 0, n - 1);
    cout << "Maximum contiguous sum is: " << max_sum << endl;
    cout<<"another way to get the Maximum"<<find_max_arr_with_x(arr,n-1)<<endl;
    return 0;
}