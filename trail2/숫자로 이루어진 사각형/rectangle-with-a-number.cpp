#include <iostream>

using namespace std;

int n;

int main() {
    cin >> n;
    int cnt=1;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(cnt==10){
                cnt=1;
            }
            cout<<cnt<<" ";
            cnt++;
        }
        cout<<"\n";
    }

    return 0;
}