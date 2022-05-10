#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int j=0;j<t;j++){
        map <int,int> counter;
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            int temp;
            cin>>temp;
            if(counter.count(temp)){
                counter[temp] += 1;
            }
            else{
                counter[temp] = 1;
            }
        }
    bool found = false;
    for(auto x: counter){
        if(x.second>=3){
            found = true;
            cout << x.first << endl;
            break;
        }
    }
    if(!found){
        cout<<-1<<endl;
    }
    }
}
