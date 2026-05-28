#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int arr[25];
int temp[25];
int answer;

void input() {
    answer = 0;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

void dfs(int lev, int start) {
    if (lev == m) {
        int cnt = temp[0];

        for (int i = 1; i < m; i++) {
            cnt ^= temp[i];
        }

        answer = max(answer, cnt);
        return;
    }

    for (int i = start; i < n; i++) {
        temp[lev] = arr[i];
        dfs(lev + 1, i + 1);
    }
}

int main() {
    input();

    dfs(0, 0);

    cout << answer;

    return 0;
}