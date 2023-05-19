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

void print_adjList(vector<vector<int>> adjList, int n){
    for (int u = 1; u <= n; u++) {
        cout << "Vertex " << u << " is adjacent to: ";
        for (int v : adjList[u]) 
            cout << v << " ";
        
        cout << endl;
    }
    cout << endl << "////////////////////////" << endl;
}

void topologicalSort(vector<pair<int, int>>& graph, int n) {

	// maybe i should check out degree
    vector<int> indegree(n + 1, 0);
    vector<vector<int>> adjList(n + 1, vector<int>(1, -2));
    vector<vector<int>> answer(n);

    for (auto& edge : graph) {
        int u = edge.first;
        int v = edge.second;
        if (adjList[u][0] == -2)
            adjList[u].pop_back();

        adjList[u].push_back(v);
        indegree[v]++;
    }

	// print adjList
	print_adjList(adjList, n);

    int count = 0;
    vector<int> tmp;
    for (int i = 1; i <= n; i++) {
        cout <<"indegree[" << i << "] : " << indegree[i] << endl;
        if (adjList[i][0] == -2)
            continue;

        bool is_isolated = (indegree[i] == 0 && adjList[i][0] == -2);
        if (is_isolated)
            cout << "is_isolated: " << i << endl;
        if (indegree[i] == 0 || is_isolated){
            answer[count].push_back(i);
            tmp.push_back(i);
        }
    }

    // for (auto k : answer[count]){
    //     cout << k << " ";
    // }
    // cout << endl;

    sort(tmp.begin(), tmp.end());
    // remove vertexes by setting the first element in adjList to -2
    for (int i=0; i<tmp.size(); ++i){
        if (adjList[tmp[i]].size() > 0)
            adjList[tmp[i]][0] = -2;
        else
            adjList[tmp[i]].push_back(-2);
    }

    ++count;

    print_adjList(adjList, n);
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
