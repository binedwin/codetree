#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> v;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;

        v.push_back({a, 1});      // 구간 시작
        v.push_back({b + 1, -1}); // 구간 끝난 다음
    }

    sort(v.begin(), v.end());

    int cnt = 0;
    int answer = 0;

    for (int i = 0; i < v.size(); i++) {
        cnt += v[i].second;
        answer = max(answer, cnt);
    }

    cout << answer;

    return 0;
}