#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int n, m;
string words[100001];
string queries[100000];

int main() {

    cin >> n >> m;

    unordered_map<string, int> um;

    for (int i = 1; i <= n; i++) {
        cin >> words[i];

        // 문자열 → 번호
        um[words[i]] = i;
    }

    for (int i = 0; i < m; i++) {
        cin >> queries[i];
    }

    for (int i = 0; i < m; i++) {

        string q = queries[i];

        // 첫 글자가 숫자라면
        if (q[0] >= '0' && q[0] <= '9') {

            int num = stoi(q);

            // 번호 → 문자열
            cout << words[num] << "\n";
        }
        else {

            // 문자열 → 번호
            cout << um[q] << "\n";
        }
    }

    return 0;
}
