#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

int* upper_tangent(int polygon1[][2], int polygon2[][2], int len1, int len2){
    int* upper = (int*)malloc(sizeof(int) * 4);
    for (int i=0;i<4;i++)
        upper[i] = INT32_MIN;
    
    for (int i=0;i<len1;i++){
        if (polygon1[i][1] >= upper[1]){
            upper[1] = polygon1[i][1];
            upper[0] = polygon1[i][0];
        }
    }

    for (int i=0;i<len2;i++){
        if (polygon2[i][1] >= upper[3]){
            upper[3] = polygon2[i][1];
            upper[2] = polygon2[i][0];
        }
    }
    return upper;
}


int* lower_tangent(int polygon1[][2], int polygon2[][2], int len1, int len2){
    int* lower = (int*)malloc(sizeof(int) * 4);
    for (int i=0;i<4;i++)
        lower[i] = INT32_MAX;
    
    for (int i=0;i<len1;i++){
        if (polygon1[i][1] <= lower[1]){
            lower[1] = polygon1[i][1];
            lower[0] = polygon1[i][0];
        }
    }

    for (int i=0;i<len2;i++){
        if (polygon2[i][1] <= lower[3]){
            lower[3] = polygon2[i][1];
            lower[2] = polygon2[i][0];
        }
    }
    return lower;
}


int main(){

    int polygon1[5][2] = {{2, 2}, {3, 3}, {5, 2}, {4, 0}, {3, 1}};
    int polygon2[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -2}};


    int* ans = upper_tangent(polygon1, polygon2, 5, 4);

    printf("upper\n1: %d %d\n2: %d %d\n", ans[0], ans[1], ans[2], ans[3]);

    ans = lower_tangent(polygon1, polygon2, 5, 4);
    printf("lower\n1: %d %d\n2: %d %d\n", ans[0], ans[1], ans[2], ans[3]);


    return 0;	
}