#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int getLength(string s) {
    int len = 0;
    int cnt = 1;

    for (int i = 1; i < s.size(); i++) {

        if (s[i] == s[i - 1]) {
            cnt++;
        }
        else {
            // 문자 1개 + 개수의 자릿수
            len += 1 + to_string(cnt).size();
            cnt = 1;
        }
    }

    // 마지막 묶음
    len += 1 + to_string(cnt).size();

    return len;
}

int main() {

    string s;
    cin >> s;

    int n = s.size();
    int answer = 1e9;

    // 오른쪽으로 k칸 shift
    for (int k = 0; k < n; k++) {

        string shifted;

        if (k == 0) {
            shifted = s;
        }
        else {
            shifted = s.substr(n - k) + s.substr(0, n - k);
        }

        answer = min(answer, getLength(shifted));
    }

    cout << answer;

    return 0;
}