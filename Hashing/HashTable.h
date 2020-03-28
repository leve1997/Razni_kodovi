// C++ class that implements hashing with chaining
// only for integers
#include <list> 
#include <vector>

class Hash {
    int Buckets;
    std::vector <std::list <int> > table;
    int hashFunction(int x) {
        return x % Buckets;
    }
public:
    Hash(int V);
    bool searchItem(int x);
    void insertItem(int x);
    void deleteItem(int x);
    void displayHash();
};