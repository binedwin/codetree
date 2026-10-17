#include <iostream>
#include <vector>

using namespace std;

int board[4][4];
int resultBoard[4][4];

vector<int> mergeLine(vector<int> v) {
    vector<int> result;

    for (int i = 0; i < v.size(); i++) {
        if (i + 1 < v.size() && v[i] == v[i + 1]) {
            result.push_back(v[i] * 2);
            i++;
        }
        else {
            result.push_back(v[i]);
        }
    }

    return result;
}

int main() {

    // 4x4 고정
    for (int y = 0; y < 4; y++) {
        for (int x = 0; x < 4; x++) {
            cin >> board[y][x];
        }
    }

    char dir;
    cin >> dir;

    // 왼쪽
    if (dir == 'L') {
        for (int y = 0; y < 4; y++) {
            vector<int> v;

            for (int x = 0; x < 4; x++) {
                if (board[y][x] != 0)
                    v.push_back(board[y][x]);
            }

            v = mergeLine(v);

            for (int i = 0; i < v.size(); i++) {
                resultBoard[y][i] = v[i];
            }
        }
    }

    // 오른쪽
    else if (dir == 'R') {
        for (int y = 0; y < 4; y++) {
            vector<int> v;

            for (int x = 3; x >= 0; x--) {
                if (board[y][x] != 0)
                    v.push_back(board[y][x]);
            }

            v = mergeLine(v);

            for (int i = 0; i < v.size(); i++) {
                resultBoard[y][3 - i] = v[i];
            }
        }
    }

    // 위
    else if (dir == 'U') {
        for (int x = 0; x < 4; x++) {
            vector<int> v;

            for (int y = 0; y < 4; y++) {
                if (board[y][x] != 0)
                    v.push_back(board[y][x]);
            }

            v = mergeLine(v);

            for (int i = 0; i < v.size(); i++) {
                resultBoard[i][x] = v[i];
            }
        }
    }

    // 아래
    else if (dir == 'D') {
        for (int x = 0; x < 4; x++) {
            vector<int> v;

            for (int y = 3; y >= 0; y--) {
                if (board[y][x] != 0)
                    v.push_back(board[y][x]);
            }

            v = mergeLine(v);

            for (int i = 0; i < v.size(); i++) {
                resultBoard[3 - i][x] = v[i];
            }
        }
    }

    for (int y = 0; y < 4; y++) {
        for (int x = 0; x < 4; x++) {
            cout << resultBoard[y][x] << " ";
        }
        cout << '\n';
    }

    return 0;
}