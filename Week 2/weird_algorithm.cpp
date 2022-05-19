#include <bits/stdc++.h>
using namespace std;

void weird(long long n){
    while(n!=1){
        if(n%2==0){
            cout<<n<<" ";
            n/=2;
        }
        else{
            cout<<n<<" ";
            n = 3*n+1;
        }
    }
    cout<<1;
}

int main(){
    long long n;
    cin>>n;
    weird(n);
}
