#include <bits/stdc++.h>
using namespace std;

int factor(int n, int p){
    int x = 0;
    int f = n/p;
    while(f != 0){
        x += f;
        f /= p;
    }
    return x;
}


int main(){
    int n;
    cin>>n;
    cout<<min(factor(n,5),factor(n,2));
}
