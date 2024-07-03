#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Helper function to sort a group and return its median
int sortAndFindMedian(vector<int>& group) {
    sort(group.begin(), group.end());
    return group[group.size() / 2];
}

// Helper function to partition the array around a pivot
int partition(vector<int>& arr, int left, int right, int pivot) {
    int pivotValue = arr[pivot];
    swap(arr[pivot], arr[right]);
    int i = left - 1;
    for (int j = left; j < right; ++j) {
        if (arr[j] < pivotValue) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[right]);
    return i + 1;
}

// Selection algorithm to find the kth smallest element in the array
int select(vector<int>& arr, int left, int right, int k) {
    if (left == right) {
        return arr[left];
    }

    // Partition the array into groups of size 5
    vector<int> medians;
    for (int i = left; i <= right; i += 5) {
        vector<int> group(arr.begin() + i, arr.begin() + min(i + 5, right + 1));
        int median = sortAndFindMedian(group);
        medians.push_back(median);
    }

    // Find the median of medians
    int medianOfMedians = select(medians, 0, medians.size() - 1, medians.size() / 2);

    // Partition the array around the median of medians
    int pivotIndex;
    for (pivotIndex = left; pivotIndex <= right; ++pivotIndex) {
        if (arr[pivotIndex] == medianOfMedians) {
            break;
        }
    }
    pivotIndex = partition(arr, left, right, pivotIndex);

    int pivotRank = pivotIndex - left + 1;

    if (k == pivotRank) {
        return arr[pivotIndex];
    } else if (k < pivotRank) {
        return select(arr, left, pivotIndex - 1, k);
    } else {
        return select(arr, pivotIndex + 1, right, k - pivotRank);
    }
}

int main() {
    vector<int> arr = {3, 6, 2, 8, 4, 7, 1, 5};
    int k = 3; // Find the 3rd smallest element

    int result = select(arr, 0, arr.size() - 1, k);
    cout << "The " << k << "th smallest element is: " << result << endl;

    return 0;
}
