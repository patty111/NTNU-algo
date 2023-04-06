#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#ifdef PROFILER_H
#include "profiler.h"
#endif // !PROFILER_H


#define module 1000000007

int main(){
    int N;
    scanf("%d", &N);

    int* dp = (int*)calloc(N+1, sizeof(int));
    dp[0] = 1;

    int coin = 1;
    for (int i = 0; i <= 31; i++) {
        for (int j = coin; j <= N; j++)
            dp[j] = (dp[j] + dp[j - coin]) % module;
        
        coin = (coin << 1) % module;
    }

    printf("%d\n", dp[N]);
    free(dp);
    return 0;
}
