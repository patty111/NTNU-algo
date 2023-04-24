/*
Problem #483 - Flight Planning

# Longest Increasing Subsequence
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct F{
    int start, end;
}flight;

// helper function for binary search
int binarySearch(int* arr, int left, int right, int x) {
    while (right-left > 1){
        int mid = left + (right-left)/2;
        if (arr[mid] >= x)
            right = mid;
        else
            left = mid;
    }
    return right;
}


int LIS(flight* arr, int len) {
    int* dp = (int*)malloc(len * sizeof(int)); // initialize tails array
    int max_len = 1;
    dp[0] = arr[0].end;

    for (int i=1; i<len; i++){
        if (arr[i].end < dp[0])
            dp[0] = arr[i].end;

        else if (arr[i].end > dp[max_len-1]) {
            dp[max_len] = arr[i].end;
            max_len++;
        }
        else {
            int idx = binarySearch(dp, -1, max_len-1, arr[i].end); // find the index of the smallest element in tails that is greater than or equal to arr[i]
            dp[idx] = arr[i].end; // replace tails[idx] with arr[i]
        }
    }

    free(dp);
    return max_len;
}


int cmpfunc(const void* a, const void* b){
    if (((flight*)a)->start != ((flight*)b)->start)
        return ((flight*)a)->start - ((flight*)b)->start;
    else
        return ((flight*)b)->end - ((flight*)a)->end;
}

int main(){
    int n, m, f;
    scanf("%d %d %d", &n, &m, &f);
    flight* flights = (flight*)malloc(sizeof(flight) * f);

    for (int i=0;i<f;i++){
        scanf("%d %d", &flights[i].start, &flights[i].end);
    }

    qsort(flights, f, sizeof(flight), cmpfunc);
    

    // for (int i=0;i<f;i++){
    //     printf("%d %d\n", flights[i].start, flights[i].end);
    // }
    printf("%d\n", LIS(flights, f));



    return 0;	
}
