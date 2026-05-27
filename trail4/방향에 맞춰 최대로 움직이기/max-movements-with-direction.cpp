#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int dy[9] = {0,-1,-1,0,1,1,1,0,-1};
int dx[9] = {0,0,1,1,1,0,-1,-1,-1};

int n, sy, sx;
int arr[10][10];
int dir[10][10];
int answer = 0;

void input() {

    cin >> n;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> arr[i][j];
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> dir[i][j];
        }
    }

    cin >> sy >> sx;

    sy--;
    sx--;
}

void dfs(int y, int x, int cnt) {

    answer = max(answer, cnt);

    int d = dir[y][x];

    int dist = 1;

    while(true) {

        int ny = y + dy[d] * dist;
        int nx = x + dx[d] * dist;

        if(ny < 0 || ny >= n || nx < 0 || nx >= n)
            break;

        // 현재 숫자보다 큰 경우만 이동 가능
        if(arr[ny][nx] > arr[y][x]) {
            dfs(ny, nx, cnt + 1);
        }

        dist++;
    }
}

int main() {

    input();

    dfs(sy, sx, 0);

    cout << answer;

    return 0;
}