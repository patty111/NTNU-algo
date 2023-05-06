/*
    Problem #484 - Speaker Diarization
    # Greedy (better (?))
    # DP
*/

#include <iostream>
#include <algorithm>
#include <vector>
// using c++ is faster
// run *.exe < shf.in to test big cases (mac env)

using namespace std;

struct Segment {
    int start;
    int end;
    int time;
};

bool cmp_func(const Segment& a, const Segment& b) {
    if (a.start != b.start)
        return a.start < b.start;
    else
        return a.end < b.end;
}

// merge and return merged segment time. if op = 1 -> merge, if op = 0 -> don't merge, only count merged segment time
void merge(Segment s, Segment& m_seg) {
    if (m_seg.end <= s.start) {
        m_seg.time += s.time;
        m_seg.end = s.end;
    }
    else if (m_seg.end > s.start && m_seg.end < s.end) {
        m_seg.time += s.time - (m_seg.end - s.start);
        m_seg.end = s.end;
    }
}

int main() {
    // decrease the delay caused by "cin", can save up to 1/3 of time
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, AUD_LEN;
    cin >> n >> AUD_LEN;

    vector<Segment> seg_arr(n);

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

    // initializing dp table

    // 注意範圍，domain 有包含還是無包含。 這邊是start無包含end有包含!! 所以for loop 要用 <=
    if (count == 0){
        cout << 0 << " " << AUD_LEN << endl;
    }
    else{
        vector<int> dp(AUD_LEN + 2, 1);
        sort(seg_arr.begin(), seg_arr.end(), cmp_func);

        for (int i = 0; i<= seg_arr[0].start; i++)
            dp[i] = 0;

        Segment m_seg = seg_arr[0];

        // fill dp table and calculate duration of time without any speaker
        int bias = 0;
        int front = seg_arr[0].end; // record the biggest "end" encountered.

        for (int i = 1; i < n; i++) {
            if (seg_arr[i].end <= front) {
                bias++;
                continue;
            }

            front = max(seg_arr[i].end, front);

            int tmp = dp[seg_arr[i].start] + 1;
            for (int j = (seg_arr[i - 1 - bias].end) + 1; j <= AUD_LEN; j++)
                dp[j] = tmp;

            bias = 0;
            merge(seg_arr[i], m_seg);
        }

        cout << dp[AUD_LEN] << " " << AUD_LEN - m_seg.time << endl;
    }
    return 0;
}
