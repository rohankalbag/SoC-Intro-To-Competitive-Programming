#include <bits/stdc++.h>
using namespace std;

int missingNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        if(nums[0]!=1)
            return 1;
        if(nums[n-1]!=n+1)
            return n+1;
        for(int i=0;i<n-1;i++){
            if(nums[i+1]-nums[i]!=1){
                return nums[i]+1;
            }
        }
        return -1;
}

int main(){
    int n;
    cin>>n;
    vector<int> numbers;

    for(int i=0;i<n-1;i++){
        int temp;
        cin>>temp;
        numbers.push_back(temp);
    }
    cout<<missingNumber(numbers);
}
