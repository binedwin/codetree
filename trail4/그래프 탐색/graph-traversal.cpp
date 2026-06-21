#include <iostream>
#include <vector>

using namespace std;

int n, m;
int answer;
vector<int> arr[1005];
bool visited[1005];

void input(){
    cin >> n >> m;
    answer = 0;

    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;

        arr[a - 1].push_back(b - 1);
        arr[b - 1].push_back(a - 1); // 무방향 그래프라면 필요
    }
}

void dfs(int now){
    visited[now] = true;

    for(int i = 0; i < arr[now].size(); i++){
        int next = arr[now][i];

        if(visited[next]) continue;

        answer++;
        dfs(next);
    }
}

int main() {
    input();

    dfs(0);

    cout << answer;

    return 0;
}