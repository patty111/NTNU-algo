// 4-4
/*
    Problem #515 - Hapi Patrol Officers
    maximum flow
*/
#include <chrono>
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <string.h>
#include <queue>
#include <math.h>

using namespace std;

bool fordFulklersonDFS(int* path, int* idx, bool* visited, int** rGraph, int V, int node, int target, int* maxFlow, int delta){
	int i;
	visited[node] = true;
	path[*idx] = node;
	*idx += 1;
	
	if(node == target){
		int bottleneck = INT_MAX;
		for(i = 0; i < *idx - 1; i++)
			bottleneck = min(bottleneck, rGraph[path[i]][path[i + 1]]);
		
		*maxFlow += bottleneck;
		for(i = 0; i < *idx - 1; i++){
			rGraph[path[i]][path[i + 1]] -= bottleneck;
			rGraph[path[i + 1]][path[i]] += bottleneck;
		}
		
		return true;
	}
	else{
		for(i = 0; i < V; i++)
			if(!visited[i] && rGraph[node][i] >= delta)
				if(!fordFulklersonDFS(path, idx, visited, rGraph, V, i, target, maxFlow, delta)){
					visited[i] = false;
					*idx -= 1;
				}
				else
					return true;
				
		return false;
	}
}
int findDelta(int** adj, int V)
{
	int i,j;
	int delta = INT_MIN;
	
	for(i=0;i<V;i++)
		for(j=0;j<V;j++)
			delta = max(delta, adj[i][j]);
	
	int pow = log(delta) / log(2);
	return 1 << pow;
}

int fordFulkerson(int** adj, int V, int start, int target)
{
	int* path = (int*)malloc(sizeof(int) * V);
	int idx = 0;
	
	bool* visited = (bool*)malloc(sizeof(bool) * V);
	memset(visited, false, sizeof(bool) * V);
	
	int maxFlow = 0;
	int delta = findDelta(adj, V);
	
	while(delta != 0)
	{
		while(fordFulklersonDFS(path, &idx, visited, adj, V, start, target, &maxFlow, delta))
		{
			idx = 0;
			memset(visited, false, sizeof(bool) * V);
		}
		delta /= 2;
	}
	return maxFlow;
}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;  // number of police stations
    cin >> n;
    int** G = new int*[n*2+2];
    for (int i=0; i<n*2+2; ++i){
        G[i] = new int[n*2+2];
        for (int j=0; j<n*2+2; ++j)
            G[i][j] = 0;
    }


    for (int i=1; i<=n; ++i){
        int w;
        cin >> w;
        G[0][i] = w;
    }

    int sum = 0;
    for (int i=0; i<n; ++i){
        int w;    
        cin >> w;
        G[n+1+i][2*n+1] = w;
        sum += w;
    }

     
    int count = 0;
    for (int i=0; i<n; ++i){
        int* transfer = new int[n];
        // transfer[i] = G[0][i].second;
        transfer[i] = G[0][i];
        int acc = 0;
        for (int j=0; j<n; ++j){
            int tmp;
            cin >> tmp;

            if (tmp != 0){
                G[i+1][j+n+1] = tmp;
                acc++;
            }
        }
        G[i+1][i+1+n] = G[0][i+1];  
        // G[i+1][i+1+n] = G[0][i+1] - acc;  
    }


    // for (int i=0; i<n*2+2; ++i){
    //     for (int j=0; j<n*2+2; ++j)
    //         cout << G[i][j] << " ";
    //     cout << endl;
    // }
    auto start = chrono::high_resolution_clock::now();   
    cout << sum - fordFulkerson(G, n*2+2, 0, n*2+1) << endl;
    auto end =  chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);

    cout << "Runtime: " << duration.count()/1000 << " milliseconds" << endl;
    return 0;
}