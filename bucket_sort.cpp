/*#include<iostream>
#include<vector>
using namespace std;
void insert_sort(vector<float>&bucket)
{
	for(int i=0;i<bucket.size();++i)
	{
		float key =bucket[i];
		int j=i-1;
		while(j>0&&bucket[j]>key)
		{
			bucket[j+1]=bucket[j];
			--j;
		}
		bucket[j+1]=key;
	}
}
void bucket_sort(float *arr,int n)
{
	vector<float>b[n];
	for(int i=0;i<n;++i)
	{
		int bi=n*arr[i];
		b[bi].push_back(arr[i]);
	}
	for(int i=0;i<n;i++)
	{
		insert_sort(b[i]);
	}
	int index =0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < b[i].size(); j++) {
            arr[index++] = b[i][j];
        }
    }
}
int main() {
    float arr[] = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};
    int n = sizeof(arr) / sizeof(arr[0]);
    bucket_sort(arr, n);

    cout << "Sorted array is \n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}*/
//a improved bucket_sort
#include <iostream>
#include <vector>
#include <algorithm> // For std::sort
using namespace std;

void bucket_sort(float *arr, int n) {
    // 使用 std::vector<float> 替代 C 风格数组
    vector<float> b[n];

    // 确定输入数据的范围
    float min_val = *min_element(arr, arr + n);
    float max_val = *max_element(arr, arr + n);

    // 动态确定桶的数量
    int num_buckets = n;

    // 将元素放入桶中
    for(int i = 0; i < n; ++i) {
        int bi = (arr[i] - min_val) / (max_val - min_val) * (num_buckets - 1);
        b[bi].push_back(arr[i]);
    }

    // 对每个桶中的元素进行排序，使用快速排序
    for(int i = 0; i < num_buckets; i++) {
        sort(b[i].begin(), b[i].end());
    }

    // 将排序后的元素放回原数组中
    int index = 0;
    for (int i = 0; i < num_buckets; i++) {
        for (int j = 0; j < b[i].size(); j++) {
            arr[index++] = b[i][j];
        }
    }
}

int main() {
    float arr[] = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};
    int n = sizeof(arr) / sizeof(arr[0]);
    bucket_sort(arr, n);

    cout << "Sorted array is \n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
