#include<bits/stdc++.h>
using namespace std;

int find_profit(vector<int>& nums,int n) {
    int size = nums.size();
    int min_ = nums[0],max_ = 0;
    for(int i=1;i<size;i++){
        min_ = min(min_,nums[i]);
        max_ = max(max_,nums[i]-min_);
    }
    return max_;
}

int main(){
    int n;cin>>n;
    vector<int> arr(n);
    
    for(int i=0;i<n;i++) cin>>arr[i];

    int index = find_profit(arr,n);

    cout<<"Maximum Profit: "<<index<<endl;

    return 0;
}