/*
    Problem #504 - Corgi-Ball
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void output(int* v, int n){
    for (int i=0; i<n; ++i)
        cout << i << " ";
    cout << endl;
}


void DFS(int i, int*& visited, vector<int>& nodes, vector<pair<int, int>>& graph){
    visited[i] = 1;
    
}


int* topological_sort(vector<pair<int, int>> graph, int node_num){
    
    int* visited = new int[node_num, 0];
    int* result = new int[node_num, 0];
    int idx = node_num - 1;

    for (int i=0; i<node_num; ++i){
        if (visited[i] == 0){
            vector<int> nodes;
            
            DFS(i, visited, nodes, graph);
            for (auto i: nodes){
                result[idx] = i;
                i--;
            }
        }
    }
    return result;
}




int main(){
    int n, m;
    cin >> n >> m;
    int* shots =  new int[n];
    vector<pair<int, int>> graph(m-1);

    cin >> shots[0];
    for (int i=1; i<m; ++i){
        cin >> shots[i]; 
        if (shots[i] > shots[i-1])
            graph.push_back({shots[i-1], shots[i]});
        else
            graph.push_back({shots[i], shots[i-1]});
    }
    




    return 0;
}
// 先建圖
// Dfs and BFS 附近但不是這兩個 -> topological sort
// 