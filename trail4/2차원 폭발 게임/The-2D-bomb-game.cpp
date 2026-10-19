#include <iostream>
#include <cstring>

using namespace std;

int n, m, k;
int board[105][105];
int tempBoard[105][105];
bool boom[105][105];


// 중력
void gravity() {
    memset(tempBoard, 0, sizeof(tempBoard));

    for (int col = 0; col < n; col++) {
        int bottom = n - 1;

        for (int row = n - 1; row >= 0; row--) {
            if (board[row][col] != 0) {
                tempBoard[bottom][col] = board[row][col];
                bottom--;
            }
        }
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            board[i][j] = tempBoard[i][j];
}


// 폭발 1회
bool explode() {
    memset(boom, false, sizeof(boom));

    bool isExploded = false;

    for (int col = 0; col < n; col++) {

        int row = 0;

        while (row < n) {

            // 빈칸
            if (board[row][col] == 0) {
                row++;
                continue;
            }

            int start = row;
            int value = board[row][col];

            // 같은 숫자가 어디까지 이어지는지
            while (row < n && board[row][col] == value) {
                row++;
            }

            int cnt = row - start;

            // m개 이상이면 전부 폭발
            if (cnt >= m) {
                isExploded = true;

                for (int r = start; r < row; r++) {
                    boom[r][col] = true;
                }
            }
        }
    }

    // 터질 게 없음
    if (!isExploded)
        return false;

    // 동시에 폭발
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (boom[i][j])
                board[i][j] = 0;
        }
    }

    gravity();

    return true;
}


// 더 이상 못 터질 때까지
void explodeAll() {
    while (explode()) {
    }
}


// 시계방향 90도 회전
void rotateBoard() {
    memset(tempBoard, 0, sizeof(tempBoard));

    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            tempBoard[col][n - 1 - row] = board[row][col];
        }
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            board[i][j] = tempBoard[i][j];

    gravity();
}


int main() {
    cin >> n >> m >> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    // K번 : 폭발 반복 -> 회전
    for (int t = 0; t < k; t++) {
        explodeAll();
        rotateBoard();
    }

    // 마지막 회전 이후에도 폭발해야 함
    explodeAll();

    int answer = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] != 0)
                answer++;
        }
    }

    cout << answer << '\n';

    return 0;
}