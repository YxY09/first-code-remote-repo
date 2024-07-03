#include <iostream>
#include <cmath>

int max_bit(int *arr, int size) {
    int max_num = 0;
    for (int i = 0; i < size; ++i) {
        if (arr[i] > max_num)
            max_num = arr[i];
    }
    int d = 1;
    while (max_num >= 10) {
        max_num /= 10;
        ++d;
    }
    return d;
}

int* counting_sort(int *arr, int d, int size) {
    int count[10] = {0}; // Initialize count array to all zeros
    int *new_arr = new int[size];

    for (int i = 0; i < size; ++i) {
        ++count[(arr[i] / static_cast<int>(pow(10, d))) % 10];
    }
    for (int i = 1; i < 10; ++i) {
        count[i] += count[i - 1];
    }
    for (int i = size - 1; i >= 0; --i) {
        new_arr[count[(arr[i] / static_cast<int>(pow(10, d))) % 10] - 1] = arr[i];
        --count[(arr[i] / static_cast<int>(pow(10, d))) % 10];
    }
    return new_arr;
}

void radix_sort(int *arr, int size) {
    int d = max_bit(arr, size);
    int *temp = nullptr;

    for (int i = 0; i < d; ++i) {
        temp = counting_sort(arr, i, size);
        std::copy(temp, temp + size, arr);
        delete[] temp; // Free the memory allocated by counting_sort
    }
}

int main() {
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int size = sizeof(arr) / sizeof(arr[0]);

    radix_sort(arr, size);

    std::cout << "Sorted array: ";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
