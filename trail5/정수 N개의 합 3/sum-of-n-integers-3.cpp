#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<vector<int>> prefix(N + 1, vector<int>(N + 1, 0));

    for (int y = 1; y <= N; y++) {
        for (int x = 1; x <= N; x++) {
            int num;
            cin >> num;

            prefix[y][x] = num
                         + prefix[y - 1][x]
                         + prefix[y][x - 1]
                         - prefix[y - 1][x - 1];
        }
    }

    int answer = 0;

    for (int y = K; y <= N; y++) {
        for (int x = K; x <= N; x++) {
            int sum = prefix[y][x]
                    - prefix[y - K][x]
                    - prefix[y][x - K]
                    + prefix[y - K][x - K];

            answer = max(answer, sum);
        }
    }

    cout << answer;

    return 0;
}