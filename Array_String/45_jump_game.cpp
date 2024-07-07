#include<bits/stdc++.h>
using namespace std;

int minimum_jump(vector<int>& nums,int n) {
    vector<int> max_jump_index(n);
    max_jump_index[0] = nums[0];
    for(int i=1;i<n;i++){
        max_jump_index[i] = max(i+nums[i],max_jump_index[i-1]);
    }
    int jump_count = 0;
    for(int index = 0;index < n-1;){
        jump_count += 1;
        index = max_jump_index[index];
    }
    return jump_count;
}

int main(){
    int n;cin>>n;
    vector<int> arr(n);
    
    for(int i=0;i<n;i++) cin>>arr[i];

    int result = minimum_jump(arr,n);

    cout<<"Minimum Jump Required: "<<result<<endl;

    return 0;
}