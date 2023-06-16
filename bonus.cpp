/*
    Problem #485 - More Flight Planning

    dp 的方法，老師有說，但有更快的方法
*/
#include <iostream>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    int* arr1 = new int[n];
    int* arr2 = new int[m];
    for (int i=0; i<n; ++i)
        cin >> arr1[i];

    for (int i=0; i<n; ++i)
        cin >> arr2[i];



    return 0;
}