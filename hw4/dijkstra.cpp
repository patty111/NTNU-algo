/**
 * Description: Dijkstra (Find shortest path from single source)
 * Usage: dijkstra O((V + E) lg(V))
 * Source: https://github.com/dragonslayerx
 */
#include <vector>
#include <iostream>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;
const int MAX = 100050;
const int INF = 1e9;

vector<int> dijkstra(vector<vector<pair<int, int>>> &G, int vertexCount, int src, int dist[], int target, vector<vector<int>> &passingVertices) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    bool isvisited[MAX];

    for (int i = 0; i < vertexCount; i++) {
        dist[i] = INF;
        isvisited[i] = false;
    }

    int* max_w = new int[vertexCount];
    dist[src] = 0;
    pq.push(make_pair(0, src));
    vector<int> path_record(G.size()+1, -1);
    
    while (!pq.empty()) {
        pair<int, int> tp = pq.top();
        pq.pop();

        int node = tp.second;
        int d = tp.first;

        if (!isvisited[node]) {
            isvisited[node] = true;
            for (int i = 0; i < G[node].size(); i++) {
                int v = G[node][i].first;
                int w = G[node][i].second;

                if (dist[v] > d + w) {
                    dist[v] = d + w;
                    path_record[v] = node+1;  // record path
                    pq.push(make_pair(dist[v], v));
                }
            }
        }
    }

    set<int> appear;
    vector<int> path;
    for (auto i: path_record){
        if (i != -1 && appear.find(i) == appear.end()){
            appear.insert(i);
            path.push_back(i);
        }
    }
    return path;

}



int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int,int> > > G(n);
    vector<vector<int>> passing_v;

    for (int i=0; i<m; ++i){
        G.push_back(vector<pair<int, int> >());
        int a, b, w;
        cin >> a >> b >> w;
        a--;b--;
        G[a].push_back(make_pair(b, w));
        G[b].push_back(make_pair(a, w));
    }

    int* dist = new int[n+1];



    vector<int> ans = dijkstra(G, n, 0, dist, n-1, passing_v);

    cout << "Shortest distance from vertex 1 to vertex " << n << " is " << dist[n-1] << endl;

    for (auto i: ans){
        cout << i << " ";
    }
    

    return 0;
}
