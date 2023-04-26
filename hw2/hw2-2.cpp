/*
    Problem #482 - BST
    Dynamic Programming
    Binary Search Tree
*/

#include <stdio.h>
#include <iostream>

using namespace std;

int cmpfunc(const void* a, const void* b){
    return *(int*)a - *(int*)b;
}


int min_path(int* nodes, int** dp, int n, int* sum_array, int start, int end){
    if (start > end)
        return 0;
    
    int left_sum = 0;
    int right_sum = sum_array[end] - sum_array[start];

    int min_path = 2147483647;
    for (int i = start; i <= end; i++) {
        int current_path = nodes[i] + max(left_sum, right_sum);

        left_sum = dp[start][i];
        if ((i+2) <= end) 
            right_sum = dp[i+2][end];

        min_path = min(min_path, current_path);
    }
    return min_path;
}



int main(){
    int n;
    scanf("%d", &n);
    int* nodes = new int[n];
    

    int* sum_array = new int[n];
    for(int i=0; i<n; i++){
        cin >> nodes[i];
    }

    qsort(nodes, n, sizeof(int), cmpfunc);




    int** dp = new int*[n];
    for (int i=0; i<n; i++){
        if (i == 0)
            sum_array[0] = nodes[0];
        else
            sum_array[i] = sum_array[i-1] + nodes[i];

        dp[i] = (int*)calloc(n, sizeof(int));
        dp[i][i] = nodes[i];
    }


    for (int i=1; i<n-1; i++){        
        for (int j=0; j<n-i; j++){
            dp[j][j+i] = min_path(nodes, dp, n, sum_array, j, j+i);
        }
    }

    // 記得處理 0, 6

    // printf("-------------------------------------------------------\n");
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<n; j++){
    //         printf("%2d ", dp[i][j]);
    //     }
    //     printf("\n");
    // }

    cout << min_path(nodes, dp, n, sum_array, 0,n-1);
    return 0;	
}