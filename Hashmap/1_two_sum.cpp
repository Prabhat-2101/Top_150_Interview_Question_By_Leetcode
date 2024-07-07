#include<bits/stdc++.h>
using namespace std;

vector<int> two_sum(vector<int>& nums, int target) {
    unordered_map<int,int> umap;
    for(int i=0;i<nums.size();i++){
        int req = target - nums[i];
        if(umap.find(req) != umap.end()) return {umap[req],i};
        umap[nums[i]] = i;
    }
    return {-1,-1};
}

int main(){
    int n;cin>>n;
    vector<int> arr(n);
    
    for(int i=0;i<n;i++) cin>>arr[i];

    int target;cin>>target;

    vector<int> index = two_sum(arr,target);

    cout<<index[0]<<" "<<index[1]<<endl;

    return 0;
}