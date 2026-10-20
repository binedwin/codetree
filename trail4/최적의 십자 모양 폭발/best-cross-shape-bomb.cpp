#include <iostream>
#include <algorithm>

using namespace std;

int n;
int original[51][51];
int board[51][51];
int temp[51][51];

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};


// 원본 복사
void copyBoard() {
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            board[y][x] = original[y][x];
        }
    }
}


// 십자 폭발
void explode(int y, int x) {

    int power = board[y][x];

    // 중심 포함, 각 방향으로 power - 1칸
    for (int d = 0; d < 4; d++) {
        for (int k = 0; k < power; k++) {

            int ny = y + dy[d] * k;
            int nx = x + dx[d] * k;

            if (ny < 0 || ny >= n || nx < 0 || nx >= n)
                continue;

            board[ny][nx] = 0;
        }
    }
}


// 중력
void gravity() {

    // temp 초기화
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            temp[y][x] = 0;
        }
    }

    for (int x = 0; x < n; x++) {

        int bottom = n - 1;

        // 아래쪽부터 살아있는 숫자를 채움
        for (int y = n - 1; y >= 0; y--) {

            if (board[y][x] != 0) {
                temp[bottom][x] = board[y][x];
                bottom--;
            }
        }
    }

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            board[y][x] = temp[y][x];
        }
    }
}


// 같은 숫자인 인접 쌍 개수
int countPairs() {

    int cnt = 0;

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {

            // 빈칸은 제외
            if (board[y][x] == 0)
                continue;

            // 오른쪽
            if (x + 1 < n &&
                board[y][x] == board[y][x + 1]) {
                cnt++;
            }

            // 아래쪽
            if (y + 1 < n &&
                board[y][x] == board[y + 1][x]) {
                cnt++;
            }
        }
    }

    return cnt;
}


int main() {

    cin >> n;

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            cin >> original[y][x];
        }
    }

    int answer = 0;

    // 모든 칸을 폭발 중심으로 선택
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {

            copyBoard();

            explode(y, x);

            gravity();

            answer = max(answer, countPairs());
        }
    }

    cout << answer << '\n';

    return 0;
}