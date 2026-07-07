#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[100005];
int answer = 0;

void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

void solve() {
    int count_arr[100005] = {0};
    int j = 0;

    for (int i = 0; i < n; i++) {
        while (j < n && count_arr[arr[j]] == 0) {
            count_arr[arr[j]]++;
            j++;
        }

        answer = max(answer, j - i);

        count_arr[arr[i]]--;
    }
}

int main() {
    input();
    solve();
    cout << answer;
    return 0;
}