/*
Algoritam koji pronalazi sve putove od vrha t do vrha s u grafu
Koristimo DFS... u vector parent spremamo trenutni put
vector<vector<int>> ce biti putevi.. size je broj puteva

*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <list>

void DFSPath (int start, int end, std::vector<bool> & visited, const std::vector <std::vector <int> > & Graph, 
                std::list<int> & path, std::list<std::list <int> > & SviPutevi, int & index) {
    path.push_back(start);
    visited[start] = true;
    if (start == end) {
        SviPutevi.push_back(path);
    }

    else 
    for (int i = 0; i < Graph[start].size(); i++) {
        int cvor = Graph[start][i];
        if (!visited[cvor]) DFSPath(cvor, end, visited, Graph, path, SviPutevi, index);   
    }     

    visited[start] = false;
    path.pop_back();
}

int main () 
{
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector <int> > graph;
    std::vector<bool> visited(n, false);
    std::vector<int> pom;
    graph.insert(graph.begin(), n , pom);

    std::cout << "Unesi graf" <<std::endl;
    int a, b, c;
    for (int i = 0; i < m; i++) {
        std::cin >> a >> b;
        graph[a].push_back(b);
    }

    int start, end;
    std::cout << std::endl << "Unesi pocetni i zavrsni cvor" << std::endl;
    std::cin >> start >> end;

    std::list<int> path;
    std::list<std::list<int> > Putevi;
    int path_index = 0;
    DFSPath(start, end, visited, graph, path, Putevi, path_index);

    for (auto i = Putevi.begin(); i != Putevi.end(); i++) {
        for (auto j = i->begin(); j != i->end(); j++) {
            if (*j == -1) break;
            std::cout << *j << " ";
        }
            std::cout <<std::endl;
    }

return 0;
}