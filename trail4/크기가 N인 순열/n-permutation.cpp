#include <iostream>
using namespace std;

int n;
int answer[100];
int visited[100];

void input(){
    cin>>n;
}

void solve(int lev){
    if(lev== n){
        for(int i=0; i<n; i++){
            cout<< answer[i]<<" ";
        }
        cout << "\n";
        return;
    }

    for(int i=1; i<=n; i++){
        if(visited[i]==1)continue;
        answer[lev]=i;
        visited[i]=1;
        solve(lev+1);
        answer[lev]=0;
        visited[i]=0;
    }
}

int main() {
    input();
    solve(0);
    return 0;
}