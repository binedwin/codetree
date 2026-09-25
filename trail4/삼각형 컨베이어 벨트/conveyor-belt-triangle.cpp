#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, t;
    cin >> n >> t;

    vector<int> belt(3 * n);

    // 3줄 입력
    for (int i = 0; i < 3 * n; i++) {
        cin >> belt[i];
    }

    // 불필요한 회전 제거
    t %= (3 * n);

    while (t--) {

        int last = belt[3 * n - 1];

        // 오른쪽으로 한 칸씩 이동
        for (int i = 3 * n - 1; i > 0; i--) {
            belt[i] = belt[i - 1];
        }

        belt[0] = last;
    }

    // 3줄 출력
    for (int i = 0; i < 3 * n; i++) {

        cout << belt[i] << " ";

        if ((i + 1) % n == 0)
            cout << '\n';
    }

    return 0;
}