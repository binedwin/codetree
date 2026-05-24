#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct value {
    int a;
    int b;
};

bool cmp(value v1, value v2) {

    // 끝점 기준 오름차순
    if(v1.b == v2.b)
        return v1.a < v2.a;

    return v1.b < v2.b;
}

int n;
vector<value> v;

void input() {
    cin >> n;

    for(int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;

        v.push_back({a, b});
    }

    sort(v.begin(), v.end(), cmp);
}

int solve() {

    int cnt = 0;

    // 이전 선택한 선분의 끝
    int last_end = -2147483648;

    for(int i=0; i<n; i++) {

        // 끝점 공유도 겹침
        if(v[i].a > last_end) {

            cnt++;
            last_end = v[i].b;
        }
    }

    return cnt;
}

int main() {

    input();

    cout << solve();

    return 0;
}