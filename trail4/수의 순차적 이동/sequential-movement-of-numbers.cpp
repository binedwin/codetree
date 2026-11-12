#include <iostream>
#include <algorithm>

using namespace std;

int n, t;
int board[25][25];

// 숫자 num의 현재 위치
int posY[625];
int posX[625];

// 8방향
int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dx[8] = {-1,  0,  1,-1, 1,-1, 0, 1};

bool inRange(int y, int x) {
    return 0 <= y && y < n && 0 <= x && x < n;
}

int main() {
    cin >> n >> t;

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            cin >> board[y][x];

            int num = board[y][x];

            posY[num] = y;
            posX[num] = x;
        }
    }

    // t번의 턴
    while (t--) {

        // 1부터 n*n까지 순서대로 이동
        for (int num = 1; num <= n * n; num++) {

            int y = posY[num];
            int x = posX[num];

            int maxValue = -1;
            int maxY = -1;
            int maxX = -1;

            // 주변 8칸 중 가장 큰 숫자 찾기
            for (int d = 0; d < 8; d++) {

                int ny = y + dy[d];
                int nx = x + dx[d];

                if (!inRange(ny, nx))
                    continue;

                if (board[ny][nx] > maxValue) {
                    maxValue = board[ny][nx];
                    maxY = ny;
                    maxX = nx;
                }
            }

            // 주변 칸이 없는 경우
            if (maxY == -1)
                continue;

            int other = board[maxY][maxX];

            // 두 숫자 위치 교환
            swap(board[y][x], board[maxY][maxX]);

            // 위치 정보도 반드시 갱신
            posY[num] = maxY;
            posX[num] = maxX;

            posY[other] = y;
            posX[other] = x;
        }
    }

    // 출력
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            cout << board[y][x] << " ";
        }
        cout << '\n';
    }

    return 0;
}