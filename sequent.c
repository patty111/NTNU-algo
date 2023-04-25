#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shuffle(int *arr, int n) {
    for (int idx = 0; idx < n; idx++) {
        int s = rand() % n;
        int tmp = arr[idx];
        arr[idx] = arr[s];
        arr[s] = tmp;
    }
}

int main() {
    int n = 500000;
    int *arr = (int *)malloc(n * sizeof(int));

    shuffle(arr, n);

    printf("1000000 1000000000\n");
    for (int i = 0; i < 500000; i++) {
        printf("%d 500000000\n", i);
    }
    for (int i = 0; i < 500000; i++) {
        printf("500000001 %d\n", i + 500000000);
    }

    free(arr);
    return 0;
}
