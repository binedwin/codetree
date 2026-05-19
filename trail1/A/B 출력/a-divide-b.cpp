#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    int n, m;
    cin>>n>>m;
    int share = n/m;
    int remain = n%m;

    cout<<share <<".";

    for(int i=0; i<20; i++){
        int answer = remain * 10;
        cout<< answer / m;
        remain = answer%m;
    }
    return 0;
}