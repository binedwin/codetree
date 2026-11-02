#include <iostream>

using namespace std;

int n, m, k;
int board[105][105];

int main() {
    cin >> n >> m >> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    // 0-index
    k--;

    int targetRow = n - 1;

    // 블록이 어느 행에서 멈추는지 찾기
    for (int row = 0; row < n - 1; row++) {

        bool blocked = false;

        // 바로 아래 행에 블록이 하나라도 있는지 확인
        for (int col = k; col < k + m; col++) {
            if (board[row + 1][col] == 1) {
                blocked = true;
                break;
            }
        }

        // 아래에 블록이 있으면 현재 행에서 멈춤
        if (blocked) {
            targetRow = row;
            break;
        }
    }

    // 최종 위치에 블록 놓기
    for (int col = k; col < k + m; col++) {
        board[targetRow][col] = 1;
    }

    // 출력
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << board[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}