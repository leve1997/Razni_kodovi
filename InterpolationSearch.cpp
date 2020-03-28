#include <iostream>

int InterpolationSearch (int arr[], int x, int n) {
    int left = 0, right = n - 1;

    while (left <= right && arr[left] <= x && arr[right] >= x) {
        if (left == right) {
            if (arr[x] == arr[left]) return left;
            return -1;
        }

        int pos = left + ((x - arr[left]) * (double)(right - left) / (arr[right] - arr[left]));

        if (arr[pos] == x) return pos;
        else if (arr[pos] < x) right = pos - 1;
        else left = pos + 1; 
    }

    return -1;
}