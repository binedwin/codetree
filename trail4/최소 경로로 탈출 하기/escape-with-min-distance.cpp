#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int y, x;
};

int n, m;
int arr[105][105];
int dist[105][105];

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

void bfs(int sy, int sx) {
    queue<Node> q;

    q.push({sy, sx});
    dist[sy][sx] = 0;

    while (!q.empty()) {
        Node now = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = now.y + dy[i];
            int nx = now.x + dx[i];

            if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            if (arr[ny][nx] == 0) continue;
            if (dist[ny][nx] != -1) continue;

            dist[ny][nx] = dist[now.y][now.x] + 1;
            q.push({ny, nx});
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            dist[i][j] = -1;
        }
    }

    bfs(0, 0);

    cout << dist[n - 1][m - 1];

    return 0;
}