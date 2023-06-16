/*
    Problem #485 - More Flight Planning
*/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>


using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n), c(m);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < m; i++)
        cin >> c[i];

    sort(a.begin(), a.end());
    sort(c.begin(), c.end());

    int i = 0, j = 0, cnt = 0;
    while (i < n && j < m) {
        if (a[i] == c[j]) {
            cnt++;
            i++;
            j++;
        } 
        else if (a[i] < c[j])
            i++;
        else
            j++;
    }

    cout << round((double)cnt / 2) << endl;

    return 0;
}