#include <iostream>
#include <set>
using namespace std;

int main() {
    int n,m;
    cin>>n>>m;
    set<int> ball;

    for(int i=0; i<m; i++){
        ball.insert(i+1);
    }

    for(int i=0; i<n; i++){
        int a;
        cin>>a;
        ball.erase(a);
        cout<<*ball.rbegin()<<"\n";
    }

    return 0;
}