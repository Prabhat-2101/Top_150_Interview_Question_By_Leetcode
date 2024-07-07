#include<bits/stdc++.h>
using namespace std;

bool can_jump(vector<int>& nums) {
    int goal = nums.size()-1;
    for(int i=nums.size()-2;i>=0;i--){
        if(i+nums[i]>=goal) goal = i;
    }
    return goal==0;
}

int main(){
    int n;cin>>n;
    vector<int> arr(n);
    
    for(int i=0;i<n;i++) cin>>arr[i];

    bool result = can_jump(arr);

    cout<<result<<endl;

    return 0;
}