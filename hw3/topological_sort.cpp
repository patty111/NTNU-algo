#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

void topologicalSort(vector<vector<int>>& adjList, int n) {
    vector<int> indegree(n + 1, 0);
    vector<int> result; // to store the topological order

    // Step 1: Compute the indegree and adjacency list
    for (int i=0; i<adjList.size(); ++i){
        for (int j=0; j<adjList[i].size(); ++j){
            int u = i;
            int v = adjList[i][j];

            indegree[v]++;
        }
    }
    for (auto i: indegree){
        cout << i << " ";
    }
    cout << endl;

    // Step 2: Create a queue and enqueue vertices with indegree 0
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        // if (adjList[i].size() == 0)   
        //     continue;
        if (indegree[i] == 0)
            q.push(i);
    }

    // Step 3: Perform topological sorting
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        result.push_back(u);

        // Decrease the indegree of u's neighbors
        for (int v : adjList[u]) {
            indegree[v]--;
            if (indegree[v] == 0)
                q.push(v);
        }
    }

    // Print the topological order
    for (int i : result)
        cout << i << " ";
    cout << endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    // vector<pair<int, int>> graph;
    vector<vector<int>> adjList(n + 1);


    int prev, curr;
    cin >> prev;
    for (int i = 1; i < m; ++i) {
        cin >> curr;
        if (curr > prev)
            adjList[prev].push_back(curr);
        else
            adjList[curr].push_back(prev);
        prev = curr;
    }

    topologicalSort(adjList, n);

    return 0;
}
