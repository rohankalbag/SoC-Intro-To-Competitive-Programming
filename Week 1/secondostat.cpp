#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    set<int> s;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        s.insert(temp);
    }
    if(s.size()>=2){
        cout<<*(++s.begin());
    }
    else{
        cout<<"NO";
    }
}
