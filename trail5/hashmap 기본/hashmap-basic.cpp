#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int N;
    cin >> N;

    unordered_map<int, int> hm;

    while (N--) {
        string cmd;
        cin >> cmd;

        if (cmd == "add") {
            int k, v;
            cin >> k >> v;
            hm[k] = v;               // 없으면 추가, 있으면 덮어쓰기
        }
        else if (cmd == "remove") {
            int k;
            cin >> k;
            hm.erase(k);             // 삭제
        }
        else if (cmd == "find") {
            int k;
            cin >> k;

            if (hm.find(k) != hm.end())
                cout << hm[k] << '\n';
            else
                cout << "None\n";
        }
    }

    return 0;
}