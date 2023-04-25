#include <iostream>
#include <algorithm>
#include <vector>

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
    // 可以省1/3的時間
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, AUD_LEN;
    cin >> n >> AUD_LEN;

    vector<Segment> seg_arr(n);

    for (int i = 0; i < n; i++) {
        cin >> seg_arr[i].start >> seg_arr[i].end;
        seg_arr[i].time = seg_arr[i].end - seg_arr[i].start;
    }

    sort(seg_arr.begin(), seg_arr.end(), cmp_func);

    // 排除第一個是 start == end的狀況 e.g. 0 0 or 1 1 or 2 2...
    int start_idx = 0;
    for (int i = 0; i < n; i++) {
        if (seg_arr[i].time == 0 && n != 1)
            start_idx++;
        else
            break;
    }

    // initializing dp table
    vector<int> dp(AUD_LEN + 10);

    // 注意範圍，domain 有包含還是無包含。 這邊是start無包含end有包含!!所以for loop 要用 <=
    for (int i = seg_arr[start_idx].start + 1; i <= AUD_LEN; i++)
        dp[i] = 1;

    Segment m_seg = seg_arr[start_idx];

    // fill dp table and calculate duration of time without any speaker
    int bias = 0;
    int front = seg_arr[start_idx].end; // record the biggest "end" encountered.

    for (int i = 1; i < n; i++) {
        // ||後面是為了排除 start == end的狀況 e.g. 0 0 or 1 1 or 2 2...
        if (seg_arr[i].end <= front || seg_arr[i].start == seg_arr[i].end) {
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
    return 0;
}
