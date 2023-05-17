/*
    Problem #502 - Budget Cut
    minimum spanning tree
    kruskal find max spanning tree
    the min of the graph is the max bottle neck
    then from the bottle neck, do a minimum spanning tree by kruskal
    2 spanning trees
*/

#include <iostream>
#include <vector>
using namespace std;

typedef struct V{
    int v;
    int weight;
}vertex;


void printGraph(vector<vector<vertex> > graph){
    for (int i=1; i<graph.size(); i++){
        cout << i << ": ";
        for(auto [vertex, weight] :graph[i]){
            // auto [vertex, weight] = neighbor;
            cout << "(" << vertex << ", " << weight << ") ";
        }
        cout << endl;
    }
}



void DFS_find_min(vector<vector<vertex> >& graph, int n, bool*& visited, int v, int ans){
    visited[v] = true;

    for (auto i: graph[v]){
        if(!visited[i.v]){
            ans = min(ans, i.weight);
            DFS_find_min(graph, n, visited, i.v, ans);
        }
    }
}


bool cmpfunc(const vertex& a, const vertex& b) {
    if (a.v == b.v)
        return a.weight < b.weight;
    else
        return a.v < b.v;
}



int main(){
    int n, m;
    cin >> n >> m;
    
    bool* visited = new bool[n];
    for (int i=0; i<n; i++)
        visited[i] = false;

    int ans = INT_MAX;
    int total_sum = 0;

    vector<vector<vertex> > graph(n + 1);  // Graph representation
    vector<int> result;


    for (int i=0; i<m; i++){
        int a, b, w;
        cin >> a >> b >> w;
        total_sum += w;
        vertex tmp; tmp.v = b; tmp.weight = w;
        graph[a].push_back(tmp);
        tmp.v = a;
        graph[b].push_back(tmp);
    }

    // sort graph
    for (auto& neighbors : graph)
        sort(neighbors.begin(), neighbors.end(), cmpfunc);

    // DFS()
    cout << total_sum << endl;
    printGraph(graph);

    return 0;
}