#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int n;
    cin>> n;
    unordered_set<int> u_s;
    for(int i=0; i<n; i++){
        int a;
        cin >>a;
        u_s.insert(a);
    }
    int cnt=0;
    for(auto a : u_s){
        cnt++;
    }
    cout<<cnt;
    return 0;
}