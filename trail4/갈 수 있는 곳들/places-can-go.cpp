#include <iostream>
#include <queue>
using namespace std;

int n,k;
int dashboard[105][105];
bool visited[105][105] ={false};
int dy[4]={-1,1,0,0};
int dx[4] ={0,0,-1,1};
int answer;
queue<pair<int,int>> q;

void input(){
    answer=0;
    cin>>n>>k;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>dashboard[i][j];
        }
    }
    for(int i=0; i<k; i++){
        int a,b;
        cin>>a>>b;
        q.push({a-1,b-1});
        answer++;
        visited[a-1][b-1] = true;
    }
}

void bfs(){
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int ny = y+dy[i];
            int nx = x+dx[i];
            if(ny<0 || ny>=n || nx<0 || nx>=n)continue;
            if(visited[ny][nx])continue;
            if(dashboard[ny][nx]==0){
                
                q.push({ny,nx});
                visited[ny][nx]=true;
                answer++;
            }
        }
    }
}

int main() {
    input();
    bfs();
    cout<<answer;
    return 0;
}