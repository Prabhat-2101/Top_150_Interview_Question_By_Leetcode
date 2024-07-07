#include<bits/stdc++.h>
using namespace std;

int majority_element(vector<int>& nums,int n) {
    int size = nums.size();
    map<int,int> mp;
    for(int i=0;i<size;i++){
        mp[nums[i]]++;
    }
    for(auto &it:mp){
        if(it.second > size/2)
            return it.first;
    }
    return -1;
}

int main(){
    int n;cin>>n;
    vector<int> arr(n);
    
    for(int i=0;i<n;i++) cin>>arr[i];

    int index = majority_element(arr,n);

    if(index==-1) cout<<"No Majority Element"<<endl;
    else cout<<"Majority Element: "<<index<<endl;
}