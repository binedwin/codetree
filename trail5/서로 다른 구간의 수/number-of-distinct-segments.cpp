#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<pair<int, int>> v;

    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }

    sort(v.begin(), v.end());

    int answer = 1;
    int start = v[0].first;
    int end = v[0].second;

    for (int i = 1; i < N; i++) {
        int a = v[i].first;
        int b = v[i].second;

        if (a <= end) {
            end = max(end, b);
        }
        else {
            answer++;
            start = a;
            end = b;
        }
    }

    cout << answer;

    return 0;
}