#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<string> arr(N + 1);
    unordered_map<string, int> mp;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        mp[arr[i]] = i;
    }

    for (int i = 0; i < M; i++) {
        string query;
        cin >> query;

        // 숫자인 경우
        if (query[0] >= '0' && query[0] <= '9') {
            int num = stoi(query);
            cout << arr[num] << '\n';
        }
        // 문자열인 경우
        else {
            cout << mp[query] << '\n';
        }
    }

    return 0;
}