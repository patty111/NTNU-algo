#include <stdio.h>
#include <stdlib.h>

typedef struct segment {
    int start;
    int end;
    int time;
} seg;

int cmp_func(const void* a, const void* b) {
    seg tmpA = *(seg*)a;
    seg tmpB = *(seg*)b;
    return tmpB.end - tmpA.end;
}

int main() {
    int n, AUD_LEN;
    scanf("%d %d", &n, &AUD_LEN);
    
    seg* seg_arr = (seg*)malloc(sizeof(seg) * n);
    for (int i=0; i<n; i++) {
        scanf("%d %d", &seg_arr[i].start, &seg_arr[i].end);
        seg_arr[i].time = seg_arr[i].end - seg_arr[i].start;
    }

    qsort(seg_arr, n, sizeof(seg), cmp_func);
    
    int last_end = 0;
    int num_speakers = 0;
    for (int i=0; i<n; i++) {
        if (seg_arr[i].start >= last_end) {
            num_speakers++;
            last_end = seg_arr[i].end;
        }
    }

    int total_time = 0;
    for (int i=0; i<n; i++) {
        total_time += seg_arr[i].time;
    }
    int no_speaker_time = AUD_LEN - total_time;

    for (int i=0; i<=n; i++){
        printf("%d %d\n", seg_arr[i].start, seg_arr[i].end);
    }
    printf("%d %d\n", num_speakers, no_speaker_time);
    return 0;
}
