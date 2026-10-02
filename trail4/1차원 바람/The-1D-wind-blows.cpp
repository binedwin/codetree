#include <iostream>

using namespace std;

int n, m, q;
int arr[105][105];

// 같은 열에 같은 숫자가 있는지 확인
bool canPropagate(int r1, int r2) {
    for (int c = 0; c < m; c++) {
        if (arr[r1][c] == arr[r2][c])
            return true;
    }

    return false;
}

// 한 행 shift
void shiftRow(int row, char dir) {

    // L 바람 = 왼쪽에서 불어옴 = 오른쪽으로 밀림
    if (dir == 'L') {

        int temp = arr[row][m - 1];

        for (int c = m - 1; c >= 1; c--) {
            arr[row][c] = arr[row][c - 1];
        }

        arr[row][0] = temp;
    }

    // R 바람 = 오른쪽에서 불어옴 = 왼쪽으로 밀림
    else {

        int temp = arr[row][0];

        for (int c = 0; c < m - 1; c++) {
            arr[row][c] = arr[row][c + 1];
        }

        arr[row][m - 1] = temp;
    }
}

char opposite(char dir) {
    if (dir == 'L')
        return 'R';

    return 'L';
}

int main() {

    cin >> n >> m >> q;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    while (q--) {

        int row;
        char dir;

        cin >> row >> dir;

        row--;  // 0-index

        // 1. 바람이 직접 부는 행 이동
        shiftRow(row, dir);

        // 2. 위쪽으로 전파
        char upDir = dir;

        for (int r = row - 1; r >= 0; r--) {

            // 현재 밀린 행과 위쪽 행 비교
            if (!canPropagate(r + 1, r))
                break;

            upDir = opposite(upDir);

            shiftRow(r, upDir);
        }

        // 3. 아래쪽으로 전파
        char downDir = dir;

        for (int r = row + 1; r < n; r++) {

            // 현재 밀린 행과 아래쪽 행 비교
            if (!canPropagate(r - 1, r))
                break;

            downDir = opposite(downDir);

            shiftRow(r, downDir);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << arr[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}