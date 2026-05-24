#include <iostream>

using namespace std;

int K, N;
int arr[10];

void dfs(int lev){
    if(lev==N){
        for(int i =0; i<N; i++){
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
        return ;
    }
    for(int i=1; i<=K; i++){
        arr[lev]=i;
        dfs(lev+1);
    }
}

int main() {
    cin >> K >> N;

    dfs(0);

    return 0;
}
