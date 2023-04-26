/*
    Problem #482 - BST
    Dynamic Programming
    Binary Search Tree
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    scanf("%d", &n);
    int* nodes = (int*)malloc(sizeof(int) * n);

    for(int i=0; i<n; i++)
        scanf("%d", &nodes[i]);
    
    int** dp = (int**)malloc(sizeof(int*) * n);
    for (int i=0; i<n; i++){
        dp[i] = (int*)malloc(sizeof(int) * n);
        dp[i][i] = nodes[i];
    }

    for (int i=1; i<n-1; i++){
        int* using_array = (int*)malloc(sizeof(int) * (n-i));

        for (int j=0; j<n-i; j++){

            int sumR = nodes[0];
            int sumL = 0;
            for (int k=0; k<i; k++){
                
            }

            dp[j][j+i] = ;
            // printf("%d %d\n", j, j+i);
            
        }
        printf("\n");
    }

    // 記得處理 0, 6

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            printf("%2d ", dp[i][j]);
        }
        printf("\n");
    }


    return 0;	
}