#include<bits/stdc++.h>
using namespace std;

int find_profit(vector<int>& nums,int n) {
    int size = nums.size();
    int total = 0;
    for(int i=0;i<size-1;i++){
        if(nums[i]<nums[i+1]) total += (nums[i+1]-nums[i]);
    }
    return total;
}

int main(){
    int n;cin>>n;
    vector<int> arr(n);
    
    for(int i=0;i<n;i++) cin>>arr[i];

    int index = find_profit(arr,n);

    cout<<"Maximum Profit: "<<index<<endl;

    return 0;
}