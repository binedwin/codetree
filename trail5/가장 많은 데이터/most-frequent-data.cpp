#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    cin>>n;
    unordered_map <string, int> u_m;
    int max_cnt=0;
    string max_u;

    for(int i=0; i<n; i++){
        string a;
        cin>>a;
        u_m[a]++;
        if(u_m[a]>max_cnt){
            max_u = a;
            max_cnt= u_m[a];
        }
    }
    cout<<u_m[max_u];

    return 0;
}