#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int board[25][25];

int main() {

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    int answer = 0;

    // 중심점
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {

            // k 범위
            // 영역 밖까지 허용되므로 2*n 정도면 충분
            for (int k = 0; k <= 2 * n; k++) {

                int gold = 0;

                // 전체 격자 확인
                for (int ny = 0; ny < n; ny++) {
                    for (int nx = 0; nx < n; nx++) {

                        int dist =
                            abs(y - ny) + abs(x - nx);

                        if (dist <= k && board[ny][nx] == 1) {
                            gold++;
                        }
                    }
                }

                int cost =
                    k * k + (k + 1) * (k + 1);

                // 손해 안 봄
                if (gold * m >= cost) {
                    answer = max(answer, gold);
                }
            }
        }
    }

    cout << answer;

    return 0;
}