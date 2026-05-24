#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

struct b{
    int y, x, b;
};

int n;
vector<b> v;
int map[25][25];
int temp[25][25];
int answer;

int one_dy[5]={-1,-2,0,1,2};
int one_dx[5]={0,0,0,0,0};
int two_dy[5]= {-1,1,0, 0,0};
int two_dx[5] = {0,0,0,-1,1};
int three_dy[5] = {-1,1,0,-1,1};
int three_dx[5] = {-1,1,0,1,-1};

void input(){
    cin>>n;
    answer=0;
    memset(map, 0, sizeof(map));

    for(int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin>>map[i][j];
            if(map[i][j]==1){
                v.push_back({i, j, 0});
            }
        }
    }
}

void dfs(int lev){

    if(lev == v.size()){
        memset(temp, 0, sizeof(temp));

        for(int i=0; i<v.size(); i++){
            if(v[i].b == 1){
                for(int j=0; j<5; j++){
                    int ny = v[i].y + one_dy[j];
                    int nx = v[i].x + one_dx[j];
                    if(ny>=0 && ny<n && nx>=0 && nx<n){
                        temp[ny][nx] = 1;
                    }
                }
            }
            else if(v[i].b == 2){
                for(int j=0; j<5; j++){
                    int ny = v[i].y + two_dy[j];
                    int nx = v[i].x + two_dx[j];
                    if(ny>=0 && ny<n && nx>=0 && nx<n){
                        temp[ny][nx] = 1;
                    }
                }
            }
            else if(v[i].b == 3){
                for(int j=0; j<5; j++){
                    int ny = v[i].y + three_dy[j];
                    int nx = v[i].x + three_dx[j];
                    if(ny>=0 && ny<n && nx>=0 && nx<n){
                        temp[ny][nx] = 1;
                    }
                }
            }
        }
        int cnt=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(temp[i][j]==1){
                    cnt++;
                }
            }
        }
        answer = max(answer, cnt);
        return;
    }

    for(int i=1; i<=3; i++){
        v[lev].b = i;
        dfs(lev+1);
    }
}

int main() {
    input();

    dfs(0);
    cout<<answer;

    return 0;
}