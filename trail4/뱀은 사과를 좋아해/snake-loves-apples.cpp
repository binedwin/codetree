#include <iostream>
#include <deque>

using namespace std;

int n, m, k;
bool apple[105][105];
bool snake[105][105];

struct Pos {
    int r, c;
};

int main() {
    cin >> n >> m >> k;

    // 사과 입력
    for (int i = 0; i < m; i++) {
        int r, c;
        cin >> r >> c;

        r--;
        c--;

        apple[r][c] = true;
    }

    deque<Pos> body;

    // 처음 뱀은 (1, 1), 길이 1
    body.push_front({0, 0});
    snake[0][0] = true;

    int time = 0;
    bool gameOver = false;

    for (int cmd = 0; cmd < k; cmd++) {

        char dir;
        int dist;

        cin >> dir >> dist;

        // 이미 게임이 끝났더라도 입력은 필요 없음
        // 온라인 채점에서는 바로 종료 가능
        if (gameOver)
            continue;

        int dr = 0;
        int dc = 0;

        if (dir == 'U') dr = -1;
        else if (dir == 'D') dr = 1;
        else if (dir == 'L') dc = -1;
        else if (dir == 'R') dc = 1;

        // dist칸 이동
        for (int step = 0; step < dist; step++) {

            time++;

            int r = body.front().r;
            int c = body.front().c;

            int nr = r + dr;
            int nc = c + dc;

            // 1. 격자 밖
            if (nr < 0 || nr >= n || nc < 0 || nc >= n) {
                gameOver = true;
                break;
            }

            // 사과가 있는지 먼저 확인
            bool hasApple = apple[nr][nc];

            // 2. 사과가 없다면 꼬리가 먼저 빠짐
            if (!hasApple) {
                Pos tail = body.back();
                body.pop_back();

                snake[tail.r][tail.c] = false;
            }

            // 3. 몸과 충돌
            if (snake[nr][nc]) {
                gameOver = true;
                break;
            }

            // 4. 머리 이동
            body.push_front({nr, nc});
            snake[nr][nc] = true;

            // 5. 사과를 먹음
            if (hasApple) {
                apple[nr][nc] = false;
            }
        }
    }

    cout << time << '\n';

    return 0;
}