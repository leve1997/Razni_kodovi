#include<vector>
#include<set>
#include<utility>
#include<iostream>
#include<limits>
#include<algorithm>
#include "DisjointSetImpl.h"

#define inf INT_MAX/2

void KruskalMST (std::vector<std::pair <int, std::pair <int, int> > > & edges, int n, std::vector <std::vector <int> > & Parent) {
    std::sort(edges.begin(), edges.end());
    DisjointSet ds(n);

    int brojac = 0;
    for (auto it = edges.begin(); it != edges.end(); it++) {
        int u = it->second.first;
        int v = it->second.second;
        int tezina = it->first;

        int rep_u = ds.Find(u);
        int rep_v = ds.Find(v);

        if (rep_u != rep_v) {
            Parent[brojac][0] = u;
            Parent[brojac][1] = v;
            Parent[brojac++][2] = tezina;
            ds.Unija(rep_u, rep_v);
        }
        if (brojac == n - 1) break;
    }
}

int main () {
    int n, m;
    std::cin >> n >> m;
    std::vector <int> p(3);
    std::vector<std::vector <int> > Parent(n - 1, p);
    std::vector <std::pair <int, std::pair <int, int> > > edges;
    edges.reserve(m);

    std::cout << "Unesi graf" <<std::endl;
    int a, b, c;
    for (int i = 0; i < m; i++) {
        std::cin >> a >> b >>c;
        edges.push_back({c, {a, b}});
    }

    KruskalMST(edges, n, Parent);

    for (int i = 0; i < Parent.size(); i++) 
        std::cout << Parent[i][0] << " <-> " << Parent[i][1] << " = " << Parent[i][2] << std::endl;

    return 0;
}