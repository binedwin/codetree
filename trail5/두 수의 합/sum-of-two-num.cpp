#include <iostream>
#include  <unordered_map>
using namespace std;

int main() {
    int n, k;
    cin>>n>>k;
    unordered_map <int, int> u_map;
    int cnt=0;

    for(int i=0; i<n; i++){
        int a;
        cin>>a;

        int target = k-a;

        if(u_map.find(target) != u_map.end()){
            cnt+= u_map[target];
        }
        u_map[a]++;
    }
    cout<<cnt;

    return 0;
}