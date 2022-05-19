#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    getline(cin, s);
    set<int> counters;
    int curr_count = 1;
    char curr_char = s[0];
    for(int i=1;i<s.size();i++){
        if(s[i]!=curr_char){
            counters.insert(curr_count);
            curr_count=1;
            curr_char = s[i];
        }
        else{
            curr_count += 1;
        }
    }
    counters.insert(curr_count);
    cout<<*prev(counters.end());
}
