#include <iostream>
#include <cstring>

using namespace std;

int n;
int arr[10];
bool visited[10];

void input(){
    cin>>n;
    memset(visited,0, sizeof(visited));
}

void dfs(int lev){
    if(lev == n){
        for(int i=0; i<n; i++){
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
        return;
    }

    for(int i=n; i>0; i--){
        if(visited[i])continue;

        visited[i]=true;
        arr[lev]=i;
        dfs(lev+1);
        arr[lev]=0;
        visited[i]=false;

    }
}

int main() {
    input();
    dfs(0);

    return 0;
}