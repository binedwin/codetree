#include <iostream>
#include <queue>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    priority_queue<int> pq;

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        pq.push(x);
    }

    while (M--) {
        int x = pq.top();
        pq.pop();

        x--;
        pq.push(x);
    }

    cout << pq.top();

    return 0;
}