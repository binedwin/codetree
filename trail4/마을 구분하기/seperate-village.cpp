#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int map[30][30];
bool visited[30][30]={false};
int dy[4]={-1,1,0,0};
int dx[4]={0,0,-1,1};
int cnt;
int vilage;
vector <int> answer;

void input(){
    cin>>n;
    cnt=0;
    vilage=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>map[i][j];
        }
    }
}

void dfs(int y, int x){
    visited[y][x]=true;
    for(int i=0; i<4; i++){
        int ny=y+dy[i];
        int nx=x+dx[i];
        if(ny<0 || ny>=n || nx<0 || nx>=n)continue;
        if(visited[ny][nx])continue;

        if(map[ny][nx]==1){
            cnt++;
            dfs(ny,nx);
        }
    }
}

int main() {
    input();
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(visited[i][j])continue;
            if(map[i][j]==1){
                cnt=1;
                vilage++;
                dfs(i,j);
                answer.push_back(cnt);
            }
        }
    }
    sort(answer.begin(), answer.end());

    cout<<vilage<<"\n";
    for(int i=0; i<answer.size(); i++){
        cout<<answer[i]<<"\n";
    }

    return 0;
}