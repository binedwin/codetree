#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;

    vector<int> points(N);

    for (int i = 0; i < N; i++) {
        cin >> points[i];
    }

    sort(points.begin(), points.end());

    for (int i = 0; i < Q; i++) {
        int a, b;
        cin >> a >> b;

        int left = lower_bound(points.begin(), points.end(), a) - points.begin();
        int right = upper_bound(points.begin(), points.end(), b) - points.begin();

        cout << right - left << '\n';
    }

    return 0;
}