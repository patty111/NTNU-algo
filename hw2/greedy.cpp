#include <iostream>
#include <stdlib.h>
#include <stack>

using namespace std;

typedef struct segment{
    int start;
    int end;
    int time;
}seg;


int cmp_func(const void* a, const void* b) {
    seg A = (*(seg*)a);
    seg B = (*(seg*)b);

    if (A.end != B.end)
        return A.end - B.end;
    else
        return A.start - B.start;
}

// merge and return merged segment time. if op = 1 -> merge, if op = 0 -> don't merge, only count merged segment time
void merge(seg s, seg m_seg) {
    if (m_seg.end <= s.start) {
        m_seg.time += s.time;
        m_seg.end = s.end;
    }
    else if (m_seg.end > s.start && m_seg.end < s.end) {
        m_seg.time += s.time - (m_seg.end - s.start);
        m_seg.end = s.end;
    }
}


void print_seg_arr(seg* arr, int n){
    cout << "----------------------------------\n";
    for (int i=0; i<n; i++)
        cout << arr[i].start << " " << arr[i].end << endl;
    cout << "----------------------------------\n";
}


int main(){
    // decrease the delay caused by "cin", can save up to 1/3 of time
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);


    int n, AUD_LEN;
    cin >> n >> AUD_LEN;

    // stack<seg> n;
    seg* seg_arr = (seg*)malloc(sizeof(seg) * (n+1));

    int count = 0;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        if ( a == b)
            continue;
        else{
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
        
        print_seg_arr(seg_arr, n);


    }
    
    return 0;
}