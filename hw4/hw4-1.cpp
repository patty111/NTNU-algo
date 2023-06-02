/*
    Problem #512 - NSFW
    djikstra
*/
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

const int INF = 1e9;

int n, m, k;
map<string, int> town_to_id;
vector<pair<int, int>> adj[1005];
int dist[1005];

void dijkstra(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    fill(dist, dist + n, INF);
    dist[start] = 0;
    pq.push({0, start});
    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        if (d > dist[u]) continue;
        for (auto [v, w] : adj[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    cin >> n >> m >> k;
    int next_id = 0;

    for (int i = 0; i < m; i++) {
        string u, v;
        int w;
        cin >> u >> v >> w;
        
        if (!town_to_id.count(u)) town_to_id[u] = next_id++;
        if (!town_to_id.count(v)) town_to_id[v] = next_id++;
        int uid = town_to_id[u], vid = town_to_id[v];
        adj[uid].push_back({vid, w});
        adj[vid].push_back({uid, w});
    }
    vector<int> stops;
    for (int i = 0; i < k; i++) {
        string s;
        cin >> s;
        stops.push_back(town_to_id[s]);
    }
    int ans = 0;
    for (int i = 0; i < k - 1; i++) {
        dijkstra(stops[i]);
        ans += dist[stops[i + 1]];
    }
    cout << ans << endl;
    return 0;
}