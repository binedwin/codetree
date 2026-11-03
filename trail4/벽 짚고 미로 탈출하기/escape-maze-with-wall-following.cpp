#include <iostream>
#include <string>

using namespace std;

int n;
int r, c;
char board[105][105];

// 0: 위, 1: 오른쪽, 2: 아래, 3: 왼쪽
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

bool visited[105][105][4];

bool inRange(int r, int c) {
    return r >= 0 && r < n && c >= 0 && c < n;
}

int main() {

    cin >> n >> r >> c;

    r--;
    c--;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        for (int j = 0; j < n; j++) {
            board[i][j] = s[j];
        }
    }

    // 처음에는 오른쪽
    int dir = 1;

    int cnt = 0;

    while (true) {

        // 같은 위치 + 같은 방향이면 무한 반복
        if (visited[r][c][dir]) {
            cout << -1;
            return 0;
        }

        visited[r][c][dir] = true;

        int nr = r + dr[dir];
        int nc = c + dc[dir];

        // -------------------------
        // Case 1 : 앞이 격자 밖
        // -------------------------
        if (!inRange(nr, nc)) {
            cnt++;
            cout << cnt;
            return 0;
        }

        // -------------------------
        // Step 1 : 앞에 벽
        // 반시계 방향 회전
        // -------------------------
        if (board[nr][nc] == '#') {
            dir = (dir + 3) % 4;
            continue;
        }

        // 여기부터는 앞이 빈 공간임

        // 앞으로 이동했다고 가정한 위치에서
        // 오른쪽 방향 확인
        int rightDir = (dir + 1) % 4;

        int rr = nr + dr[rightDir];
        int rc = nc + dc[rightDir];

        // -------------------------
        // Case 2
        // 앞으로 간 뒤 오른쪽에 벽이 있음
        // → 앞으로만 1칸
        // -------------------------
        if (inRange(rr, rc) && board[rr][rc] == '#') {

            r = nr;
            c = nc;

            cnt++;
        }

        // -------------------------
        // Case 3
        // 오른쪽에 벽이 없음
        // → 앞으로 1칸
        // → 오른쪽 회전
        // → 다시 1칸
        // -------------------------
        else {

            // 먼저 앞으로
            r = nr;
            c = nc;
            cnt++;

            // 시계 방향 90도
            dir = rightDir;

            int nextR = r + dr[dir];
            int nextC = c + dc[dir];

            // 두 번째 이동에서 격자 밖이면 탈출
            if (!inRange(nextR, nextC)) {
                cnt++;

                cout << cnt;
                return 0;
            }

            r = nextR;
            c = nextC;
            cnt++;
        }
    }

    return 0;
}