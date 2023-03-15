#include <stdio.h>
#include <stdlib.h>

typedef struct{
  int my_array[100000];
} Array_by_val;

void op_1(int* arr, int pos, int val){
    arr[pos-1] = val;
}

void op_2(Array_by_val arr, int pos, int arrLen) {

    int index = pos - 1;

    for (int i = 1; i < arrLen; i++) {
        for (int j = i; j > 0 && arr.my_array[j] < arr.my_array[j - 1]; j--) {
            if (j == index) {
                index--;
                arr.my_array[j] = arr.my_array[j - 1] + arr.my_array[j];
                arr.my_array[j - 1] = arr.my_array[j] - arr.my_array[j - 1];
                arr.my_array[j] = arr.my_array[j] - arr.my_array[j - 1];
            }
            else if (index == j - 1) {
                index++;
                arr.my_array[j - 1] = arr.my_array[j] + arr.my_array[j - 1];
                arr.my_array[j] = arr.my_array[j - 1] - arr.my_array[j];
                arr.my_array[j - 1] = arr.my_array[j - 1] - arr.my_array[j];
            }
            else {
                arr.my_array[j - 1] = arr.my_array[j - 1] + arr.my_array[j];
                arr.my_array[j] = arr.my_array[j - 1] - arr.my_array[j];
                arr.my_array[j - 1] = arr.my_array[j - 1] - arr.my_array[j];
            }
        }
    }
    printf("%d\n", index + 1);
}


int main(){
    int n, Q;
    int op, pos, val;   // pos uses twice
    scanf("%d %d",&n,&Q);
    // int* arr = (int*)malloc(sizeof(int) * n);
    Array_by_val arr;
    for (int i=0;i<n;i++) scanf("%d",&arr.my_array[i]);
    

    // start doing operation
    for (int i=0;i<Q;i++){
        scanf("%d", &op);
        if (op == 1){
            scanf("%d %d",&pos, &val);
            op_1(arr.my_array, pos, val);
        }
        else{
            scanf("%d", &pos);
            op_2(arr, pos, n);
        }
    }
        for (int i=0;i<n;i++) printf("%d ",arr.my_array[i]);

    return 0;
}