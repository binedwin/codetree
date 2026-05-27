#include <iostream>
using namespace std;

int n, m;
int arr[15];

void dfs(int lev, int start) {
    if (lev == m) {
        for (int i = 0; i < m; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = start; i <= n; i++) {
        arr[lev] = i;
        dfs(lev + 1, i + 1);
    }
}

int main() {
    cin >> n >> m;

    dfs(0, 1);

    return 0;
}