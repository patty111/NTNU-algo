#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int MAXN = 99999;

vector<pair<int, double>> adj[MAXN];
double dist[MAXN];

int main() {
    int n, m, start, end;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        double p;
        cin >> a >> b >> p;
        adj[a].push_back({b, p});
        adj[b].push_back({a, p});
    }
    cin >> start >> end;

    priority_queue<pair<double, int>> pq;
    pq.push({1.0, start});
    fill(dist, dist + n, 0.0);
    dist[start] = 1.0;

    while (!pq.empty()) {
        double d = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        
        if (u == end) {
            printf("%.3f\n", dist[end]);
            return 0;
        }

        if (d < dist[u])
            continue;
        
        for (auto [v, p] : adj[u]) {
            double nd = dist[u] * p;
                if (nd > dist[v]) {
                    dist[v] = nd;
                    pq.push({dist[v], v});
                }
        }
    }

    cout << "0.000" << endl;
    return 0;
}