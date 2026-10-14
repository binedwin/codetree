#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> board(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    int r, c;
    cin >> r >> c;

    // 0-index
    r--;
    c--;

    int power = board[r][c];

    // 폭발 범위
    // 세로
    for (int y = r - power + 1; y <= r + power - 1; y++) {
        if (y >= 0 && y < n)
            board[y][c] = 0;
    }

    // 가로
    for (int x = c - power + 1; x <= c + power - 1; x++) {
        if (x >= 0 && x < n)
            board[r][x] = 0;
    }

    // 중력 적용
    vector<vector<int>> temp(n, vector<int>(n, 0));

    for (int x = 0; x < n; x++) {

        int bottom = n - 1;

        // 아래에서부터 살아있는 숫자만 채움
        for (int y = n - 1; y >= 0; y--) {
            if (board[y][x] != 0) {
                temp[bottom][x] = board[y][x];
                bottom--;
            }
        }
    }

    // 출력
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << temp[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}