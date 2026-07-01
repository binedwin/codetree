#include <iostream>
#include <map>
using namespace std;

int main() {
    map<int,int> m;
    int n;
    cin>>n;
    
    for(int i=0; i<n; i++){
        int a;
        cin>>a;
        if(m.find(a) != m.end()){
            continue;
        }
        m[a]= i+1;
    }
    for(auto x : m){
        cout<< x.first << " "<< x.second<<"\n";
    }

    return 0;
}