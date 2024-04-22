/*
    Problem #485 - More Flight Planning

    dp 的方法，老師有說，但有更快的方法
*/
#include <algorithm>
#include <iostream>
#include <vector>

#define VI vector<int>
#define VVI vector<VI>
#define MAXNUM 1000005

using namespace std;

int LIS(VI& arr) {
    int len = arr.size();
    int ldx = 1, pos;
    VI tmp(len, 0);

    if (len == 0) return 0;
    tmp[0] = arr[0];
    for (int ndx = 1; ndx < len; ndx++) {
        int left = 0, right = ldx, mid;
        while (left < right) {
            mid = (left + right) / 2;
            if (tmp[mid] < arr[ndx])
                left = mid + 1;
            else
                right = mid;
        }
        if (tmp[left] < arr[ndx])
            tmp[left + 1] = arr[ndx], ldx++;
        else
            tmp[left] = arr[ndx];
    }
    return ldx;
}

int main(void) {
    int airport, lines;
    int depNum, arrNum;  // Amount of the Departure & Arrival Airport
    VVI depPos(MAXNUM);  // The list of the Department Airport (In Airport Location)
    VI flyList;          // The list of flight from 0 to n in Arrival that fly from the DepPos
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    cin >> depNum >> arrNum;
    for (int idx = 0; idx < arrNum; idx++) {
        cin >> airport;
        depPos[airport].push_back(idx);
    }
    for (int idx = 0; idx < depNum; idx++) {
        cin >> airport;
        for (int idx = depPos[airport].size() - 1; idx >= 0; idx--)
            flyList.push_back(depPos[airport][idx]);
    }

    for (int idx = 0; idx < arrNum; idx++)
        for (int jdx = 0; jdx < depPos[idx].size(); jdx++)
            cout << depPos[idx][jdx] << ' ';
    cout << endl;

    for (int idx = 0; idx < arrNum; idx++)
        cout << flyList[idx] << ' ';
    cout << endl;

    lines = LIS(flyList);
    cout << lines << endl;
    return 0;
}