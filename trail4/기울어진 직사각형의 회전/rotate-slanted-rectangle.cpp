#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> board(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    int r, c, m1, m2, m3, m4, dir;
    cin >> r >> c >> m1 >> m2 >> m3 >> m4 >> dir;

    r--;
    c--;

    vector<vector<int>> temp = board;

    int dy[4];
    int dx[4];
    int moveCnt[4];

    // 반시계 방향
    if (dir == 0) {
        int ddy[4] = {-1, -1, 1, 1};
        int ddx[4] = { 1, -1,-1, 1};
        int cnt[4] = {m1, m2, m3, m4};

        for (int i = 0; i < 4; i++) {
            dy[i] = ddy[i];
            dx[i] = ddx[i];
            moveCnt[i] = cnt[i];
        }
    }

    // 시계 방향
    else {
        int ddy[4] = {-1, -1, 1, 1};
        int ddx[4] = {-1,  1, 1,-1};
        int cnt[4] = {m4, m3, m2, m1};

        for (int i = 0; i < 4; i++) {
            dy[i] = ddy[i];
            dx[i] = ddx[i];
            moveCnt[i] = cnt[i];
        }
    }

    int y = r;
    int x = c;

    // 경계를 따라 값을 한 칸씩 이동
    for (int d = 0; d < 4; d++) {

        for (int k = 0; k < moveCnt[d]; k++) {

            int ny = y + dy[d];
            int nx = x + dx[d];

            temp[ny][nx] = board[y][x];

            y = ny;
            x = nx;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << temp[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}