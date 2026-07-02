#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int y, x;
};

int dist(Edge a, Edge b) {
    return abs(a.y - b.y) + abs(a.x - b.x);
}

int main() {
    int n;
    cin >> n;

    vector<Edge> v;
    int L[100005];
    int R[100005];

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }

    L[0] = 0;
    for (int i = 1; i < n; i++) {
        L[i] = L[i - 1] + dist(v[i - 1], v[i]);
    }

    R[n - 1] = 0;
    for (int i = n - 2; i >= 0; i--) {
        R[i] = R[i + 1] + dist(v[i], v[i + 1]);
    }

    int answer = 1e9;

    for (int i = 1; i <= n - 2; i++) {
        int total = L[i - 1] + dist(v[i - 1], v[i + 1]) + R[i + 1];
        answer = min(answer, total);
    }

    cout << answer;

    return 0;
}