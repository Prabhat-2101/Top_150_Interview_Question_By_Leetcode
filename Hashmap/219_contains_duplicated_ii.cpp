#include<bits/stdc++.h>
using namespace std;

bool contains_nearby_duplicate(vector<int>& nums, int k) {
    unordered_map<int,int> umap;
    for(int i=0;i<nums.size();i++){
        if(umap.find(nums[i]) != umap.end()){
            if((i - umap[nums[i]])<=k) return true;
        }
        umap[nums[i]] = i;
    }
    return false;
}

int main(){
    int n;cin>>n;
    vector<int> arr(n);
    
    for(int i=0;i<n;i++) cin>>arr[i];

    int k;cin>>k;

    bool result = contains_nearby_duplicate(arr,k);

    cout<<result<<endl;

    return 0;
}