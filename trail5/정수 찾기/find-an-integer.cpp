#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    int n,m;
    cin>>n;
    unordered_set<int> u_s;

    for(int i=0; i<n; i++){
        int a;
        cin>>a;
        u_s.insert(a);
    }
    
    cin>>m;

    for(int i=0; i<m; i++){
        int a;
        cin>>a;
        if(u_s.find(a) != u_s.end()){
            cout<<1<<"\n";
        }
        else{
            cout<<0<<"\n";
        }
    }
    return 0;
}