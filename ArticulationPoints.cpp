#include<vector>
#include<set>
#include<utility>
#include<iostream>
#include<limits>
#include <algorithm>

int brojac = 1;

int ArtDFS (const std::vector <std::vector <int> > & Graph, int cvor, int roditelj,
            std::vector<int> & Art, std::vector<int> & rbr) {
    rbr[cvor] = brojac;
    int minBr = brojac, brGrananja = 0, t, maxt = 0; // maxt je najveci minBr djece --> sluzi za provjeru je li art tocka

    for (int i = 0; i < Graph[cvor].size(); i++) {
        if (Graph[cvor][i] == roditelj) continue;
        if (rbr[Graph[cvor][i]]) minBr = std::min(minBr, rbr[Graph[cvor][i]]);
        else {
            brojac++;
            brGrananja++;
            t = ArtDFS(Graph,Graph[cvor][i], cvor, Art, rbr);
            maxt = std::max(maxt, t);
            minBr = std::min(minBr, t);
        }
    }

        if (rbr[cvor] == 1) { // ako je pocetni
            if (brGrananja > 1) Art.push_back(cvor);
        }
        else if (maxt >= rbr[cvor] && Graph[cvor].size() > 1)  // Art tocka ako i samo ako u DFS stablu cvor X ima neko dijete Y t.d je rbr[X] <= miknBr[Y]
            Art.push_back(cvor);

    return minBr;
}

int main () 
{
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector <int> > graph;
    std::vector<int> redniBr(n, 0);
    std::vector<int> ArtPoints;
    std::vector<int> pom;
    graph.insert(graph.begin(), n , pom);

    std::cout << "Unesi graf" <<std::endl;
    int a, b, c;
    for (int i = 0; i < m; i++) {
        std::cin >> a >> b;
        if (a == b) continue;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    ArtDFS(graph, 0, -1, ArtPoints, redniBr);
    std::sort(ArtPoints.begin(), ArtPoints.end());

    for (int i = 0; i < ArtPoints.size(); i++) std::cout << ArtPoints[i] << " ";

    system("pause");
    return 0;
}