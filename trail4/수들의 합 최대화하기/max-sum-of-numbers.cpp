#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
int arr[15];
int map[15][15];
bool visited[15]={false};
int answer=0;

void input(){
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>map[i][j];
        }
    }
}

void solve(int lev){
    if(lev==n){
        int cnt=0;
        for(int i=0; i<n; i++){
            cnt+=arr[i];
        }
        answer = max(answer,cnt);
        return;
    }
    for(int i=0; i<n; i++){
        if(visited[i])continue;
        arr[lev]= map[lev][i];
        visited[i]=true;
        solve(lev+1);
        arr[lev]=0;
        visited[i]=false;
    }
}

int main() {
    input();
    solve(0);
    cout<<answer;
    return 0;
}