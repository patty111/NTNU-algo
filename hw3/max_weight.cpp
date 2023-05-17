#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

typedef struct V{
    int v;
    int weight;
}vertex;

vector<int> path_w;

void printGraph(vector<vector<vertex>> graph){
    for (int i=1; i<graph.size(); i++){
        cout << i << ": ";
        for(auto [vertex, weight] :graph[i]){
            // auto [vertex, weight] = neighbor;
            cout << "(" << vertex << ", " << weight << ") ";
        }
        cout << endl;
    }
}


void DFS(vector<vector<vertex>> graph, int n, bool*& visited, int v, int min_w, vector<int>& result, int end){
    visited[v] = true;
    // cout << v << endl;
    // cout << min_w << endl;
    if (v == end){
        path_w.push_back(min_w);
        cout << "end: "<< min_w << endl;
        return;
    }

    for (auto i: graph[v]){

        // cout << "\nvisited: ";
        // for (int j=0; j<n; j++)
        //     cout << visited[j] << " ";
        // cout << endl;
        if(!visited[i.v]){
            min_w = min(min_w, i.weight);
            // result.push_back(min_w);
            cout << i.v << " "<< end << endl;
            // end of path
            DFS(graph, n, visited, i.v, min_w, result, end);
        }
    }
}


bool compare_vertices(const vertex& a, const vertex& b) {
    if (a.v == b.v)
        return a.weight < b.weight;
    else
        return a.v < b.v;
}


int main() {
    int n, m;  // Number of islands and edges
    int start, end;

    cin >> n >> m;
    
    bool* visited = new bool[n];
    for (int i=0; i<n; i++)
        visited[i] = false;
    
    cout << endl;
    int min_w = INT_MAX;
    
    vector<vector<vertex>> graph(n + 1);  // Graph representation
    vector<int> result;


    for (int i=0; i<m; i++){
        int a, b, w;
        cin >> a >> b >> w;
        graph[a].push_back({b, w});
        graph[b].push_back({a, w});
    }

    // sort graph
    for (auto& neighbors : graph)
        sort(neighbors.begin(), neighbors.end(), compare_vertices);

    cin >> start >> end;

    DFS(graph, n, visited, start, min_w, result, end);

    printGraph(graph);
    
    int ans = INT_MIN;
    for (auto i: path_w)
        cout << i << " ";
        // ans = ans < i ? i : ans;
    // cout << ans << endl;
    return 0;
}
