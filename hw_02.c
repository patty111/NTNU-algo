/*
    Problem 467 Exploration Progress
    hint: store only the difference between adjcent elements in array
    -> [2, 4, 3] -> [0, 2, -1]
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main(){
    int n, m;
    int ans = -1;
    scanf("%d %d", &n, &m);

    int* T = (int*)malloc(sizeof(int) * n);
    int* P = (int*)calloc(n, sizeof(int));

    for (int i=0;i<n;i++) 
        scanf("%d", &T[i]);

    int day = 1;
    while (day <= m) {
        int u, v, k;
        scanf("%d %d %d", &u, &v, &k);

        for (int j=u;j<=v;j++)
            P[j] += k;

        int check = 1;
        for (int i=0;i<n;i++) {
            if (P[i] < T[i]) {
                check = 0;
                break;
            }
        }

        if (check) {
            ans = day;
            break;
        }

        day++;
    }

    printf("%d\n", ans);

    return 0;
}