#include <iostream>
#include <vector>

using namespace std;

int n, m, q;
int board[105][105];

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};


// 직사각형 테두리를 시계 방향으로 1칸 회전
void rotate(int r1, int c1, int r2, int c2) {

    // 왼쪽 위 값 저장
    int temp = board[r1][c1];

    // 왼쪽 변 : 아래 값을 위로
    for (int r = r1; r < r2; r++) {
        board[r][c1] = board[r + 1][c1];
    }

    // 아래쪽 변 : 오른쪽 값을 왼쪽으로
    for (int c = c1; c < c2; c++) {
        board[r2][c] = board[r2][c + 1];
    }

    // 오른쪽 변 : 위 값을 아래로
    for (int r = r2; r > r1; r--) {
        board[r][c2] = board[r - 1][c2];
    }

    // 위쪽 변 : 왼쪽 값을 오른쪽으로
    for (int c = c2; c > c1 + 1; c--) {
        board[r1][c] = board[r1][c - 1];
    }

    board[r1][c1 + 1] = temp;
}


// 직사각형 내부 평균 계산
void average(int r1, int c1, int r2, int c2) {

    // 동시에 변경해야 하므로 원본 복사
    int temp[105][105];

    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            temp[r][c] = board[r][c];
        }
    }

    for (int r = r1; r <= r2; r++) {
        for (int c = c1; c <= c2; c++) {

            int sum = temp[r][c];
            int cnt = 1;

            for (int d = 0; d < 4; d++) {

                int nr = r + dy[d];
                int nc = c + dx[d];

                if (nr < 0 || nr >= n || nc < 0 || nc >= m)
                    continue;

                sum += temp[nr][nc];
                cnt++;
            }

            board[r][c] = sum / cnt;
        }
    }
}


int main() {

    cin >> n >> m >> q;

    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            cin >> board[r][c];
        }
    }

    while (q--) {

        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;

        // 문제는 1-index
        r1--;
        c1--;
        r2--;
        c2--;

        rotate(r1, c1, r2, c2);
        average(r1, c1, r2, c2);
    }

    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            cout << board[r][c] << " ";
        }
        cout << '\n';
    }

    return 0;
}