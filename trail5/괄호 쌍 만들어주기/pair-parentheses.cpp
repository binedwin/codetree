#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;

    long long openCnt = 0;
    long long answer = 0;

    for (int i = 0; i < s.size() - 1; i++) {
        if (s[i] == '(' && s[i + 1] == '(') {
            openCnt++;
        }

        if (s[i] == ')' && s[i + 1] == ')') {
            answer += openCnt;
        }
    }

    cout << answer;

    return 0;
}