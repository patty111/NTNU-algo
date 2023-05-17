/*
    Problem #503 - Lava
    Flood fill, queue, BFS
*/
// try binary search to cut time
#include <iostream>
#include <vector>
#include <queue>
using namespace std;


typedef struct Point{
    int x, y, time;
}point;

void print_room(char** room, int n, int m){
    cout << "\n";
    for (int i = 1; i < n+1; i++){
        for (int j = 1; j < m+1; j++)
            cout << room[i][j];
        cout << endl;
    }
    cout << "\n";
}


bool has_path(char** room, int n, int m, point bed, point door) {
    bool found = false;
    vector<vector<bool>> visited(n + 2, vector<bool>(m + 2, false));
    queue<point> q;

    q.push(bed);
    visited[bed.x][bed.y] = true;

    while (!q.empty()) {
        point curr = q.front();
        q.pop();

        if (curr.x == door.x && curr.y == door.y)
            return true;

        int dx[] = {0, 0, 1, -1};  // Possible movements: up, right, down, left
        int dy[] = {1, -1, 0, 0};

        for (int i = 0; i < 4; i++) {
            int nx = curr.x + dx[i];
            int ny = curr.y + dy[i];

            if (room[nx][ny] != 'O' && room[nx][ny] != 'L' && !visited[nx][ny]) {
                q.push({nx, ny});
                visited[nx][ny] = true;
            }
        }
    }
    return found;
}



int main(){
    int n, m;
    cin >> n >> m;
    char** room = new char*[n+2];

    int fill = 0; // record how many floor is lava or obstacles

    point bed, door;
    queue<point> lava;

    for (int i = 0; i < (n+2); i++){
        room[i] = new char[m+2];
        for (int j = 0; j < (m+2); j++){
            if (i == 0 || i == n+1 || j == 0 || j == m+1){   // make boundary
                room[i][j] = 'O';
                continue;
            }
            else{
                cin >> room[i][j];
                if (room[i][j] != 'C')
                    fill++;
            }
            point tmp;
            tmp.x = i; tmp.y = j;

            switch (room[i][j]){
                case 'L':
                    tmp.time = 1;
                    lava.push(tmp);
                    break;
                case 'D':
                    door = tmp;
                    break;
                case 'B':
                    bed = tmp;
                    break;
                default:
                    break;
            }
        }
    }

    // flood fill
    int time = 2;
    point next;
    while (!lava.empty() && n*m > fill){
        bool flag = false;

        while (n*m > fill){
            point curr = lava.front();
            lava.pop();

            // Check all adjacent points 下上右左
            int dx[] = {0, 0, 1, -1};
            int dy[] = {1, -1, 0, 0};

            for (int i = 0; i < 4; i++){
                int nx = curr.x + dx[i];
                int ny = curr.y + dy[i];

                // Check is valid
                if (room[nx][ny] == 'C'){
                    room[nx][ny] = 'L';
                    lava.push({nx, ny, time});
                    fill++;
                    
                    if (!flag)
                        next = {nx, ny};
                    flag = true;
                }
            }

            if (next.x == lava.front().x && next.y == lava.front().y){
                time++;
                break;
            }
        }

        if (!has_path(room, n, m, bed, door))
            break;
    }

    int ans = time - 3;
    ans = ans > 0 ? ans : -1;
    cout << ans << endl;
    return 0;
}