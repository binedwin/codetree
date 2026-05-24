#include <iostream>

using namespace std;

int n;
int arr[15];
int answer;

bool check() {
    int idx = 0;

    while (idx < n) {
        int num = arr[idx];

        // 남은 길이가 부족하면 실패
        if (idx + num > n)
            return false;

        // num개가 연속인지 확인
        for (int i = 0; i < num; i++) {
            if (arr[idx + i] != num)
                return false;
        }

        idx += num;
    }

    return true;
}

void dfs(int lev) {

    if (lev == n) {
        if (check())
            answer++;
        return;
    }

    // 문제 조건: 숫자는 1~4
    for (int i = 1; i <= 4; i++) {
        arr[lev] = i;
        dfs(lev + 1);
    }
}

int main() {

    cin >> n;

    dfs(0);

    cout << answer;

    return 0;
}