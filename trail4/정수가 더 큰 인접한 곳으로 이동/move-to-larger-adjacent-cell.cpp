#include <iostream>

using namespace std;

int n;
int r, c;
int board[105][105];

// 상 하 좌 우
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

int main() {
    cin >> n >> r >> c;

    // 1-index -> 0-index
    r--;
    c--;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    while (true) {

        // 현재 위치 출력
        cout << board[r][c] << " ";

        bool moved = false;

        // 상 -> 하 -> 좌 -> 우 순서
        for (int d = 0; d < 4; d++) {

            int nr = r + dy[d];
            int nc = c + dx[d];

            // 격자 밖이면 무시
            if (nr < 0 || nr >= n || nc < 0 || nc >= n)
                continue;

            // 현재 값보다 크면 바로 이동
            if (board[nr][nc] > board[r][c]) {
                r = nr;
                c = nc;

                moved = true;
                break;
            }
        }

        // 이동 가능한 곳이 없음
        if (!moved)
            break;
    }

    return 0;
}