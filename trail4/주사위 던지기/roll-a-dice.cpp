#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, r, c;
    cin >> n >> m >> r >> c;

    r--;
    c--;

    // 주사위 초기 상태
    int top = 1;
    int bottom = 6;
    int left = 4;
    int right = 3;
    int up = 5;      // 격자 위쪽 방향
    int down = 2;    // 격자 아래쪽 방향

    vector<vector<int>> board(n, vector<int>(n, 0));

    // 처음 놓인 위치
    board[r][c] = bottom;

    for (int i = 0; i < m; i++) {
        char dir;
        cin >> dir;

        int nr = r;
        int nc = c;

        if (dir == 'L') nc--;
        else if (dir == 'R') nc++;
        else if (dir == 'U') nr--;
        else if (dir == 'D') nr++;

        // 격자 밖이면 아무것도 하지 않음
        if (nr < 0 || nr >= n || nc < 0 || nc >= n)
            continue;

        int temp;

        // 왼쪽으로 굴림
        if (dir == 'L') {
            temp = top;

            top = right;
            right = bottom;
            bottom = left;
            left = temp;
        }

        // 오른쪽으로 굴림
        else if (dir == 'R') {
            temp = top;

            top = left;
            left = bottom;
            bottom = right;
            right = temp;
        }

        // 위쪽으로 굴림
        else if (dir == 'U') {
            temp = top;

            top = down;
            down = bottom;
            bottom = up;
            up = temp;
        }

        // 아래쪽으로 굴림
        else if (dir == 'D') {
            temp = top;

            top = up;
            up = bottom;
            bottom = down;
            down = temp;
        }

        r = nr;
        c = nc;

        // 새로운 바닥면 숫자로 덮어쓰기
        board[r][c] = bottom;
    }

    int answer = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            answer += board[i][j];
        }
    }

    cout << answer << '\n';

    return 0;
}