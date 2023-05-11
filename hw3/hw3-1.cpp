/*
    Problem #500 - Shopocalypse Now: Finding Critical Roads in a Town
    Bridges in a graph
    Tarjan’s Algorithm
*/


#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
using namespace std;

class Graph{
    int V;
    list<int> *adj;
    void findCritRoad(int u, vector<bool>& visited, vector<int>& disc, vector<int>& low, int parent, vector<pair<int,int>>& roads);

public:
    Graph(int V);
    void addEdge(int v, int w);
    void printRoads();
};

Graph::Graph(int V){
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int src, int dest){
    adj[src].push_back(dest);
    adj[dest].push_back(src);
}

void Graph::findCritRoad(int u, vector<bool>& visited, vector<int>& disc, vector<int>& low, int parent, vector<pair<int,int>>& roads){
    static int time = 0;
    visited[u] = true;
    disc[u] = low[u] = ++time;

    for (list<int>::iterator i = adj[u].begin(); i != adj[u].end(); i++){
        int v = *i;
        if (v == parent)
            continue;

        if(visited[v])
            low[u] = min(low[u], disc[v]);
        
        else{
            parent = u;
            findCritRoad(v, visited, disc, low, parent, roads);
            low[u] = min(low[u], low[v]);
            if (low[v] > disc[u])
                roads.push_back({min(u,v), max(u,v)});
        }
    }
}

void Graph::printRoads(){
    vector<bool> visited (V,false);
    vector<int> disc (V,-1);
    vector<int> low (V,-1);
    int parent = -1;
    vector<pair<int,int>> roads;
    for (int i=0; i<V; i++)
        if (visited[i] == false)
            findCritRoad(i, visited, disc, low, parent, roads);
    
    sort(roads.begin(), roads.end());

    int flag = 1;
    for (auto road : roads){
        flag = 0;
        cout << road.first << " " << road.second << endl;
    }
    if (flag)
        cout << "No Critical Road" << endl;
}


int main(){
    int n, m;
    cin >> n >> m;
    Graph g(n);
    for (int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        g.addEdge(a, b);
    }
    g.printRoads();
    return 0;
}
