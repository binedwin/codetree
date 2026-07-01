#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> arr(N);

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    unordered_map<int, int> cnt;
    long long answer = 0;

    for (int j = 0; j < N; j++) {
        for (int i = j + 1; i < N; i++) {
            int target = K - arr[j] - arr[i];

            if (cnt.find(target) != cnt.end()) {
                answer += cnt[target];
            }
        }

        cnt[arr[j]]++;
    }

    cout << answer;

    return 0;
}