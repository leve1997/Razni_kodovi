#include <vector>
#include <iostream>

int BinarySearch (const std::vector <int> & arr, int x, int left, int right) {
    if (left > right) return -1;
    int m = (left + right) / 2;
    if (arr[m] == x) return m;
    if (arr[m] < x) return BinarySearch(arr, x, m + 1, right);
    return BinarySearch(arr, x, left, m - 1);    
}