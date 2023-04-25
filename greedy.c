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
    if (tmpA.start != tmpB.start)
        return tmpA.start - tmpB.start;
    else
        return tmpA.end - tmpB.end;
}

void merge(seg s, seg* m_seg){
    if (m_seg->end <= s.start){
        m_seg->time = m_seg->time + s.time;
        m_seg->end = s.end;
    }
    else if (m_seg->end > s.start && m_seg->end < s.end){
        m_seg->time = m_seg->time + s.time - (m_seg->end - s.start);
        m_seg->end = s.end;
    }
}


int main(){
    int n, AUD_LEN;
    scanf("%d %d", &n, &AUD_LEN);
    seg* seg_arr = (seg*)malloc(sizeof(seg) * (n+1)); 

    for (int i=0;i<n;i++){ 
        scanf("%d %d", &seg_arr[i].start, &seg_arr[i].end); 
        seg_arr[i].time = seg_arr[i].end - seg_arr[i].start; 
    } 

    qsort(seg_arr, n, sizeof(seg), cmp_func); 


    int start = 0, end = 0, res = 0, bias = 0; 
    while (end < AUD_LEN){ 
        while (end < AUD_LEN && bias < n) 
            end = seg_arr[bias++].end;  // Expand end pointer 
        res++; 
        bias--; 
        end++;  // Shift end pointer 
        while (end < AUD_LEN && bias < n) 
            start = seg_arr[bias++].start;  // Expand start pointer 
    } 

    printf("%d %d\n",res , AUD_LEN - seg_arr[bias-1].end); 
    return 0;
}