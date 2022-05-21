#include <bits/stdc++.h>
using namespace std;

long long twoknights(long long n){
    long long x = (n*n*n*n - n*n)/2; // C(n^2,2)
    long long y = 4*(n-1)*(n-2); // (n+1-2)(n+1-3)*2*2
    return x-y;
}

int main(){
    long long n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cout<<twoknights(i)<<endl;
    }
}
