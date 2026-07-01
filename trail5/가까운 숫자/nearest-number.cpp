#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin>>n;
    set<int> s;
    s.insert(0);
    int answer=1e9;

    for(int i=0; i<n; i++){
        int a;
        cin>>a;
        
        auto it = s.lower_bound(a);

        if(it != s.end()){
            answer = min (answer, abs(*it -a));
        }
        if(it != s.begin()){
            it--;
            answer =min(answer, abs(*it -a));
        }
        s.insert(a);
        cout<<answer<<"\n";
    }
    return 0;
}