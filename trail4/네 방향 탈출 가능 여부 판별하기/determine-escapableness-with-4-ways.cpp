#include <iostream>
#include <queue>

using namespace std;

int n, m;
int board[105][105];
bool visited[105][105];

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

int main() {

    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    if(board[0][0] == 0) {
        cout << 0;
        return 0;
    }

    queue<pair<int,int>> q;

    q.push({0, 0});
    visited[0][0] = true;

    while(!q.empty()) {

        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        if(y == n - 1 && x == m - 1) {
            cout << 1;
            return 0;
        }

        for(int i = 0; i < 4; i++) {

            int ny = y + dy[i];
            int nx = x + dx[i];

            if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            if(visited[ny][nx]) continue;
            if(board[ny][nx] == 0) continue;

            visited[ny][nx] = true;
            q.push({ny, nx});
        }
    }

    cout << 0;

    return 0;
}