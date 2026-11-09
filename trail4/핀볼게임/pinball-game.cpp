#include <iostream>
#include <algorithm>

using namespace std;

int n;
int board[105][105];

// 0: 아래, 1: 왼쪽, 2: 위, 3: 오른쪽
int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, -1, 0, 1};

bool inRange(int y, int x) {
    return y >= 0 && y < n && x >= 0 && x < n;
}

// 거울에 부딪혔을 때 방향 변경
int changeDir(int mirror, int dir) {

    // 1 = /
    if (mirror == 1) {
        if (dir == 0) return 1; // 아래 -> 왼쪽
        if (dir == 1) return 0; // 왼쪽 -> 아래
        if (dir == 2) return 3; // 위 -> 오른쪽
        if (dir == 3) return 2; // 오른쪽 -> 위
    }

    // 2 = '\'
    else {
        if (dir == 0) return 3; // 아래 -> 오른쪽
        if (dir == 3) return 0; // 오른쪽 -> 아래
        if (dir == 2) return 1; // 위 -> 왼쪽
        if (dir == 1) return 2; // 왼쪽 -> 위
    }

    return dir;
}

int simulate(int y, int x, int dir) {

    // 격자 안으로 들어오는 시간 1초
    int time = 1;

    // 시작하자마자 거울일 수도 있음
    if (board[y][x] != 0) {
        dir = changeDir(board[y][x], dir);
    }

    while (true) {

        int ny = y + dy[dir];
        int nx = x + dx[dir];

        // 다음 칸이 격자 밖
        if (!inRange(ny, nx)) {
            time++;   // 격자 밖으로 나가는 시간
            break;
        }

        // 한 칸 이동
        y = ny;
        x = nx;
        time++;

        // 거울이면 방향 변경
        if (board[y][x] != 0) {
            dir = changeDir(board[y][x], dir);
        }
    }

    return time;
}

int main() {

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    int answer = 0;

    // 위쪽에서 아래로
    for (int x = 0; x < n; x++) {
        answer = max(answer, simulate(0, x, 0));
    }

    // 오른쪽에서 왼쪽으로
    for (int y = 0; y < n; y++) {
        answer = max(answer, simulate(y, n - 1, 1));
    }

    // 아래쪽에서 위로
    for (int x = 0; x < n; x++) {
        answer = max(answer, simulate(n - 1, x, 2));
    }

    // 왼쪽에서 오른쪽으로
    for (int y = 0; y < n; y++) {
        answer = max(answer, simulate(y, 0, 3));
    }

    cout << answer << '\n';

    return 0;
}