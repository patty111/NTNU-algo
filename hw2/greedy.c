#include <stdio.h>
#include <stdlib.h>
typedef struct segment{
    int start;
    int end;
    int time;
}seg;


int cmp_func(const void* a, const void* b){
    seg tmpA = *(seg*)a;
    seg tmpB = *(seg*)b;
    if (tmpA.time != tmpB.time)
        return tmpA.time - tmpB.time;
    else
        return tmpA.start - tmpB.start;
}


int main(){
    int n, AUD_LEN;
    scanf("%d %d", &n, &AUD_LEN);
    
    seg* seg_arr = (seg*)malloc(sizeof(seg) * (n+1));

    int count = 0;
    for (int i=0;i<n;i++){
        int a, b;
        scanf("%d %d", &seg_arr[i].start, &seg_arr[i].end);
        if (a != b){
            seg_arr[i].start = a;
            seg_arr[i].end = b;
            seg_arr[i].time = seg_arr[i].end - seg_arr[i].start;
            count++;
        }
    }


    if (count == 0){
        printf("0 %d\n", AUD_LEN);
    }
    else{
        qsort(seg_arr, count, sizeof(seg), cmp_func);

        for (int i=0; i<count; i++)
            printf("%d %d %d\n", seg_arr[i].start, seg_arr[i].end, seg_arr[i].time);

        int left_seg_start = seg_arr[0].start;
        int left_seg_end = seg_arr[0].end;
        int right_seg_start = seg_arr[0].start;
        int right_seg_end = seg_arr[0].end;

        int inner_seg_count = 0;
        int* inner_seg_start = (int*)malloc(sizeof(int) * (count + 1));
        int* inner_seg_end = (int*)malloc(sizeof(int) * (count + 1));

        for (int i=1; i<count; i++){

        }

   
    // printf("%d %d\n",dp[AUD_LEN] , AUD_LEN - m_seg->time);
    }
    
    return 0;
}