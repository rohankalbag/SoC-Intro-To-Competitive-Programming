#include <bits/stdc++.h>
using namespace std;

int main(){
    typedef long long ll;
    ll w,h,n;
    cin>>w>>h>>n;
    set<ll>y;
    set<ll>x;
    multiset<ll>y_diff;
    multiset<ll>x_diff;

    y.insert(0);
    x.insert(0);
    x.insert(w);
    y.insert(h);
    x_diff.insert(w);
    y_diff.insert(h);

    for(ll i=0;i<n;i++){
        char a;
        cin>>a;
        ll d;
        cin>>d;
        if(a == 'V'){
            x.insert(d);
            auto it = x.find(d);
            x_diff.erase(x_diff.find(*next(it,1) - *prev(it,1)));
            x_diff.insert(*next(it,1) - *it);
            x_diff.insert(*it - *prev(it,1));
        }
        else{
            y.insert(d);
            auto it = y.find(d);
            y_diff.erase(y_diff.find(*next(it,1) - *prev(it,1)));
            y_diff.insert(*next(it,1) - *it);
            y_diff.insert(*it - *prev(it,1));
        }
        cout<<(*prev(x_diff.end(),1))*(*prev(y_diff.end(),1))<<endl;
    }
}
