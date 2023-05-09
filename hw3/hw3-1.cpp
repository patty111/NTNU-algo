#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 100005;
int n, m, idx = 0, bridge_cnt = 0;
vector<int> adj[MAXN], bridges;
int low[MAXN], disc[MAXN], parent[MAXN];

void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void dfs(int u) {
    low[u] = disc[u] = ++idx;

    for (auto v : adj[u]) {
        if (!disc[v]) {
            parent[v] = u;
            dfs(v);
            low[u] = min(low[u], low[v]);

            if (low[v] > disc[u]) {
                bridge_cnt++;
                bridges.push_back(u);
                bridges.push_back(v);
            }
        } else if (v != parent[u]) {
            low[u] = min(low[u], disc[v]);
        }
    }
}

void findBridges() {
    for (int i = 1; i <= n; ++i) {
        if (!disc[i]) {
            dfs(i);
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        addEdge(a, b);
    }


    
    findBridges();

}