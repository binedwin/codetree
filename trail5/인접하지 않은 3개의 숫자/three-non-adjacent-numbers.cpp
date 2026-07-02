#include <iostream>
#include <algorithm>
using namespace std;

int arr[100005];
int dp[100005][4];

int main() {
    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    int INF = -1e9;

    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= 3; j++) {
            dp[i][j] = INF;
        }
    }

    dp[0][0] = 0;

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= 3; j++) {
            // i번째 숫자를 안 고르는 경우
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);

            // i번째 숫자를 고르는 경우
            if (j > 0) {
                if (i == 1) {
                    if (j == 1)
                        dp[i][j] = max(dp[i][j], arr[i]);
                }
                else {
                    dp[i][j] = max(dp[i][j], dp[i - 2][j - 1] + arr[i]);
                }
            }
        }
    }

    cout << dp[N][3];

    return 0;
}