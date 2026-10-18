#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<vector<int>> board;

void gravity() {
    vector<vector<int>> temp(n, vector<int>(n, 0));

    for (int x = 0; x < n; x++) {
        int bottom = n - 1;

        for (int y = n - 1; y >= 0; y--) {
            if (board[y][x] != 0) {
                temp[bottom][x] = board[y][x];
                bottom--;
            }
        }
    }

    board = temp;
}

void bomb(int col) {
    col--;  // 0-index

    // 해당 열에서 가장 위에 있는 폭탄 찾기
    int row = -1;

    for (int y = 0; y < n; y++) {
        if (board[y][col] != 0) {
            row = y;
            break;
        }
    }

    // 폭탄이 없으면 아무 일도 안 일어남
    if (row == -1)
        return;

    int power = board[row][col];

    int dy[4] = {-1, 1, 0, 0};
    int dx[4] = {0, 0, -1, 1};

    // 중심
    board[row][col] = 0;

    // 상하좌우 power - 1칸
    for (int d = 0; d < 4; d++) {
        for (int k = 1; k < power; k++) {
            int ny = row + dy[d] * k;
            int nx = col + dx[d] * k;

            if (ny < 0 || ny >= n || nx < 0 || nx >= n)
                break;

            board[ny][nx] = 0;
        }
    }

    gravity();
}

int main() {
    cin >> n >> m;

    board.assign(n, vector<int>(n));

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            cin >> board[y][x];
        }
    }

    for (int i = 0; i < m; i++) {
        int col;
        cin >> col;

        bomb(col);
    }

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            cout << board[y][x] << " ";
        }
        cout << '\n';
    }

    return 0;
}