/*
Problem #484 - Speaker Diarization
# Greedy (better)
# DP
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct segment{
    int start;
    int end;
    int time;
}seg;


int cmp_func(const void* a, const void* b){
    seg tmpA = *(seg*)a;
    seg tmpB = *(seg*)b;
    if (tmpA.start != tmpB.start)
        return tmpA.end - tmpB.end;
    else
        return tmpA.start - tmpB.start;
}

// merge and return merged segment time. if op = 1 -> merge, if op = 0 -> don't merge, only count merged segment time
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
    for (int i=0;i<n;i++)
        printf("%d %d\n", seg_arr[i].start, seg_arr[i].end);

    // initialize dp table

    // 排除第一個是 start == end的狀況 e.g. 0 0 or 1 1 or 2 2...
    int start_idx = 0;
    for (int i=0;i<n;i++){
        if (seg_arr[i].time == 0 && n != 1)
            start_idx++;
        else
            break;
    }
    
    int* dp = (int*)calloc((AUD_LEN + 1), sizeof(int));    
        // 注意範圍，domain 有包含還是無包含。 這邊是start無包含end有包含!!所以for loop 要用 <=
    for (int i=seg_arr[start_idx].start + 1;i<=AUD_LEN;i++)
        dp[i] = 1;
    
    seg* m_seg = (seg*)malloc(sizeof(seg));
    m_seg->start = seg_arr[start_idx].start;
    m_seg->end = seg_arr[start_idx].end;
    m_seg->time = seg_arr[start_idx].time;

    // fill dp table and calculate duration of time without any speaker
    int bias = 0;
    int front = seg_arr[start_idx].end; // record the biggest "end" encountered.

    for (int i=1;i<n;i++){
        //  ||後面是為了排除 start == end的狀況 e.g. 0 0 or 1 1 or 2 2...
        if (seg_arr[i].end <= front || seg_arr[i].start == seg_arr[i].end){
            bias++;
            continue;
        }

        front = seg_arr[i].end > front ? seg_arr[i].end : front;
        
        int tmp = dp[seg_arr[i].start] + 1;
        for (int j=(seg_arr[i-1-bias].end) + 1;j<=AUD_LEN;j++)
            dp[j] = tmp;
        
        bias = 0;
        merge(seg_arr[i], m_seg);
    }


    printf("%d %d\n",dp[AUD_LEN] , AUD_LEN - m_seg->time);
    return 0;
}