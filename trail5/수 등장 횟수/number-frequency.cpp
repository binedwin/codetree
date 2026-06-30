#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    unordered_map<int, int> cnt;

    // 수열 입력
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }

    // 질의 처리
    for (int i = 0; i < M; i++) {
        int x;
        cin >> x;
        cout << cnt[x] << " ";
    }

    return 0;
}