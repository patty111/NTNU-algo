#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

void op_2(int* arr, int pos, int arrLen) {
    int* sortedArr = malloc(arrLen * sizeof(int));
    memcpy(sortedArr, arr, arrLen * sizeof(int));
    int index = pos-1;

    for (int i = 1; i < arrLen; i++) {
        for (int j = i; j > 0 && sortedArr[j] < sortedArr[j - 1]; j--) {
            // Swap adjacent elements if they are in the wrong order
            if (j == index)
                index = j - 1;
            else if (index == j-1)
                index = j+1;
            
            int temp = sortedArr[j];
            sortedArr[j] = sortedArr[j - 1];
            sortedArr[j - 1] = temp;
        }
    }
    printf("%d\n", index+1);

    free(sortedArr);
}

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        for (int j = i; j > 0 && arr[j] < arr[j - 1]; j--) {
            // Swap adjacent elements if they are in the wrong order
            int temp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = temp;
        }
    }
}


int main(){
    // int a[10] = {2, 4, 5, 1, 8, 9, 10, 7, 6, 3};
    int a[10] = {1, 4, 4, 5, 1, 1, 1, 1, 1, 0};
    // int b[3] = {3,2,2};
    op_2(a, 2, 10);
    // op_2(b, 3, 3);
    for (int i=0;i<10;i++) printf("%d ",a[i]);
    printf("\n");
    insertionSort(a, 10);
    for (int i=0;i<10;i++) printf("%d ",a[i]);








    return 0;
}