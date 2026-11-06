#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, t, r, c;
    cin >> n >> t >> r >> c;

    r--;
    c--;

    vector<vector<int>> board(n, vector<int>(n, 0));

    board[r][c] = 1;

    int dy[4] = {-1, 1, 0, 0};
    int dx[4] = {0, 0, -1, 1};

    int dist = 1;

    for (int time = 0; time < t; time++) {

        // 현재 상태를 복사
        // 새로 생긴 폭탄이 같은 시간에 또 폭발하는 것을 방지
        vector<vector<int>> next = board;

        for (int y = 0; y < n; y++) {
            for (int x = 0; x < n; x++) {

                if (board[y][x] == 0)
                    continue;

                for (int d = 0; d < 4; d++) {

                    int ny = y + dy[d] * dist;
                    int nx = x + dx[d] * dist;

                    if (ny < 0 || ny >= n || nx < 0 || nx >= n)
                        continue;

                    next[ny][nx] = 1;
                }
            }
        }

        board = next;

        // 다음 폭발 거리는 2배
        dist *= 2;
    }

    int answer = 0;

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            if (board[y][x] == 1)
                answer++;
        }
    }

    cout << answer << '\n';

    return 0;
}