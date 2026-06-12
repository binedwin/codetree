#include <iostream>

using namespace std;

int n;
int arr[10];
bool visited[10]={false};

void input(){
    cin>>n;
}

void solve(int lev){
    if(lev==n){
        for(int i=0; i<n; i++){
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
        return;
    }

    for(int i=n; i>=1; i--){
        if(visited[i])continue;
        arr[lev]=i;
        visited[i]=true;
        solve(lev+1);
        visited[i]=false;
        arr[lev]=0;
    }
}

int main() {
    input();
    solve(0);

    return 0;
}
