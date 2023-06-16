/*
    Problem #515 - Hapi Patrol Officers
    maximum flow
*/
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

int bfs(int** G, int n, int s, int t, int* parent) {
    bool visited[n];
    memset(visited, false, sizeof(visited));
    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v = 0; v < n; v++) {
            if (!visited[v] && G[u][v] > 0) {
                q.push(v);
                visited[v] = true;
                parent[v] = u;
            }
        }
    }
    return visited[t];
}

int edmonds_karp(int** G, int n, int s, int t) {
    int** residual = new int*[n];
    for (int i = 0; i < n; i++) {
        residual[i] = new int[n];
        for (int j = 0; j < n; j++)
            residual[i][j] = G[i][j];
    }

    int parent[n];
    int max_flow = 0;

    while (bfs(residual, n, s, t, parent)) {
        int path_flow = numeric_limits<int>::max();

        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            path_flow = min(path_flow, residual[u][v]);
        }

        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            residual[u][v] -= path_flow;
            residual[v][u] += path_flow;
        }
        max_flow += path_flow;
    }

    for (int i = 0; i < n; i++)
        delete[] residual[i];
    delete[] residual;
    return max_flow;
}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;  // number of police stations
    cin >> n;
    int** G = new int*[n*2+2];
    for (int i=0; i<n*2+2; ++i){
        G[i] = new int[n*2+2];
        for (int j=0; j<n*2+2; ++j)
            G[i][j] = 0;
    }


    for (int i=1; i<=n; ++i){
        int w;
        cin >> w;
        G[0][i] = w;
    }

    int sum = 0;
    for (int i=0; i<n; ++i){
        int w;    
        cin >> w;
        G[n+1+i][2*n+1] = w;
        sum += w;
    }

    int count = 0;
    for (int i=0; i<n; ++i){
        int* transfer = new int[n];
        transfer[i] = G[0][i];

        for (int j=0; j<n; ++j){
            int tmp;
            cin >> tmp;
            G[i+1][j+n+1] = tmp;
        }
        G[i+1][i+1+n] = G[0][i+1];  
    }

    cout << sum - edmonds_karp(G, n*2+2, 0, n*2+1) << endl;
    return 0;
}