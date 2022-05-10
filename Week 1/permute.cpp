#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        deque<int> arr;
        int x;
        cin>>x;
        arr.push_back(x);
        for(int i=1;i<n;i++){
            cin>>x;
            if(x <= arr.front()){
                arr.push_front(x);
            }
            else{
                arr.push_back(x);
            }
        }

        for(auto it = arr.begin(); it!=arr.end();it++){
            cout<<*it<<" ";
        }
        cout<<endl;
    }
}
