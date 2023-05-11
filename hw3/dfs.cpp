#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Graph {
    int n;           
    vector<int>* adjList; 
    bool* visited;
    
public:
    Graph(int num_of_vertices){
        n = num_of_vertices;
        adjList = new vector<int>[n];
        visited = new bool[n];
    }
    
    void addEdge(int src, int dest){
        adjList[src].push_back(dest);
        adjList[dest].push_back(src);
    }
    
    void DFS(int vertex){
        visited[vertex] = true;
        cout << vertex << " ";

        for (auto v : adjList[vertex]){
            if (!visited[v]){
                DFS(v);
            }
        }
    }

    void printGraph() {
        for (int i=0; i<n; i++) {
            cout << i;

            sort(adjList[i].begin(), adjList[i].end());
            for (auto x : adjList[i])
                cout << " -> " << x;
            cout << endl;
        }
    }

    //destroy the dynamically allocated memory
    ~Graph() {
        delete[] adjList;
        delete[] visited;  
    }        
};

int main() {
    int n, m;
    cin >> n >> m;
    Graph g(n);
    
    for (int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        g.addEdge(a, b);
    }
    
    g.DFS(0);
    cout << endl;
    
    return 0;
}
