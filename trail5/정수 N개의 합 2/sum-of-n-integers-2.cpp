#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    int arr[100005];

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int sum = 0;

    // 처음 K개 합
    for (int i = 0; i < K; i++) {
        sum += arr[i];
    }

    int answer = sum;

    // 창을 한 칸씩 오른쪽으로 이동
    for (int i = K; i < N; i++) {
        sum -= arr[i - K]; // 왼쪽 끝 제거
        sum += arr[i];     // 오른쪽 새 원소 추가

        answer = max(answer, sum);
    }

    cout << answer;

    return 0;
}