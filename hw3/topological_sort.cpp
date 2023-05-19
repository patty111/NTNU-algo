#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

void output(int* v, int n) {
    for (int i = 0; i < n; ++i)
        cout << v[i] << " ";
    cout << endl;
}

void topologicalSort(vector<pair<int, int>>& graph, int n) {

	// maybe i should check out degree
    vector<int> indegree(n + 1, 0);
    vector<vector<int>> adjList(n + 1, vector<int>());

    for (auto& edge : graph) {
        int u = edge.first;
        int v = edge.second;
        adjList[u].push_back(v);
        indegree[v]++;
    }

	// print adjList
	for (int u = 1; u <= n; u++) {
    cout << "Vertex " << u << " is adjacent to: ";
    for (int v : adjList[u]) {
        cout << v << " ";
    }
    cout << endl;
	}

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0)
            q.push(i);
    }

    vector<int> sortedOrder(n, -1);
	int idx = 0;
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        sortedOrder[idx] = curr;

        for (int neighbor : adjList[curr]) {
            indegree[neighbor]--;
            if (indegree[neighbor] == 0)
                q.push(neighbor);

		// output(sortedOrder.data(), n);
        }
		++idx;
    }

    if (sortedOrder.size() != n) {
        cout << -1 << endl;  // Not a valid topological order
    } else {
        output(sortedOrder.data(), n);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    int* shots = new int[n];
    vector<pair<int, int>> graph;

    cin >> shots[0];
    for (int i = 1; i < m; ++i) {
        cin >> shots[i];
        if (shots[i] > shots[i - 1])
            graph.push_back({ shots[i - 1], shots[i] });
		else
            graph.push_back({ shots[i], shots[i - 1] });
    }


    topologicalSort(graph, n);

    delete[] shots;
    return 0;
}
