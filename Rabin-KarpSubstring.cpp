// Algorithm to find substring a in a larger string b
// in O(a + b) time
#include <string>
#include <iostream>
#include <cassert>
#include <math.h>

#define MOD 101

int hashFunc (std::string s) {
    int sum = 0;

    for (int i = 0; i < s.size(); i++)
        sum = (128 * sum + static_cast<int>(s[i])) % MOD;

    return sum;
}

// returns smallest index if such substring exists, else returns -1
// can be modified to return last, or how many times it appears...
int findSubstring (std::string bigger, std::string smaller) {
    assert(bigger.size() > smaller.size());
    int hash1 = hashFunc(smaller);
    std::string pom = bigger.substr(0, smaller.size());
    int tr = hashFunc(pom);
    int pot = static_cast<int>(pow(128, smaller.size() - 1)) % MOD;

    for (int i = 0; i < bigger.size() - smaller.size() + 1; i++) {
        pom = bigger.substr(i, smaller.size());
        if (tr == hash1) {
            if (pom == smaller) return i;
        }
        if (i + smaller.size() < bigger.size())
        tr = (128 * (tr - static_cast<int>(bigger[i]) * pot)
            + static_cast<int>(bigger[i + smaller.size()])) % MOD;
        if (tr < 0) tr += MOD;
    }
    
    return -1;
}

// tester function
int main () {
    std::string a = "ear", b = "doe are hearing me";
    std::cout << findSubstring(b, a) << std::endl;

    return 0;
}