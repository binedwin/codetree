#include <iostream>

using namespace std;

int n, m;
bool answer = false;

int map[105][105];
bool visited[105][105];

int dy[2] = {1, 0}; // 아래, 오른쪽
int dx[2] = {0, 1};

void dfs(int y, int x) {

    if(answer) return;

    if(y == n - 1 && x == m - 1) {
        answer = true;
        return;
    }

    for(int i = 0; i < 2; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
        if(visited[ny][nx]) continue;
        if(map[ny][nx] == 0) continue;

        visited[ny][nx] = true;
        dfs(ny, nx);
    }
}

int main() {

    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }

    if(map[0][0] == 1) {
        visited[0][0] = true;
        dfs(0, 0);
    }

    cout << answer;

    return 0;
}