/*
    Problem #482 - BST
    Dynamic Programming
    binary Search Tree
*/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int* nums = new int(n);

    for (int i=0; i<n; i++)
        cin >> nums[i];
    
    // declare dp table
    int** dp = new int*[n];
    for (int i=0; i<n; i++)
        dp[i] = new int[n];
    
    for (int i=0; i<n; i++){
        
    }









    return 0;
}