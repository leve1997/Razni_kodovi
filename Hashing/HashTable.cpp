#include <list>
#include <vector>
#include <iostream>
#include "HashTable.h"

Hash::Hash (int V) : Buckets(V), table(Buckets)
{}

bool Hash::searchItem(int x) {
    int ind = hashFunction(x);
    for (auto it = table[ind].begin(); it != table[ind].end(); it++)
        if (*it == x) return true;
    return false;
}

void Hash::insertItem(int x) {
    int ind = hashFunction(x);
    table[ind].push_back(x);
}

void Hash::deleteItem(int x) {
    int ind = hashFunction(x);
    auto it = table[ind].begin();
    for (it; it != table[ind].end(); it++)
        if (*it == x) break;
    
    if (it != table[ind].end()) table[ind].erase(it); 
}

void Hash::displayHash() {
    for (int i = 0; i < Buckets; i++) {
            std::cout << i << " --> ";
        for (auto j = table[i].begin(); j != table[i].end(); j++)
            std::cout << *j << "\t";
            std::cout << std::endl;
    }
}