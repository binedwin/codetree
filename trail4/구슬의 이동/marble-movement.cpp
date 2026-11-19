#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Ball {
    int id;
    int r, c;
    int dir;
    int v;
    bool alive;
};

int n, m, t, k;

// L, U, R, D
int dr[4] = {0, -1, 0, 1};
int dc[4] = {-1, 0, 1, 0};

bool inRange(int r, int c) {
    return 0 <= r && r < n && 0 <= c && c < n;
}

int getDir(char d) {
    if (d == 'L') return 0;
    if (d == 'U') return 1;
    if (d == 'R') return 2;
    return 3; // D
}

int main() {
    cin >> n >> m >> t >> k;

    vector<Ball> balls;

    for (int i = 1; i <= m; i++) {
        int r, c, v;
        char d;

        cin >> r >> c >> d >> v;

        balls.push_back({
            i,
            r - 1,
            c - 1,
            getDir(d),
            v,
            true
        });
    }

    // t초 진행
    for (int time = 0; time < t; time++) {

        // 1. 모든 살아있는 구슬 이동
        for (auto &ball : balls) {

            if (!ball.alive)
                continue;

            // 속도만큼 이동
            for (int move = 0; move < ball.v; move++) {

                int nr = ball.r + dr[ball.dir];
                int nc = ball.c + dc[ball.dir];

                // 벽이면 즉시 방향 반전
                if (!inRange(nr, nc)) {
                    ball.dir = (ball.dir + 2) % 4;

                    nr = ball.r + dr[ball.dir];
                    nc = ball.c + dc[ball.dir];
                }

                ball.r = nr;
                ball.c = nc;
            }
        }

        // 2. 이동이 모두 끝난 뒤 충돌 확인
        vector<vector<vector<int>>> pos(
            n, vector<vector<int>>(n)
        );

        for (int i = 0; i < balls.size(); i++) {
            if (balls[i].alive) {
                pos[balls[i].r][balls[i].c].push_back(i);
            }
        }

        // 3. 같은 칸에 k개 초과라면 우선순위 높은 k개만 생존
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {

                if (pos[r][c].size() <= k)
                    continue;

                auto &v = pos[r][c];

                sort(v.begin(), v.end(), [&](int a, int b) {

                    // 속도가 큰 구슬 우선
                    if (balls[a].v != balls[b].v)
                        return balls[a].v > balls[b].v;

                        // 속도 같으면 번호가 큰 구슬 우선
                        return balls[a].id > balls[b].id;
                    });

                // k개 이후는 제거
                for (int i = k; i < v.size(); i++) {
                    balls[v[i]].alive = false;
                }
            }
        }
    }

    int answer = 0;

    for (auto &ball : balls) {
        if (ball.alive)
            answer++;
    }

    cout << answer << '\n';

    return 0;
}
