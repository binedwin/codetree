#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int n,m,k;
int sequence[15];
int number[15];
int answer;

void input(){
    cin>>n>>m>>k;
    answer=0;
    memset(sequence, 0, sizeof(sequence));
    memset(number, 0, sizeof(number));

    for(int i=0; i<n; i++){
        cin>>sequence[i];
    }
}

void dfs(int lev){
    if(lev==n){
        int cnt=0;
        for(int i=0; i<k; i++){
            if(number[i]>=m-1){
                cnt++;
            }
        }
        answer = max(answer, cnt);
        return;
    }

    for(int i=0; i<k; i++){
        number[i]+=sequence[lev];
        dfs(lev+1);
        number[i]-=sequence[lev];
    }
}

int main() {
    input();
    dfs(0);
    cout<<answer;
    return 0;
}

// 말이 m-1이 되면은 골인
// 조합으로 하나씩 더하면 됨