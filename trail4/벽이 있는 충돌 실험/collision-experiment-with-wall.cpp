#include <iostream>
#include <vector>

using namespace std;

struct Ball {
    int y, x;
    int dir;
};

// U, D, L, R
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

int opposite(int dir) {
    if (dir == 0) return 1; // U -> D
    if (dir == 1) return 0; // D -> U
    if (dir == 2) return 3; // L -> R
    return 2;               // R -> L
}

int getDir(char c) {
    if (c == 'U') return 0;
    if (c == 'D') return 1;
    if (c == 'L') return 2;
    return 3;
}

int main() {

    int T;
    cin >> T;

    while (T--) {

        int n, m;
        cin >> n >> m;

        vector<Ball> balls;

        for (int i = 0; i < m; i++) {
            int y, x;
            char d;

            cin >> y >> x >> d;

            balls.push_back({
                y - 1,
                x - 1,
                getDir(d)
            });
        }

        // 최대 2N초만 확인하면 충분
        for (int time = 0; time < 2 * n; time++) {

            int cnt[55][55] = {};

            // 1. 모든 구슬 이동
            for (auto &ball : balls) {

                int ny = ball.y + dy[ball.dir];
                int nx = ball.x + dx[ball.dir];

                // 벽에 부딪힘
                if (ny < 0 || ny >= n ||
                    nx < 0 || nx >= n) {

                    // 이동하지 않고 방향만 반대로
                    ball.dir = opposite(ball.dir);
                }
                else {
                    ball.y = ny;
                    ball.x = nx;
                }

                cnt[ball.y][ball.x]++;
            }

            // 2. 충돌한 구슬 제거
            vector<Ball> next;

            for (auto ball : balls) {

                if (cnt[ball.y][ball.x] == 1) {
                    next.push_back(ball);
                }
            }

            balls = next;
        }

        cout << balls.size() << '\n';
    }

    return 0;
}