// test program for hashing
#include <iostream>
#include "HashTable.h"
int main () {
    int n = 12;
    int arr[] = {15, 60, 2, 9, 568, 751, 45, 86, 55, 47, 33, 100};

    Hash h(7);
    
    for (int i = 0; i < n; i++)
        h.insertItem(arr[i]);

    std::cout << "Pocetno stanje:\n";
    h.displayHash();

    for (int i = 0; i < n; i++) 
        if (arr[i] % 3 == 0) h.deleteItem(arr[i]);

    h.displayHash();

    return 0;
}