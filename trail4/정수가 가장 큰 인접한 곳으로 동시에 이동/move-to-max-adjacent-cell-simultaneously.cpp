#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct Ball {
    int y, x;
};

int n, m, t;
int board[25][25];

// 상 하 좌 우
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

bool inRange(int y, int x) {
    return 0 <= y && y < n && 0 <= x && x < n;
}

int main() {
    cin >> n >> m >> t;

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            cin >> board[y][x];
        }
    }

    vector<Ball> balls;

    for (int i = 0; i < m; i++) {
        int y, x;
        cin >> y >> x;

        balls.push_back({y - 1, x - 1});
    }

    // T초 진행
    while (t--) {

        int cnt[25][25] = {};

        // 1. 모든 구슬의 다음 위치 계산
        for (Ball ball : balls) {

            int bestValue = INT_MIN;
            int bestY = -1;
            int bestX = -1;

            // 상 -> 하 -> 좌 -> 우
            for (int d = 0; d < 4; d++) {

                int ny = ball.y + dy[d];
                int nx = ball.x + dx[d];

                if (!inRange(ny, nx))
                    continue;

                // 더 큰 값을 발견한 경우만 변경
                // 같은 값이면 먼저 본 방향 유지
                if (board[ny][nx] > bestValue) {
                    bestValue = board[ny][nx];
                    bestY = ny;
                    bestX = nx;
                }
            }

            cnt[bestY][bestX]++;
        }

        // 2. 충돌하지 않은 구슬만 남김
        vector<Ball> nextBalls;

        for (int y = 0; y < n; y++) {
            for (int x = 0; x < n; x++) {

                // 정확히 하나만 온 경우 생존
                if (cnt[y][x] == 1) {
                    nextBalls.push_back({y, x});
                }
            }
        }

        balls = nextBalls;
    }

    cout << balls.size() << '\n';

    return 0;
}