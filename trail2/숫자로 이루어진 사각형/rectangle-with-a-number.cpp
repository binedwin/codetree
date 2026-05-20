#include <iostream>

using namespace std;

int N;

void quadrangle(){
    int cnt =1;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if( cnt == 10){
                cnt=1;
            }
            cout<<cnt<<" ";
            cnt++;
        }
        cout<< "\n";
    }
}

int main() {
    cin >> N;
    quadrangle();
    return 0;
}