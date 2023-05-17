#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, weight;
};

bool descmp(const Edge& a, const Edge& b) {
    return a.weight > b.weight;
}

bool asccmp(const Edge& a, const Edge& b) {
    return a.weight < b.weight;
}

int findParent(vector<int>& parent, int v) {
    if (parent[v] == v)
        return v;
    return findParent(parent, parent[v]);
}

void unionSet(vector<int>& parent, int u, int v) {
    int uParent = findParent(parent, u);
    int vParent = findParent(parent, v);
    parent[uParent] = vParent;
}

vector<Edge> max_spanning_tree(vector<Edge>& edges, int n) {
    vector<int> parent(n + 1);
    for (int i = 1; i <= n; i++)
        parent[i] = i;

    vector<Edge> maxSpanningTree;
    int count = 0;
    int index = 0;

    while (count < n - 1 && index < edges.size()) {
        Edge currentEdge = edges[index];
        int u = currentEdge.u;
        int v = currentEdge.v;
        int uParent = findParent(parent, u);
        int vParent = findParent(parent, v);

        if (uParent != vParent) {
            maxSpanningTree.push_back(currentEdge);
            unionSet(parent, u, v);
            count++;
        }

        index++;
    }

    return maxSpanningTree;
}


vector<Edge> min_spanning_tree(vector<Edge>& edges, int n, int bottle_neck) {
    vector<int> parent(n + 1);
    for (int i = 1; i <= n; i++)
        parent[i] = i;

    vector<Edge> minSpanningTree;
    int count = 0;
    int index = 0;

    while (count < n - 1 && index < edges.size()) {
        if (edges[index].weight < bottle_neck){
            index++;
            continue;
        }
        Edge currentEdge = edges[index];
        int u = currentEdge.u;
        int v = currentEdge.v;
        int uParent = findParent(parent, u);
        int vParent = findParent(parent, v);

        if (uParent != vParent) {
            minSpanningTree.push_back(currentEdge);
            unionSet(parent, u, v);
            count++;
        }
        index++;
    }
    return minSpanningTree;
}


int main() {
    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }

    sort(edges.begin(), edges.end(), descmp);

    // first spanning tree (max), finding bottle neck
    vector<Edge> maxSpanningTree = max_spanning_tree(edges, n);

    // Print the maximum spanning tree
    int bottle_neck = INT_MAX;
    for (const Edge& edge : maxSpanningTree) {
        // cout << edge.u << " " << edge.v << " " << edge.weight << endl;
        bottle_neck = min(bottle_neck, edge.weight);
    }

    // cout << "bottle neck: " << bottle_neck << endl;

    // 2nd spanning tree (min)
    sort(edges.begin(), edges.end(), asccmp);

    // for (auto i: edges){
    //     cout << i.u << " " << i.v << " " << i.weight << endl;
    // }

    vector<Edge> newSpanningTree = min_spanning_tree(edges, n, bottle_neck);
    
    // Print the new minimum spanning tree
    int sum = 0;
    // cout << endl << "Minimum spanning tree:" << endl;
    for (const Edge& edge : newSpanningTree) {
        sum += edge.weight;
        // cout << edge.u << " " << edge.v << " " << edge.weight << endl;
    }
    cout << sum << endl;

    return 0;
}
