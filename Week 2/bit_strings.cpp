#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    long long ans = 1;

    long long fact = 1;
    for(int i=0;i<9;i++){
        fact*=10;
    }
    fact += 7;

    for(int i=0;i<n;i++){
        ans = ((ans%fact)*2)%fact;
    }
    cout<<ans;
}
