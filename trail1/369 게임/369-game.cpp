#include <iostream>
using namespace std;

int main() {
    int n;
    cin>> n;

    for(int i=1 ; i<=n; i++){
        int a, b;
        bool temp = true;
        if(i >9){
            a= i/10;
            b= i%10;
            if((a!=0 && a%3==0) ||(b!=0 && b%3==0) || i %3==0){
                temp=false;
            }
            else{
                temp=true;
            }
        }
        else{
            if(i%3==0){
                temp=false;
            }
            else{
                temp =true;
            }
        }

        if( temp == true){
            cout<<i<<" ";
        }
        else{
            cout<<0<<" ";
        }
    }
    return 0;
}