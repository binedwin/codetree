#include <iostream>

using namespace std;

int n;
int arr[101];

void removeBlock(int s, int e) {
    int temp[101];
    int idx = 0;

    // s~e 구간을 제외하고 복사
    for (int i = 0; i < n; i++) {
        if (i >= s && i <= e)
            continue;

        temp[idx++] = arr[i];
    }

    // 다시 원본 배열로 복사
    for (int i = 0; i < idx; i++) {
        arr[i] = temp[i];
    }

    // 현재 블록 개수 변경
    n = idx;
}

int main() {

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // 정확히 2번 제거
    for (int t = 0; t < 2; t++) {

        int s, e;
        cin >> s >> e;

        // 입력은 1-index
        removeBlock(s - 1, e - 1);
    }

    cout << n << '\n';

    for (int i = 0; i < n; i++) {
        cout << arr[i] << '\n';
    }

    return 0;
}