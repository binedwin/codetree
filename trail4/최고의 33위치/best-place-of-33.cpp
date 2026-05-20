#include <iostream>
#include <algorithm>

using namespace std;

int N;
int grid[20][20];
int answer;

void check(int y, int x){
    int cnt=0;
    for (int i = y; i < y+3; i++) {
        for (int j = x; j < x+3; j++) {
            if(i<0 || j<0 || i>=N || j >=N) return;
            else{
                if(grid[i][j]==1){
                    cnt++;
                }
            }
        }
    }
    answer= max(cnt, answer);
}

int main() {
    cin >> N;
    answer=0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            check(i,j);

        }
    }
    cout<<answer;

    return 0;
}
