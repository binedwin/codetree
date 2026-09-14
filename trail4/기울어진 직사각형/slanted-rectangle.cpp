#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[25][25];

int dy[4] = {-1, -1, 1, 1};
int dx[4] = {1, -1, -1, 1};

int getSum(int y, int x, int a, int b) {

    int sum = 0;

    // 각 방향 이동 횟수
    int len[4] = {a, b, a, b};

    for (int dir = 0; dir < 4; dir++) {

        for (int i = 0; i < len[dir]; i++) {

            y += dy[dir];
            x += dx[dir];

            // 격자 밖
            if (y < 0 || x < 0 || y >= n || x >= n)
                return -1;

            sum += arr[y][x];
        }
    }

    return sum;
}

int main() {

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    int answer = 0;

    // 시작점
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {

            // 두 변의 길이
            for (int a = 1; a < n; a++) {
                for (int b = 1; b < n; b++) {

                    int sum = getSum(y, x, a, b);

                    if (sum != -1)
                        answer = max(answer, sum);
                }
            }
        }
    }

    cout << answer;

    return 0;
}