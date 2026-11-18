#include <iostream>
#include <vector>
using namespace std;

int n, m;

// 각 숫자의 현재 위치
int posY[405];
int posX[405];

vector<vector<vector<int>>> board;

// 8방향
int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

bool inRange(int y, int x) {
    return 0 <= y && y < n && 0 <= x && x < n;
}

void moveNumber(int num) {

    int y = posY[num];
    int x = posX[num];

    int maxNum = -1;
    int nextY = -1;
    int nextX = -1;

    // 주변 8칸에 있는 모든 숫자 중 가장 큰 숫자 찾기
    for (int d = 0; d < 8; d++) {

        int ny = y + dy[d];
        int nx = x + dx[d];

        if (!inRange(ny, nx))
            continue;

        // 해당 칸에 쌓여 있는 모든 숫자 확인
        for (int value : board[ny][nx]) {

            if (value > maxNum) {
                maxNum = value;
                nextY = ny;
                nextX = nx;
            }
        }
    }

    // 주변에 숫자가 하나도 없으면 이동하지 않음
    if (maxNum == -1)
        return;

    // 현재 칸에서 num의 위치 찾기
    int idx = 0;

    while (board[y][x][idx] != num) {
        idx++;
    }

    // num부터 위에 있는 숫자들을 이동
    vector<int> moving;

    for (int i = idx; i < board[y][x].size(); i++) {
        moving.push_back(board[y][x][i]);
    }

    // 원래 위치에서 제거
    board[y][x].erase(
        board[y][x].begin() + idx,
        board[y][x].end()
    );

    // 목적지 위에 순서대로 쌓기
    for (int value : moving) {
        board[nextY][nextX].push_back(value);

        posY[value] = nextY;
        posX[value] = nextX;
    }
}

int main() {

    cin >> n >> m;

    board.resize(
        n,
        vector<vector<int>>(n)
    );

    // 처음에는 각 칸에 숫자 하나씩
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {

            int num;
            cin >> num;

            board[y][x].push_back(num);

            posY[num] = y;
            posX[num] = x;
        }
    }

    // m번 이동
    for (int i = 0; i < m; i++) {

        int num;
        cin >> num;

        moveNumber(num);
    }

    // 각 칸 출력
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {

            if (board[y][x].empty()) {
                cout << "None\n";
                continue;
            }

            // 위에 있는 숫자부터 출력
            for (int i = board[y][x].size() - 1; i >= 0; i--) {
                cout << board[y][x][i] << " ";
            }

            cout << '\n';
        }
    }

    return 0;
}
