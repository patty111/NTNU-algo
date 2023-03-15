#include <stdio.h>
#include <stdlib.h>

void op_1(int* arr, int pos, int val){
    arr[pos-1] = val;
}

void op_2(int* arr, int pos, int arrLen) {
    int* sortedArr = malloc(arrLen * sizeof(int));
    memcpy(sortedArr, arr, arrLen * sizeof(int));
    int index = pos - 1;

    for (int i = 1; i < arrLen; i++) {
        for (int j = i; j > 0 && sortedArr[j] < sortedArr[j - 1]; j--) {
            if (j == index) {
                index--;
                sortedArr[j] = sortedArr[j - 1] + sortedArr[j];
                sortedArr[j - 1] = sortedArr[j] - sortedArr[j - 1];
                sortedArr[j] = sortedArr[j] - sortedArr[j - 1];
            }
            else if (index == j - 1) {
                index++;
                sortedArr[j - 1] = sortedArr[j] + sortedArr[j - 1];
                sortedArr[j] = sortedArr[j - 1] - sortedArr[j];
                sortedArr[j - 1] = sortedArr[j - 1] - sortedArr[j];
            }
            else {
                sortedArr[j - 1] = sortedArr[j - 1] + sortedArr[j];
                sortedArr[j] = sortedArr[j - 1] - sortedArr[j];
                sortedArr[j - 1] = sortedArr[j - 1] - sortedArr[j];
            }
        }
    }
    printf("%d\n", index + 1);
    free(sortedArr);
}


int main(){
    int n, Q;
    int op, pos, val;   // pos uses twice
    scanf("%d %d",&n,&Q);
    int* arr = (int*)malloc(sizeof(int) * n);
    for (int i=0;i<n;i++) scanf("%d",&arr[i]);
    

    // start doing operation
    for (int i=0;i<Q;i++){
        scanf("%d", &op);
        if (op == 1){
            scanf("%d %d",&pos, &val);
            op_1(arr, pos, val);
        }
        else{
            scanf("%d", &pos);
            op_2(arr, pos, n);
        }
    }
    return 0;
}