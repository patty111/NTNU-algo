/*
    Probelm 466 - Insertion Sort
    O(n)
    https://www.geeksforgeeks.org/insertion-sort/
    https://stackoverflow.com/questions/4774456/pass-an-array-to-a-function-by-value
*/

#include <stdio.h>
#include <stdlib.h>

void op_1(int* arr, int pos, int val){
    arr[pos-1] = val;
}

void op_2(int* arr, int pos, int arrLen){
    int count = 0;
    int value = arr[pos - 1];

    for (int i=0;i<arrLen;i++) {
        if (arr[i] < value || (arr[i] == value && i < pos - 1))
            count++;
    }

    printf("%d\n", count + 1);
}



int main(){
    int n, Q;
    int op, pos, val;
    scanf("%d %d",&n,&Q);

    int* arr = (int*)malloc(sizeof(int) * n);
    for (int i=0;i<n;i++) scanf("%d",&arr[i]);

    for (int i=0;i<Q;i++) {
        scanf("%d", &op);
        if (op == 1) {
            scanf("%d %d",&pos, &val);
            op_1(arr, pos, val);
        }

        else{
            scanf("%d", &pos);
            op_2(arr, pos, n);
        }
    }

    free(arr);
    return 0;
}
