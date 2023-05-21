/*
    Problem #504 - Corgi-Ball
    // Topological sort
    
    #1 create adjList: 反向箭頭 in ascending
    ex: 3 7 4 5 9 1 6 8 2 -> 3->7 /->4 ->5->9/ ->1->6->8 /->2
                             ㇗㇘    ㇗-----㇘    ㇗---㇘
    #2 remove horizontal arrows, count remove how many the graph will be a DAG
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int ansCount(int n, vector<vector<int>>& adjList) {
    int count = 0;
    int start = 0;

    for (int curr=1; curr<n; curr++){
        for (auto i: adjList[curr]){
            if (i < start) 
                continue;

            start = curr;
            count++;
            break;
        }
    }
    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adjList(n + 1);

    int prev, curr;
    cin >> prev;
    prev--;

    for (int i=1; i<m; ++i) {
        cin >> curr;
        curr--;

        if (curr > prev)
            adjList[curr].push_back(prev);
        else
            adjList[prev].push_back(curr);
        prev = curr;
    }

    cout << ansCount(n, adjList) + 1 << endl;
    return 0;
}