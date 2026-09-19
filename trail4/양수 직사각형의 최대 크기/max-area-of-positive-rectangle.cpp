#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int arr[20][20];

bool isPositive(int y1, int x1, int y2, int x2) {

    for (int y = y1; y <= y2; y++) {
        for (int x = x1; x <= x2; x++) {

            // 0 또는 음수가 하나라도 있으면 실패
            if (arr[y][x] <= 0)
                return false;
        }
    }

    return true;
}

int main() {

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    int answer = -1;

    // 왼쪽 위 (y1, x1)
    for (int y1 = 0; y1 < n; y1++) {
        for (int x1 = 0; x1 < m; x1++) {

            // 오른쪽 아래 (y2, x2)
            for (int y2 = y1; y2 < n; y2++) {
                for (int x2 = x1; x2 < m; x2++) {

                    if (isPositive(y1, x1, y2, x2)) {

                        int size =
                            (y2 - y1 + 1) *
                            (x2 - x1 + 1);

                        answer = max(answer, size);
                    }
                }
            }
        }
    }

    cout << answer;

    return 0;
}