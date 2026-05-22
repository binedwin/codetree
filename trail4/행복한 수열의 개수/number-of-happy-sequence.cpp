#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int n,m;
int map[105][105];
int answer;

void input(){
    cin>>n >> m;
    answer =0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>map[i][j];
        }
    }
}

int row_check(int num){
    int cnt= 1;
    int max_cnt =0;
    for(int i =1; i<=n; i++){
        if(map[num][i]== map[num][i-1]){
            cnt++;
        }
        else{
            cnt =1;
        }
        max_cnt = max(cnt , max_cnt);
    }
    if(max_cnt >= m){
        return 1;
    }
    else return 0;
}

int colom_check(int num){
    int cnt= 1;
    int max_cnt =0;
    for(int i =1; i<=n; i++){
        if(map[i][num]== map[i-1][num]){
            cnt++;
        }
        else{
            cnt =1;
        }
        max_cnt = max(cnt , max_cnt);
    }
    if(max_cnt >= m){
        return 1;
    }
    else return 0;
}

int main() {
    input();
    // 행이 똑같은지
    for(int i=0; i<n; i++){
        answer = answer+ colom_check(i) + row_check(i);
    }
    cout <<answer;
    return 0;
}