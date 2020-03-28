// disjoint set data structure
// Applications --> Union-find algorithm, detecting cycles in a graph, Kruskals MST, Job Sequesing problem
            // --> find = In which subset given element is
            // --> Union = Join 2 subsets in a single one

#include <iostream> 
#include <vector>

class DisjointSet {
public:
    // Constructor
    DisjointSet(int n);
    // Nalazi reprezentanta seta u kojem se x nalazi
    // Path Compression
    int Find (int x);
    // Spaja setove u kojima se nalaze x, odnosno y
    // Union by rank
    void Unija (int x, int y);
private:
    std::vector <int> Parent;
    std::vector <int> Rank;
    int broj_elemenata;
    void StartingSet();
};

DisjointSet::DisjointSet(int n) : broj_elemenata(n), Rank(n), Parent(n) {
    StartingSet();
}

void DisjointSet::StartingSet() {
    for (int i = 0; i < broj_elemenata; i++)
        Parent[i] = i;
}

int DisjointSet::Find (int x) {
    if (Parent[x] == x) return x;

    int result = Find(Parent[x]);

    // cache result
    Parent[x] = result;
    return result;
}

void DisjointSet::Unija (int x, int y) 
{
    int rep_x = Find(x);
    int rep_y = Find(y);

    if (rep_x == rep_y) return;

    if (Rank[rep_x] <= Rank[rep_y]) Parent[rep_x] = Parent[rep_y];
    else Parent[rep_y] = Parent[rep_x];

    if (Rank[rep_x] == Rank[rep_y]) Rank[rep_y]++;
}
