#include<vector>
#include<set>
#include<utility>
#include<iostream>
#include<limits>

/*
1) Initialize distances of all vertices as infinite.

2) Create an empty set.  Every item of set is a pair
  (weight, vertex). Weight (or distance) is used used
  as first item  of pair as first item is by default 
  used to compare two pairs.

3) Insert source vertex into the set and make its
   distance as 0.

4) While Set doesn't become empty, do following
    a) Extract minimum distance vertex from Set. 
       Let the extracted vertex be u.
    b) Loop through all adjacent of u and do 
       following for every vertex v.

           // If there is a shorter path to v
           // through u. 
           If dist[v] > dist[u] + weight(u, v)

               (i) Update distance of v, i.e., do
                     dist[v] = dist[u] + weight(u, v)
               (i) If v is in set, update its distance
                   in set by removing it first, then
                   inserting with new distance
               (ii) If v is not in set, then insert
                    it in set with new distance
               
5) Print distance array dist[] to print all shortest
   paths. 
 */

#define inf INT_MAX/2

// graf prikazan pomocu matrice susjedstva gdje je pair<cvor, udaljenost> 

void Dijkstra (const std::vector<std::vector <std::pair< int, int > > > & graf, 
                std::vector<int> & dist, int start) {
    std::set <std::pair<int, int> > najblizi; // pair < udaljenost, cvor>
    najblizi.insert(std::make_pair(0, start));

    dist[start] = 0;
    while (!najblizi.empty()) {
        auto temp = *(najblizi.begin());
        najblizi.erase(najblizi.begin());
        int cvor = temp.second;

        for (int i = 0; i < graf[cvor].size(); i++) {
            int susjed = graf[cvor][i].first;
            int udaljenost = graf[cvor][i].second;

            if (dist[susjed] > dist[cvor] + udaljenost) {
                if (dist[susjed] != inf) 
                    najblizi.erase(najblizi.find(std::make_pair(dist[susjed], susjed)));
                
                dist[susjed] = dist[cvor] + udaljenost;
                najblizi.insert(std::make_pair(dist[susjed], susjed));
            }
        } 
            
        
    } 
}

int main () {
    int n = 9, m = 15;
    std::vector<std::vector <std::pair< int, int > > > graph;
    std::vector<int> dist(n, inf);
    std::vector<std::pair<int, int> > pom;
    graph.insert(graph.begin(), n , pom);

    std::cout << "Unesi graf" <<std::endl;
    int a, b, c;
    for (int i = 0; i < m; i++) {
        std::cin >> a >> b >>c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
    
    Dijkstra(graph, dist, 0);

    for (int i = 0; i < n; i++) std::cout << dist[i] << " ";

    return 0;
}