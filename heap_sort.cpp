#include<iostream>
using namespace std;
void adjust_down(int arr[],int parent,int size)
{
	int maxIndex=parent;
	int lhs=2*parent+1;
	int rhs=2*parent+2;
	if(lhs<size&&arr[lhs]>arr[maxIndex])
	{
		maxIndex=lhs;
	}
	if(rhs<size&&arr[rhs]>arr[maxIndex])
	{
		maxIndex=rhs;
	}
	if(maxIndex!=parent)
	{
		swap(arr[parent],arr[maxIndex]);
		adjust_down(arr,maxIndex,size);
	}

}
void heap_sort(int arr[],int size)
{
	//build a max heap
	for(int i=size/2-1;i>=0;--i)
	{
		adjust_down(arr,i,size);
	}
	//extract elements from the heap one by one
	for(int i=size-1;i>0;--i)
	{
		swap(arr[i],arr[0]);
		adjust_down(arr,0,i);
	}
}
int main() {
    int arr[] = {1, 4, 5, 2, 1, 4, 5, 6, 7, 2, 4, 5, 6, 3, 0, 19, 18, 201};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array:" << endl;
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    heap_sort(arr, size);

    cout << "Sorted array:" << endl;
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}