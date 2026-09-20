#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, t;
    cin >> n >> t;

    vector<int> belt(2 * n);

    for (int i = 0; i < 2 * n; i++) {
        cin >> belt[i];
    }

    t %= (2 * n);

    while (t--) {
        int last = belt[2 * n - 1];

        for (int i = 2 * n - 1; i > 0; i--) {
            belt[i] = belt[i - 1];
        }

        belt[0] = last;
    }

    // 위쪽
    for (int i = 0; i < n; i++) {
        cout << belt[i] << " ";
    }
    cout << '\n';

    // 아래쪽
    for (int i = n; i < 2 * n; i++) {
        cout << belt[i] << " ";
    }

    return 0;
}