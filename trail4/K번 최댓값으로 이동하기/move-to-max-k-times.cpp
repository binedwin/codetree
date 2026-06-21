#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int n, k;
int board[105][105];
bool visited[105][105];

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

int sy, sx;

bool canGo(int y, int x, int standard) {
    if(y < 0 || y >= n || x < 0 || x >= n) return false;
    if(visited[y][x]) return false;
    if(board[y][x] >= standard) return false;
    return true;
}

bool bfs() {
    memset(visited, false, sizeof(visited));

    int standard = board[sy][sx];

    queue<pair<int, int>> q;
    q.push({sy, sx});
    visited[sy][sx] = true;

    int bestY = -1;
    int bestX = -1;
    int bestValue = -1;

    while(!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        if(!(y == sy && x == sx)) {
            if(board[y][x] > bestValue) {
                bestValue = board[y][x];
                bestY = y;
                bestX = x;
            }
            else if(board[y][x] == bestValue) {
                if(y < bestY || (y == bestY && x < bestX)) {
                    bestY = y;
                    bestX = x;
                }
            }
        }

        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(canGo(ny, nx, standard)) {
                visited[ny][nx] = true;
                q.push({ny, nx});
            }
        }
    }

    if(bestY == -1) return false;

    sy = bestY;
    sx = bestX;
    return true;
}

int main() {
    cin >> n >> k;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    cin >> sy >> sx;
    sy--;
    sx--;

    for(int i = 0; i < k; i++) {
        if(!bfs()) break;
    }

    cout << sy + 1 << " " << sx + 1;

    return 0;
}