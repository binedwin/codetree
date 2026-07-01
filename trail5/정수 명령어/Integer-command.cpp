#include <iostream>
#include <string>
#include <set>
using namespace std;

int main() {
    int tc;
    cin>>tc;
    for(int t=0; t<tc; t++){
        int k;
        cin>>k;
        set<int> s;
        for(int i=0; i<k; i++){
            string a;
            int b;
            cin>>a>>b;
            if(a=="I"){
                s.insert(b);
            }
            else if(a=="D" && !s.empty()){
                if(b==1){
                    s.erase(prev(s.end()));
                }
                else{
                    s.erase(s.begin());
                }
            }
        }
        if(s.empty()){
            cout<<"EMPTY"<<"\n";
        }
        else{
            cout<<*s.rbegin()<<" "<< *s.begin()<<"\n";
        }
    }
    return 0;
}