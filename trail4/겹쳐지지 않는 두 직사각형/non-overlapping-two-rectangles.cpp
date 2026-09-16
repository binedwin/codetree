#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int n, m;
int board[25][25];
int psum[25][25];

int topMax[25];
int bottomMax[25];
int leftMax[25];
int rightMax[25];

// (y1, x1) ~ (y2, x2) 직사각형 합
int getSum(int y1, int x1, int y2, int x2) {
    return psum[y2][x2]
         - psum[y1 - 1][x2]
         - psum[y2][x1 - 1]
         + psum[y1 - 1][x1 - 1];
}

int main() {

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> board[i][j];

            psum[i][j] =
                psum[i - 1][j]
                + psum[i][j - 1]
                - psum[i - 1][j - 1]
                + board[i][j];
        }
    }

    for (int i = 0; i < 25; i++) {
        topMax[i] = bottomMax[i] = INT_MIN;
        leftMax[i] = rightMax[i] = INT_MIN;
    }

    // 모든 직사각형 탐색
    for (int y1 = 1; y1 <= n; y1++) {
        for (int x1 = 1; x1 <= m; x1++) {

            for (int y2 = y1; y2 <= n; y2++) {
                for (int x2 = x1; x2 <= m; x2++) {

                    int sum = getSum(y1, x1, y2, x2);

                    // 이 직사각형의 아래쪽 끝
                    topMax[y2] = max(topMax[y2], sum);

                    // 위쪽 시작
                    bottomMax[y1] = max(bottomMax[y1], sum);

                    // 오른쪽 끝
                    leftMax[x2] = max(leftMax[x2], sum);

                    // 왼쪽 시작
                    rightMax[x1] = max(rightMax[x1], sum);
                }
            }
        }
    }

    // 1 ~ i 영역에서 가장 큰 직사각형
    for (int i = 2; i <= n; i++)
        topMax[i] = max(topMax[i], topMax[i - 1]);

    for (int i = 2; i <= m; i++)
        leftMax[i] = max(leftMax[i], leftMax[i - 1]);

    // i ~ 끝 영역에서 가장 큰 직사각형
    for (int i = n - 1; i >= 1; i--)
        bottomMax[i] = max(bottomMax[i], bottomMax[i + 1]);

    for (int i = m - 1; i >= 1; i--)
        rightMax[i] = max(rightMax[i], rightMax[i + 1]);

    int answer = INT_MIN;

    // 가로로 자르기
    for (int i = 1; i < n; i++) {
        answer = max(answer,
                     topMax[i] + bottomMax[i + 1]);
    }

    // 세로로 자르기
    for (int i = 1; i < m; i++) {
        answer = max(answer,
                     leftMax[i] + rightMax[i + 1]);
    }

    cout << answer;

    return 0;
}