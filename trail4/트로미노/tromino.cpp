#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int board[205][205];

// 총 6가지 모양
int shape[6][3][2] = {
    {{0,0}, {0,1}, {0,2}},   // 가로 3칸
    {{0,0}, {1,0}, {2,0}},   // 세로 3칸

    {{0,0}, {1,0}, {0,1}},   // ㄱ
    {{0,0}, {1,0}, {1,1}},
    {{0,0}, {0,1}, {1,1}},
    {{0,1}, {1,0}, {1,1}}
};

int main() {

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    int answer = 0;

    // 모든 시작 위치
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {

            // 6가지 블록
            for (int s = 0; s < 6; s++) {

                int sum = 0;
                bool possible = true;

                for (int k = 0; k < 3; k++) {

                    int ny = y + shape[s][k][0];
                    int nx = x + shape[s][k][1];

                    // 격자 밖
                    if (ny < 0 || nx < 0 || ny >= n || nx >= m) {
                        possible = false;
                        break;
                    }

                    sum += board[ny][nx];
                }

                if (possible) {
                    answer = max(answer, sum);
                }
            }
        }
    }

    cout << answer;

    return 0;
}