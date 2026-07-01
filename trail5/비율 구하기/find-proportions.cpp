#include <iostream>
#include <string>
#include <map>
#include <iomanip>
using namespace std;

int main() {
    int n;
    cin >> n;

    map<string, int> mp;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        mp[s]++;
    }

    cout << fixed << setprecision(4);

    for (auto x : mp) {
        cout << x.first << " "
             << (double)x.second * 100 / n
             << "\n";
    }

    return 0;
}