#include <iostream>
#include <map>
#include <string>
#include <iomanip>

using namespace std;

int main() {

    int n;
    cin >> n;

    map<string, int> cnt;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        cnt[s]++;
    }

    for (auto x : cnt) {

        double ratio = (double)x.second / n * 100;

        cout << x.first << " "
             << fixed << setprecision(4)
             << ratio << "\n";
    }

    return 0;
}