#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b){
    if(a.second == b.second){
        return a.first> b.first;
    }
    return a.second> b.second;
}

int main() {
    int n,k;
    cin>>n>>k;
    int arr[100005];
    unordered_map <int, int> u_m;
    int max_cnt=0;

    for(int i=0; i<n; i++){
        int a;
        cin>> a;
        u_m[a]++;
    }

    vector <pair<int, int>> v;

    for( auto x : u_m){
        v.push_back(x);
    }

    sort(v.begin(), v.end(), cmp);

    for(int i=0; i<k; i++){
        cout<<v[i].first<<" ";
    }

    
    return 0;
}