#include <iostream>
using namespace std;

int k, n;
int temp[10];

void input(){
    cin>>k >>n;
}

void dfs(int lev){
    if(lev==n){
        if(n>=3){
            for(int i=2; i<n; i++){
                if((temp[i] == temp[i-1]) && (temp[i-1]==temp[i-2])){
                    return;
                }
            }
        }
        for(int i=0; i<n; i++){
            cout<< temp[i]<<" ";
        }
        cout<<"\n";
        return;
    }
    for(int i=1; i<=k; i++){
        temp[lev]=i;
        dfs(lev+1);
    }
}

int main() {
    input();
    dfs(0);
    return 0;
}