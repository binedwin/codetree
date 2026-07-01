#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int n, m;
    cin >> n;

    unordered_set<int> s;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        s.insert(x);
    }

    cin >> m;

    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;

        if (s.find(x) != s.end())
            cout << 1 << " ";
        else
            cout << 0 << " ";
    }

    return 0;
}