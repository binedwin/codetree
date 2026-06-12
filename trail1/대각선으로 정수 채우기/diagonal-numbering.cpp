#include <iostream>
using namespace std;

int n, m;
int arr[105][105];

int main() {
    cin >> n >> m;

    int num = 1;

    for (int sum = 0; sum <= n + m - 2; sum++) {
        for (int r = 0; r < n; r++) {
            int c = sum - r;

            if (c >= 0 && c < m) {
                arr[r][c] = num++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}