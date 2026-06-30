#include <iostream>
#include <map>
using namespace std;

int main() {
    int N;
    cin >> N;

    map<int, int> tm;

    while (N--) {
        string cmd;
        cin >> cmd;

        if (cmd == "add") {
            int k, v;
            cin >> k >> v;
            tm[k] = v;
        }
        else if (cmd == "remove") {
            int k;
            cin >> k;
            tm.erase(k);
        }
        else if (cmd == "find") {
            int k;
            cin >> k;

            if (tm.find(k) != tm.end())
                cout << tm[k] << '\n';
            else
                cout << "None\n";
        }
        else if (cmd == "print_list") {
            if (tm.empty()) {
                cout << "None\n";
            }
            else {
                for (auto it : tm) {
                    cout << it.second << " ";
                }
                cout << '\n';
            }
        }
    }

    return 0;
}