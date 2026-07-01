#include <iostream>
#include <set>
#include <string>
using namespace std;

int main() {
    int N;
    cin >> N;

    set<int> s;

    while (N--) {
        string cmd;
        cin >> cmd;

        if (cmd == "add") {
            int x;
            cin >> x;
            s.insert(x);
        }
        else if (cmd == "remove") {
            int x;
            cin >> x;
            s.erase(x);
        }
        else if (cmd == "find") {
            int x;
            cin >> x;

            if (s.find(x) != s.end())
                cout << "true\n";
            else
                cout << "false\n";
        }
        else if (cmd == "lower_bound") {
            int x;
            cin >> x;

            auto it = s.lower_bound(x);

            if (it == s.end())
                cout << "None\n";
            else
                cout << *it << '\n';
        }
        else if (cmd == "upper_bound") {
            int x;
            cin >> x;

            auto it = s.upper_bound(x);

            if (it == s.end())
                cout << "None\n";
            else
                cout << *it << '\n';
        }
        else if (cmd == "largest") {
            if (s.empty())
                cout << "None\n";
            else
                cout << *s.rbegin() << '\n';
        }
        else if (cmd == "smallest") {
            if (s.empty())
                cout << "None\n";
            else
                cout << *s.begin() << '\n';
        }
    }

    return 0;
}