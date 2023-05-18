/*
    Problem #504 - Corgi-Ball
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void output(vector<int> v){
    for (auto i: v)
        cout << i << " ";
    cout << endl;
}


void refresh(vector<int>& v, int num, int last){
    for (int i=num; i<v.size(); ++i){
        v[i] = last+1;
    }
}



int main(){
    int n, m;
    cin >> n >> m;
    vector <int> shots(n);
    vector <int> result(n, 0);
    for (int i=0; i<m; ++i)
        cin >> shots[i];
    
    for (int i=0; i<shots[0]; ++i)
        result[i] = 1;

    int last = shots[0];
    for (int i=1; i<shots.size(); ++i){
        if (shots[i] > last){

        }
    }
    
    output(result);



    return 0;
}
// 先建圖
// Dfs and BFS 附近但不是這兩個 -> topological sort
// 