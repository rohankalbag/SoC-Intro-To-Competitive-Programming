#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    map<int,int> s;
    vector<int> storage;
    stack<int> a;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        a.push(temp);
    }
    while(!a.empty()){
        if(!s.count(a.top())){
            s[a.top()] = 1;
            storage.push_back(a.top());
        }
        a.pop();
    }
    cout<<s.size()<<endl;
    for(auto rit = storage.rbegin(); rit != storage.rend(); rit++)
        cout << *rit << " ";
}
