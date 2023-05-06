/*
    Problem #482 - BST
    Dynamic Programming
    Binary Search Tree
*/

#include <stdio.h>
#include <iostream>
#include <stdint.h>
#include <limits.h>
using namespace std;

int cmpfunc(const void* a, const void* b){
    return *(int*)a - *(int*)b;
}


int64_t min_path(int* nodes, int64_t** dp, int n, int64_t* sum_array, int start, int end){
    if (start > end)
        return 0;
    
    int64_t left_sum = 0;
    int64_t right_sum = sum_array[end] - sum_array[start];

    int64_t min_path = INT64_MAX;
    for (int64_t i = start; i <= end; i++) {
        int64_t current_path = nodes[i] + max(left_sum, right_sum);

        left_sum = dp[start][i];
        if ((i+2) <= end) 
            right_sum = dp[i+2][end];

        min_path = min(min_path, current_path);
    }
    return min_path;
}


void print_table(long long int** dp, int n){
    printf("-------------------------------------------------------\n");
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            printf("%2d ", dp[i][j]);
        }
        printf("\n");
    }
}


int main(){
    int n;
    scanf("%d", &n);
    int* nodes = new int[n];
    

    int64_t* sum_array = new int64_t[n];
    for(int i=0; i<n; i++){
        cin >> nodes[i];
    }

    qsort(nodes, n, sizeof(int), cmpfunc);


    int64_t** dp = new int64_t*[n];
    for (int i=0; i<n; i++){
        if (i == 0)
            sum_array[0] = nodes[0];
        else
            sum_array[i] = sum_array[i-1] + nodes[i];

        dp[i] = (int64_t*)calloc(n, sizeof(int64_t));
        dp[i][i] = nodes[i];
    }


    for (int i=1; i<n-1; i++){        
        for (int j=0; j<n-i; j++){
            dp[j][j+i] = min_path(nodes, dp, n, sum_array, j, j+i);
        }
    }

    // 記得處理 0, 6
    print_table(dp, n);
    cout << min_path(nodes, dp, n, sum_array, 0, n-1);
    return 0;	
}