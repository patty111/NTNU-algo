/*
    Problem 467 - Exploration Progress
    hint: store only the difference between adjacent elements in array
    e.g. [2, 4, 3] -> [0, 2, -1]
    O(nm)
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main(){
    int n, m;
    int ans = -1;
    scanf("%d %d", &n, &m);

    int* T = (int*)malloc(sizeof(int) * n);
    int* diff = (int*)calloc(n, sizeof(int));

    for (int i=0;i<n;i++) 
        scanf("%d", &T[i]);

    int day = 1;
    while (day <= m) {
        int u, v, k;
        scanf("%d %d %d", &u, &v, &k);

        diff[u] += k;
        if (v+1 < n) 
            diff[v+1] -= k;

        int check = 1;

        if (diff[0] < T[0])
            check = 0;
        else{
            int add = diff[0];
            for (int i=1;i<n;i++){
                add += diff[i];
                if (add < T[i]){
                    check = 0;
                    break;
                }
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
