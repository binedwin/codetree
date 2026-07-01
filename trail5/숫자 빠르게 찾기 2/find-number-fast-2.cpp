#include <iostream>
#include <set>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    set<int> s;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        s.insert(a);
    }

    for (int i = 0; i < m; i++) {
        int a;
        cin >> a;

        auto it = s.lower_bound(a);

        if (it == s.end()) {
            cout << -1 << "\n";
        }
        else {
            cout << *it << "\n";
        }
    }

    return 0;
}