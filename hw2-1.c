#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
int main(){
    int n;
    scanf("%d", &n);
    int* dp = (int*)malloc(sizeof(int) * n);

    dp[0] = 1;
    for (int i=0;i<log2(n);i++){
        int bills = pow(2, i);
        for (int j=bills; j<=n; j++)
            dp[j] = dp[j-bills];
    }

    printf("%d\n", dp[n]);




    return 0;	
}