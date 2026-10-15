#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> bombs(n);

    for (int i = 0; i < n; i++) {
        cin >> bombs[i];
    }

    while (true) {
        vector<int> temp;
        bool exploded = false;

        int i = 0;

        while (i < bombs.size()) {

            int j = i;

            // 같은 숫자가 어디까지 연속되는지 확인
            while (j < bombs.size() && bombs[j] == bombs[i]) {
                j++;
            }

            int cnt = j - i;

            // m개 미만이면 살아남음
            if (cnt < m) {
                for (int k = i; k < j; k++) {
                    temp.push_back(bombs[k]);
                }
            }
            else {
                exploded = true;
            }

            i = j;
        }

        bombs = temp;

        // 더 이상 폭발하지 않으면 종료
        if (!exploded)
            break;
    }

    cout << bombs.size() << '\n';

    for (int x : bombs) {
        cout << x << '\n';
    }

    return 0;
}