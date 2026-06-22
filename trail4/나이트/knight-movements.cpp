#include <iostream>
#include <queue>

using namespace std;

int n;
int dist[105][105];

int dy[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dx[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

int sy, sx, ty, tx;

struct Edge {
    int y, x;
};

void input() {
    cin >> n;
    cin >> sy >> sx >> ty >> tx;

    sy--;
    sx--;
    ty--;
    tx--;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dist[i][j] = -1;
        }
    }
}

void bfs(int y, int x) {
    queue<Edge> q;

    q.push({y, x});
    dist[y][x] = 0;

    while (!q.empty()) {
        Edge now = q.front();
        q.pop();

        for (int i = 0; i < 8; i++) {
            int ny = now.y + dy[i];
            int nx = now.x + dx[i];

            if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
            if (dist[ny][nx] != -1) continue;

            dist[ny][nx] = dist[now.y][now.x] + 1;
            q.push({ny, nx});
        }
    }
}

int main() {
    input();
    bfs(sy, sx);

    cout << dist[ty][tx];

    return 0;
}