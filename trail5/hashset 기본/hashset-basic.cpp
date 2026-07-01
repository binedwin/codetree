#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int n;
    cin>>n;
    unordered_set <int> u_s;

    for(int i=0; i<n; i++){
        string a;
        int b;
        cin>> a>>b;

        if(a=="find"){
            if(u_s.find(b) != u_s.end()){
                cout<<"true"<<"\n";
            }
            else{
                cout<<"false" <<"\n";
            }
        }
        else if(a=="add"){
            u_s.insert(b);
        }
        else{
            u_s.erase(b);
        }
    }
    return 0;
}